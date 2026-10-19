#include "fcl_scale_transition.h"
/* measured: this unit passes u8 colour channels unmasked (002f6cf0, 002f9d90); see fcl_color.h. */
#include "fcl_animation_internal.h"
#include "model_motion_internal.h"
/* Original translation unit y_fclCombine.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "fcl_color.h"
#include "fcl_row_draw.h"
#include "fcl_row_mode.h"
#include "evt_internal.h"
#include "include_asm.h"
#include "fcl_bounds_packet.h"
#include "fcl_draw_task.h"
#include "sdk_task_registration.h"
#include "kwln_task_internal.h"
#include "datUnit_internal.h"
#include "fcl_combine_row_internal.h"
#include "scene_resource_internal.h"
#include "h_cdvd_request_internal.h"
extern s32 fclCombineMenuUpdate(u8 *task);
extern void fclCombineMenuDestroy(u8 *task);
#include "type.h"

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} FclByte4;

#include "fcl_combine_internal.h"
#include "cmb_card_eff.h"

/* Outer task allocation (0x2C), distinct from the child menu's 0x314 bytes.
   Constructor bit patterns stay integers until their float consumers are known. */
typedef struct {
    s8 state;
    u8 pad1[3];
    s32 unk4;
    s32 unk8;
    u8 unkC;
    s8 messageSlot;
    u8 padE[2];
    union { s32 handle; u8 *pointer; } directory;
    u8 unk14;
    u8 pad15[7];
    u32 childTask;
    s32 unk20;
    s32 unk24;
    s16 unk28;
    u8 pad2A[2];
} FclCombineTaskState;

/* 0x1C-byte calendar rule entries; fclCombineCheckRules compares the same
   entry on each pass, so the loop deliberately does not advance this record. */
typedef struct {
    u8 pad0[2];
    s8 kind;
    u8 pad3;
    s16 firstValue;
    s16 secondValue;
    u8 pad8[0x14];
} FclCombineRule;

/* Recipe prerequisites have a 12-byte stride and variant-specific widths. */
typedef struct {
    s8 kind;
    u8 pad1[3];
    union { u16 id; s16 itemId; u32 flag; } key;
    union { s16 threshold; u32 skillId; } value;
} FclCombineRequirement;

/* Save/restore allocates exactly 0x3004 bytes: 256 records and four flags. */
typedef struct {
    DatPersonaRecord records[0x100];
    u8 claimedSlots[4];
} FclCombineSnapshot;
/* One 10-byte combine row at task state +0xC4 (current row index at +0xB4). */
typedef struct {
    s16 state0;
    s16 state1;
    s16 id;
    s16 x;
    s16 y;
} FclCombineRow;
/* Menu work allocated as 0x314 bytes by fclCombineMenuCreate. The command
   table is nine 10-byte rows; task handles retain their integer and pointer uses. */
typedef struct {
    s8 f0; /* 0x0 */
    u8 f1; /* 0x1 */
    u8 pad2[0xB];
    s8 fD; /* 0xD */
    s16 unkE; /* 0xE */
    s32 unk10; /* 0x10 */
    union { s32 signedValue; u32 value; } unk14; /* 0x14 */
    u8 pad18[0x2];
    s8 sourceCount; /* 0x1A */
    u8 pad1B[0x1];
    union { s16 signedValue; u16 value; } outcome; /* 0x1C */
    s8 outcomeCount; /* 0x1E */
    s8 stageKind; /* 0x1F */
    s8 unk20; /* 0x20 */
    s8 unk21; /* 0x21 */
    u8 pad22[0x2];
    union { s16 signedValue; u16 value; } unk24; /* 0x24 */
    s8 unk26; /* 0x26 */
    s8 unk27; /* 0x27 */
    u8 pad28[0x88];
    s8 unkB0; /* 0xB0 */
    s8 unkB1; /* 0xB1 */
    s8 rareOutcome; /* 0xB2 */
    s8 unkB3; /* 0xB3 */
    s8 commandCursor; /* 0xB4 */
    s8 commandCount; /* 0xB5 */
    s8 fB6; /* 0xB6 */
    s8 unkB7; /* 0xB7 */
    s16 selectedIds[6]; /* 0xB8 */
    FclCombineRow commandRows[9]; /* 0xC4 */
    s16 f11E; /* 0x11E */
    s16 unk120; /* 0x120 */
    s8 f122; /* 0x122 */
    u8 pad123[0x1];
    s32 unk124; /* 0x124 */
    s8 f128; /* 0x128 */
    s8 f129; /* 0x129 */
    u8 pad12A[0x6];
    s8 claimSlot; /* 0x130 */
    u8 pad131[0x7];
    s8 unk138; /* 0x138 */
    s8 unk139; /* 0x139 */
    s8 unk13A; /* 0x13A */
    u8 pad13B[0x1];
    s8 unk13C; /* 0x13C */
    s8 unk13D; /* 0x13D */
    s8 unk13E; /* 0x13E */
    s8 rewardIndex; /* 0x13F */
    u8 pad140[4];
    u8 unk144;
    u8 pad145[3];
    union { s32 handle; u8 *task; } drawTask; /* 0x148 */
    u8 pad14C[0x8];
    s32 rowTasks[12]; /* 0x154 */
    s32 f184; /* 0x184 */
    union { s32 handle; u8 *task; } ballTask; /* 0x188 */
    u8 pad18C[0x90];
    s32 ballTasks[12]; /* 0x21C */
    s32 spritePoolTask; /* 0x24C */
    u8 * bustupTask; /* 0x250 */
    union { s32 handle; u8 *task; } detailTask; /* 0x254 */
    u8 * panelTasks[12]; /* 0x258 */
    u8 pad288[0x4];
    union { s32 handle; u8 *task; } headerTask; /* 0x28C */
    union { s32 handle; u8 *task; } arrowTask; /* 0x290 */
    u8 pad294[0x10];
    u8 * levelUpTask; /* 0x2A4 */
    u8 * skillReplaceTask; /* 0x2A8 */
    s32 topBorderTask; /* 0x2AC */
    s32 bottomBorderTask; /* 0x2B0 */
    s32 middleBorderTask; /* 0x2B4 */
    u8 pad2B8[4];
    u8 * f2BC; /* 0x2BC */
    u8 pad2C0[0x14];
    s8 ruleIndex; /* 0x2D4 */
    u8 pad2D5[0x3];
    s16 f2D8; /* 0x2D8 */
    s8 outcomeIds[5]; /* 0x2DA */
    s8 outcomeIdCount; /* 0x2DF */
    u8 pad2E0[0x19];
    s8 f2F9; /* 0x2F9 */
    s8 f2FA; /* 0x2FA */
    u8 pad2FB[0x5];
    s32 eventTask; /* 0x300 */
    s32 cardEffectTask; /* 0x304 */
    s32 cardSpriteTask; /* 0x308 */
    u8 f30C[5]; /* 0x30C */
    u8 pad311[3];
} FclCombineMenu;

/* The reward table has two eight-byte entries (root states 0x14..0x16). */
typedef struct {
    s8 chance;
    u8 pad1;
    s16 item;
    s32 flag;
} FclCombineReward;

/* Tail of the shared draw-record prefix; y_draw.c allocates 0x100 bytes
   and updates the independent scale and value channels at these offsets. */
typedef struct {
    FclCombineRowSprite row;
    u8 pad8C[0x14];
    f32 scaleX;
    u8 padA4[8];
    f32 scaleY;
    u8 padB0[0x20];
    f32 value;
    u8 padD4[0x2C];
} FclCombineMenuSprite;

/* fclCombineSlotRecord returns slot +0x104 in each 0x200-byte ball record.
   The animation fields are relative to that returned pointer, not the task. */
typedef struct {
    s16 flags;
    u8 pad2[2];
    f32 depth;
    u8 pad8[0x10];
    FclVec2 positionStart;
    FclVec2 positionEnd;
    FclVec2 position;
    u8 pad30[0x2E];
    u8 alpha;
    u8 pad5F[0x16];
    FclDrawColor color;
    u8 pad79[0x83];
} FclCombineBallSlot;

/* fclCombineGetWork exposes this child model state; the provider's
   FclCombineModelWork clears +4 and reserves the byte at +1. */
typedef struct {
    s8 state;
    s8 unk1;
    u8 pad2[2];
    u8 cleared;
    u8 pad5[0xEF];
} FclCombineModelWork;

/* The camera handle's +4 word is forwarded to func_003e9cb0 unchanged. */
typedef struct {
    u8 pad0[4];
    u32 unk4;
} FclCombineCamera;

/* y_draw.c allocates 0x130-byte panel work and tests this hidden byte
   before writing its four vertex packets. */
typedef struct {
    u8 pad0[0x124];
    u8 hidden;
    u8 pad125[0xB];
} FclCombinePanelWork;

typedef FclVec2 FclVec2f;

extern void fclCombineDrawRosterRows(u8 *, s32, s32, s8);
extern void fclCombineDrawRosterList(u8 *, s32, s32, s8);
extern void func_002e68b0(s8);
extern void func_002e6c90(s8);
extern void fclDrawSetSlot(u8 *, s32, s8, s8);
extern void fclCombineDrawSelectedName(u8 *);
extern s32 fclCombineGetWork(u8 *);
extern void shdPersonaSetOpacity(u8 *, f32);
extern void fclDrawSetVisible(u8 *, s8);
extern u8 datPersonaGetBuffedStat(u8 *, s32);
extern s32 fclCombineApplyDiscount(u16, s32);
extern void fclAddMoney(s32);
extern void fclDrawNumber(FclVec2, f32, FclDrawColor, s32, s16, u32, s32, s32, s32, s32, s32);
extern void *resourceFindByName(void *);
extern u8 D_00641B30[];
extern void fclCombineMoveRosterCursor(u8 *, s64);
extern void fclCombineDrawSlotFrames(u8 *, FclVec2, s32, s8);
extern void fclCombineSlideInHeaderSprites(f32, f32, u8 *, s64, s8);
extern s32 shdPersonaIsTransitioning(u8 *);
extern char iGpffffa8a4;
extern u16 D_008C0252[];
extern void fclCombineDrawPanelBorder(u8 *, s8);
extern void fclSpriteStartMove(u8 *, FclVec2, FclVec2, u32);
extern void fclSpriteStartFade(u8 *, u8, u8, u32);
extern void fclCombineFadeCursorArrow(u8 *, s64, f32);
extern void fclCombineSetReady(u8 *);
extern void fclCombineInitView(u8 *);
extern u8 *datPersonaCachedRecord(s32);
extern char iGpffffa8a0;

extern void fclDrawSetSlotMode(u8 *, s32, s8);
extern f32 fclEaseInterpolate(s64, f32, f32, f32, f32);
extern s32 datCalcGetLevelById(s32);
extern void yListSlotCreate(s32, s8);
extern void fclCombineLayoutDetailSprites(u8 *, s64);
extern s32 fclCombineRowsBusy(u8 *);
extern u8 *yListSlotWork(s8);
extern u8 *yListSlotEntry(s8, s16);
extern void datPersonaPreviewLevelUp(u8 *, u8 *, s32);
extern s32 datPersonaExpToNextLevel(u8 *);
extern s32 datPersonaRosterCapacity(void);
extern void fclCombineLayoutFrame(u8 *, s64, s8);
extern void fclCombineFadeLabelSprites(u8 *, s64, s64, s64, s64, s64, s64, s64, s8, s8, s8);
extern s32 fclPackRgba(u8, u8, u8, u8);
extern int frFontExDrawTextDeferredOutB(f32, f32, f32, int, s8, int, const char *, int, int, void *, int);
extern u8 *sdkSpriteNewNode(u32, u32);
extern s32 fclCombineGetSpritePool(void);
extern f32 sdkSpriteScaledWidth(u8 *);
extern f32 sdkSpriteScaledHeight(u8 *);
extern void sdkSpriteFreeNode(void *);
extern void fclSpriteStartAlphaAt(s16, u8, u8, u8, s32, s16);
extern void fclSpriteStartPositionAt(s16, FclVec2f, FclVec2f, u32, u32, s16);
extern void fclDrawSetPlacement(u8 *, s32, u8, s32);
extern void shdPersonaEndSelection(u8 *, s32);
extern void shdPersonaSetChildDispCtlHandle(u8 *, s32);
extern u32 shdPersonaIsSelectionActive(u8 *);
extern void shdPersonaStepSelectionCursor(u8 *);
extern void shdPersonaBeginSelection(u8 *);
extern void fclDrawSetFlag(u8 *, s8);
extern u8 *fclDrawGetResource(u8 *);
extern s32 sdkSndStartStream(s16, s16, s16, s16);
extern void fclDrawSetStateByte(u8 *, s8);
extern void fclCombineFadePanelSprite(u8 *, s64, f32);
extern s8 fclDrawGetState(u8 *);
extern void fclDrawResetScale(u8 *);
extern s16 fclSpriteFlagBit(s16, s16);
extern u8 *fclSpriteEntry(s16);
extern void fclCombineHandleGridInput(u8 *, s64, u8, u8);
extern void fclCombineRefreshRosterSelection(u8 *);
extern void fclCombinePartyRow(u8 *, FclVec2, s32, s32, s16, s16, s8, s8);
extern void fclCombineDrawPersonaRow(u8 *, FclVec2, s8, s8, s32, s16, s16, s8, s8, u8);
extern void fclCombineSelectSlotEntry(u8 *, s8, s8, s64, s64);
extern void fclCombineDrawPersonaCard(u8 *, s16, FclVec2f, FclVec2f);
extern void fclCombineDrawPersonaCardAlt(u8 *, s16, FclVec2, FclVec2);
extern void fclCombineSetupPairGrid(u8 *, s8);
extern void fclCombineRefreshGridCells(u8 *, s16);
extern void fclCombineStepSidePanel(u8 *, s16, s8);
extern u32 RpRandom(void);
extern void fclSpriteSetFlag(s16, s16, s8);
extern s32 nmMesWindowDestroySlot(s64);
extern void nmMesWindowStepSlotRelease(s32);
extern s32 yListSlotContainsId(s8, s16);
extern void fclCombineLayoutTransition(u8 *, s32);
extern s8 datGetPersonaArcanaCommunityValue(u16);
extern u32 datGetFlag(s32);
extern void *memset(void *, s32, u32);
extern void yListSlotFillNearLevel(s8, u16 *, s8);
extern void yListSlotFillByLevel(s8, u16 *, s8);
extern s32 datPersonaFindSkillSlot(u8 *, u16);
extern s32 datPersonaCountSkills(u8 *);
extern s32 datPersonaAddSkill(u8 *, u16);
extern s32 nmMesWindowSlotStatus(s32);
extern s32 fadeStatus(void);
extern s32 fadeBeginTransition(s32, s32);
extern s16 cmmTopCommunityOfArcana(s32);
extern s32 fclRollRareChance(s8);
extern void fclDrawSetPlacementEx(u8 *, s32, s8, s32, s32);
extern s32 cmmCommunityExpRemaining(s32,  u8 *,  s8);
extern s32 fclAddClamped(s32, s32, s32, s32, s8);
extern s32 fclSubClamped(s32, s32, s32, s32, s8);
extern f32 D_00640C10[];
extern f32 D_00640C18[];
extern u8 D_00795E60[];
extern u16 D_008C024E[];
extern u16 D_008C024C[];
extern u16 D_008C027A[];
extern u8 *iGpffffb440;
extern u8 *iGpffffb3d4;
extern f32 iGpffff8504;
extern void fclCombineFuseSourceRecords(u16 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, s32, s8, s8);
extern void fclCombinePlayCue(u8 *, s32, s32);
extern void fclCombinePlayResultCue(u8 *, u16);
extern void shdPersonaFillStateBlock(u8 *, u8 *);
extern s32 shdPersonaReplaceSkill(u8 *, u16, u16);
extern u8 *func_00243840(s32);
extern int frFontExDrawTextDeferred(f32, f32, f32, int, s8, int, const char *, int, int, void *);
extern s32 nmMesWindowGetSlotState(s8);
extern void yListBuildPairFlags(void);
extern void fclCombineDrawGridRows(u8 *);
extern u16 *fclCombineFindMatchPtr(u8 *);
extern s32 fclCombineRollTier(u8 *);
extern s32 fclCombineFindMatchIndex(u8 *);
extern s32 fclCombinePersonaInRoster(u16);
extern s32 fclCombineFindRandomSkillIndex(u8 *);
extern s32 datPersonaReplaceSkill(u8 *, s16, u16);
extern u16 datPersonaCountValidMembers(void);
extern u8 *datStagedRecord(void);
extern void nmMesWindowSetNumberColor(u8 *, s16, FclDrawColor);
extern s64 nmMesWindowAcquire(void *);
extern s32 nmMesWindowShowSlotRecord(s8, s32);
extern s32 nmMesWindowSetSlotParam(s64, s32);
extern void nmMesWindowSetSlotFlag(s64, s8);
extern int sprintf(char *, const char *, ...);
extern void nmMesWindowSetNumber(u8 *, s16, s32, FclVec2, FclDrawColor, f32, s64);
extern u32 fclGetMoney(void);
extern u8 *cmbCardEffCreateTask(u8 *, s8);

extern void cmmDateSelectionRefresh(u8 *task);
extern s32 fclBustupCreate(u8 *task);


extern void fclSpriteSetCornerColors(u8 *task, FclDrawColor color);
extern void fclSpriteSetBaseScale(u8 *task, f32 depth);
extern void fclSpriteSetOrder(u8 *task, u32 order);
extern void fclSpriteSetHidden(u8 *task, u8 hidden);
extern void fclSpriteSetMode(u8 *task, u8 mode);
extern void fieldSceneUnload(void);
extern s32 kwlnTaskGetTaskByName(void *);
extern void fclCombineRequestRefresh(void);
extern void H_Cdvd_Destroy(void *);
extern void (*jtbl_008873EC[])(void *);
extern u8 D_00641BC8[];
extern s8 D_007490F8[];
extern struct DatPersonaRecord *datPersonaRosterSlot(s16);
extern u8 datPersonaGetArcana(u16);
extern s32 fclCombineGetMesWindow(void);
extern void nmMesWindowSetSlotString(s8, s32, void *);
extern s32 datGetPersonaCacheCompletionPercent(void);
extern void *datGetItemNameId(s16);
extern s16 D_00749040[];
extern s16 D_00749060[];
extern s16 D_00749080[];
extern s16 D_007490A0[];
extern s16 D_007490C0[];
extern s16 D_007490E0[];
extern s8 D_00749100[];
extern void nmMesWindowRequestRefresh(void);
/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
extern s32 datPersonaGetSkillAt(void *, s16);
extern u16 *iGpffffb3ec;
extern u8 *iGpffffb594;
extern void datPersonaCacheRecord(void *);
extern void datItemSetCount(s16, s32);
extern u8 D_00641BE0[];
extern u8 D_00641C00[];
extern char iGpffffa8c8;
extern void func_00440b68(const void *, const void *, s32 );
extern s32 H_Cdvd_AcquireDirectory(void *, s32 );
extern void sdkSndFadeOutChannelFrames(s32, s32, s32);
extern s32 datGetClearedWord(void);
extern void datSetHeroLevel(s32, s32);
extern void datSetMoney(s32);
extern u8 *datPersonaAddRosterMember(u16 personaId);
extern void fclCombineMoveGridCursor(u8 *, s32);
extern u16 D_008C0276[];
extern f32 D_00640D78[];
extern void datSetFlag(s32, s32);
extern void chkmemAllocSiteTag(const void *, s32);
extern void *memcpy(void *, void *, u32);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00641B00[];
extern u16 datPersonaLeadPersonaId(void);
extern s32 datPersonaRemoveRosterMemberById(s32);
extern s32 datPersonaInsertRosterRecord(u8 *);
extern s32 datPersonaSelectRosterMemberById(s32);
extern void datPersonaRemoveSelectedRosterMember(void);
extern void datPersonaInitRecord(u8 *, u16 );
extern s64 fclFuseRollPersona(u16 *, u8 *, s64 );
/* The item id is an s16; the callee sign-extends its own table index. */
extern s32 datGetSelectorByte(s16 );
extern u8 fclCalendarMonth(void);
extern s32 fclCalendarDay(void);
extern s8 D_00641A60[];
extern s8 D_00749480[];
extern u8 *iGpffffb44c;
extern s8 iGpffffa8a8;
extern u16 cmmCommunityRecordValue(s32 );
extern struct DatPersonaRecord *datPersonaFindRosterRecordById(s32 );
extern s32 datItemCount(s16 id);
extern u8 D_00641880[];
extern u8 D_0063FCA0[];
extern u8 D_006406F0[];
extern s64 calGetDayEntryForMonthDay(s32 , s32 );
extern s32 fclCombineCheckRules(u8 *, s8 , u16 *);
extern f32 D_00641660[];
extern u8 D_006417E0[];
extern u8 D_00882FAE[];
extern u8 D_00882FB0[];
extern u8 D_00882FB1[];
extern f32 datGetAverageRecordScore(void);
extern void fclCombineDrawDetailFrame(u8 *, s32 );
extern void fclCombineDrawActionList(u8 *);
extern void fclCombineMoveChoiceCursor(u8 *, s32 , u8 *);
extern s32 fclCombineMenuCreate(u8 *);
extern s32 kwlnTaskIsLinked(s32 );
extern void fadeBeginReturnTransition(s32, s32);
extern s32 H_Cdvd_IsFileLoaded(void *);
extern void fieldSceneLoad(s32, s32);
extern void fieldSceneRequestRoom(s32);
extern s16 datCategoryRank(s16);
extern s32 fclCombineEventSceneCreate(u8 *, s32, s32);
extern void cmmCommunityAllocRecord(s32);
extern s32 fieldSceneLoadStep(void);
extern u8 *MT_Scene_GetResListHead(s32);
extern u8 *kwlnGetCamera(void);
extern f32 MT_Scene_GetCameraFov(void);
extern void K_View_SetFov(u8 *, f32 );
extern s32 MT_Scene_GetCameraResFirst(void);
extern void func_003e9cb0(s32, s32, s32);
extern void fclCombineCdvdTaskCreate(void);
extern s32 fclCombineInPreviewState(void);
extern s32 fclModelEffectCreate(s32, s32);
extern u8 *fclSpritePoolCreate(s32, s32);
extern void fclSpriteReset(s16, s16);
extern s32 fclCombineGetSpriteList(void);
extern u8 D_00641B10[];
extern s32 fclDrawIsActive(s32);
extern s32 evtGetEventFrame(void);
extern s32 kwlnTaskIsLinked(s32);
extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *);
extern s32 func_00459760(void);
extern void sdkSndPlayCue(s32, s32);
extern void fclCombineConsumeMaterials(u8 *, s16 *);
extern s32 fclDrawTaskCreate(u8 *);
extern s32 fclCombineClaimSlot(u8 *);
extern f32 D_00640C50[];
extern f32 D_00640C58[];
extern u8 D_00641BB0[];
extern void fclCombineDrawEntryCell(u8 *, FclVec2, FclVec2, s8, s16, s16, s16);
extern u8 D_00640760[];
extern u8 D_00640790[];
extern u8 D_0064079C[];
extern u8 D_006407A8[];
extern u8 D_006407C0[];
extern u16 datStagedId(void);
/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
extern u16 datPersonaRosterSlotFlags(u16);
extern void datStageRecord(u8 *, u16);
extern void datStageSetId(u16);
extern u8 D_00749350[];
extern u16 fclCombineOtherHeroId(void);




/* Registers the combine UI and its child draw tasks. Creators return
 * real SDK handles; positions, colors and bounds use their shared contracts.
 * MWCCPS2 b210 -O2: 3256/3264 bytes, 148 resolved relocations, eight zero
 * tail bytes. See the SDK/Fcl closure evidence for every affected owner.
 */
// FUN_002E8410
/* Historical whole-layout probe: 2088 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
s32 fclCombineMenuCreate(u8 *parentTask) {
    s32 k;
    s32 task;
    u8 *out;
    FclDrawColor menuColor;
    u8 *e;

    chkmemAllocSiteTag(D_00641B00, 0x166);
    out = D_008873F4[0](1, 0x314, 0x40000);
    task = (s32)kwlnTaskCreateChild((void *)((void *)((s32)parentTask)), (const void *)(D_00641B10), 0xF, 0, 0, fclCombineMenuUpdate, fclCombineMenuDestroy, (u8 *)(out));
    *out = 0;
    *(out + 1) = 0x11;
    *(out + 0x144) = 0;
    cmmDateSelectionRefresh((u8 *)(task));
    *(out + 0x20) = 0;
    *(out + 0xB3) = 0;
    ((FclCombineMenu *)out)->detailTask.handle = fclModelEffectCreate((s32)parentTask, 0);
    {
        s32 partyIndex;
        for (partyIndex = 0; partyIndex < (datPersonaRosterCapacity() & 0xFFFF); partyIndex++) {
            ((FclCombineMenu *)out)->rowTasks[partyIndex] = fclCmbBallTaskCreateSlots((s32)parentTask, datPersonaRosterCapacity() & 0xFF, 0x41);
        }
    }
    ((FclCombineMenu *)out)->f184 = fclCmbBallTaskCreateSlots((s32)parentTask, datPersonaRosterCapacity() & 0xFF, 0x41);
    ((FclCombineMenu *)out)->ballTask.handle = fclCmbBallTaskCreateSlots((s32)parentTask, datPersonaRosterCapacity() & 0xFF, 0x58);
    {
        s32 segmentIndex;
        for (segmentIndex = 0; segmentIndex < 0xC; segmentIndex++) {
            menuColor = fclMakeDrawColor(0, 0, 0x99, 0xFF);
            /* measured: field typing changes 2187 normalized bytes in the full owner. */
            e = fclCombineSlotRecord(*(u8 **)(out + 0x188), (s8)segmentIndex);
            ((FclCombineBallSlot *)e)->color = menuColor;
        }
    }
    ((FclCombineMenu *)out)->spritePoolTask = (s32)fclSpritePoolCreate((s32)parentTask, fclCombineGetSpritePool());
    {
        s32 descriptorId;
        for (descriptorId = 0; descriptorId < 500; descriptorId++) {
            fclSpriteReset((s16)descriptorId, (s16)descriptorId);
        }
    }
    {
        s32 pairIndex;
        for (pairIndex = 0; pairIndex < 0xC; pairIndex++) {
            fclSpriteReset((s16)(pairIndex * 2 + 500), 0x1AC);
            fclSpriteReset((s16)(pairIndex * 2 + 501), 0x1AF);
        }
    }
    fclSpriteReset(0x20C, 0x80);
    {
        s32 arrowIndex;
        for (arrowIndex = 0; arrowIndex < 9; arrowIndex++) {
            fclSpriteReset((s16)(arrowIndex + 0x20D), 0xDC);
        }
    }
    {
        s32 indicatorIndex;
        for (indicatorIndex = 0; indicatorIndex < 3; indicatorIndex++) {
            fclSpriteReset((s16)(indicatorIndex + 0x216), 0x86);
            fclSpriteReset((s16)(indicatorIndex + 0x219), 0x87);
        }
    }
    {
        s32 rowIndex;
        for (rowIndex = 0; rowIndex < 0xC; rowIndex++) {
            fclSpriteReset((s16)(rowIndex + 0x21C), 0x193);
            fclSpriteReset((s16)(rowIndex + 0x22B), 0x19A);
            fclSpriteReset((s16)(rowIndex + 0x238), 0x188);
            fclSpriteReset((s16)(rowIndex + 0x244), 0x18C);
            fclSpriteReset((s16)(rowIndex + 0x250), 0x1C);
            fclSpriteReset((s16)(rowIndex + 0x25E), (s16)(rowIndex + 0x39));
            fclSpriteReset((s16)(rowIndex + 0x270), 0x193);
            fclSpriteReset((s16)(rowIndex + 0x27D), 0x19B);
            fclSpriteReset((s16)(rowIndex + 0x28B), 0x188);
            fclSpriteReset((s16)(rowIndex + 0x297), 0x18D);
            fclSpriteReset((s16)(rowIndex + 0x2A3), 0x1C);
        }
    }
    fclSpriteReset(0x228, 0x193);
    fclSpriteReset(0x229, 0x193);
    fclSpriteReset(0x2B1, 0x1A2);
    fclSpriteReset(0x25C, 0x1C);
    fclSpriteReset(0x25D, 0x1C);
    fclSpriteReset(0x27C, 0x193);
    fclSpriteReset(0x289, 0x19B);
    fclSpriteReset(0x28A, 0x19B);
    fclSpriteReset(0x237, 0x73);
    fclSpriteReset(0x2AF, 0x73);
    fclSpriteReset(0x2B0, 0x73);
    fclSpriteReset(0x26A, 0x46);
    fclSpriteReset(0x26B, 0x46);
    fclSpriteReset(0x26C, 0x46);
    fclSpriteReset(0x26D, 0x46);
    fclSpriteReset(0x26E, 0x46);
    fclSpriteReset(0x26F, 0x46);
    fclSpriteReset(0x2B2, 0x54);
    fclSpriteReset(0x2B3, 0x54);
    {
        s32 ballIndex;
        for (ballIndex = 0; ballIndex < 0xC; ballIndex++) {
            ((FclCombineMenu *)out)->ballTasks[ballIndex] = fclCmbBallTaskCreate((s32)parentTask);
        }
    }
    fclSpriteReset(0x2B4, 0x193);
    fclSpriteReset(0x2B5, 0x19A);
    fclSpriteReset(0x2B6, 0x51);
    fclSpriteReset(0x2B7, 0x52);
    fclSpriteReset(0x2B8, 0x53);
    fclSpriteReset(0x2B9, 0x73);
    fclSpriteReset(0x2BA, 0x73);
    for (k = 0; k < 2; k++) {
        fclSpriteReset((s16)(k + 0x2BB), 0xA4);
        fclSpriteReset((s16)(k + 0x2BD), 0xA5);
        fclSpriteReset((s16)(k + 0x2BF), 0xBC);
        fclSpriteReset((s16)(k + 0x2C3), 0x19C);
        fclSpriteReset((s16)(k + 0x2C1), 0x14F);
    }
    for (k = 0; k < 8; k++) {
        fclSpriteReset((s16)(k + 0x2C5), 0x19E);
    }
    fclSpriteReset(0x2CD, 0x9E);
    fclSpriteReset(0x2CE, 0xA0);
    fclSpriteReset(0x2CF, 0x81);
    fclSpriteReset(0x2D0, 0x11E);
    fclSpriteReset(0x2D1, 0x11E);
    fclSpriteReset(0x2D8, 0x1D6);
    fclSpriteReset(0x2D9, 0x1D7);
    fclSpriteReset(0x2DA, 0x165);
    fclSpriteReset(0x2DB, (s16)((fclCalendarMonth() % 10) + 9));
    fclSpriteReset(0x2DC, (s16)(((u8)fclCalendarDay() / 10) + 9));
    fclSpriteReset(0x2DD, (s16)(((u8)fclCalendarDay() % 10) + 9));
    fclSpriteReset(0x22A, 0x193);
    fclSpriteReset(0x2DE, 0x126);
    fclSpriteReset(0x2DE, 0x125);
    for (k = 0; k < 0xC; k++) {
        fclSpriteReset((s16)(k + 0x2FB), 0x131);
        ((FclCombineMenu *)out)->panelTasks[k] = (u8 *)fclSpriteCreatePanelChild(task);
    }
    ((FclCombineMenu *)out)->headerTask.handle = (s32)fclSpriteSpawnChild(task, fclMakeVec2(288.0f, 14.0f));
    /* measured: field typing changes 886 normalized bytes in the full owner. */
    fclSpriteSetPositionBounds((u8 *)*(s32 *)(out + 0x28C), fclMakeVec2(288.0f, 14.0f), fclMakeBoundsPacket(160.0f, 36.0f));
    /* measured: field typing changes 886 normalized bytes in the full owner. */
    fclSpriteSetOrder((u8 *)(*(s32 *)(out + 0x28C)), 0xAB);
    /* measured: field typing changes 887 normalized bytes in the full owner. */
    fclSpriteSetHidden((u8 *)(*(s32 *)(out + 0x28C)), 0);
    /* measured: field typing changes 887 normalized bytes in the full owner. */
    fclSpriteSetCornerColors((u8 *)*(s32 *)(out + 0x28C), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0));
    /* measured: field typing changes 887 normalized bytes in the full owner. */
    fclSpriteSetBaseScale((u8 *)(*(s32 *)(out + 0x28C)), 53.0f);
    ((FclCombineMenu *)out)->arrowTask.handle = (s32)fclSpriteSpawnChild(task, fclMakeVec2(0.0f, 14.0f));
    /* measured: field typing changes 713 normalized bytes in the full owner. */
    fclSpriteSetPositionBounds((u8 *)*(s32 *)(out + 0x290), fclMakeVec2(0.0f, 14.0f), fclMakeBoundsPacket(26.0f, 36.0f));
    /* measured: field typing changes 713 normalized bytes in the full owner. */
    fclSpriteSetOrder((u8 *)(*(s32 *)(out + 0x290)), 0xAB);
    /* measured: field typing changes 714 normalized bytes in the full owner. */
    fclSpriteSetHidden((u8 *)(*(s32 *)(out + 0x290)), 0);
    /* measured: field typing changes 714 normalized bytes in the full owner. */
    fclSpriteSetCornerColors((u8 *)*(s32 *)(out + 0x290), fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0));
    /* measured: field typing changes 714 normalized bytes in the full owner. */
    fclSpriteSetBaseScale((u8 *)(*(s32 *)(out + 0x290)), 53.0f);
    ((FclCombineMenu *)out)->topBorderTask = (s32)fclSpriteSpawnChild(task, fclMakeVec2(0.0f, 0.0f));
    /* measured: field typing changes 548 normalized bytes in the full owner. */
    fclSpriteSetPositionBounds((u8 *)*(s32 *)(out + 0x2AC), fclMakeVec2(0.0f, 0.0f), fclMakeBoundsPacket(640.0f, 7.0f));
    /* measured: field typing changes 548 normalized bytes in the full owner. */
    fclSpriteSetOrder((u8 *)(*(s32 *)(out + 0x2AC)), 0xB2);
    /* measured: field typing changes 549 normalized bytes in the full owner. */
    fclSpriteSetCornerColors((u8 *)*(s32 *)(out + 0x2AC), fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF));
    /* measured: field typing changes 548 normalized bytes in the full owner. */
    fclSpriteSetHidden((u8 *)(*(s32 *)(out + 0x2AC)), 1);
    /* measured: field typing changes 548 normalized bytes in the full owner. */
    fclSpriteSetMode((u8 *)(*(s32 *)(out + 0x2AC)), 1);
    ((FclCombineMenu *)out)->bottomBorderTask = (s32)fclSpriteSpawnChild(task, fclMakeVec2(0.0f, 432.0f));
    /* measured: field typing changes 394 normalized bytes in the full owner. */
    fclSpriteSetPositionBounds((u8 *)*(s32 *)(out + 0x2B0), fclMakeVec2(0.0f, 432.0f), fclMakeBoundsPacket(640.0f, 16.0f));
    /* measured: field typing changes 394 normalized bytes in the full owner. */
    fclSpriteSetOrder((u8 *)(*(s32 *)(out + 0x2B0)), 0xB2);
    /* measured: field typing changes 395 normalized bytes in the full owner. */
    fclSpriteSetCornerColors((u8 *)*(s32 *)(out + 0x2B0), fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF));
    /* measured: field typing changes 394 normalized bytes in the full owner. */
    fclSpriteSetHidden((u8 *)(*(s32 *)(out + 0x2B0)), 1);
    /* measured: field typing changes 394 normalized bytes in the full owner. */
    fclSpriteSetMode((u8 *)(*(s32 *)(out + 0x2B0)), 1);
    ((FclCombineMenu *)out)->middleBorderTask = (s32)fclSpriteSpawnChild(task, fclMakeVec2(0.0f, 69.0f));
    /* measured: field typing changes 232 normalized bytes in the full owner. */
    fclSpriteSetPositionBounds((u8 *)*(s32 *)(out + 0x2B4), fclMakeVec2(0.0f, 69.0f), fclMakeBoundsPacket(640.0f, 343.0f));
    /* measured: field typing changes 232 normalized bytes in the full owner. */
    fclSpriteSetOrder((u8 *)(*(s32 *)(out + 0x2B4)), 0xB2);
    /* measured: field typing changes 233 normalized bytes in the full owner. */
    fclSpriteSetCornerColors((u8 *)*(s32 *)(out + 0x2B4), fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xE5));
    /* measured: field typing changes 232 normalized bytes in the full owner. */
    fclSpriteSetHidden((u8 *)(*(s32 *)(out + 0x2B4)), 1);
    /* measured: field typing changes 232 normalized bytes in the full owner. */
    fclSpriteSetMode((u8 *)(*(s32 *)(out + 0x2B4)), 1);
    ((FclCombineMenu *)out)->bustupTask = (u8 *)fclBustupCreate((u8 *)(task));
    ((FclCombineMenu *)out)->f2BC = (u8 *)fclSpriteListCreateChild(task, 0x30, fclCombineGetSpriteList());
    return task;
}


/* measured: 8604 executable bytes / 8608-byte window, verify MATCH, 287 relocations.
   Rewritten from the retail assembly.  The switch keeps retail's case order
   (MWCC tests the sparse labels in reverse); opt_lifetimes gives each loop
   index its own register as retail does; the second reward scan keeps its own
   selection local; row lookups use the 10-byte FclCombineRow at +0xC4. */
// Fcl combine menu root (state 0): opens the screen (intro 0x11-0x17), runs the command bar (0x18) and the row list (0x1A), and routes each row to its target state; state 0x0B leaves the screen.
// FUN_002E90D0
#pragma push
#pragma opt_lifetimes on
/* Historical whole-layout probe: 8 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
void fclCombineMenuRoot(u8 *task)
{
    extern u8 D_00641870[];
    extern s32 datGetFlag(s32);
    extern s32 fclBustupIsActive(u8 *);
    extern void fclCombineDrawSlotRows(u8 *, s64);
    extern void fclCombineStepSlotSelection(u8 *, s8);
    extern void fclCombineBuildRows(u8 *);
    extern void fclCombineMarkRow(s16);
    extern void fclCombineUpdateEntryHighlight(u8 *, s8, s8, s16, s16);
    extern s8 fclCombineMapSlotKind(s8);
    extern void fclCombineSetSlotColors(u8 *, s16, FclDrawColor, FclDrawColor, FclDrawColor);
    FclDrawColor color0;
    FclDrawColor color1;
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
    FclVec2 slotPos0;
    s32 msgArgs0[2];
    s32 msgArgs1[2];
    FclVec2 pos0;
    FclVec2 pos1;
    FclVec2 pos2;
    FclVec2 pos3;
    FclVec2 pos4;
    FclVec2 pos5;
    FclVec2 pos6;
    FclVec2 pos7;
    FclVec2 pos8;
    FclVec2 pos9;
    FclVec2 pos10;
    FclVec2 pos11;
    FclVec2 pos12;
    FclVec2 pos13;
    FclVec2 pos14;
    FclVec2 slotPos1;
    FclVec2 slotPos2;
    char text[0x88];
    s32 off;
    s8 selected2;
    s16 k2;
    s16 menu;
    u8 *te;
    s16 n;
    s8 *p;
    s8 selected;
    s16 j;
    FclVec2 *vec;
    u16 buttons;
    s16 k;
    u8 *entry;

    p = (s8*)((KwlnTask *)task)->work;
    switch ((u8)p[1]) {
    case 0x11:
        p[1] = 0x12;
        break;
    case 0x12:
        p[1] = 0x14;
        if (datGetFlag(0x131D) == 0) {
            p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            nmMesWindowShowSlotRecord(p[0xD], 0x4C);
            datSetFlag(0x131D, 1);
            p[1] = 0x13;
        }
        break;
    case 0x13:
        if (nmMesWindowSlotStatus(p[0xD]) != 0) {
            nmMesWindowStepSlotRelease(p[0xD]);
            break;
        }
        nmMesWindowDestroySlot(p[0xD]);
        p[1] = 0x12;
        break;
    case 0x14:
        selected = -1;
        for (k = 0; k < 2; k++) {
            entry = D_00641870 + k * 8;
            if (datGetFlag(((FclCombineReward *)entry)->flag) == 0) {
                if ((f32)*(s8 *)entry <= 100.0f * datGetAverageRecordScore()) {
                    selected = k;
                }
            }
        }
        p[0x13F] = selected;
        if (p[0x13F] != -1) {
            entry = D_00641870 + p[0x13F] * 8;
            p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            sprintf(text, &iGpffffa8a0, *(s8 *)entry);
            nmMesWindowSetSlotString(p[0xD], 0, text);
            if (datGetAverageRecordScore() >= 1.0f) {
                nmMesWindowShowSlotRecord(p[0xD], 8);
            } else {
                nmMesWindowShowSlotRecord(p[0xD], 7);
            }
            p[1] = 0x15;
        } else {
            p[1] = 0x17;
        }
        break;
    case 0x15:
        if (nmMesWindowSlotStatus(p[0xD]) != 0) {
            nmMesWindowStepSlotRelease(p[0xD]);
            break;
        }
        nmMesWindowDestroySlot(p[0xD]);
        entry = D_00641870 + p[0x13F] * 8;
        p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
        msgArgs0[0] = ((FclCombineReward *)entry)->item;
        msgArgs0[1] = 0;
        nmMesWindowSetSlotString(p[0xD], 0, msgArgs0);
        nmMesWindowShowSlotRecord(p[0xD], 9);
        /* measured: field typing changes 5472 normalized bytes in the full owner. */
        datItemSetCount(*(s16 *)(entry + 2), (u8)((u8)datItemCount(*(s16 *)(entry + 2)) + 1));
        p[1] = 0x16;
        break;
    case 0x16:
        if (nmMesWindowSlotStatus(p[0xD]) != 0) {
            nmMesWindowStepSlotRelease(p[0xD]);
            break;
        }
        nmMesWindowDestroySlot(p[0xD]);
        datSetFlag(((FclCombineReward *)D_00641870)[p[0x13F]].flag, 1);
        selected2 = -1;
        for (k2 = 0; k2 < 2; k2++) {
            entry = D_00641870 + k2 * 8;
            if (datGetFlag(((FclCombineReward *)entry)->flag) == 0) {
                if ((f32)*(s8 *)entry <= 100.0f * datGetAverageRecordScore()) {
                    selected2 = k2;
                }
            }
        }
        p[0x13F] = selected2;
        if (p[0x13F] == -1) {
            p[1] = 0x17;
            break;
        }
        entry = D_00641870 + p[0x13F] * 8;
        p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
        msgArgs1[0] = ((FclCombineReward *)entry)->item;
        msgArgs1[1] = 0;
        nmMesWindowSetSlotString(p[0xD], 0, msgArgs1);
        nmMesWindowShowSlotRecord(p[0xD], 9);
        /* measured: field typing changes 5185 normalized bytes in the full owner. */
        datItemSetCount(*(s16 *)(entry + 2), (u8)((u8)datItemCount(*(s16 *)(entry + 2)) + 1));
        break;
    case 0x17:
        if (fclBustupIsActive(((FclCombineMenu *)p)->bustupTask) == 0) {
            break;
        }
        ((FclCombineMenu *)p)->drawTask.handle = fclDrawTaskCreate(task);
        fclCombineCreateSlotIcons(task, 0);
        fclCombineDrawSlotRows(task, 0);
        pos0 = fclMakeVec2(-78.0f, -82.0f);
        fclSpriteCreate(0x80, pos0, 220.0f, 0x3F);
        color0 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x80))->color = color0;
        fclSpriteStartTweenAt(0x80, 0, 0x5A0, 0, 0.0f, -360.0f);
        fclSpriteSetFlag(0x80, 6, 0);
        fclSpriteEntry(0x80)[0xDB] = 1;
        pos1 = fclMakeVec2(2.0f, -2.0f);
        pos2 = fclMakeVec2(-78.0f, -82.0f);
        fclSpriteStartPositionAt(0x80, pos1, pos2, 1, 0xA, 0);
        fclSpriteStartAlphaAt(0x80, 0, 0xFF, 2, 0xA, 0);
        pos3 = fclMakeVec2(540.0f, (f32)0x15B);
        fclSpriteCreate(0x20C, pos3, 220.0f, 0x3F);
        color1 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x20C))->color = color1;
        fclSpriteStartTweenAt(0x20C, 0, 0x5A0, 0, 0.0f, -360.0f);
        fclSpriteSetFlag(0x20C, 6, 0);
        fclSpriteEntry(0x20C)[0xDB] = 1;
        pos4 = fclMakeVec2(460.0f, (f32)0x10B);
        pos5 = fclMakeVec2(540.0f, (f32)0x15B);
        fclSpriteStartPositionAt(0x20C, pos4, pos5, 1, 0xA, 0);
        fclSpriteStartAlphaAt(0x20C, 0, 0xFF, 2, 0xA, 0);
        pos6 = fclMakeVec2(-190.0f, 200.0f);
        fclSpriteCreate(0x81, pos6, 215.0f, 0x56);
        color2 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(0x81))->color = color2;
        fclSpriteStartAlphaAt(0x81, 0, 0xFF, 0, 0xA, 0);
        ((FclCombineMenuSprite *)fclSpriteEntry(0x81))->value = 90.0f;
        vec = (FclVec2 *)D_00640C50;
        pos7 = fclMakeVec2(vec->x, vec->y);
        fclSpriteCreate(0x84, pos7, 217.0f, 0x40);
        fclSpriteStartAlphaAt(0x84, 0, 0xFF, 0, 0xA, 0);
        vec = (FclVec2 *)D_00640C58;
        pos8 = fclMakeVec2(vec->x, vec->y);
        fclSpriteCreate(0x85, pos8, 218.0f, 0x40);
        fclSpriteStartAlphaAt(0x85, 0, 0xFF, 0, 0xA, 0);
        fclCombineLayoutDetailSprites(task, 0);
        fclCombineSlideInSlotSprites(task, 0x92, 0);
        fclCombineFadeLabelSprites(task, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0);
        p[0x138] = 0;
        if (datGetFlag(0x1305) != 0 && datGetFlag(0x1308) == 0) {
            p[0x138] |= 2;
        }
        if (fclCombineClaimSlot(task) == 0) {
            p[1] = 0x18;
        }
        break;
    case 0x18:
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x1F4))->flags, 1) == 1) {
            break;
        }
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x1F6))->flags, 1) == 1) {
            break;
        }
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x1F8))->flags, 1) == 1) {
            break;
        }
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x1FA))->flags, 1) == 1) {
            break;
        }
        if (fclCombineRowsBusy(task) == 1) {
            break;
        }
        buttons = D_008C027A[0];
        if (buttons & 0x1000) {
            fclCombineStepSlotSelection(task, 1);
            break;
        }
        if (buttons & 0x4000) {
            fclCombineStepSlotSelection(task, 0);
            break;
        }
        buttons = D_008C024E[0];
        if (buttons & 0x40) {
            sdkSndStartStream(0, 0, 0, 1);
            for (n = 0; n < 3; n++) {
                off = n * 2;
                pos9 = fclMakeVec2(26.0f, (f32)(n * 34 + 87));
                /* measured: field typing changes 4145 normalized bytes in the full owner. */
                fclCombineDrawListRow(task, n, pos9, *(s16 *)(p + off + 0xB8), (s16)off, 1);
            }
            switch (p[0xB3]) {
            case 0:
                if (datGetFlag(0x131E) == 0) {
                    p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                    nmMesWindowShowSlotRecord(p[0xD], 0x4D);
                    datSetFlag(0x131E, 1);
                    p[1] = 0x22;
                } else {
                    fclCombineBuildRows(task);
                }
                break;
            case 1:
                if (datGetFlag(0x131B) == 0) {
                    p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                    nmMesWindowShowSlotRecord(p[0xD], 0x4F);
                    datSetFlag(0x131B, 1);
                    p[1] = 0x21;
                } else {
                    vec = (FclVec2 *)D_00641660;
                    pos10 = fclMakeVec2(vec->x, vec->y);
                    fclSpriteCreate(0x1C6, pos10, 242.0f, 0x3D);
                    fclSpriteStartAlphaAt(0x1C6, 0, 0x64, 0, 0xA, 0);
                    p[0xB6] = 0;
                    fclCombineDrawActionList(task);
                    fclCombineSlideInSlotSprites(task, 0x96, 0x92);
                    p[1] = 0x1B;
                }
                break;
            case 2:
                fclCombineLayoutDetailSprites(task, 1);
                fclCombineCreateSlotIcons(task, 1);
                fclCombineSlideInSlotSprites(task, 0, 0x92);
                fclCombineFadeLabelSprites(task, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0);
                fclSpriteStartAlphaAt(0x81, 0xFF, 0, 0, 6, 0);
                fclSpriteStartAlphaAt(0x80, 0xFF, 0, 2, 0xA, 0);
                fclSpriteStartAlphaAt(0x20C, 0xFF, 0, 2, 0xA, 0);
                fclSpriteStartAlphaAt(0x84, 0xFF, 0, 0, 6, 0);
                fclSpriteStartAlphaAt(0x85, 0xFF, 0, 0, 6, 0);
                for (n = 0; n < 3; n++) {
                    pos11 = fclMakeVec2(26.0f, (f32)(n * 34 + 87));
                    fclCombineDrawListRow(task, n, pos11, ((FclCombineMenu *)p)->selectedIds[n], 0, 1);
                }
                p[1] = 0x19;
                break;
            }
        } else if (buttons & 0x20) {
            fclCombineLayoutDetailSprites(task, 1);
            fclCombineCreateSlotIcons(task, 1);
            fclCombineSlideInSlotSprites(task, 0, 0x92);
            fclCombineFadeLabelSprites(task, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0);
            fclSpriteStartAlphaAt(0x81, 0xFF, 0, 0, 6, 0);
            fclSpriteStartAlphaAt(0x80, 0xFF, 0, 2, 0xA, 0);
            fclSpriteStartAlphaAt(0x20C, 0xFF, 0, 2, 0xA, 0);
            fclSpriteStartAlphaAt(0x84, 0xFF, 0, 0, 6, 0);
            fclSpriteStartAlphaAt(0x85, 0xFF, 0, 0, 6, 0);
            for (n = 0; n < 3; n++) {
                pos12 = fclMakeVec2(26.0f, (f32)(n * 34 + 87));
                fclCombineDrawListRow(task, n, pos12, ((FclCombineMenu *)p)->selectedIds[n], 0, 1);
            }
            p[1] = 0x19;
            sdkSndStartStream(0, 0, 0, 2);
        }
        break;
    case 0x22:
        if (nmMesWindowSlotStatus(p[0xD]) != 0) {
            nmMesWindowStepSlotRelease(p[0xD]);
            break;
        }
        nmMesWindowDestroySlot(p[0xD]);
        fclCombineBuildRows(task);
        break;
    case 0x21:
        if (nmMesWindowSlotStatus(p[0xD]) != 0) {
            nmMesWindowStepSlotRelease(p[0xD]);
            break;
        }
        nmMesWindowDestroySlot(p[0xD]);
        vec = (FclVec2 *)D_00641660;
        pos13 = fclMakeVec2(vec->x, vec->y);
        fclSpriteCreate(0x1C6, pos13, 242.0f, 0x3D);
        fclSpriteStartAlphaAt(0x1C6, 0, 0x64, 0, 0xA, 0);
        p[0xB6] = 0;
        fclCombineDrawActionList(task);
        fclCombineSlideInSlotSprites(task, 0x96, 0x92);
        p[1] = 0x1B;
        break;
    case 0x19:
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x1F4))->flags, 1) == 1) {
            break;
        }
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x92))->flags, 1) == 1) {
            break;
        }
        p[0] = 0xB;
        break;
    case 0x97:
        if (nmMesWindowSlotStatus(p[0xD]) != 0) {
            nmMesWindowStepSlotRelease(p[0xD]);
            break;
        }
        nmMesWindowDestroySlot(p[0xD]);
        if (fclCombineClaimSlot(task) == 0) {
            p[1] = 0x18;
        }
        break;
    case 0x1A:
        if (fclCombineRowsBusy(task) == 1) {
            break;
        }
        fclSpriteSetHidden(((FclCombineMenu *)p)->headerTask.task, 0);
        fclSpriteSetHidden(((FclCombineMenu *)p)->arrowTask.task, 0);
        buttons = D_008C027A[0];
        if (buttons & 0x8000) {
            p[0xB4] = fclSubClamped(p[0xB4], 1, 0, p[0xB5] - 1, 2);
            fclCombineMarkRow(((FclCombineRow *)(p + 0xC4))[p[0xB4]].id);
            sdkSndStartStream(0, 0, 0, 0);
            for (n = 0; n < p[0xB5]; n++) {
                fclCombineUpdateEntryHighlight(task, n, ((FclCombineMenu *)p)->commandRows[n].id, ((FclCombineMenu *)p)->commandRows[n].x, ((FclCombineMenu *)p)->commandRows[n].y);
            }
        } else if (buttons & 0x2000) {
            p[0xB4] = fclAddClamped(p[0xB4], 1, p[0xB5] - 1, 0, 2);
            fclCombineMarkRow(((FclCombineRow *)(p + 0xC4))[p[0xB4]].id);
            sdkSndStartStream(0, 0, 0, 0);
            for (n = 0; n < p[0xB5]; n++) {
                fclCombineUpdateEntryHighlight(task, n, ((FclCombineMenu *)p)->commandRows[n].id, ((FclCombineMenu *)p)->commandRows[n].x, ((FclCombineMenu *)p)->commandRows[n].y);
            }
        } else {
            buttons = D_008C024E[0];
            if (buttons & 0x40) {
                fclSpriteSetFlag(0x2F2, 0, 1);
                sdkSndStartStream(0, 0, 0, 1);
                if (((FclCombineRow *)(p + 0xC4))[p[0xB4]].id == 8) {
                    if (fclCombineClaimSlot(task) == 0) {
                        p[1] = 0x18;
                    }
                    fclCombineLayoutTransition(task, 1);
                    fclCombineDrawSlotRows(task, 0);
                    fclCombineSlideInSlotSprites(task, 0x92, 0x96);
                    fclSpriteStartAlphaAt(0x1C6, fclSpriteEntry(0x1C6)[0x6E], 0, 0, 0xA, 0);
                } else {
                    p[1] = 0x1C;
                }
            } else if (buttons & 0x20) {
                fclSpriteSetFlag(0x2F2, 0, 1);
                if (fclCombineClaimSlot(task) == 0) {
                    p[1] = 0x18;
                }
                fclCombineLayoutTransition(task, 1);
                sdkSndStartStream(0, 0, 0, 2);
                fclCombineDrawSlotRows(task, 0);
                fclCombineSlideInSlotSprites(task, 0x92, 0x96);
                fclSpriteStartAlphaAt(0x1C6, fclSpriteEntry(0x1C6)[0x6E], 0, 0, 0xA, 0);
            }
        }
        break;
    case 0x1C:
        fclCombineLayoutTransition(task, 1);
        p[0] = ((FclCombineRow *)(p + 0xC4))[p[0xB4]].state0;
        p[1] = ((FclCombineRow *)(p + 0xC4))[p[0xB4]].state1;
        break;
    case 0x1B:
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry((p[0xB7] + 3) * 2 + 0x1F4))->flags, 1) == 1) {
            break;
        }
        buttons = D_008C027A[0];
        if (buttons & 0x1000) {
            sdkSndStartStream(0, 0, 0, 0);
            menu = fclCombineMapSlotKind(p[0xB6]);
            color3 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
            color4 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
            color5 = fclMakeDrawColor(0x25, 0x2F, 0x94, 0xFF);
            fclCombineSetSlotColors(task, menu, color3, color4, color5);
            if (datGetFlag(0x1306) != 0) {
                p[0xB6] = fclSubClamped(p[0xB6], 1, 0, (s16)(p[0xB7] - 2), 2);
            } else {
                p[0xB6] = fclSubClamped(p[0xB6], 1, 0, (s16)(p[0xB7] - 1), 2);
            }
            menu = fclCombineMapSlotKind(p[0xB6]);
            color6 = fclMakeDrawColor(0xC6, 0xEE, 1, 0xFF);
            color7 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            color8 = fclMakeDrawColor(0x92, 0xC8, 7, 0xFF);
            fclCombineSetSlotColors(task, menu, color6, color7, color8);
            break;
        }
        if (buttons & 0x4000) {
            sdkSndStartStream(0, 0, 0, 0);
            menu = fclCombineMapSlotKind(p[0xB6]);
            color9 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
            color10 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
            color11 = fclMakeDrawColor(0x25, 0x2F, 0x94, 0xFF);
            fclCombineSetSlotColors(task, menu, color9, color10, color11);
            if (datGetFlag(0x1306) != 0) {
                p[0xB6] = fclAddClamped(p[0xB6], 1, (s16)(p[0xB7] - 2), 0, 2);
            } else {
                p[0xB6] = fclAddClamped(p[0xB6], 1, (s16)(p[0xB7] - 1), 0, 2);
            }
            menu = fclCombineMapSlotKind(p[0xB6]);
            color12 = fclMakeDrawColor(0xC6, 0xEE, 1, 0xFF);
            color13 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            color14 = fclMakeDrawColor(0x92, 0xC8, 7, 0xFF);
            fclCombineSetSlotColors(task, menu, color12, color13, color14);
            break;
        }
        buttons = D_008C024E[0];
        if (buttons & 0x40) {
            sdkSndStartStream(0, 0, 0, 1);
            if (p[0xB6] == p[0xB7] - 1) {
                for (j = 0; j < p[0xB7]; j++) {
                    slotPos0 = ((FclCombineRowSprite *)fclSpriteEntry((j + 4) * 2 + 0x1F4))->position;
                    fclCombineDrawListRow(task, j + 4, slotPos0, ((FclCombineMenu *)p)->selectedIds[j], (s16)(j * 2), 1);
                }
                fclCombineDrawSlotRows(task, 3);
                fclCombineSlideInSlotSprites(task, 0x92, 0x96);
                fclSpriteStartAlphaAt(0x1C6, fclSpriteEntry(0x1C6)[0x6E], 0, 0, 0xA, 0);
                if (fclCombineClaimSlot(task) == 0) {
                    p[1] = 0x18;
                }
            } else {
                for (j = 0; j < p[0xB7]; j++) {
                    slotPos2 = ((FclCombineRowSprite *)fclSpriteEntry((j + 4) * 2 + 0x1F4))->position;
                    fclCombineDrawListRow(task, j + 4, slotPos2, ((FclCombineMenu *)p)->selectedIds[j], (s16)(j * 2), 1);
                }
                switch (p[0xB6]) {
                case 0:
                    ((u8 *)p)[1] = 0x8A;
                    p[0] = 0xF;
                    fclCombineSlideInSlotSprites(task, 0x117, 0x96);
                    break;
                case 1:
                    ((u8 *)p)[1] = 0x8A;
                    p[0] = 0x10;
                    fclCombineSlideInSlotSprites(task, 0x118, 0x96);
                    break;
                case 2:
                    if (datGetFlag(0x1305) != 0) {
                        p[0] = 8;
                        p[1] = 0x75;
                    } else {
                        p[0] = 0xA;
                        ((u8 *)p)[1] = 0xC2;
                    }
                    break;
                case 3:
                    if (datGetFlag(0x1305) != 0) {
                        p[0] = 0xA;
                        ((u8 *)p)[1] = 0xC2;
                    } else {
                        fclCombineDrawSlotRows(task, 3);
                        fclCombineSlideInSlotSprites(task, 0x92, 0x96);
                        if (fclCombineClaimSlot(task) == 0) {
                            p[1] = 0x18;
                        }
                    }
                    break;
                case 4:
                    if (datGetFlag(0x1305) != 0) {
                        fclCombineDrawSlotRows(task, 3);
                        fclCombineSlideInSlotSprites(task, 0x92, 0x96);
                        if (fclCombineClaimSlot(task) == 0) {
                            p[1] = 0x18;
                        }
                    }
                    break;
                }
            }
        } else if (buttons & 0x20) {
            for (j = 0; j < p[0xB7]; j++) {
                slotPos1 = ((FclCombineRowSprite *)fclSpriteEntry((j + 4) * 2 + 0x1F4))->position;
                fclCombineDrawListRow(task, j + 4, slotPos1, ((FclCombineMenu *)p)->selectedIds[j], (s16)(j * 2), 1);
            }
            fclCombineDrawSlotRows(task, 3);
            fclSpriteStartAlphaAt(0x1C6, fclSpriteEntry(0x1C6)[0x6E], 0, 0, 0xA, 0);
            fclCombineSlideInSlotSprites(task, 0x92, 0x96);
            if (fclCombineClaimSlot(task) == 0) {
                p[1] = 0x18;
            }
            sdkSndStartStream(0, 0, 0, 2);
        }
        break;
    case 0x20:
        if (nmMesWindowSlotStatus(p[0xD]) != 0) {
            nmMesWindowStepSlotRelease(p[0xD]);
            break;
        }
        nmMesWindowDestroySlot(p[0xD]);
        for (j = 0; j < p[0xB7]; j++) {
            off = j * 2;
            pos14 = fclMakeVec2(26.0f, (f32)(j * 34 + 87));
            /* measured: field typing changes 458 normalized bytes in the full owner. */
            fclCombineDrawListRow(task, j + 4, pos14, *(s16 *)(p + off + 0xB8), (s16)off, 0);
        }
        color15 = fclMakeDrawColor(0xC6, 0xEE, 1, 0xFF);
        te = fclSpriteEntry((p[0xB6] + 4) * 2 + 0x1F5);
        ((FclCombineRowSprite *)te)->color = color15;
        /* measured: field typing changes 8 normalized bytes in the full owner. */
        ((FclCombineRowSprite *)fclSpriteEntry((p[0xB6] + 4) * 2 + 0x1F4))->color = *(FclDrawColor *)(te + 0x85);
        color16 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(((s16 *)(p + 0xB8))[p[0xB6]]))->color = color16;
        color17 = fclMakeDrawColor(0x92, 0xC8, 7, 0xFF);
        ((FclCombineRowSprite *)fclSpriteEntry(p[0xB6] + 0x2FF))->color = color17;
        p[1] = 0x1B;
        break;
    }
}
#pragma pop

/* One 12-byte slot of the combine layout tables at D_00640760 / D_006407C0. */
typedef struct {
    f32 x;
    f32 y;
    s16 col;
    s16 row;
} FclCombineLayoutSlot;

/* Layout 8 gives the consecutive left and right/central phases their own
   transition values. The real aggregate-return position temporaries remain
   at every placement. See docs/probe_archive/FclCombine_002eb270_20261004.md. */
// Fcl combine layout transition: transition 0 slides the layout in; any other value slides it out with jitter.
// FUN_002EB270
void fclCombineLayoutTransition(u8 *task, s32 transition) {
    extern u8 D_006407F0[];
    FclCombineLayoutSlot *slot;
    u8 *work;
    s16 jitter;

    /* Only the signed low byte selects the transition: zero enters, every
       other value exits, and one also hides the six selection overlays. */
    work = ((u8*)((KwlnTask *)task)->work);
    if (((FclCombineMenu *)(work))->commandCount % 2 == 0) {
        if (((FclCombineMenu *)(work))->commandCount == 6) {
            s32 transition6;
            s16 left6;

            for (left6 = 0, transition6 = (s8)transition; left6 < 3; left6++) {
                slot = (FclCombineLayoutSlot *)D_00640760 + (left6 + 1);
                if (transition6 == 0) {
                    fclCombineDrawEntryCell(task, fclMakeVec2(-200.0f, 100.0f + slot->y), fclMakeVec2(slot->x, slot->y), left6, left6 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    ((FclCombineMenu *)(work))->commandRows[left6].x = slot->col * 3 + 0x3E;
                    ((FclCombineMenu *)(work))->commandRows[left6].y = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(-300.0f, slot->y + jitter), left6, left6 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_006407A8;
            if (transition6 == 0) {
                fclCombineDrawEntryCell(task, fclMakeVec2(700.0f, 100.0f + slot->y), fclMakeVec2(slot->x, slot->y), 8, 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                ((FclCombineMenu *)(work))->commandRows[5].x = slot->col * 3 + 0x3E;
                ((FclCombineMenu *)(work))->commandRows[5].y = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(700.0f, slot->y + jitter), 8, 1, slot->col * 3 + 0x3E, slot->row + 0x57);
            }
            slot = (FclCombineLayoutSlot *)D_0064079C;
            if (transition6 == 0) {
                fclCombineDrawEntryCell(task, fclMakeVec2(700.0f, 100.0f + slot->y), fclMakeVec2(slot->x, slot->y), 7, 6, slot->col * 3 + 0x3E, slot->row + 0x57);
                ((FclCombineMenu *)(work))->commandRows[4].x = slot->col * 3 + 0x3E;
                ((FclCombineMenu *)(work))->commandRows[4].y = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(700.0f, slot->y + jitter), 7, 3, slot->col * 3 + 0x3E, slot->row + 0x57);
            }
            slot = (FclCombineLayoutSlot *)D_00640790;
            if (transition6 == 0) {
                fclCombineDrawEntryCell(task, fclMakeVec2(700.0f, 100.0f + slot->y), fclMakeVec2(slot->x, slot->y), 6, 0xA, slot->col * 3 + 0x3E, slot->row + 0x57);
                ((FclCombineMenu *)(work))->commandRows[3].x = slot->col * 3 + 0x3E;
                ((FclCombineMenu *)(work))->commandRows[3].y = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(700.0f, slot->y + jitter), 6, 5, slot->col * 3 + 0x3E, slot->row + 0x57);
            }
        } else if (((FclCombineMenu *)(work))->commandCount == 8) {
            s32 leftTransition8;
            s32 rightTransition8;
            s16 left8;
            s16 right8;

            /* Each edge traversal owns its transition value. */
            for (left8 = 0, leftTransition8 = (s8)transition; left8 < 4; left8++) {
                slot = (FclCombineLayoutSlot *)D_00640760 + left8;
                if (leftTransition8 == 0) {
                    fclCombineDrawEntryCell(task, fclMakeVec2(-200.0f, 100.0f + slot->y), fclMakeVec2(slot->x, slot->y), left8, left8 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    ((FclCombineMenu *)(work))->commandRows[left8].x = slot->col * 3 + 0x3E;
                    ((FclCombineMenu *)(work))->commandRows[left8].y = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(-300.0f, slot->y + jitter), left8, left8 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            /* The left phase has finished; carry its mode into the right
               traversal and the remaining central placement. */
            for (right8 = 0, rightTransition8 = leftTransition8; right8 < 3; right8++) {
                slot = (FclCombineLayoutSlot *)D_00640760 + (7 - right8);
                if (rightTransition8 == 0) {
                    fclCombineDrawEntryCell(task, fclMakeVec2(700.0f, 100.0f + slot->y), fclMakeVec2(slot->x, slot->y), 8 - right8, right8 * 4 + 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                    ((FclCombineMenu *)(work))->commandRows[(7 - right8)].x = slot->col * 3 + 0x3E;
                    ((FclCombineMenu *)(work))->commandRows[(7 - right8)].y = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(700.0f, slot->y + jitter), 8 - right8, right8 * 2 + 1, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_00640790;
            if (rightTransition8 == 0) {
                fclCombineDrawEntryCell(task, fclMakeVec2(700.0f, 100.0f + slot->y), fclMakeVec2(slot->x, slot->y), 4, 0xE, slot->col * 3 + 0x3E, slot->row + 0x57);
                ((FclCombineMenu *)(work))->commandRows[4].x = slot->col * 3 + 0x3E;
                ((FclCombineMenu *)(work))->commandRows[4].y = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(700.0f, slot->y + jitter), 4, 7, slot->col * 3 + 0x3E, slot->row + 0x57);
            }
        }
    } else {
        if (((FclCombineMenu *)(work))->commandCount == 5) {
            s32 transition5;
            s16 pair5;

            for (pair5 = 0, transition5 = (s8)transition; pair5 < 2; pair5++) {
                slot = (FclCombineLayoutSlot *)D_006407C0 + (pair5 + 2);
                if (transition5 == 0) {
                    fclCombineDrawEntryCell(task, fclMakeVec2(-200.0f, 100.0f + slot->y), fclMakeVec2(slot->x, slot->y), pair5, pair5 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    ((FclCombineMenu *)(work))->commandRows[pair5].x = slot->col * 3 + 0x3E;
                    ((FclCombineMenu *)(work))->commandRows[pair5].y = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(-300.0f, slot->y + jitter), pair5, pair5 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
                slot = (FclCombineLayoutSlot *)D_006407C0 + (6 - pair5);
                if (transition5 == 0) {
                    fclCombineDrawEntryCell(task, fclMakeVec2(700.0f, 100.0f + slot->y), fclMakeVec2(slot->x, slot->y), 8 - pair5, pair5 * 4 + 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                    ((FclCombineMenu *)(work))->commandRows[(4 - pair5)].x = slot->col * 3 + 0x3E;
                    ((FclCombineMenu *)(work))->commandRows[(4 - pair5)].y = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(700.0f, slot->y + jitter), 8 - pair5, pair5 * 2 + 1, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_006407F0;
            if (transition5 == 0) {
                fclCombineDrawEntryCell(task, fclMakeVec2(-200.0f, 100.0f + slot->y), fclMakeVec2(slot->x, slot->y), 6, 8, slot->col * 3 + 0x3E, slot->row + 0x57);
                ((FclCombineMenu *)(work))->commandRows[2].x = slot->col * 3 + 0x3E;
                ((FclCombineMenu *)(work))->commandRows[2].y = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                if (RpRandom() % 100 >= 50) {
                    fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(-300.0f, slot->y + jitter), 6, 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                } else {
                    fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(700.0f, slot->y + jitter), 6, 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
        } else if (((FclCombineMenu *)(work))->commandCount == 7) {
            s32 transition7;
            s16 pair7;

            for (pair7 = 0, transition7 = (s8)transition; pair7 < 3; pair7++) {
                slot = (FclCombineLayoutSlot *)D_006407C0 + (pair7 + 1);
                if (transition7 == 0) {
                    fclCombineDrawEntryCell(task, fclMakeVec2(-200.0f, 100.0f + slot->y), fclMakeVec2(slot->x, slot->y), pair7, pair7 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    ((FclCombineMenu *)(work))->commandRows[pair7].x = slot->col * 3 + 0x3E;
                    ((FclCombineMenu *)(work))->commandRows[pair7].y = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(-300.0f, slot->y + jitter), pair7, pair7 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
                slot = (FclCombineLayoutSlot *)D_006407C0 + (7 - pair7);
                if (transition7 == 0) {
                    fclCombineDrawEntryCell(task, fclMakeVec2(700.0f, 100.0f + slot->y), fclMakeVec2(slot->x, slot->y), 8 - pair7, pair7 * 4 + 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                    ((FclCombineMenu *)(work))->commandRows[(6 - pair7)].x = slot->col * 3 + 0x3E;
                    ((FclCombineMenu *)(work))->commandRows[(6 - pair7)].y = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(700.0f, slot->y + jitter), 8 - pair7, pair7 * 2 + 1, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_006407F0;
            if (transition7 == 0) {
                fclCombineDrawEntryCell(task, fclMakeVec2(-200.0f, 100.0f + slot->y), fclMakeVec2(slot->x, slot->y), 3, 0xC, slot->col * 3 + 0x3E, slot->row + 0x57);
                ((FclCombineMenu *)(work))->commandRows[3].x = slot->col * 3 + 0x3E;
                ((FclCombineMenu *)(work))->commandRows[3].y = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                if (RpRandom() % 100 >= 50) {
                    fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(-300.0f, slot->y + jitter), 3, 6, slot->col * 3 + 0x3E, slot->row + 0x57);
                } else {
                    fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(700.0f, slot->y + jitter), 3, 6, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
        } else if (((FclCombineMenu *)(work))->commandCount == 9) {
            s32 transition9;
            s16 pair9;

            for (pair9 = 0, transition9 = (s8)transition; pair9 < 4; pair9++) {
                slot = (FclCombineLayoutSlot *)D_006407C0 + pair9;
                if (transition9 == 0) {
                    fclCombineDrawEntryCell(task, fclMakeVec2(-200.0f, 100.0f + slot->y), fclMakeVec2(slot->x, slot->y), pair9, pair9 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    ((FclCombineMenu *)(work))->commandRows[pair9].x = slot->col * 3 + 0x3E;
                    ((FclCombineMenu *)(work))->commandRows[pair9].y = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(-300.0f, slot->y + jitter), pair9, pair9 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
                slot = (FclCombineLayoutSlot *)D_006407C0 + (8 - pair9);
                if (transition9 == 0) {
                    fclCombineDrawEntryCell(task, fclMakeVec2(700.0f, 100.0f + slot->y), fclMakeVec2(slot->x, slot->y), 8 - pair9, pair9 * 4 + 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                    ((FclCombineMenu *)(work))->commandRows[(8 - pair9)].x = slot->col * 3 + 0x3E;
                    ((FclCombineMenu *)(work))->commandRows[(8 - pair9)].y = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(700.0f, slot->y + jitter), 8 - pair9, pair9 * 2 + 1, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_006407F0;
            if (transition9 == 0) {
                fclCombineDrawEntryCell(task, fclMakeVec2(-200.0f, 100.0f + slot->y), fclMakeVec2(slot->x, slot->y), 4, 0x10, slot->col * 3 + 0x3E, slot->row + 0x57);
                ((FclCombineMenu *)(work))->commandRows[4].x = slot->col * 3 + 0x3E;
                ((FclCombineMenu *)(work))->commandRows[4].y = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                if (RpRandom() % 100 >= 50) {
                    fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(-300.0f, slot->y + jitter), 4, 8, slot->col * 3 + 0x3E, slot->row + 0x57);
                } else {
                    fclCombineDrawEntryCell(task, fclMakeVec2(slot->x, slot->y), fclMakeVec2(700.0f, slot->y + jitter), 4, 8, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
        }
    }
    /* Each resource is looked up again after hiding it in retail. */
    if ((s8)transition == 1) {
        fclSpriteEntry(0x216)[0x73] = 0;
        fclSpriteEntry(0x216);
        fclSpriteEntry(0x217)[0x73] = 0;
        fclSpriteEntry(0x217);
        fclSpriteEntry(0x218)[0x73] = 0;
        fclSpriteEntry(0x218);
        fclSpriteEntry(0x219)[0x73] = 0;
        fclSpriteEntry(0x219);
        fclSpriteEntry(0x21A)[0x73] = 0;
        fclSpriteEntry(0x21A);
        fclSpriteEntry(0x21B)[0x73] = 0;
        fclSpriteEntry(0x21B);
    }
}


/* measured: full body now MATCH (object 1136B, retail window 1136B).
   The stack argument/global load is forced in retail order with the named
   FclVec2f base. Table stores use an integer-domain scaled offset so the
   addu has the retail offset-first operand order; direct byte increments
   preserve retail's store-before-next-index schedule. */
// Fcl combine rows: builds the 10-byte combine row table (ids and sprite offsets) and creates the first row sprite.
// FUN_002ECFC0
/* Historical whole-layout probe: 54 normalized bytes differed (2026-10-18).
   Individual indexed stores still require the documented index-first address. */
void fclCombineBuildRows(u8 *task) {
    FclVec2 position;
    u8 *menuWork;
    FclVec2f *base;

    menuWork = ((u8*)((KwlnTask *)task)->work);
    base = (FclVec2f *)D_00641660;
    position = fclMakeVec2(base->x, base->y);
    fclSpriteCreate(0x1C6, position, 242.0f, 0x3D);
    fclSpriteStartAlphaAt(0x1C6, 0, 0x64, 0, 0xA, 0);
    ((FclCombineMenu *)(menuWork))->commandCursor = 0;
    ((FclCombineMenu *)(menuWork))->commandCount = 0;
    /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
    *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC4) = 1;
    /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
    *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC6) = 0x23;
    /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
    *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC8) = 0;
    ((FclCombineMenu *)(menuWork))->commandCount = ((FclCombineMenu *)(menuWork))->commandCount + 1;
    /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
    *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC4) = 2;
    /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
    *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC6) = 0x38;
    /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
    *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC8) = 1;
    ((FclCombineMenu *)(menuWork))->commandCount = ((FclCombineMenu *)(menuWork))->commandCount + 1;
    if (datGetFlag(0x1301) != 0) {
        /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
        *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC4) = 3;
        /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
        *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC6) = 0x51;
        /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
        *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC8) = 2;
        ((FclCombineMenu *)(menuWork))->commandCount = ((FclCombineMenu *)(menuWork))->commandCount + 1;
    }
    if (datGetFlag(0x1302) != 0) {
        /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
        *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC4) = 4;
        /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
        *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC6) = 0x51;
        /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
        *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC8) = 3;
        ((FclCombineMenu *)(menuWork))->commandCount = ((FclCombineMenu *)(menuWork))->commandCount + 1;
    }
    if (datGetFlag(0x1303) != 0) {
        /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
        *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC4) = 5;
        /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
        *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC6) = 0x51;
        /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
        *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC8) = 4;
        ((FclCombineMenu *)(menuWork))->commandCount = ((FclCombineMenu *)(menuWork))->commandCount + 1;
    }
    if (datGetFlag(0x1304) != 0) {
        /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
        *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC4) = 6;
        /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
        *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC6) = 0x63;
        /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
        *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC8) = 5;
        ((FclCombineMenu *)(menuWork))->commandCount = ((FclCombineMenu *)(menuWork))->commandCount + 1;
    }
    /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
    *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC4) = 7;
    /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
    *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC6) = 0x6E;
    /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
    *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC8) = 6;
    ((FclCombineMenu *)(menuWork))->commandCount = ((FclCombineMenu *)(menuWork))->commandCount + 1;
    /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
    *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC4) = 9;
    /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
    *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC6) = 0xC2;
    /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
    *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC8) = 7;
    ((FclCombineMenu *)(menuWork))->commandCount = ((FclCombineMenu *)(menuWork))->commandCount + 1;
    /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
    *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC4) = 0xB;
    /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
    *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC6) = 0xD8;
    /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
    *(s16 *)((u8 *)(((FclCombineMenu *)(menuWork))->commandCount * 10) + (u32)menuWork + 0xC8) = 8;
    ((FclCombineMenu *)(menuWork))->commandCount = ((FclCombineMenu *)(menuWork))->commandCount + 1;
    fclCombineLayoutTransition(task, 0);
    fclCombineSlideInSlotSprites(task, 0x96, 0x92);
    ((FclCombineMenu *)(menuWork))->f1 = 0x1A;
}
/* measured 002ed430 2026-09-19: object 3816 against retail's 3764 instructions, +1.38% inside the 3651-3877 band with
   61 instructions of headroom; 2865 fnalign edits (+10 reloc-only), 3139 differing words.
   No pragmas: retail here is unscheduled like the rest of this unit.
   Built from an m2c oracle (since removed), de-noised to this file's idiom - field macros expanded to direct
   casts, the gp temporaries resolved to ((s32)iGpffffb440) and ((s32)iGpffffb3d4), the six error-marked
   ldr/ldl sites written as struct-by-value `*(FclVec2f *)(ps + 0x38)` with `ps = fclSpriteEntry(0x151/0x2E0)`,
   the 11 colour bases with their unknown-type companions folded to u8 colXXX[4] (`&sp` -> col, `sp` -> col[0],
   `(s32)sp` -> (*(s32 *)col)), the (s32)(sp)+0x110/0xF0 stores rewritten as sp110[]/spF0[] (u16[16]),
   37 s64 temporaries narrowed to s32 (3963 -> 3659) with four - var_16, var_16_2, var_16_3, var_17_2 - kept s64
   to land 3659 inside the band, the switch-3 labels restored as case 0-2 (retail jtbl, +157 to 3816, still inside),
   the m2c arg-count hallucinations on fclSpriteEntry/func_0010b5b0/fclCombineRowsBusy/fclDrawGetState/fclSpriteFlagBit/
   nmMesWindowSlotStatus/func_00122720 cut back to the retail arg counts, the (f32)(s32) float wrappers collapsed
   (0x437F0000->255.0f, 0x43000000->128.0f, 0x422C0000->43.0f), and D_008C027A/024E to [0]. */
/* measured 002ed430 (owner, 2026-09-19): fnalign **2865 -> 2856 edits**, count
   3816 -> 3814 against retail 3764, by writing m2c's top-tested `loop_N:` /
   `if (cond) { ...; goto loop_N; }` as the `do { } while (cond)` retail actually
   emits.  The m2c shape tests at the TOP of every iteration; retail's only compare is
   at the bottom, ending in `bnez ..., .-N`, with no guard before the first pass.
   Swept across the 44 first-party floors carrying the pattern: 21 improved in-gate,
   2 improved but fell outside the band and were left alone (func_0037da60 574 -> 569,
   func_002e4ac0 334 -> 329), and 7 got worse - notably func_002ac750 842 -> 857 and
   func_00468ff0 310 -> 323 - so it is measured per loop, not applied on sight. */
/* measured 002ed430 (2026-09-20): deficit_scan first per assignment - retail 3764 vs object 3814 (+50, +1.3% INSIDE) so deficit -50 and every retail-only run is CROSS (227 at 0x002efe74, 103 at 0x002ef934, 98 at 0x002eea48, all > deficit). Opcode delta BOTH directions: retail has more lb +22/bnez +12/addu +12, object has more dsll32 +43/dsra32 +42/mtc1 +16/mov.s +10/lui +7/cvt.s.w +5 - the surplus names double-extends + float conversions, as on func_0026a020 (mul.s/lui/mtc1 vs add.s doubling idiom, -66 there). Fixed: func_00275820 (f32x3->s32x3, 7 calls, each saved mtc1/lui/cvt), fclEaseInterpolate (s32,s32->s32,f32 + 0->0.0f at both calls), fclSpriteSetFlag (s32->s16 first), var_16/var_16_2/var_16_3/var_17_2 s64->s16 with (s8)/(s16) loop rewrites, *func_002e4870 u8->s8 (3 sites + 0xD), and 38x (s64)(<<0x30/0x38) to (s16)/(s8) for 0x128+1/00314660/fclSpriteEntry narrow params. fnalign **2856 -> 2559 edits** (-297, +31 reloc-only), count **3814 -> 3693** (-121) vs retail 3761 trimmed (-68, -1.8% INSIDE 3648-3874). Remaining retail dsll32 +19/dsra32 +20 vs object addiu +41/move +14 are CROSS (all long runs still > deficit 68), no ABSENT. */
/* measured: 15048 executable bytes / 15056B retail window, zero differing words.
   Keys: the colour branches of state 0x2A build their 0x270 sprite id as an
   unsigned sum, so it is not CSE'd with the alpha lookup's id and its spill
   gives retail's 0x260 frame; func_00275820 uses its real (f32 x, f32 y,
   f32 scale, ...) signature; `> 5` for the menu range test; store-then-reread
   of f11E/f2FA; fclDrawSetPlacementEx takes the slot byte as s8. */

typedef struct {
    u8 pad0[0x2E4];
    s8 f2E4;
} FclPartySlot;

/* measured: 15048B/window 15056B, eight zero alignment bytes. See
   docs/probe_archive/FclCombine_002ed430_recovery_20260925.md. */
// Fcl combine menu fusion (state 1): the fusion core. Shows the partner grid (0x2A) for the selected source, confirms with cues and money and duplicate checks (0x2D-0x31), rolls the rare chance (0x34), builds the result list with inherited skills (0x36-0x37), then hands to the result handler (state 0x0D, sub-state 0xC5).
// FUN_002ED430
/* Historical whole-layout probe: 10602 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
void fclCombineMenuFusion(u8 *task) {
    extern void fclCombineMaterialListBuild(s8);
    extern f32 D_00640E70[];
    s16 nearestLevelDifference;
    u8 *ps;
    FclDrawColor gridBaseColor;
    FclDrawColor selectedRowColor;
    FclDrawColor selectedNumberColor;
    FclDrawColor selectedDigitColor;
    FclDrawColor specialRowColor;
    FclDrawColor specialNumberColor;
    FclDrawColor specialDigitColor;
    FclDrawColor normalRowColor;
    FclDrawColor normalLabelColor;
    FclDrawColor normalNumberColor;
    FclDrawColor normalDigitColor;
    FclPackedPosition position2;
    FclVec2 position3;
    FclPackedPosition position4;
    FclPackedPosition position5;
    FclVec2 position6;
    FclVec2 position7;
    FclPackedPosition position8;
    FclPackedPosition position9;
    FclVec2 position10;
    FclVec2 position11;
    FclPackedPosition position12;
    FclPackedPosition position13;
    FclVec2 position14;
    FclPackedPosition position15;
    FclPackedPosition position16;
    FclPackedPosition position17;
    FclVec2 position18;
    FclVec2 position19;
    FclVec2 position20;
    FclVec2 position21;
    FclVec2 position22;
    FclVec2 position23;
    FclPackedPosition position24;
    FclPackedPosition position25;
    FclVec2 position26;
    FclVec2 position27;
    FclVec2f position28;
    FclVec2f position29;
    FclVec2f position30;
    FclVec2f position31;
    FclVec2f position32;
    u16 excludedIds[16];
    u16 excludedLevelIds[16];
    u8 spriteValue;
    s32 selectedSpriteId;
    s8 rareChanceKind;
    f32 coordinate;
    f32 coordinate2;
    f32 textYOrFrame;
    f32 partnerYOrFrame;
    s32 value;
    s16 *entry;
    s16 value2;
    s16 value3;
    s32 textColor;
    s32 personaModel;
    s32 textColor2;
    s32 textColor3;
    s32 personaModel2;
    s32 personaModel3;
    s32 personaModel4;
    s32 personaModel5;
    s32 personaModel6;
    s32 personaModel7;
    s32 personaModel8;
    s32 personaModel9;
    s32 personaModel10;
    s32 personaModel11;
    s32 personaModel12;
    s32 textColor4;
    s32 textColor5;
    s32 textColor6;
    s32 textColor7;
    s32 value4;
    s32 value5;
    s32 value6;
    s32 resultIndex;
    s32 value7;
    s32 value8;
    s32 value9;
    s32 value10;
    s32 value11;
    s32 value12;
    s32 value13;
    s32 value14;
    s32 value15;
    s32 value16;
    s32 community;
    s32 community2;
    s32 community3;
    s16 entryCount;
    s32 value17;
    s32 value18;
    s32 value19;
    s32 spriteId;
    s32 spriteId2;
    s32 spriteId3;
    s32 spriteId4;
    s32 spriteId5;
    s32 spriteId6;
    s16 rosterIndex;
    s16 rosterIndex2;
    s16 index;
    s16 index2;
    s16 index3;
    s16 rosterIndex3;
    s16 rosterIndex4;
    s16 rosterIndex5;
    s16 rosterIndex6;
    s16 rosterIndex7;
    s16 skillIndex;
    s16 index4;
    s16 resultIndex2;
    s16 skillIndex2;
    s16 rosterIndex8;
    s16 rosterIndex9;
    s8 resultIndex3;
    s8 resultIndex4;
    s8 value20;
    s8 previewSelection;
    s8 previewSelection2;
    s8 value21;
    u16 *personaRecord;
    u16 *personaRecord2;
    u16 *personaRecord3;
    u16 *personaRecord4;
    u16 *personaRecord5;
    s32 firstSelection;
    s32 firstSelection2;
    s32 firstSelection3;
    u16 resultIndex7;
    u16 resultIndex8;
    u16 firstSelection4;
    u16 firstSelection5;
    u16 resultList4;
    s32 firstSelection6;
    s32 firstSelection7;
    u32 entryCount2;
    u32 randomValue;
    u8 spriteAlpha;
    s32 resultIndex9;
    s32 resultIndex10;
    s32 resultIndex11;
    u8 spriteAlpha2;
    u8 spriteAlpha3;
    u8 level;
    s32 level2;
    s32 resultIndex12;
    s32 value22;
    u8 state;
    u8 value23;
    u8 value24;
    u8 value25;
    u8 value26;
    u8 spriteValue2;
    FclPartySlot *partySlot;
    FclPartySlot *partySlot2;
    FclPartySlot *partySlot3;
    FclCombineWork *menuWork;
    FclCombineWork *menuWork2;
    FclCombineWork *menuWork3;
    FclCombineWork *menuWork4;
    u8 slotByte;
    s32 slotMode;
    FclVec2f *basePos;
    u8 *entry2;
    u8 *entry3;
    u8 *sprite6;
    u8 *entry4;
    u8 *sprite7;
    u8 *entry5;
    u8 *entry6;
    u8 *sprite8;
    u8 *sprite9;
    u8 *sprite10;
    u8 *sprite11;
    u8 *sprite12;
    u8 *sprite13;
    u8 *sprite14;
    u8 *sprite15;
    u8 *entry7;
    u8 *entry8;
    u8 *sprite16;

    menuWork4 = (FclCombineWork*)((KwlnTask *)task)->work;
    state = (u8)((u8)((u8)(menuWork4->f1)));
    switch (state) {                               /* switch 1 */
    case 0x23:                                      /* switch 1 */
        yListSlotCreate(1, 0);
        yListSlotCreate(0xA, 1);
        yListSlotCreate(0xA, 2);
        yListSlotCreate(0xA, 3);
        yListSlotCreate(0xA, 4);
        yListSlotCreate(0xA, 5);
        yListSlotCreate(0xA, 6);
        yListSlotCreate(0xA, 7);
        yListSlotCreate(0xA, 8);
        yListSlotCreate(0xA, 9);
        yListSlotCreate(0xA, 0xA);
        yListSlotCreate(0xA, 0xB);
        yListSlotCreate(0xA, 0xC);
        yListSlotCreate(0, 0xD);
        fclCombineLayoutDetailSprites(task, 1);
        menuWork4->f1 = 0x24U;
        return;
    case 0x24:
        if (fclCombineRowsBusy(task) != 1 && *(s8 *)yListSlotWork(0) == 1 && *(s8 *)yListSlotWork(1) == 1
            && *(s8 *)yListSlotWork(2) == 1 && *(s8 *)yListSlotWork(0xD) == 1) {
            for (rosterIndex = 0; rosterIndex < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex++) {
                gridBaseColor = fclMakeDrawColor(0, 0, 0x99, 0xFF);
                ((FclCombineBallSlot *)fclCombineSlotRecord((u8 *)menuWork4->f188, rosterIndex))->color = gridBaseColor;
            }
            fclCombineSlideInSlotSprites(task, 0x93, 0x96);
            fclCombineSetupPairGrid(task, 0);
            fclCombineLayoutFrame(task, 1, 0);
            fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            menuWork4->f129 = -1;
            menuWork4->f1 = 0x25;
        }
        break;
    case 0x25:                                      /* switch 1 */
        fclCombineAdvanceGridFade(task, 0x27, 0);
        return;
    case 0x26:
        for (rosterIndex8 = 0; rosterIndex8 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex8++) {
            textYOrFrame = (f32)((FclCombineRowSprite *)fclSpriteEntry(rosterIndex8 + 0x21C))->positionElapsed;
            spriteValue2 = (u8)fclEaseInterpolate(0, 255.0f, 0.0f, textYOrFrame, (f32)((FclCombineRowSprite *)fclSpriteEntry(rosterIndex8 + 0x21C))->positionDuration);
            if (menuWork4->f11E == rosterIndex8) {
                textColor6 = fclPackRgba(0x2D, 0x2D, 0x2D, spriteValue2);
            } else {
                textColor6 = fclPackRgba(0xCC, 0xFF, 0xFF, spriteValue2);
            }
            if (rosterIndex8 < ((FclCombinePersonaListHeader *)yListSlotWork(0))->count) {
                textYOrFrame = (f32)(rosterIndex8 * 0x17 + 0x80);
                frFontExDrawTextDeferredOutB(113.0f, textYOrFrame, 43.0f, textColor6, 0, 2, (const char *)(iGpffffb440 + ((u16 *)yListSlotEntry(0, rosterIndex8))[1] * 0x11), 0, 0, D_00795E60, 0x15);
            }
        }
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x21C))->flags, 1) == 0
            && (s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x193))->flags, 1) == 0) {
            fclCombineSlideInSlotSprites(task, 0x96, 0x93);
            fclCombineLayoutTransition(task, 0);
            fclCombineLayoutDetailSprites(task, 0);
            menuWork4->f0 = 0;
            menuWork4->f1 = 0x1A;
        }
        break;
    case 0x27:                                      /* switch 1 */
        if ((s8)fclDrawGetState(menuWork4->f148) < 0 || (s8)fclDrawGetState(menuWork4->f148) > 5) {
            fclCombineHandleGridInput(task, 0, 0x2A, 0x26);
            return;
        }
        break;
    case 0x28:                                      /* switch 1 */
        if ((s32)((s32)(((s16)(fclSpriteFlagBit((((FclCombineRowSprite *)fclSpriteEntry(0x21C))->flags), 1))))) != (s32)((s32)(1))) {
            fclDrawSetPlacement(menuWork4->f148, (s32)(((u16 *)yListSlotEntry(0, menuWork4->f11E))), 0, 0);
            shdPersonaEndSelection(fclDrawGetResource(menuWork4->f148), 1);
            personaModel8 = (s32)((s32)((s32)(fclDrawGetResource(menuWork4->f148))));
            shdPersonaSetChildDispCtlHandle((u8 *)personaModel8, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
            menuWork4->f1 = 0x29U;
            return;
        }
        break;
    case 0x29:
        if ((s8)fclDrawGetState(menuWork4->f148) == 5) {
            if (shdPersonaIsSelectionActive(fclDrawGetResource(menuWork4->f148)) == 1) {
                shdPersonaStepSelectionCursor(fclDrawGetResource(menuWork4->f148));
            }
            if (D_008C024E[0] & 0x80) {
                if (shdPersonaIsSelectionActive(fclDrawGetResource(menuWork4->f148)) == 0) {
                    shdPersonaBeginSelection(fclDrawGetResource(menuWork4->f148));
                    fclDrawSetFlag(menuWork4->f148, 0);
                } else {
                    shdPersonaEndSelection(fclDrawGetResource(menuWork4->f148), 1);
                    fclDrawSetFlag(menuWork4->f148, 1);
                }
            } else if (D_008C024E[0] & 0x20) {
                if (shdPersonaIsSelectionActive(fclDrawGetResource(menuWork4->f148)) == 1) {
                    shdPersonaEndSelection(fclDrawGetResource(menuWork4->f148), 1);
                    fclDrawSetFlag(menuWork4->f148, 1);
                } else {
                    if ((s8)fclDrawGetState(menuWork4->f148) != 5) {
                        break;
                    }
                    sdkSndStartStream(0, 1, 0, 4);
                    fclDrawSetStateByte(menuWork4->f148, 3);
                    if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x1E4))->flags, 0) == 1) {
                        fclSpriteStartAlphaAt(0x1E4, ((FclCombineRowSprite *)fclSpriteEntry(0x1E4))->alpha, 0, 0, 0xA, 0);
                    }
                }
            }
        }
        if ((s8)fclDrawGetState(menuWork4->f148) < 0 || (s8)fclDrawGetState(menuWork4->f148) > 5) {
            for (rosterIndex2 = 0; rosterIndex2 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex2++) {
                position2.position = fclMakeVec2(16.0f, 128.0f);
                fclCombinePartyRow(task, position2.position, (s8)(rosterIndex2), ((u16 *)yListSlotEntry(0, rosterIndex2))[1], ((DatPersonaRecord *)yListSlotEntry(0, rosterIndex2))->level, 0, 0, (s64)((s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count));
            }
            position3 = fclMakeVec2(16.0f, 104.0f);
            fclCombineDrawSlotFields(task, position3, 0, 0, 0, 0, 0);
            fclCombineFadeLabelSprites(task, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            fclCombineRefreshGridCells(task, 0);
            fclSpriteSetHidden(menuWork4->f28C, 0);
            fclSpriteSetHidden(menuWork4->f290, 0);
            menuWork4->f1 = 0x27;
        }
        break;
    case 0x2A:
        spriteAlpha3 = ((FclCombineRowSprite *)fclSpriteEntry(0x7C))->alpha;
        /* measured: field typing changes 10606 normalized bytes in the full owner. */
        menuWork2 = *(FclCombineWork **)(task + 0x38);
        sprite12 = fclSpriteEntry(0x7C);
        position28 = ((FclCombineRowSprite *)sprite12)->position;
        textColor5 = fclPackRgba(0xCC, 0xFF, 0xFF, spriteAlpha3);
        frFontExDrawTextDeferredOutB(111.0f + position28.x, position28.y, 43.0f, textColor5, 0, 2, (const char *)(iGpffffb440 + ((u16 *)yListSlotEntry(0, menuWork2->f128))[1] * 0x11), 0, 0, D_00795E60, 0x15);
        for (rosterIndex9 = 0; rosterIndex9 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex9++) {
            fclCombineSelectSlotEntry(task, rosterIndex9, menuWork4->f128, menuWork4->f129, 0);
            if (menuWork4->f128 != rosterIndex9 && ((FclCombineRowList *)yListSlotWork(0))->availability[menuWork4->f128][rosterIndex9] > 0) {
                spriteId5 = rosterIndex9 + 0x270;
                partnerYOrFrame = (f32)((FclCombineRowSprite *)fclSpriteEntry(spriteId5))->positionElapsed;
                spriteValue = (u8)fclEaseInterpolate(0, 0.0f, 255.0f, partnerYOrFrame, (f32)((FclCombineRowSprite *)fclSpriteEntry(spriteId5))->positionDuration);
                if (rosterIndex9 == menuWork4->f11E) {
                    spriteId6 = rosterIndex9 + 0x27D;
                    /* Unsigned: retail recomputes this id per colour branch instead of
                       reusing temp_23, and the resulting spill sets the 0x260 frame. */
                    selectedSpriteId = rosterIndex9 + 0x270U;
                    ((FclCombineRowSprite *)fclSpriteEntry(selectedSpriteId))->alpha = ((FclCombineRowSprite *)fclSpriteEntry(spriteId6))->alpha = 0xFF;
                    selectedRowColor = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
                    sprite13 = fclSpriteEntry(rosterIndex9 + 0x297);
                    ((FclCombineRowSprite *)sprite13)->color = selectedRowColor;
                    sprite14 = fclSpriteEntry(rosterIndex9 + 0x28B);
                    /* measured: field typing changes 8 normalized bytes in the full owner. */
                    ((FclCombineRowSprite *)sprite14)->color = *(FclDrawColor *)(sprite13 + 0x85);
                    sprite15 = fclSpriteEntry(spriteId6);
                    /* measured: field typing changes 8 normalized bytes in the full owner. */
                    ((FclCombineRowSprite *)sprite15)->color = *(FclDrawColor *)(sprite14 + 0x85);
                    /* measured: field typing changes 8 normalized bytes in the full owner. */
                    ((FclCombineRowSprite *)fclSpriteEntry(selectedSpriteId))->color = *(FclDrawColor *)(sprite15 + 0x85);
                    selectedNumberColor = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                    ((FclCombineRowSprite *)fclSpriteEntry(rosterIndex9 + 0x2A3))->color = selectedNumberColor;
                    selectedDigitColor = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                    nmMesWindowSetNumberColor((u8 *)menuWork4->f2BC, (s8)(rosterIndex9 + 0xC), selectedDigitColor);
                    textColor7 = fclPackRgba(0x2D, 0x2D, 0x2D, spriteValue);
                    if (((FclCombineRowList *)yListSlotWork(0))->availability[menuWork4->f128][rosterIndex9] == 2) {
                        fclSpriteSetFlag(0xCF, 0, 1);
                        fclSpriteSetFlag(0xD2, 0, 1);
                        fclSpriteSetFlag(spriteId5, 0, 0);
                        fclSpriteSetFlag(spriteId6, 0, 0);
                    }
                } else if (((FclCombineRowList *)yListSlotWork(0))->availability[menuWork4->f128][rosterIndex9] == 2) {
                    spriteId = rosterIndex9 + 0x27D;
                    spriteId3 = rosterIndex9 + 0x270U;
                    ((FclCombineRowSprite *)fclSpriteEntry(spriteId3))->alpha = ((FclCombineRowSprite *)fclSpriteEntry(spriteId))->alpha = 0;
                    specialRowColor = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
                    sprite16 = fclSpriteEntry(spriteId);
                    ((FclCombineRowSprite *)sprite16)->color = specialRowColor;
                    /* measured: field typing changes 8 normalized bytes in the full owner. */
                    ((FclCombineRowSprite *)fclSpriteEntry(spriteId3))->color = *(FclDrawColor *)(sprite16 + 0x85);
                    specialNumberColor = fclMakeDrawColor(0xFF, 0xCC, 0xFA, 0xFF);
                    ((FclCombineRowSprite *)fclSpriteEntry(rosterIndex9 + 0x2A3))->color = specialNumberColor;
                    specialDigitColor = fclMakeDrawColor(0xFF, 0xCC, 0xFA, 0xFF);
                    nmMesWindowSetNumberColor((u8 *)menuWork4->f2BC, (s8)(rosterIndex9 + 0xC), specialDigitColor);
                    textColor7 = fclPackRgba(0xFF, 0xCC, 0xFA, spriteValue);
                    fclSpriteSetFlag(0xCF, 0, 0);
                    fclSpriteSetFlag(0xD2, 0, 0);
                } else {
                    spriteId2 = rosterIndex9 + 0x27D;
                    spriteId4 = rosterIndex9 + 0x270U;
                    ((FclCombineRowSprite *)fclSpriteEntry(spriteId4))->alpha = ((FclCombineRowSprite *)fclSpriteEntry(spriteId2))->alpha = 0xCC;
                    normalRowColor = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                    sprite6 = fclSpriteEntry(spriteId2);
                    ((FclCombineRowSprite *)sprite6)->color = normalRowColor;
                    /* measured: field typing changes 8 normalized bytes in the full owner. */
                    ((FclCombineRowSprite *)fclSpriteEntry(spriteId4))->color = *(FclDrawColor *)(sprite6 + 0x85);
                    normalLabelColor = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                    sprite7 = fclSpriteEntry(rosterIndex9 + 0x297);
                    ((FclCombineRowSprite *)sprite7)->color = normalLabelColor;
                    /* measured: field typing changes 8 normalized bytes in the full owner. */
                    ((FclCombineRowSprite *)fclSpriteEntry(rosterIndex9 + 0x28B))->color = *(FclDrawColor *)(sprite7 + 0x85);
                    normalNumberColor = fclMakeDrawColor(0, 0, 0x66, 0xFF);
                    ((FclCombineRowSprite *)fclSpriteEntry(rosterIndex9 + 0x2A3))->color = normalNumberColor;
                    normalDigitColor = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
                    nmMesWindowSetNumberColor((u8 *)menuWork4->f2BC, (s8)(rosterIndex9 + 0xC), normalDigitColor);
                    textColor7 = fclPackRgba(0xCC, 0xFF, 0xFF, spriteValue);
                }
                partnerYOrFrame = (f32)(rosterIndex9 * 0x17 + 0x80);
                frFontExDrawTextDeferredOutB((f32)0x195, partnerYOrFrame, 43.0f, textColor7, 0, 2, (const char *)(iGpffffb440 + ((u16 *)yListSlotEntry(menuWork4->f128 + 1, rosterIndex9))[1] * 0x11), 0, 0, D_00795E60, 0x15);
            }
        }
        if ((s8)fclDrawGetState(menuWork4->f148) < 0 || (s8)fclDrawGetState(menuWork4->f148) > 5) {
            if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x1C7))->flags, 0) == 1) {
                fclCombineStepSidePanel(task, 0x1C7, 0);
                fclCombineStepSidePanel(task, 0x2E8, 1);
            }
            if (D_008C027A[0] & 0x1000) {
                menuWork4->f11E = (s8)fclSubClamped(menuWork4->f11E, 1, 0, (s16)(((FclCombinePersonaListHeader *)yListSlotWork(0))->count - 1), 2);
                sdkSndStartStream(0, 0, 0, 0);
            } else if (D_008C027A[0] & 0x4000) {
                menuWork4->f11E = (s8)fclAddClamped(menuWork4->f11E, 1, (s16)(((FclCombinePersonaListHeader *)yListSlotWork(0))->count - 1), 0, 2);
                sdkSndStartStream(0, 0, 0, 0);
            } else if (D_008C024E[0] & 0x40) {
                if (menuWork4->f128 != menuWork4->f11E && ((FclCombineRowList *)yListSlotWork(0))->availability[menuWork4->f128][menuWork4->f11E] > 0) {
                    sdkSndStartStream(0, 0, 0, 1);
                    for (rosterIndex3 = 0; rosterIndex3 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex3++) {
                        position4.position = fclMakeVec2((f32)0x149, 128.0f);
                        firstSelection6 = ((u16 *)yListSlotEntry(menuWork4->f128 + 1, rosterIndex3))[1];
                        slotByte = ((DatPersonaRecord *)yListSlotEntry(menuWork4->f128 + 1, rosterIndex3))->level;
                        fclCombineDrawPersonaRow(task, position4.position, menuWork4->f128, rosterIndex3, firstSelection6, slotByte, 0, 1, 1, 0xCC);
                        position5.position = fclMakeVec2(16.0f, 128.0f);
                        fclCombinePartyRow(task, position5.position, (s8)(rosterIndex3), ((u16 *)yListSlotEntry(0, rosterIndex3))[1], ((DatPersonaRecord *)yListSlotEntry(0, rosterIndex3))->level, 0, 1, (s64)((s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count));
                    }
                    position6 = fclMakeVec2(16.0f, 104.0f);
                    fclCombineDrawSlotFields(task, position6, 0, 1, 0, 0, 0);
                    position7 = fclMakeVec2((f32)0x149, 104.0f);
                    fclCombineDrawSlotLabels(task, position7, 0, 1);
                    fclCombineLayoutFrame(task, 1, 1);
                    fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                    fclCombineFadePanelSprite(task, 0, 0.0f);
                    fclSpriteSetHidden(menuWork4->f28C, 1);
                    fclSpriteSetHidden(menuWork4->f290, 1);
                    menuWork4->f1 = 0x2E;
                } else {
                    sdkSndStartStream(0, 0, 0, 8);
                }
            } else if (D_008C024C[0] & 0x80) {
                if (menuWork4->f11E < ((FclCombinePersonaListHeader *)yListSlotWork(0))->count) {
                    sdkSndStartStream(0, 1, 0, 3);
                    for (rosterIndex4 = 0; rosterIndex4 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex4++) {
                        position8.position = fclMakeVec2((f32)0x149, 128.0f);
                        firstSelection7 = ((u16 *)yListSlotEntry(menuWork4->f128 + 1, rosterIndex4))[1];
                        slotByte = ((DatPersonaRecord *)yListSlotEntry(menuWork4->f128 + 1, rosterIndex4))->level;
                        fclCombineDrawPersonaRow(task, position8.position, menuWork4->f128, rosterIndex4, firstSelection7, slotByte, 0, 1, 1, 0xCC);
                        position9.position = fclMakeVec2(16.0f, 128.0f);
                        fclCombinePartyRow(task, position9.position, (s8)(rosterIndex4), ((u16 *)yListSlotEntry(0, rosterIndex4))[1], ((DatPersonaRecord *)yListSlotEntry(0, rosterIndex4))->level, 0, 1, (s64)((s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count));
                    }
                    position10 = fclMakeVec2(16.0f, 104.0f);
                    fclCombineDrawSlotFields(task, position10, 0, 1, 0, 0, 0);
                    position11 = fclMakeVec2((f32)0x149, 104.0f);
                    fclCombineDrawSlotLabels(task, position11, 0, 1);
                    fclCombineLayoutFrame(task, 1, 1);
                    fclCombineFadeLabelSprites(task, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                    fclCombineFadePanelSprite(task, 0, 60.0f);
                    fclSpriteSetHidden(menuWork4->f28C, 1);
                    fclSpriteSetHidden(menuWork4->f290, 1);
                    menuWork4->f1 = 0x2B;
                }
            } else if (D_008C024E[0] & 0x20) {
                fclCombineApplySlotState(task, (s8)menuWork4->f11E, 0, 0xFF);
                menuWork4->f11E = menuWork4->f128;
                fclCombineApplySlotState(task, menuWork4->f11E, 1, 0xFF);
                sdkSndStartStream(0, 0, 0, 2);
                fclCombineSlideInSlotSprites(task, 0x93, 0x94);
                basePos = (FclVec2f *)D_00640C10;
                position12.position = fclMakeVec2(basePos->x, basePos->y);
                position13.position = fclMakeVec2(-380.0f, basePos->y);
                fclCombineDrawPersonaCard(task, menuWork4->f128, position12.position, position13.position);
                position14 = fclMakeVec2((f32)0x149, 104.0f);
                fclCombineDrawSlotLabels(task, position14, 0, 1);
                for (rosterIndex5 = 0; rosterIndex5 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex5++) {
                    position15.position = fclMakeVec2((f32)0x149, 128.0f);
                    firstSelection = ((u16 *)yListSlotEntry(menuWork4->f128 + 1, rosterIndex5))[1];
                    slotByte = ((DatPersonaRecord *)yListSlotEntry(menuWork4->f128 + 1, rosterIndex5))->level;
                    fclCombineDrawPersonaRow(task, position15.position, menuWork4->f128, rosterIndex5, firstSelection, slotByte, 0, 1, 1, 0xCC);
                }
                fclCombineRefreshGridCells(task, 3);
                menuWork4->f1 = 0x27;
            }
        }
        break;
    case 0x2B:
        sprite8 = fclSpriteEntry(0x7C);
        position29 = ((FclCombineRowSprite *)sprite8)->position;
        textColor = fclPackRgba(0xCC, 0xFF, 0xFF, 0xFF);
        frFontExDrawTextDeferredOutB(111.0f + position29.x, position29.y, 43.0f, textColor, 0, 2, (const char *)(iGpffffb440 + ((u16 *)yListSlotEntry(0, menuWork4->f128))[1] * 0x11), 0, 0, D_00795E60, 0x15);
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x21C))->flags, 1) != 1) {
            fclDrawSetPlacement(menuWork4->f148, (s32)(((u16 *)yListSlotEntry(0, menuWork4->f11E))), 0, 0);
            shdPersonaEndSelection(fclDrawGetResource(menuWork4->f148), 1);
            personaModel = (s32)fclDrawGetResource(menuWork4->f148);
            shdPersonaSetChildDispCtlHandle((u8 *)personaModel, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
            menuWork4->f1 = 0x2C;
        }
        break;
    case 0x2C:
        sprite9 = fclSpriteEntry(0x7C);
        position30 = ((FclCombineRowSprite *)sprite9)->position;
        textColor2 = fclPackRgba(0xCC, 0xFF, 0xFF, 0xFF);
        frFontExDrawTextDeferredOutB(111.0f + position30.x, position30.y, 43.0f, textColor2, 0, 2, (const char *)(iGpffffb440 + ((u16 *)yListSlotEntry(0, menuWork4->f128))[1] * 0x11), 0, 0, D_00795E60, 0x15);
        if ((s8)fclDrawGetState(menuWork4->f148) == 5) {
            if (shdPersonaIsSelectionActive(fclDrawGetResource(menuWork4->f148)) == 1) {
                shdPersonaStepSelectionCursor(fclDrawGetResource(menuWork4->f148));
            }
            if (D_008C024E[0] & 0x80) {
                if (shdPersonaIsSelectionActive(fclDrawGetResource(menuWork4->f148)) == 0) {
                    shdPersonaBeginSelection(fclDrawGetResource(menuWork4->f148));
                    fclDrawSetFlag(menuWork4->f148, 0);
                } else {
                    shdPersonaEndSelection(fclDrawGetResource(menuWork4->f148), 1);
                    fclDrawSetFlag(menuWork4->f148, 1);
                }
            } else if (D_008C024E[0] & 0x20) {
                if (shdPersonaIsSelectionActive(fclDrawGetResource(menuWork4->f148)) == 1) {
                    shdPersonaEndSelection(fclDrawGetResource(menuWork4->f148), 1);
                    fclDrawSetFlag(menuWork4->f148, 1);
                } else {
                    if ((s8)fclDrawGetState(menuWork4->f148) != 5) {
                        break;
                    }
                    sdkSndStartStream(0, 1, 0, 4);
                    fclDrawSetStateByte(menuWork4->f148, 3);
                    if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x1E4))->flags, 0) == 1) {
                        fclSpriteStartAlphaAt(0x1E4, ((FclCombineRowSprite *)fclSpriteEntry(0x1E4))->alpha, 0, 0, 0xA, 0);
                    }
                }
            }
        }
        if ((s8)fclDrawGetState(menuWork4->f148) < 0 || (s8)fclDrawGetState(menuWork4->f148) > 5) {
            for (rosterIndex6 = 0; rosterIndex6 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex6++) {
                position16.position = fclMakeVec2((f32)0x149, 128.0f);
                firstSelection2 = ((u16 *)yListSlotEntry(menuWork4->f128 + 1, rosterIndex6))[1];
                slotByte = ((DatPersonaRecord *)yListSlotEntry(menuWork4->f128 + 1, rosterIndex6))->level;
                fclCombineDrawPersonaRow(task, position16.position, menuWork4->f128, rosterIndex6, firstSelection2, slotByte, 0, 0, 1, 0xCC);
                position17.position = fclMakeVec2(16.0f, 128.0f);
                fclCombinePartyRow(task, position17.position, (s8)(rosterIndex6), ((u16 *)yListSlotEntry(0, rosterIndex6))[1], ((DatPersonaRecord *)yListSlotEntry(0, rosterIndex6))->level, 0, 0, (s64)((s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count));
            }
            position18 = fclMakeVec2(16.0f, 104.0f);
            fclCombineDrawSlotFields(task, position18, 0, 0, 0, 0, 0);
            position19 = fclMakeVec2((f32)0x149, 104.0f);
            fclCombineDrawSlotLabels(task, position19, 0, 0);
            fclCombineLayoutFrame(task, 1, 0);
            fclCombineFadeLabelSprites(task, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            fclSpriteSetHidden(menuWork4->f28C, 0);
            fclSpriteSetHidden(menuWork4->f290, 0);
            menuWork4->f1 = 0x2A;
        }
        break;
    case 0x2E:
        spriteAlpha = ((FclCombineRowSprite *)fclSpriteEntry(0x7C))->alpha;
        /* measured: field typing changes 10606 normalized bytes in the full owner. */
        menuWork3 = *(FclCombineWork **)(task + 0x38);
        sprite10 = fclSpriteEntry(0x7C);
        position31 = ((FclCombineRowSprite *)sprite10)->position;
        textColor3 = fclPackRgba(0xCC, 0xFF, 0xFF, spriteAlpha);
        frFontExDrawTextDeferredOutB(111.0f + position31.x, position31.y, 43.0f, textColor3, 0, 2, (const char *)(iGpffffb440 + ((u16 *)yListSlotEntry(0, menuWork3->f128))[1] * 0x11), 0, 0, D_00795E60, 0x15);
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x21C))->flags, 1) != 1) {
            menuWork4->f2F9 = menuWork4->f128 + 1;
            menuWork4->f2FA = menuWork4->f11E;
            resultIndex = menuWork4->f2FA;
            personaRecord5 = ((u16 *)yListSlotEntry(menuWork4->f2F9, resultIndex));
            partySlot = (FclPartySlot *)(yListSlotWork(menuWork4->f2F9) + (s8)resultIndex);
            community = (s16)cmmTopCommunityOfArcana(iGpffffb3d4[((u16 *)yListSlotEntry(menuWork4->f2F9, menuWork4->f2FA))[1] * 14 + 2]);
            slotMode = cmmCommunityExpRemaining(community, (u8 *)((u8 *)((u16 *)yListSlotEntry(menuWork4->f2F9, menuWork4->f2FA))), 0);
            fclDrawSetPlacementEx(menuWork4->f148, (s32)(personaRecord5), partySlot->f2E4, slotMode, 1);
            personaModel2 = (s32)fclDrawGetResource(menuWork4->f148);
            shdPersonaSetChildDispCtlHandle((u8 *)personaModel2, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
            resultIndex9 = ((DatPersonaRecord *)yListSlotEntry(menuWork4->f2F9, menuWork4->f2FA))->level;
            if ((datCalcGetLevelById(1) & 0xFF) < resultIndex9) {
                personaModel3 = (s32)fclDrawGetResource(menuWork4->f148);
                shdPersonaSetChildDispCtlHandle((u8 *)personaModel3, fclPackRgba(0x14, 0x14, 0x14, 0xFF));
            }
            shdPersonaEndSelection(fclDrawGetResource(menuWork4->f148), 1);
            fclCombineDrawStageBanner(task, 3, 0);
            menuWork4->f1 = 0x2D;
        }
        break;
    case 0x2D:                                      /* switch 1 */
        if ((s32)((s32)(((s8)(fclDrawGetState(menuWork4->f148))))) == (s32)((s32)(0xD))) {
            if ((s32)((s32)(shdPersonaIsSelectionActive(fclDrawGetResource(menuWork4->f148)))) == (s32)((s32)(1))) {
                shdPersonaStepSelectionCursor(fclDrawGetResource(menuWork4->f148));
            }
            if (D_008C024E[0] & 0x40) {
                menuWork4->f1 = 0x2FU;
                sdkSndStartStream(0, 0, 0, 1);
                return;
            }
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(shdPersonaIsSelectionActive(fclDrawGetResource(menuWork4->f148)))) == (s32)((s32)(0))) {
                    shdPersonaBeginSelection(fclDrawGetResource(menuWork4->f148));
                    fclDrawSetFlag(menuWork4->f148, 0);
                    return;
                }
                shdPersonaEndSelection(fclDrawGetResource(menuWork4->f148), 1);
                fclDrawSetFlag(menuWork4->f148, 1);
                return;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(shdPersonaIsSelectionActive(fclDrawGetResource(menuWork4->f148)))) == (s32)((s32)(1))) {
                    shdPersonaEndSelection(fclDrawGetResource(menuWork4->f148), 1);
                    fclDrawSetFlag(menuWork4->f148, 1);
                    return;
                }
                menuWork4->f1 = 0x35U;
                fclDrawSetStateByte(menuWork4->f148, 0xB);
                fclCombineDrawStageBanner(task, 3, 1);
                fclCombineFadePanelSprite(task, 1, 0.0f);
                sdkSndStartStream(0, 0, 0, 2);
                return;
            }
            if (D_008C024E[0] & 8) {
                if (menuWork4->f122 != 2) {
                    sdkSndStartStream(0, 2, 0, 5);
                }
                menuWork4->f122 = (s8)((s8)(fclAddClamped(menuWork4->f122, 1, 2, 0, 1)));
                ps = fclSpriteEntry(0x151);
                position20 = fclMakeVec2((f32)((menuWork4->f122 * 0x8E) + 0x6A), 16.0f);
                fclSpriteStartPositionAt(0x151, (((FclCombineRowSprite *)ps)->position), position20, 1, 4, 0);
                ps = fclSpriteEntry(0x2E0);
                position21 = fclMakeVec2((f32)((menuWork4->f122 * 0x8E) + 0x6A), 16.0f);
                fclSpriteStartPositionAt(0x2E0, (((FclCombineRowSprite *)ps)->position), position21, 1, 4, 0);
                previewSelection = (s8)((s8)((s8)(menuWork4->f122)));
                switch (previewSelection) {                   /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    personaModel4 = (s32)((s32)((s32)(fclDrawGetResource(menuWork4->f148))));
                    shdPersonaSetChildDispCtlHandle((u8 *)personaModel4, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
                    fclDrawSetPlacementEx(menuWork4->f148, (s32)(((u16 *)yListSlotEntry(0, menuWork4->f128))), 0, 0, 1);
                    return;
                case 1:                             /* switch 2 */
                    personaModel5 = (s32)((s32)((s32)(fclDrawGetResource(menuWork4->f148))));
                    shdPersonaSetChildDispCtlHandle((u8 *)personaModel5, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
                    fclDrawSetPlacementEx(menuWork4->f148, (s32)(((u16 *)yListSlotEntry(0, menuWork4->f11E))), 0, 0, 1);
                    return;
                case 2:                             /* switch 2 */
                    personaModel6 = (s32)((s32)((s32)(fclDrawGetResource(menuWork4->f148))));
                    shdPersonaSetChildDispCtlHandle((u8 *)personaModel6, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
                    resultIndex10 = (u8)((u8)((u8)((((DatPersonaRecord *)yListSlotEntry(menuWork4->f2F9, menuWork4->f2FA))->level))));
                    if ((s32)((s32)((datCalcGetLevelById(1) & 0xFF))) < (s32)((s32)((s32) resultIndex10))) {
                        personaModel7 = (s32)((s32)((s32)(fclDrawGetResource(menuWork4->f148))));
                        shdPersonaSetChildDispCtlHandle((u8 *)personaModel7, fclPackRgba(0x14, 0x14, 0x14, 0xFFU));
                    }
                    resultIndex3 = (s8)((s8)((s8)(menuWork4->f2FA)));
                    personaRecord3 = (u16 *)(((u16 *)yListSlotEntry(menuWork4->f2F9, resultIndex3)));
                    partySlot2 = (FclPartySlot *)(yListSlotWork(menuWork4->f2F9) + (s8)resultIndex3);
                    community2 = (s16)cmmTopCommunityOfArcana(iGpffffb3d4[((u16 *)yListSlotEntry(menuWork4->f2F9, menuWork4->f2FA))[1] * 14 + 2]);
                    slotMode = cmmCommunityExpRemaining(community2, (u8 *)((u8 *)((u16 *)yListSlotEntry(menuWork4->f2F9, menuWork4->f2FA))), 0);
                    fclDrawSetPlacementEx(menuWork4->f148, (s32)(personaRecord3), partySlot2->f2E4, slotMode, 1);
                    return;
                }
            } else if (D_008C024E[0] & 4) {
                if (menuWork4->f122 != 0) {
                    sdkSndStartStream(0, 2, 0, 5);
                }
                menuWork4->f122 = (s8)((s8)(fclSubClamped(menuWork4->f122, 1, 0, 2, 1)));
                ps = fclSpriteEntry(0x151);
                position22 = fclMakeVec2((f32)((menuWork4->f122 * 0x8E) + 0x6A), 16.0f);
                fclSpriteStartPositionAt(0x151, (((FclCombineRowSprite *)ps)->position), position22, 1, 4, 0);
                ps = fclSpriteEntry(0x2E0);
                position23 = fclMakeVec2((f32)((menuWork4->f122 * 0x8E) + 0x6A), 16.0f);
                fclSpriteStartPositionAt(0x2E0, (((FclCombineRowSprite *)ps)->position), position23, 1, 4, 0);
                previewSelection2 = (s8)((s8)((s8)(menuWork4->f122)));
                switch (previewSelection2) {                 /* switch 3; irregular */
                case 0:                             /* switch 3 */
                    personaModel9 = (s32)((s32)((s32)(fclDrawGetResource(menuWork4->f148))));
                    shdPersonaSetChildDispCtlHandle((u8 *)personaModel9, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
                    fclDrawSetPlacementEx(menuWork4->f148, (s32)(((u16 *)yListSlotEntry(0, menuWork4->f128))), 0, 0, 1);
                    return;
                case 1:                             /* switch 3 */
                    personaModel10 = (s32)((s32)((s32)(fclDrawGetResource(menuWork4->f148))));
                    shdPersonaSetChildDispCtlHandle((u8 *)personaModel10, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
                    fclDrawSetPlacementEx(menuWork4->f148, (s32)(((u16 *)yListSlotEntry(0, menuWork4->f11E))), 0, 0, 1);
                    return;
                case 2:                             /* switch 3 */
                    personaModel11 = (s32)((s32)((s32)(fclDrawGetResource(menuWork4->f148))));
                    shdPersonaSetChildDispCtlHandle((u8 *)personaModel11, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
                    resultIndex11 = (u8)((u8)((u8)((((DatPersonaRecord *)yListSlotEntry(menuWork4->f2F9, menuWork4->f2FA))->level))));
                    if ((s32)((s32)((datCalcGetLevelById(1) & 0xFF))) < (s32)((s32)((s32) resultIndex11))) {
                        personaModel12 = (s32)((s32)((s32)(fclDrawGetResource(menuWork4->f148))));
                        shdPersonaSetChildDispCtlHandle((u8 *)personaModel12, fclPackRgba(0x14, 0x14, 0x14, 0xFFU));
                    }
                    resultIndex4 = (s8)((s8)((s8)(menuWork4->f2FA)));
                    personaRecord4 = (u16 *)(((u16 *)yListSlotEntry(menuWork4->f2F9, resultIndex4)));
                    partySlot3 = (FclPartySlot *)(yListSlotWork(menuWork4->f2F9) + (s8)resultIndex4);
                    community3 = (s16)cmmTopCommunityOfArcana(iGpffffb3d4[((u16 *)yListSlotEntry(menuWork4->f2F9, menuWork4->f2FA))[1] * 14 + 2]);
                    slotMode = cmmCommunityExpRemaining(community3, (u8 *)((u8 *)((u16 *)yListSlotEntry(menuWork4->f2F9, menuWork4->f2FA))), 0);
                    fclDrawSetPlacementEx(menuWork4->f148, (s32)(personaRecord4), partySlot3->f2E4, slotMode, 1);
                    return;
                }
            }
        }
        break;
    case 0x35:
        spriteAlpha2 = ((FclCombineRowSprite *)fclSpriteEntry(0x7C))->alpha;
        /* measured: field typing changes 10606 normalized bytes in the full owner. */
        menuWork = *(FclCombineWork **)(task + 0x38);
        sprite11 = fclSpriteEntry(0x7C);
        position32 = ((FclCombineRowSprite *)sprite11)->position;
        textColor4 = fclPackRgba(0xCC, 0xFF, 0xFF, spriteAlpha2);
        frFontExDrawTextDeferredOutB(111.0f + position32.x, position32.y, 43.0f, textColor4, 0, 2, (const char *)(iGpffffb440 + ((u16 *)yListSlotEntry(0, menuWork->f128))[1] * 0x11), 0, 0, D_00795E60, 0x15);
        if ((s8)fclDrawGetState(menuWork4->f148) == 0xE) {
            fclCombineLayoutFrame(task, 1, 0);
            fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            menuWork4->f129 = -1;
            for (rosterIndex7 = 0; rosterIndex7 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex7++) {
                position24.position = fclMakeVec2(16.0f, 128.0f);
                fclCombinePartyRow(task, position24.position, (s8)(rosterIndex7), ((u16 *)yListSlotEntry(0, rosterIndex7))[1], ((DatPersonaRecord *)yListSlotEntry(0, rosterIndex7))->level, 0, 0, (s64)((s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count));
                position25.position = fclMakeVec2((f32)0x149, 128.0f);
                firstSelection3 = ((u16 *)yListSlotEntry(menuWork4->f128 + 1, rosterIndex7))[1];
                slotByte = ((DatPersonaRecord *)yListSlotEntry(menuWork4->f128 + 1, rosterIndex7))->level;
                fclCombineDrawPersonaRow(task, position25.position, menuWork4->f128, rosterIndex7, firstSelection3, slotByte, 0, 0, 1, 0xCC);
            }
            position26 = fclMakeVec2(16.0f, 104.0f);
            fclCombineDrawSlotFields(task, position26, 0, 0, 0, 0, 0);
            position27 = fclMakeVec2((f32)0x149, 104.0f);
            fclCombineDrawSlotLabels(task, position27, 0, 0);
            fclSpriteSetHidden(menuWork4->f28C, 0);
            fclSpriteSetHidden(menuWork4->f290, 0);
            menuWork4->f1 = 0x2A;
        }
        break;
    case 0x2F:
        resultIndex7 = ((u16 *)yListSlotEntry(menuWork4->f2F9, menuWork4->f2FA))[1];
        resultIndex12 = ((DatPersonaRecord *)yListSlotEntry(menuWork4->f2F9, menuWork4->f2FA))->level;
        if ((datCalcGetLevelById(1) & 0xFF) < resultIndex12) {
            fclCombinePlayCue(task, 0x26, 0);
            menuWork4->f1 = 0x31;
        } else if (yListSlotContainsId(0, (s32)((s16)((DatPersonaRecord *)yListSlotEntry(menuWork4->f2F9, menuWork4->f2FA))->id)) == 1) {
            fclCombinePlayCue(task, 0x27, 0);
            menuWork4->f1 = 0x31;
        } else {
            if (datGetPersonaArcanaCommunityValue(resultIndex7) == 0) {
                fclCombinePlayResultCue(task, resultIndex7);
            } else {
                fclCombinePlayCue(task, (s8)(datGetPersonaArcanaCommunityValue(resultIndex7) + 0x2E), 1);
            }
            menuWork4->f1 = 0x30;
        }
        break;
    case 0x30:                                      /* switch 1 */
        if ((s32)((s32)(nmMesWindowSlotStatus((s8)(menuWork4->fD)))) != (s32)((s32)(0))) {
            nmMesWindowStepSlotRelease((s8)(menuWork4->fD));
            return;
        }
        if ((s32)((s32)(nmMesWindowGetSlotState(menuWork4->fD))) == (s32)((s32)(0))) {
            menuWork4->f1 = 0x33U;
            fadeBeginTransition(1, 0xA);
        } else {
            menuWork4->f1 = 0x2DU;
        }
        nmMesWindowDestroySlot((s8)(menuWork4->fD));
        return;
    case 0x31:                                      /* switch 1 */
        if ((s32)((s32)(nmMesWindowSlotStatus((s8)(menuWork4->fD)))) != (s32)((s32)(0))) {
            nmMesWindowStepSlotRelease((s8)(menuWork4->fD));
            return;
        }
        nmMesWindowDestroySlot((s8)(menuWork4->fD));
        menuWork4->f1 = 0x2DU;
        return;
    case 0x33:                                      /* switch 1 */
        if ((s32)((s32)(fadeStatus())) != (s32)((s32)(0))) {
            fclDrawSetStateByte(menuWork4->f148, 0xB);
            fclDrawResetScale(menuWork4->f148);
            fclCombineDrawStageBanner(task, 3, 1);
            for (index = 0; index < 0x30C; index++) {
                fclSpriteSetFlag(index, 0, 1);
            }
            menuWork4->f1 = 0x32U;
            return;
        }
        break;
    case 0x32:                                      /* switch 1 */
        if ((s32)((s32)(((s8)(fclDrawGetState(menuWork4->f148))))) == (s32)((s32)(0xE))) {
            menuWork4->f1 = 0x34U;
            return;
        }
        break;
    case 0x34:                                      /* switch 1 */
        rareChanceKind = 2;
        if ((((FclCombineRowList *)yListSlotWork(0))->availability[menuWork4->f128][menuWork4->f11E]) == 2) {
            rareChanceKind = 0;
        }
        if ((s32)((s32)(datGetFlag(0x1461))) == (s32)((s32)(0))) {
            if ((s32)((s32)(fclRollRareChance(rareChanceKind))) == (s32)((s32)(1))) {
                if (RpRandom() % 1000U < 0x1F4U) {
                    menuWork4->f1 = 0x36U;
                    menuWork4->fB2 = 1;
                    return;
                }
                menuWork4->f1 = 0x37U;
                menuWork4->fB2 = 2;
                return;
            }
            menuWork4->fB2 = 0;
            menuWork4->f0 = 0xD;
            menuWork4->f1 = 0xC5U;
            return;
        }
        menuWork4->f1 = 0x36U;
        menuWork4->fB2 = 1;
        return;
    case 0x36:
        memset(&excludedIds, 0, 0x1A);
        for (index2 = 0; index2 < ((FclCombinePersonaListHeader *)yListSlotWork(0))->count; index2++) {
            excludedIds[index2] = ((u16 *)yListSlotEntry(0, index2))[1];
        }
        resultIndex8 = ((u16 *)yListSlotEntry(menuWork4->f2F9, menuWork4->f2FA))[1];
        excludedIds[((FclCombinePersonaListHeader *)yListSlotWork(0))->count] = resultIndex8;
        yListSlotFillNearLevel(0xD, excludedIds, (s8)datCalcGetLevelById(1));
        entryCount2 = (u32)((FclCombinePersonaListHeader *)yListSlotWork(0xD))->count;
        randomValue = (RpRandom() % entryCount2) * 0xA;
        entryCount = (s8)(randomValue % (u32)((FclCombinePersonaListHeader *)yListSlotWork(0xD))->count);
        menuWork4->f2F9 = menuWork4->f128 + 1;
        menuWork4->f2FA = menuWork4->f11E;
        for (skillIndex = 0; skillIndex < 8; skillIndex++) {
            if ((((1 << skillIndex) & 0xFF & ((FclPartySlot *)(yListSlotWork(menuWork4->f2F9) + menuWork4->f2FA))->f2E4) >> skillIndex) == 1
                && (s32)datPersonaCountSkills((u8 *)(((u16 *)yListSlotEntry(0xD, entryCount)))) < 8) {
                firstSelection4 = ((u16 *)yListSlotEntry(menuWork4->f128 + 1, menuWork4->f11E))[skillIndex + 6];
                if (datPersonaFindSkillSlot((u8 *)((u16 *)yListSlotEntry(0xD, entryCount)), firstSelection4) == -1) {
                    datPersonaAddSkill((u8 *)((u16 *)yListSlotEntry(0xD, entryCount)), firstSelection4);
                }
            }
        }
        menuWork4->f2F9 = 0xD;
        menuWork4->f2FA = entryCount;
        personaRecord = ((u16 *)yListSlotEntry(menuWork4->f2F9, menuWork4->f2FA));
        fclDrawSetSlotMode(menuWork4->f148, (s32)(personaRecord), ((FclPartySlot *)(yListSlotWork(menuWork4->f128 + 1) + menuWork4->f11E))->f2E4);
        menuWork4->f0 = 0xD;
        menuWork4->f1 = 0xC5;
        break;
    case 0x37:
        nearestLevelDifference = 0x63;
        memset(&excludedLevelIds, 0, 0x1A);
        for (index3 = 0; index3 < ((FclCombinePersonaListHeader *)yListSlotWork(0))->count; index3++) {
            excludedLevelIds[index3] = ((u16 *)yListSlotEntry(0, index3))[1];
        }
        firstSelection5 = ((u16 *)yListSlotEntry(menuWork4->f128 + 1, menuWork4->f11E))[1];
        excludedLevelIds[((FclCombinePersonaListHeader *)yListSlotWork(0))->count] = firstSelection5;
        yListSlotFillByLevel(0xD, excludedLevelIds, (s8)datCalcGetLevelById(1));
        if (((FclCombinePersonaListHeader *)yListSlotWork(0xD))->count == 0) {
            menuWork4->f2F9 = menuWork4->f128 + 1;
            menuWork4->f2FA = menuWork4->f11E;
            menuWork4->f1 = 0x36;
            menuWork4->fB2 = 1;
            break;
        }
        menuWork4->f2F9 = 0xD;
        for (index4 = 0; index4 < ((FclCombinePersonaListHeader *)yListSlotWork(0xD))->count; index4++) {
            level = ((DatPersonaRecord *)yListSlotEntry(0xD, index4))->level;
            if (level >= (datCalcGetLevelById(1) & 0xFF)) {
                menuWork4->f2FA = index4;
                break;
            }
            if (nearestLevelDifference > (datCalcGetLevelById(1) & 0xFF) - ((DatPersonaRecord *)yListSlotEntry(0xD, index4))->level) {
                level2 = ((DatPersonaRecord *)yListSlotEntry(0xD, index4))->level;
                nearestLevelDifference = (datCalcGetLevelById(1) & 0xFF) - level2;
                menuWork4->f2FA = index4;
            }
        }
        resultIndex2 = menuWork4->f2FA;
        menuWork4->f2F9 = menuWork4->f128 + 1;
        for (skillIndex2 = 0; skillIndex2 < 8; skillIndex2++) {
            if ((((1 << skillIndex2) & 0xFF & ((FclPartySlot *)(yListSlotWork(menuWork4->f2F9) + menuWork4->f11E))->f2E4) >> skillIndex2) == 1
                && (s32)datPersonaCountSkills((u8 *)(((u16 *)yListSlotEntry(0xD, resultIndex2)))) < 8) {
                resultList4 = ((u16 *)yListSlotEntry(menuWork4->f2F9, menuWork4->f11E))[skillIndex2 + 6];
                if (datPersonaFindSkillSlot((u8 *)((u16 *)yListSlotEntry(0xD, resultIndex2)), resultList4) == -1) {
                    datPersonaAddSkill((u8 *)((u16 *)yListSlotEntry(0xD, resultIndex2)), resultList4);
                }
            }
        }
        menuWork4->f2F9 = 0xD;
        personaRecord2 = ((u16 *)yListSlotEntry(0xD, menuWork4->f2FA));
        fclDrawSetSlotMode(menuWork4->f148, (s32)(personaRecord2), ((FclPartySlot *)(yListSlotWork(menuWork4->f128 + 1) + menuWork4->f11E))->f2E4);
        menuWork4->f0 = 0xD;
        menuWork4->f1 = 0xC5;
        break;
    }
}

/* Native position/color payloads and row views preserve the retail 0x400 frame. */
typedef struct {
    s8 f0;
    u8 f1;
    u8 pad2[0xB];
    s8 fD;
    u8 padE[0xA4];
    s8 fB2;
    u8 padB3[0x6B];
    s16 f11E;
    u8 pad120[0x2];
    s8 f122;
    u8 pad123[0x5];
    s8 f128;
    s8 f129;
    u8 pad12A[0x1E];
    u8 *f148;
    u8 pad14C[0x8];
    u8 *rows[12];
    u8 *f184;
    u8 *f188;
    u8 pad18C[0x100];
    u8 *f28C;
    u8 *f290;
    u8 pad294[0x65];
    s8 f2F9;
    s8 f2FA;
    u8 pad2FB[0x5];
} FclCombineCtl;

typedef struct {
    u8 pad0[0x154];
    u8 *list;
} FclCombineColumnTasks;

/* The provider-relative slot animation layout preserves each expansion's
   original position, color, alpha and call-argument evaluation shape. */
#define FCL_COMBINE_TRIPLE_GRID_ROW(menu, outer, mode, transition, headerPosition, cellPosition, color0, color1) do { \
    s32 grid = mode; \
 \
    s32 offset = outer * 23; \
    s32 y; \
    s16 inner; \
    FclCombineColumnTasks *list; \
 \
    fclSpriteStartEntrance(fclCombineSlotRecord((u8 *)menu->f184, (s8)outer), \
        (headerPosition = fclMakeVec2((f32)(offset + 329), 104.0f)), \
        (color0 = fclMakeDrawColor(0, 0, 0x99, 0xFF)), \
        (color1 = fclMakeDrawColor(0, 0, 0x99, 0xFF)), 255, 255, 32.0f, 159.0f, 3, 0, transition, 0); \
    inner = 0; \
    list = (FclCombineColumnTasks *)((u8 *)menu + outer * 4); \
    y = offset + 127; \
    for (; inner < (datPersonaRosterCapacity() & 0xFFFF); inner++) { \
        if (grid) { \
            fclSpriteStartEntrance(fclCombineSlotRecord(list->list, (s8)inner), \
                (cellPosition = fclMakeVec2((f32)(inner * 23 + 329), (f32)y)), \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->color, \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->color, \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->alpha, \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->alpha, \
                32.0f, ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->depth, 3, 0, transition, 0); \
        } else { \
            fclSpriteStartEntrance(fclCombineSlotRecord(list->list, (s8)inner), \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->position, \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->color, \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->color, \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->alpha, \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->alpha, \
                32.0f, ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->depth, 3, 0, transition, 0); \
        } \
    } \
} while (0)
// Fcl combine menu fusion triple (state 2): a fusion with a second source. Picks the second persona from the roster and the third through the grid (0x38-0x47), then rolls the rare chance (0x4D), builds the result list with inherited skills (0x4F-0x50), and hands to the result handler (state 0x0D, sub-state 0xC5).
// FUN_002F0F00
#pragma push
#pragma opt_loop_invariants on
/* Historical whole-layout probe: 17054 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
void fclCombineMenuFusionTriple(u8 *task) {

    u8 *s0;
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
    FclVec2f base3A;
    FclVec2f position;
    FclVec2f position2;
    FclVec2f position3;
    FclVec2f position4;
    FclVec2f position5;
    FclVec2f position6;
    FclVec2f position7;
    FclVec2f position8;
    FclVec2f position9;
    FclVec2f position10;
    FclVec2f position11;
    FclVec2f position12;
    FclVec2f position13;
    FclVec2f position14;
    FclVec2f position15;
    FclVec2f position16;
    FclVec2f position17;
    FclVec2f position18;
    FclVec2f position19;
    FclVec2f position20;
    FclVec2f position21;
    FclVec2f position22;
    FclVec2f position23;
    FclVec2f position24;
    FclVec2f position25;
    FclVec2f position26;
    FclVec2f position27;
    FclVec2f position28;
    FclVec2f position29;
    FclVec2f position30;
    FclVec2f position31;
    FclVec2f position32;
    FclVec2f position33;
    FclVec2f position34;
    FclVec2f position35;
    FclVec2f position36;
    FclVec2f position37;
    FclVec2f position38;
    FclVec2f position39;
    FclVec2f position40;
    FclVec2f position41;
    FclVec2f position42;
    FclVec2f position43;
    FclVec2f position44;
    FclVec2f position45;
    FclVec2f position46;
    FclVec2f position47;
    FclVec2f position48;
    FclVec2f position49;
    FclVec2f position50;
    FclVec2f position51;
    FclVec2f position52;
    FclVec2f position53;
    FclVec2f position54;
    FclVec2f position55;
    FclVec2f position56;
    FclVec2f position57;
    FclVec2f position58;
    FclVec2f position59;
    FclVec2f position60;
    FclVec2f position61;
    FclVec2f position62;
    FclVec2f position63;
    FclVec2f position64;
    FclVec2f position65;
    FclVec2f position66;
    FclVec2f position67;
    FclVec2f position68;
    FclVec2f position69;
    FclVec2 position70;
    FclVec2 position71;
    FclVec2 position72;
    FclVec2 position73;
    FclVec2f position74;
    FclVec2f position75;
    u16 excludedIds[16];
    u16 excludedIds2[16];
    s8 rareChanceKind;
    f32 coordinate;
    f32 spriteValue;
    f32 coordinate2;
    f32 spriteValue2;
    f32 spriteValue3;
    f32 coordinate3;
    f32 coordinate4;
    s16 cursorRow;
    s16 cursorRow2;
    s16 cursorRow3;
    s16 cursorRow4;
    s16 cursorRow5;
    s16 cursorRow6;
    s32 textColor;
    s32 personaModel;
    s32 textColor2;
    s32 textColor3;
    s32 textColor4;
    s32 textColor5;
    s32 textColor6;
    s32 personaModel2;
    s32 textColor7;
    s32 textColor8;
    s32 personaModel3;
    s32 textColor9;
    s32 textColor10;
    s32 personaModel4;
    s32 personaModel5;
    s32 textColor11;
    s32 textColor12;
    s32 personaModel6;
    s32 personaModel7;
    s32 personaModel8;
    s32 personaModel9;
    s32 personaModel10;
    s32 personaModel11;
    s32 personaModel12;
    s32 personaModel13;
    s32 personaModel14;
    s32 personaModel15;
    s32 textColor13;
    s32 textColor14;
    s32 textColor15;
    s32 labelX;
    u8 *spriteNode;
    s32 labelX2;
    s32 labelX3;
    u8 *spriteNode2;
    u8 *spriteNode3;
    s32 labelX4;
    s32 spriteFlags;
    u8 *spriteNode4;
    s16 gridRowIndex;
    s16 gridRowIndex2;
    s16 gridColumnIndex;
    s16 gridColumnIndex2;
    s16 gridRow;
    s16 partyRow;
    s16 resultRow;
    s32 textColor16;
    s32 textColor17;
    s32 textColor18;
    s16 spriteId;
    s16 spriteId2;
    s32 resultIndex;
    s32 gridRowIndex3;
    s16 spriteId3;
    s32 resultIndex2;
    s32 community;
    s32 community2;
    s32 community3;
    s16 selectedResult;
    s32 value;
    s16 index;
    s16 index2;
    s16 skillIndex;
    s16 skillIndex2;
    s32 candidateIndex;
    s16 gridColumn;
    s16 candidateFound;
    s8 secondSelection;
    s8 resultIndex3;
    s8 resultIndex4;
    s8 secondSelection2;
    s8 secondSelection3;
    s8 secondSelection4;
    s8 resultIndex5;
    s8 secondSelection5;
    s8 previewSelection;
    s8 previewSelection2;
    u16 *personaRecord;
    u16 *personaRecord2;
    u16 *personaRecord3;
    u16 *personaRecord4;
    u16 *personaRecord5;
    u16 *personaRecord6;
    u16 resultIndex6;
    u16 resultIndex7;
    u16 secondSelection8;
    u16 resultList4;
    u32 listWork;
    u32 randomValue;
    u8 spriteAlpha;
    u8 spriteAlpha2;
    u8 spriteAlpha3;
    u8 spriteAlpha4;
    s32 resultIndex8;
    u8 spriteAlpha5;
    u8 spriteAlpha6;
    s32 resultIndex9;
    s32 resultIndex10;
    u8 spriteAlpha7;
    u8 spriteAlpha8;
    u8 spriteAlpha9;
    s32 resultIndex11;
    u8 state;
    u8 spriteValue4;
    u8 spriteValue5;
    u8 spriteValue6;
    FclVec2f *basePos;
    u8 *resultList5;
    u8 *resultList6;
    u8 *resultList7;
    FclCombineCtl *menuWork;
    FclCombineColumnTasks *entry;
    FclCombineCtl *menuWork2;
    FclCombineCtl *menuWork3;
    FclCombineCtl *menuWork4;
    FclCombineCtl *menuWork5;
    FclCombineCtl *menuWork6;
    FclCombineCtl *menuWork7;
    FclCombineCtl *menuWork8;
    FclCombineCtl *menuWork9;
    FclCombineCtl *menuWork10;
    FclCombineCtl *menuWork11;
    FclCombineCtl *menuWork12;
    u8 *sprite17;
    u8 *sprite18;
    u8 *sprite19;
    u8 *sprite20;
    u8 *sprite21;
    u8 *sprite22;
    u8 *sprite23;
    u8 *sprite24;
    u8 *sprite25;
    u8 *sprite26;
    u8 *sprite27;
    u8 *sprite28;
    u8 *sprite29;
    u8 *sprite30;
    u8 *sprite31;

    menuWork = (FclCombineCtl*)((KwlnTask *)task)->work;
    state = (u8)((u8)((u8)(menuWork->f1)));
    switch (state) {                               /* switch 1 */
    case 0x38:                                      /* switch 1 */
        yListSlotCreate(1, 0);
        yListSlotCreate(0xA, 1);
        yListSlotCreate(0xA, 2);
        yListSlotCreate(0xA, 3);
        yListSlotCreate(0xA, 4);
        yListSlotCreate(0xA, 5);
        yListSlotCreate(0xA, 6);
        yListSlotCreate(0xA, 7);
        yListSlotCreate(0xA, 8);
        yListSlotCreate(0xA, 9);
        yListSlotCreate(0xA, 0xA);
        yListSlotCreate(0xA, 0xB);
        yListSlotCreate(0xA, 0xC);
        yListSlotCreate(0, 0xD);
        fclCombineLayoutDetailSprites(task, 1);
        menuWork->f1 = 0x39U;
        return;
    case 0x39:                                      /* switch 1 */
        if (fclCombineRowsBusy(task) != 1 && *(s8 *)yListSlotWork(0) == 1) {
            for (partyRow = 0; partyRow < (datPersonaRosterCapacity() & 0xFFFF); partyRow++) {
                color = fclMakeDrawColor(0, 0, 0x99, 0xFF);
                ((FclCombineBallSlot *)fclCombineSlotRecord((u8 *)menuWork->f188, partyRow))->color = color;
            }
            fclCombineSlideInSlotSprites(task, 0x93, 0x96);
            fclCombineSetupPairGrid(task, 1);
            fclCombineLayoutFrame(task, 1, 0);
            fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            menuWork->f1 = 0x3AU;
            return;
        }
        break;
    case 0x3A:                                      /* switch 1 */
        for (partyRow = 0; partyRow < (datPersonaRosterCapacity() & 0xFFFF); partyRow++) {
            spriteValue = (f32)((FclCombineRowSprite *)fclSpriteEntry(partyRow + 0x21C))->positionElapsed;
            spriteValue4 = (u8)fclEaseInterpolate(0, 0, 255.0f, spriteValue, (f32)((FclCombineRowSprite *)fclSpriteEntry(partyRow + 0x21C))->positionDuration);
            if (menuWork->f11E == partyRow) {
                textColor17 = fclPackRgba(0x2D, 0x2D, 0x2D, spriteValue4);
            } else {
                textColor17 = fclPackRgba(0xCC, 0xFF, 0xFF, spriteValue4);
            }
            if (partyRow < ((FclCombinePersonaListHeader *)yListSlotWork(0))->count) {
                spriteValue = (f32)(partyRow * 0x17 + 0x80);
                frFontExDrawTextDeferredOutB(113.0f, spriteValue, 43.0f, textColor17, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, partyRow))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
            }
        }
        if (((*(s16 *)fclCombineSlotRecord(((u8 **)((u8 *)menuWork + 0x150))[datPersonaRosterCapacity() & 0xFFFF], (datPersonaRosterCapacity() & 0xFFFF) - 1) & 4) >> 2) == 0) {
            coordinate2 = (f32)(u32)datPersonaRosterCapacity() / 12.0f;
            position3 = fclMakeVec2((f32)0x149, 128.0f);
            base3A = *(FclVec2f *)&position3;
            coordinate = (f32)((datPersonaRosterCapacity() & 0xFFFF) * 0x17) / 2.0f;
            position = fclMakeVec2(base3A.x + coordinate, base3A.y + coordinate);
            spriteNode4 = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x7E);
            coordinate3 = coordinate2 * sdkSpriteScaledWidth(spriteNode4) / 2.0f;
            coordinate4 = coordinate2 * sdkSpriteScaledHeight(spriteNode4) / 2.0f;
            sdkSpriteFreeNode(spriteNode4);
            position2 = fclMakeVec2(position.x - coordinate3, position.y - coordinate4);
            fclSpriteCreate(0x7E, position2, 156.0f, 0x56);
            fclSpriteStartAlphaAt(0x7E, 0, 0xFF, 0, 2, 0);
            ((FclCombineMenuSprite *)fclSpriteEntry(0x7E))->scaleY = coordinate2;
            ((FclCombineMenuSprite *)fclSpriteEntry(0x7E))->scaleX = coordinate2;
            switch (datPersonaRosterCapacity() & 0xFFFF) {
            case 12:
                position4 = fclMakeVec2(position2.x, position2.y - 20.0f);
                fclSpriteStartPositionAt(0x7E, position2, *(FclVec2f *)&position4, 1, 8, 0);
                break;
            case 10:
                position5 = fclMakeVec2(position2.x, position2.y - 16.0f);
                fclSpriteStartPositionAt(0x7E, position2, *(FclVec2f *)&position5, 1, 8, 0);
                break;
            case 8:
                position6 = fclMakeVec2(position2.x, position2.y - 13.0f);
                fclSpriteStartPositionAt(0x7E, position2, *(FclVec2f *)&position6, 1, 8, 0);
                break;
            case 6:
                position7 = fclMakeVec2(position2.x, position2.y - 10.0f);
                fclSpriteStartPositionAt(0x7E, position2, *(FclVec2f *)&position7, 1, 8, 0);
                break;
            }
            ((FclCombineRowSprite *)fclSpriteEntry(0x7E))->positionReverse = 1;
            fclSpriteStartRevealScaleAt(0x7E, coordinate2, coordinate2, coordinate2 - iGpffff8218, coordinate2, 0, 4, 4);
            if (menuWork->f128 == -1) {
                menuWork->f11E = 0;
            }
            menuWork->f1 = 0x3DU;
            return;
        }
        break;
    case 0x3B:                                      /* switch 1 */
        for (gridRow = 0; gridRow < (datPersonaRosterCapacity() & 0xFFFF); gridRow++) {
            spriteValue2 = (f32)((FclCombineRowSprite *)fclSpriteEntry(gridRow + 0x21C))->positionElapsed;
            spriteValue5 = (u8)fclEaseInterpolate(0, 255.0f, 0.0f, spriteValue2, (f32)((FclCombineRowSprite *)fclSpriteEntry(gridRow + 0x21C))->positionDuration);
            if (menuWork->f11E == gridRow) {
                textColor16 = fclPackRgba(0x2D, 0x2D, 0x2D, spriteValue5);
            } else {
                textColor16 = fclPackRgba(0xCC, 0xFF, 0xFF, spriteValue5);
            }
            if (gridRow < ((FclCombinePersonaListHeader *)yListSlotWork(0))->count) {
                spriteValue = (f32)(gridRow * 0x17 + 0x80);
                frFontExDrawTextDeferredOutB(113.0f, spriteValue, 43.0f, textColor16, 0, 2, (const char *)(iGpffffb440 + ((u16 *)yListSlotEntry(0, gridRow))[1] * 0x11), 0, 0, D_00795E60, 0x15);
            }
        }
        if (((s32)((s32)(((s32) (*(s16 *)fclCombineSlotRecord((u8 *)(menuWork->rows[0]), 0) & 4) >> 2))) == (s32)((s32)(0))) && ((s32)((s32)(((s16)(fclSpriteFlagBit((*((s16 *)((u8 *)(fclSpriteEntry(0x21C)) + (0x10)))), 1))))) == (s32)((s32)(0)))) {
            fclCombineSlideInSlotSprites(task, 0x96, 0x93);
            fclCombineLayoutTransition(task, 0U);
            fclCombineLayoutDetailSprites(task, 0);
            menuWork->f0 = 0;
            menuWork->f1 = 0x1AU;
            return;
        }
        break;
    case 0x3D:                                      /* switch 1 */
        candidateFound = -1;
        for (partyRow = 0; partyRow < (datPersonaRosterCapacity() & 0xFFFF); partyRow++) {
            spriteValue3 = (f32)((FclCombineRowSprite *)fclSpriteEntry(partyRow + 0x21C))->positionElapsed;
            spriteValue6 = (u8)fclEaseInterpolate(0, 0.0f, 255.0f, spriteValue3, (f32)((FclCombineRowSprite *)fclSpriteEntry(partyRow + 0x21C))->positionDuration);
            if (menuWork->f11E == partyRow) {
                textColor18 = fclPackRgba(0x2D, 0x2D, 0x2D, spriteValue6);
            } else {
                textColor18 = fclPackRgba(0xCC, 0xFF, 0xFF, spriteValue6);
            }
            if (partyRow < ((FclCombinePersonaListHeader *)yListSlotWork(0))->count) {
                spriteValue = (f32)(partyRow * 0x17 + 0x80);
                frFontExDrawTextDeferredOutB(113.0f, spriteValue, 43.0f, textColor18, 0, 2, (const char *)(iGpffffb440 + ((u16 *)yListSlotEntry(0, partyRow))[1] * 0x11), 0, 0, D_00795E60, 0x15);
            }
            spriteFlags = (s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(partyRow + 0x21C))->flags, 1);
            if (spriteFlags == 1) {
                candidateFound = 1;
            }
        }
        if (((s16)(candidateFound)) == -1) {
            menuWork->f1 = 0x3CU;
            return;
        }
        break;
    case 0x3C:                                      /* switch 1 */
        if ((s8)fclDrawGetState((u8 *)menuWork->f148) < 0 || (s8)fclDrawGetState((u8 *)menuWork->f148) > 5) {
            fclCombineHandleGridInput(task, 1, 0x40, 0x3B);
            return;
        }
        break;
    case 0x3E:                                      /* switch 1 */
        if ((s32)((s32)(((s16)(fclSpriteFlagBit((*((s16 *)((u8 *)(fclSpriteEntry(0x21C)) + (0x10)))), 1))))) != (s32)((s32)(1))) {
            fclDrawSetPlacement((u8 *)(menuWork->f148), (s32)((u16 *)yListSlotEntry(0, menuWork->f11E)), 0, 0);
            shdPersonaEndSelection(fclDrawGetResource((u8 *)(menuWork->f148)), 1);
            personaModel3 = (s32)((s32)((s32)(fclDrawGetResource((u8 *)(menuWork->f148)))));
            shdPersonaSetChildDispCtlHandle((u8 *)personaModel3,  fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
            menuWork->f1 = 0x3FU;
            return;
        }
        break;
    case 0x3F:                                      /* switch 1 */
        if (fclDrawGetState((u8 *)(menuWork->f148)) == (s32)(5)) {
            if ((s32)((s32)(shdPersonaIsSelectionActive(fclDrawGetResource((u8 *)(menuWork->f148))))) == (s32)((s32)(1))) {
                shdPersonaStepSelectionCursor(fclDrawGetResource((u8 *)(menuWork->f148)));
            }
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(shdPersonaIsSelectionActive(fclDrawGetResource((u8 *)(menuWork->f148))))) == (s32)((s32)(0))) {
                    shdPersonaBeginSelection(fclDrawGetResource((u8 *)(menuWork->f148)));
                    fclDrawSetFlag((u8 *)(menuWork->f148),  0);
                } else {
                    shdPersonaEndSelection(fclDrawGetResource((u8 *)(menuWork->f148)), 1);
                    fclDrawSetFlag((u8 *)(menuWork->f148),  1);
                }
                goto restoreTriplePartnerGrid;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(shdPersonaIsSelectionActive(fclDrawGetResource((u8 *)(menuWork->f148))))) == (s32)((s32)(1))) {
                    shdPersonaEndSelection(fclDrawGetResource((u8 *)(menuWork->f148)), 1);
                    fclDrawSetFlag((u8 *)(menuWork->f148),  1);
                    goto restoreTriplePartnerGrid;
                }
                if (fclDrawGetState((u8 *)(menuWork->f148)) == (s32)(5)) {
                    sdkSndStartStream(0, 1, 0, 4);
                    fclDrawSetStateByte((u8 *)(menuWork->f148),  3);
                    if ((s32)((s32)(((s16)(fclSpriteFlagBit((*((s16 *)((u8 *)(fclSpriteEntry(0x1E4)) + (0x10)))), 0))))) == (s32)((s32)(1))) {
                        fclSpriteStartAlphaAt(0x1E4, (*((u8 *)((u8 *)(fclSpriteEntry(0x1E4)) + (0x6E)))), 0, 0, 0xA, 0);
                    }
                    goto restoreTriplePartnerGrid;
                }
            } else {
                goto restoreTriplePartnerGrid;
            }
        } else {
restoreTriplePartnerGrid:
            if ((s8)fclDrawGetState((u8 *)menuWork->f148) < 0 || (s8)fclDrawGetState((u8 *)menuWork->f148) > 5) {
                for (partyRow = 0; partyRow < (datPersonaRosterCapacity() & 0xFFFF); partyRow++) {
                    position8 = fclMakeVec2(16.0f, 128.0f);

                    fclCombinePartyRow(task, position8, (s8)partyRow, ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, partyRow))) + (2))))), ((*((u8 *)((u8 *)(((u16 *)yListSlotEntry(0, partyRow))) + (4))))), 0, 0, ((s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count));
                }
                position9 = fclMakeVec2(16.0f, 104.0f);
                fclCombineDrawSlotFields(task, position9, 0, 0, 0, 0, 0);
                fclCombineFadeLabelSprites(task, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                for (gridRow = 0; gridRow < (datPersonaRosterCapacity() & 0xFFFF); gridRow++) {

                    FCL_COMBINE_TRIPLE_GRID_ROW(menuWork, gridRow, 1, 0, position10, position11, color2, color3);
                    {
                        s16 labelRow;
                        s16 labelId;
                        u8 *labelNode;
                        labelRow = (s16)gridRow;
                        labelId = (s16)((labelRow + 0x25E));
                        labelNode = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x39);
                        fclSpriteStartAlphaAt(labelId, 0U, 0xFF, 0, 3, 0);
                        fclSpriteStartRevealScaleAt(labelId, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, 0);
                        labelX3 = (labelRow * 0x17) + 0x14E;
                        position12 = fclMakeVec2((f32) labelX3, 110.0f + (sdkSpriteScaledHeight(labelNode) / 2.0f));
                        position13 = fclMakeVec2((f32) labelX3, 110.0f);
                        fclSpriteStartPositionAt(labelId, (*(FclVec2f *)&position12), (*(FclVec2f *)&position13),  0,  3,  0);
                        sdkSpriteFreeNode(labelNode);
                    }
                }
                fclSpriteSetHidden((u8 *)(menuWork->f28C), 0);
                fclSpriteSetHidden((u8 *)(menuWork->f290), 0);
                menuWork->f1 = 0x3CU;
                return;
            }
        }
        break;
    case 0x40:                                      /* switch 1 */
        menuWork->f129 = -1;
        for (partyRow = 0; partyRow < (datPersonaRosterCapacity() & 0xFFFF); partyRow++) {
            fclCombineSelectSlotEntry(task, (s8)(partyRow), menuWork->f128, menuWork->f129, 0);
        }
        spriteAlpha9 = (*((u8 *)((u8 *)(fclSpriteEntry(0x7C)) + (0x6E))));
        /* measured: field typing changes 17240 normalized bytes in the full owner. */
        menuWork12 = *(FclCombineCtl **)(task + 0x38);
        sprite27 = (u8 *)(fclSpriteEntry(0x7C));
        position61 = ((FclCombineRowSprite *)sprite27)->position;
        textColor15 = (s32)((s32)(fclPackRgba(0xCC, 0xFF, 0xFF, spriteAlpha9)));
        frFontExDrawTextDeferredOutB(111.0f + position61.x, position61.y, 43.0f, textColor15, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, menuWork12->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s8)fclDrawGetState((u8 *)menuWork->f148) < 0 || (s8)fclDrawGetState((u8 *)menuWork->f148) > 5) {
            if (D_008C027A[0] & 0x1000) {
                menuWork->f11E = (s16)((s16)(fclSubClamped(menuWork->f11E, 1, 0, (s16)(((*((s32 *)((u8 *)(yListSlotWork(0)) + (8)))) - 1)), 2)));
                sdkSndStartStream(0, 0, 0, 0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                menuWork->f11E = (s16)((s16)(fclAddClamped(menuWork->f11E, 1, (s16)(((*((s32 *)((u8 *)(yListSlotWork(0)) + (8)))) - 1)), 0, 2)));
                sdkSndStartStream(0, 0, 0, 0);
                return;
            }
            if (D_008C024E[0] & 0x80) {
                cursorRow = (s16)((s16)((s16)(menuWork->f11E)));
                if (cursorRow < (*((s32 *)((u8 *)(yListSlotWork(0)) + (8))))) {
                    sdkSndStartStream(0, 1, 0, 3);
                    for (partyRow = 0; partyRow < (datPersonaRosterCapacity() & 0xFFFF); partyRow++) {
                        position14 = fclMakeVec2(16.0f, 128.0f);

                        fclCombinePartyRow(task, position14, (s8)partyRow, ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, partyRow))) + (2))))), ((*((u8 *)((u8 *)(((u16 *)yListSlotEntry(0, partyRow))) + (4))))), 0, 1, ((s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count));
                    }
                    position15 = fclMakeVec2(16.0f, 104.0f);
                    fclCombineDrawSlotFields(task, position15, 0, 1, 0, 0, 0);
                    fclCombineFadeLabelSprites(task, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                    for (gridRow = 0; gridRow < (datPersonaRosterCapacity() & 0xFFFF); gridRow++) {
                        FCL_COMBINE_TRIPLE_GRID_ROW(menuWork, gridRow, 0, 1, position16, position11, color4, color5);
                        gridRowIndex = (s16)(gridRow);
                        spriteId = (s16)((gridRowIndex + 0x25E));
                        spriteNode2 = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x39);
                        fclSpriteStartAlphaAt(spriteId, 0xFFU, 0, 0, 3, 0);
                        fclSpriteStartRevealScaleAt(spriteId, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                        labelX = (gridRowIndex * 0x17) + 0x14E;
                        position17 = fclMakeVec2((f32) labelX, 110.0f);
                        position18 = fclMakeVec2((f32) labelX, 110.0f + (sdkSpriteScaledHeight(spriteNode2) / 2.0f));
                        fclSpriteStartPositionAt(spriteId, (*(FclVec2f *)&position17), (*(FclVec2f *)&position18),  0,  3,  0);
                        sdkSpriteFreeNode(spriteNode2);
                    }
                    fclCombineFadePanelSprite(task, 0, 60.0f);
                    fclSpriteSetHidden((u8 *)(menuWork->f28C), 1);
                    fclSpriteSetHidden((u8 *)(menuWork->f290), 1);
                    menuWork->f1 = 0x41U;
                    return;
                }
            } else {
                if (D_008C024E[0] & 0x40) {
                    cursorRow6 = (s16)((s16)((s16)(menuWork->f11E)));
                    if ((menuWork->f128 != cursorRow6) && ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, cursorRow6))) + (2)))) != 0)) {
                        sdkSndStartStream(0, 0, 0, 1);
                        menuWork->f129 = (s8)((s8)((s8) menuWork->f11E));
                        basePos = (FclVec2f *)D_00640C18;
                        position19 = fclMakeVec2(-380.0f, 81.0f);
                        position20 = fclMakeVec2(basePos->x, basePos->y);
                        fclCombineDrawPersonaCardAlt(task, menuWork->f129, position19, position20);
                        for (gridRow = 0; gridRow < (datPersonaRosterCapacity() & 0xFFFF); gridRow++) {
                        gridRowIndex3 = (s16)(gridRow);
                            secondSelection = (s8)((s8)((s8)(menuWork->f129)));
                            if ((*((s8 *)((u8 *)((yListSlotWork((u32)secondSelection + 1U) + (secondSelection * 0xC) + gridRowIndex3)) + (0x14)))) > 0) {
                                position21 = fclMakeVec2((f32) 0x149, 128.0f);

                                fclCombineDrawPersonaRow(task, position21, (s64)menuWork->f129, gridRow, ((u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)yListSlotEntry((s8)((menuWork->f129 + 1)), gridRow))) + (2)))))))), ((*((u8 *)((u8 *)(((u16 *)yListSlotEntry((s8)((secondSelection + 1)), gridRow))) + (4))))), 3, 0, 1, 0xCC);
                            }
                            FCL_COMBINE_TRIPLE_GRID_ROW(menuWork, gridRow, 1, 1, position22, position23, color6, color7);
                            gridRowIndex2 = (s16)(gridRow);
                            spriteId3 = (s16)((gridRowIndex2 + 0x25E));
                            spriteNode3 = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x39);
                            fclSpriteStartAlphaAt(spriteId3, 0xFFU, 0, 0, 3, 0);
                            fclSpriteStartRevealScaleAt(spriteId3, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                            labelX4 = (gridRowIndex2 * 0x17) + 0x14E;
                            position24 = fclMakeVec2((f32) labelX4, 110.0f);
                            position25 = fclMakeVec2((f32) labelX4, 110.0f + (sdkSpriteScaledHeight(spriteNode3) / 2.0f));
                            fclSpriteStartPositionAt(spriteId3, (*(FclVec2f *)&position24), (*(FclVec2f *)&position25),  0,  3,  0);
                            sdkSpriteFreeNode(spriteNode3);
                            secondSelection2 = (s8)((s8)((s8)(menuWork->f129)));
                            if ((*((s8 *)((u8 *)((yListSlotWork((u32)secondSelection2 + 1U) + (secondSelection2 * 0xC) + gridRowIndex2)) + (0x14)))) > 0) {
                                personaRecord = (u16 *)(((u16 *)yListSlotEntry((s8)((menuWork->f129 + 1)), gridRow)));
                                personaRecord5 = (u16 *)(((u16 *)yListSlotEntry(0, menuWork->f128)));
                                personaRecord6 = (u16 *)(((u16 *)yListSlotEntry(0, menuWork->f129)));
                                fclCombineFuseSourceRecords(personaRecord, (u8 *)personaRecord5, (u8 *)personaRecord6, (u8 *)((u16 *)yListSlotEntry(0, gridRow)), NULL, NULL, NULL, 3, (s8)((secondSelection2 + 1)), (s8)(gridRow));
                            }
                        }
                        position26 = fclMakeVec2((f32) 0x149, 104.0f);
                        fclCombineDrawSlotLabels(task, position26, 3, 0);
                        fclCombineSlideInSlotSprites(task, 0x95, 0x94);
                        fclCombineFlashSlot(task, menuWork->f129);
                        menuWork->f1 = 0x43U;
                        return;
                    }
                    sdkSndStartStream(0, 0, 0, 8);
                    return;
                }
                if (D_008C024C[0] & 0x80) {
                    cursorRow2 = (s16)((s16)((s16)(menuWork->f11E)));
                    if (cursorRow2 < (*((s32 *)((u8 *)(yListSlotWork(0)) + (8))))) {
                        sdkSndStartStream(0, 1, 0, 3);
                        for (partyRow = 0; partyRow < (datPersonaRosterCapacity() & 0xFFFF); partyRow++) {
                            position27 = fclMakeVec2(16.0f, 128.0f);

                            fclCombinePartyRow(task, position27, (s8)partyRow, ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, partyRow))) + (2))))), ((*((u8 *)((u8 *)(((u16 *)yListSlotEntry(0, partyRow))) + (4))))), 0, 1, ((s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count));
                        }
                        position28 = fclMakeVec2(16.0f, 104.0f);
                        fclCombineDrawSlotFields(task, position28, 0, 1, 0, 0, 0);
                        for (gridColumn = 0; gridColumn < (datPersonaRosterCapacity() & 0xFFFF); gridColumn++) {
                            FCL_COMBINE_TRIPLE_GRID_ROW(menuWork, gridColumn, 0, 1, position29, position11, color8, color9);
                            gridColumnIndex = (s16)(gridColumn);
                            spriteId2 = (s16)((((s8)((gridColumnIndex + 0x6A))) + 0x1F4));
                            spriteNode = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x39);
                            fclSpriteStartAlphaAt(spriteId2, 0xFFU, 0, 0, 3, 0);
                            fclSpriteStartRevealScaleAt(spriteId2, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                            labelX2 = (gridColumnIndex * 0x17) + 0x14E;
                            position30 = fclMakeVec2((f32) labelX2, 110.0f);
                            position31 = fclMakeVec2((f32) labelX2, 110.0f + (sdkSpriteScaledHeight(spriteNode) / 2.0f));
                            fclSpriteStartPositionAt(spriteId2, (*(FclVec2f *)&position30), (*(FclVec2f *)&position31),  0,  3,  0);
                            sdkSpriteFreeNode(spriteNode);
                        }
                        menuWork->f1 = 0x41U;
                        return;
                    }
                } else if (D_008C024E[0] & 0x20) {
                    fclCombineApplySlotState(task, (s8) menuWork->f11E, 0, 0xFF);
                    menuWork->f11E = menuWork->f128;
                    fclCombineApplySlotState(task, (s8)menuWork->f11E, 1, 0xFF);
                    sdkSndStartStream(0, 0, 0, 2);
                    fclCombineSlideInSlotSprites(task, 0x93, 0x94);
                    basePos = (FclVec2f *)D_00640C10;
                    position32 = fclMakeVec2(basePos->x, basePos->y);
                    position33 = fclMakeVec2(-380.0f, basePos->y);
                    fclCombineDrawPersonaCard(task, menuWork->f128, position32, position33);
                    datPersonaRosterCapacity();
                    for (gridColumn = 0; gridColumn < (datPersonaRosterCapacity() & 0xFFFF); gridColumn++) {
                        candidateIndex = 0;
                        gridColumnIndex2 = (s16)(gridColumn);
                        entry = (FclCombineColumnTasks *)((u8 *)menuWork + gridColumnIndex2 * 4);
                        for (; (s32)((s32)(((s16)(candidateIndex)))) < (s32)((s32)((datPersonaRosterCapacity() & 0xFFFF)));) {
                        value = (s16)(candidateIndex);
                            fclSpriteStartEntrance(fclCombineSlotRecord(entry->list, (s8)candidateIndex),
                                (position34 = fclMakeVec2((f32)(value * 23 + 329), (f32)(gridColumnIndex2 * 23 + 127))),
                                ((FclCombineBallSlot *)fclCombineSlotRecord(entry->list, (s8)candidateIndex))->color,
                                (color10 = fclMakeDrawColor(0, 0, 0x99, 0xA5)), 0xA5, 0xA5,
                                32.0f, ((FclCombineBallSlot *)fclCombineSlotRecord(entry->list, (s8)candidateIndex))->depth, 6, 0, 1, 1);
                            candidateIndex = (s16)((candidateIndex + 1));
                        }
                    }
                    fclSpriteStartAlphaAt(0x7E, 0U, 0xFF, 0, 3, 3);
                    fclSpriteSetFlag(0x7E, 0, 0);
                    menuWork->f1 = 0x3CU;
                    return;
                }
            }
        }
        break;
    case 0x41:                                      /* switch 1 */
        sprite28 = (u8 *)(fclSpriteEntry(0x7C));
        position62 = ((FclCombineRowSprite *)sprite28)->position;
        textColor = (s32)((s32)(fclPackRgba(0xCC, 0xFF, 0xFF, 0xFFU)));
        frFontExDrawTextDeferredOutB(111.0f + position62.x, position62.y, 43.0f, textColor, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, menuWork->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s32)((s32)(((s16)(fclSpriteFlagBit((*((s16 *)((u8 *)(fclSpriteEntry(0x21C)) + (0x10)))), 1))))) != (s32)((s32)(1))) {
            fclDrawSetPlacement((u8 *)(menuWork->f148), (s32)((u16 *)yListSlotEntry(0, menuWork->f11E)), 0, 0);
            shdPersonaEndSelection(fclDrawGetResource((u8 *)(menuWork->f148)), 1);
            personaModel = (s32)((s32)((s32)(fclDrawGetResource((u8 *)(menuWork->f148)))));
            shdPersonaSetChildDispCtlHandle((u8 *)personaModel,  fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
            menuWork->f1 = 0x42U;
            return;
        }
        break;
    case 0x42:                                      /* switch 1 */
        sprite29 = (u8 *)(fclSpriteEntry(0x7C));
        position63 = ((FclCombineRowSprite *)sprite29)->position;
        textColor2 = (s32)((s32)(fclPackRgba(0xCC, 0xFF, 0xFF, 0xFFU)));
        frFontExDrawTextDeferredOutB(111.0f + position63.x, position63.y, 43.0f, textColor2, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, menuWork->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if (fclDrawGetState((u8 *)(menuWork->f148)) == (s32)(5)) {
            if ((s32)((s32)(shdPersonaIsSelectionActive(fclDrawGetResource((u8 *)(menuWork->f148))))) == (s32)((s32)(1))) {
                shdPersonaStepSelectionCursor(fclDrawGetResource((u8 *)(menuWork->f148)));
            }
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(shdPersonaIsSelectionActive(fclDrawGetResource((u8 *)(menuWork->f148))))) == (s32)((s32)(0))) {
                    shdPersonaBeginSelection(fclDrawGetResource((u8 *)(menuWork->f148)));
                    fclDrawSetFlag((u8 *)(menuWork->f148),  0);
                } else {
                    shdPersonaEndSelection(fclDrawGetResource((u8 *)(menuWork->f148)), 1);
                    fclDrawSetFlag((u8 *)(menuWork->f148),  1);
                }
                goto restoreTripleRoster;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(shdPersonaIsSelectionActive(fclDrawGetResource((u8 *)(menuWork->f148))))) == (s32)((s32)(1))) {
                    shdPersonaEndSelection(fclDrawGetResource((u8 *)(menuWork->f148)), 1);
                    fclDrawSetFlag((u8 *)(menuWork->f148),  1);
                    goto restoreTripleRoster;
                }
                if (fclDrawGetState((u8 *)(menuWork->f148)) == (s32)(5)) {
                    sdkSndStartStream(0, 1, 0, 4);
                    fclDrawSetStateByte((u8 *)(menuWork->f148),  3);
                    if ((s32)((s32)(((s16)(fclSpriteFlagBit((*((s16 *)((u8 *)(fclSpriteEntry(0x1E4)) + (0x10)))), 0))))) == (s32)((s32)(1))) {
                        fclSpriteStartAlphaAt(0x1E4, (*((u8 *)((u8 *)(fclSpriteEntry(0x1E4)) + (0x6E)))), 0, 0, 0xA, 0);
                    }
                    goto restoreTripleRoster;
                }
            } else {
                goto restoreTripleRoster;
            }
        } else {
restoreTripleRoster:
            if ((s8)fclDrawGetState((u8 *)menuWork->f148) < 0 || (s8)fclDrawGetState((u8 *)menuWork->f148) > 5) {
                for (partyRow = 0; partyRow < (datPersonaRosterCapacity() & 0xFFFF); partyRow++) {
                    position35 = fclMakeVec2(16.0f, 128.0f);

                    fclCombinePartyRow(task, position35, (s8)partyRow, ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, partyRow))) + (2))))), ((*((u8 *)((u8 *)(((u16 *)yListSlotEntry(0, partyRow))) + (4))))), 0, 0, ((s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count));
                }
                position36 = fclMakeVec2(16.0f, 104.0f);
                fclCombineDrawSlotFields(task, position36, 0, 0, 0, 0, 0);
                fclCombineFadeLabelSprites(task, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                fclCombineRefreshGridCells(task, 0);
                fclSpriteSetHidden((u8 *)(menuWork->f28C), 0);
                fclSpriteSetHidden((u8 *)(menuWork->f290), 0);
                menuWork->f1 = 0x40U;
                return;
            }
        }
        break;
    case 0x43:                                      /* switch 1 */
        fclCombineRefreshRosterSelection(task);
        spriteAlpha = (*((u8 *)((u8 *)(fclSpriteEntry(0x7C)) + (0x6E))));
        /* measured: field typing changes 17240 normalized bytes in the full owner. */
        menuWork2 = *(FclCombineCtl **)(task + 0x38);
        sprite30 = (u8 *)(fclSpriteEntry(0x7C));
        position64 = ((FclCombineRowSprite *)sprite30)->position;
        textColor3 = (s32)((s32)(fclPackRgba(0xCC, 0xFF, 0xFF, spriteAlpha)));
        frFontExDrawTextDeferredOutB(111.0f + position64.x, position64.y, 43.0f, textColor3, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, menuWork2->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        spriteAlpha2 = (*((u8 *)((u8 *)(fclSpriteEntry(0x7D)) + (0x6E))));
        /* measured: field typing changes 17241 normalized bytes in the full owner. */
        menuWork3 = *(FclCombineCtl **)(task + 0x38);
        sprite31 = (u8 *)(fclSpriteEntry(0x7D));
        position65 = ((FclCombineRowSprite *)sprite31)->position;
        textColor4 = (s32)((s32)(fclPackRgba(0xCC, 0xFF, 0xFF, spriteAlpha2)));
        frFontExDrawTextDeferredOutB(111.0f + position65.x, position65.y, 43.0f, textColor4, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, menuWork3->f129))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s8)fclDrawGetState((u8 *)menuWork->f148) < 0 || (s8)fclDrawGetState((u8 *)menuWork->f148) > 5) {
            if ((s32)((s32)(((s16)(fclSpriteFlagBit((*((s16 *)((u8 *)(fclSpriteEntry(0x1C7)) + (0x10)))), 0))))) == (s32)((s32)(1))) {
                fclCombineStepSidePanel(task, 0x1C7, 0);
                fclCombineStepSidePanel(task, 0x2E8, 1);
            }
            if (D_008C027A[0] & 0x1000) {
                menuWork->f11E = (s16)((s16)(fclSubClamped(menuWork->f11E, 1, 0, (s16)(((*((s32 *)((u8 *)(yListSlotWork(0)) + (8)))) - 1)), 2)));
                sdkSndStartStream(0, 0, 0, 0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                menuWork->f11E = (s16)((s16)(fclAddClamped(menuWork->f11E, 1, (s16)(((*((s32 *)((u8 *)(yListSlotWork(0)) + (8)))) - 1)), 0, 2)));
                sdkSndStartStream(0, 0, 0, 0);
                return;
            }
            if (D_008C024E[0] & 0x80) {
                cursorRow3 = (s16)((s16)((s16)(menuWork->f11E)));
                if (cursorRow3 < (*((s32 *)((u8 *)(yListSlotWork(0)) + (8))))) {
                    sdkSndStartStream(0, 1, 0, 3);
                    for (resultRow = 0; resultRow < (datPersonaRosterCapacity() & 0xFFFF); resultRow++) {
                        position37 = fclMakeVec2((f32) 0x149, 128.0f);

                        fclCombineDrawPersonaRow(task, position37, (s64)menuWork->f129, resultRow, ((u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)yListSlotEntry((s8)((menuWork->f129 + 1)), resultRow))) + (2)))))))), ((*((u8 *)((u8 *)(((u16 *)yListSlotEntry((s8)((menuWork->f129 + 1)), resultRow))) + (4))))), 0, 1, 1, 0xCC);
                        position38 = fclMakeVec2(16.0f, 128.0f);

                        fclCombinePartyRow(task, position38, (s8)resultRow, ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, resultRow))) + (2))))), ((*((u8 *)((u8 *)(((u16 *)yListSlotEntry(0, resultRow))) + (4))))), 0, 1, ((s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count));
                    }
                    position39 = fclMakeVec2(16.0f, 104.0f);
                    fclCombineDrawSlotFields(task, position39, 0, 1, 0, 0, 0);
                    position40 = fclMakeVec2((f32) 0x149, 104.0f);
                    fclCombineDrawSlotLabels(task, position40, 0, 1);
                    fclCombineLayoutFrame(task, 1, 1);
                    fclCombineFadeLabelSprites(task, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                    fclCombineFadePanelSprite(task, 0, 60.0f);
                    fclSpriteSetHidden((u8 *)(menuWork->f28C), 1);
                    fclSpriteSetHidden((u8 *)(menuWork->f290), 1);
                    menuWork->f1 = 0x44U;
                    return;
                }
            } else {
                if (D_008C024E[0] & 0x40) {
                    cursorRow5 = (s16)((s16)((s16)(menuWork->f11E)));
                    if (menuWork->f128 != cursorRow5) {
                        secondSelection5 = (s8)((s8)((s8)(menuWork->f129)));
                        if ((secondSelection5 != cursorRow5) && ((*((s8 *)((u8 *)((yListSlotWork((s8) ((s8)((secondSelection5 + 1)))) + (menuWork->f129 * 0xC) + menuWork->f11E)) + (0x14)))) > 0)) {
                            sdkSndStartStream(0, 0, 0, 1);
                            for (resultRow = 0; resultRow < (datPersonaRosterCapacity() & 0xFFFF); resultRow++) {
                                position41 = fclMakeVec2((f32) 0x149, 128.0f);

                                fclCombineDrawPersonaRow(task, position41, (s64)menuWork->f129, resultRow, ((u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)yListSlotEntry((s8)((menuWork->f129 + 1)), resultRow))) + (2)))))))), ((*((u8 *)((u8 *)(((u16 *)yListSlotEntry((s8)((menuWork->f129 + 1)), resultRow))) + (4))))), 0, 1, 1, 0xCC);
                                position42 = fclMakeVec2(16.0f, 128.0f);

                                fclCombinePartyRow(task, position42, (s8)resultRow, ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, resultRow))) + (2))))), ((*((u8 *)((u8 *)(((u16 *)yListSlotEntry(0, resultRow))) + (4))))), 0, 1, ((s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count));
                            }
                            position43 = fclMakeVec2(16.0f, 104.0f);
                            fclCombineDrawSlotFields(task, position43, 0, 1, 0, 0, 0);
                            position44 = fclMakeVec2((f32) 0x149, 104.0f);
                            fclCombineDrawSlotLabels(task, position44, 0, 1);
                            fclCombineLayoutFrame(task, 1, 1);
                            fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                            fclCombineFadePanelSprite(task, 0, 0);
                            fclSpriteSetHidden((u8 *)(menuWork->f28C), 1);
                            fclSpriteSetHidden((u8 *)(menuWork->f290), 1);
                            menuWork->f1 = 0x47U;
                            return;
                        }
                    }
                    sdkSndStartStream(0, 0, 0, 8);
                    return;
                }
                if (D_008C024E[0] & 0x20) {
                    fclCombineApplySlotState(task, (s8) menuWork->f11E, 0, 0xFF);
                    menuWork->f11E = menuWork->f129;
                    fclCombineApplySlotState(task, (s8)menuWork->f11E, 1, 0xFF);
                    sdkSndStartStream(0, 0, 0, 2);
                    basePos = (FclVec2f *)D_00640C18;
                    position45 = fclMakeVec2(basePos->x, basePos->y);
                    position46 = fclMakeVec2(-380.0f, 81.0f);
                    fclCombineDrawPersonaCardAlt(task, menuWork->f129, position45, position46);
                    position47 = fclMakeVec2((f32) 0x149, 104.0f);
                    fclCombineDrawSlotLabels(task, position47, 0, 1);
                    for (resultRow = 0; resultRow < (datPersonaRosterCapacity() & 0xFFFF); resultRow++) {
                        position48 = fclMakeVec2((f32) 0x149, 128.0f);

                        fclCombineDrawPersonaRow(task, position48, (s64)menuWork->f129, resultRow, ((u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)yListSlotEntry((s8)((menuWork->f129 + 1)), resultRow))) + (2)))))))), ((*((u8 *)((u8 *)(((u16 *)yListSlotEntry((s8)((menuWork->f129 + 1)), resultRow))) + (4))))), 0, 1, 1, 0xCC);
                    }
                    fclCombineRefreshGridCells(task, 3);
                    fclCombineSlideInSlotSprites(task, 0x94, 0x95);
                    menuWork->f1 = 0x40U;
                    return;
                }
            }
        }
        break;
    case 0x44:                                      /* switch 1 */
        sprite17 = (u8 *)(fclSpriteEntry(0x7C));
        position66 = ((FclCombineRowSprite *)sprite17)->position;
        textColor5 = (s32)((s32)(fclPackRgba(0xCC, 0xFF, 0xFF, 0xFFU)));
        frFontExDrawTextDeferredOutB(111.0f + position66.x, position66.y, 43.0f, textColor5, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, menuWork->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        /* measured: field typing changes 17241 normalized bytes in the full owner. */
        menuWork4 = *(FclCombineCtl **)(task + 0x38);
        sprite18 = (u8 *)(fclSpriteEntry(0x7D));
        position67 = ((FclCombineRowSprite *)sprite18)->position;
        textColor6 = (s32)((s32)(fclPackRgba(0xCC, 0xFF, 0xFF, 0xFFU)));
        frFontExDrawTextDeferredOutB(111.0f + position67.x, position67.y, 43.0f, textColor6, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, menuWork4->f129))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s32)((s32)(((s16)(fclSpriteFlagBit((*((s16 *)((u8 *)(fclSpriteEntry(0x21C)) + (0x10)))), 1))))) != (s32)((s32)(1))) {
            fclDrawSetPlacement((u8 *)(menuWork->f148), (s32)((u16 *)yListSlotEntry(0, menuWork->f11E)), 0, 0);
            shdPersonaEndSelection(fclDrawGetResource((u8 *)(menuWork->f148)), 1);
            personaModel2 = (s32)((s32)((s32)(fclDrawGetResource((u8 *)(menuWork->f148)))));
            shdPersonaSetChildDispCtlHandle((u8 *)personaModel2,  fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
            menuWork->f1 = 0x45U;
            return;
        }
        break;
    case 0x45:                                      /* switch 1 */
        sprite19 = (u8 *)(fclSpriteEntry(0x7C));
        position68 = ((FclCombineRowSprite *)sprite19)->position;
        textColor7 = (s32)((s32)(fclPackRgba(0xCC, 0xFF, 0xFF, 0xFFU)));
        frFontExDrawTextDeferredOutB(111.0f + position68.x, position68.y, 43.0f, textColor7, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, menuWork->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        /* measured: field typing changes 17241 normalized bytes in the full owner. */
        menuWork5 = *(FclCombineCtl **)(task + 0x38);
        sprite20 = (u8 *)(fclSpriteEntry(0x7D));
        position69 = ((FclCombineRowSprite *)sprite20)->position;
        textColor8 = (s32)((s32)(fclPackRgba(0xCC, 0xFF, 0xFF, 0xFFU)));
        frFontExDrawTextDeferredOutB(111.0f + position69.x, position69.y, 43.0f, textColor8, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, menuWork5->f129))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if (fclDrawGetState((u8 *)(menuWork->f148)) == (s32)(5)) {
            if ((s32)((s32)(shdPersonaIsSelectionActive(fclDrawGetResource((u8 *)(menuWork->f148))))) == (s32)((s32)(1))) {
                shdPersonaStepSelectionCursor(fclDrawGetResource((u8 *)(menuWork->f148)));
            }
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(shdPersonaIsSelectionActive(fclDrawGetResource((u8 *)(menuWork->f148))))) == (s32)((s32)(0))) {
                    shdPersonaBeginSelection(fclDrawGetResource((u8 *)(menuWork->f148)));
                    fclDrawSetFlag((u8 *)(menuWork->f148),  0);
                } else {
                    shdPersonaEndSelection(fclDrawGetResource((u8 *)(menuWork->f148)), 1);
                    fclDrawSetFlag((u8 *)(menuWork->f148),  1);
                }
                goto restoreTripleResultGrid;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(shdPersonaIsSelectionActive(fclDrawGetResource((u8 *)(menuWork->f148))))) == (s32)((s32)(1))) {
                    shdPersonaEndSelection(fclDrawGetResource((u8 *)(menuWork->f148)), 1);
                    fclDrawSetFlag((u8 *)(menuWork->f148),  1);
                    goto restoreTripleResultGrid;
                }
                if (fclDrawGetState((u8 *)(menuWork->f148)) == (s32)(5)) {
                    sdkSndStartStream(0, 1, 0, 4);
                    fclDrawSetStateByte((u8 *)(menuWork->f148),  3);
                    if ((s32)((s32)(((s16)(fclSpriteFlagBit((*((s16 *)((u8 *)(fclSpriteEntry(0x1E4)) + (0x10)))), 0))))) == (s32)((s32)(1))) {
                        fclSpriteStartAlphaAt(0x1E4, (*((u8 *)((u8 *)(fclSpriteEntry(0x1E4)) + (0x6E)))), 0, 0, 0xA, 0);
                    }
                    goto restoreTripleResultGrid;
                }
            } else {
                goto restoreTripleResultGrid;
            }
        } else {
restoreTripleResultGrid:
            if ((s8)fclDrawGetState((u8 *)menuWork->f148) < 0 || (s8)fclDrawGetState((u8 *)menuWork->f148) > 5) {
                fclCombineLayoutFrame(task, 1, 0);
                fclCombineFadeLabelSprites(task, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                for (gridRow = 0; gridRow < (datPersonaRosterCapacity() & 0xFFFF); gridRow++) {

                    position49 = fclMakeVec2(16.0f, 128.0f);

                    fclCombinePartyRow(task, position49, (s8)gridRow, ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, gridRow))) + (2))))), ((*((u8 *)((u8 *)(((u16 *)yListSlotEntry(0, gridRow))) + (4))))), 0, 0, ((s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count));
                    secondSelection3 = (s8)((s8)((s8)(menuWork->f129)));
                    if ((*((s8 *)((u8 *)((yListSlotWork((u32)secondSelection3 + 1U) + (secondSelection3 * 0xC) + gridRow)) + (0x14)))) > 0) {
                        position50 = fclMakeVec2((f32) 0x149, 128.0f);

                        fclCombineDrawPersonaRow(task, position50, (s64)menuWork->f129, gridRow, ((u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)yListSlotEntry((s8)((menuWork->f129 + 1)), gridRow))) + (2)))))))), ((*((u8 *)((u8 *)(((u16 *)yListSlotEntry((s8)((secondSelection3 + 1)), gridRow))) + (4))))), 0, 0, 1, 0xCC);
                    }
                }
                position51 = fclMakeVec2(16.0f, 104.0f);
                fclCombineDrawSlotFields(task, position51, 0, 0, 0, 0, 0);
                position52 = fclMakeVec2((f32) 0x149, 104.0f);
                fclCombineDrawSlotLabels(task, position52, 0, 0);
                menuWork->f1 = 0x43U;
                return;
            }
        }
        break;
    case 0x47:                                      /* switch 1 */
        spriteAlpha3 = (u8)((u8)((u8)((*((u8 *)((u8 *)(fclSpriteEntry(0x7C)) + (0x6E)))))));
        /* measured: field typing changes 17240 normalized bytes in the full owner. */
        menuWork6 = *(FclCombineCtl **)(task + 0x38);
        sprite21 = (u8 *)(fclSpriteEntry(0x7C));
        position70 = ((FclCombineRowSprite *)sprite21)->position;
        textColor9 = (s32)((s32)(fclPackRgba(0xCC, 0xFF, 0xFF, spriteAlpha3)));
        frFontExDrawTextDeferredOutB(111.0f + position70.x, position70.y, 43.0f, textColor9, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, menuWork6->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        spriteAlpha4 = (*((u8 *)((u8 *)(fclSpriteEntry(0x7D)) + (0x6E))));
        /* measured: field typing changes 17241 normalized bytes in the full owner. */
        menuWork7 = *(FclCombineCtl **)(task + 0x38);
        sprite22 = (u8 *)(fclSpriteEntry(0x7D));
        position71 = ((FclCombineRowSprite *)sprite22)->position;
        textColor10 = (s32)((s32)(fclPackRgba(0xCC, 0xFF, 0xFF, spriteAlpha4)));
        frFontExDrawTextDeferredOutB(111.0f + position71.x, position71.y, 43.0f, textColor10, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, menuWork7->f129))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s32)((s32)(((s16)(fclSpriteFlagBit((*((s16 *)((u8 *)(fclSpriteEntry(0x21C)) + (0x10)))), 1))))) != (s32)((s32)(1))) {
            menuWork->f2F9 = (s8)((s8)((s8) (menuWork->f129 + 1)));
            cursorRow4 = (s16)((s16)((s16)(menuWork->f11E)));
            menuWork->f2FA = (s8) cursorRow4;
            resultIndex = menuWork->f2FA;
            personaRecord2 = (u16 *)(((u16 *)yListSlotEntry(menuWork->f2F9, resultIndex)));
            resultList5 = (u8 *)(yListSlotWork(menuWork->f2F9) + ((s8)(resultIndex)));
            community = (s64)((s64)((s16)cmmTopCommunityOfArcana(iGpffffb3d4[((u16 *)yListSlotEntry(menuWork->f2F9, menuWork->f2FA))[1] * 14 + 2])));
            fclDrawSetPlacementEx((u8 *)(menuWork->f148), (s32)(personaRecord2), (((FclPartySlot *)(resultList5))->f2E4), cmmCommunityExpRemaining(community, (u8 *)((u8 *)(((u16 *)yListSlotEntry(menuWork->f2F9, menuWork->f2FA)))), 0), 1);
            personaModel4 = (s32)((s32)((s32)(fclDrawGetResource((u8 *)(menuWork->f148)))));
            shdPersonaSetChildDispCtlHandle((u8 *)personaModel4,  fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
            resultIndex8 = (u8)((u8)((u8)((*((u8 *)((u8 *)(((u16 *)yListSlotEntry(menuWork->f2F9, menuWork->f2FA))) + (4)))))));
            if ((s32)((s32)((datCalcGetLevelById(1) & 0xFF))) < (s32)((s32)((s32) resultIndex8))) {
                personaModel5 = (s32)((s32)((s32)(fclDrawGetResource((u8 *)(menuWork->f148)))));
                shdPersonaSetChildDispCtlHandle((u8 *)personaModel5,  fclPackRgba(0x14, 0x14, 0x14, 0xFFU));
            }
            shdPersonaEndSelection(fclDrawGetResource((u8 *)(menuWork->f148)), 1);
            fclCombineDrawStageBanner(task, 4, 0);
            menuWork->f1 = 0x46U;
            return;
        }
        break;
    case 0x46:                                      /* switch 1 */
        spriteAlpha5 = (u8)((u8)((u8)((*((u8 *)((u8 *)(fclSpriteEntry(0x7C)) + (0x6E)))))));
        /* measured: field typing changes 17240 normalized bytes in the full owner. */
        menuWork8 = *(FclCombineCtl **)(task + 0x38);
        sprite23 = (u8 *)(fclSpriteEntry(0x7C));
        position72 = ((FclCombineRowSprite *)sprite23)->position;
        textColor11 = (s32)((s32)(fclPackRgba(0xCC, 0xFF, 0xFF, spriteAlpha5)));
        frFontExDrawTextDeferredOutB(111.0f + position72.x, position72.y, 43.0f, textColor11, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, menuWork8->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        spriteAlpha6 = (*((u8 *)((u8 *)(fclSpriteEntry(0x7D)) + (0x6E))));
        /* measured: field typing changes 17241 normalized bytes in the full owner. */
        menuWork9 = *(FclCombineCtl **)(task + 0x38);
        sprite24 = (u8 *)(fclSpriteEntry(0x7D));
        position73 = ((FclCombineRowSprite *)sprite24)->position;
        textColor12 = (s32)((s32)(fclPackRgba(0xCC, 0xFF, 0xFF, spriteAlpha6)));
        frFontExDrawTextDeferredOutB(111.0f + position73.x, position73.y, 43.0f, textColor12, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, menuWork9->f129))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s32)((s8)fclDrawGetState((u8 *)(menuWork->f148))) == (s32)(0xD)) {
            if ((s32)((s32)(shdPersonaIsSelectionActive(fclDrawGetResource((u8 *)(menuWork->f148))))) == (s32)((s32)(1))) {
                shdPersonaStepSelectionCursor(fclDrawGetResource((u8 *)(menuWork->f148)));
            }
            if (D_008C024E[0] & 0x40) {
                menuWork->f1 = 0x48U;
                sdkSndStartStream(0, 0, 0, 1);
                return;
            }
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(shdPersonaIsSelectionActive(fclDrawGetResource((u8 *)(menuWork->f148))))) == (s32)((s32)(0))) {
                    shdPersonaBeginSelection(fclDrawGetResource((u8 *)(menuWork->f148)));
                    fclDrawSetFlag((u8 *)(menuWork->f148), 0);
                    return;
                }
                shdPersonaEndSelection(fclDrawGetResource((u8 *)(menuWork->f148)), 1);
                fclDrawSetFlag((u8 *)(menuWork->f148), 1);
                return;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(shdPersonaIsSelectionActive(fclDrawGetResource((u8 *)(menuWork->f148))))) == (s32)((s32)(1))) {
                    shdPersonaEndSelection(fclDrawGetResource((u8 *)(menuWork->f148)), 1);
                    fclDrawSetFlag((u8 *)(menuWork->f148),  1);
                    return;
                }
                sdkSndStartStream(0, 0, 0, 2);
                menuWork->f1 = 0x4EU;
                fclDrawSetStateByte((u8 *)(menuWork->f148),  0xB);
                fclCombineFadePanelSprite(task, 1, 0);
                fclCombineDrawStageBanner(task, 4, 1);
                return;
            }
            if (D_008C024E[0] & 8) {
                if (menuWork->f122 != 3) {
                    sdkSndStartStream(0, 2, 0, 5);
                }
                menuWork->f122 = (s8)((s8)(fclAddClamped(menuWork->f122, 1, 3, 0, 1)));
                s0 = fclSpriteEntry(0x152);
                position53 = fclMakeVec2((f32)((menuWork->f122 * 0x6B) + 0x6A), 16.0f);
                fclSpriteStartPositionAt(0x152, (((FclCombineRowSprite *)s0)->position), (*(FclVec2f *)&position53),  1,  4,  0);
                s0 = fclSpriteEntry(0x2E0);
                position54 = fclMakeVec2((f32)((menuWork->f122 * 0x6B) + 0x6A), 16.0f);
                fclSpriteStartPositionAt(0x2E0, (((FclCombineRowSprite *)s0)->position), (*(FclVec2f *)&position54),  1,  4,  0);
                previewSelection = (s8)((s8)((s8)(menuWork->f122)));
                switch (previewSelection) {                   /* switch 3; irregular */
                case 0:                             /* switch 3 */
                    personaModel6 = (s32)((s32)((s32)(fclDrawGetResource((u8 *)(menuWork->f148)))));
                    shdPersonaSetChildDispCtlHandle((u8 *)personaModel6,  fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
                    fclDrawSetPlacementEx((u8 *)((*((s32 *)((u8 *)((u32)(menuWork) + (0x148U)))))), (s32)(((u16 *)yListSlotEntry(0, menuWork->f128))), 0, 0, 1);
                    return;
                case 1:                             /* switch 3 */
                    personaModel7 = (s32)((s32)((s32)(fclDrawGetResource((u8 *)(menuWork->f148)))));
                    shdPersonaSetChildDispCtlHandle((u8 *)personaModel7,  fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
                    fclDrawSetPlacementEx((u8 *)((*((s32 *)((u8 *)((u32)(menuWork) + (0x148U)))))), (s32)(((u16 *)yListSlotEntry(0, menuWork->f129))), 0, 0, 1);
                    return;
                case 2:                             /* switch 3 */
                    personaModel8 = (s32)((s32)((s32)(fclDrawGetResource((u8 *)(menuWork->f148)))));
                    shdPersonaSetChildDispCtlHandle((u8 *)personaModel8,  fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
                    fclDrawSetPlacementEx((u8 *)((*((s32 *)((u8 *)((u32)(menuWork) + (0x148U)))))), (s32)(((u16 *)yListSlotEntry(0, menuWork->f11E))), 0, 0, 1);
                    return;
                case 3:                             /* switch 3 */
                    personaModel9 = (s32)((s32)((s32)(fclDrawGetResource((u8 *)(menuWork->f148)))));
                    shdPersonaSetChildDispCtlHandle((u8 *)personaModel9,  fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
                    resultIndex9 = (u8)((u8)((u8)((*((u8 *)((u8 *)(((u16 *)yListSlotEntry(menuWork->f2F9, menuWork->f2FA))) + (4)))))));
                    if ((s32)((s32)((datCalcGetLevelById(1) & 0xFF))) < (s32)((s32)((s32) resultIndex9))) {
                        personaModel10 = (s32)((s32)((s32)(fclDrawGetResource((u8 *)(menuWork->f148)))));
                        shdPersonaSetChildDispCtlHandle((u8 *)personaModel10,  fclPackRgba(0x14, 0x14, 0x14, 0xFFU));
                    }
                    resultIndex3 = (s8)((s8)((s8)(menuWork->f2FA)));
                    personaRecord3 = (u16 *)(((u16 *)yListSlotEntry(menuWork->f2F9, (s64) resultIndex3)));
                    resultList6 = (u8 *)(yListSlotWork(menuWork->f2F9) + ((s8)(resultIndex3)));
                    community2 = (s64)((s64)((s16)cmmTopCommunityOfArcana(iGpffffb3d4[((u16 *)yListSlotEntry(menuWork->f2F9, menuWork->f2FA))[1] * 14 + 2])));
                    fclDrawSetPlacementEx((u8 *)(menuWork->f148), (s32)(personaRecord3), (((FclPartySlot *)(resultList6))->f2E4), cmmCommunityExpRemaining(community2, (u8 *)((u8 *)(((u16 *)yListSlotEntry(menuWork->f2F9, menuWork->f2FA)))), 0), 1);
                    return;
                }
            } else if (D_008C024E[0] & 4) {
                if (menuWork->f122 != 0) {
                    sdkSndStartStream(0, 2, 0, 5);
                }
                menuWork->f122 = (s8)((s8)(fclSubClamped(menuWork->f122, 1, 0, 3, 1)));
                s0 = fclSpriteEntry(0x152);
                position55 = fclMakeVec2((f32)((menuWork->f122 * 0x6B) + 0x6A), 16.0f);
                fclSpriteStartPositionAt(0x152, (((FclCombineRowSprite *)s0)->position), (*(FclVec2f *)&position55),  1,  4,  0);
                s0 = fclSpriteEntry(0x2E0);
                position56 = fclMakeVec2((f32)((menuWork->f122 * 0x6B) + 0x6A), 16.0f);
                fclSpriteStartPositionAt(0x2E0, (((FclCombineRowSprite *)s0)->position), (*(FclVec2f *)&position56),  1,  4,  0);
                previewSelection2 = (s8)((s8)((s8)(menuWork->f122)));
                switch (previewSelection2) {                 /* switch 4; irregular */
                case 0:                             /* switch 4 */
                    personaModel11 = (s32)((s32)((s32)(fclDrawGetResource((u8 *)(menuWork->f148)))));
                    shdPersonaSetChildDispCtlHandle((u8 *)personaModel11,  fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
                    fclDrawSetPlacementEx((u8 *)((*((s32 *)((u8 *)((u32)(menuWork) + (0x148U)))))), (s32)(((u16 *)yListSlotEntry(0, menuWork->f128))), 0, 0, 1);
                    return;
                case 1:                             /* switch 4 */
                    personaModel12 = (s32)((s32)((s32)(fclDrawGetResource((u8 *)(menuWork->f148)))));
                    shdPersonaSetChildDispCtlHandle((u8 *)personaModel12,  fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
                    fclDrawSetPlacementEx((u8 *)((*((s32 *)((u8 *)((u32)(menuWork) + (0x148U)))))), (s32)(((u16 *)yListSlotEntry(0, menuWork->f129))), 0, 0, 1);
                    return;
                case 2:                             /* switch 4 */
                    personaModel13 = (s32)((s32)((s32)(fclDrawGetResource((u8 *)(menuWork->f148)))));
                    shdPersonaSetChildDispCtlHandle((u8 *)personaModel13,  fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
                    fclDrawSetPlacementEx((u8 *)((*((s32 *)((u8 *)((u32)(menuWork) + (0x148U)))))), (s32)(((u16 *)yListSlotEntry(0, menuWork->f11E))), 0, 0, 1);
                    return;
                case 3:                             /* switch 4 */
                    personaModel14 = (s32)((s32)((s32)(fclDrawGetResource((u8 *)(menuWork->f148)))));
                    shdPersonaSetChildDispCtlHandle((u8 *)personaModel14,  fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
                    resultIndex10 = (u8)((u8)((u8)((*((u8 *)((u8 *)(((u16 *)yListSlotEntry(menuWork->f2F9, menuWork->f2FA))) + (4)))))));
                    if ((s32)((s32)((datCalcGetLevelById(1) & 0xFF))) < (s32)((s32)((s32) resultIndex10))) {
                        personaModel15 = (s32)((s32)((s32)(fclDrawGetResource((u8 *)(menuWork->f148)))));
                        shdPersonaSetChildDispCtlHandle((u8 *)personaModel15,  fclPackRgba(0x14, 0x14, 0x14, 0xFFU));
                    }
                    resultIndex4 = (s8)((s8)((s8)(menuWork->f2FA)));
                    personaRecord4 = (u16 *)(((u16 *)yListSlotEntry(menuWork->f2F9, (s64) resultIndex4)));
                    resultList7 = (u8 *)(yListSlotWork(menuWork->f2F9) + ((s8)(resultIndex4)));
                    community3 = (s64)((s64)((s16)cmmTopCommunityOfArcana(iGpffffb3d4[((u16 *)yListSlotEntry(menuWork->f2F9, menuWork->f2FA))[1] * 14 + 2])));
                    fclDrawSetPlacementEx((u8 *)(menuWork->f148), (s32)(personaRecord4), (((FclPartySlot *)(resultList7))->f2E4), cmmCommunityExpRemaining(community3, (u8 *)((u8 *)(((u16 *)yListSlotEntry(menuWork->f2F9, menuWork->f2FA)))), 0), 1);
                    return;
                }
            }
        }
        break;
    case 0x4E:                                      /* switch 1 */
        spriteAlpha7 = (u8)((u8)((u8)((*((u8 *)((u8 *)(fclSpriteEntry(0x7C)) + (0x6E)))))));
        /* measured: field typing changes 17240 normalized bytes in the full owner. */
        menuWork10 = *(FclCombineCtl **)(task + 0x38);
        sprite25 = (u8 *)(fclSpriteEntry(0x7C));
        position74 = ((FclCombineRowSprite *)sprite25)->position;
        textColor13 = (s32)((s32)(fclPackRgba(0xCC, 0xFF, 0xFF, spriteAlpha7)));
        frFontExDrawTextDeferredOutB(111.0f + position74.x, position74.y, 43.0f, textColor13, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, menuWork10->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        spriteAlpha8 = (*((u8 *)((u8 *)(fclSpriteEntry(0x7D)) + (0x6E))));
        /* measured: field typing changes 17241 normalized bytes in the full owner. */
        menuWork11 = *(FclCombineCtl **)(task + 0x38);
        sprite26 = (u8 *)(fclSpriteEntry(0x7D));
        position75 = ((FclCombineRowSprite *)sprite26)->position;
        textColor14 = (s32)((s32)(fclPackRgba(0xCC, 0xFF, 0xFF, spriteAlpha8)));
        frFontExDrawTextDeferredOutB(111.0f + position75.x, position75.y, 43.0f, textColor14, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, menuWork11->f129))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if (fclDrawGetState((u8 *)(menuWork->f148)) == (s32)(0xE)) {
            fclCombineLayoutFrame(task, 1, 0);
            fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            for (gridRow = 0; gridRow < (datPersonaRosterCapacity() & 0xFFFF); gridRow++) {

                position57 = fclMakeVec2(16.0f, 128.0f);

                fclCombinePartyRow(task, position57, (s8)gridRow, ((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, gridRow))) + (2))))), ((*((u8 *)((u8 *)(((u16 *)yListSlotEntry(0, gridRow))) + (4))))), 0, 0, ((s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count));
                secondSelection4 = (s8)((s8)((s8)(menuWork->f129)));
                if ((*((s8 *)((u8 *)((yListSlotWork((u32)secondSelection4 + 1U) + (secondSelection4 * 0xC) + gridRow)) + (0x14)))) > 0) {
                    position58 = fclMakeVec2((f32) 0x149, 128.0f);

                    fclCombineDrawPersonaRow(task, position58, (s64)menuWork->f129, gridRow, ((u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)yListSlotEntry((s8)((menuWork->f129 + 1)), gridRow))) + (2)))))))), ((*((u8 *)((u8 *)(((u16 *)yListSlotEntry((s8)((secondSelection4 + 1)), gridRow))) + (4))))), 0, 0, 1, 0xCC);
                }
            }
            position59 = fclMakeVec2(16.0f, 104.0f);
            fclCombineDrawSlotFields(task, position59, 0, 0, 0, 0, 0);
            position60 = fclMakeVec2((f32) 0x149, 104.0f);
            fclCombineDrawSlotLabels(task, position60, 0, 0);
            menuWork->f1 = 0x43U;
            return;
        }
        break;
    case 0x48:                                      /* switch 1 */
        resultIndex6 = (u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(menuWork->f2F9, menuWork->f2FA))) + (2)))))));
        resultIndex11 = (u8)((u8)((u8)((*((u8 *)((u8 *)(((u16 *)yListSlotEntry(menuWork->f2F9, menuWork->f2FA))) + (4)))))));
        if ((s32)((s32)((datCalcGetLevelById(1) & 0xFF))) < (s32)((s32)((s32) resultIndex11))) {
            fclCombinePlayCue(task, 0x26, 0);
            menuWork->f1 = 0x4AU;
            return;
        }
        if (yListSlotContainsId(0, (s32)(s16)((DatPersonaRecord *)yListSlotEntry(menuWork->f2F9, menuWork->f2FA))->id) == 1) {
            fclCombinePlayCue(task, 0x27, 0);
            menuWork->f1 = 0x4AU;
            return;
        }
        if ((s32)((s32)(((s8)(datGetPersonaArcanaCommunityValue(resultIndex6))))) == (s32)((s32)(0))) {
            fclCombinePlayResultCue(task, resultIndex6);
        } else {
            fclCombinePlayCue(task, (s8)((((s8)(datGetPersonaArcanaCommunityValue(resultIndex6))) + 0x2E)), 1);
        }
        menuWork->f1 = 0x49U;
        return;
    case 0x49:                                      /* switch 1 */
        if ((s32)((s32)(nmMesWindowSlotStatus((s8)(menuWork->fD)))) != (s32)((s32)(0))) {
            nmMesWindowStepSlotRelease((s8)(menuWork->fD));
            return;
        }
        if ((s32)((s32)(nmMesWindowGetSlotState(menuWork->fD))) == (s32)((s32)(0))) {
            menuWork->f1 = 0x4CU;
            fadeBeginTransition(1, 0xA);
        } else {
            menuWork->f1 = 0x46U;
        }
        nmMesWindowDestroySlot((s8)(menuWork->fD));
        return;
    case 0x4A:                                      /* switch 1 */
        if ((s32)((s32)(nmMesWindowSlotStatus((s8)(menuWork->fD)))) != (s32)((s32)(0))) {
            nmMesWindowStepSlotRelease((s8)(menuWork->fD));
            return;
        }
        nmMesWindowDestroySlot((s8)(menuWork->fD));
        menuWork->f1 = 0x46U;
        return;
    case 0x4C:                                      /* switch 1 */
        if ((s32)((s32)(fadeStatus())) != (s32)((s32)(0))) {
            fclDrawSetStateByte((u8 *)(menuWork->f148),  0xB);
            fclDrawResetScale((u8 *)(menuWork->f148));
            fclCombineDrawStageBanner(task, 4, 1);
            for (index2 = 0; index2 < 0x30C; index2++) {
                fclSpriteSetFlag(index2, 0, 1);
            }
            menuWork->f1 = 0x4BU;
            return;
        }
        break;
    case 0x4B:                                      /* switch 1 */
        if (fclDrawGetState((u8 *)(menuWork->f148)) == (s32)(0xE)) {
            menuWork->f1 = 0x4DU;
            return;
        }
        break;
    case 0x4D:                                      /* switch 1 */
        rareChanceKind = 3;
        if ((*((s8 *)((u8 *)((yListSlotWork(0) + (menuWork->f129 * 0xC) + menuWork->f11E)) + (0x14)))) == 2) {
            rareChanceKind = 0;
        }
        if ((s32)((s32)(datGetFlag(0x1461))) == (s32)((s32)(0))) {
            if ((s32)((s32)(fclRollRareChance(rareChanceKind))) == (s32)((s32)(1))) {
                if (RpRandom() % 1000U < 0x1F4U) {
                    menuWork->f1 = 0x4FU;
                    menuWork->fB2 = 1;
                    return;
                }
                menuWork->f1 = 0x50U;
                menuWork->fB2 = 2;
                return;
            }
            menuWork->fB2 = 0;
            menuWork->f0 = 0xD;
            menuWork->f1 = 0xC5U;
            return;
        }
        if (RpRandom() % 1000U < 0x1F4U) {
            menuWork->f1 = 0x4FU;
            menuWork->fB2 = 1;
            return;
        }
        menuWork->f1 = 0x50U;
        menuWork->fB2 = 2;
        return;
    case 0x4F:                                      /* switch 1 */
        memset(&excludedIds, 0, 0x1A);
        for (index = 0; index < (*((s32 *)((u8 *)(yListSlotWork(0)) + (8)))); index++) {
            excludedIds[index] = (u16)((u16)((u16) (*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, index))) + (2))))));
        }
        resultIndex7 = (u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)yListSlotEntry(menuWork->f2F9, menuWork->f2FA))) + (2)))))));
        excludedIds[(*((s32 *)((u8 *)(yListSlotWork(0)) + (8))))] = resultIndex7;
        yListSlotFillNearLevel(0xD, (u16 *)(excludedIds), (s8)(datCalcGetLevelById(1)));
        listWork = (*((u32 *)((u8 *)(yListSlotWork(0xD)) + (8))));
        randomValue = (u32)((u32)((RpRandom() % listWork) * 0xA));
        selectedResult = (s64)((s64)((s8)((randomValue % (u32) (*((u32 *)((u8 *)(yListSlotWork(0xD)) + (8))))))));
        menuWork->f2F9 = (s8)((s8)((s8) (menuWork->f129 + 1)));
        menuWork->f2FA = (s8)((s8)((s8) menuWork->f11E));
        for (skillIndex = 0; skillIndex < 8; skillIndex++) {

            if (((s32)((s32)(((s32) ((1 << skillIndex) & 0xFF & (*((s8 *)((u8 *)((yListSlotWork(menuWork->f2F9) + menuWork->f2FA)) + (0x2E4))))) >> skillIndex))) == (s32)((s32)(1))) && ((s32)((s32)(datPersonaCountSkills((u8 *)(yListSlotEntry(0xD, selectedResult))))) < (s32)((s32)(8)))) {
                secondSelection8 = (u16)((u16)((u16)((*((u16 *)((u8 *)((((u16 *)yListSlotEntry((s8)((menuWork->f129 + 1)), menuWork->f11E)) + skillIndex)) + (0xC)))))));
                if ((s32)((s32)(datPersonaFindSkillSlot((u8 *)(((u16 *)yListSlotEntry(0xD, selectedResult))),  secondSelection8))) == (s32)((s32)(-1))) {
                    datPersonaAddSkill((u8 *)(((u16 *)yListSlotEntry(0xD, selectedResult))),  secondSelection8);
                }
            }
        }
        menuWork->f2F9 = 0xD;
        menuWork->f2FA = (s8) selectedResult;
        resultIndex2 = menuWork->f2FA;
        fclDrawSetSlotMode((u8 *)(menuWork->f148), (s32)((u16 *)yListSlotEntry(menuWork->f2F9, resultIndex2)), (*((s8 *)((u8 *)((yListSlotWork(menuWork->f2F9) + ((s8)(resultIndex2)))) + (0x2E4)))));
        menuWork->f0 = 0xD;
        menuWork->f1 = 0xC5U;
        return;
    case 0x50:                                      /* switch 1 */
        {
            s16 level;
            s16 index3;
            u16 secondSelection9;
            s16 index4;
            s32 level2;
            level = 0x63;
            memset(&excludedIds2, 0, 0x1A);
            for (index3 = 0; index3 < (*((s32 *)((u8 *)(yListSlotWork(0)) + (8)))); index3++) {
                excludedIds2[index3] = (u16)((u16)((u16) (*((u16 *)((u8 *)(((u16 *)yListSlotEntry(0, index3))) + (2))))));
            }
            secondSelection9 = (u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)yListSlotEntry((s8)((menuWork->f129 + 1)), menuWork->f11E))) + (2)))))));
            excludedIds2[(*((s32 *)((u8 *)(yListSlotWork(0)) + (8))))] = secondSelection9;
            yListSlotFillByLevel(0xD, (u16 *)(excludedIds2), (s8)(datCalcGetLevelById(1)));
            if ((*((s32 *)((u8 *)(yListSlotWork(0xD)) + (8)))) == 0) {
                menuWork->f2F9 = (s8)((s8)((s8) (menuWork->f129 + 1)));
                menuWork->f2FA = (s8)((s8)((s8) menuWork->f11E));
                menuWork->f1 = 0x4FU;
                menuWork->fB2 = 1;
                return;
            }
            menuWork->f2F9 = 0xD;
            for (index4 = 0; index4 < ((FclCombinePersonaListHeader *)yListSlotWork(0xD))->count; index4++) {
                level2 = (*((u8 *)((u8 *)(((u16 *)yListSlotEntry(0xD, index4))) + (4))));
                if ((s32)((s32)((s32) level2)) >= (s32)((s32)((datCalcGetLevelById(1) & 0xFF)))) {
                    menuWork->f2FA = (s8) index4;
                    break;
                } else {
                    if ((s16)level > (s8)((datCalcGetLevelById(1) & 0xFF) - ((DatPersonaRecord *)yListSlotEntry(0xD, index4))->level)) {
                        level = (s8)((datCalcGetLevelById(1) & 0xFF) - ((DatPersonaRecord *)yListSlotEntry(0xD, index4))->level);
                        menuWork->f2FA = (s8) index4;
                    }

                }
            }
        }
        selectedResult = (s8)((s8)((s8)(menuWork->f2FA)));
        menuWork->f2F9 = (s8)((s8)((s8) (menuWork->f129 + 1)));
        for (skillIndex2 = 0; skillIndex2 < 8; skillIndex2++) {

            if (((s32)((s32)(((s32) ((1 << skillIndex2) & 0xFF & (*((s8 *)((u8 *)((yListSlotWork(menuWork->f2F9) + menuWork->f11E)) + (0x2E4))))) >> skillIndex2))) == (s32)((s32)(1))) && ((s32)((s32)(datPersonaCountSkills((u8 *)(yListSlotEntry(0xD, selectedResult))))) < (s32)((s32)(8)))) {
                resultList4 = (u16)((u16)((u16)((*((u16 *)((u8 *)((((u16 *)yListSlotEntry(menuWork->f2F9, menuWork->f11E)) + skillIndex2)) + (0xC)))))));
                if ((s32)((s32)(datPersonaFindSkillSlot((u8 *)(((u16 *)yListSlotEntry(0xD, selectedResult))),  resultList4))) == (s32)((s32)(-1))) {
                    datPersonaAddSkill((u8 *)(((u16 *)yListSlotEntry(0xD, selectedResult))),  resultList4);
                }
            }
        }
        menuWork->f2F9 = 0xD;
        resultIndex5 = (s8)((s8)((s8)(menuWork->f2FA)));
        fclDrawSetSlotMode((u8 *)(menuWork->f148), (s32)((u16 *)yListSlotEntry(0xD, resultIndex5)), (*((s8 *)((u8 *)((yListSlotWork(menuWork->f2F9) + ((s8)(resultIndex5)))) + (0x2E4)))));
        menuWork->f0 = 0xD;
        menuWork->f1 = 0xC5U;
        break;
    }

}
#pragma pop
#undef FCL0F00_GRID_ROW
/* measured: 12084 executable bytes / 12096-byte window, verify MATCH, 391 relocations.
   Rewritten from the retail assembly with opt_lifetimes (each loop and case keeps
   its own registers, as in retail).  00275820 takes its floats first; colour
   builders passed straight into 002ba5d0 keep retail's call order; the object ids
   reused inside the selected-row branch are locals computed before their first
   colour call; the row index is copied into its own local at each branch. */
/* The colour packers take byte channels through the shared interface: the
   alphas are u8 locals and retail passes them unmasked. func_00313ae0 is
   (s8 kind, u16 id) and widens the id once on entry. */
// Fcl combine menu material pick (states 3-5): picks the roster persona for material slot p[0x1A] (0-2), shows its detail with d-pad paging, and plays the cue; the 0x5C-0x5E path hands to the result handler (state 0x0D, sub-state 0xC5). Cancel returns to the menu root.
// FUN_002F6CF0
#pragma push
#pragma opt_lifetimes on
/* Historical whole-layout probe: 8417 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
void fclCombineMenuMaterialPick(u8 *task) {
    extern void fclCombineMaterialListBuild(s8);
    extern void fclCombineDrawSidePanels(u8 *, s32, s8);
    extern s32 fclCombineMaterialsHeld(s8, s8);
    extern s8 fclCombineItemSlot(s8, u16);
    extern s32 fclCombineSlotOwned(s8, s8);
    extern f32 D_00640E70[];
    FclDrawColor color0;
    FclDrawColor color1;
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
    FclPackedPosition rowPos;
    FclPackedPosition pos0;
    FclPackedPosition pos1;
    FclPackedPosition pos2;
    FclPackedPosition pos3;
    FclPackedPosition pos4;
    FclPackedPosition pos5;
    FclPackedPosition pos6;
    s8 *p;
    u8 *ps;
    u8 *te;
    FclVec2 *base;
    s16 i;
    s16 k;
    s16 m;
    u8 alpha;
    u8 alpha2;
    u8 alpha3;
    s32 rgba;
    s32 rgba2;
    s32 rgba3;
    s16 step2;
    s16 obj2;
    s32 stepInt2;
    s16 step;
    s32 stepInt;
    s16 obj;
    s8 slot;
    u16 id;
    s32 objA;
    s32 row;
    s32 objB;
    s32 objC;
    u16 item;
    u8 shade;
    u16 buttons;

    p = (s8*)((KwlnTask *)task)->work;
    switch ((u8)p[1]) {
    case 0x51:
        yListSlotCreate(0xA, 0);
        yListSlotCreate(0xA, 1);
        yListSlotCreate(0xA, 2);
        yListSlotCreate(0xA, 3);
        yListSlotCreate(0xA, 4);
        yListSlotCreate(0xA, 5);
        yListSlotCreate(0xA, 6);
        yListSlotCreate(0xA, 7);
        yListSlotCreate(0xA, 8);
        yListSlotCreate(0xA, 9);
        yListSlotCreate(0xA, 0xA);
        yListSlotCreate(0xA, 0xB);
        yListSlotCreate(0xA, 0xC);
        fclCombineLayoutDetailSprites(task, 1);
        fclCombineLayoutFrame(task, 0, 0);
        fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
        p[1] = 0x52;
        break;
    case 0x52:
        if (*(s8 *)yListSlotWork(0) == 0) {
            break;
        }
        if (fclCombineRowsBusy(task) == 1) {
            break;
        }
        p[0x129] = -1;
        p[0x128] = -1;
        ((FclCombineMenu *)p)->f11E = -1;
        for (i = 0; i < (u16)datPersonaRosterCapacity(); i++) {
            color0 = fclMakeDrawColor(0, 0, 0x99, 0xFF);
            ((FclCombineBallSlot *)fclCombineSlotRecord(((FclCombineMenu *)p)->ballTask.task, i))->color = color0;
        }
        fclCombineMaterialListBuild(p[0x1A]);
        fclCombineDrawSidePanels(task, 2, 0);
        base = (FclVec2 *)D_00640E70;
        pos0.position = fclMakeVec2(base->x, base->y);
        fclSpriteCreate(0xC8, pos0.position, 42.0f, 0x5A);
        fclSpriteStartAlphaAt(0xC8, 0xFF, 0, 0, 0xA, 0xA);
        pos1.position = fclMakeVec2((f32)0x28A + base->x, base->y);
        pos2.position = fclMakeVec2(base->x - 50.0f, base->y);
        fclSpriteStartPositionAt(0xC8, pos1.position, pos2.position, 0, 0x14, 0);
        fclCombineSlideInSlotSprites(task, 0x98, 0x96);
        /* measured: field typing changes 8145 normalized bytes in the full owner. */
        *(s16 *)(p + 0x11E) = 0;
        p[1] = 0x53;
        break;
    case 0x53:
        /* measured: field typing changes 6968 normalized bytes in the full owner. */
        for (i = 0; i < ((FclCombinePersonaListHeader *)yListSlotWork(*(s16 *)(p + 0x11E) + 1))->count; i++) {
            rowPos.position = fclMakeVec2((f32)0x139, 128.0f);
            rowPos.position.y += (f32)(i * 23);
            if (((s8 *)yListSlotWork(((FclCombineMenu *)p)->f11E + 1))[i + 0x14] == 0) {
                alpha = (u8)fclEaseInterpolate(0, 0.0f, 128.0f, ((FclCombineRowSprite *)fclSpriteEntry(i + 0x21C))->positionElapsed,
                                          ((FclCombineRowSprite *)fclSpriteEntry(i + 0x21C))->positionDuration);
            } else {
                alpha = (u8)fclEaseInterpolate(0, 0.0f, 255.0f, ((FclCombineRowSprite *)fclSpriteEntry(i + 0x21C))->positionElapsed,
                                          ((FclCombineRowSprite *)fclSpriteEntry(i + 0x21C))->positionDuration);
            }
            rgba = fclPackRgba(0xCC, 0xFF, 0xFF, alpha);
            frFontExDrawTextDeferredOutB((f32)0x19D, (f32)(i * 23 + 0x80), 43.0f, rgba, 0, 2,
                          /* measured: field typing changes 7781 normalized bytes in the full owner. */
                          (const char *)((u8 *)iGpffffb440 + ((u16 *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, i))[1] * 0x11),
                          0, 0, D_00795E60, 0x15);
            ((FclCombineRowSprite *)fclSpriteEntry(i + 0x250))->image =
                /* measured: field typing changes 7781 normalized bytes in the full owner. */
                (u8)datPersonaGetArcana(((u16 *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, i))[1]) + 0x1B;
            /* measured: field typing changes 7780 normalized bytes in the full owner. */
            if (((u8 *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, i))[4] == 0) {
                row = i;
                color1 = fclMakeDrawColor(0x24, 0x3F, 0x9F, 0xFF);
                ((FclCombineRowSprite *)fclSpriteEntry(row + 0x238))->color = color1;
                color2 = fclMakeDrawColor(0x24, 0x3F, 0x9F, 0xFF);
                ((FclCombineRowSprite *)fclSpriteEntry(row + 0x244))->color = color2;
                shade = 0x66;
                fclSpriteEntry(i + 0x21C)[0x6E] = shade;
                fclSpriteEntry(row + 0x22B)[0x6E] = shade;
                nmMesWindowSetNumber(((FclCombineMenu *)p)->f2BC, (s8)i, 0, rowPos.position, color3 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, alpha), 46.0f, 0x59);
            } else {
                row = i;
                color4 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                ((FclCombineRowSprite *)fclSpriteEntry(row + 0x238))->color = color4;
                color5 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                ((FclCombineRowSprite *)fclSpriteEntry(row + 0x244))->color = color5;
                shade = 0xCC;
                fclSpriteEntry(i + 0x21C)[0x6E] = shade;
                fclSpriteEntry(row + 0x22B)[0x6E] = shade;
                /* measured: field typing changes 7780 normalized bytes in the full owner. */
                nmMesWindowSetNumber(((FclCombineMenu *)p)->f2BC, (s8)i, ((u8 *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, i))[4],
                              rowPos.position, color6 = fclMakeDrawColor(shade, 0xFF, 0xFF, alpha), 46.0f, 0x59);
            }
        }
        for (k = 0; k < ((FclCombinePersonaListHeader *)yListSlotWork(0))->count; k++) {
            alpha2 = (u8)fclEaseInterpolate(0, 0.0f, 255.0f, ((FclCombineRowSprite *)fclSpriteEntry(k + 0x270))->positionElapsed,
                                       ((FclCombineRowSprite *)fclSpriteEntry(k + 0x270))->positionDuration);
            if (((FclCombineMenu *)p)->f11E == k) {
                color7 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, alpha2);
                nmMesWindowSetNumberColor((u8 *)((FclCombineMenu *)p)->f2BC, (s8)(k + 0xC), *(FclDrawColor *)&color7);
            } else if (fclCombineMaterialsHeld(p[0x1A], (s8)k) == 1) {
                color8 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, alpha2);
                nmMesWindowSetNumberColor((u8 *)((FclCombineMenu *)p)->f2BC, (s8)(k + 0xC), *(FclDrawColor *)&color8);
            } else {
                alpha2 = (u8)fclEaseInterpolate(0, 0.0f, 128.0f, ((FclCombineRowSprite *)fclSpriteEntry(k + 0x270))->positionElapsed,
                                           ((FclCombineRowSprite *)fclSpriteEntry(k + 0x270))->positionDuration);
                color9 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, alpha2);
                nmMesWindowSetNumberColor((u8 *)((FclCombineMenu *)p)->f2BC, (s8)(k + 0xC), *(FclDrawColor *)&color9);
            }
            rgba2 = fclPackRgba(0xCC, 0xFF, 0xFF, alpha2);
            /* measured: field typing changes 6652 normalized bytes in the full owner. */
            if (*(s16 *)(p + 0x11E) == k) {
                rgba2 = fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF);
            }
            frFontExDrawTextDeferredOutB(97.0f, (f32)(k * 23 + 0x80), 43.0f, rgba2, 0, 2,
                          (const char *)((u8 *)iGpffffb440 + ((u16 *)yListSlotEntry(0, k))[1] * 0x11),
                          0, 0, D_00795E60, 0x15);
            fclSpriteEntry(k + 0x270)[0x6E] = fclSpriteEntry(k + 0x27D)[0x6E] = 0x97;
            color10 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
            te = fclSpriteEntry(k + 0x27D);
            ((FclCombineRowSprite *)te)->color = color10;
            /* measured: field typing changes 8 normalized bytes in the full owner. */
            ((FclCombineRowSprite *)fclSpriteEntry(k + 0x270))->color = *(FclDrawColor *)(te + 0x85);
            objA = k + 0x297;
            objB = k + 0x28B;
            color11 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
            te = fclSpriteEntry(objA);
            ((FclCombineRowSprite *)te)->color = color11;
            /* measured: field typing changes 8 normalized bytes in the full owner. */
            ((FclCombineRowSprite *)fclSpriteEntry(objB))->color = *(FclDrawColor *)(te + 0x85);
            objC = k + 0x2A3;
            color12 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(objC))->color = color12;
            /* measured: field typing changes 6652 normalized bytes in the full owner. */
            if (*(s16 *)(p + 0x11E) == k) {
                fclSpriteEntry(k + 0x270)[0x6E] = fclSpriteEntry(k + 0x27D)[0x6E] = 0xFF;
                color13 = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
                ps = fclSpriteEntry(objA);
                ((FclCombineRowSprite *)ps)->color = color13;
                te = fclSpriteEntry(objB);
                /* measured: field typing changes 8 normalized bytes in the full owner. */
                ((FclCombineRowSprite *)te)->color = *(FclDrawColor *)(ps + 0x85);
                ps = fclSpriteEntry(k + 0x27D);
                /* measured: field typing changes 8 normalized bytes in the full owner. */
                ((FclCombineRowSprite *)ps)->color = *(FclDrawColor *)(te + 0x85);
                /* measured: field typing changes 8 normalized bytes in the full owner. */
                ((FclCombineRowSprite *)fclSpriteEntry(k + 0x270))->color = *(FclDrawColor *)(ps + 0x85);
                color14 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                ((FclCombineRowSprite *)fclSpriteEntry(objC))->color = color14;
            }
        }
        for (m = 0; m < ((FclCombinePersonaListHeader *)yListSlotWork(1))->count; m++) {
            if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(m + 0x21C))->flags, 1) == 1) {
                return;
            }
        }
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0xC8))->flags, 1) == 1) {
            return;
        }
        buttons = D_008C027A[0];
        if (buttons & 0x1000) {
            sdkSndStartStream(0, 0, 0, 0);
            /* measured: field typing changes 5528 normalized bytes in the full owner. */
            ((FclCombineMenu *)p)->f11E = fclSubClamped(*(s16 *)(p + 0x11E), 1, 0, (s16)(((FclCombinePersonaListHeader *)yListSlotWork(0))->count - 1), 2);
            break;
        }
        if (buttons & 0x4000) {
            sdkSndStartStream(0, 0, 0, 0);
            /* measured: field typing changes 5461 normalized bytes in the full owner. */
            ((FclCombineMenu *)p)->f11E = fclAddClamped(*(s16 *)(p + 0x11E), 1, (s16)(((FclCombinePersonaListHeader *)yListSlotWork(0))->count - 1), 0, 2);
            break;
        }
        buttons = D_008C024E[0];
        if (buttons & 0x40) {
            if (fclCombineMaterialsHeld(p[0x1A], (s8)((FclCombineMenu *)p)->f11E) == 1) {
                sdkSndStartStream(0, 0, 0, 1);
                p[0x2FA] = ((FclCombineMenu *)p)->f11E;
                ((FclCombineMenu *)p)->f11E = -1;
                fclCombineDrawSidePanels(task, 0, 1);
                fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                fclCombineFadePanelSprite(task, 0, 0.0f);
                /* measured: field typing changes 5370 normalized bytes in the full owner. */
                *(s16 *)(p + 0x11E) = p[0x2FA];
                p[1] = 0x58;
                fclSpriteSetHidden(((FclCombineMenu *)p)->headerTask.task, 1);
                fclSpriteSetHidden(((FclCombineMenu *)p)->arrowTask.task, 1);
            } else {
                sdkSndStartStream(0, 0, 0, 8);
            }
        } else if (buttons & 0x20) {
            sdkSndStartStream(0, 0, 0, 2);
            p[0x2FA] = ((FclCombineMenu *)p)->f11E;
            ((FclCombineMenu *)p)->f11E = -1;
            fclCombineDrawSidePanels(task, 0, 1);
            /* measured: field typing changes 5220 normalized bytes in the full owner. */
            *(s16 *)(p + 0x11E) = p[0x2FA];
            fclCombineLayoutFrame(task, 0, 1);
            fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
            fclCombineSlideInSlotSprites(task, 0x96, 0x98);
            p[1] = 0x56;
        } else if (buttons & 0x80) {
            sdkSndStartStream(0, 1, 0, 3);
            p[0x2FA] = ((FclCombineMenu *)p)->f11E;
            ((FclCombineMenu *)p)->f11E = -1;
            fclCombineDrawSidePanels(task, 0, 1);
            fclCombineFadeLabelSprites(task, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
            fclCombineFadePanelSprite(task, 0, 60.0f);
            fclSpriteSetHidden(((FclCombineMenu *)p)->headerTask.task, 1);
            fclSpriteSetHidden(((FclCombineMenu *)p)->arrowTask.task, 1);
            p[1] = 0x54;
        }
        break;
    case 0x54:
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x21C))->flags, 1) == 1) {
            break;
        }
        id = ((u16 *)yListSlotEntry(0, p[0x2FA]))[1];
        datPersonaInitRecord((u8 *)yListSlotEntry(0, p[0x2FA]), id);
        fclDrawSetPlacement(((FclCombineMenu *)p)->drawTask.task, (s32)yListSlotEntry(0, p[0x2FA]), 0, 0);
        /* measured: field typing changes 4915 normalized bytes in the full owner. */
        shdPersonaEndSelection(fclDrawGetResource(*(u8 **)(p + 0x148)), 1);
        /* measured: field typing changes 4915 normalized bytes in the full owner. */
        shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
        if (((u8 *)yListSlotEntry(0, p[0x2FA]))[4] > (u8)datCalcGetLevelById(1)) {
            /* measured: field typing changes 4915 normalized bytes in the full owner. */
            shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0x14, 0x14, 0x14, 0xFF));
        }
        p[1] = 0x55;
        break;
    case 0x55:
        if (fclDrawGetState(((FclCombineMenu *)p)->drawTask.task) == 5) {
            /* measured: field typing changes 4746 normalized bytes in the full owner. */
            if (shdPersonaIsSelectionActive(fclDrawGetResource(*(u8 **)(p + 0x148))) == 1) {
                /* measured: field typing changes 4746 normalized bytes in the full owner. */
                shdPersonaStepSelectionCursor(fclDrawGetResource(*(u8 **)(p + 0x148)));
            }
            buttons = D_008C024E[0];
            if (buttons & 0x80) {
                /* measured: field typing changes 4746 normalized bytes in the full owner. */
                if (shdPersonaIsSelectionActive(fclDrawGetResource(*(u8 **)(p + 0x148))) == 0) {
                    /* measured: field typing changes 4746 normalized bytes in the full owner. */
                    shdPersonaBeginSelection(fclDrawGetResource(*(u8 **)(p + 0x148)));
                    /* measured: field typing changes 4746 normalized bytes in the full owner. */
                    fclDrawSetFlag(*(u8 **)(p + 0x148), 0);
                } else {
                    /* measured: field typing changes 4746 normalized bytes in the full owner. */
                    shdPersonaEndSelection(fclDrawGetResource(*(u8 **)(p + 0x148)), 1);
                    /* measured: field typing changes 4745 normalized bytes in the full owner. */
                    fclDrawSetFlag(*(u8 **)(p + 0x148), 1);
                }
            } else if (buttons & 0x20) {
                /* measured: field typing changes 4746 normalized bytes in the full owner. */
                if (shdPersonaIsSelectionActive(fclDrawGetResource(*(u8 **)(p + 0x148))) == 1) {
                    /* measured: field typing changes 4746 normalized bytes in the full owner. */
                    shdPersonaEndSelection(fclDrawGetResource(*(u8 **)(p + 0x148)), 1);
                    /* measured: field typing changes 4745 normalized bytes in the full owner. */
                    fclDrawSetFlag(*(u8 **)(p + 0x148), 1);
                } else {
                    /* measured: field typing changes 4746 normalized bytes in the full owner. */
                    if (fclDrawGetState(*(u8 **)(p + 0x148)) != 5) {
                        break;
                    }
                    sdkSndStartStream(0, 1, 0, 4);
                    /* measured: field typing changes 4745 normalized bytes in the full owner. */
                    fclDrawSetStateByte(*(u8 **)(p + 0x148), 3);
                    if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x1E4))->flags, 0) == 1) {
                        fclSpriteStartAlphaAt(0x1E4, fclSpriteEntry(0x1E4)[0x6E], 0, 0, 0xA, 0);
                    }
                }
            }
        }
        /* measured: field typing changes 4746 normalized bytes in the full owner. */
        if (fclDrawGetState(*(u8 **)(p + 0x148)) < 0 || fclDrawGetState(*(u8 **)(p + 0x148)) > 5) {
            fclCombineDrawSidePanels(task, 0, 0);
            fclCombineFadeLabelSprites(task, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            ((FclCombineMenu *)p)->f11E = p[0x2FA];
            p[1] = 0x53;
            fclSpriteSetHidden(((FclCombineMenu *)p)->headerTask.task, 0);
            fclSpriteSetHidden(((FclCombineMenu *)p)->arrowTask.task, 0);
        }
        break;
    case 0x56:
        for (i = 0; i < ((FclCombinePersonaListHeader *)yListSlotWork(1))->count; i++) {
            if (((s8 *)yListSlotWork(((FclCombineMenu *)p)->f11E + 1))[i + 0x14] == 0) {
                alpha3 = (u8)fclEaseInterpolate(0, 128.0f, 0.0f, ((FclCombineRowSprite *)fclSpriteEntry(i + 0x21C))->positionElapsed,
                                           ((FclCombineRowSprite *)fclSpriteEntry(i + 0x21C))->positionDuration);
            } else {
                alpha3 = (u8)fclEaseInterpolate(0, 255.0f, 0.0f, ((FclCombineRowSprite *)fclSpriteEntry(i + 0x21C))->positionElapsed,
                                           ((FclCombineRowSprite *)fclSpriteEntry(i + 0x21C))->positionDuration);
            }
            rgba3 = fclPackRgba(0xCC, 0xFF, 0xFF, alpha3);
            frFontExDrawTextDeferredOutB((f32)0x19D, (f32)(i * 23 + 0x80), 43.0f, rgba3, 0, 2,
                          /* measured: field typing changes 4265 normalized bytes in the full owner. */
                          (const char *)((u8 *)iGpffffb440 + ((u16 *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, i))[1] * 0x11),
                          0, 0, D_00795E60, 0x15);
        }
        for (k = 0; k < ((FclCombinePersonaListHeader *)yListSlotWork(0))->count; k++) {
            if (fclCombineMaterialsHeld(p[0x1A], (s8)k) == 1) {
                alpha3 = (u8)fclEaseInterpolate(0, 255.0f, 0.0f, ((FclCombineRowSprite *)fclSpriteEntry(k + 0x270))->positionElapsed,
                                           ((FclCombineRowSprite *)fclSpriteEntry(k + 0x270))->positionDuration);
            } else {
                alpha3 = (u8)fclEaseInterpolate(0, 128.0f, 0.0f, ((FclCombineRowSprite *)fclSpriteEntry(k + 0x270))->positionElapsed,
                                           ((FclCombineRowSprite *)fclSpriteEntry(k + 0x270))->positionDuration);
            }
            rgba3 = fclPackRgba(0xCC, 0xFF, 0xFF, alpha3);
            if (((FclCombineMenu *)p)->f11E == k) {
                alpha3 = (u8)fclEaseInterpolate(0, 255.0f, 0.0f, ((FclCombineRowSprite *)fclSpriteEntry(k + 0x270))->positionElapsed,
                                           ((FclCombineRowSprite *)fclSpriteEntry(k + 0x270))->positionDuration);
                rgba3 = fclPackRgba(0x2D, 0x2D, 0x2D, alpha3);
            }
            frFontExDrawTextDeferredOutB(97.0f, (f32)(k * 23 + 0x80), 43.0f, rgba3, 0, 2,
                          (const char *)((u8 *)iGpffffb440 + ((u16 *)yListSlotEntry(0, k))[1] * 0x11),
                          0, 0, D_00795E60, 0x15);
        }
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x2B4))->flags, 1) != 0) {
            break;
        }
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x27C))->flags, 1) != 0) {
            break;
        }
        fclCombineLayoutTransition(task, 0);
        fclCombineLayoutDetailSprites(task, 0);
        p[1] = 0x1A;
        p[0] = 0;
        ((FclCombineMenu *)p)->f11E = -1;
        break;
    case 0x58:
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x21C))->flags, 1) == 1) {
            break;
        }
        p[0x2F9] = 0;
        if (fclCombineMaterialsHeld(p[0x1A], p[0x2FA]) == 1) {
            slot = p[0x2FA];
            fclCombineFuseSourceRecords((u16 *)yListSlotEntry(0, slot), (u8 *)yListSlotEntry(p[0x2FA] + 1, 0),
                                        (u8 *)yListSlotEntry(p[0x2FA] + 1, 1), (u8 *)yListSlotEntry(p[0x2FA] + 1, 2),
                                        (u8 *)yListSlotEntry(p[0x2FA] + 1, 3), (u8 *)yListSlotEntry(p[0x2FA] + 1, 4),
                                        (u8 *)yListSlotEntry(slot + 1, 5), p[0x1A], 0, slot);
        }
        fclDrawSetPlacementEx(((FclCombineMenu *)p)->drawTask.task, (s32)yListSlotEntry(p[0x2F9], p[0x2FA]), ((s8 *)yListSlotWork(p[0x2F9]))[p[0x2FA] + 0x2E4], cmmCommunityExpRemaining(cmmTopCommunityOfArcana(iGpffffb3d4[((u16 *)yListSlotEntry(p[0x2F9], p[0x2FA]))[1] * 14 + 2]),
                      (u8 *)yListSlotEntry(p[0x2F9], p[0x2FA]), 0), 1);
        /* measured: field typing changes 2868 normalized bytes in the full owner. */
        shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
        if (((u8 *)yListSlotEntry(p[0x2F9], p[0x2FA]))[4] > (u8)datCalcGetLevelById(1)) {
            /* measured: field typing changes 2868 normalized bytes in the full owner. */
            shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0x14, 0x14, 0x14, 0xFF));
        }
        /* measured: field typing changes 2868 normalized bytes in the full owner. */
        shdPersonaEndSelection(fclDrawGetResource(*(u8 **)(p + 0x148)), 1);
        fclCombineDrawStageBanner(task, (s8)(p[0x1A] + 1), 0);
        p[1] = 0x57;
        break;
    case 0x57:
        if (fclDrawGetState(((FclCombineMenu *)p)->drawTask.task) != 0xD) {
            break;
        }
        /* measured: field typing changes 2586 normalized bytes in the full owner. */
        if (shdPersonaIsSelectionActive(fclDrawGetResource(*(u8 **)(p + 0x148))) == 1) {
            /* measured: field typing changes 2586 normalized bytes in the full owner. */
            shdPersonaStepSelectionCursor(fclDrawGetResource(*(u8 **)(p + 0x148)));
        }
        buttons = D_008C024E[0];
        if (buttons & 0x40) {
            p[1] = 0x59;
            sdkSndStartStream(0, 0, 0, 1);
        } else if (buttons & 0x20) {
            /* measured: field typing changes 2586 normalized bytes in the full owner. */
            if (shdPersonaIsSelectionActive(fclDrawGetResource(*(u8 **)(p + 0x148))) == 1) {
                /* measured: field typing changes 2586 normalized bytes in the full owner. */
                shdPersonaEndSelection(fclDrawGetResource(*(u8 **)(p + 0x148)), 1);
                /* measured: field typing changes 2585 normalized bytes in the full owner. */
                fclDrawSetFlag(*(u8 **)(p + 0x148), 1);
            } else {
                p[1] = 0x5F;
                /* measured: field typing changes 2585 normalized bytes in the full owner. */
                fclDrawSetStateByte(*(u8 **)(p + 0x148), 0xB);
                fclCombineDrawStageBanner(task, (s8)(p[0x1A] + 1), 1);
                fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                fclCombineFadePanelSprite(task, 1, 0.0f);
                sdkSndStartStream(0, 0, 0, 2);
            }
        } else if (buttons & 0x80) {
            /* measured: field typing changes 2586 normalized bytes in the full owner. */
            if (shdPersonaIsSelectionActive(fclDrawGetResource(*(u8 **)(p + 0x148))) == 0) {
                /* measured: field typing changes 2586 normalized bytes in the full owner. */
                shdPersonaBeginSelection(fclDrawGetResource(*(u8 **)(p + 0x148)));
                /* measured: field typing changes 2586 normalized bytes in the full owner. */
                fclDrawSetFlag(*(u8 **)(p + 0x148), 0);
            } else {
                /* measured: field typing changes 2586 normalized bytes in the full owner. */
                shdPersonaEndSelection(fclDrawGetResource(*(u8 **)(p + 0x148)), 1);
                /* measured: field typing changes 2585 normalized bytes in the full owner. */
                fclDrawSetFlag(*(u8 **)(p + 0x148), 1);
            }
        } else if (buttons & 8) {
            if (p[0x122] != ((FclCombinePersonaListHeader *)yListSlotWork(((FclCombineMenu *)p)->f11E + 1))->count) {
                sdkSndStartStream(0, 2, 0, 5);
            }
            /* measured: field typing changes 2212 normalized bytes in the full owner. */
            p[0x122] = fclAddClamped(p[0x122], 1, ((FclCombinePersonaListHeader *)yListSlotWork(*(s16 *)(p + 0x11E) + 1))->count, 0, 1);
            switch (p[0x1A] + 1) {
            case 5:
                step = 0x55;
                obj = 0x153;
                break;
            case 6:
                step = 0x47;
                obj = 0x154;
                break;
            case 7:
                step = 0x3D;
                obj = 0x155;
                break;
            }
            stepInt = step;
            ps = fclSpriteEntry(obj);
            pos3.position = fclMakeVec2((f32)(stepInt * p[0x122] + 0x6A), 16.0f);
            fclSpriteStartPositionAt(obj, ((FclCombineRowSprite *)ps)->position, pos3.position, 1, 4, 0);
            ps = fclSpriteEntry(0x2E0);
            pos4.position = fclMakeVec2((f32)(stepInt * p[0x122] + 0x6A), 16.0f);
            fclSpriteStartPositionAt(0x2E0, ((FclCombineRowSprite *)ps)->position, pos4.position, 1, 4, 0);
            if (p[0x122] < p[0x1A]) {
                /* measured: field typing changes 2585 normalized bytes in the full owner. */
                shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
                /* measured: field typing changes 2585 normalized bytes in the full owner. */
                fclDrawSetPlacementEx(*(u8 **)(p + 0x148), (s32)yListSlotEntry(p[0x2FA] + 1, p[0x122]), 0, 0, 1);
            } else {
                /* measured: field typing changes 2585 normalized bytes in the full owner. */
                shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
                if (((u8 *)yListSlotEntry(p[0x2F9], p[0x2FA]))[4] > (u8)datCalcGetLevelById(1)) {
                    /* measured: field typing changes 2585 normalized bytes in the full owner. */
                    shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0x14, 0x14, 0x14, 0xFF));
                }
                /* measured: field typing changes 2586 normalized bytes in the full owner. */
                fclDrawSetPlacementEx(*(u8 **)(p + 0x148), (s32)yListSlotEntry(p[0x2F9], p[0x2FA]), ((s8 *)yListSlotWork(p[0x2F9]))[p[0x2FA] + 0x2E4], cmmCommunityExpRemaining(cmmTopCommunityOfArcana(iGpffffb3d4[((u16 *)yListSlotEntry(p[0x2F9], p[0x2FA]))[1] * 14 + 2]),
                              (u8 *)yListSlotEntry(p[0x2F9], p[0x2FA]), 0), 1);
            }
        } else if (buttons & 4) {
            if (p[0x122] != 0) {
                sdkSndStartStream(0, 2, 0, 5);
            }
            p[0x122] = fclSubClamped(p[0x122], 1, 0, ((FclCombinePersonaListHeader *)yListSlotWork(((FclCombineMenu *)p)->f11E + 1))->count, 1);
            switch (p[0x1A] + 1) {
            case 5:
                step2 = 0x55;
                obj2 = 0x153;
                break;
            case 6:
                step2 = 0x47;
                obj2 = 0x154;
                break;
            case 7:
                step2 = 0x3D;
                obj2 = 0x155;
                break;
            }
            stepInt2 = step2;
            ps = fclSpriteEntry(obj2);
            pos5.position = fclMakeVec2((f32)(stepInt2 * p[0x122] + 0x6A), 16.0f);
            fclSpriteStartPositionAt(obj2, ((FclCombineRowSprite *)ps)->position, pos5.position, 1, 4, 0);
            ps = fclSpriteEntry(0x2E0);
            pos6.position = fclMakeVec2((f32)(stepInt2 * p[0x122] + 0x6A), 16.0f);
            fclSpriteStartPositionAt(0x2E0, ((FclCombineRowSprite *)ps)->position, pos6.position, 1, 4, 0);
            if (p[0x122] < p[0x1A]) {
                /* measured: field typing changes 2590 normalized bytes in the full owner. */
                shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
                /* measured: field typing changes 2590 normalized bytes in the full owner. */
                fclDrawSetPlacementEx(*(u8 **)(p + 0x148), (s32)yListSlotEntry(p[0x2FA] + 1, p[0x122]), 0, 0, 1);
            } else {
                /* measured: field typing changes 2590 normalized bytes in the full owner. */
                shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
                if (((u8 *)yListSlotEntry(p[0x2F9], p[0x2FA]))[4] > (u8)datCalcGetLevelById(1)) {
                    /* measured: field typing changes 2590 normalized bytes in the full owner. */
                    shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0x14, 0x14, 0x14, 0xFF));
                }
                /* measured: field typing changes 2591 normalized bytes in the full owner. */
                fclDrawSetPlacementEx(*(u8 **)(p + 0x148), (s32)yListSlotEntry(p[0x2F9], p[0x2FA]), ((s8 *)yListSlotWork(p[0x2F9]))[p[0x2FA] + 0x2E4], cmmCommunityExpRemaining(cmmTopCommunityOfArcana(iGpffffb3d4[((u16 *)yListSlotEntry(p[0x2F9], p[0x2FA]))[1] * 14 + 2]),
                              (u8 *)yListSlotEntry(p[0x2F9], p[0x2FA]), 0), 1);
            }
        }
        break;
    case 0x5F:
        if (fclDrawGetState(((FclCombineMenu *)p)->drawTask.task) != 0xE) {
            break;
        }
        ((FclCombineMenu *)p)->f11E = -1;
        fclCombineDrawSidePanels(task, 0, 0);
        /* measured: field typing changes 908 normalized bytes in the full owner. */
        *(s16 *)(p + 0x11E) = p[0x2FA];
        fclSpriteSetHidden(((FclCombineMenu *)p)->headerTask.task, 0);
        fclSpriteSetHidden(((FclCombineMenu *)p)->arrowTask.task, 0);
        p[1] = 0x53;
        break;
    case 0x59:
        item = ((u16 *)yListSlotEntry(p[0x2F9], p[0x2FA]))[1];
        if (((u8 *)yListSlotEntry(p[0x2F9], p[0x2FA]))[4] > (u8)datCalcGetLevelById(1)) {
            fclCombinePlayCue(task, 0x26, 0);
            p[1] = 0x5B;
            break;
        }
        if (fclCombineSlotOwned(p[0x1A], fclCombineItemSlot(p[0x1A], item)) == 1) {
            fclCombinePlayCue(task, 0x27, 0);
            p[1] = 0x5B;
            break;
        }
        if (datGetPersonaArcanaCommunityValue(item) == 0) {
            fclCombinePlayResultCue(task, item);
        } else {
            fclCombinePlayCue(task, (s8)(datGetPersonaArcanaCommunityValue(item) + 0x2E), 1);
        }
        p[1] = 0x5A;
        break;
    case 0x5A:
        if (nmMesWindowSlotStatus(p[0xD]) != 0) {
            nmMesWindowStepSlotRelease(p[0xD]);
            break;
        }
        if (nmMesWindowGetSlotState(p[0xD]) == 0) {
            p[1] = 0x5D;
            fadeBeginTransition(1, 0xA);
        } else {
            p[1] = 0x57;
        }
        nmMesWindowDestroySlot(p[0xD]);
        break;
    case 0x5B:
        if (nmMesWindowSlotStatus(p[0xD]) != 0) {
            nmMesWindowStepSlotRelease(p[0xD]);
            break;
        }
        nmMesWindowDestroySlot(p[0xD]);
        p[1] = 0x57;
        break;
    case 0x5D:
        if (fadeStatus() != 0) {
            fclDrawSetStateByte(((FclCombineMenu *)p)->drawTask.task, 0xB);
            /* measured: field typing changes 524 normalized bytes in the full owner. */
            fclDrawResetScale(*(u8 **)(p + 0x148));
            fclCombineDrawStageBanner(task, (s8)(p[0x1A] + 1), 1);
            for (i = 0; i < 0x30C; i++) {
                fclSpriteSetFlag(i, 0, 1);
            }
            p[1] = 0x5C;
        }
        break;
    case 0x5C:
        if (fclDrawGetState(((FclCombineMenu *)p)->drawTask.task) == 0xE) {
            p[1] = 0x5E;
            switch (((u16 *)yListSlotEntry(p[0x2F9], p[0x2FA]))[1]) {
            case 0x17:
                datSetFlag(0x130E, 1);
                break;
            case 0x57:
                datSetFlag(0x130F, 1);
                break;
            case 0x93:
                datSetFlag(0x1310, 1);
                break;
            case 0xB9:
                datSetFlag(0x1311, 1);
                break;
            case 0x52:
                datSetFlag(0x1312, 1);
                break;
            case 0x77:
                datSetFlag(0x1313, 1);
                break;
            case 0x26:
                datSetFlag(0x1314, 1);
                break;
            case 0x14:
                datSetFlag(0x1315, 1);
                break;
            case 0x53:
                datSetFlag(0x1316, 1);
                break;
            case 0x68:
                datSetFlag(0x1317, 1);
                break;
            case 0x90:
                datSetFlag(0x1318, 1);
                break;
            case 0xA6:
                datSetFlag(0x1319, 1);
                break;
            }
        }
        break;
    case 0x5E:
        p[0xB2] = 0;
        p[0] = 0xD;
        ((u8 *)p)[1] = 0xC5;
        break;
    case 0x60:
    case 0x61:
    case 0x62:
        break;
    }
}
#pragma pop

/* Copy sourceCount records (0x30 bytes each), initialize resultRecord by ID,
   and store the fusion inheritance mask in listSlot's entryIndex at +0x2E4. */
// FUN_002F9C30
void fclCombineFuseSourceRecords(u16 *resultRecord, u8 *firstSource, u8 *secondSource, u8 *thirdSource, u8 *fourthSource, u8 *fifthSource, u8 *sixthSource, s32 sourceCount, s8 listSlot, s8 entryIndex) {
    u16 buf[6 * 24];
    s8 v;

    switch ((s16)sourceCount) {
    case 0:
        break;
    case 6:
        memcpy(buf + 5 * 24, sixthSource, 0x30);
        /* fallthrough */
    case 5:
        memcpy(buf + 4 * 24, fifthSource, 0x30);
        /* fallthrough */
    case 4:
        memcpy(buf + 3 * 24, fourthSource, 0x30);
        /* fallthrough */
    case 3:
        memcpy(buf + 2 * 24, thirdSource, 0x30);
        /* fallthrough */
    case 2:
        memcpy(buf + 1 * 24, secondSource, 0x30);
        /* fallthrough */
    case 1:
        memcpy(buf, firstSource, 0x30);
        break;
    }
    datPersonaInitRecord((u8 *)resultRecord, resultRecord[1]);
    v = (s8)fclFuseRollPersona(resultRecord, (u8 *)buf, (s8)sourceCount);
    *(yListSlotWork(listSlot) + entryIndex + 0x2E4) = v;
}

/* measured: 8460 executable bytes / 8464-byte window, verify MATCH, 298 relocations.
   Rewritten from the retail assembly: 00275820 takes its three floats first
   (frFontEx prototype), so the row y is an inline argument; each alpha and colour
   is its own int local (retail gives them distinct registers and passes them to
   002b2a30 unmasked), the 0x68 roster loop uses its own index, and the state
   range checks are written `> 5` / `> 0xD`. */
// Fcl combine menu preview (state 6): browses the roster, previews the selected persona in the draw, then returns to the menu root (sub-state 0x1A) or hands to the result handler (state 0x0D, sub-state 0xC5).
// FUN_002F9D90
/* Historical whole-layout probe: 5870 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
void fclCombineMenuPreview(u8 *task) {
    extern void yListSlotAppend(s8, s32, s8);
    extern void fclCombineDrawPairLayout(u8 *, s32, s8);
    extern void shdPersonaSetChildDispCtlHandle(u8 *, s32); /* retail loads the colour into $a1 */
    extern s16 yListStepIndex(s16, s16, s16, s16, s16);
    extern f32 D_00640E70[];
    FclDrawColor slotColor;
    FclDrawColor rowColor;
    FclDrawColor color0C;
    FclVec2 pos0;
    FclVec2 pos1;
    FclVec2 pos2;
    FclVec2 pos3;
    FclVec2 pos4;
    FclVec2 pos5;
    FclVec2 pos6;
    s16 j;
    u8 shade;
    u8 alpha;
    u8 alpha3;
    u8 alpha2;
    u8 alpha4;
    s32 color2;
    s32 color;
    u16 buttons;
    FclVec2 *base;
    u8 *ps;
    s16 i;
    s8 *p;

    p = (s8*)((KwlnTask *)task)->work;
    switch ((u8)p[1]) {
    case 0x63:
        yListSlotCreate(0xA, 0);
        yListSlotCreate(0xA, 1);
        yListSlotAppend(0, 1, 1);
        yListSlotAppend(0, 0x2C, 1);
        yListSlotAppend(0, 0x92, 1);
        yListSlotAppend(0, 0x7F, 1);
        yListSlotAppend(0, 0x45, 1);
        yListSlotAppend(0, 0x1E, 1);
        yListSlotAppend(0, 0x56, 1);
        yListSlotAppend(0, 0xA3, 1);
        yListSlotAppend(0, 0x23, 1);
        yListSlotAppend(0, 2, 1);
        yListSlotAppend(0, 0xB, 1);
        yListSlotAppend(0, 0x81, 1);
        yListSlotAppend(1, 0xBD, 0);
        p[1] = 0x64;
        break;
    case 0x64:
        if (*(s8 *)yListSlotWork(0) == 0) {
            break;
        }
        if (fclCombineRowsBusy(task) == 1) {
            break;
        }
        p[0x20] = 0;
        for (i = 0; i < 12; i++) {
            if (((u8 *)yListSlotEntry(0, i))[4] == 0) {
                p[0x20] = 1;
            }
        }
        for (i = 0; i < (u16)datPersonaRosterCapacity(); i++) {
            slotColor = fclMakeDrawColor(0, 0, 0x99, 0xFF);
            ((FclCombineBallSlot *)fclCombineSlotRecord(((FclCombineMenu *)p)->ballTask.task, i))->color = slotColor;
        }
        p[0x129] = -1;
        p[0x128] = -1;
        ((FclCombineMenu *)p)->f11E = -1;
        fclCombineLayoutDetailSprites(task, 1);
        fclCombineDrawPairLayout(task, 2, 0);
        if (p[0x20] == 0) {
            fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
        } else {
            fclCombineFadeLabelSprites(task, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0);
            ps = fclSpriteEntry(0x8A);
            ((FclCombineRowSprite *)ps)->position.x += 60.0f;
        }
        base = (FclVec2 *)D_00640E70;
        pos0 = fclMakeVec2(base->x, base->y);
        fclSpriteCreate(0xC8, pos0, 42.0f, 0x5A);
        fclSpriteStartAlphaAt(0xC8, 0xFF, 0, 0, 0xA, 0xA);
        pos1 = fclMakeVec2((f32)0x28A + base->x, base->y);
        pos2 = fclMakeVec2(base->x - 50.0f, base->y);
        fclSpriteStartPositionAt(0xC8, pos1, pos2, 0, 0x14, 0);
        fclCombineSlideInSlotSprites(task, 0x98, 0x96);
        p[1] = 0x65;
        break;
    case 0x65:
        if (fclDrawGetState(((FclCombineMenu *)p)->drawTask.task) == 0xD) {
            p[1] = 0x69;
            break;
        }
        for (i = 0; i < 12; i++) {
            if (i < ((FclCombinePersonaListHeader *)yListSlotWork(0))->count) {
                if (((u8 *)yListSlotEntry(0, i))[4] > 0) {
                    alpha = (u8)fclEaseInterpolate(0, 0.0f, 255.0f,
                                          ((FclCombineRowSprite *)fclSpriteEntry(i + 0x21C))->positionElapsed,
                                          ((FclCombineRowSprite *)fclSpriteEntry(i + 0x21C))->positionDuration);
                    shade = 0xCC;
                    fclSpriteEntry(i + 0x21C)[0x6E] = shade;
                    fclSpriteEntry(i + 0x22B)[0x6E] = shade;
                } else {
                    alpha = (u8)fclEaseInterpolate(0, 0.0f, 128.0f,
                                          ((FclCombineRowSprite *)fclSpriteEntry(i + 0x21C))->positionElapsed,
                                          ((FclCombineRowSprite *)fclSpriteEntry(i + 0x21C))->positionDuration);
                    shade = 0x66;
                    fclSpriteEntry(i + 0x21C)[0x6E] = shade;
                    fclSpriteEntry(i + 0x22B)[0x6E] = shade;
                }
                color = fclPackRgba(0xCC, 0xFF, 0xFF, alpha);
                rowColor = fclMakeDrawColor(0xCC, 0xFF, 0xFF, alpha);
                nmMesWindowSetNumberColor((u8 *)((FclCombineMenu *)p)->f2BC, i, *(FclDrawColor *)&rowColor);
                frFontExDrawTextDeferredOutB((f32)0x19D, (f32)(i * 23 + 0x80), 43.0f, color, 0, 2,
                      (const char *)((u8 *)iGpffffb440 + ((u16 *)yListSlotEntry(0, i))[1] * 0x11), 0, 0, D_00795E60, 0x15);
            }
        }
        alpha3 = (u8)fclEaseInterpolate(0, 0.0f, 255.0f, ((FclCombineRowSprite *)fclSpriteEntry(0x270))->positionElapsed,
                              ((FclCombineRowSprite *)fclSpriteEntry(0x270))->positionDuration);
        color0C = fclMakeDrawColor(0x2D, 0x2D, 0x2D, alpha3);
        nmMesWindowSetNumberColor((u8 *)((FclCombineMenu *)p)->f2BC, 0xC, *(FclDrawColor *)&color0C);
        frFontExDrawTextDeferredOutB(97.0f, 195.0f, 43.0f, fclPackRgba(0x2D, 0x2D, 0x2D, alpha3), 0, 2,
                      (const char *)((u8 *)iGpffffb440 + ((u16 *)yListSlotEntry(1, 0))[1] * 0x11), 0, 0, D_00795E60, 0x15);
        fclSpriteEntry(0x270)[0x6E] = fclSpriteEntry(0x27D)[0x6E] = 0xFF;
        /* measured: field typing changes 5899 normalized bytes in the full owner. */
        if ((fclDrawGetState(*(u8 **)(p + 0x148)) < 8 || fclDrawGetState(*(u8 **)(p + 0x148)) > 0xD) &&
            /* measured: field typing changes 5899 normalized bytes in the full owner. */
            (fclDrawGetState(*(u8 **)(p + 0x148)) < 0 || fclDrawGetState(*(u8 **)(p + 0x148)) > 5)) {
            for (i = 0; i < 12; i++) {
                if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(i + 0x21C))->flags, 1) == 1) {
                    return;
                }
            }
            if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0xC8))->flags, 1) == 1) {
                return;
            }
            buttons = D_008C024E[0];
            if (buttons & 0x40) {
                if (p[0x20] == 0) {
                    sdkSndStartStream(0, 0, 0, 1);
                    p[0x2F9] = 1;
                    p[0x2FA] = 0;
                    /* measured: field typing changes 5901 normalized bytes in the full owner. */
                    fclDrawSetPlacementEx(*(u8 **)(p + 0x148), (s32)yListSlotEntry(p[0x2F9], p[0x2FA]), 0, cmmCommunityExpRemaining(cmmTopCommunityOfArcana(iGpffffb3d4[((u16 *)yListSlotEntry(p[0x2F9], p[0x2FA]))[1] * 14 + 2]),
                                  (u8 *)yListSlotEntry(p[0x2F9], p[0x2FA]), 0), 1);
                    /* measured: field typing changes 5899 normalized bytes in the full owner. */
                    shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
                    if (((u8 *)yListSlotEntry(p[0x2F9], p[0x2FA]))[4] > (u8)datCalcGetLevelById(1)) {
                        /* measured: field typing changes 5899 normalized bytes in the full owner. */
                        shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0x14, 0x14, 0x14, 0xFF));
                    }
                    /* measured: field typing changes 5899 normalized bytes in the full owner. */
                    shdPersonaEndSelection(fclDrawGetResource(*(u8 **)(p + 0x148)), 1);
                    fclCombineDrawStageBanner(task, 8, 0);
                    fclCombineDrawPairLayout(task, 0, 1);
                    fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                    fclCombineFadePanelSprite(task, 0, 0.0f);
                } else {
                    sdkSndStartStream(0, 0, 0, 8);
                }
            } else if (buttons & 0x80) {
                fclCombineDrawPairLayout(task, 0, 1);
                if (p[0x20] == 0) {
                    fclCombineFadeLabelSprites(task, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                } else {
                    fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                }
                fclCombineFadePanelSprite(task, 0, 60.0f);
                p[1] = 0x66;
                sdkSndStartStream(0, 1, 0, 3);
            } else if (buttons & 0x20) {
                fclCombineDrawPairLayout(task, 0, 1);
                if (p[0x20] == 0) {
                    fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                } else {
                    fclCombineFadeLabelSprites(task, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                }
                p[1] = 0x68;
                sdkSndStartStream(0, 0, 0, 2);
            }
        }
        break;
    case 0x66:
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x21C))->flags, 1) == 1) {
            break;
        }
        fclDrawSetPlacement(((FclCombineMenu *)p)->drawTask.task, (s32)yListSlotEntry(1, 0), 0, 0);
        /* measured: field typing changes 3353 normalized bytes in the full owner. */
        shdPersonaEndSelection(fclDrawGetResource(*(u8 **)(p + 0x148)), 1);
        if (p[0x20] == 0) {
            /* measured: field typing changes 3353 normalized bytes in the full owner. */
            shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
        } else {
            /* measured: field typing changes 3353 normalized bytes in the full owner. */
            shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0x14, 0x14, 0x14, 0xFF));
        }
        p[1] = 0x67;
        break;
    case 0x67:
        if (fclDrawGetState(((FclCombineMenu *)p)->drawTask.task) == 5) {
            /* measured: field typing changes 3210 normalized bytes in the full owner. */
            if (shdPersonaIsSelectionActive(fclDrawGetResource(*(u8 **)(p + 0x148))) == 1) {
                /* measured: field typing changes 3210 normalized bytes in the full owner. */
                shdPersonaStepSelectionCursor(fclDrawGetResource(*(u8 **)(p + 0x148)));
            }
            buttons = D_008C024E[0];
            if (buttons & 0x80) {
                /* measured: field typing changes 3210 normalized bytes in the full owner. */
                if (shdPersonaIsSelectionActive(fclDrawGetResource(*(u8 **)(p + 0x148))) == 0) {
                    /* measured: field typing changes 3210 normalized bytes in the full owner. */
                    shdPersonaBeginSelection(fclDrawGetResource(*(u8 **)(p + 0x148)));
                    /* measured: field typing changes 3210 normalized bytes in the full owner. */
                    fclDrawSetFlag(*(u8 **)(p + 0x148), 0);
                } else {
                    /* measured: field typing changes 3210 normalized bytes in the full owner. */
                    shdPersonaEndSelection(fclDrawGetResource(*(u8 **)(p + 0x148)), 1);
                    /* measured: field typing changes 3209 normalized bytes in the full owner. */
                    fclDrawSetFlag(*(u8 **)(p + 0x148), 1);
                }
            } else if (buttons & 0x20) {
                /* measured: field typing changes 3210 normalized bytes in the full owner. */
                if (shdPersonaIsSelectionActive(fclDrawGetResource(*(u8 **)(p + 0x148))) == 1) {
                    /* measured: field typing changes 3210 normalized bytes in the full owner. */
                    shdPersonaEndSelection(fclDrawGetResource(*(u8 **)(p + 0x148)), 1);
                    /* measured: field typing changes 3209 normalized bytes in the full owner. */
                    fclDrawSetFlag(*(u8 **)(p + 0x148), 1);
                } else {
                    /* measured: field typing changes 3210 normalized bytes in the full owner. */
                    if (fclDrawGetState(*(u8 **)(p + 0x148)) != 5) {
                        break;
                    }
                    sdkSndStartStream(0, 1, 0, 4);
                    /* measured: field typing changes 3209 normalized bytes in the full owner. */
                    fclDrawSetStateByte(*(u8 **)(p + 0x148), 3);
                    if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x1E4))->flags, 0) == 1) {
                        fclSpriteStartAlphaAt(0x1E4, fclSpriteEntry(0x1E4)[0x6E], 0, 0, 0xA, 0);
                    }
                }
            }
        }
        /* measured: field typing changes 3210 normalized bytes in the full owner. */
        if (fclDrawGetState(*(u8 **)(p + 0x148)) < 0 || fclDrawGetState(*(u8 **)(p + 0x148)) > 5) {
            fclCombineDrawPairLayout(task, 0, 0);
            if (p[0x20] == 0) {
                fclCombineFadeLabelSprites(task, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            } else {
                fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                ps = fclSpriteEntry(0x8A);
                ((FclCombineRowSprite *)ps)->position.x += 60.0f;
            }
            p[1] = 0x65;
        }
        break;
    case 0x68:
        for (j = 0; j < ((FclCombinePersonaListHeader *)yListSlotWork(0))->count; j++) {
            alpha2 = (u8)fclEaseInterpolate(0, 255.0f, 0.0f, ((FclCombineRowSprite *)fclSpriteEntry(j + 0x21C))->positionElapsed,
                                  ((FclCombineRowSprite *)fclSpriteEntry(j + 0x21C))->positionDuration);
            color2 = fclPackRgba(0xCC, 0xFF, 0xFF, alpha2);
            if (((FclCombineMenu *)p)->f11E == j) {
                color2 = fclPackRgba(0x2D, 0x2D, 0x2D, alpha2);
            }
            frFontExDrawTextDeferredOutB((f32)0x19D, (f32)(j * 23 + 0x80), 43.0f, color2, 0, 2,
                      (const char *)((u8 *)iGpffffb440 + ((u16 *)yListSlotEntry(0, j))[1] * 0x11), 0, 0, D_00795E60, 0x15);
        }
        alpha4 = (((FclCombinePersonaListHeader *)yListSlotWork(0))->count >= 0xC)
                    ? (u8)fclEaseInterpolate(0, 255.0f, 0.0f, ((FclCombineRowSprite *)fclSpriteEntry(0x270))->positionElapsed,
                                        ((FclCombineRowSprite *)fclSpriteEntry(0x270))->positionDuration)
                    : (u8)fclEaseInterpolate(0, 128.0f, 0.0f, ((FclCombineRowSprite *)fclSpriteEntry(0x270))->positionElapsed,
                                        ((FclCombineRowSprite *)fclSpriteEntry(0x270))->positionDuration);
        frFontExDrawTextDeferredOutB(97.0f, 195.0f, 43.0f, fclPackRgba(0xCC, 0xFF, 0xFF, alpha4), 0, 2,
                      (const char *)((u8 *)iGpffffb440 + ((u16 *)yListSlotEntry(1, 0))[1] * 0x11), 0, 0, D_00795E60, 0x15);
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x71))->flags, 1) == 0 &&
            (s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x70))->flags, 1) == 0) {
            fclCombineLayoutTransition(task, 0);
            fclCombineLayoutDetailSprites(task, 0);
            fclCombineSlideInSlotSprites(task, 0x96, 0x98);
            p[1] = 0x1A;
            p[0] = 0;
        }
        break;
    case 0x69:
        if (fclDrawGetState(((FclCombineMenu *)p)->drawTask.task) != 0xD) {
            break;
        }
        /* measured: field typing changes 1928 normalized bytes in the full owner. */
        if (shdPersonaIsSelectionActive(fclDrawGetResource(*(u8 **)(p + 0x148))) == 1) {
            /* measured: field typing changes 1928 normalized bytes in the full owner. */
            shdPersonaStepSelectionCursor(fclDrawGetResource(*(u8 **)(p + 0x148)));
        }
        buttons = D_008C024E[0];
        if (buttons & 0x40) {
            yListSlotEntry(p[0x2F9], p[0x2FA]);
            sdkSndStartStream(0, 0, 0, 1);
            if (((u8 *)yListSlotEntry(p[0x2F9], p[0x2FA]))[4] > (u8)datCalcGetLevelById(1)) {
                fclCombinePlayCue(task, 0x26, 0);
                p[1] = 0x6B;
            } else {
                fclCombinePlayCue(task, 0x39, 1);
                p[1] = 0x6A;
            }
        } else if (buttons & 0x80) {
            /* measured: field typing changes 1928 normalized bytes in the full owner. */
            if (shdPersonaIsSelectionActive(fclDrawGetResource(*(u8 **)(p + 0x148))) == 0) {
                /* measured: field typing changes 1928 normalized bytes in the full owner. */
                shdPersonaBeginSelection(fclDrawGetResource(*(u8 **)(p + 0x148)));
                /* measured: field typing changes 1928 normalized bytes in the full owner. */
                fclDrawSetFlag(*(u8 **)(p + 0x148), 0);
            } else {
                /* measured: field typing changes 1928 normalized bytes in the full owner. */
                shdPersonaEndSelection(fclDrawGetResource(*(u8 **)(p + 0x148)), 1);
                /* measured: field typing changes 1927 normalized bytes in the full owner. */
                fclDrawSetFlag(*(u8 **)(p + 0x148), 1);
            }
        } else if (buttons & 0x20) {
            /* measured: field typing changes 1928 normalized bytes in the full owner. */
            if (shdPersonaIsSelectionActive(fclDrawGetResource(*(u8 **)(p + 0x148))) == 1) {
                /* measured: field typing changes 1928 normalized bytes in the full owner. */
                shdPersonaEndSelection(fclDrawGetResource(*(u8 **)(p + 0x148)), 1);
                /* measured: field typing changes 1927 normalized bytes in the full owner. */
                fclDrawSetFlag(*(u8 **)(p + 0x148), 1);
            } else {
                /* measured: field typing changes 1927 normalized bytes in the full owner. */
                fclDrawSetStateByte(*(u8 **)(p + 0x148), 0xB);
                fclCombineDrawStageBanner(task, 8, 1);
                fclCombineDrawPairLayout(task, 0, 0);
                if (p[0x20] == 0) {
                    fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                } else {
                    fclCombineFadeLabelSprites(task, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0);
                }
                fclCombineFadePanelSprite(task, 1, 0.0f);
                p[1] = 0x65;
                sdkSndStartStream(0, 0, 0, 2);
            }
        } else if (D_008C024E[2] & 8) {
            if (p[0x122] != 0xC) {
                sdkSndStartStream(0, 2, 0, 5);
            }
            p[0x122] = fclAddClamped(p[0x122], 1, 0xC, 0, 1);
            /* measured: field typing changes 1369 normalized bytes in the full owner. */
            ((FclCombineMenu *)p)->unk120 = yListStepIndex(p[0x122], *(s16 *)(p + 0x120), 0xC, 7, 1);
            ps = fclSpriteEntry(0x155);
            /* measured: field typing changes 1369 normalized bytes in the full owner. */
            pos3 = fclMakeVec2((f32)(*(s16 *)(p + 0x120) * 61 + 0x6A), 16.0f);
            fclSpriteStartPositionAt(0x155, ((FclCombineRowSprite *)ps)->position, pos3, 1, 4, 0);
            ps = fclSpriteEntry(0x2E0);
            /* measured: field typing changes 1369 normalized bytes in the full owner. */
            pos4 = fclMakeVec2((f32)(*(s16 *)(p + 0x120) * 61 + 0x6A), 16.0f);
            fclSpriteStartPositionAt(0x2E0, ((FclCombineRowSprite *)ps)->position, pos4, 1, 4, 0);
            fclCombineDrawStageTiles(task, 0, 0);
            if (p[0x122] < 0xC) {
                /* measured: field typing changes 1928 normalized bytes in the full owner. */
                shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
                /* measured: field typing changes 1928 normalized bytes in the full owner. */
                fclDrawSetPlacementEx(*(u8 **)(p + 0x148), (s32)yListSlotEntry(0, p[0x122]), 0, 0, 1);
            } else {
                /* measured: field typing changes 1928 normalized bytes in the full owner. */
                shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
                if (((u8 *)yListSlotEntry(p[0x2F9], p[0x2FA]))[4] > (u8)datCalcGetLevelById(1)) {
                    /* measured: field typing changes 1928 normalized bytes in the full owner. */
                    shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0x14, 0x14, 0x14, 0xFF));
                }
                /* measured: field typing changes 1930 normalized bytes in the full owner. */
                fclDrawSetPlacementEx(*(u8 **)(p + 0x148), (s32)yListSlotEntry(p[0x2F9], p[0x2FA]), 0, cmmCommunityExpRemaining(cmmTopCommunityOfArcana(iGpffffb3d4[((u16 *)yListSlotEntry(p[0x2F9], p[0x2FA]))[1] * 14 + 2]),
                              (u8 *)yListSlotEntry(p[0x2F9], p[0x2FA]), 0), 1);
            }
        } else if (D_008C024E[2] & 4) {
            if (p[0x122] != 0) {
                sdkSndStartStream(0, 2, 0, 5);
            }
            p[0x122] = fclSubClamped(p[0x122], 1, 0, 0, 1);
            /* measured: field typing changes 814 normalized bytes in the full owner. */
            ((FclCombineMenu *)p)->unk120 = yListStepIndex(p[0x122], *(s16 *)(p + 0x120), 0xC, 7, -1);
            ps = fclSpriteEntry(0x155);
            /* measured: field typing changes 814 normalized bytes in the full owner. */
            pos5 = fclMakeVec2((f32)(*(s16 *)(p + 0x120) * 61 + 0x6A), 16.0f);
            fclSpriteStartPositionAt(0x155, ((FclCombineRowSprite *)ps)->position, pos5, 1, 4, 0);
            ps = fclSpriteEntry(0x2E0);
            /* measured: field typing changes 814 normalized bytes in the full owner. */
            pos6 = fclMakeVec2((f32)(*(s16 *)(p + 0x120) * 61 + 0x6A), 16.0f);
            fclSpriteStartPositionAt(0x2E0, ((FclCombineRowSprite *)ps)->position, pos6, 1, 4, 0);
            fclCombineDrawStageTiles(task, 0, 0);
            if (p[0x122] < 0xC) {
                /* measured: field typing changes 1928 normalized bytes in the full owner. */
                shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
                /* measured: field typing changes 1928 normalized bytes in the full owner. */
                fclDrawSetPlacementEx(*(u8 **)(p + 0x148), (s32)yListSlotEntry(0, p[0x122]), 0, 0, 1);
            } else {
                /* measured: field typing changes 1928 normalized bytes in the full owner. */
                shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
                if (((u8 *)yListSlotEntry(p[0x2F9], p[0x2FA]))[4] > (u8)datCalcGetLevelById(1)) {
                    /* measured: field typing changes 1928 normalized bytes in the full owner. */
                    shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0x14, 0x14, 0x14, 0xFF));
                }
                /* measured: field typing changes 1930 normalized bytes in the full owner. */
                fclDrawSetPlacementEx(*(u8 **)(p + 0x148), (s32)yListSlotEntry(p[0x2F9], p[0x2FA]), 0, cmmCommunityExpRemaining(cmmTopCommunityOfArcana(iGpffffb3d4[((u16 *)yListSlotEntry(p[0x2F9], p[0x2FA]))[1] * 14 + 2]),
                              (u8 *)yListSlotEntry(p[0x2F9], p[0x2FA]), 0), 1);
            }
        }
        break;
    case 0x6A:
        if (nmMesWindowSlotStatus(p[0xD]) != 0) {
            nmMesWindowStepSlotRelease(p[0xD]);
            break;
        }
        if (nmMesWindowGetSlotState(p[0xD]) == 0) {
            p[1] = 0x6C;
            fadeBeginTransition(1, 0xA);
        } else {
            p[1] = 0x69;
        }
        nmMesWindowDestroySlot(p[0xD]);
        break;
    case 0x6B:
        if (nmMesWindowSlotStatus(p[0xD]) != 0) {
            nmMesWindowStepSlotRelease(p[0xD]);
            break;
        }
        nmMesWindowDestroySlot(p[0xD]);
        p[1] = 0x69;
        break;
    case 0x6C:
        if (fadeStatus() != 0) {
            fclDrawSetStateByte(((FclCombineMenu *)p)->drawTask.task, 0xB);
            /* measured: field typing changes 205 normalized bytes in the full owner. */
            fclDrawResetScale(*(u8 **)(p + 0x148));
            fclCombineDrawStageBanner(task, 8, 1);
            ((FclCombineMenu *)p)->f11E = p[0x122];
            for (i = 0; i < 0x30C; i++) {
                fclSpriteSetFlag(i, 0, 1);
            }
            p[1] = 0x6D;
        }
        break;
    case 0x6D:
        if (fclDrawGetState(((FclCombineMenu *)p)->drawTask.task) == 0xE) {
            p[0xB2] = 0;
            p[0] = 0xD;
            ((u8 *)p)[1] = 0xC5;
        }
        break;
    }
}

/* measured: all 26320 bytes match; distinct caption origin and mutable
 * iterator lifetimes retain the retail loop allocation. */
#pragma push
#pragma opt_lifetimes on
typedef struct {
    u8 f0;
    u8 f1;
    u8 pad2[0xB];
    s8 fD;
    u8 padE[0xA9];
    s8 fB7;
    u8 padB8[0x66];
    s16 f11E;
    s16 f120;
    s8 f122;
    s8 f123;
    f32 f124;
    s8 f128;
    s8 f129;
    u8 pad12A[0x10];
    s8 f13A;
    u8 pad13B[0xD];
    u8 * f148;
    u8 pad14C[0x108];
    s32 f254;
    u8 pad258[0x34];
    s32 f28C;
    s32 f290;
    u8 pad294[0x18];
    s32 f2AC;
    s32 f2B0;
    s32 f2B4;
    s32 f2B8;
    s32 f2BC;
    u8 pad2C0[0x60];
} FclCombineSel;

// Fcl combine menu price/purchase screen (entered from state 0x10). With f0 == 0xF it lists candidate personas with a buffed-stat price after discount and buys the selected one: inserts it into the roster and deducts the price.
// With f0 == 0x10 it runs the same list with a non-purchase apply action and no price or money change.
// FUN_002FBEA0
/* List counts deliberately use the signed low halfword of the word at +8;
   retain that alias width. The detail task exposes only a byte-state getter,
   so its state at +1 remains a raw byte rather than an invented full layout. */
void fclCombineMenuPriceInfo(u8 *task) {

    struct {
        s16 firstEntry;
        u8 alpha;
        s32 fontColor;
    } caption;
    FclCombineSel *p;
    u8 state;
    FclDrawColor fc_colW5;
    FclDrawColor fc_colW7;
    FclDrawColor fc_colW4;
    FclDrawColor fc_colW2;
    FclVec2f rowOrigin;
    u8 *ps;
    s32 entryCount;
    s16 rowIndex;
    s16 index;
    s32 entryIndex;
    f32 spriteValue;
    u8 spriteValue2;
    s32 textColor;
    s32 total;
    s32 saved;
    s16 drawSlot;
    u16 bitSav;
    u16 originalFlags;
    s32 tmpu8;

    char text[32];
    char text2[128];
    s16 numberSlot;
    p = ((FclCombineSel*)((KwlnTask *)task)->work);
    state = p->f1;
    switch (state) {
    case 0x8A:
        fclCombineLayoutDetailSprites(task, 1);
        if (p->f0 == 0x10) {
            yListSlotCreate(6, 0);
        } else if (p->f0 == 0xF) {
            if (datGetFlag(0x1460) != 0) {
                yListSlotCreate(8, 0);
            } else {
                yListSlotCreate(2, 0);
            }
        }
        p->f11E = 0;
        p->f120 = 0;
        p->f129 = -1;
        p->f128 = -1;
        p->f123 = 0;
        p->f1 = 0x8B;
        return;
    case 0x8B:
        if (*(s8 *)yListSlotWork(0) == 0) {
            return;
        }
        for (index = 0; index < p->fB7; index++) {
            if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)(fclSpriteEntry(index * 2 + 0x1F8)))->flags, 1) == 1) {
                return;
            }
        }
        entryCount = (s16)((FclCombinePersonaListHeader *)yListSlotWork(0))->count;
        if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 8) {
            entryCount = 8;
            p->f124 = 125.0f / (f32)(((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count - 8);
        }
        if (p->f0 == 0x10) {
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count == 0) {
                p->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                nmMesWindowShowSlotRecord(p->fD, 0xE);
                p->f1 = 0x93;
            } else {
                fclCombineDrawRosterRows(task, 2, entryCount, 0);
                p->f1 = 0x8D;
            }
        } else if (p->f0 == 0xF) {
            p->f123 = 0;
            if (datGetFlag(0x1460) == 0) {
                func_002e68b0(0);
            }
            fclCombineDrawRosterList(task, 2, entryCount, 0);
            p->f1 = 0x98;
        }
        ((FclCombineRowSprite *)(fclSpriteEntry(p->f11E + 0x270)))->alpha = ((FclCombineRowSprite *)(fclSpriteEntry(p->f11E + 0x27D)))->alpha = 0xFF;
        fclSpriteSetFlag(0x270, 2, 1);
        fclSpriteSetFlag(0x27D, 2, 1);
        ((FclCombineRowSprite *)(fclSpriteEntry(p->f11E + 0x270)))->color = ((FclCombineRowSprite *)(fclSpriteEntry(p->f11E + 0x27D)))->color = ((FclCombineRowSprite *)(fclSpriteEntry(p->f11E + 0x28B)))->color = ((FclCombineRowSprite *)(fclSpriteEntry(p->f11E + 0x297)))->color = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
        ((FclCombineRowSprite *)(fclSpriteEntry(p->f11E + 0x2A3)))->color = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        nmMesWindowSetNumberColor((u8 *)p->f2BC, (s8)(p->f11E + 0xC), fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF));
        return;
    case 0x8D:
        entryCount = (s16)((FclCombinePersonaListHeader *)yListSlotWork(0))->count;
        if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 8) {
            entryCount = 8;
        }
        index = p->f11E - p->f120;
        rowIndex = 0;
        entryIndex = (s16)entryCount + index;
        while (index < entryIndex) {
            spriteValue = (f32)(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->positionElapsed);
            spriteValue2 = (u8)fclEaseInterpolate(0, 0.0f, 255.0f, spriteValue, (f32)(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->positionDuration));
            if (p->f11E == index) {
                textColor = fclPackRgba(0x2D, 0x2D, 0x2D, spriteValue2);
                fc_colW5 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, spriteValue2);
            } else {
                textColor = fclPackRgba(0xCC, 0xFF, 0xFF, spriteValue2);
                fc_colW5 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, spriteValue2);
            }
            frFontExDrawTextDeferredOutB(244.0f, (f32)(s32)((rowIndex * 0x17) + 0x6E), 43.0f, textColor, 0, 2, (const char *)((iGpffffb440) + ((((DatPersonaRecord *)(yListSlotEntry(0, index)))->id) * 0x11)), 0, 0, D_00795E60, 0x15);
            drawSlot = (s8)(rowIndex + 0xC);
            nmMesWindowSetNumber((u8 *)p->f2BC, drawSlot,
                          ((DatPersonaRecord *)(yListSlotEntry(0, index)))->level,
                          fclMakeVec2(146.0f, 111.0f + 23.0f * (f32)rowIndex),
                          fc_colW5, 46.0f, 0x59);
            ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2A3)))))->image = (s16)((datPersonaGetArcana(((DatPersonaRecord *)(yListSlotEntry(0, index)))->id) & 0xFF) + 0x1B);
            if (fclSpriteFlagBit(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->flags, 1) == 0) {
                if ((s16)index == p->f11E) {
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->alpha = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x27D)))))->alpha = 0xFF;
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x27D)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x28B)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x297)))))->color = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2A3)))))->color = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                    nmMesWindowSetNumberColor((u8 *)p->f2BC, drawSlot, fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF));
                } else {
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->alpha = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x27D)))))->alpha = 0x80;
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x27D)))))->color = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x28B)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x297)))))->color = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2A3)))))->color = fclMakeDrawColor(0, 0, 0x66, 0xFF);
                    nmMesWindowSetNumberColor((u8 *)p->f2BC, drawSlot, fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF));
                }
            }
            index++;
            rowIndex++;
        }
        if (fclSpriteFlagBit(((FclCombineRowSprite *)(fclSpriteEntry((((s16)entryCount + 0x26F)))))->flags, 1) == 1) {
            break;
        }
        if ((D_008C0276[0] & 0x1000) && (p->f13A == 0)) {
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count <= 1) {
                break;
            }
            sdkSndStartStream(0, 0, 0, 0);
            fclCombineMoveRosterCursor(task, 5);
            return;
        } else if (D_008C027A[0] & 0x1000) {
            if (p->f11E != 0) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count <= 1) {
                break;
            }
            fclCombineMoveRosterCursor(task, 1);
            return;
        } else if ((D_008C0276[0] & 0x4000) && (p->f13A == 0)) {
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count <= 1) {
                break;
            }
            sdkSndStartStream(0, 0, 0, 0);
            fclCombineMoveRosterCursor(task, 4);
            return;
        } else if (D_008C027A[0] & 0x4000) {
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count <= 1) {
                break;
            }
            if (p->f11E != (s16)((((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count - 1))) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            fclCombineMoveRosterCursor(task, 0);
            return;
        } else if (D_008C027A[0] & 0x2000) {
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count <= 1) {
                break;
            }
            if (p->f11E != (s16)((((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count - 1))) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            fclCombineMoveRosterCursor(task, 2);
            return;
        } else if (D_008C027A[0] & 0x8000) {
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count <= 1) {
                break;
            }
            if (p->f11E != 0) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            fclCombineMoveRosterCursor(task, 3);
            return;
        } else if (D_008C024E[0] & 0x40) {
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > p->f11E) {
                p->f122 = 0;
                entryCount = (s16)((FclCombinePersonaListHeader *)yListSlotWork(0))->count;
                if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 8) {
                    entryCount = 8;
                }
                if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 8) {
                    p->f124 = 125.0f / (f32)(((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count - 8);
                }
                fclCombineDrawRosterRows(task, 0, entryCount, 1);
                p->f1 = 0x8E;
                sdkSndStartStream(0, 0, 0, 1);
            }
        } else if (D_008C024E[0] & 0x80) {
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 0) {
                p->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                nmMesWindowSetSlotParam(p->fD, 0);
                nmMesWindowShowSlotRecord(p->fD, 0xC);
                nmMesWindowSetSlotFlag(p->fD, 0);
                nmMesWindowRequestRefresh();
                p->f1 = 0x96;
                sdkSndStartStream(0, 0, 0, 1);
            }
        } else if (D_008C024E[0] & 0x20) {
            index = p->f11E - p->f120;
            rowIndex = 0;
            entryIndex = (s16)entryCount + index;
            while (index < entryIndex) {
                fclCombineDrawPersonaRow(task, fclMakeVec2(162.0f, 111.0f), -1, rowIndex, ((DatPersonaRecord *)(yListSlotEntry(0, index)))->id, ((DatPersonaRecord *)(yListSlotEntry(0, index)))->level, 0, 1, 0, 0xCC);
                index++;
                rowIndex++;
            }
            fclCombineDrawSlotFields(task, fclMakeVec2(156.0f, 87.0f), 0, 1, 0, 1, 1);
            fclCombineDrawSlotFrames(task, fclMakeVec2(472.0f, 112.0f), 0, 1);
            fclCombineSlideInHeaderSprites((f32)0x1A1, 220.0f, task, 0, 1);
            p->f1 = 0x94;
            sdkSndStartStream(0, 0, 0, 2);
        }
        p->f13A = 0;
        break;
    case 0x95:
        if (nmMesWindowSlotStatus(p->fD) != 0) {
            nmMesWindowStepSlotRelease(p->fD);
            return;
        }
        if (nmMesWindowGetSlotState(p->fD) == 0) {
            originalFlags = *(u16 *)yListSlotEntry(0, p->f11E);
            if (*(u16 *)yListSlotEntry(0, p->f11E) & 4) {
                *(u16 *)yListSlotEntry(0, p->f11E) = 0;
                *(u16 *)yListSlotEntry(0, p->f11E) |= 1;
                datPersonaCacheRecord(yListSlotEntry(0, p->f11E));
                *(u16 *)yListSlotEntry(0, p->f11E) = originalFlags;
            } else {
                datPersonaCacheRecord(yListSlotEntry(0, p->f11E));
            }
            nmMesWindowDestroySlot(p->fD);
            p->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            nmMesWindowShowSlotRecord(p->fD, 0xD);
            p->f1 = 0x91;
            return;
        }
        p->f1 = 0x8F;
        nmMesWindowDestroySlot(p->fD);
        return;
    case 0x96:
        entryCount = (s16)((FclCombinePersonaListHeader *)yListSlotWork(0))->count;
        if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 8) {
            entryCount = 8;
        }
        index = p->f11E - p->f120;
        rowIndex = 0;
        entryIndex = (s16)entryCount + index;
        while (index < entryIndex) {
            spriteValue = (f32)(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->positionElapsed);
            spriteValue2 = (u8)fclEaseInterpolate(0, 0.0f, 255.0f, spriteValue, (f32)(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->positionDuration));
            if (p->f11E == index) {
                textColor = fclPackRgba(0x2D, 0x2D, 0x2D, spriteValue2);
            } else {
                textColor = fclPackRgba(0xCC, 0xFF, 0xFF, spriteValue2);
            }
            frFontExDrawTextDeferredOutB(244.0f, (f32)(s32)((rowIndex * 0x17) + 0x6E), 43.0f, textColor, 0, 2, (const char *)((iGpffffb440) + ((((DatPersonaRecord *)(yListSlotEntry(0, index)))->id) * 0x11)), 0, 0, D_00795E60, 0x15);
            index++;
            rowIndex++;
        }
        if (nmMesWindowSlotStatus(p->fD) != 0) {
            nmMesWindowStepSlotRelease(p->fD);
            return;
        }
        if (nmMesWindowGetSlotState(p->fD) == 0) {
            index = 0;
            while (index < ((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count) {
                bitSav = *(u16 *)yListSlotEntry(0, index);
                if (*(u16 *)yListSlotEntry(0, index) & 4) {
                    *(u16 *)yListSlotEntry(0, index) = 0;
                    *(u16 *)yListSlotEntry(0, index) |= 1;
                    datPersonaCacheRecord(yListSlotEntry(0, index));
                    *(u16 *)yListSlotEntry(0, index) = bitSav;
                } else {
                    datPersonaCacheRecord(yListSlotEntry(0, index));
                }
                index++;
            }
            nmMesWindowDestroySlot(p->fD);
            p->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            nmMesWindowShowSlotRecord(p->fD, 0xD);
            p->f1 = 0x92;
            fclCombineDrawRosterRows(task, 0, entryCount, 1);
            return;
        }
        p->f1 = 0x8D;
        nmMesWindowDestroySlot(p->fD);
        return;
    case 0x8E:
        if (fclSpriteFlagBit(((FclCombineRowSprite *)(fclSpriteEntry(0x270)))->flags, 1) != 1) {
            fclSpriteSetHidden((u8 *)(p->f28C), 1);
            fclSpriteSetHidden((u8 *)(p->f290), 1);
            fclDrawSetPlacement(p->f148, (s32)yListSlotEntry(0, p->f11E), 0, 1);
            shdPersonaEndSelection(fclDrawGetResource(p->f148), 1);
            shdPersonaSetChildDispCtlHandle(fclDrawGetResource(p->f148), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
            fclCombineDrawStageBanner(task, 0, 0);
            p->f1 = 0x8F;
            return;
        }
        break;
    case 0x8F:
        if ((s8)fclDrawGetState(p->f148) != 5) {
            break;
        }
        if (shdPersonaIsSelectionActive(fclDrawGetResource(p->f148)) == 1) {
            shdPersonaStepSelectionCursor(fclDrawGetResource(p->f148));
        }
        if ((D_008C0276[0] & 0x1000) && (p->f13A == 0)) {
            if (shdPersonaIsSelectionActive(fclDrawGetResource(p->f148)) == 0) {
                if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count <= 1) {
                    goto conv8F;
                }
                sdkSndStartStream(0, 2, 0, 5);
                fclCombineMoveRosterCursor(task, 5);
                if (p->f122 == 0) {
                    fclDrawSetPlacement(p->f148, (s32)yListSlotEntry(0, p->f11E), 0, 1);
                    shdPersonaSetChildDispCtlHandle(fclDrawGetResource(p->f148), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
                } else {
                    fclDrawSetPlacement(p->f148, (s32)datPersonaCachedRecord(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id), 0, 1);
                    shdPersonaSetChildDispCtlHandle(fclDrawGetResource(p->f148), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
                }
                goto conv8F;
            }
        } else if (D_008C027A[0] & 0x1000) {
            if (shdPersonaIsSelectionActive(fclDrawGetResource(p->f148)) == 0) {
                if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count <= 1) {
                    goto conv8F;
                }
                if (p->f11E != 0) {
                    sdkSndStartStream(0, 2, 0, 5);
                }
                fclCombineMoveRosterCursor(task, 1);
                if (p->f122 == 0) {
                    fclDrawSetPlacement(p->f148, (s32)yListSlotEntry(0, p->f11E), 0, 1);
                    shdPersonaSetChildDispCtlHandle(fclDrawGetResource(p->f148), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
                } else {
                    fclDrawSetPlacement(p->f148, (s32)datPersonaCachedRecord(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id), 0, 1);
                    shdPersonaSetChildDispCtlHandle(fclDrawGetResource(p->f148), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
                }
                goto conv8F;
            }
        } else if (D_008C027A[0] & 1) {
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count <= 1) {
                goto conv8F;
            }
            sdkSndStartStream(0, 2, 0, 5);
            fclCombineMoveRosterCursor(task, 5);
            if (p->f122 == 0) {
                fclDrawSetPlacement(p->f148, (s32)yListSlotEntry(0, p->f11E), 0, 1);
                shdPersonaSetChildDispCtlHandle(fclDrawGetResource(p->f148), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
            } else {
                fclDrawSetPlacement(p->f148, (s32)datPersonaCachedRecord(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id), 0, 1);
                shdPersonaSetChildDispCtlHandle(fclDrawGetResource(p->f148), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
            }
            goto conv8F;
        } else if ((D_008C0276[0] & 0x4000) && (p->f13A == 0)) {
            if (shdPersonaIsSelectionActive(fclDrawGetResource(p->f148)) == 0) {
                if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count <= 1) {
                    goto conv8F;
                }
                sdkSndStartStream(0, 2, 0, 5);
                fclCombineMoveRosterCursor(task, 4);
                if (p->f122 == 0) {
                    fclDrawSetPlacement(p->f148, (s32)yListSlotEntry(0, p->f11E), 0, 1);
                    shdPersonaSetChildDispCtlHandle(fclDrawGetResource(p->f148), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
                } else {
                    fclDrawSetPlacement(p->f148, (s32)datPersonaCachedRecord(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id), 0, 1);
                    shdPersonaSetChildDispCtlHandle(fclDrawGetResource(p->f148), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
                }
                goto conv8F;
            }
        } else if (D_008C027A[0] & 0x4000) {
            if (shdPersonaIsSelectionActive(fclDrawGetResource(p->f148)) == 0) {
                if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count <= 1) {
                    goto conv8F;
                }
                if (p->f11E != (s16)((((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count - 1))) {
                    sdkSndStartStream(0, 2, 0, 5);
                }
                fclCombineMoveRosterCursor(task, 0);
                if (p->f122 == 0) {
                    fclDrawSetPlacement(p->f148, (s32)yListSlotEntry(0, p->f11E), 0, 1);
                    shdPersonaSetChildDispCtlHandle(fclDrawGetResource(p->f148), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
                } else {
                    fclDrawSetPlacement(p->f148, (s32)datPersonaCachedRecord(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id), 0, 1);
                    shdPersonaSetChildDispCtlHandle(fclDrawGetResource(p->f148), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
                }
                goto conv8F;
            }
        } else if (D_008C0252[0] & 2) {
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count <= 1) {
                goto conv8F;
            }
            sdkSndStartStream(0, 2, 0, 5);
            fclCombineMoveRosterCursor(task, 4);
            if (p->f122 == 0) {
                fclDrawSetPlacement(p->f148, (s32)yListSlotEntry(0, p->f11E), 0, 1);
                shdPersonaSetChildDispCtlHandle(fclDrawGetResource(p->f148), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
            } else {
                fclDrawSetPlacement(p->f148, (s32)datPersonaCachedRecord(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id), 0, 1);
                shdPersonaSetChildDispCtlHandle(fclDrawGetResource(p->f148), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
            }
            if (p->f122 == 0) {
                fclDrawSetPlacement(p->f148, (s32)yListSlotEntry(0, p->f11E), 0, 1);
                shdPersonaSetChildDispCtlHandle(fclDrawGetResource(p->f148), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
            } else {
                fclDrawSetPlacement(p->f148, (s32)datPersonaCachedRecord(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id), 0, 1);
                shdPersonaSetChildDispCtlHandle(fclDrawGetResource(p->f148), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
            }
            goto conv8F;
        } else if (D_008C024E[0] & 8) {
            if (p->f122 == 1) {
                p->f122 = 0;
                ps = fclSpriteEntry(0x150);
                fclSpriteStartPositionAt(0x150, ((FclCombineRowSprite *)(ps))->position, fclMakeVec2((f32)0x141, 16.0f), 1, 4, 0);
                ps = fclSpriteEntry(0x2E0);
                fclSpriteStartPositionAt(0x2E0, ((FclCombineRowSprite *)(ps))->position, fclMakeVec2((f32)0x141, 16.0f), 1, 4, 0);
                fclDrawSetSlot(p->f148, (s32)yListSlotEntry(0, p->f11E), 0, 1);
                sdkSndStartStream(0, 2, 0, 5);
            }
            goto conv8F;
        } else if (D_008C024E[0] & 4) {
            if (p->f122 == 0) {
                p->f122 = 1;
                ps = fclSpriteEntry(0x150);
                fclSpriteStartPositionAt(0x150, ((FclCombineRowSprite *)(ps))->position, fclMakeVec2(107.0f, 16.0f), 1, 4, 0);
                ps = fclSpriteEntry(0x2E0);
                fclSpriteStartPositionAt(0x2E0, ((FclCombineRowSprite *)(ps))->position, fclMakeVec2(107.0f, 16.0f), 1, 4, 0);
                fclDrawSetSlot(p->f148, (s32)datPersonaCachedRecord(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id), 0, 0);
                sdkSndStartStream(0, 2, 0, 5);
            }
            goto conv8F;
        } else if (D_008C024E[0] & 0x40) {
            p->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            sprintf(text, &iGpffffa8a4, ((char *)iGpffffb440) + ((((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id) * 0x11));
            nmMesWindowSetSlotString(p->fD, 0, &text);
            nmMesWindowSetSlotParam(p->fD, 0);
            nmMesWindowShowSlotRecord(p->fD, 0xB);
            nmMesWindowSetSlotFlag(p->fD, 0);
            nmMesWindowRequestRefresh();
            p->f1 = 0x95;
            sdkSndStartStream(0, 0, 0, 1);
            goto conv8F;
        } else if (D_008C024E[0] & 0x20) {
            if (shdPersonaIsTransitioning(fclDrawGetResource(p->f148)) == 1) {
                break;
            }
            if (shdPersonaIsSelectionActive(fclDrawGetResource(p->f148)) == 1) {
                shdPersonaEndSelection(fclDrawGetResource(p->f148), 1);
                fclDrawSetFlag(p->f148, 1);
            } else {
                fclDrawSetStateByte(p->f148, 3);
                fclCombineDrawStageBanner(task, 0, 1);
                p->f1 = 0x90;
                sdkSndStartStream(0, 0, 0, 2);
            }
        } else if (D_008C024E[0] & 0x80) {
            if (shdPersonaIsSelectionActive(fclDrawGetResource(p->f148)) == 0) {
                shdPersonaBeginSelection(fclDrawGetResource(p->f148));
                fclDrawSetFlag(p->f148, 0);
            } else {
                shdPersonaEndSelection(fclDrawGetResource(p->f148), 1);
                fclDrawSetFlag(p->f148, 1);
            }
        }
    conv8F:
        p->f13A = 0;
        break;
    case 0x90:
        if (((s8)fclDrawGetState(p->f148) < 0 || (s8)fclDrawGetState(p->f148) > 5) && *(s8 *)yListSlotWork(0) != 0) {
            entryCount = (s16)((FclCombinePersonaListHeader *)yListSlotWork(0))->count;
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 8) {
                entryCount = 8;
            }
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 8) {
                p->f124 = 125.0f / (f32)(((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count - 8);
            }
            fclSpriteSetHidden((u8 *)(p->f28C), 0);
            fclSpriteSetHidden((u8 *)(p->f290), 0);
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 0) {
                fclCombineDrawRosterRows(task, 0, entryCount, 0);
                p->f11E = 0;
                p->f120 = 0;
                p->f1 = 0x8B;
                return;
            }
            p->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            nmMesWindowShowSlotRecord(p->fD, 0xE);
            p->f1 = 0x93;
            return;
        }
        break;
    case 0x91:
        if (nmMesWindowSlotStatus(p->fD) != 0) {
            nmMesWindowStepSlotRelease(p->fD);
            return;
        }
        nmMesWindowDestroySlot(p->fD);
        fclDrawSetStateByte(p->f148, 3);
        fclCombineDrawStageBanner(task, 0, 1);
        yListSlotCreate(6, 0);
        p->f1 = 0x90;
        return;
    case 0x92:
        if (nmMesWindowSlotStatus(p->fD) != 0) {
            nmMesWindowStepSlotRelease(p->fD);
            return;
        }
        nmMesWindowDestroySlot(p->fD);
        fclCombineDrawActionList(task);
        fclCombineSlideInSlotSprites(task, 0x96, 0x118);
        fclCombineLayoutDetailSprites(task, 0);
        p->f0 = 0;
        p->f1 = 0x1B;
        return;
    case 0x93:
        if (nmMesWindowSlotStatus(p->fD) != 0) {
            nmMesWindowStepSlotRelease(p->fD);
            return;
        }
        nmMesWindowDestroySlot(p->fD);
        fclCombineDrawActionList(task);
        fclCombineSlideInSlotSprites(task, 0x96, 0x118);
        fclCombineLayoutDetailSprites(task, 0);
        p->f0 = 0;
        p->f1 = 0x1B;
        return;
    case 0x97:
        if (nmMesWindowSlotStatus(p->fD) != 0) {
            nmMesWindowStepSlotRelease(p->fD);
            return;
        }
        nmMesWindowDestroySlot(p->fD);
        if (fclCombineClaimSlot(task) == 0) {
            if ((s8)fclDrawGetState(p->f148) == 5) {
                fclDrawSetStateByte(p->f148, 3);
                fclCombineDrawStageBanner(task, 0, 1);
            }
            p->f1 = 0x8D;
            return;
        }
        break;
    case 0x94:
        entryCount = (s16)((FclCombinePersonaListHeader *)yListSlotWork(0))->count;
        if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 8) {
            entryCount = 8;
        }
        index = p->f11E - p->f120;
        rowIndex = 0;
        entryIndex = (s16)entryCount + index;
        while (index < entryIndex) {
            spriteValue = (f32)(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->positionElapsed);
            spriteValue2 = (u8)fclEaseInterpolate(0, 255.0f, 0.0f, spriteValue, (f32)(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->positionDuration));
            if (p->f11E == rowIndex) {
                textColor = fclPackRgba(0x2D, 0x2D, 0x2D, spriteValue2);
            } else {
                textColor = fclPackRgba(0xCC, 0xFF, 0xFF, spriteValue2);
            }
            frFontExDrawTextDeferredOutB(244.0f, (f32)(s32)((rowIndex * 0x17) + 0x6E), 43.0f, textColor, 0, 2, (const char *)((iGpffffb440) + ((((DatPersonaRecord *)(yListSlotEntry(0, index)))->id) * 0x11)), 0, 0, D_00795E60, 0x15);
            index++;
            rowIndex++;
        }
        if (fclSpriteFlagBit(((FclCombineRowSprite *)(fclSpriteEntry(0x193)))->flags, 1) == 0) {
            fclCombineDrawActionList(task);
            fclCombineSlideInSlotSprites(task, 0x96, 0x118);
            fclCombineLayoutDetailSprites(task, 0);
            p->f0 = 0;
            p->f1 = 0x1B;
            return;
        }
        break;
    case 0x98:
        fclDrawNumber(fclMakeVec2(250.0f + ((FclCombineRowSprite *)fclSpriteEntry(0x69))->position.x, 46.0f), 47.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 0x10, 5, fclGetMoney(), 9, 0x37, (s32)resourceFindByName(&D_00641B30), fclCombineGetSpritePool(), 0x56);
        entryCount = (s16)((FclCombinePersonaListHeader *)yListSlotWork(0))->count;
        if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 8) {
            entryCount = 8;
        }
        index = p->f11E - p->f120;
        rowIndex = 0;
        entryIndex = (s16)entryCount + index;
        while (index < entryIndex) {
            spriteValue = (f32)(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->positionElapsed);
            spriteValue2 = (u8)fclEaseInterpolate(0, 0.0f, 255.0f, spriteValue, (f32)(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->positionDuration));
            if (p->f11E == index) {
                textColor = fclPackRgba(0x2D, 0x2D, 0x2D, spriteValue2);
                fc_colW7 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, spriteValue2);
            } else {
                textColor = fclPackRgba(0xCC, 0xFF, 0xFF, spriteValue2);
                fc_colW7 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, spriteValue2);
            }
            frFontExDrawTextDeferredOutB(172.0f, (f32)(s32)((rowIndex * 0x17) + 0x96), 43.0f, textColor, 0, 2, (const char *)((iGpffffb440) + ((((DatPersonaRecord *)(yListSlotEntry(0, index)))->id) * 0x11)), 0, 0, D_00795E60, 0x15);
            if (fclSpriteFlagBit(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2A3)))))->flags, 1) == 0) {
                ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2A3)))))->image = (s16)((datPersonaGetArcana(((DatPersonaRecord *)(yListSlotEntry(0, index)))->id) & 0xFF) + 0x1B);
            }
            numberSlot = (s8)(rowIndex + 0xC);
            tmpu8 = ((DatPersonaRecord *)(yListSlotEntry(0, index)))->level;
            nmMesWindowSetNumber((u8 *)p->f2BC, numberSlot, tmpu8, fclMakeVec2(74.0f, 151.0f + 23.0f * (f32)rowIndex), fc_colW7, 46.0f, 0x59);
            total = ((datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 0) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 1) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 2) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 3) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 4) & 0xFF)) * ((datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 0) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 1) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 2) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 3) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 4) & 0xFF)) + 0x7D0;
            fclDrawNumber(fclMakeVec2(510.0f, (f32)(s32)((rowIndex * 0x17) + 0x9E)), 47.0f, fc_colW7, 0x10, 5, fclCombineApplyDiscount(((DatPersonaRecord *)(yListSlotEntry(0, index)))->id, total), 9, 0x37, (s32)resourceFindByName(&D_00641B30), fclCombineGetSpritePool(), 0xAA);
            if (fclSpriteFlagBit(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->flags, 1) == 0) {
                if ((s16)index == p->f11E) {
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->alpha = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x27D)))))->alpha = 0xFF;
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x27D)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x28B)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x297)))))->color = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2A3)))))->color = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                    nmMesWindowSetNumberColor((u8 *)p->f2BC, numberSlot, fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF));
                } else {
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->alpha = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x27D)))))->alpha = 0x80;
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x27D)))))->color = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x28B)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x297)))))->color = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2A3)))))->color = fclMakeDrawColor(0, 0, 0x66, 0xFF);
                    nmMesWindowSetNumberColor((u8 *)p->f2BC, numberSlot, fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF));
                }
            }
            if (fclSpriteFlagBit(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x21F)))))->flags, 1) == 0) {
                if ((s16)index == p->f11E) {
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x21F)))))->alpha = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2C5)))))->alpha = 0xFF;
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x21F)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2C5)))))->color = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
                } else {
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x21F)))))->alpha = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2C5)))))->alpha = 0x80;
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x21F)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2C5)))))->color = fclMakeDrawColor(0, 0, 0x99, 0xFF);
                }
            }
            index++;
            rowIndex++;
        }
        if (fclSpriteFlagBit(((FclCombineRowSprite *)(fclSpriteEntry((((s16)entryCount + 0x26F)))))->flags, 1) == 1) {
            return;
        }
        if ((D_008C0276[0] & 0x1000) && (p->f13A == 0)) {
            sdkSndStartStream(0, 0, 0, 0);
            fclCombineMoveRosterCursor(task, 5);
            return;
        } else if (D_008C027A[0] & 0x1000) {
            if (p->f11E != 0) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            fclCombineMoveRosterCursor(task, 1);
            return;
        } else if ((D_008C0276[0] & 0x4000) && (p->f13A == 0)) {
            sdkSndStartStream(0, 0, 0, 0);
            fclCombineMoveRosterCursor(task, 4);
            return;
        } else if (D_008C027A[0] & 0x4000) {
            if (p->f11E != (s16)((((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count - 1))) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            fclCombineMoveRosterCursor(task, 0);
            return;
        } else if (D_008C027A[0] & 0x2000) {
            if (p->f11E != (s16)((((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count - 1))) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            fclCombineMoveRosterCursor(task, 2);
            return;
        } else if (D_008C027A[0] & 0x8000) {
            if (p->f11E != 0) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            fclCombineMoveRosterCursor(task, 3);
            return;
        } else if (D_008C0276[0] & 8) {
            if (p->f123 == 0) {
                if (datGetFlag(0x1460) == 0) {
                    func_002e6c90(0);
                }
                p->f123 = 1;
                rowOrigin = ((FclCombineRowSprite *)(fclSpriteEntry(0x2EA)))->position;
                fclSpriteStartPositionAt(0x2EA, rowOrigin, fclMakeVec2(336.0f, rowOrigin.y), 1, 8, 0);
                rowOrigin = ((FclCombineRowSprite *)(fclSpriteEntry(0x2EB)))->position;
                fclSpriteStartPositionAt(0x2EB, rowOrigin, fclMakeVec2(556.0f, rowOrigin.y), 1, 8, 0);
                rowOrigin = ((FclCombineRowSprite *)(fclSpriteEntry(0x2E2)))->position;
                fclSpriteStartPositionAt(0x2E2, rowOrigin, fclMakeVec2(336.0f, rowOrigin.y), 1, 8, 0);
                rowOrigin = ((FclCombineRowSprite *)(fclSpriteEntry(0x2E3)))->position;
                fclSpriteStartPositionAt(0x2E3, rowOrigin, fclMakeVec2(556.0f, rowOrigin.y), 1, 8, 0);
                sdkSndStartStream(0, 0, 0, 5);
            }
            goto conv98;
        } else if (D_008C0276[0] & 4) {
            if (p->f123 == 1) {
                if (datGetFlag(0x1460) == 0) {
                    func_002e68b0(0);
                }
                p->f123 = 0;
                rowOrigin = ((FclCombineRowSprite *)(fclSpriteEntry(0x2EA)))->position;
                fclSpriteStartPositionAt(0x2EA, rowOrigin, fclMakeVec2(79.0f, rowOrigin.y), 1, 8, 0);
                rowOrigin = ((FclCombineRowSprite *)(fclSpriteEntry(0x2EB)))->position;
                fclSpriteStartPositionAt(0x2EB, rowOrigin, fclMakeVec2((f32)0x12B, rowOrigin.y), 1, 8, 0);
                rowOrigin = ((FclCombineRowSprite *)(fclSpriteEntry(0x2E2)))->position;
                fclSpriteStartPositionAt(0x2E2, rowOrigin, fclMakeVec2(79.0f, rowOrigin.y), 1, 8, 0);
                rowOrigin = ((FclCombineRowSprite *)(fclSpriteEntry(0x2E3)))->position;
                fclSpriteStartPositionAt(0x2E3, rowOrigin, fclMakeVec2((f32)0x12B, rowOrigin.y), 1, 8, 0);
                sdkSndStartStream(0, 0, 0, 5);
            }
            goto conv98;
        } else if (D_008C024E[0] & 0x40) {
            p->f122 = 0;
            entryCount = (s16)((FclCombinePersonaListHeader *)yListSlotWork(0))->count;
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 8) {
                entryCount = 8;
            }
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 8) {
                p->f124 = 125.0f / (f32)(((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count - 8);
            }
            fclCombineDrawRosterList(task, 0, entryCount, 1);
            p->f1 = 0x99;
            sdkSndStartStream(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x20) {
            entryCount = (s16)((FclCombinePersonaListHeader *)yListSlotWork(0))->count;
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 8) {
                entryCount = 8;
            }
            if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 8) {
                p->f124 = 125.0f / (f32)(((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count - 8);
            }
            fclCombineDrawRosterList(task, 0, entryCount, 1);
            p->f1 = 0x9C;
            sdkSndStartStream(0, 0, 0, 2);
        }
    conv98:
        p->f13A = 0;
        break;
    case 0x9D:
        if (p->f122 == 1) {
            fclCombineDrawSelectedName(task);
        } else {
            ((FclCombineModelWork *)fclCombineGetWork((u8 *)p->f254))->unk1 = 1;
            shdPersonaSetOpacity(fclDrawGetResource(p->f148), 0.0f);
        }
        if (nmMesWindowSlotStatus(p->fD) != 0) {
            nmMesWindowStepSlotRelease(p->fD);
            return;
        }
        nmMesWindowDestroySlot(p->fD);
        p->f1 = 0x9A;
        return;
    case 0x9E:
        if (p->f122 == 1) {
            fclCombineDrawSelectedName(task);
        } else {
            ((FclCombineModelWork *)fclCombineGetWork((u8 *)p->f254))->unk1 = 1;
            shdPersonaSetOpacity(fclDrawGetResource(p->f148), 0.0f);
        }
        if (nmMesWindowSlotStatus(p->fD) != 0) {
            nmMesWindowStepSlotRelease(p->fD);
            return;
        }
        if (nmMesWindowGetSlotState(p->fD) == 0) {
            datPersonaInsertRosterRecord((u8 *)yListSlotEntry(0, p->f11E));
            total = ((datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 0) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 1) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 2) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 3) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 4) & 0xFF)) * ((datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 0) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 1) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 2) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 3) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 4) & 0xFF)) + 0x7D0;
            saved = fclCombineApplyDiscount(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id, total);
            fclAddMoney(fclGetMoney() - saved);
            nmMesWindowDestroySlot(p->fD);
            p->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            nmMesWindowSetSlotString(p->fD, 0, (void *)(((s32)iGpffffb440) + ((((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id) * 0x11)));
            nmMesWindowShowSlotRecord(p->fD, 0x10);
            p->f1 = 0x9F;
            sdkSndStartStream(1, 0, 2, 6);
            if (p->f2B8 != 0) {
                p->f2B8 = 0;
            }
            p->f2B8 = (s32)cmbCardEffCreateTask(task, p->f122);
            return;
        }
        nmMesWindowDestroySlot(p->fD);
        p->f1 = 0x9A;
        return;
    case 0x9F:
        if (p->f122 == 1) {
            fclCombineDrawSelectedName(task);
        } else {
            ((FclCombineModelWork *)fclCombineGetWork((u8 *)p->f254))->unk1 = 1;
            shdPersonaSetOpacity(fclDrawGetResource(p->f148), 0.0f);
        }
        if (nmMesWindowSlotStatus(p->fD) != 0) {
            nmMesWindowStepSlotRelease(p->fD);
            return;
        }
        nmMesWindowDestroySlot(p->fD);
        p->f1 = 0x9A;
        return;
    case 0x99:
        if (fclSpriteFlagBit(((FclCombineRowSprite *)(fclSpriteEntry(0x270)))->flags, 1) != 1) {
            fclDrawSetVisible(p->f148, 0);
            fclDrawSetPlacement(p->f148, (s32)yListSlotEntry(0, p->f11E), 0, 1);
            shdPersonaEndSelection(fclDrawGetResource(p->f148), 1);
            shdPersonaSetChildDispCtlHandle(fclDrawGetResource(p->f148), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
            fclCombineDrawStageBanner(task, 1, 0);
            p->f1 = 0x9A;
            return;
        }
        break;
    case 0x9A:
        if ((s8)fclDrawGetState(p->f148) < 0 || (s8)fclDrawGetState(p->f148) > 5) {
            break;
        }
        fclSpriteSetHidden((u8 *)p->f28C, 1);
        fclSpriteSetHidden((u8 *)p->f290, 1);
        fclSpriteSetFlag(0x84, 0, 1);
        fclSpriteSetFlag(0x85, 0, 1);
        fclSpriteSetFlag(0x1C6, 0, 1);
        fclSpriteSetFlag(0x80, 0, 1);
        fclSpriteSetFlag(0x20C, 0, 1);
        if (p->f122 == 1) {
            fclCombineDrawSelectedName(task);
        } else {
            ((FclCombineModelWork *)fclCombineGetWork((u8 *)p->f254))->unk1 = 1;
            shdPersonaSetOpacity(fclDrawGetResource(p->f148), 0.0f);
        }
        if ((s8)fclDrawGetState(p->f148) != 5) {
            return;
        }
        if (shdPersonaIsSelectionActive(fclDrawGetResource(p->f148)) == 1) {
            shdPersonaStepSelectionCursor(fclDrawGetResource(p->f148));
        }
        if ((D_008C0276[0] & 0x1000) && (p->f13A == 0)) {
            if (shdPersonaIsSelectionActive(fclDrawGetResource(p->f148)) != 0) {
                return;
            }
            sdkSndStartStream(0, 2, 0, 5);
            fclCombineMoveRosterCursor(task, 5);
            fclDrawSetPlacement(p->f148, (s32)datPersonaCachedRecord(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id), 0, 1);
            return;
        } else if (D_008C027A[0] & 0x1000) {
            if (shdPersonaIsSelectionActive(fclDrawGetResource(p->f148)) != 0) {
                return;
            }
            if (p->f11E != 0) {
                sdkSndStartStream(0, 2, 0, 5);
            }
            fclCombineMoveRosterCursor(task, 1);
            fclDrawSetPlacement(p->f148, (s32)datPersonaCachedRecord(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id), 0, 1);
            return;
        } else if (D_008C0252[0] & 1) {
            sdkSndStartStream(0, 2, 0, 5);
            fclCombineMoveRosterCursor(task, 5);
            fclDrawSetPlacement(p->f148, (s32)datPersonaCachedRecord(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id), 0, 1);
            return;
        } else if ((D_008C0276[0] & 0x4000) && (p->f13A == 0)) {
            if (shdPersonaIsSelectionActive(fclDrawGetResource(p->f148)) != 0) {
                return;
            }
            sdkSndStartStream(0, 2, 0, 5);
            fclCombineMoveRosterCursor(task, 4);
            fclDrawSetPlacement(p->f148, (s32)datPersonaCachedRecord(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id), 0, 1);
            return;
        } else if (D_008C027A[0] & 0x4000) {
            if (shdPersonaIsSelectionActive(fclDrawGetResource(p->f148)) != 0) {
                return;
            }
            if (p->f11E != (s16)((((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count - 1))) {
                sdkSndStartStream(0, 2, 0, 5);
            }
            fclCombineMoveRosterCursor(task, 0);
            fclDrawSetPlacement(p->f148, (s32)datPersonaCachedRecord(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id), 0, 1);
            return;
        } else if (D_008C0252[0] & 2) {
            sdkSndStartStream(0, 2, 0, 5);
            fclCombineMoveRosterCursor(task, 4);
            fclDrawSetPlacement(p->f148, (s32)datPersonaCachedRecord(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id), 0, 1);
            goto conv9A;
        } else if (D_008C024E[0] & 0x80) {
            if (p->f122 == 1) {
                return;
            }
            if (shdPersonaIsSelectionActive(fclDrawGetResource(p->f148)) == 0) {
                shdPersonaBeginSelection(fclDrawGetResource(p->f148));
                fclDrawSetFlag(p->f148, 0);
            } else {
                shdPersonaEndSelection(fclDrawGetResource(p->f148), 1);
                fclDrawSetFlag(p->f148, 1);
            }
            goto conv9A;
        } else if (D_008C024E[0] & 8) {
            if (p->f122 == 1) {
                p->f122 = 0;
                ps = fclSpriteEntry(0x150);
                fclSpriteStartPositionAt(0x150, ((FclCombineRowSprite *)(ps))->position, fclMakeVec2((f32)0x141, 16.0f), 1, 4, 0);
                ps = fclSpriteEntry(0x2E0);
                fclSpriteStartPositionAt(0x2E0, ((FclCombineRowSprite *)(ps))->position, fclMakeVec2((f32)0x141, 16.0f), 1, 4, 0);
                fclDrawSetVisible(p->f148, 0);
                fclCombineDrawPanelBorder(task, 1);
                fclSpriteStartMove((u8 *)p->f2AC, fclMakeVec2(0.0f, 0.0f), fclMakeVec2(0.0f, -7.0f), 4);
                fclSpriteStartMove((u8 *)p->f2B0, fclMakeVec2(0.0f, 432.0f), fclMakeVec2(0.0f, 480.0f), 6);
                fclSpriteStartBoundsMove((u8 *)p->f2B4, fclMakeVec2(0.0f, 69.0f), fclMakeVec2(0.0f, 93.0f), fclMakeBoundsPacket(640.0f, (f32)0x157), fclMakeBoundsPacket(640.0f, 294.0f), 5);
                fclSpriteStartFade((u8 *)p->f2B4, 0xE5, 0, 5);
                fclCombineFadeCursorArrow(task, 0, 0.0f);
                fclDrawSetPlacement(p->f148, (s32)datPersonaCachedRecord(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id), 0, 1);
                sdkSndStartStream(0, 0, 0, 5);
            }
            goto conv9A;
        } else if (D_008C024E[0] & 4) {
            if (p->f122 == 0) {
                p->f122 = 1;
                ps = fclSpriteEntry(0x150);
                fclSpriteStartPositionAt(0x150, ((FclCombineRowSprite *)(ps))->position, fclMakeVec2(107.0f, 16.0f), 1, 4, 0);
                ps = fclSpriteEntry(0x2E0);
                fclSpriteStartPositionAt(0x2E0, ((FclCombineRowSprite *)(ps))->position, fclMakeVec2(107.0f, 16.0f), 1, 4, 0);
                fclDrawSetVisible(p->f148, 1);
                fclCombineDrawPanelBorder(task, 0);
                sdkSndStartStream(0, 0, 0, 5);
                fclSpriteStartMove((u8 *)p->f2AC, fclMakeVec2(0.0f, -10.0f), fclMakeVec2(0.0f, 0.0f), 4);
                fclSpriteStartMove((u8 *)p->f2B0, fclMakeVec2(0.0f, 480.0f), fclMakeVec2(0.0f, 432.0f), 6);
                fclSpriteStartBoundsMove((u8 *)p->f2B4, fclMakeVec2(0.0f, 93.0f), fclMakeVec2(0.0f, 69.0f), fclMakeBoundsPacket(640.0f, 294.0f), fclMakeBoundsPacket(640.0f, (f32)0x157), 5);
                fclSpriteStartFade((u8 *)p->f2B4, 0, 0xE5, 5);
                fclCombineFadePanelSprite(task, 1, 0.0f);
            }
            goto conv9A;
        } else if (D_008C024E[0] & 0x40) {
            sdkSndStartStream(0, 0, 0, 1);
            if (datPersonaFindRosterRecordById(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id) != 0) {
                fclCombinePlayCue(task, 0x12, 0);
                p->f1 = 0x9D;
                return;
            }
            if ((datPersonaRosterCapacity() & 0xFFFF) <= (datPersonaCountValidMembers() & 0xFFFF)) {
                fclCombinePlayCue(task, 0x14, 0);
                p->f1 = 0x9D;
                return;
            }
            total = ((datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 0) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 1) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 2) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 3) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 4) & 0xFF)) * ((datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 0) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 1) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 2) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 3) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, p->f11E), 4) & 0xFF)) + 0x7D0;
            saved = fclCombineApplyDiscount(((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id, total);
            if (fclGetMoney() >= saved) {
                p->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                sprintf(text, &iGpffffa8a4, ((char *)iGpffffb440) + ((((DatPersonaRecord *)(yListSlotEntry(0, p->f11E)))->id) * 0x11));
                nmMesWindowSetSlotString(p->fD, 0, &text);
                sprintf(text2, &iGpffffa8a0, saved);
                nmMesWindowSetSlotString(p->fD, 1, &text2);
                nmMesWindowSetSlotParam(p->fD, 0);
                nmMesWindowShowSlotRecord(p->fD, 0xF);
                nmMesWindowSetSlotFlag(p->fD, 0);
                nmMesWindowRequestRefresh();
                p->f1 = 0x9E;
                goto conv9A;
            } else {
                fclCombinePlayCue(task, 0x11, 0);
                p->f1 = 0x9D;
                goto conv9A;
            }
        } else if (D_008C024E[0] & 0x20) {
            if (shdPersonaIsTransitioning(fclDrawGetResource(p->f148)) == 1) {
                return;
            }
            if (shdPersonaIsSelectionActive(fclDrawGetResource(p->f148)) == 1 && p->f122 == 0) {
                shdPersonaEndSelection(fclDrawGetResource(p->f148), 1);
                fclDrawSetFlag(p->f148, 1);
            } else {
                sdkSndStartStream(0, 0, 0, 2);
                fclDrawSetStateByte(p->f148, 3);
                fclCombineDrawStageBanner(task, 1, 1);
                if (p->f122 == 1) {
                    fclCombineDrawPanelBorder(task, 1);
                    fclSpriteStartMove((u8 *)p->f2AC, fclMakeVec2(0.0f, 0.0f), fclMakeVec2(0.0f, -7.0f), 5);
                    fclSpriteStartMove((u8 *)p->f2B0, fclMakeVec2(0.0f, 432.0f), fclMakeVec2(0.0f, 480.0f), 5);
                    fclSpriteStartBoundsMove((u8 *)p->f2B4, fclMakeVec2(0.0f, 69.0f), fclMakeVec2(0.0f, 239.0f), fclMakeBoundsPacket(640.0f, (f32)0x157), fclMakeBoundsPacket(640.0f, 0.0f), 5);
                } else {
                    fclCombineFadePanelSprite(task, 1, 0.0f);
                }
                fclCombineSetReady((u8 *)p->f254);
                entryCount = (s16)((FclCombinePersonaListHeader *)yListSlotWork(0))->count;
                if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 8) {
                    entryCount = 8;
                }
                if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 8) {
                    p->f124 = 125.0f / (f32)(((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count - 8);
                }
                fclCombineDrawRosterList(task, 0, entryCount, 0);
                p->f1 = 0x9B;
                ((FclCombineModelWork *)fclCombineGetWork((u8 *)p->f254))->unk1 = 1;
                fclCombineInitView((u8 *)p->f254);
                fclSpriteSetFlag(0x80, 0, 0);
                fclSpriteSetFlag(0x20C, 0, 0);
                fclSpriteSetHidden((u8 *)p->f28C, 0);
                fclSpriteSetHidden((u8 *)p->f290, 0);
                fclSpriteSetFlag(0x84, 0, 0);
                fclSpriteSetFlag(0x85, 0, 0);
                fclSpriteSetFlag(0x1C6, 0, 0);
            }
            goto conv9A;
        }
    conv9A:
        p->f13A = 0;
        return;
    case 0x9B:
        fclDrawNumber(fclMakeVec2(250.0f + ((FclCombineRowSprite *)fclSpriteEntry(0x69))->position.x, 46.0f), 47.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 0x10, 5, fclGetMoney(), 9, 0x37, (s32)resourceFindByName(&D_00641B30), fclCombineGetSpritePool(), 0x56);
        entryCount = (s16)((FclCombinePersonaListHeader *)yListSlotWork(0))->count;
        if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 8) {
            entryCount = 8;
        }
        index = p->f11E - p->f120;
        rowIndex = 0;
        entryIndex = (s16)entryCount + index;
        while (index < entryIndex) {
            spriteValue = (f32)(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->positionElapsed);
            spriteValue2 = (u8)fclEaseInterpolate(0, 0.0f, 255.0f, spriteValue, (f32)(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->positionDuration));
            if (p->f11E == index) {
                textColor = fclPackRgba(0x2D, 0x2D, 0x2D, spriteValue2);
                fc_colW4 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, spriteValue2);
            } else {
                textColor = fclPackRgba(0xCC, 0xFF, 0xFF, spriteValue2);
                fc_colW4 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, spriteValue2);
            }
            frFontExDrawTextDeferredOutB(172.0f, (f32)(s32)((rowIndex * 0x17) + 0x96), 43.0f, textColor, 0, 2, (const char *)((iGpffffb440) + ((((DatPersonaRecord *)(yListSlotEntry(0, index)))->id) * 0x11)), 0, 0, D_00795E60, 0x15);
            if (fclSpriteFlagBit(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2A3)))))->flags, 1) == 0) {
                ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2A3)))))->image = (s16)((datPersonaGetArcana(((DatPersonaRecord *)(yListSlotEntry(0, index)))->id) & 0xFF) + 0x1B);
            }
            total = ((datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 0) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 1) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 2) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 3) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 4) & 0xFF)) * ((datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 0) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 1) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 2) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 3) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 4) & 0xFF)) + 0x7D0;
            fclDrawNumber(fclMakeVec2(510.0f, (f32)(s32)((rowIndex * 0x17) + 0x9E)), 47.0f, fc_colW4, 0x10, 5, fclCombineApplyDiscount(((DatPersonaRecord *)(yListSlotEntry(0, index)))->id, total), 9, 0x37, (s32)resourceFindByName(&D_00641B30), fclCombineGetSpritePool(), 0xAA);
            if (fclSpriteFlagBit(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->flags, 1) == 0) {
                if ((s16)index == p->f11E) {
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->alpha = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x27D)))))->alpha = 0xFF;
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x27D)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x28B)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x297)))))->color = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2A3)))))->color = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                    nmMesWindowSetNumberColor((u8 *)p->f2BC, (s8)(rowIndex + 0xC), fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF));
                } else {
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->alpha = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x27D)))))->alpha = 0x80;
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x27D)))))->color = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x28B)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x297)))))->color = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2A3)))))->color = fclMakeDrawColor(0, 0, 0x66, 0xFF);
                    nmMesWindowSetNumberColor((u8 *)p->f2BC, (s8)(rowIndex + 0xC), fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF));
                }
            }
            if (fclSpriteFlagBit(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x21F)))))->flags, 1) == 0) {
                if ((s16)index == p->f11E) {
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x21F)))))->alpha = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2C5)))))->alpha = 0xFF;
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x21F)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2C5)))))->color = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
                } else {
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x21F)))))->alpha = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2C5)))))->alpha = 0x80;
                    ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x21F)))))->color = ((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x2C5)))))->color = fclMakeDrawColor(0, 0, 0x99, 0xFF);
                }
            }
            index++;
            rowIndex++;
        }
        if ((s8)fclDrawGetState(p->f148) == 6) {
            shdPersonaSetOpacity(fclDrawGetResource(p->f148), 0.0f);
            p->f1 = 0x98;
            return;
        }
        break;
    case 0x9C:
        entryCount = (s16)((FclCombinePersonaListHeader *)yListSlotWork(0))->count;
        if (((FclCombinePersonaListHeader *)(yListSlotWork(0)))->count > 8) {
            entryCount = 8;
        }
        caption.firstEntry = p->f11E - p->f120;
        fclDrawNumber(fclMakeVec2(254.0f + ((FclCombineRowSprite *)fclSpriteEntry(0x69))->position.x, 46.0f), 47.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 0x10, 5, fclGetMoney(), 9, 0x37, (s32)resourceFindByName(&D_00641B30), fclCombineGetSpritePool(), 0x56);
        index = caption.firstEntry;
        rowIndex = 0;
        entryIndex = (s16)entryCount + index;
        while (index < entryIndex) {
            spriteValue = (f32)(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->positionElapsed);
            caption.alpha = (u8)fclEaseInterpolate(0, 255.0f, 0.0f, spriteValue, (f32)(((FclCombineRowSprite *)(fclSpriteEntry(((rowIndex + 0x270)))))->positionDuration));
            if (p->f11E == index) {
                caption.fontColor = fclPackRgba(0x2D, 0x2D, 0x2D, caption.alpha);
                fc_colW2 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, caption.alpha);
            } else {
                caption.fontColor = fclPackRgba(0xCC, 0xFF, 0xFF, caption.alpha);
                fc_colW2 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, caption.alpha);
            }
            frFontExDrawTextDeferredOutB(172.0f, (f32)(s32)((rowIndex * 0x17) + 0x96), 43.0f, caption.fontColor, 0, 2, (const char *)((iGpffffb440) + ((((DatPersonaRecord *)(yListSlotEntry(0, index)))->id) * 0x11)), 0, 0, D_00795E60, 0x15);
            total = ((datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 0) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 1) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 2) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 3) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 4) & 0xFF)) * ((datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 0) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 1) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 2) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 3) & 0xFF) + (datPersonaGetBuffedStat((u8 *)yListSlotEntry(0, index), 4) & 0xFF)) + 0x7D0;
            fclDrawNumber(fclMakeVec2(510.0f, (f32)(s32)((rowIndex * 0x17) + 0x9E)), 47.0f, fc_colW2, 0x10, 5, fclCombineApplyDiscount(((DatPersonaRecord *)(yListSlotEntry(0, index)))->id, total), 9, 0x37, (s32)resourceFindByName(&D_00641B30), fclCombineGetSpritePool(), 0xAA);
            index++;
            rowIndex++;
        }
        if (fclSpriteFlagBit(((FclCombineRowSprite *)(fclSpriteEntry(0x193)))->flags, 1) == 0) {
            fclCombineDrawActionList(task);
            fclCombineSlideInSlotSprites(task, 0x96, 0x117);
            fclCombineLayoutDetailSprites(task, 0);
            p->f0 = 0;
            p->f1 = 0x1B;
            return;
        }
        break;
    case 0x8C:
        break;
    default:
        return;
    }
}

#pragma pop
// Fcl combine slot claim: takes the first free combine slot (0-3) whose gate is met and sets up its item; 0 if none.
// FUN_00302570
/* Historical whole-layout probe: 253 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
s32 fclCombineClaimSlot(u8 *task) {
    u8 *p;
    s32 idx;
    s8 i;

    p = ((KwlnTask *)task)->work;
    ((FclCombineMenu *)p)->claimSlot = 0;
    i = 0;
    while ((s32)i < 4) {
        if ((datGetFlag((s32)i + 0x1309) == 0) && (datGetPersonaCacheCompletionPercent() >= D_00749100[(s32)i])) {
            /* measured: field typing changes 232 normalized bytes in the full owner. */
            *(s8 *)(p + 0x130) = (s8)i;
            ((FclCombineMenu *)p)->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            /* measured: field typing changes 156/233 normalized bytes in the full owner. */
            nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 0, datGetItemNameId((s16)(*(s8 *)(p + 0x130) + 0x464)));
            /* measured: field typing changes 165/233 normalized bytes in the full owner. */
            nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), *(s8 *)(p + 0x130) + 0x17);
            datSetFlag((s32)i + 0x1309, 1);
            datItemSetCount((s16)(i + 0x464), 1);
            ((FclCombineMenu *)p)->f1 = 0x97;
            return 1;
        }
        i++;
    }
    return 0;
}

/* Apply the first enabled discount tier: 25, 20, 15 or 10 percent of price. */
// FUN_003026C0
s32 fclCombineApplyDiscount(u16 personaId, s32 price)
{
    s16 i;

    datPersonaGetArcana(personaId);
    for (i = 0; i < 4; i++) {
        if (datGetFlag(0x130C - i) != 0) {
            return price - (price / 100) * (0x19 - i * 5);
        }
    }
    return price;
}

/* MATCHED: no pragmas. Retail-order rewrite of the guarded draft: both
   bb680 tests take the busy arm first; the 0xD store is re-read as
   *(s8 *)(p + 0xD) (b210 forwards it); the tracked positions are FclVec2f
   struct copies in and out of fclSpriteWork; fclSpriteStartPositionAt takes FclVec2f
   by value, so *(FclVec2f *)(q + 0x38) gives retail's ldr/ldl; 413 and 321
   are (f32) int conversions (cvt.s.w); the format string is a gp-relative
   s32 (iGpffffa8a0). Stack slots follow declaration order: fv0 first, the
   FclVec2 constructor results, then fv7..fv1, then buf. */
// Fcl combine menu detail panels (state 7): shows the two detail panels with their counts (0x6E-0x72), follows the sprite anchors each frame (0x73, 0x74), and the d-pad switches panels; cancel (0x20) returns to state 0 at sub-state 0x1A.
// FUN_00302770
/* Historical whole-layout probe: 2717 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
void fclCombineMenuDetailPanels(u8 *task) {
    extern u8 *fclSpriteWork(u8 *task);
    extern void fclCombineDrawDetailPanel(u8 *task);
    FclVec2f fv0;
    FclVec2 position;
    FclVec2 position2;
    FclVec2 position3;
    FclVec2 position4;
    FclVec2 position5;
    FclVec2 position6;
    FclVec2 position7;
    FclVec2 position8;
    FclVec2 position9;
    FclVec2 position10;
    FclVec2 position11;
    FclVec2 position12;
    FclVec2 position13;
    FclVec2 position14;
    FclVec2 position15;
    FclVec2 position16;
    FclVec2 position17;
    FclVec2 position18;
    FclVec2 position19;
    FclVec2 position20;
    FclVec2 position21;
    FclVec2 position22;
    FclVec2 position23;
    FclVec2 position24;
    FclVec2 position25;
    FclVec2 position26;
    FclVec2 position27;
    FclVec2 position28;
    FclVec2 position29;
    FclVec2 position30;
    FclVec2 position31;
    FclVec2 position32;
    FclVec2 position33;
    FclVec2 position34;
    FclVec2 position35;
    FclVec2 position36;
    FclVec2 position37;
    FclVec2 position38;
    FclVec2f fv7;
    FclVec2f fv6;
    FclVec2f fv5;
    FclVec2f fv4;
    FclVec2f fv3;
    FclVec2f fv2;
    FclVec2f fv1;
    char buf[128];
    u8 *p;
    u8 *q;
    s16 i;

    p = ((KwlnTask *)task)->work;
    switch (p[1]) {
    case 0x6E:
        fclCombineSlideInSlotSprites(task, 0x1E7, 0x96);
        if (datGetFlag(0x131A) == 0) {
            ((FclCombineMenu *)p)->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            /* measured: field typing changes 2690 normalized bytes in the full owner. */
            nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x4E);
            datSetFlag(0x131A, 1);
            p[1] = 0x6F;
            break;
        }
        p[1] = 0x70;
        position = fclMakeVec2(640.0f, 98.0f);
        position2 = fclMakeVec2((f32)413, 99.0f);
        fclCombineStartMove(((FclCombineMenu *)p)->bustupTask, position, position2, 6, 0);
        fclCombineFadeLabelSprites(task, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);
    case 0x70:
        cmmDateSelectionRefresh(task);
        ((FclCombineMenu *)p)->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
        sprintf(buf, (const char *)&iGpffffa8a0, fclCalendarMonth());
        /* measured: field typing changes 2525 normalized bytes in the full owner. */
        nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 0, buf);
        sprintf(buf, (const char *)&iGpffffa8a0, (u8)fclCalendarDay());
        /* measured: field typing changes 2525 normalized bytes in the full owner. */
        nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 1, buf);
        /* measured: field typing changes 2525 normalized bytes in the full owner. */
        nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x4A);
        p[1] = 0x71;
        break;
    case 0x71:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 2430 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
        } else {
            /* measured: field typing changes 2430 normalized bytes in the full owner. */
            nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
            p[1] = 0x72;
            /* measured: field typing changes 59 normalized bytes in the full owner. */
            *(s8 *)(p + 0xD) = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            /* measured: field typing changes 59 normalized bytes in the full owner. */
            nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x4B);
            fclCombineDrawStageBanner(task, 2, 0);
            position3 = fclMakeVec2(57.0f, 72.0f);
            position4 = fclMakeVec2(-346.0f, 72.0f);
            fclCombineSlidePanelColumn(task, 0, position3, position4, 1, 0);
            position5 = fclMakeVec2(460.0f, 72.0f);
            position6 = fclMakeVec2(460.0f, 72.0f);
            fclCombineSlidePanelColumn(task, 1, position5, position6, 1, 0);
            fclSpriteSetHidden((u8 *)(((FclCombineMenu *)p)->headerTask.handle), 1);
            fclSpriteSetHidden((u8 *)(((FclCombineMenu *)p)->arrowTask.handle), 1);
            fclCombineLayoutDetailSprites(task, 1);
            fclCombineCreateSlotIcons(task, 1);
        }
        break;
    case 0x72:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 2150 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
        } else {
            /* measured: field typing changes 2150 normalized bytes in the full owner. */
            nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
            p[1] = 0x73;
        }
    case 0x73:
        fclCombineDrawDetailPanel(task);
        q = fclSpriteEntry(0x2E3);
        fv0 = ((FclCombineRowSprite *)q)->position;
        position7 = fclMakeVec2(fv0.x - 50.0f, fv0.y - 50.0f);
        *(FclVec2f *)fclSpriteWork(((FclCombineMenu *)p)->panelTasks[0]) = position7;
        q = fclSpriteEntry(0x2E2);
        fv1 = ((FclCombineRowSprite *)q)->position;
        position8 = fclMakeVec2(fv1.x - 50.0f, fv1.y - 50.0f);
        *(FclVec2f *)fclSpriteWork(((FclCombineMenu *)p)->panelTasks[1]) = position8;
        q = fclSpriteEntry(0x2E9);
        fv2 = ((FclCombineRowSprite *)q)->position;
        position9 = fclMakeVec2(fv2.x - 50.0f, fv2.y - 50.0f);
        *(FclVec2f *)fclSpriteWork(((FclCombineMenu *)p)->panelTasks[2]) = position9;
        q = fclSpriteEntry(0x2EF);
        fv3 = ((FclCombineRowSprite *)q)->position;
        position10 = fclMakeVec2(fv3.x - 50.0f, fv3.y - 50.0f);
        *(FclVec2f *)fclSpriteWork(((FclCombineMenu *)p)->panelTasks[3]) = position10;
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x1CA))->flags, 1) != 1) {
            if (D_008C024E[0] & 8) {
                if (((FclCombineMenu *)p)->f122 != 1) {
                    break;
                }
                sdkSndStartStream(0, 0, 0, 5);
                q = fclSpriteEntry(0x150);
                position11 = fclMakeVec2((f32)321, 16.0f);
                fclSpriteStartPositionAt(0x150, ((FclCombineRowSprite *)q)->position, position11, 1, 4, 0);
                q = fclSpriteEntry(0x2E0);
                position12 = fclMakeVec2((f32)321, 16.0f);
                fclSpriteStartPositionAt(0x2E0, ((FclCombineRowSprite *)q)->position, position12, 1, 4, 0);
                position13 = fclMakeVec2(57.0f, 72.0f);
                position14 = fclMakeVec2(-346.0f, 72.0f);
                fclCombineSlidePanelColumn(task, 0, position13, position14, 0, 1);
                position15 = fclMakeVec2(460.0f, 72.0f);
                position16 = fclMakeVec2(460.0f, 72.0f);
                fclCombineSlidePanelColumn(task, 1, position15, position16, 0, 0);
                /* measured: field typing changes 1774 normalized bytes in the full owner. */
                *(s8 *)(p + 0x122) = 0;
            } else if (D_008C024E[0] & 4) {
                if (((FclCombineMenu *)p)->f122 != 0) {
                    break;
                }
                sdkSndStartStream(0, 0, 0, 5);
                q = fclSpriteEntry(0x150);
                position17 = fclMakeVec2(107.0f, 16.0f);
                fclSpriteStartPositionAt(0x150, ((FclCombineRowSprite *)q)->position, position17, 1, 4, 0);
                q = fclSpriteEntry(0x2E0);
                position18 = fclMakeVec2(107.0f, 16.0f);
                fclSpriteStartPositionAt(0x2E0, ((FclCombineRowSprite *)q)->position, position18, 1, 4, 0);
                position19 = fclMakeVec2(57.0f, 72.0f);
                position20 = fclMakeVec2(-346.0f, 72.0f);
                fclCombineSlidePanelColumn(task, 0, position19, position20, 0, 0);
                position21 = fclMakeVec2(460.0f, 72.0f);
                position22 = fclMakeVec2(460.0f, 72.0f);
                fclCombineSlidePanelColumn(task, 1, position21, position22, 0, 1);
                /* measured: field typing changes 1453 normalized bytes in the full owner. */
                *(s8 *)(p + 0x122) = 1;
            } else if ((D_008C024E[0] & 0x20) && p[1] == 0x73) {
                nmMesWindowDestroySlot(((FclCombineMenu *)p)->fD);
                sdkSndStartStream(0, 0, 0, 2);
                fclCombineDrawStageBanner(task, 2, 1);
                if (((FclCombineMenu *)p)->f122 == 1) {
                    position23 = fclMakeVec2(57.0f, 72.0f);
                    position24 = fclMakeVec2(940.0f, 72.0f);
                    fclCombineSlidePanelColumn(task, 0, position23, position24, 0, 1);
                    position25 = fclMakeVec2(460.0f, 72.0f);
                    position26 = fclMakeVec2(940.0f, 72.0f);
                    fclCombineSlidePanelColumn(task, 1, position25, position26, 0, 1);
                    fclSpriteSetFlag(0x2E8, 0, 1);
                    fclSpriteSetFlag(0x2EE, 0, 1);
                } else if (((FclCombineMenu *)p)->f122 == 0) {
                    position27 = fclMakeVec2(57.0f, 72.0f);
                    position28 = fclMakeVec2(-640.0f, 72.0f);
                    fclCombineSlidePanelColumn(task, 0, position27, position28, 0, 1);
                    position29 = fclMakeVec2(460.0f, 72.0f);
                    position30 = fclMakeVec2(-640.0f, 72.0f);
                    fclCombineSlidePanelColumn(task, 1, position29, position30, 0, 1);
                }
                fclCombineLayoutTransition(task, 0);
                p[1] = 0x74;
                fclCombineFadeLabelSprites(task, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
                position31 = fclMakeVec2((f32)413, 99.0f);
                position32 = fclMakeVec2(640.0f, 98.0f);
                fclCombineStartMove(((FclCombineMenu *)p)->bustupTask, position31, position32, 6, 0);
                fclCombineLayoutDetailSprites(task, 0);
                fclCombineCreateSlotIcons(task, 0);
            }
        }
        break;
    case 0x74:
        q = fclSpriteEntry(0x2E3);
        fv4 = ((FclCombineRowSprite *)q)->position;
        position33 = fclMakeVec2(fv4.x - 50.0f, fv4.y - 50.0f);
        *(FclVec2f *)fclSpriteWork(((FclCombineMenu *)p)->panelTasks[0]) = position33;
        q = fclSpriteEntry(0x2E2);
        fv5 = ((FclCombineRowSprite *)q)->position;
        position34 = fclMakeVec2(fv5.x - 50.0f, fv5.y - 50.0f);
        *(FclVec2f *)fclSpriteWork(((FclCombineMenu *)p)->panelTasks[1]) = position34;
        q = fclSpriteEntry(0x2E9);
        fv6 = ((FclCombineRowSprite *)q)->position;
        position35 = fclMakeVec2(fv6.x - 50.0f, fv6.y - 50.0f);
        *(FclVec2f *)fclSpriteWork(((FclCombineMenu *)p)->panelTasks[2]) = position35;
        q = fclSpriteEntry(0x2EF);
        fv7 = ((FclCombineRowSprite *)q)->position;
        position36 = fclMakeVec2(fv7.x - 50.0f, fv7.y - 50.0f);
        *(FclVec2f *)fclSpriteWork(((FclCombineMenu *)p)->panelTasks[3]) = position36;
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x1CA))->flags, 1) != 1) {
            for (i = 0; i < 4; i++) {
                ((FclCombinePanelWork *)fclSpriteWork(((FclCombineMenu *)p)->panelTasks[i]))->hidden = 1;
            }
            fclCombineSlideInSlotSprites(task, 0x96, 0x1E7);
            fclSpriteSetHidden((u8 *)(((FclCombineMenu *)p)->headerTask.handle), 0);
            fclSpriteSetHidden((u8 *)(((FclCombineMenu *)p)->arrowTask.handle), 0);
            *p = 0;
            p[1] = 0x1A;
        }
        break;
    case 0x6F:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 176 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
        } else {
            /* measured: field typing changes 176 normalized bytes in the full owner. */
            nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
            p[1] = 0x70;
            position37 = fclMakeVec2(640.0f, 98.0f);
            position38 = fclMakeVec2((f32)413, 99.0f);
            fclCombineStartMove(((FclCombineMenu *)p)->bustupTask, position37, position38, 6, 0);
            fclCombineFadeLabelSprites(task, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        break;
    }
}

/* measured: 1036/1040 bytes with eight resolved code relocations and a fully resolved
   44-byte switch table at 0x00749300. Independent searches keep their own
   short counters; the nested category search retains separate inner/outer
   lifetimes. The existing loop-invariant pragma hoists the flag constant. */
// Fcl combine rule check: tests the ids against the combine's three category rules; 1 when they pass or no rule is set.
// FUN_00303610
#pragma push
#pragma opt_loop_invariants on
s32 fclCombineCheckRules(u8 *task, s8 sourceCount, u16 *personaIds)
{
    u8 *rule;
    u16 *last;
    s16 want;
    s8 kind;
    s8 index;
    s16 i;
    s16 j;
    s16 k;
    s16 count;
    s8 found;

    index = ((FclCombineMenu *)(((KwlnTask *)task)->work))->ruleIndex;
    if (index == -1) {
        return 1;
    }
    rule = D_0063FCA0 + index * 0x1C;
    i = 0;
    count = sourceCount;
    last = personaIds + count;
    for (; i < 3; i++) {
        kind = ((FclCombineRule *)rule)->kind;
        if (kind == 0) {
            continue;
        }
        found = 0;
        switch (kind) {
        case 1: {
            s16 item;
            for (item = 0; item < count; item++) {
                want = ((FclCombineRule *)rule)->firstValue;
                if (want == (datPersonaGetArcana(personaIds[item]) & 0xFF)) {
                    found = 1;
                    break;
                }
            }
            break;
        }
        case 2: {
            s16 item;
            for (item = 0; item < count; item++) {
                if (((FclCombineRule *)rule)->firstValue == personaIds[item]) {
                    found = 1;
                    break;
                }
            }
            break;
        }
        case 3:
            want = ((FclCombineRule *)rule)->firstValue;
            if (want == (datPersonaGetArcana(*last) & 0xFF)) {
                found = 1;
            }
            break;
        case 4:
            if (((FclCombineRule *)rule)->firstValue == *last) {
                found = 1;
            }
            break;
        case 5:
            for (k = 0; k < count; k++) {
                want = ((FclCombineRule *)rule)->firstValue;
                if (want == (datPersonaGetArcana(personaIds[k]) & 0xFF)) {
                    for (j = 0; j < count; j++) {
                        want = ((FclCombineRule *)rule)->secondValue;
                        if (want == (datPersonaGetArcana(personaIds[j]) & 0xFF)) {
                            found = 1;
                            break;
                        }
                    }
                }
            }
            break;
        case 6: {
            s16 first;
            s16 second;
            for (first = 0; first < count; first++) {
                if (((FclCombineRule *)rule)->firstValue == personaIds[first]) {
                    for (second = 0; second < count; second++) {
                        if (((FclCombineRule *)rule)->secondValue == personaIds[second]) {
                            found = 1;
                            break;
                        }
                    }
                }
            }
            break;
        }
        case 7:
            if (count != 3) {
                return 0;
            }
            found = 1;
            break;
        case 8:
            if (count != 4) {
                return 0;
            }
            found = 1;
            break;
        case 9:
            if (count != 5) {
                return 0;
            }
            found = 1;
            break;
        case 10:
            if (count != 6) {
                return 0;
            }
            found = 1;
            break;
        }
        if (found == 0) {
            return 0;
        }
    }
    return 1;
}
#pragma pop

// Fcl combine id check: gathers the item ids for the combine's stage count and validates them; 1 when they pass.
// FUN_00303A20
/* Historical whole-layout probe: 730 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
s32 fclCombineCheckIds(u8 *task) {
    s8 *p = ((s8*)((KwlnTask *)task)->work);
    u16 buf[7];

    switch (p[0x1A]) {
    case 2:
        buf[0] = ((DatPersonaRecord *)(yListSlotEntry(0, p[0x128])))->id;
        buf[1] = ((DatPersonaRecord *)(yListSlotEntry(0, ((FclCombineMenu *)p)->f11E)))->id;
        buf[2] = ((DatPersonaRecord *)(yListSlotEntry(p[0x2F9], p[0x2FA])))->id;
        break;
    case 3:
        buf[0] = ((DatPersonaRecord *)(yListSlotEntry(0, p[0x128])))->id;
        buf[1] = ((DatPersonaRecord *)(yListSlotEntry(0, p[0x129])))->id;
        buf[2] = ((DatPersonaRecord *)(yListSlotEntry(0, ((FclCombineMenu *)p)->f11E)))->id;
        buf[3] = ((DatPersonaRecord *)(yListSlotEntry(p[0x2F9], p[0x2FA])))->id;
        break;
    case 4:
        buf[0] = ((DatPersonaRecord *)(yListSlotEntry((s8)(((FclCombineMenu *)p)->f11E + 1), 0)))->id;
        /* measured: field typing changes 725 normalized bytes in the full owner. */
        buf[1] = ((DatPersonaRecord *)(yListSlotEntry((s8)(*(s16 *)(p + 0x11E) + 1), 1)))->id;
        /* measured: field typing changes 738 normalized bytes in the full owner. */
        buf[2] = ((DatPersonaRecord *)(yListSlotEntry((s8)(*(s16 *)(p + 0x11E) + 1), 2)))->id;
        /* measured: field typing changes 738 normalized bytes in the full owner. */
        buf[3] = ((DatPersonaRecord *)(yListSlotEntry((s8)(*(s16 *)(p + 0x11E) + 1), 3)))->id;
        buf[4] = ((DatPersonaRecord *)(yListSlotEntry(p[0x2F9], p[0x2FA])))->id;
        break;
    case 5:
        buf[0] = ((DatPersonaRecord *)(yListSlotEntry((s8)(((FclCombineMenu *)p)->f11E + 1), 0)))->id;
        /* measured: field typing changes 722 normalized bytes in the full owner. */
        buf[1] = ((DatPersonaRecord *)(yListSlotEntry((s8)(*(s16 *)(p + 0x11E) + 1), 1)))->id;
        /* measured: field typing changes 731 normalized bytes in the full owner. */
        buf[2] = ((DatPersonaRecord *)(yListSlotEntry((s8)(*(s16 *)(p + 0x11E) + 1), 2)))->id;
        /* measured: field typing changes 731 normalized bytes in the full owner. */
        buf[3] = ((DatPersonaRecord *)(yListSlotEntry((s8)(*(s16 *)(p + 0x11E) + 1), 3)))->id;
        /* measured: field typing changes 731 normalized bytes in the full owner. */
        buf[4] = ((DatPersonaRecord *)(yListSlotEntry((s8)(*(s16 *)(p + 0x11E) + 1), 4)))->id;
        buf[5] = ((DatPersonaRecord *)(yListSlotEntry(p[0x2F9], p[0x2FA])))->id;
        break;
    case 6:
        buf[0] = ((DatPersonaRecord *)(yListSlotEntry((s8)(((FclCombineMenu *)p)->f11E + 1), 0)))->id;
        /* measured: field typing changes 719 normalized bytes in the full owner. */
        buf[1] = ((DatPersonaRecord *)(yListSlotEntry((s8)(*(s16 *)(p + 0x11E) + 1), 1)))->id;
        /* measured: field typing changes 723 normalized bytes in the full owner. */
        buf[2] = ((DatPersonaRecord *)(yListSlotEntry((s8)(*(s16 *)(p + 0x11E) + 1), 2)))->id;
        /* measured: field typing changes 723 normalized bytes in the full owner. */
        buf[3] = ((DatPersonaRecord *)(yListSlotEntry((s8)(*(s16 *)(p + 0x11E) + 1), 3)))->id;
        /* measured: field typing changes 723 normalized bytes in the full owner. */
        buf[4] = ((DatPersonaRecord *)(yListSlotEntry((s8)(*(s16 *)(p + 0x11E) + 1), 4)))->id;
        /* measured: field typing changes 723 normalized bytes in the full owner. */
        buf[5] = ((DatPersonaRecord *)(yListSlotEntry((s8)(*(s16 *)(p + 0x11E) + 1), 5)))->id;
        buf[6] = ((DatPersonaRecord *)(yListSlotEntry(p[0x2F9], p[0x2FA])))->id;
        break;
    }
    return fclCombineCheckRules(task, p[0x1A], buf);
}

/* measured: 740 executable bytes / 752B retail window, all eight relocations exact.
   Five s32 weights and five s8 IDs reproduce the real stack buffers. A named
   compact-store pointer and the s16 value cast preserve retail address lifetimes. */
// Fcl combine outcome list: appends to the outcome list at p+0x2DA (count at p+0x2DF) from either the current calendar row (selector -1) or the selected entry's five candidates. Candidates with weight 100 are appended directly; the rest are weighted and one is drawn with RpRandom.
// FUN_00303DE0
#pragma opt_loop_invariants on
void fclCombineRollOutcomeList(u8 *task)
{
    s32 weights[5];
    s8 ids[5];
    s8 *p;
    u32 total;
    s8 count;
    s16 cumulative;
    u32 selectedAddress;
    s8 *calendar;
    s32 month;
    s16 i;
    s16 j;
    s16 k;
    s32 roll;
    s32 *entry;

    p = ((s8*)((KwlnTask *)task)->work);
    total = 0;
    count = 0;
    cumulative = 0;
    /* Keep the pre-callback selector snapshot without forming a pointer
       before the table when the selector is -1. */
    selectedAddress = (u32)D_0063FCA0 + p[724] * 28;
    month = fclCalendarMonth();
    calendar = (s8 *)D_006406F0 + (s8)calGetDayEntryForMonthDay(month, (u8)fclCalendarDay()) * 20;
    p[735] = 0;
    if (p[724] == -1) {
        for (i = 0; i < 5; i++) {
            s8 id;
            s8 weight;
            ids[i] = 0;
            weights[i] = 0;
            id = calendar[i * 4];
            if (id != 0) {
                weight = calendar[i * 4 + 1];
                if (weight == 100) {
                    p[p[735] + 730] = id;
                    p[735]++;
                } else {
                    entry = weights + count;
                    *entry = weight;
                    total += weight;
                    ids[count] = id;
                    count++;
                }
            }
        }
    } else {
        for (j = 0; j < 5; j++) {
            s8 id;
            s8 weight;
            ids[j] = 0;
            weights[j] = 0;
            id = ((s8 *)selectedAddress)[j * 4 + 8];
            if (id != 0) {
                weight = ((s8 *)selectedAddress)[j * 4 + 9];
                if (weight == 100) {
                    p[p[735] + 730] = id;
                    p[735]++;
                } else {
                    entry = weights + count;
                    *entry = weight;
                    total += weight;
                    ids[count] = id;
                    count++;
                }
            }
        }
    }
    if (count > 0) {
        roll = (s16)(RpRandom() % total);
        for (k = 0; k < count; k++) {
            cumulative += (s16)weights[k];
            if (roll < cumulative) {
                p[p[735] + 730] = ids[k];
                p[735]++;
                return;
            }
        }
    }
}
#pragma opt_loop_invariants reset
/* Defined below.  The selector is a signed byte that fclCombineRollOutcome forwards
   without re-extending it. */
s32 fclCombineStageValue(s32 count, s8 stageKind);
/* measured: object 532B/window 544B, nd 0. The five-byte weight table copy is
   the tree's load / advance / decrement / store order through a named byte
   temporary. The random roll is an s32 holding the (s8) remainder (extended
   once, retail $a0); the running sum and the s16 index are narrow locals that
   re-extend at each use. The picked stage is an s8 assigned from the call
   (extension at the assignment), then copied into a separate s32 `cur`
   (second extension after the join) that the retry loop compares without a
   further extension; count is an s32 narrowed with `(s8)(count + 1)` so the
   final call passes it raw. Declaration order colours k/limit/count into
   $s5/$s4/$s3 (count reuses arg1's register after its last use). */
// Fcl combine outcome roll: picks the stage (0-4) from the five weights, then the result count, and returns its value.
// FUN_003040D0
s32 fclCombineRollOutcome(u8 *task, s16 level, s8 stageKind)
{
    s8 weights[5];
    u8 *work;
    s8 *src;
    s8 *dst;
    s32 n;
    s8 v;
    s16 i;
    s8 acc;
    s32 roll;
    s16 k;
    s8 limit;
    s32 count;
    s8 stage;
    s8 pick;
    s32 cur;

    work = ((u8*)((KwlnTask *)task)->work);
    src = &iGpffffa8a8;
    dst = weights;
    n = 5;
    do {
        v = *src;
        src += 1;
        n -= 1;
        *dst = v;
        dst += 1;
    } while (n > 0);
    roll = (s8)(RpRandom() % 100);
    acc = weights[0];
    i = 0;
    goto check;
body:
    if (roll < acc) {
        stage = i;
        goto found;
    }
    acc += weights[i + 1];
    i += 1;
check:
    if (i < 4) goto body;
    stage = 4;
found:
    limit = 10;
    if (RpRandom() % 100 < 30) {
        pick = fclSubClamped(level, stage, 1, 0x63, 1);
    } else {
        pick = fclAddClamped(level, stage, 0x63, 1, 1);
    }
    cur = pick;
    k = 0;
    count = 0;
    goto check2;
body2:
    if (cur < limit) goto done;
    limit = fclAddClamped(limit, 10, 0x63, 1, 1);
    count = (s8)(count + 1);
    k += 1;
check2:
    if (k < 10) goto body2;
done:
    ((FclCombineMenu *)(work))->outcomeCount = count;
    return fclCombineStageValue(count, stageKind);
}
/* Look up count in the selected stageKind table (1-6); return -1 otherwise. */
// FUN_003042F0
s32 fclCombineStageValue(s32 count, s8 stageKind)
{
    switch (stageKind) {
    case 1:
        return D_00749040[(s8)count];
    case 2:
        return D_00749060[(s8)count];
    case 3:
        return D_00749080[(s8)count];
    case 4:
        return D_007490A0[(s8)count];
    case 5:
        return D_007490C0[(s8)count];
    case 6:
        return D_007490E0[(s8)count];
    }
    return -1;
}

/* A 0x30-byte combination recipe, as copied out by yListSlotCopyEntry and
   passed by value to fclCombinePickCandidateId.  Its word alignment gives the
   two-word copy loop retail uses for the argument. */
typedef struct {
    s32 data[12];
} FclCombineRecipe;

/* measured: MATCH.  The recipe is passed by value: the six 8-byte blocks
   retail copies into sp+0x4F0 are the compiler's own copy of the struct
   argument.  The key arrives as an s16 and goes to func_00313690
   unextended; bound takes the sign extension.  The loop then fills an
   sp+0x70 s16 table from the func_00313690 key and retries rand()%count
   until func_0010ce10 succeeds.  The random divisor is a separate s32
   local after the sign-extended s64 count; a signed modulo result and a
   named s16 *entry table pointer give retail's dsll32/dsra32 remainder
   and its separate addiu 0x70 before lhu. */
// Fcl combine candidate id: picks a random persona id for the recipe from the ids of the same kind (func_00313690) as arg1, excluding arg1 itself. The draw loop stops at the first pick that datPersonaFindSkillSlot reports as absent (-1), as written.
// FUN_00304410
u16 fclCombinePickCandidateId(FclCombineRecipe recipe, s16 excludedId) {
    s16 table[0x240];
    s64 key;
    s64 count;
    s32 j;
    s32 i;
    s64 j_mask;
    s8 retry;
    s32 divisor;
    s16 *entry;
    u16 selected;
    s64 bound;

    key = (s16)datGetSelectorByte(excludedId);
    count = (s16)key;
    i = 0;
    retry = 0;
    j = 0;
    bound = excludedId;
    goto scan;
scan_body:
    key = (s16)datGetSelectorByte((s16)j);
    if (count == (s16)key && bound != j_mask) {
        table[(s16)i] = (s16)j;
        i = (s16)(i + 1);
    }
    j = (j + 1) & 0xFFFF;
scan:
    j_mask = (u16)j;
    if (j_mask < 0x240) goto scan_body;
    j_mask = (s16)i;
    divisor = (s32)j_mask;
    do {
        entry = table + (s16)(RpRandom() % (u32)divisor);
        selected = *entry;
        if (datPersonaFindSkillSlot((u8 *)&recipe, selected) == -1) {
            retry = 1;
        }
    } while ((s8)retry == 0);
    return selected;
}

/* A work-relative view used while stepping through the row-task table. */
typedef struct {
    u8 pad0[0x154];
    u8 *list;
} FclCombineRowTasks;

typedef struct {
    u16 original;
    u16 replacement;
} FclSkillPair;

#pragma push
/* Preserve signed loop induction and row-coordinate invariants from retail. */
#pragma opt_loop_invariants on
/* Both grid transitions share the header/row draw sequence; mode 0 preserves cell positions. */
/* The provider-relative slot animation layout also preserves this inlined
   roster-grid sequence, including its original argument evaluation shape. */
#define FCL_COMBINE_GRID_ROW(menu, outer, inner, mode, headerPosition, cellPosition, color0, color1) do { \
    s32 grid = mode; \
 \
    s32 offset = outer * 23; \
    s32 y; \
    FclCombineRowTasks *list; \
 \
    fclSpriteStartEntrance(fclCombineSlotRecord((u8 *)menu->f184, (s8)outer), \
        (headerPosition = fclMakeVec2((f32)(offset + 329), 104.0f)), \
        (color0 = fclMakeDrawColor(0, 0, 0x99, 0xFF)), \
        (color1 = fclMakeDrawColor(0, 0, 0x99, 0xFF)), 255, 255, 32.0f, 159.0f, 3, 0, 1, 0); \
    inner = 0; \
    list = (FclCombineRowTasks *)((u8 *)menu + outer * 4); \
    y = offset + 127; \
    for (; inner < (datPersonaRosterCapacity() & 0xFFFF); inner++) { \
        if (grid) { \
            fclSpriteStartEntrance(fclCombineSlotRecord(list->list, (s8)inner), \
                (cellPosition = fclMakeVec2((f32)(inner * 23 + 329), (f32)y)), \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->color, \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->color, \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->alpha, \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->alpha, \
                32.0f, ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->depth, 3, 0, 1, 0); \
        } else { \
            fclSpriteStartEntrance(fclCombineSlotRecord(list->list, (s8)inner), \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->position, \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->color, \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->color, \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->alpha, \
                ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->alpha, \
                32.0f, ((FclCombineBallSlot *)fclCombineSlotRecord(list->list, (s8)inner))->depth, 3, 0, 1, 0); \
        } \
    } \
} while (0)
// Fcl combine menu roster fusion (state 8): picks two roster personas (0x75-0x7E) and previews the match bonus, then confirms (0x81-0x83), writes the fused persona and removes both sources from the roster.
// The result is added to the roster and may replace a skill (0x85-0x89).
// FUN_00304580
/* Historical whole-layout probe: 12990 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
void fclCombineMenuRosterFusion(u8 *task) {
    FclDrawColor gridBaseColor;
    FclDrawColor gridHeaderStartColor;
    FclDrawColor gridHeaderEndColor;
    FclDrawColor gridCellStartColor;
    FclDrawColor gridCellEndColor;
    FclDrawColor selectedRowColor;
    FclDrawColor selectedNumberColor;
    FclDrawColor selectedDigitColor;
    FclDrawColor normalRowColor;
    FclDrawColor normalLabelColor;
    FclDrawColor normalNumberColor;
    FclDrawColor normalDigitColor;
    u8 *ps;





    u8 personaState[5];
    u8 personaState2[5];
    u8 personaState3[5];
    u8 personaState4[5];
    u8 personaState5[5];
    u8 personaState6[5];
    FclVec2 position;
    FclVec2 position2;
    FclVec2 position3;
    FclVec2 position4;
    FclVec2 position5;
    FclVec2 position6;
    FclVec2 position7;
    FclVec2 position8;
    FclVec2 position9;
    FclVec2 position10;
    FclVec2 position11;
    FclVec2 position12;
    FclVec2 position13;
    FclVec2 position14;
    FclVec2 position15;
    FclVec2 position16;
    FclVec2 position17;
    FclVec2 position18;
    FclVec2 position19;
    FclVec2 position20;
    FclVec2 position21;
    FclVec2 position22;
    FclVec2 position23;
    FclVec2 position24;
    FclVec2 position25;
    FclVec2 position26;
    FclVec2 position27;
    FclVec2 position28;
    FclVec2 position29;
    FclVec2 position30;
    FclVec2 position31;
    FclVec2 position32;
    FclVec2 position33;
    FclVec2 position34;
    FclVec2 position35;
    FclVec2 position36;
    FclVec2 position37;
    FclVec2 position38;
    FclVec2 position39;
    FclVec2f position40;
    FclVec2f position41;
    FclVec2f position42;
    FclVec2f position43;
    FclVec2f position44;
    char skillName[0x20];
    u8 *spriteNode;
    f32 spriteValue;
    s16 cursorRow;
    s32 personaModel;
    s32 personaModel2;
    s32 textColor;
    s32 personaModel3;
    s32 textColor2;
    s32 personaModel4;
    s32 textColor3;
    s32 textColor4;
    s32 personaModel5;
    s32 personaModel6;
    s32 textColor5;
    s32 memberCount;
    s32 labelX;
    s32 labelX2;
    u8 *spriteNode2;
    u8 *spriteNode3;
    u16 packedResult;
    u16 packedResult2;
    s32 textColor6;
    s32 textColor7;
    s32 textColor8;
    s32 textColor9;
    s64 matchIndex;
    s16 spriteId;
    s16 spriteId2;
    s8 selectedRow;
    s32 selectedRowAlt;
    s64 tier;
    s16 gridRowIndex;
    s16 gridColumnIndex;
    s8 packedResult3;
    s64 matchIndex2;
    s64 matchIndex3;
    s16 skillPairIndex;
    s8 bonusCount;
    s64 matchIndex4;
    s16 rosterIndex;
    s16 rosterIndex2;
    s16 rosterIndex3;
    s16 rosterIndex4;
    s16 rosterIndex5;
    s16 gridRow;
    s16 gridColumn;
    s16 rosterIndex6;
    s16 rosterIndex7;
    s16 rosterIndex8;
    s16 rosterIndex9;
    s16 rosterIndex10;
    FclVec2f *basePos;
    s16 rosterIndex11;
    s16 rosterIndex12;
    s32 id27D;
    s32 id270;
    s32 id27D_2;
    s32 id270_2;
    s16 rosterIndex13;
    s16 rosterIndex14;
    s16 index;
    s16 index2;
    s16 index3;
    s16 index4;
    s16 index5;
    s16 index6;
    s16 index7;
    s8 bonusKind;
    s16 index8;
    s8 firstSelection;
    s32 firstSelection2;
    s8 previewSelection;
    s8 previewSelection2;
    u16 *skillPair;
    u16 *personaRecord;
    u16 *personaRecord2;
    u16 *personaRecord3;
    u16 *personaRecord4;
    u16 *personaRecord5;
    u16 *personaRecord6;
    u16 *personaRecord7;
    u16 *personaRecord8;
    u16 *personaRecord9;
    u16 *personaRecord10;
    u16 *personaRecord11;
    u16 *personaRecord12;
    u16 *personaRecord13;
    u16 *personaRecord14;
    u16 *personaRecord15;
    u16 *personaRecord16;
    u16 *personaRecord17;
    u16 *personaRecord18;
    u16 *personaRecord19;
    u16 *personaRecord20;
    u16 *personaRecord21;
    u16 *personaRecord22;
    u16 *personaRecord23;
    u16 *personaRecord24;
    s32 firstSelection3;
    s32 firstSelection4;
    s32 firstSelection5;
    s32 firstSelection6;
    s32 firstSelection7;
    s32 firstSelection8;
    u8 spriteAlpha;
    u8 spriteAlpha2;
    u8 spriteAlpha3;
    u8 spriteAlpha4;
    u8 spriteAlpha5;
    u8 state;
    u8 spriteValue2;
    FclSkillPair *skillPair2;
    FclCombineMenu *work;
    u8 slotByte;
    FclCombineMenu *menuWork;
    FclCombineMenu *menuWork2;
    FclCombineMenu *menuWork3;
    FclCombineMenu *menuWork4;
    FclCombineMenu *menuWork5;
    u8 *sprite8;
    u8 *sprite9;
    u8 *sprite10;
    u8 *sprite11;
    u8 *sprite12;
    u8 *sprite13;
    u8 *sprite14;
    u8 *sprite15;
    u8 *sprite16;
    u8 *sprite17;
    work = (FclCombineMenu*)((KwlnTask *)task)->work;
    state = (u8)(work->f1);
    switch (state) {                               /* switch 1 */
    case 0x75:
        if (datGetFlag(0x131C) == 0) {
            work->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            nmMesWindowShowSlotRecord(work->fD, 0x50);
            datSetFlag(0x131C, 1);
            work->f1 = 0x76;
        } else {
            work->f1 = 0x77;
        }
        break;
    case 0x76:
        if (nmMesWindowSlotStatus(work->fD) != 0) {
            nmMesWindowStepSlotRelease(work->fD);
        } else {
            nmMesWindowDestroySlot(work->fD);
            work->f1 = 0x77;
        }
        break;
    case 0x77:
        fclCombineLayoutDetailSprites(task, 1);
        if (datGetFlag(0x1306) != 0) {
            fclDrawSetFlag((u8 *)work->drawTask.handle, 1);
            shdPersonaEndSelection(fclDrawGetResource((u8 *)work->drawTask.handle), 1);
            personaModel = (s32)fclDrawGetResource((u8 *)work->drawTask.handle);
            shdPersonaSetChildDispCtlHandle((u8 *)personaModel, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
            fclDrawSetSlotMode((u8 *)work->drawTask.handle, (s32)datStagedRecord(), 0);
            fclDrawSetStateByte((u8 *)work->drawTask.handle, 1);
            if (datGetFlag(0x1307) == 0) {
                packedResult = datStagedId() & 0xFFFF;
                bonusKind = packedResult & 0xF;
                bonusCount = (packedResult >> 0xC) & 0xF;
                for (index8 = 0; index8 < 5; index8++) {
                    work->f30C[index8] = 0;
                }
                switch (bonusKind) {
                case 0: {
                    s16 bonusIndex;
                    for (bonusIndex = 0; bonusIndex < bonusCount + 1; bonusIndex++) {
                        work->f30C[0] += D_00749350[bonusIndex];
                        work->f30C[1] += D_00749350[bonusIndex];
                    }
                    break;
                }
                case 1: {
                    s16 bonusIndex;
                    for (bonusIndex = 0; bonusIndex < bonusCount + 1; bonusIndex++) {
                        work->f30C[2] += D_00749350[bonusIndex];
                        work->f30C[3] += D_00749350[bonusIndex];
                    }
                    break;
                }
                case 2: {
                    s16 bonusIndex;
                    for (bonusIndex = 0; bonusIndex < bonusCount + 1; bonusIndex++) {
                        work->f30C[4] += D_00749350[bonusIndex];
                        work->f30C[0] += D_00749350[bonusIndex];
                    }
                    break;
                }
                case 3: {
                    s16 bonusIndex;
                    for (bonusIndex = 0; bonusIndex < bonusCount + 1; bonusIndex++) {
                        work->f30C[1] += D_00749350[bonusIndex];
                        work->f30C[2] += D_00749350[bonusIndex];
                    }
                    break;
                }
                }
                shdPersonaFillStateBlock(fclDrawGetResource((u8 *)work->drawTask.handle), work->f30C);
            } else {
                fclCombinePlayCue(task, 0x22, 0);
                work->f1 = 0x85;
                break;
            }
            packedResult3 = (s8)(((datStagedId() & 0xFFFF) >> 0xC) & 0xF);
            if (packedResult3 < 4) {
                fclCombinePlayCue(task, 0x1F, 0);
            } else if (packedResult3 < 7) {
                fclCombinePlayCue(task, 0x20, 0);
            } else {
                fclCombinePlayCue(task, 0x21, 0);
            }
            work->f1 = 0x85;
        } else {
            for (rosterIndex = 0; rosterIndex < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex++) {
                gridBaseColor = fclMakeDrawColor(0, 0, 0x99, 0xFF);
                ((FclCombineBallSlot *)fclCombineSlotRecord((u8 *)work->ballTask.handle, rosterIndex))->color = gridBaseColor;
            }
            fclCombineSlideInSlotSprites(task, 0x93, 0x96);
            fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            fclCombineLayoutFrame(task, 1, 0);
            fclDrawSetFlag((u8 *)work->drawTask.handle, 0);
            yListSlotCreate(5, 0);
            yListSlotCreate(0xA, 1);
            yListSlotCreate(0xA, 2);
            yListSlotCreate(0xA, 3);
            yListSlotCreate(0xA, 4);
            yListSlotCreate(0xA, 5);
            yListSlotCreate(0xA, 6);
            yListSlotCreate(0xA, 7);
            yListSlotCreate(0xA, 8);
            yListSlotCreate(0xA, 9);
            yListSlotCreate(0xA, 0xA);
            yListSlotCreate(0xA, 0xB);
            yListSlotCreate(0xA, 0xC);
            work->f1 = 0x78;
        }
        break;
    case 0x78:
        if (*(s8 *)yListSlotWork(0) != 0) {
            yListBuildPairFlags();
            work->f11E = 0;
            fclCombineSetupPairGrid(task, 1);
            work->f1 = 0x79;
        }
        break;
    case 0x79:
        fclCombineAdvanceGridFade(task, 0x7B, 0);
        break;
    case 0x7B:                                      /* switch 1 */
        for (rosterIndex2 = 0; rosterIndex2 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex2++) {
            fclCombineSelectSlotEntry(task, (s8)(rosterIndex2), -1, -1, 0);
        }
        if ((((s8)(fclDrawGetState((u8 *)work->drawTask.handle))) < 0) || (((s8)(fclDrawGetState((u8 *)work->drawTask.handle))) > 5)) {
            if (D_008C027A[0] & 0x1000) {
                work->f11E = fclSubClamped(work->f11E, 1, 0, (datPersonaRosterCapacity() & 0xFFFF) - 1, 2);
                sdkSndStartStream(0, 0, 0, 0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                work->f11E = fclAddClamped(work->f11E, 1, (datPersonaRosterCapacity() & 0xFFFF) - 1, 0, 2);
                sdkSndStartStream(0, 0, 0, 0);
                return;
            }
            if (D_008C024E[0] & 0x80) {
                sdkSndStartStream(0, 1, 0, 3);
                for (rosterIndex3 = 0; rosterIndex3 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex3++) {
                    position = fclMakeVec2(16.0f, 128.0f);
                    fclCombinePartyRow(task, position, (s8)rosterIndex3, ((u16 *)yListSlotEntry(0, rosterIndex3))[1], ((DatPersonaRecord *)yListSlotEntry(0, rosterIndex3))->level, 0, 1, (s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count);
                }
                position2 = fclMakeVec2(16.0f, 104.0f);
                fclCombineDrawSlotFields(task, position2, 0, 1, 0, 0, 0);
                for (gridColumn = 0; gridColumn < (datPersonaRosterCapacity() & 0xFFFF); gridColumn++) {
                    spriteNode = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x77);
                    FCL_COMBINE_GRID_ROW(work, gridColumn, gridRow, 0, position3, position10, gridHeaderStartColor, gridHeaderEndColor);
                    sdkSpriteFreeNode(spriteNode);
                    gridColumnIndex = (s16)(gridColumn);
                    spriteId = (s16)((gridColumnIndex + 0x25E));
                    spriteNode2 = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x39);
                    fclSpriteStartAlphaAt(spriteId, 0xFFU, 0, 0, 3, 0);
                    fclSpriteStartRevealScaleAt(spriteId, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                    labelX2 = (gridColumnIndex * 0x17) + 0x14E;
                    position4 = fclMakeVec2((f32) labelX2, 110.0f);
                    position5 = fclMakeVec2((f32) labelX2, 110.0f + (sdkSpriteScaledHeight(spriteNode2) / 2.0f));
                    fclSpriteStartPositionAt(spriteId, (*(FclVec2f *)&position4), (*(FclVec2f *)&position5), 0, 3, 0);
                    sdkSpriteFreeNode(spriteNode2);
                }
                fclCombineFadeLabelSprites(task, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                fclSpriteSetHidden((u8 *)(work->headerTask.handle), 1);
                fclSpriteSetHidden((u8 *)(work->arrowTask.handle), 1);
                work->f1 = 0x7CU;
                return;
            }
            if (D_008C024E[0] & 0x40) {
                cursorRow = (s16)(work->f11E);
                if (cursorRow < (((FclCombinePersonaListHeader *)yListSlotWork(0))->count)) {
                    sdkSndStartStream(0, 0, 0, 1);
                    work->f128 = (s8) work->f11E;
                    work->f129 = -1;
                    basePos = (FclVec2f *)D_00640C10;
                    position6 = fclMakeVec2(-380.0f, basePos->y);
                    position7 = fclMakeVec2(basePos->x, basePos->y);
                    fclCombineDrawPersonaCard(task, work->f11E, *(FclVec2f *)&position6, *(FclVec2f *)&position7);
                    for (gridRow = 0; gridRow < (datPersonaRosterCapacity() & 0xFFFF); gridRow++) {
                        position8 = fclMakeVec2((f32) 0x149, 128.0f);
                        firstSelection8 = (u16)((((DatPersonaRecord *)yListSlotEntry((s8)((work->f128 + 1)), gridRow))->id));
                        slotByte = ((DatPersonaRecord *)yListSlotEntry(work->f128 + 1, gridRow))->level;
                        fclCombineDrawPersonaRow(task, position8, work->f128, gridRow, firstSelection8, slotByte, 3, 0, 1, 0xCC);
                        FCL_COMBINE_GRID_ROW(work, gridRow, gridColumn, 1, position9, position10, gridCellStartColor, gridCellEndColor);
                        gridRowIndex = (s16)(gridRow);
                        spriteId2 = (s16)((gridRowIndex + 0x25E));
                        spriteNode3 = sdkSpriteNewNode(fclCombineGetSpritePool(), 0x39);
                        fclSpriteStartAlphaAt(spriteId2, 0xFFU, 0, 0, 3, 0);
                        fclSpriteStartRevealScaleAt(spriteId2, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                        labelX = (gridRowIndex * 0x17) + 0x14E;
                        position11 = fclMakeVec2((f32) labelX, 110.0f);
                        position12 = fclMakeVec2((f32) labelX, 110.0f + (sdkSpriteScaledHeight(spriteNode3) / 2.0f));
                        fclSpriteStartPositionAt(spriteId2, (*(FclVec2f *)&position11), (*(FclVec2f *)&position12), 0, 3, 0);
                        sdkSpriteFreeNode(spriteNode3);
                    }
                    position13 = fclMakeVec2((f32) 0x149, 104.0f);
                    fclCombineDrawSlotLabels(task, position13, 3, 0);
                    fclCombineSlideInSlotSprites(task, 0x94, 0x93);
                    fclCombineFlashSlot(task, (s64)work->f128);
                    work->f1 = 0x7EU;
                    return;
                }
            } else if (D_008C024E[0] & 0x20) {
                sdkSndStartStream(0, 0, 0, 2);
                fclCombineDrawGridRows(task);
                fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                fclCombineLayoutFrame(task, 1, 1);
                fclCombineDrawActionList(task);
                work->f1 = 0x7AU;
                return;
            }
        }
        break;
    case 0x7C:                                      /* switch 1 */
        if (((s16)(fclSpriteFlagBit((((FclCombineRowSprite *)fclSpriteEntry(0x21C))->flags), 1))) != 1) {
            fclDrawSetPlacement((u8 *)work->drawTask.handle, (s32)yListSlotEntry(0, work->f11E), 0, 0);
            personaModel2 = (s32)(fclDrawGetResource((u8 *)work->drawTask.handle));
            shdPersonaSetChildDispCtlHandle((u8 *)personaModel2, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
            shdPersonaEndSelection(fclDrawGetResource((u8 *)work->drawTask.handle), 1);
            work->f1 = 0x7DU;
            return;
        }
        break;
    case 0x7D:                                      /* switch 1 */
        if ((((s8)(fclDrawGetState((u8 *)work->drawTask.handle))) < 0) || (((s8)(fclDrawGetState((u8 *)work->drawTask.handle))) > 5)) {
            for (rosterIndex4 = 0; rosterIndex4 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex4++) {
                position14 = fclMakeVec2(16.0f, 128.0f);
                fclCombinePartyRow(task, position14, (s8)rosterIndex4, ((u16 *)yListSlotEntry(0, rosterIndex4))[1], ((DatPersonaRecord *)yListSlotEntry(0, rosterIndex4))->level, 0, 0, (s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count);
            }
            position15 = fclMakeVec2(16.0f, 104.0f);
            fclCombineDrawSlotFields(task, position15, 0, 0, 0, 0, 0);
            fclCombineRefreshGridCells(task, 0);
            fclCombineFadeLabelSprites(task, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            fclSpriteSetHidden((u8 *)(work->headerTask.handle), 1);
            fclSpriteSetHidden((u8 *)(work->arrowTask.handle), 1);
            work->f1 = 0x7BU;
            return;
        }
        break;
    case 0x7A:
        for (rosterIndex11 = 0; rosterIndex11 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex11++) {
            spriteValue = (f32)((FclCombineRowSprite *)fclSpriteEntry(rosterIndex11 + 0x21C))->positionElapsed;
            spriteValue2 = (u8)fclEaseInterpolate(0, 255.0f, 0.0f, spriteValue, (f32)((FclCombineRowSprite *)fclSpriteEntry(rosterIndex11 + 0x21C))->positionDuration);
            if (work->f11E == rosterIndex11) {
                textColor6 = fclPackRgba(0x2D, 0x2D, 0x2D, spriteValue2);
            } else {
                textColor6 = fclPackRgba(0xCC, 0xFF, 0xFF, spriteValue2);
            }
            if (rosterIndex11 < ((FclCombinePersonaListHeader *)yListSlotWork(0))->count - 1) {
                spriteValue = (f32)(rosterIndex11 * 0x17 + 0x80);
                frFontExDrawTextDeferred(113.0f, spriteValue, 43.0f, textColor6, 0, 2, (const char *)(iGpffffb440 + ((u16 *)yListSlotEntry(0, rosterIndex11))[1] * 0x11), 0, 0, D_00795E60);
            }
        }
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x21C))->flags, 1) == 0
            && (s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(0x193))->flags, 1) == 0) {
            fclCombineSlideInSlotSprites(task, 0x96, 0x93);
            fclCombineLayoutDetailSprites(task, 0);
            work->f0 = 0;
            work->f1 = 0x1B;
        }
        break;
    case 0x7E:                                      /* switch 1 */
        work->f129 = -1;
        spriteAlpha = (u8)((((FclCombineRowSprite *)fclSpriteEntry(0x7C))->alpha));
        /* measured: field typing changes 12994 normalized bytes in the full owner. */
        menuWork5 = *(FclCombineMenu **)(task + 0x38);
        sprite14 = (u8 *)(fclSpriteEntry(0x7C));
        position40 = ((FclCombineRowSprite *)sprite14)->position;
        textColor = fclPackRgba(0xCC, 0xFF, 0xFF, spriteAlpha);
        frFontExDrawTextDeferredOutB(111.0f + position40.x, position40.y, 43.0f, textColor, 0, 2, (const char *)((iGpffffb440) + ((((DatPersonaRecord *)yListSlotEntry(0, menuWork5->f128))->id) * 0x11)), 0, 0, D_00795E60, 0x15);
        for (rosterIndex12 = 0; rosterIndex12 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex12++) {
            fclCombineSelectSlotEntry(task, (s8)(rosterIndex12), work->f128, work->f129, 0);
            if ((((s16)(fclSpriteFlagBit((((FclCombineRowSprite *)fclSpriteEntry((s16)((rosterIndex12 + 0x270))))->flags), 1))) == 0) && (work->f128 != rosterIndex12) && ((((FclCombineRowList *)yListSlotWork(0))->availability[work->f128][rosterIndex12]) > 0)) {
                if (rosterIndex12 == work->f11E) {
                    id27D = rosterIndex12 + 0x27D;
                    id270 = rosterIndex12 + 0x270U;
                    ((FclCombineRowSprite *)fclSpriteEntry(id270))->alpha = ((FclCombineRowSprite *)fclSpriteEntry(id27D))->alpha = 0xFF;
                    selectedRowColor = fclMakeDrawColor(0xCC, 0xFF, 0x33, 0xFF);
                    sprite15 = fclSpriteEntry(rosterIndex12 + 0x297);
                    ((FclCombineRowSprite *)sprite15)->color = selectedRowColor;
                    sprite16 = fclSpriteEntry(rosterIndex12 + 0x28B);
                    /* measured: field typing changes 8 normalized bytes in the full owner. */
                    ((FclCombineRowSprite *)sprite16)->color = *(FclDrawColor *)(sprite15 + 0x85);
                    sprite17 = fclSpriteEntry(id27D);
                    /* measured: field typing changes 8 normalized bytes in the full owner. */
                    ((FclCombineRowSprite *)sprite17)->color = *(FclDrawColor *)(sprite16 + 0x85);
                    /* measured: field typing changes 8 normalized bytes in the full owner. */
                    ((FclCombineRowSprite *)fclSpriteEntry(id270))->color = *(FclDrawColor *)(sprite17 + 0x85);
                    selectedNumberColor = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                    ((FclCombineRowSprite *)fclSpriteEntry(rosterIndex12 + 0x2A3))->color = selectedNumberColor;
                    selectedDigitColor = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                    nmMesWindowSetNumberColor(work->f2BC, (s8)(rosterIndex12 + 0xC), selectedDigitColor);
                    textColor7 = fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF);
                } else {
                    id27D_2 = rosterIndex12 + 0x27D;
                    id270_2 = rosterIndex12 + 0x270U;
                    ((FclCombineRowSprite *)fclSpriteEntry(id270_2))->alpha = ((FclCombineRowSprite *)fclSpriteEntry(id27D_2))->alpha = 0xCC;
                    normalRowColor = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                    sprite8 = fclSpriteEntry(id27D_2);
                    ((FclCombineRowSprite *)sprite8)->color = normalRowColor;
                    /* measured: field typing changes 8 normalized bytes in the full owner. */
                    ((FclCombineRowSprite *)fclSpriteEntry(id270_2))->color = *(FclDrawColor *)(sprite8 + 0x85);
                    normalLabelColor = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
                    sprite9 = fclSpriteEntry(rosterIndex12 + 0x297);
                    ((FclCombineRowSprite *)sprite9)->color = normalLabelColor;
                    /* measured: field typing changes 8 normalized bytes in the full owner. */
                    ((FclCombineRowSprite *)fclSpriteEntry(rosterIndex12 + 0x28B))->color = *(FclDrawColor *)(sprite9 + 0x85);
                    normalNumberColor = fclMakeDrawColor(0, 0, 0x66, 0xFF);
                    ((FclCombineRowSprite *)fclSpriteEntry(rosterIndex12 + 0x2A3))->color = normalNumberColor;
                    normalDigitColor = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
                    nmMesWindowSetNumberColor(work->f2BC, (s8)(rosterIndex12 + 0xC), normalDigitColor);
                    textColor7 = fclPackRgba(0xCC, 0xFF, 0xFF, 0xFF);
                }
                spriteValue = (f32) ((rosterIndex12 * 0x17) + 0x80);
                frFontExDrawTextDeferred((f32) 0x195, spriteValue, 43.0f, textColor7, 0, 2, (const char *)(iGpffffb440 + ((((DatPersonaRecord *)yListSlotEntry((s8)((work->f128 + 1)), rosterIndex12))->id) * 0x11)), 0, 0, D_00795E60);
            }
        }
        if ((((s8)(fclDrawGetState((u8 *)work->drawTask.handle))) < 0) || (((s8)(fclDrawGetState((u8 *)work->drawTask.handle))) > 5)) {
            if (D_008C027A[0] & 0x1000) {
                work->f11E = fclSubClamped(work->f11E, 1, 0, (((FclCombinePersonaListHeader *)yListSlotWork(0))->count) - 1, 2);
                sdkSndStartStream(0, 0, 0, 0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                work->f11E = fclAddClamped(work->f11E, 1, (((FclCombinePersonaListHeader *)yListSlotWork(0))->count) - 1, 0, 2);
                sdkSndStartStream(0, 0, 0, 0);
                return;
            }
            if (D_008C024E[0] & 0x40) {
                if ((work->f128 != work->f11E) && ((((FclCombineRowList *)yListSlotWork(0))->availability[work->f128][work->f11E]) > 0)) {
                    sdkSndStartStream(0, 0, 0, 1);
                    for (rosterIndex6 = 0; rosterIndex6 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex6++) {
                        position16 = fclMakeVec2((f32) 0x149, 128.0f);
                        firstSelection3 = (u16)((((DatPersonaRecord *)yListSlotEntry((s8)((work->f128 + 1)), rosterIndex6))->id));
                        slotByte = ((DatPersonaRecord *)yListSlotEntry(work->f128 + 1, rosterIndex6))->level;
                        fclCombineDrawPersonaRow(task, position16, work->f128, rosterIndex6, firstSelection3, slotByte, 3, 1, 1, 0xCC);
                    }
                    work->f2F9 = (s8) (work->f128 + 1);
                    work->f2FA = (s8) work->f11E;
                    work->f129 = (s8) work->f11E;
                    for (index = 0; index < 5; index++) {
                        work->f30C[index] = 0;
                    }
                    matchIndex2 = (s8)(fclCombineFindMatchIndex(task));
                    switch (matchIndex2) {            /* switch 3; irregular */
                    case 0:                         /* switch 3 */
                        personaRecord = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                        (((DatPersonaRecord *)personaRecord)->stats[0]) = (u8) ((((DatPersonaRecord *)personaRecord)->stats[0]) + 6);
                        personaRecord2 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                        (((DatPersonaRecord *)personaRecord2)->stats[1]) = (u8) ((((DatPersonaRecord *)personaRecord2)->stats[1]) + 6);
                        work->f30C[0] = 6;
                        work->f30C[1] = 6;
                        break;
                    case 1:                         /* switch 3 */
                        personaRecord3 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                        (((DatPersonaRecord *)personaRecord3)->stats[2]) = (u8) ((((DatPersonaRecord *)personaRecord3)->stats[2]) + 6);
                        personaRecord4 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                        (((DatPersonaRecord *)personaRecord4)->stats[3]) = (u8) ((((DatPersonaRecord *)personaRecord4)->stats[3]) + 6);
                        work->f30C[2] = 6;
                        work->f30C[3] = 6;
                        break;
                    case 2:                         /* switch 3 */
                        personaRecord5 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                        (((DatPersonaRecord *)personaRecord5)->stats[4]) = (u8) ((((DatPersonaRecord *)personaRecord5)->stats[4]) + 6);
                        personaRecord6 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                        (((DatPersonaRecord *)personaRecord6)->stats[0]) = (u8) ((((DatPersonaRecord *)personaRecord6)->stats[0]) + 6);
                        work->f30C[4] = 6;
                        work->f30C[0] = 6;
                        break;
                    case 3:                         /* switch 3 */
                        personaRecord7 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                        (((DatPersonaRecord *)personaRecord7)->stats[1]) = (u8) ((((DatPersonaRecord *)personaRecord7)->stats[1]) + 6);
                        personaRecord8 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                        (((DatPersonaRecord *)personaRecord8)->stats[2]) = (u8) ((((DatPersonaRecord *)personaRecord8)->stats[2]) + 6);
                        work->f30C[1] = 6;
                        work->f30C[2] = 6;
                        break;
                    }
                    fclDrawSetPlacementEx((u8 *)work->drawTask.handle, (s32)yListSlotEntry(work->f2F9, work->f2FA), 0, 0, 1);
                    personaModel3 = (s32)(fclDrawGetResource((u8 *)work->drawTask.handle));
                    shdPersonaSetChildDispCtlHandle((u8 *)personaModel3, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
                    shdPersonaEndSelection(fclDrawGetResource((u8 *)work->drawTask.handle), 1);
                    work->f1 = 0x81U;
                    for (rosterIndex5 = 0; rosterIndex5 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex5++) {
                        position17 = fclMakeVec2(16.0f, 128.0f);
                        fclCombinePartyRow(task, position17, (s8)rosterIndex5, ((u16 *)yListSlotEntry(0, rosterIndex5))[1], ((DatPersonaRecord *)yListSlotEntry(0, rosterIndex5))->level, 0, 1, (s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count);
                    }
                    position18 = fclMakeVec2(16.0f, 104.0f);
                    fclCombineDrawSlotFields(task, position18, 0, 1, 0, 0, 0);
                    position19 = fclMakeVec2((f32) 0x149, 104.0f);
                    fclCombineDrawSlotLabels(task, position19, 0, 1);
                    fclCombineLayoutFrame(task, 1, 1);
                    fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                    fclCombineFadePanelSprite(task, 0, 0);
                    fclCombineDrawStageBanner(task, 3, 0);
                    fclSpriteSetHidden((u8 *)(work->headerTask.handle), 1);
                    fclSpriteSetHidden((u8 *)(work->arrowTask.handle), 1);
                    return;
                }
            } else {
                if (D_008C024C[0] & 0x80) {
                    sdkSndStartStream(0, 1, 0, 3);
                    for (rosterIndex7 = 0; rosterIndex7 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex7++) {
                        position20 = fclMakeVec2((f32) 0x149, 128.0f);
                        firstSelection4 = (u16)((((DatPersonaRecord *)yListSlotEntry((s8)((work->f128 + 1)), rosterIndex7))->id));
                        slotByte = ((DatPersonaRecord *)yListSlotEntry(work->f128 + 1, rosterIndex7))->level;
                        fclCombineDrawPersonaRow(task, position20, work->f128, rosterIndex7, firstSelection4, slotByte, 0, 1, 1, 0xCC);
                        position21 = fclMakeVec2(16.0f, 128.0f);
                        fclCombinePartyRow(task, position21, (s8)rosterIndex7, ((u16 *)yListSlotEntry(0, rosterIndex7))[1], ((DatPersonaRecord *)yListSlotEntry(0, rosterIndex7))->level, 0, 1, (s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count);
                    }
                    position22 = fclMakeVec2(16.0f, 104.0f);
                    fclCombineDrawSlotFields(task, position22, 0, 1, 0, 0, 0);
                    position23 = fclMakeVec2((f32) 0x149, 104.0f);
                    fclCombineDrawSlotLabels(task, position23, 0, 1);
                    fclCombineLayoutFrame(task, 1, 1);
                    fclCombineFadeLabelSprites(task, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                    fclSpriteSetHidden((u8 *)(work->headerTask.handle), 1);
                    fclSpriteSetHidden((u8 *)(work->arrowTask.handle), 1);
                    work->f1 = 0x7FU;
                    return;
                }
                if (D_008C024E[0] & 0x20) {
                    fclCombineApplySlotState(task, (s8) work->f11E, 0, 0xFF);
                    work->f11E = work->f128;
                    fclCombineApplySlotState(task, work->f11E, 1, 0xFF);
                    sdkSndStartStream(0, 0, 0, 2);
                    fclCombineSlideInSlotSprites(task, 0x93, 0x94);
                    basePos = (FclVec2f *)D_00640C10;
                    position24 = fclMakeVec2(basePos->x, basePos->y);
                    position25 = fclMakeVec2(-380.0f, basePos->y);
                    fclCombineDrawPersonaCard(task, work->f128, *(FclVec2f *)&position24, *(FclVec2f *)&position25);
                    position26 = fclMakeVec2((f32) 0x149, 104.0f);
                    fclCombineDrawSlotLabels(task, position26, 0, 1);
                    for (rosterIndex8 = 0; rosterIndex8 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex8++) {
                        position27 = fclMakeVec2((f32) 0x149, 128.0f);
                        firstSelection5 = (u16)((((DatPersonaRecord *)yListSlotEntry((s8)((work->f128 + 1)), rosterIndex8))->id));
                        slotByte = ((DatPersonaRecord *)yListSlotEntry(work->f128 + 1, rosterIndex8))->level;
                        fclCombineDrawPersonaRow(task, position27, work->f128, rosterIndex8, firstSelection5, slotByte, 0, 1, 1, 0xCC);
                    }
                    fclCombineRefreshGridCells(task, 3);
                    work->f1 = 0x7BU;
                    return;
                }
            }
        }
        break;
    case 0x7F:                                      /* switch 1 */
        spriteAlpha2 = (u8)((((FclCombineRowSprite *)fclSpriteEntry(0x7C))->alpha));
        /* measured: field typing changes 12994 normalized bytes in the full owner. */
        menuWork = *(FclCombineMenu **)(task + 0x38);
        sprite10 = (u8 *)(fclSpriteEntry(0x7C));
        position41 = ((FclCombineRowSprite *)sprite10)->position;
        textColor2 = fclPackRgba(0xCC, 0xFF, 0xFF, spriteAlpha2);
        frFontExDrawTextDeferredOutB(111.0f + position41.x, position41.y, 43.0f, textColor2, 0, 2, (const char *)((iGpffffb440) + ((((DatPersonaRecord *)yListSlotEntry(0, menuWork->f128))->id) * 0x11)), 0, 0, D_00795E60, 0x15);
        if (((s16)(fclSpriteFlagBit((((FclCombineRowSprite *)fclSpriteEntry(0x270))->flags), 1))) != 1) {
            fclDrawSetPlacement((u8 *)work->drawTask.handle, (s32)yListSlotEntry(0, work->f11E), 0, 0);
            personaModel4 = (s32)(fclDrawGetResource((u8 *)work->drawTask.handle));
            shdPersonaSetChildDispCtlHandle((u8 *)personaModel4, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
            shdPersonaEndSelection(fclDrawGetResource((u8 *)work->drawTask.handle), 1);
            work->f1 = 0x80U;
            return;
        }
        break;
    case 0x80:                                      /* switch 1 */
        spriteAlpha3 = (u8)((((FclCombineRowSprite *)fclSpriteEntry(0x7C))->alpha));
        /* measured: field typing changes 12994 normalized bytes in the full owner. */
        menuWork2 = *(FclCombineMenu **)(task + 0x38);
        sprite11 = (u8 *)(fclSpriteEntry(0x7C));
        position42 = ((FclCombineRowSprite *)sprite11)->position;
        textColor3 = fclPackRgba(0xCC, 0xFF, 0xFF, spriteAlpha3);
        frFontExDrawTextDeferredOutB(111.0f + position42.x, position42.y, 43.0f, textColor3, 0, 2, (const char *)((iGpffffb440) + ((((DatPersonaRecord *)yListSlotEntry(0, menuWork2->f128))->id) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((((s8)(fclDrawGetState((u8 *)work->drawTask.handle))) < 0) || (((s8)(fclDrawGetState((u8 *)work->drawTask.handle))) > 5)) {
            for (rosterIndex9 = 0; rosterIndex9 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex9++) {
                position28 = fclMakeVec2((f32) 0x149, 128.0f);
                firstSelection6 = (u16)((((DatPersonaRecord *)yListSlotEntry((s8)((work->f128 + 1)), rosterIndex9))->id));
                slotByte = ((DatPersonaRecord *)yListSlotEntry(work->f128 + 1, rosterIndex9))->level;
                fclCombineDrawPersonaRow(task, position28, work->f128, rosterIndex9, firstSelection6, slotByte, 0, 0, 1, 0xCC);
                position29 = fclMakeVec2(16.0f, 128.0f);
                fclCombinePartyRow(task, position29, (s8)rosterIndex9, ((u16 *)yListSlotEntry(0, rosterIndex9))[1], ((DatPersonaRecord *)yListSlotEntry(0, rosterIndex9))->level, 0, 0, (s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count);
            }
            position30 = fclMakeVec2(16.0f, 104.0f);
            fclCombineDrawSlotFields(task, position30, 0, 0, 0, 0, 0);
            position31 = fclMakeVec2((f32) 0x149, 104.0f);
            fclCombineDrawSlotLabels(task, position31, 0, 0);
            fclCombineLayoutFrame(task, 1, 0);
            fclCombineFadeLabelSprites(task, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            work->f1 = 0x7EU;
            return;
        }
        break;
    case 0x81:                                      /* switch 1 */
        spriteAlpha4 = (u8)((((FclCombineRowSprite *)fclSpriteEntry(0x7C))->alpha));
        /* measured: field typing changes 12994 normalized bytes in the full owner. */
        menuWork3 = *(FclCombineMenu **)(task + 0x38);
        sprite12 = (u8 *)(fclSpriteEntry(0x7C));
        position43 = ((FclCombineRowSprite *)sprite12)->position;
        textColor4 = fclPackRgba(0xCC, 0xFF, 0xFF, spriteAlpha4);
        frFontExDrawTextDeferredOutB(111.0f + position43.x, position43.y, 43.0f, textColor4, 0, 2, (const char *)((iGpffffb440) + ((((DatPersonaRecord *)yListSlotEntry(0, menuWork3->f128))->id) * 0x11)), 0, 0, D_00795E60, 0x15);
        for (rosterIndex13 = 0; rosterIndex13 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex13++) {
            fclCombineSelectSlotEntry(task, (s8)(rosterIndex13), work->f128, work->f129, 0);
            if (rosterIndex13 == work->f11E) {
                textColor8 = fclPackRgba(0x2D, 0x2D, 0x2D, 0xFFU);
            } else {
                textColor8 = fclPackRgba(0xCC, 0xFF, 0xFF, 0xFFU);
            }
            firstSelection = (s8)(work->f128);
            if (firstSelection != rosterIndex13) {
                selectedRow = (s8)(firstSelection);
                if ((((FclCombineRowList *)yListSlotWork(0))->availability[selectedRow][rosterIndex13]) > 0) {
                    spriteValue = (f32) ((rosterIndex13 * 0x17) + 0x80);
                    frFontExDrawTextDeferred((f32) 0x195, spriteValue, 43.0f, textColor8, 0, 2, (const char *)(iGpffffb440 + ((((DatPersonaRecord *)yListSlotEntry((s8)((selectedRow + 1)), rosterIndex13))->id) * 0x11)), 0, 0, D_00795E60);
                }
            }
        }
        if (work->f122 == 2) {
            shdPersonaFillStateBlock(fclDrawGetResource((u8 *)work->drawTask.handle), work->f30C);
        }
        if (((s8)(fclDrawGetState((u8 *)work->drawTask.handle))) == 0xD) {
            if (shdPersonaIsSelectionActive(fclDrawGetResource((u8 *)work->drawTask.handle)) == 1) {
                shdPersonaStepSelectionCursor(fclDrawGetResource((u8 *)work->drawTask.handle));
            }
            if (D_008C024E[0] & 0x40) {
                fclCombinePlayCue(task, 0x1B, 1);
                work->f1 = 0x83U;
                sdkSndStartStream(0, 0, 0, 1);
                return;
            }
            if (D_008C024E[0] & 0x20) {
                if (shdPersonaIsSelectionActive(fclDrawGetResource((u8 *)work->drawTask.handle)) == 1) {
                    shdPersonaEndSelection(fclDrawGetResource((u8 *)work->drawTask.handle), 1);
                    fclDrawSetFlag((u8 *)work->drawTask.handle, 1);
                    return;
                }
                sdkSndStartStream(0, 0, 0, 2);
                work->f1 = 0x82U;
                fclDrawSetStateByte((u8 *)work->drawTask.handle, 0xB);
                fclCombineDrawStageBanner(task, 3, 1);
                fclCombineLayoutFrame(task, 1, 0);
                fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                work->f129 = -1;
                for (rosterIndex10 = 0; rosterIndex10 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex10++) {
                    position32 = fclMakeVec2(16.0f, 128.0f);
                    fclCombinePartyRow(task, position32, (s8)rosterIndex10, ((u16 *)yListSlotEntry(0, rosterIndex10))[1], ((DatPersonaRecord *)yListSlotEntry(0, rosterIndex10))->level, 0, 0, (s8)((FclCombinePersonaListHeader *)yListSlotWork(0))->count);
                    position33 = fclMakeVec2((f32) 0x149, 128.0f);
                    firstSelection7 = (u16)((((DatPersonaRecord *)yListSlotEntry((s8)((work->f128 + 1)), rosterIndex10))->id));
                    slotByte = ((DatPersonaRecord *)yListSlotEntry(work->f128 + 1, rosterIndex10))->level;
                    fclCombineDrawPersonaRow(task, position33, work->f128, rosterIndex10, firstSelection7, slotByte, 0, 0, 1, 0xCC);
                }
                position34 = fclMakeVec2(16.0f, 104.0f);
                fclCombineDrawSlotFields(task, position34, 0, 0, 0, 0, 0);
                position35 = fclMakeVec2((f32) 0x149, 104.0f);
                fclCombineDrawSlotLabels(task, position35, 0, 0);
                fclCombineFadeLabelSprites(task, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                fclCombineFadePanelSprite(task, 1, 0);
                for (index2 = 0; index2 < 5; index2++) {
                    personaState[index2] = 0;
                }
                shdPersonaFillStateBlock(fclDrawGetResource((u8 *)work->drawTask.handle), personaState);
                matchIndex4 = (s8)(fclCombineFindMatchIndex(task));
                switch (matchIndex4) {                 /* switch 4; irregular */
                case 0:                             /* switch 4 */
                    personaRecord9 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                    (((DatPersonaRecord *)personaRecord9)->stats[0]) = (u8) ((((DatPersonaRecord *)personaRecord9)->stats[0]) - 6);
                    personaRecord10 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                    (((DatPersonaRecord *)personaRecord10)->stats[1]) = (u8) ((((DatPersonaRecord *)personaRecord10)->stats[1]) - 6);
                    return;
                case 1:                             /* switch 4 */
                    personaRecord11 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                    (((DatPersonaRecord *)personaRecord11)->stats[2]) = (u8) ((((DatPersonaRecord *)personaRecord11)->stats[2]) - 6);
                    personaRecord12 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                    (((DatPersonaRecord *)personaRecord12)->stats[3]) = (u8) ((((DatPersonaRecord *)personaRecord12)->stats[3]) - 6);
                    return;
                case 2:                             /* switch 4 */
                    personaRecord13 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                    (((DatPersonaRecord *)personaRecord13)->stats[4]) = (u8) ((((DatPersonaRecord *)personaRecord13)->stats[4]) - 6);
                    personaRecord14 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                    (((DatPersonaRecord *)personaRecord14)->stats[0]) = (u8) ((((DatPersonaRecord *)personaRecord14)->stats[0]) - 6);
                    return;
                case 3:                             /* switch 4 */
                    personaRecord15 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                    (((DatPersonaRecord *)personaRecord15)->stats[1]) = (u8) ((((DatPersonaRecord *)personaRecord15)->stats[1]) - 6);
                    personaRecord16 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                    (((DatPersonaRecord *)personaRecord16)->stats[2]) = (u8) ((((DatPersonaRecord *)personaRecord16)->stats[2]) - 6);
                    return;
                }
            } else {
                if (D_008C024E[0] & 8) {
                    if (work->f122 != 2) {
                        sdkSndStartStream(0, 2, 0, 5);
                    }
                    work->f122 = fclAddClamped(work->f122, 1, 2, 0, 1);
                    ps = fclSpriteEntry(0x151);
                    position36 = fclMakeVec2((f32) ((work->f122 * 0x8E) + 0x6A), 16.0f);
                    fclSpriteStartPositionAt(0x151, (((FclCombineRowSprite *)ps)->position), (*(FclVec2f *)&position36), 1, 4, 0);
                    ps = fclSpriteEntry(0x2E0);
                    position37 = fclMakeVec2((f32) ((work->f122 * 0x8E) + 0x6A), 16.0f);
                    fclSpriteStartPositionAt(0x2E0, (((FclCombineRowSprite *)ps)->position), (*(FclVec2f *)&position37), 1, 4, 0);
                    for (index3 = 0; index3 < 5; index3++) {
                        personaState2[index3] = 0;
                    }
                    shdPersonaFillStateBlock(fclDrawGetResource((u8 *)work->drawTask.handle), personaState2);
                    previewSelection = (s8)(work->f122);
                    switch (previewSelection) {            /* switch 5; irregular */
                    case 0:                         /* switch 5 */
                        fclDrawSetPlacementEx((u8 *)work->drawTask.handle, (s32)yListSlotEntry(0, work->f128), 0, 0, 1);
                        break;
                    case 1:                         /* switch 5 */
                        fclDrawSetPlacementEx((u8 *)work->drawTask.handle, (s32)yListSlotEntry(0, work->f129), 0, 0, 1);
                        break;
                    case 2:                         /* switch 5 */
                        fclDrawSetPlacementEx((u8 *)work->drawTask.handle, (s32)yListSlotEntry(work->f2F9, work->f2FA), 0, 0, 1);
                        break;
                    }
                    personaModel5 = (s32)(fclDrawGetResource((u8 *)work->drawTask.handle));
                    shdPersonaSetChildDispCtlHandle((u8 *)personaModel5, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
                    return;
                }
                if (D_008C024E[0] & 4) {
                    if (work->f122 != 0) {
                        sdkSndStartStream(0, 2, 0, 5);
                    }
                    work->f122 = fclSubClamped(work->f122, 1, 0, 2, 1);
                    ps = fclSpriteEntry(0x151);
                    position38 = fclMakeVec2((f32) ((work->f122 * 0x8E) + 0x6A), 16.0f);
                    fclSpriteStartPositionAt(0x151, (((FclCombineRowSprite *)ps)->position), (*(FclVec2f *)&position38), 1, 4, 0);
                    ps = fclSpriteEntry(0x2E0);
                    position39 = fclMakeVec2((f32) ((work->f122 * 0x8E) + 0x6A), 16.0f);
                    fclSpriteStartPositionAt(0x2E0, (((FclCombineRowSprite *)ps)->position), (*(FclVec2f *)&position39), 1, 4, 0);
                    for (index4 = 0; index4 < 5; index4++) {
                        personaState3[index4] = 0;
                    }
                    shdPersonaFillStateBlock(fclDrawGetResource((u8 *)work->drawTask.handle), personaState3);
                    previewSelection2 = (s8)(work->f122);
                    switch (previewSelection2) {            /* switch 6; irregular */
                    case 0:                         /* switch 6 */
                        fclDrawSetPlacementEx((u8 *)work->drawTask.handle, (s32)yListSlotEntry(0, work->f128), 0, 0, 1);
                        break;
                    case 1:                         /* switch 6 */
                        fclDrawSetPlacementEx((u8 *)work->drawTask.handle, (s32)yListSlotEntry(0, work->f129), 0, 0, 1);
                        break;
                    case 2:                         /* switch 6 */
                        fclDrawSetPlacementEx((u8 *)work->drawTask.handle, (s32)yListSlotEntry(work->f2F9, work->f2FA), 0, 0, 1);
                        break;
                    }
                    personaModel6 = (s32)(fclDrawGetResource((u8 *)work->drawTask.handle));
                    shdPersonaSetChildDispCtlHandle((u8 *)personaModel6, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFFU));
                    return;
                }
                if (D_008C024E[0] & 0x80) {
                    if (shdPersonaIsSelectionActive(fclDrawGetResource((u8 *)work->drawTask.handle)) == 0) {
                        shdPersonaBeginSelection(fclDrawGetResource((u8 *)work->drawTask.handle));
                        fclDrawSetFlag((u8 *)work->drawTask.handle, 0);
                        return;
                    }
                    shdPersonaEndSelection(fclDrawGetResource((u8 *)work->drawTask.handle), 1);
                    fclDrawSetFlag((u8 *)work->drawTask.handle, 1);
                    return;
                }
            }
        }
        break;
    case 0x82:                                      /* switch 1 */
        spriteAlpha5 = (u8)((((FclCombineRowSprite *)fclSpriteEntry(0x7C))->alpha));
        /* measured: field typing changes 12994 normalized bytes in the full owner. */
        menuWork4 = *(FclCombineMenu **)(task + 0x38);
        sprite13 = (u8 *)(fclSpriteEntry(0x7C));
        position44 = ((FclCombineRowSprite *)sprite13)->position;
        textColor5 = fclPackRgba(0xCC, 0xFF, 0xFF, spriteAlpha5);
        frFontExDrawTextDeferredOutB(111.0f + position44.x, position44.y, 43.0f, textColor5, 0, 2, (const char *)((iGpffffb440) + ((((DatPersonaRecord *)yListSlotEntry(0, menuWork4->f128))->id) * 0x11)), 0, 0, D_00795E60, 0x15);
        for (rosterIndex14 = 0; rosterIndex14 < (datPersonaRosterCapacity() & 0xFFFF); rosterIndex14++) {
            fclCombineSelectSlotEntry(task, (s8)(rosterIndex14), work->f128, work->f129, 0);
            if (((s16)(fclSpriteFlagBit((((FclCombineRowSprite *)fclSpriteEntry((s16)((rosterIndex14 + 0x270))))->flags), 1))) == 0) {
                if (rosterIndex14 == work->f11E) {
                    textColor9 = fclPackRgba(0x2D, 0x2D, 0x2D, 0xFFU);
                } else {
                    textColor9 = fclPackRgba(0xCC, 0xFF, 0xFF, 0xFFU);
                }
                firstSelection2 = (s8)(work->f128);
                if (firstSelection2 != rosterIndex14) {
                    selectedRowAlt = (s8)(firstSelection2);
                    if ((((FclCombineRowList *)yListSlotWork(0))->availability[selectedRowAlt][rosterIndex14]) > 0) {
                        spriteValue = (f32)(rosterIndex14 * 0x17 + 0x80);
                        frFontExDrawTextDeferred((f32)0x195, spriteValue, 43.0f, textColor9, 0, 2, (const char *)(iGpffffb440 + ((u16 *)yListSlotEntry(selectedRowAlt + 1, rosterIndex14))[1] * 0x11), 0, 0, D_00795E60);
                    }
                }
            }
        }
        if (((s8)(fclDrawGetState((u8 *)work->drawTask.handle))) == 0xE) {
            fclSpriteSetHidden((u8 *)(work->headerTask.handle), 0);
            fclSpriteSetHidden((u8 *)(work->arrowTask.handle), 0);
            work->f1 = 0x7EU;
            return;
        }
        break;
    case 0x83:                                      /* switch 1 */
        if (nmMesWindowSlotStatus(work->fD) != 0) {
            nmMesWindowStepSlotRelease(work->fD);
            return;
        }
        if (nmMesWindowGetSlotState(work->fD) == 0) {
            datSetFlag(0x1306, 1);
            fclDrawSetStateByte((u8 *)work->drawTask.handle, 0xB);
            fclCombineDrawStageBanner(task, 3, 1);
            fclSpriteSetFlag(0x7C, 0, 1);
            fclSpriteSetFlag(0x228, 0, 1);
            fclSpriteSetFlag(0x1A2, 0, 1);
            fclSpriteSetFlag(0x25C, 0, 1);
            fclSpriteSetFlag(0x54, 0, 1);
            fclSpriteSetFlag(0x26A, 0, 1);
            fclSpriteSetFlag(0x26B, 0, 1);
            fclSpriteSetFlag(0x74, 0, 1);
            fclCombineFadePanelSprite(task, 1, 0);
            for (index5 = 0; index5 < 5; index5++) {
                personaState4[index5] = 0;
            }
            shdPersonaFillStateBlock(fclDrawGetResource((u8 *)work->drawTask.handle), personaState4);
            matchIndex3 = (s8)(fclCombineFindMatchIndex(task));
            switch (matchIndex3) {                    /* switch 7; irregular */
            case 0:                                 /* switch 7 */
                personaRecord17 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                (((DatPersonaRecord *)personaRecord17)->stats[0]) = (u8) ((((DatPersonaRecord *)personaRecord17)->stats[0]) - 6);
                personaRecord18 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                (((DatPersonaRecord *)personaRecord18)->stats[1]) = (u8) ((((DatPersonaRecord *)personaRecord18)->stats[1]) - 6);
                break;
            case 1:                                 /* switch 7 */
                personaRecord19 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                (((DatPersonaRecord *)personaRecord19)->stats[2]) = (u8) ((((DatPersonaRecord *)personaRecord19)->stats[2]) - 6);
                personaRecord20 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                (((DatPersonaRecord *)personaRecord20)->stats[3]) = (u8) ((((DatPersonaRecord *)personaRecord20)->stats[3]) - 6);
                break;
            case 2:                                 /* switch 7 */
                personaRecord21 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                (((DatPersonaRecord *)personaRecord21)->stats[4]) = (u8) ((((DatPersonaRecord *)personaRecord21)->stats[4]) - 6);
                personaRecord22 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                (((DatPersonaRecord *)personaRecord22)->stats[0]) = (u8) ((((DatPersonaRecord *)personaRecord22)->stats[0]) - 6);
                break;
            case 3:                                 /* switch 7 */
                personaRecord23 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                (((DatPersonaRecord *)personaRecord23)->stats[1]) = (u8) ((((DatPersonaRecord *)personaRecord23)->stats[1]) - 6);
                personaRecord24 = (u16 *)(yListSlotEntry(work->f2F9, work->f2FA));
                (((DatPersonaRecord *)personaRecord24)->stats[2]) = (u8) ((((DatPersonaRecord *)personaRecord24)->stats[2]) - 6);
                break;
            }
            tier = (s8)(fclCombineRollTier(task));
            matchIndex = (s8)(fclCombineFindMatchIndex(task));
            datStageRecord((u8 *)fclCombineFindMatchPtr(task), ((((s8)(tier)) << 8) | (((s8)(matchIndex)) | 0x30)) & 0xFFFF);
            datPersonaRemoveRosterMemberById((((DatPersonaRecord *)yListSlotEntry(0, work->f128))->id));
            datPersonaRemoveRosterMemberById((((DatPersonaRecord *)yListSlotEntry(0, work->f129))->id));
            fclCombineSlideInSlotSprites(task, 0x96, 0x94);
            work->f1 = 0x84U;
        } else {
            work->f1 = 0x81U;
        }
        nmMesWindowDestroySlot(work->fD);
        return;
    case 0x84:                                      /* switch 1 */
        if (((s8)(fclDrawGetState((u8 *)work->drawTask.handle))) == 0xE) {
            fclCombineLayoutDetailSprites(task, 0);
            fclSpriteSetHidden((u8 *)(work->headerTask.handle), 0);
            fclSpriteSetHidden((u8 *)(work->arrowTask.handle), 0);
            work->fB6 = 0;
            fclCombineDrawActionList(task);
            work->f0 = 0;
            work->f1 = 0x1BU;
            return;
        }
        break;
    case 0x85:                                      /* switch 1 */
        if (nmMesWindowSlotStatus(work->fD) != 0) {
            nmMesWindowStepSlotRelease(work->fD);
            return;
        }
        work->f1 = 0x86U;
        nmMesWindowDestroySlot(work->fD);
        memberCount = datPersonaCountValidMembers() & 0xFFFF;
        if (memberCount == (datPersonaRosterCapacity() & 0xFFFF)) {
            fclCombinePlayCue(task, 0x23, 0);
            work->f1 = 0x87U;
            return;
        }
        if (fclCombinePersonaInRoster((((DatPersonaRecord *)datStagedRecord())->id)) == 1) {
            fclCombinePlayCue(task, 0x27, 0);
            work->f1 = 0x87U;
            return;
        }
        fclCombinePlayCue(task, 0x1E, 1);
        return;
    case 0x86:                                      /* switch 1 */
        if (nmMesWindowSlotStatus(work->fD) != 0) {
            nmMesWindowStepSlotRelease(work->fD);
            return;
        }
        if (nmMesWindowGetSlotState(work->fD) == 0) {
            packedResult2 = datStagedId() & 0xFFFF;
            if ((((s8)(((packedResult2 >> 0xC) & 0xF))) >= ((s8)(((packedResult2 >> 4) & 0xF)))) && (datGetFlag(0x1307) == 0)) {
                work->outcome.signedValue = fclCombineFindRandomSkillIndex(task);
                skillPairIndex = work->outcome.signedValue;
                if (skillPairIndex == -1) {
                    datPersonaInsertRosterRecord((u8 *)datStagedRecord());
                    datSetFlag(0x1306, 0);
                    datSetFlag(0x1307, 0);
                    work->selectedIds[2] = 0x16B;
                    goto finishRosterFusionMessage;
                }
                skillPair = (u16 *)((u8 *)iGpffffb3ec + skillPairIndex * 4);
                work->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                sprintf(skillName, (const char *)&iGpffffa8a4, (const char *)func_00243840(*skillPair));
                nmMesWindowSetSlotString(work->fD, 0, &skillName);
                nmMesWindowSetSlotParam(work->fD, 0);
                nmMesWindowShowSlotRecord(work->fD, 0x24);
                nmMesWindowSetSlotFlag(work->fD, 0);
                nmMesWindowRequestRefresh();
                work->f1 = 0x88U;
                return;
            }
            datPersonaInsertRosterRecord((u8 *)datStagedRecord());
            datSetFlag(0x1306, 0);
            datSetFlag(0x1307, 0);
            work->selectedIds[2] = 0x16B;
            for (index6 = 0; index6 < 5; index6++) {
                personaState5[index6] = 0;
            }
            shdPersonaFillStateBlock(fclDrawGetResource((u8 *)work->drawTask.handle), personaState5);
            goto finishRosterFusionMessage;
        }
finishRosterFusionMessage:
        fclDrawSetStateByte((u8 *)work->drawTask.handle, 0xB);
        work->f1 = 0x84U;
        nmMesWindowDestroySlot(work->fD);
        return;
    case 0x88:                                      /* switch 1 */
        if (nmMesWindowSlotStatus(work->fD) != 0) {
            nmMesWindowStepSlotRelease(work->fD);
            return;
        }
        if (nmMesWindowGetSlotState(work->fD) == 0) {
            nmMesWindowDestroySlot(work->fD);
            work->f2D8 = 0;
            work->f1 = 0x89U;
            return;
        }
        nmMesWindowDestroySlot(work->fD);
        fclDrawSetStateByte((u8 *)work->drawTask.handle, 0xB);
        work->f1 = 0x84U;
        datPersonaInsertRosterRecord((u8 *)datStagedRecord());
        datSetFlag(0x1306, 0);
        datSetFlag(0x1307, 0);
        work->selectedIds[2] = 0x16B;
        return;
    case 0x89:                                      /* switch 1 */
        skillPair2 = (FclSkillPair *)iGpffffb3ec + work->outcome.signedValue;
        work->f2D8 = fclAddClamped(work->f2D8, 1, 0x28, 0, 1);
        if (work->f2D8 == 0x14) {
            shdPersonaReplaceSkill(fclDrawGetResource((u8 *)work->drawTask.handle), skillPair2->original, skillPair2->replacement);
            datPersonaReplaceSkill((u8 *)datStagedRecord(), (s16)skillPair2->original, skillPair2->replacement);
            sdkSndStartStream(1, 3, 3, 2);
        }
        if (work->f2D8 >= 0x28) {
            work->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            sprintf(skillName, (const char *)&iGpffffa8a4, (const char *)func_00243840(skillPair2->original));
            nmMesWindowSetSlotString(work->fD, 0, &skillName);
            sprintf(skillName, (const char *)&iGpffffa8a4, (const char *)func_00243840(skillPair2->replacement));
            nmMesWindowSetSlotString(work->fD, 1, &skillName);
            nmMesWindowShowSlotRecord(work->fD, 0x57);
            work->f1 = 0x87U;
            datPersonaInsertRosterRecord((u8 *)datStagedRecord());
            datSetFlag(0x1306, 0);
            datSetFlag(0x1307, 0);
            work->selectedIds[2] = 0x16B;
            return;
        }
        break;
    case 0x87:                                      /* switch 1 */
        if (nmMesWindowSlotStatus(work->fD) != 0) {
            nmMesWindowStepSlotRelease(work->fD);
            return;
        }
        fclDrawSetStateByte((u8 *)work->drawTask.handle, 0xB);
        work->f1 = 0x84U;
        nmMesWindowDestroySlot(work->fD);
        for (index7 = 0; index7 < 5; index7++) {
            personaState6[index7] = 0;
        }
        shdPersonaFillStateBlock(fclDrawGetResource((u8 *)work->drawTask.handle), personaState6);
        break;
    }
}
#undef FCL_COMBINE_GRID_ROW
#pragma pop
/* measured: same stack-lookup-table floor as fclCombineFindMatchIndex — retail loads
   tbl[i] via sll/addu($sp)/addiu(0x48)/lh ($v0); mwcc b210 folds the 0x48
   into the load displacement in every spelling (array-index nd 42,
   byte-offset arithmetic nd 42), shifting all following words by one. */
/* MATCHED wave 14: the stack-table INITIALIZER was the real defect, not the
   load form. A `s16 table[4] = {…}` initializer makes mwcc load the 4
   constants from a gp-relative pool (lh $a2,($gp) x4) instead of retail's
   four addiu/sh pairs; writing `table[0]=0xD; table[1]=0x35; …` as
   individual stores reproduces retail exactly (the sll/addu/sp/addiu(0x48)/
   lhu load shape then matches byte-for-byte). nd 95 -> 1 -> MATCH. Note the
   return type is u16* (returns the raw func_002e48a0 results), and the
   per-iteration args reload p[0x128]/p[0x129] with (s8) hunches. */
// Fcl combine match: when one material's code matches a table entry, returns the other material's record; else 0.
// FUN_00308CC0
u16 *fclCombineFindMatchPtr(u8 *task) {
    s16 table[4];
    s8 *p = ((s8*)((KwlnTask *)task)->work);
    s16 i;
    table[0] = 0xD;
    table[1] = 0x35;
    table[2] = 0x49;
    table[3] = 0x66;
    for (i = 0; i < 4; i++) {
        if (table[i] == ((u16 *)yListSlotEntry(0, p[0x128]))[1]) {
            return (u16 *)yListSlotEntry(0, p[0x129]);
        }
        if (table[i] == ((u16 *)yListSlotEntry(0, p[0x129]))[1]) {
            return (u16 *)yListSlotEntry(0, p[0x128]);
        }
    }
    return 0;
}
// Fcl combine roll: picks a tier 0-5 from a percentage roll against the cumulative thresholds in D_007490F8.
// FUN_00308DC0
s32 fclCombineRollTier(u8 *task)
{
    s16 i;
    s32 temp;
    s8 *p;

    temp = (u8)(RpRandom() % 100U);
    i = 0;
    p = D_007490F8;
    while (i < 6) {
        if (temp < p[i]) {
            return (s8)i;
        }
        i++;
    }
    return 5;
}
/* measured: retail loads the stack lookup table via sll/addu($sp)/addiu(0x48)
   then lh ($v0); mwcc b210 folds the 0x48 into the load displacement
   (sll/addu/lh 0x48($v0)) no matter the spelling — probed array-index,
   named pointer, byte-offset arithmetic, for-loop, initializer-list, and
   #pragma schedule on (nd 56); best nd 40. Same floor family as fclCombineApplyPackedResult. */
/* MATCHED wave 14: same fix as fclCombineFindMatchPtr — the table INITIALIZER was the
   defect. Individual stores `table[0]=0xD; …` (not the array initializer,
   which pulls the 4 constants from a gp pool) reproduce retail's addiu/sh
   pairs; the sll/addu/sp/addiu(0x48)/lh read immediately matches, and the
   loop/branch layout falls into place (nd 10 -> 1 benign padding -> MATCH).
   Key types: table is s16[4], p is the s8* work at arg0+0x38, table compare
   against func_002e48a0(0, p[0x128])[1] / [0x129] with (s8)i return. */
// Fcl combine match index: returns the index (0-3) of the matching code, or -1 when none matches.
// FUN_00308E50
s32 fclCombineFindMatchIndex(u8 *task) {
    s16 table[4];
    s8 *p = ((s8*)((KwlnTask *)task)->work);
    s16 i;
    table[0] = 0xD;
    table[1] = 0x35;
    table[2] = 0x49;
    table[3] = 0x66;
    for (i = 0; i < 4; i++) {
        if (table[i] == ((u16 *)yListSlotEntry(0, p[0x128]))[1]) return (s8)i;
        if (table[i] == ((u16 *)yListSlotEntry(0, p[0x129]))[1]) return (s8)i;
    }
    return -1;
}
/* floor (above marker kept clear for the verifier): the array-address
   sequence sll/addu(sp)/addiu(0x48) vs mwcc's sll/addiu/addu with swapped
   $v0/$v1 coloring — probed array, pointer, named-temp, separate-locals,
   byte-offset forms and schedule/opt_* pragmas; best nd 4 (scheduling). */
/* MATCHED: the four nibbles are s8 locals (retail re-extends each at use)
   extracted in n1, n2, n0, n3 order; the flag walk counter is s32 against a
   (u16) count; total is s16; packed is u16 built n0-first with no nibble
   masks; the switch is on n0, not n2.  fclCombineOtherHeroId returns u16 and
   datStageSetId takes u16 (no mask / sign-extension at either call site).
   The byte sum reads ((u8 *)&datStagedRecord()[0x13])[j] (addu, lbu 0x26)
   and packed is declared before j (register rotation). */
// Fcl combine packed result: applies the packed four-nibble result word (datStagedId) to the roster flags (cycling the 0x20/0x40/0x80 bits of members with bit 4) and, when flag 0x1306 is set and 0x1307 is not, either hands the working record to the other hero (when the nibble or total rule fires) or raises the two stat bytes chosen by n0 by D_00749350[n3], capped at 0x63.
// FUN_00308F40
void fclCombineApplyPackedResult(void) {
    u16 raw;
    s8 n0;
    s8 n1;
    s8 n2;
    s8 n3;
    s16 total;
    s32 i;
    u16 packed;
    s32 j;
    u8 *p;

    raw = datStagedId();
    n1 = (raw >> 4) & 0xF;
    n2 = (raw >> 8) & 0xF;
    n0 = raw & 0xF;
    n3 = (raw >> 12) & 0xF;
    total = 0;
    for (i = 0; i < (u16)datPersonaCountValidMembers(); i++) {
        if (datPersonaRosterSlotFlags(i) & 4) {
            if (datPersonaRosterSlotFlags(i) & 0x80) {
                *(u16 *)datPersonaRosterSlot(i) ^= 4;
                *(u16 *)datPersonaRosterSlot(i) ^= 0x20;
                *(u16 *)datPersonaRosterSlot(i) ^= 0x40;
                *(u16 *)datPersonaRosterSlot(i) ^= 0x80;
            } else if (datPersonaRosterSlotFlags(i) & 0x40) {
                *(u16 *)datPersonaRosterSlot(i) |= 0x80;
            } else if (datPersonaRosterSlotFlags(i) & 0x20) {
                *(u16 *)datPersonaRosterSlot(i) |= 0x40;
            } else {
                *(u16 *)datPersonaRosterSlot(i) |= 0x20;
            }
        }
    }
    if (datGetFlag(0x1307) == 0 && datGetFlag(0x1306) != 0) {
        n3 = fclAddClamped(n3, 1, 6, 0, 1);
        packed = n0 | (n1 << 4) | (n2 << 8) | (n3 << 12);
        for (j = 0; j < 5; j++) {
            total += ((u8 *)&((u16 *)datStagedRecord())[0x13])[j];
        }
        if (n3 >= n2 || n3 == 6) {
            p = (u8 *)datStagedRecord();
            datPersonaInitRecord(p, fclCombineOtherHeroId());
            datStageRecord((u8 *)datStagedRecord(), packed);
            datSetFlag(0x1307, 1);
            return;
        }
        if (total >= 0x1E) {
            p = (u8 *)datStagedRecord();
            datPersonaInitRecord(p, fclCombineOtherHeroId());
            datStageRecord((u8 *)datStagedRecord(), packed);
            datSetFlag(0x1307, 1);
            return;
        }
        datStageSetId(packed);
        switch (n0) {
        case 0:
            if (((u8 *)datStagedRecord())[0x1C] != 0x63) {
                ((u8 *)datStagedRecord())[0x26] =
                    fclAddClamped(((u8 *)datStagedRecord())[0x26],
                                 D_00749350[n3], 0x63, 0, 1);
            }
            if (((u8 *)datStagedRecord())[0x1D] != 0x63) {
                ((u8 *)datStagedRecord())[0x27] =
                    fclAddClamped(((u8 *)datStagedRecord())[0x27],
                                 D_00749350[n3], 0x63, 0, 1);
            }
            break;
        case 1:
            if (((u8 *)datStagedRecord())[0x1E] != 0x63) {
                ((u8 *)datStagedRecord())[0x28] =
                    fclAddClamped(((u8 *)datStagedRecord())[0x28],
                                 D_00749350[n3], 0x63, 0, 1);
            }
            if (((u8 *)datStagedRecord())[0x1F] != 0x63) {
                ((u8 *)datStagedRecord())[0x29] =
                    fclAddClamped(((u8 *)datStagedRecord())[0x29],
                                 D_00749350[n3], 0x63, 0, 1);
            }
            break;
        case 2:
            if (((u8 *)datStagedRecord())[0x20] != 0x63) {
                ((u8 *)datStagedRecord())[0x2A] =
                    fclAddClamped(((u8 *)datStagedRecord())[0x2A],
                                 D_00749350[n3], 0x63, 0, 1);
            }
            if (((u8 *)datStagedRecord())[0x1C] != 0x63) {
                ((u8 *)datStagedRecord())[0x26] =
                    fclAddClamped(((u8 *)datStagedRecord())[0x26],
                                 D_00749350[n3], 0x63, 0, 1);
            }
            break;
        case 3:
            if (((u8 *)datStagedRecord())[0x1D] != 0x63) {
                ((u8 *)datStagedRecord())[0x27] =
                    fclAddClamped(((u8 *)datStagedRecord())[0x27],
                                 D_00749350[n3], 0x63, 0, 1);
            }
            if (((u8 *)datStagedRecord())[0x1E] != 0x63) {
                ((u8 *)datStagedRecord())[0x28] =
                    fclAddClamped(((u8 *)datStagedRecord())[0x28],
                                 D_00749350[n3], 0x63, 0, 1);
            }
            break;
        }
    }
}

// Fcl combine other hero: returns the other hero persona id, 0xBA when the current one is 0xB3, else 0xB3.
// FUN_003095F0
u16 fclCombineOtherHeroId(void)
{
    if (((u16 *)datStagedRecord())[1] == 0xB3) {
        return 0xBA;
    }
    return 0xB3;
}

/* Return 1 when personaId is present in the valid party roster, otherwise 0. */
// FUN_00309630
s32 fclCombinePersonaInRoster(u16 personaId)
{
    s16 i;
    s32 key;

    i = 0;
    key = personaId;
    while (i < (u16)datPersonaCountValidMembers()) {
        if (key == ((DatPersonaRecord *)(datPersonaRosterSlot(i)))->id) {
            return 1;
        }
        i++;
    }
    return 0;
}
// Fcl combine random skill index: draws a random skill of the working persona and scans the skill-pair table (iGpffffb3ec) for it, drawing again after each table group ends, for up to four attempts. Returns the table index of the match, or -1.
// FUN_003096D0
s32 fclCombineFindRandomSkillIndex(u8 *task)
{
    u32 skillCount;
    u16 *skillPair;
    s32 emptyPairCount;
    s32 pairIndex;
    s16 randomSkillIndex;
    u16 originalSkill;

    pairIndex = 0;
    emptyPairCount = 0;
    while ((s16)emptyPairCount < 4) {
        skillCount = datPersonaCountSkills(datStagedRecord());
        randomSkillIndex = (s16)(RpRandom() % skillCount);
    scanSkillPairs:
        skillPair = &iGpffffb3ec[(s16)pairIndex * 2];
        originalSkill = skillPair[0];
        if (originalSkill == datPersonaGetSkillAt(datStagedRecord(), randomSkillIndex)) {
            return pairIndex;
        }
        pairIndex = (s16)(pairIndex + 1);
        if ((originalSkill == 0) || (skillPair[1] == 0)) {
            emptyPairCount = (s16)(emptyPairCount + 1);
        } else {
            goto scanSkillPairs;
        }
    }
    return -1;
}
/* measured: 6272B == retail window, zero differing words. The search helper
   below is inlined at each single-id test; the two 6-id scans in states
   0xCC/0xCE are written out with their own index declared before the outer
   counter, which gives retail's $t2/$t1 colouring (the helper form swaps them).
   The fade tail is a second inline so each expansion gets its own stack slots. */
/* Membership test over the work's slot list (count at +0x2DF, entries at
   +0x2DA). Retail inlines it at every use and re-reads the work pointer. */
/* Count and IDs are typed; only the measured task-work reload stays raw. */
static inline s32 fclCombineHasEntry(u8 *task, s8 id)
{
    /* measured: field typing changes 4535 normalized bytes in the full owner. */
    u8 *w = *(u8 **)(task + 0x38);
    s16 i;

    for (i = 0; i < ((FclCombineMenu *)w)->outcomeIdCount; i++) {
        if (((FclCombineMenu *)w)->outcomeIds[i] == id) {
            return 1;
        }
    }
    return 0;
}

/* Starts the 20-frame fade used when the combine result is confirmed. */
/* Only the measured pointer-valued sprite handle load remains byte-addressed. */
static inline void fclCombineStartFade(u8 *task)
{
    extern u8 *datScreenPointToWorldPosition(u8 *, s32, s32, f32);
    extern void cmbCardEffSetSpriteValue(s32, s32); /* lint: allow H011 -- caller's declared types kept; retyping to the definition is unmeasured */
    u8 *w = ((KwlnTask *)task)->work;
    FclVec3 pos;
    FclDrawColor color;

    datScreenPointToWorldPosition((u8 *)&pos, 0x140, 0xA5, 300.0f);
    color = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
    /* measured: field typing changes 1223 normalized bytes in the full owner. */
    cmbCardEffSpawnSprite(*(u8 **)(w + 0x308), pos, 0.0f, 0.0f, 0.0f, 1.0f, color, 0, -1);
    cmbCardEffSetSpriteValue(((FclCombineMenu *)w)->cardSpriteTask, 0x14);
    ((FclCombineMenu *)w)->f2D8 = 0;
}

/* measured: the loop-invariant pragma hoists the slot-search id and count out of
   every inlined search, as retail does. */
// Fcl combine menu result (state 0x0D): tallies the slot outcome, shows the result text and cues, then hands off to skill pick (sub-state 0xA0) or finish (state 0x0E, sub-state 0xD2); the fade ends the sequence.
// FUN_003097E0
#pragma opt_loop_invariants on
/* Historical whole-layout probe: 4469 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
void fclCombineMenuResult(u8 *task) {
    extern void fclCombineSetModel(s32, u16, s32);
    extern s32 cmbCardEffSpawnChild(u8 *, u16 *, s32); /* lint: allow H011 -- caller's declared types kept; retyping to the definition is unmeasured */
    extern s32 cmbCardEffCreateSprite(u8 *, void *, s32); /* lint: allow H011 -- caller's declared types kept; retyping to the definition is unmeasured */
    extern s8 *cmbCardEffWork(s32); /* lint: allow H011 -- caller's declared types kept; s8 return is dereferenced and retyping is unmeasured */
    extern s32 cmbCardEffSpriteFileLoaded(s32); /* lint: allow H011 -- caller's declared types kept; retyping to the definition is unmeasured */
    extern s32 fclCombineEventTaskCreate(u8 *, s8);
    extern void frFontExCopyString(void *, void *, s32);
    extern void fclCombineClearState(s32);
    extern s32 cmmCommunityName(s32);
    extern void fclDrawSetState(u8 *, s8);
    extern void fclCombineRollOutcomeList(u8 *);
    extern u8 D_00641B50[];
    u8 *p;
    u16 cls;
    s16 i;
    s16 j;
    s32 v;
    s16 k;
    char text[32];
    char text2[32];
    u16 buf[12];

    /* measured: field typing changes 4511 normalized bytes in the full owner. */
    p = *(u8 **)(task + 0x38);
    cls = ((DatPersonaRecord *)yListSlotEntry(((FclCombineMenu *)p)->f2F9, ((FclCombineMenu *)p)->f2FA))->id;
    switch (p[1]) {
    case 0xC5:
        datSetFlag(0x58, 0);
        datSetFlag(0x59, 0);
        datSetFlag(0x5A, 0);
        datSetFlag(0x5B, 0);
        datSetFlag(0x5C, 0);
        datSetFlag(0x5D, 0);
        datSetFlag(0x5E, 0);
        datSetFlag(0x5F, 0);
        datSetFlag(0x1450, 0);
        ((FclCombineMenu *)p)->unk26 = 0;
        ((FclCombineMenu *)p)->unk20 = 0;
        ((FclCombineMenu *)p)->unkE = 0;
        ((FclCombineMenu *)p)->unk21 = 0;
        ((FclCombineMenu *)p)->f2D8 = 0;
        fclSpriteSetFlag(0x84, 0, 1);
        fclSpriteSetFlag(0x85, 0, 1);
        fclSpriteSetFlag(0x1C6, 0, 1);
        for (i = 0; i < 0x30C; i++) {
            fclSpriteSetFlag(i, 0, 1);
        }
        fclCombineRollOutcomeList(task);
        fclCombineSetModel(((FclCombineMenu *)p)->detailTask.handle, cls, 0);
        /* measured: field typing changes 4196 normalized bytes in the full owner. */
        *(((s8 *)fclCombineGetWork(*(u8 **)(p + 0x254))) + 1) = 0;
        for (k = 0; k < 0xC; k++) {
            buf[k] = 0;
        }
        switch (((FclCombineMenu *)p)->sourceCount) {
        case 2:
            buf[0] = ((DatPersonaRecord *)yListSlotEntry(0, ((FclCombineMenu *)p)->f128))->id;
            buf[1] = ((DatPersonaRecord *)yListSlotEntry(0, ((FclCombineMenu *)p)->f11E))->id;
            ((FclCombineMenu *)p)->cardEffectTask = cmbCardEffSpawnChild(task, buf, 1);
            break;
        case 3:
            buf[0] = ((DatPersonaRecord *)yListSlotEntry(0, ((FclCombineMenu *)p)->f128))->id;
            buf[1] = ((DatPersonaRecord *)yListSlotEntry(0, ((FclCombineMenu *)p)->f129))->id;
            buf[2] = ((DatPersonaRecord *)yListSlotEntry(0, ((FclCombineMenu *)p)->f11E))->id;
            ((FclCombineMenu *)p)->cardEffectTask = cmbCardEffSpawnChild(task, buf, 2);
            break;
        case 4:
            buf[0] = ((DatPersonaRecord *)yListSlotEntry(((FclCombineMenu *)p)->f11E + 1, 0))->id;
            /* measured: field typing changes 3959 normalized bytes in the full owner. */
            buf[1] = ((DatPersonaRecord *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, 1))->id;
            /* measured: field typing changes 3959 normalized bytes in the full owner. */
            buf[2] = ((DatPersonaRecord *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, 2))->id;
            /* measured: field typing changes 3959 normalized bytes in the full owner. */
            buf[3] = ((DatPersonaRecord *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, 3))->id;
            ((FclCombineMenu *)p)->cardEffectTask = cmbCardEffSpawnChild(task, buf, 3);
            break;
        case 5:
            buf[0] = ((DatPersonaRecord *)yListSlotEntry(((FclCombineMenu *)p)->f11E + 1, 0))->id;
            /* measured: field typing changes 3824 normalized bytes in the full owner. */
            buf[1] = ((DatPersonaRecord *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, 1))->id;
            /* measured: field typing changes 3824 normalized bytes in the full owner. */
            buf[2] = ((DatPersonaRecord *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, 2))->id;
            /* measured: field typing changes 3824 normalized bytes in the full owner. */
            buf[3] = ((DatPersonaRecord *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, 3))->id;
            /* measured: field typing changes 3824 normalized bytes in the full owner. */
            buf[4] = ((DatPersonaRecord *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, 4))->id;
            ((FclCombineMenu *)p)->cardEffectTask = cmbCardEffSpawnChild(task, buf, 4);
            break;
        case 6:
            buf[0] = ((DatPersonaRecord *)yListSlotEntry(((FclCombineMenu *)p)->f11E + 1, 0))->id;
            /* measured: field typing changes 3661 normalized bytes in the full owner. */
            buf[1] = ((DatPersonaRecord *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, 1))->id;
            /* measured: field typing changes 3661 normalized bytes in the full owner. */
            buf[2] = ((DatPersonaRecord *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, 2))->id;
            /* measured: field typing changes 3661 normalized bytes in the full owner. */
            buf[3] = ((DatPersonaRecord *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, 3))->id;
            /* measured: field typing changes 3661 normalized bytes in the full owner. */
            buf[4] = ((DatPersonaRecord *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, 4))->id;
            /* measured: field typing changes 3661 normalized bytes in the full owner. */
            buf[5] = ((DatPersonaRecord *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, 5))->id;
            ((FclCombineMenu *)p)->cardEffectTask = cmbCardEffSpawnChild(task, buf, 5);
            break;
        case 7:
            for (i = 0; i < 0xC; i++) {
                buf[i] = ((DatPersonaRecord *)yListSlotEntry(0, i))->id;
            }
            ((FclCombineMenu *)p)->cardEffectTask = cmbCardEffSpawnChild(task, buf, 6);
            break;
        }
        if (datGetPersonaArcanaCommunityValue(cls) > 0) {
            ((FclCombineMenu *)p)->cardSpriteTask = cmbCardEffCreateSprite(task, D_00641B50, 7);
        }
        p[1] = 0xC6;
        break;
    case 0xC6:
        if (*cmbCardEffWork(((FclCombineMenu *)p)->cardEffectTask) != 0 &&
            (datGetPersonaArcanaCommunityValue(cls) <= 0 || cmbCardEffSpriteFileLoaded(((FclCombineMenu *)p)->cardSpriteTask) != 0)) {
            ((FclCombineMenu *)p)->eventTask = fclCombineEventTaskCreate(task, ((FclCombineMenu *)p)->sourceCount - 2);
            if (((FclCombineMenu *)p)->rareOutcome != 0) {
                datSetFlag(0x5C, 1);
            }
            p[1] = 0xC7;
        }
        break;
    case 0xC7:
        if (datGetFlag(0x5B) != 0) {
            if (((FclCombineMenu *)p)->rareOutcome == 1) {
                fclCombinePlayCue(task, 0x28, 0);
                p[1] = 0xC8;
                return;
            }
            if (((FclCombineMenu *)p)->rareOutcome == 2) {
                fclCombinePlayCue(task, 0x29, 0);
                p[1] = 0xC8;
                return;
            }
            if (fclCombineCheckIds(task) == 1 && fclCombineHasEntry(task, 0xC) == 1) {
                p[1] = 0xCB;
                ((FclCombineMenu *)p)->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                /* measured: field typing changes 3054 normalized bytes in the full owner. */
                nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x2A);
                /* measured: field typing changes 4458 normalized bytes in the full owner. */
                *(u16 *)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)) |= 4;
                return;
            }
            if (iGpffffb3d4[cls * 0xE + 0xD] == 0) {
                p[1] = 0xCC;
                return;
            }
            ((FclCombineMenu *)p)->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            sprintf(text, (const char *)&iGpffffa8a4, iGpffffb440 + cls * 0x11);
            /* measured: field typing changes 2963 normalized bytes in the full owner. */
            nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 1, text);
            /* measured: field typing changes 2963 normalized bytes in the full owner. */
            nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), iGpffffb3d4[cls * 0xE + 0xD] + 0x71);
            p[1] = 0xCA;
        }
        break;
    case 0xC8:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 2876 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
            return;
        }
        /* measured: field typing changes 2876 normalized bytes in the full owner. */
        nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
        if (fclCombineCheckIds(task) == 1 && fclCombineHasEntry(task, 0xC) == 1) {
            p[1] = 0xCB;
            /* measured: field typing changes 152 normalized bytes in the full owner. */
            *(s8 *)(p + 0xD) = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            /* measured: field typing changes 152 normalized bytes in the full owner. */
            nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x2A);
            /* measured: field typing changes 4458 normalized bytes in the full owner. */
            *(u16 *)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)) |= 4;
            return;
        }
        if (iGpffffb3d4[cls * 0xE + 0xD] == 0) {
            p[1] = 0xCC;
            return;
        }
        /* measured: field typing changes 2876 normalized bytes in the full owner. */
        *(s8 *)(p + 0xD) = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
        sprintf(text, (const char *)&iGpffffa8a4, iGpffffb440 + cls * 0x11);
        /* measured: field typing changes 2876 normalized bytes in the full owner. */
        nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 1, text);
        /* measured: field typing changes 2876 normalized bytes in the full owner. */
        nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), iGpffffb3d4[cls * 0xE + 0xD] + 0x71);
        p[1] = 0xCA;
        break;
    case 0xC9:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 2571 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
            return;
        }
        /* measured: field typing changes 2571 normalized bytes in the full owner. */
        nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
        p[1] = 0xC7;
        break;
    case 0xCA:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 2528 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
            return;
        }
        /* measured: field typing changes 2528 normalized bytes in the full owner. */
        nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
        p[1] = 0xCC;
        if (datGetFlag(0x5B) != 0) {
            p[1] = 0xCC;
        }
        break;
    case 0xCB:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 2467 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
            return;
        }
        /* measured: field typing changes 2467 normalized bytes in the full owner. */
        nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
        if (datGetFlag(0x5B) != 0) {
            if (iGpffffb3d4[cls * 0xE + 0xD] == 0) {
                p[1] = 0xCC;
                return;
            }
            /* measured: field typing changes 2467 normalized bytes in the full owner. */
            *(s8 *)(p + 0xD) = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            sprintf(text, (const char *)&iGpffffa8a4, iGpffffb440 + cls * 0x11);
            /* measured: field typing changes 2467 normalized bytes in the full owner. */
            nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 1, text);
            /* measured: field typing changes 2467 normalized bytes in the full owner. */
            nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), iGpffffb3d4[cls * 0xE + 0xD] + 0x71);
            p[1] = 0xCA;
        } else if (datGetFlag(0x5C) != 0) {
            p[1] = 0xC9;
        }
        p[1] = 0xC7;
        break;
    case 0xCC:
        if (datGetPersonaArcanaCommunityValue(cls) == 0) {
            p[1] = 0xCF;
            if (fclCombineCheckIds(task) == 1) {
                if (fclCombineHasEntry(task, 7) == 1) {
                    datSetFlag(0x59, 1);
                    *(s8 *)p = 0xC;
                    p[1] = 0xA0;
                    ((FclCombineMenu *)p)->unk13C = 1;
                    return;
                }
                if (fclCombineHasEntry(task, 0xD) == 1) {
                    datSetFlag(0x59, 1);
                    *(s8 *)p = 0xC;
                    p[1] = 0xA0;
                    ((FclCombineMenu *)p)->unk13C = 3;
                    return;
                }
                if (fclCombineHasEntry(task, 0xA) == 1) {
                    datSetFlag(0x59, 1);
                    *(s8 *)p = 0xC;
                    p[1] = 0xA0;
                }
                {
                    s16 n;
                    s16 m;
                    u8 *w;
                    s32 r;

                    for (m = 0; m < 6; m++) {
                        w = ((KwlnTask *)task)->work;
                        for (n = 0; n < ((FclCombineMenu *)w)->outcomeIdCount; n++) {
                            /* measured: field typing changes 1 normalized bytes in the full owner. */
                            if (*(s8 *)(w + n + 0x2DA) == (s8)(m + 1)) {
                                r = 1;
                                goto found_cc;
                            }
                        }
                        r = 0;
                    found_cc:
                        if (r == 1) {
                            datSetFlag(0x59, 1);
                            *(s8 *)p = 0xC;
                            p[1] = 0xA0;
                            break;
                        }
                    }
                }
                if (fclCombineHasEntry(task, 9) == 1) {
                    datSetFlag(0x59, 1);
                    *(s8 *)p = 0xC;
                    p[1] = 0xA0;
                }
            }
        } else {
            ((FclCombineMenu *)p)->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            /* measured: field typing changes 1705 normalized bytes in the full owner. */
            nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 0,
                          /* measured: field typing changes 4458 normalized bytes in the full owner. */
                          iGpffffb44c + datPersonaGetArcana(((DatPersonaRecord *)yListSlotEntry(*(s8 *)(p + 0x2F9),
                                                                             /* measured: field typing changes 4458 normalized bytes in the full owner. */
                                                                             *(s8 *)(p + 0x2FA)))->id) * 0x15);
            sprintf(text, (const char *)&iGpffffa8a4, iGpffffb440 + cls * 0x11);
            /* measured: field typing changes 1705 normalized bytes in the full owner. */
            nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 1, text);
            /* measured: field typing changes 1705 normalized bytes in the full owner. */
            nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x3A);
            p[1] = 0xCD;
        }
        break;
    case 0xCD:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 1579 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
            return;
        }
        /* measured: field typing changes 1579 normalized bytes in the full owner. */
        nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
        if (fclCombineHasEntry(task, 8) == 1) {
            v = cmmTopCommunityOfArcana(iGpffffb3d4[cls * 0xE + 2]);
            /* measured: field typing changes 4510/4513 normalized bytes in the full owner. */
            ((FclCombineMenu *)p)->unk10 = cmmCommunityExpRemaining(v, yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)), 1);
            if (fclCombineCheckIds(task) == 1) {
                /* measured: field typing changes 4549 normalized bytes in the full owner. */
                *(s8 *)(p + 0xD) = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                sprintf(text, (const char *)&iGpffffa8a4, cmmCommunityName(cmmTopCommunityOfArcana(iGpffffb3d4[cls * 0xE + 2])));
                frFontExCopyString(text, text2, 0x20);
                /* measured: field typing changes 4549 normalized bytes in the full owner. */
                nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 0, text2);
                sprintf(text, (const char *)&iGpffffa8a4, iGpffffb440 + cls * 0x11);
                /* measured: field typing changes 4549 normalized bytes in the full owner. */
                nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 1, text);
                /* measured: field typing changes 4549 normalized bytes in the full owner. */
                nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x55);
                ((FclCombineMenu *)p)->unk21 = 1;
                p[1] = 0xD0;
                return;
            }
            fclCombineClearState(((FclCombineMenu *)p)->detailTask.handle);
            datSetFlag(0x59, 1);
            fclCombineStartFade(task);
            p[1] = 0xD1;
        } else {
            /* measured: field typing changes 4458 normalized bytes in the full owner. */
            ((FclCombineMenu *)p)->unk10 = cmmCommunityExpRemaining(cmmTopCommunityOfArcana(iGpffffb3d4[cls * 0xE + 2]), yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)), 0);
            fclCombineClearState(((FclCombineMenu *)p)->detailTask.handle);
            datSetFlag(0x59, 1);
            fclCombineStartFade(task);
            p[1] = 0xD1;
        }
        break;
    case 0xCE:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 946 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
            return;
        }
        /* measured: field typing changes 946 normalized bytes in the full owner. */
        nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
        p[1] = 0xCF;
        if (fclCombineCheckIds(task) == 1) {
            if (fclCombineHasEntry(task, 7) == 1) {
                datSetFlag(0x59, 1);
                *(s8 *)p = 0xC;
                p[1] = 0xA0;
                ((FclCombineMenu *)p)->unk13C = 1;
                return;
            }
            if (fclCombineHasEntry(task, 0xD) == 1) {
                datSetFlag(0x59, 1);
                *(s8 *)p = 0xC;
                p[1] = 0xA0;
                ((FclCombineMenu *)p)->unk13C = 3;
                return;
            }
            if (fclCombineHasEntry(task, 0xA) == 1) {
                datSetFlag(0x59, 1);
                *(s8 *)p = 0xC;
                p[1] = 0xA0;
            }
            {
                s16 n;
                s16 m;
                u8 *w;
                s32 r;

                for (m = 0; m < 6; m++) {
                    w = ((KwlnTask *)task)->work;
                    for (n = 0; n < ((FclCombineMenu *)w)->outcomeIdCount; n++) {
                        /* measured: field typing changes 1 normalized bytes in the full owner. */
                        if (*(s8 *)(w + n + 0x2DA) == (s8)(m + 1)) {
                            r = 1;
                            goto found_ce;
                        }
                    }
                    r = 0;
                found_ce:
                    if (r == 1) {
                        datSetFlag(0x59, 1);
                        *(s8 *)p = 0xC;
                        p[1] = 0xA0;
                        break;
                    }
                }
            }
            if (fclCombineHasEntry(task, 9) == 1) {
                datSetFlag(0x59, 1);
                *(s8 *)p = 0xC;
                p[1] = 0xA0;
            }
        }
        break;
    case 0xCF:
        datSetFlag(0x59, 1);
        datSetFlag(0x5D, 1);
        datSetFlag(0x5F, 1);
        *(s8 *)p = 0xE;
        p[1] = 0xD2;
        fclDrawSetState((u8 *)((FclCombineMenu *)p)->drawTask.handle, 0);
        break;
    case 0xD0:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 318 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
            return;
        }
        /* measured: field typing changes 318 normalized bytes in the full owner. */
        nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
        fclCombineClearState(((FclCombineMenu *)p)->detailTask.handle);
        datSetFlag(0x59, 1);
        fclCombineStartFade(task);
        p[1] = 0xD1;
        break;
    case 0xD1:
        /* measured: field typing changes 29 normalized bytes in the full owner. */
        ((FclCombineMenu *)p)->f2D8 = fclAddClamped(*(s16 *)(p + 0x2D8), 1, 0x32, 0, 1);
        /* measured: field typing changes 163 normalized bytes in the full owner. */
        if (*(s16 *)(p + 0x2D8) == 0x14) {
            sdkSndStartStream(1, 0, 4, 5);
        }
        /* measured: field typing changes 32 normalized bytes in the full owner. */
        if ((s8)((FclCombineModelWork *)fclCombineGetWork(((FclCombineMenu *)p)->detailTask.task))->cleared == 4 && *(s16 *)(p + 0x2D8) >= 0x14) {
            *(s8 *)p = 0xC;
            p[1] = 0xA0;
        }
        break;
    }
}
#pragma opt_loop_invariants reset

/* MATCHED: switch on the state byte (C2/C3/C4) with s16 loop counters;
   colours are FclDrawColor struct returns copied whole to te+0x85 (lbu x4,
   sb x4); the D_00640D78 pair is read through a named FclVec2f base (lui/
   addiu base then lwc1 0/4); the flag at p+0x13A is s8; the scroll loop
   declares k before e and keeps lim as s32; the 0xD store is re-read as
   *(s8 *)(p + 0xD) for func_002badc0 (b210 forwards it after the lh). */
// Fcl combine menu material grid (state 0x09): scrollable six-row list. 0xC2 builds the rows, 0xC3 polls the pad (0x40 selects a row, 0x20 leaves to sub-state 0x1A, the scroll calls page the list), 0xC4 waits for the dialog.
// FUN_0030B060
/* Historical whole-layout probe: 1243 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
void fclCombineMenuMaterialGrid(u8 *task)
{
    u8 *p;
    u8 kind;
    s16 i;
    s16 j;
    s16 k;
    s16 e;
    s32 lim;
    FclVec2 v0;
    FclVec2 v1;
    FclVec2 v2;
    FclVec2 v3;
    FclDrawColor c0;
    FclDrawColor c1;
    FclDrawColor c2;
    FclDrawColor c3;
    u8 *te;
    FclVec2f *base;

    p = ((KwlnTask *)task)->work;
    kind = *(p + 1);
    switch (kind) {
    case 0xC2:
        ((FclCombineMenu *)p)->unk120 = 0;
        ((FclCombineMenu *)p)->f11E = 0;
        fclCombineSlideInSlotSprites(task, 0x97, 0x96);
        for (i = 0; i < 8; i++) {
            fclSpriteSetFlag((s16)(i + 0x179), 0, 1);
        }
        for (j = 0; j < 6; j++) {
            v0 = fclMakeVec2(26.0f, (f32)(j * 0x22 + 0x57));
            fclCombineDrawListRow(task, (s8)j, v0, (s16)(j + 0x179), (s16)(j * 2 + 2), 0);
        }
        c0 = fclMakeDrawColor(0xC6, 0xEE, 1, 0xFF);
        /* measured: field typing changes 1217 normalized bytes in the full owner. */
        te = fclSpriteEntry((s16)(*(s16 *)(p + 0x11E) * 2 + 500));
        ((FclCombineRowSprite *)te)->color = c0;
        c1 = fclMakeDrawColor(0xC6, 0xEE, 1, 0xFF);
        /* measured: field typing changes 1217 normalized bytes in the full owner. */
        te = fclSpriteEntry((s16)(*(s16 *)(p + 0x11E) * 2 + 501));
        ((FclCombineRowSprite *)te)->color = c1;
        c2 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        /* measured: field typing changes 1219 normalized bytes in the full owner. */
        te = fclSpriteEntry((s16)(*(s16 *)(p + 0x11E) + 0x179));
        ((FclCombineRowSprite *)te)->color = c2;
        c3 = fclMakeDrawColor(0x92, 0xC8, 7, 0xFF);
        /* measured: field typing changes 1219 normalized bytes in the full owner. */
        te = fclSpriteEntry((s16)(*(s16 *)(p + 0x120) + 0x2FB));
        ((FclCombineRowSprite *)te)->color = c3;
        base = (FclVec2f *)D_00640D78;
        v1 = fclMakeVec2(base->x, base->y);
        fclCombineDrawSlotFrames(task, v1, 1, 0);
        ((FclCombineMenu *)p)->unk124 = 0x428F0000;
        *(p + 1) = 0xC3;
        break;
    case 0xC3:
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(500))->flags, 1) != 1) {
            if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(502))->flags, 1) != 1) {
                if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(504))->flags, 1) != 1) {
                    if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(506))->flags, 1) != 1) {
                        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(508))->flags, 1) != 1) {
                            if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(510))->flags, 1) != 1) {
                                if ((D_008C0276[0] & 0x1000) && (((FclCombineMenu *)p)->unk13A == 0)) {
                                    fclCombineMoveGridCursor(task, 5);
                                    return;
                                }
                                if (D_008C027A[0] & 0x1000) {
                                    fclCombineMoveGridCursor(task, 1);
                                    return;
                                }
                                if ((D_008C0276[0] & 0x4000) && (((FclCombineMenu *)p)->unk13A == 0)) {
                                    fclCombineMoveGridCursor(task, 4);
                                    return;
                                }
                                if (D_008C027A[0] & 0x4000) {
                                    fclCombineMoveGridCursor(task, 0);
                                    return;
                                }
                                if (D_008C027A[0] & 0x8000) {
                                    fclCombineMoveGridCursor(task, 3);
                                    return;
                                }
                                if (D_008C027A[0] & 0x2000) {
                                    fclCombineMoveGridCursor(task, 2);
                                    return;
                                }
                                if (D_008C024E[0] & 0x40) {
                                    sdkSndStartStream(0, 0, 0, 1);
((FclCombineMenu *)p)->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                                    /* measured: field typing changes 368 normalized bytes in the full owner. */
                                    nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), ((FclCombineMenu *)p)->f11E + 0x58);
                                    *(p + 1) = 0xC4;
                                } else if (D_008C024E[0] & 0x20) {
                                    sdkSndStartStream(0, 0, 0, 2);
                                    fclCombineSlideInSlotSprites(task, 0x96, 0x97);
                                    base = (FclVec2f *)D_00640D78;
                                    v2 = fclMakeVec2(base->x, base->y);
                                    fclCombineDrawSlotFrames(task, v2, 1, 1);
                                    e = ((FclCombineMenu *)p)->f11E - ((FclCombineMenu *)p)->unk120;
                                    k = 0;
                                    lim = e + 6;
                                    for (; e < lim; e++, k++) {
                                        v3 = fclMakeVec2(26.0f, (f32)(k * 0x22 + 0x57));
                                        fclCombineDrawListRow(task, (s8)k, v3, (s16)(e + 0x179), (s16)((5 - k) * 2), 1);
                                    }
                                    fclCombineLayoutTransition(task, 0);
                                    *p = 0;
                                    *(p + 1) = 0x1A;
                                }
                                *(p + 0x13A) = 0;
                                return;
                            }
                        }
                    }
                }
            }
        }
        break;
    case 0xC4:
        if (nmMesWindowSlotStatus((s8)*(p + 0xD)) != 0) {
            nmMesWindowStepSlotRelease((s8)*(p + 0xD));
        } else {
            nmMesWindowDestroySlot((s8)*(p + 0xD));
            *(p + 1) = 0xC3;
        }
        break;
    }
}

/* MATCHED: colours are FclDrawColor struct returns copied whole (the
   501 -> 500 copy is a struct copy between the two elements); the flag
   words are read directly (b210 CSEs them where retail does); case 0 tests
   datCategoryRank(1) >= 3 && !flag 0x96F for the 0x70 arm; *(s8 *)te is the
   second fclCombineDrawListRow argument. The row loop derives the second byte as
   &D_00882FB0[j * 2] + 1: that second use of j is what makes b210
   re-extend j at the top of the body instead of reusing the test's copy. */
// Fcl combine menu option pick (state 0x0A): lists the option rows (kinds 0-3 and 0xB), shows the selected kind's message on select (0x40), and returns to state 0 on cancel (0x20).
// FUN_0030B7B0
/* Historical whole-layout probe: 2197 normalized bytes differed (2026-10-18).
   Access-site typing now isolates the measured exceptions and packed tables below. */
void fclCombineMenuOptionPick(u8 *task) {
    u8 *p;
    u8 kind;
    s16 i;
    s16 j;
    FclVec2 v0;
    FclVec2 v1;
    FclVec2 v2;
    FclVec2 v3;
    FclVec2 v4;
    FclVec2 v5;
    FclDrawColor c0;
    FclDrawColor c1;
    FclDrawColor c2;
    FclDrawColor c3;
    FclDrawColor c4;
    FclDrawColor c5;
    FclDrawColor c6;
    u8 *te;
    u8 *te2;
    u8 *p501;
    u8 *p500;
    u8 *row;
    s8 sidx;
    s8 t;

    p = ((KwlnTask *)task)->work;
    kind = *(p + 1);
    switch (kind) {
    case 0xC2:
        fclCombineSlideInSlotSprites(task, 0x97, 0x96);
        ((FclCombineMenu *)p)->f11E = 0;
        *(p + 0x139) = 0;
        v0 = fclMakeVec2(26.0f, 87.0f);
        fclCombineDrawListRow(task, 0, v0, 0x168, 2, 0);
        D_00882FB0[((FclCombineMenu *)p)->unk139 * 2] = 0;
        D_00882FB1[((FclCombineMenu *)p)->unk139 * 2] = 0;
        ((FclCombineMenu *)p)->unk139 += 1;
        v1 = fclMakeVec2(26.0f, (f32)(((FclCombineMenu *)p)->unk139 * 0x22 + 0x57));
        fclCombineDrawListRow(task, 1, v1, 0x174, 4, 0);
        /* measured: field typing changes 2006 normalized bytes in the full owner. */
        D_00882FB0[*(s8 *)(p + 0x139) * 2] = 1;
        /* measured: field typing changes 2006 normalized bytes in the full owner. */
        D_00882FB1[*(s8 *)(p + 0x139) * 2] = 0xC;
        /* measured: field typing changes 172 normalized bytes in the full owner. */
        *(s8 *)(p + 0x139) += 1;
        /* measured: field typing changes 174 normalized bytes in the full owner. */
        v2 = fclMakeVec2(26.0f, (f32)(*(s8 *)(p + 0x139) * 0x22 + 0x57));
        fclCombineDrawListRow(task, 2, v2, 0x170, 6, 0);
        /* measured: field typing changes 2006 normalized bytes in the full owner. */
        D_00882FB0[*(s8 *)(p + 0x139) * 2] = 2;
        /* measured: field typing changes 2006 normalized bytes in the full owner. */
        D_00882FB1[*(s8 *)(p + 0x139) * 2] = 8;
        /* measured: field typing changes 293 normalized bytes in the full owner. */
        *(s8 *)(p + 0x139) += 1;
        /* measured: field typing changes 295 normalized bytes in the full owner. */
        v3 = fclMakeVec2(26.0f, (f32)(*(s8 *)(p + 0x139) * 0x22 + 0x57));
        fclCombineDrawListRow(task, 3, v3, 0x171, 8, 0);
        /* measured: field typing changes 2006 normalized bytes in the full owner. */
        D_00882FB0[*(s8 *)(p + 0x139) * 2] = 3;
        /* measured: field typing changes 2006 normalized bytes in the full owner. */
        D_00882FB1[*(s8 *)(p + 0x139) * 2] = 9;
        /* measured: field typing changes 2003 normalized bytes in the full owner. */
        *(s8 *)(p + 0x139) += 1;
        if (datGetFlag(0x1305) != 0) {
            /* measured: field typing changes 2005 normalized bytes in the full owner. */
            v4 = fclMakeVec2(26.0f, (f32)(*(s8 *)(p + 0x139) * 0x22 + 0x57));
            fclCombineDrawListRow(task, 0xB, v4, 0x173, 0xA, 0);
            /* measured: field typing changes 2006 normalized bytes in the full owner. */
            D_00882FB0[*(s8 *)(p + 0x139) * 2] = 0xB;
            /* measured: field typing changes 2006 normalized bytes in the full owner. */
            D_00882FB1[*(s8 *)(p + 0x139) * 2] = 0xB;
            /* measured: field typing changes 2003 normalized bytes in the full owner. */
            *(s8 *)(p + 0x139) += 1;
        }
        /* measured: field typing changes 2189 normalized bytes in the full owner. */
        for (j = 0; j < *(s8 *)(p + 0x139); j++) {
            te = &D_00882FB0[j * 2];
            c0 = fclMakeDrawColor(0, 0, 0x66, 0xFF);
            p501 = fclSpriteEntry((s16)(*(s8 *)te * 2 + 501));
            ((FclCombineRowSprite *)p501)->color = c0;
            p500 = fclSpriteEntry((s16)(*(s8 *)te * 2 + 500));
            /* measured: field typing changes 8 normalized bytes in the full owner. */
            ((FclCombineRowSprite *)p500)->color = *(FclDrawColor *)(p501 + 0x85);
            row = &D_00882FB0[j * 2] + 1;
            c1 = fclMakeDrawColor(0xCC, 0xFF, 0xFF, 0xFF);
            te2 = fclSpriteEntry((s16)(*(s8 *)row + 0x168));
            ((FclCombineRowSprite *)te2)->color = c1;
            if (*(s8 *)te == 0xB && datGetFlag(0x1308) == 0) {
                c2 = fclMakeDrawColor(0xFF, 0xCC, 0xFF, 0xFF);
                te2 = fclSpriteEntry((s16)(*(s8 *)row + 0x168));
                ((FclCombineRowSprite *)te2)->color = c2;
            }
        }
        c3 = fclMakeDrawColor(0xC6, 0xEE, 1, 0xFF);
        te = fclSpriteEntry(500);
        ((FclCombineRowSprite *)te)->color = c3;
        c4 = fclMakeDrawColor(0xC6, 0xEE, 1, 0xFF);
        te = fclSpriteEntry(501);
        ((FclCombineRowSprite *)te)->color = c4;
        c5 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        te = fclSpriteEntry(0x168);
        ((FclCombineRowSprite *)te)->color = c5;
        c6 = fclMakeDrawColor(0x92, 0xC8, 7, 0xFF);
        /* measured: field typing changes 2178 normalized bytes in the full owner. Raw table access uses interior aliases into an interleaved two-byte choice table. */
        te = fclSpriteEntry((s16)(*(s8 *)(D_00882FB0 + *(s16 *)(p + 0x11E) * 2) + 0x2FB));
        ((FclCombineRowSprite *)te)->color = c6;
        if (((FclCombineMenu *)p)->unk138 > 0) {
            fclCombineDrawDetailFrame(task, 0);
        }
        *(p + 1) = 0xC3;
        break;
    case 0xC3:
        if ((s16)fclSpriteFlagBit(
                /* measured: field typing changes 2124 normalized bytes in the full owner. Raw table access uses interior aliases into an interleaved two-byte choice table. */
                ((FclCombineRowSprite *)fclSpriteEntry((s16)(*(s8 *)(D_00882FAE + *(s8 *)(p + 0x139) * 2) * 2 + 500)))->flags,
                1) != 1) {
            if ((D_008C0276[0] & 0x1000) && (((FclCombineMenu *)p)->unk13A == 0)) {
                fclCombineMoveChoiceCursor(task, 5, D_00882FB0);
                return;
            }
            if (D_008C027A[0] & 0x1000) {
                fclCombineMoveChoiceCursor(task, 1, D_00882FB0);
                return;
            }
            if ((D_008C0276[0] & 0x4000) && (((FclCombineMenu *)p)->unk13A == 0)) {
                fclCombineMoveChoiceCursor(task, 4, D_00882FB0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                fclCombineMoveChoiceCursor(task, 0, D_00882FB0);
                return;
            }
            if (D_008C024E[0] & 0x40) {
                sdkSndStartStream(0, 0, 0, 1);
                t = D_00882FB0[((FclCombineMenu *)p)->f11E * 2];
                switch (t) {
                case 0:
                    *(p + 0xD) = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                    if ((fclCalendarMonth() & 0xFF) == 3 && (fclCalendarDay() & 0xFF) >= 0x14 &&
                        (fclCalendarDay() & 0xFF) < 0x20) {
                        nmMesWindowShowSlotRecord((s8)*(p + 0xD), 0x6F);
                    } else if ((s16)datCategoryRank(1) >= 3 && datGetFlag(0x96F) == 0) {
                        nmMesWindowShowSlotRecord((s8)*(p + 0xD), 0x70);
                    } else {
                        nmMesWindowShowSlotRecord((s8)*(p + 0xD), (cmmCommunityRecordValue(0x14) & 0xFFFF) + 0x64);
                    }
                    break;
                case 1:
                    sidx = (s8)(10.0f * datGetAverageRecordScore());
                    te = D_006417E0 + ((fclCalendarMonth() & 0xFF) - 1) * 0xB;
                    *(p + 0xD) = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                    nmMesWindowShowSlotRecord(((FclCombineMenu *)p)->fD, ((s8 *)te)[sidx] + 2);
                    break;
                case 2:
                    *(p + 0xD) = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                    nmMesWindowShowSlotRecord(((FclCombineMenu *)p)->fD, 0x61);
                    break;
                case 3:
                    *(p + 0xD) = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                    nmMesWindowShowSlotRecord(((FclCombineMenu *)p)->fD, 0x62);
                    break;
                case 11:
                    datSetFlag(0x1308, 1);
                    *(p + 0xD) = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                    nmMesWindowShowSlotRecord(((FclCombineMenu *)p)->fD, 0x63);
                    if (((FclCombineMenu *)p)->unk138 == 0) {
                        fclCombineDrawDetailFrame(task, 1);
                    }
                    break;
                }
                *(p + 1) = 0xC4;
            } else if (D_008C024E[0] & 0x20) {
                sdkSndStartStream(0, 0, 0, 2);
                for (i = 0; i < ((FclCombineMenu *)p)->unk139; i++) {
                    te = &D_00882FB0[i * 2];
                    v5 = fclMakeVec2(26.0f, (f32)(i * 0x22 + 0x57));
                    /* Raw: second byte of an interleaved choice record. */
                    fclCombineDrawListRow(task, *(s8 *)te, v5, (s16)(*(s8 *)(te + 1) + 0x168), (s16)(i * 2 + 2), 1);
                }
                if (((FclCombineMenu *)p)->unk138 > 0) {
                    fclCombineDrawDetailFrame(task, 1);
                }
                fclCombineDrawActionList(task);
                fclCombineSlideInSlotSprites(task, 0x96, 0x97);
                *p = 0;
                *(p + 1) = 0x1B;
            }
            *(p + 0x13A) = 0;
            return;
        }
        break;
    case 0xC4:
        if (nmMesWindowSlotStatus((s8)*(p + 0xD)) != 0) {
            nmMesWindowStepSlotRelease((s8)*(p + 0xD));
        } else {
            nmMesWindowDestroySlot((s8)*(p + 0xD));
            *(p + 1) = 0xC3;
        }
        break;
    }
}

/* One four-byte ingredient slot of the D_0063FCA0 recipe rows and the
   D_006406F0 calendar rows read by fclCombineMenuResultGrowth. */
typedef struct {
    s8 kind;
    s8 weight;
    s16 item;
} FclCombineSlot;

/* Nonzero when the task's slot list (count at 0x2DF, kinds from 0x2DA)
   holds the given kind.  Retail inlines this at every use. */
/* The task-work reload retains its measured inlined-owner difference below. */
static inline s32 fclCombineHasSlotKind(u8 *task, s8 kind)
{
    /* measured: field typing changes 9087 normalized bytes in the full owner. */
    s8 *q = *(s8 **)(task + 0x38);
    s16 i;

    for (i = 0; i < q[0x2DF]; i++) {
        if (q[i + 0x2DA] == kind) {
            return 1;
        }
    }
    return 0;
}

/* The item table lookup of fclCombineStageValue, which retail inlines into
   fclCombineMenuResultGrowth with the kind read before the roll is made. */
static inline s16 fclCombinePickItem(s8 kind, s8 roll)
{
    switch (kind) {
    case 1:
        return D_00749040[roll];
    case 2:
        return D_00749060[roll];
    case 3:
        return D_00749080[roll];
    case 4:
        return D_007490A0[roll];
    case 5:
        return D_007490C0[roll];
    case 6:
        return D_007490E0[roll];
    }
    return -1;
}

/* The independent state scans preserve each counter's lifetime.
   Item values narrow at their halfword consumers; the skill replacement
   provider and every caller use a signed-halfword previous-skill ID.
   The progress value is explicitly forwarded to the child setter. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma opt_common_subs off
static inline u16 fclItemHalf(const s32 *value)
{
    return *value;
}
#pragma pop
// Fcl combine menu result growth (state 0x0C): handed off from the fusion result (state 0x0D, via 0xA0). Experience and level-up (0xA0-0xA4), stat boosts on the highest then lowest stat (0xA8-0xAB),
// skill roll, learn, or replace (0xAC-0xBB), then finish (0xBF-0xC1 -> 0xD2).
// FUN_0030C3C0
#pragma push
/* measured: hoists each slot scan's count and kind out of its loop. */
#pragma opt_loop_invariants on
/* measured: keeps the 0xAC slot pointer as its own index-first address. */
#pragma opt_propagation off
/* Historical whole-layout probe: 9513 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
void fclCombineMenuResultGrowth(u8 *task) {
    extern s32 datGetFlag(s32);
    extern u32 shdPersonaLevelUpIsDone(u8 *);
    extern void fclDrawSetHandleValue(u8 *, u32);
    extern s32 sdkSndStopStream(s16, s16);
    extern u8 *shdPersonaLevelUpCreate(s32, s32, u8 *, s32, s32, s32 *);
    extern u8 *shdPersonaSkillReplaceCreate(s32, u8 *, s32, u8 *);
    extern s32 datBlockStageIsEight(u8 *);
    extern void frFontExCopyString(void *, void *, s32);
    extern void shdPersonaSetPendingSkill(u8 *, s32);
    extern void shdPersonaArmSkillReveal(u8 *);
    extern s32 shdPersonaAddSkill(u8 *, u16);
    extern void yListSlotCopyEntry(u8 *, s8, s16);
    extern void fclDrawSetState(u8 *, s8);
    extern s32 D_00641B90[];
    extern u8 D_00641AD0[];
    u8 list[5];
    FclPackedPosition pos;
    char text[0x20];
    char name[0x20];
    FclCombineRecipe info;
    u8 *p;
    s8 *slot;
    u8 *e;
    u8 *row;
    FclCombineSlot *cal;
    s16 j1;
    s8 *q2;
    s16 k2;
    s32 found2;
    s16 j2;
    s8 *q3;
    s16 k3;
    s32 found3;
    s16 j3;
    s16 i1;
    s16 i2;
    s16 i3;
    s16 i4;
    s16 i5;
    s16 i6;
    s16 i7;
    s16 i8;
    s16 i9;
    s8 *q4;
    s16 k4;
    s32 found4;
    s16 j4;
    s16 i10;
    s16 i11;
    s8 *q5;
    s16 k5;
    s32 found5;
    s16 j5;
    s8 *q6;
    s16 k6;
    s32 found6;
    s16 j6;
    s8 *q7;
    s16 k7;
    s32 found7;
    s16 j7;
    s16 i12;
    s16 j8;
    s16 i13;
    s16 i14;
    s16 i15;
    s8 best;
    s8 top;
    u32 count;
    s8 kind;
    s8 roll;
    s32 item;
    u16 id;

    p = ((KwlnTask *)task)->work;
    id = ((u16 *)yListSlotEntry(((FclCombineMenu *)p)->f2F9, ((FclCombineMenu *)p)->f2FA))[1];
    switch (p[1]) {
    case 0xA0:
        if (datGetFlag(0x5E) != 0) {
            *((s8 *)fclCombineGetWork(((FclCombineMenu *)p)->detailTask.task)) = 4;
            /* measured: field typing changes 9076 normalized bytes in the full owner. */
            fclDrawSetPlacementEx(((FclCombineMenu *)p)->drawTask.task, (s32)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)), 0, 0, 0);
            /* measured: field typing changes 8641 normalized bytes in the full owner. */
            shdPersonaSetChildDispCtlHandle(fclDrawGetResource(*(u8 **)(p + 0x148)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
            /* measured: field typing changes 8641 normalized bytes in the full owner. */
            shdPersonaEndSelection(fclDrawGetResource(*(u8 **)(p + 0x148)), 1);
            p[1] = 0xA1;
        }
        break;
    case 0xA1:
        datSetFlag(0x5D, 1);
        if (datGetPersonaArcanaCommunityValue(id) > 0) {
            p[1] = 0xA2;
            {
                u8 *persona;
                s32 experience;
                /* measured: field typing changes 9076 normalized bytes in the full owner. */
                persona = yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA));
                experience = ((FclCombineMenu *)p)->unk10;
                datPersonaPreviewLevelUp(persona, p + 0x28, experience);
            }
            p[0xB1] = p[0x28];
        } else if (fclCombineCheckIds(task) == 1) {
            if (fclCombineHasSlotKind(task, 7) == 1) {
                p[1] = 0xA8;
                p[0x22] = 0xA8;
                p[0x13C] = 1;
                if (((FclCombineMenu *)p)->unk21 == 0) {
                    p[1] = 0xBD;
                }
            } else if (fclCombineHasSlotKind(task, 0xD) == 1) {
                p[1] = 0xA8;
                p[0x22] = 0xA8;
                p[0x13C] = 3;
                if (((FclCombineMenu *)p)->unk21 == 0) {
                    p[1] = 0xBD;
                }
            } else if (fclCombineHasSlotKind(task, 0xA) == 1) {
                p[1] = 0xB2;
                p[0x22] = 0xB2;
                if (((FclCombineMenu *)p)->unk21 == 0) {
                    p[1] = 0xBD;
                }
            } else {
                for (j1 = 0; j1 < 6; j1++) {
                    if (fclCombineHasSlotKind(task, j1 + 1) == 1) {
                        p[1] = 0xAC;
                        p[0x22] = 0xAC;
                        if (((FclCombineMenu *)p)->unk21 == 0) {
                            p[1] = 0xBD;
                        }
                        return;
                    }
                }
                if (fclCombineHasSlotKind(task, 9) == 1) {
                    p[1] = 0xB8;
                    p[0x22] = 0xB8;
                    if (((FclCombineMenu *)p)->unk21 == 0) {
                        p[1] = 0xBD;
                    }
                }
            }
        }
        break;
    case 0xA2:
        if (((FclCombineMenu *)p)->unkB1 != 0) {
            /* measured: field typing changes 9076 normalized bytes in the full owner. */
            ((FclCombineMenu *)p)->unk14.signedValue = datPersonaExpToNextLevel(yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)));
            {
                u8 *persona;
                s32 experience;
                /* measured: field typing changes 9076 normalized bytes in the full owner. */
                persona = yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA));
                /* measured: field typing changes 7909 normalized bytes in the full owner. */
                experience = *(s32 *)(p + 0x14);
                datPersonaPreviewLevelUp(persona, p + 0x28, experience);
            }
            /* measured: field typing changes 7908 normalized bytes in the full owner. */
            ((FclCombineMenu *)p)->unk10 -= *(s32 *)(p + 0x14);
            ((FclCombineMenu *)p)->outcome.signedValue = 0;
            ((FclCombineMenu *)p)->f2D8 = 1;
            /* measured: field typing changes 7917 normalized bytes in the full owner. */
            (*(s8 *)(p + 0xB1))--;
            p[1] = 0xA4;
            sdkSndStartStream(0, 0, 0, 0xA);
        } else {
            p[1] = 0xBF;
            if (fclCombineCheckIds(task) == 1) {
                if (fclCombineHasSlotKind(task, 7) == 1) {
                    p[1] = 0xA8;
                    p[0x22] = 0xA8;
                    p[0x13C] = 1;
                    if (((FclCombineMenu *)p)->unk21 == 0) {
                        p[1] = 0xBD;
                    }
                } else if (fclCombineHasSlotKind(task, 0xD) == 1) {
                    p[1] = 0xA8;
                    p[0x22] = 0xA8;
                    p[0x13C] = 3;
                    if (((FclCombineMenu *)p)->unk21 == 0) {
                        p[1] = 0xBD;
                    }
                } else if (fclCombineHasSlotKind(task, 0xA) == 1) {
                    p[1] = 0xB2;
                    p[0x22] = 0xB2;
                    if (((FclCombineMenu *)p)->unk21 == 0) {
                        p[1] = 0xBD;
                    }
                } else {
                    for (j2 = 0; j2 < 6; j2++) {
                        /* measured: field typing changes 9251 normalized bytes in the full owner. */
                        q2 = *(s8 **)(task + 0x38);
                        for (k2 = 0; k2 < q2[0x2DF]; k2++) {
                            if (q2[k2 + 0x2DA] == (s8)(j2 + 1)) {
                                found2 = 1;
                                goto checked2;
                            }
                        }
                        found2 = 0;
                    checked2:
                        if (found2 == 1) {
                            p[1] = 0xAC;
                            p[0x22] = 0xAC;
                            if (((FclCombineMenu *)p)->unk21 == 0) {
                                p[1] = 0xBD;
                            }
                            return;
                        }
                    }
                    if (fclCombineHasSlotKind(task, 9) == 1) {
                        p[1] = 0xB8;
                        p[0x22] = 0xB8;
                        if (((FclCombineMenu *)p)->unk21 == 0) {
                            p[1] = 0xBD;
                        }
                    }
                }
            }
        }
        break;
    case 0xA3:
        if (shdPersonaLevelUpIsDone(((FclCombineMenu *)p)->levelUpTask) != 0) {
            /* measured: field typing changes 7240 normalized bytes in the full owner. */
            kwlnTaskDestroyWithHierarchy((KwlnTask *)*(u8 **)(p + 0x2A4));
            /* measured: field typing changes 7239 normalized bytes in the full owner. */
            *(u8 **)(p + 0x2A4) = 0;
            p[1] = 0xA2;
        }
        break;
    case 0xA4:
        fclDrawSetHandleValue(((FclCombineMenu *)p)->drawTask.task,
                      /* measured: field typing changes 7203 normalized bytes in the full owner. */
                      ((FclCombineMenu *)p)->unk14.value - (u32)fclEaseInterpolate(2, 1.0f, (f32)*(u32 *)(p + 0x14),
                                                               (f32)((FclCombineMenu *)p)->f2D8, 55.0f));
        /* measured: field typing changes 7441 normalized bytes in the full owner. */
        if (*(s16 *)(p + 0x2D8) < 0x37) {
            /* measured: field typing changes 184/7441 normalized bytes in the full owner. */
            *(s16 *)(p + 0x2D8) = fclAddClamped(*(s16 *)(p + 0x2D8), 1, 0x37, 0, 1);
            /* measured: field typing changes 184 normalized bytes in the full owner. */
            if (*(s16 *)(p + 0x2D8) > 0xF &&
                ((D_008C024E[0] & 0x40) || (D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x800))) {
                /* measured: field typing changes 7203 normalized bytes in the full owner. */
                *(s16 *)(p + 0x2D8) = 0x37;
            }
        } else {
            sdkSndStopStream(0, 0);
            /* measured: field typing changes 9076 normalized bytes in the full owner. */
            ((DatPersonaRecord *)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))->exp += datPersonaExpToNextLevel(yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)));
            if (((FclCombineMenu *)p)->unkB1 == 0) {
                /* measured: field typing changes 9076 normalized bytes in the full owner. */
                ((DatPersonaRecord *)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))->exp += ((FclCombineMenu *)p)->unk10;
            }
            /* measured: field typing changes 7205 normalized bytes in the full owner. */
            ((FclCombineMenu *)p)->levelUpTask = shdPersonaLevelUpCreate((s32)task, (s32)fclDrawGetResource(*(u8 **)(p + 0x148)), p + 0x28,
                                                fclCombineGetMesWindow(), 0, (s32 *)D_00641AD0);
            p[1] = 0xA3;
        }
        break;
    case 0xCE:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 6828 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
        } else {
            /* measured: field typing changes 6828 normalized bytes in the full owner. */
            nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
            p[1] = 0xBF;
            if (fclCombineCheckIds(task) == 1) {
                if (fclCombineHasSlotKind(task, 7) == 1) {
                    p[1] = 0xA8;
                    p[0x22] = 0xA8;
                    p[0x13C] = 1;
                    if (((FclCombineMenu *)p)->unk21 == 0) {
                        p[1] = 0xBC;
                    }
                    fclDrawSetStateByte(((FclCombineMenu *)p)->drawTask.task, 9);
                } else if (fclCombineHasSlotKind(task, 0xD) == 1) {
                    p[1] = 0xA8;
                    p[0x22] = 0xA8;
                    p[0x13C] = 3;
                    if (((FclCombineMenu *)p)->unk21 == 0) {
                        p[1] = 0xBC;
                    }
                    fclDrawSetStateByte(((FclCombineMenu *)p)->drawTask.task, 9);
                } else if (fclCombineHasSlotKind(task, 0xA) == 1) {
                    p[1] = 0xB2;
                    p[0x22] = 0xB2;
                    if (((FclCombineMenu *)p)->unk21 == 0) {
                        p[1] = 0xBD;
                    }
                } else {
                    for (j3 = 0; j3 < 6; j3++) {
                        /* measured: field typing changes 9205 normalized bytes in the full owner. */
                        q3 = *(s8 **)(task + 0x38);
                        for (k3 = 0; k3 < q3[0x2DF]; k3++) {
                            if (q3[k3 + 0x2DA] == (s8)(j3 + 1)) {
                                found3 = 1;
                                goto checked3;
                            }
                        }
                        found3 = 0;
                    checked3:
                        if (found3 == 1) {
                            p[1] = 0xAC;
                            p[0x22] = 0xAC;
                            if (((FclCombineMenu *)p)->unk21 == 0) {
                                p[1] = 0xBC;
                            }
                            fclDrawSetStateByte(((FclCombineMenu *)p)->drawTask.task, 9);
                            return;
                        }
                    }
                    if (fclCombineHasSlotKind(task, 9) == 1) {
                        p[1] = 0xB8;
                        p[0x22] = 0xB8;
                        if (((FclCombineMenu *)p)->unk21 == 0) {
                            p[1] = 0xBC;
                        }
                        fclDrawSetStateByte(((FclCombineMenu *)p)->drawTask.task, 9);
                    }
                }
            }
        }
        break;
    case 0xA8:
        /* This retail state retains a counter-only traversal. */
        for (i1 = 0; i1 < 5; i1++) {
        }
        p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
        for (i2 = 0; i2 < 0x20; i2++) {
            text[i2] = 0;
        }
        sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
        nmMesWindowSetSlotString(((FclCombineMenu *)p)->fD, 0, text);
        /* measured: field typing changes 6075 normalized bytes in the full owner. */
        nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x54);
        p[1] = 0xA9;
        break;
    case 0xA9:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 6038 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
        } else {
            /* measured: field typing changes 6038 normalized bytes in the full owner. */
            nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
            for (i3 = 0; i3 < 5; i3++) {
                list[i3] = 0;
            }
            p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            for (i4 = 0; i4 < 0x20; i4++) {
                name[i4] = 0;
                text[i4] = 0;
            }
            /* measured: field typing changes 9076 normalized bytes in the full owner. */
            e = (u8 *)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA));
            best = 0;
            top = e[0x1C];
            for (i5 = 1; i5 < 5; i5++) {
                if (top < e[i5 + 0x1C]) {
                    top = e[i5 + 0x1C];
                    best = i5;
                }
            }
            p[0x13D] = best;
            sprintf(text, (const char *)&iGpffffa8a4, (const char *)D_00641B90[best]);
            frFontExCopyString(text, name, 0x20);
            /* measured: field typing changes 6038 normalized bytes in the full owner. */
            nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 0, name);
            list[((FclCombineMenu *)p)->unk13D] = ((FclCombineMenu *)p)->unk13C;
            /* measured: field typing changes 5764/9076 normalized bytes in the full owner. */
            ((u8 *)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))[*(s8 *)(p + 0x13D) + 0x1C] += (u8)p[0x13C];
            for (i6 = 0; i6 < 0x20; i6++) {
                name[i6] = 0;
                text[i6] = 0;
            }
            /* measured: field typing changes 5763 normalized bytes in the full owner. */
            sprintf(text, &iGpffffa8a0, *(s8 *)(p + 0x13C));
            /* measured: field typing changes 6038 normalized bytes in the full owner. */
            nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 1, text);
            /* measured: field typing changes 9076 normalized bytes in the full owner. */
            e = (u8 *)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA));
            best = 0;
            top = e[0x1C];
            for (i7 = 1; i7 < 5; i7++) {
                if (e[i7 + 0x1C] < top) {
                    top = e[i7 + 0x1C];
                    best = i7;
                }
            }
            p[0x13E] = best;
            /* measured: field typing changes 5765 normalized bytes in the full owner. */
            list[best] = *(s8 *)(p + 0x13C);
            /* measured: field typing changes 9076 normalized bytes in the full owner. */
            ((u8 *)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))[((FclCombineMenu *)p)->unk13E + 0x1C] += (u8)p[0x13C];
            shdPersonaFillStateBlock(fclDrawGetResource(((FclCombineMenu *)p)->drawTask.task), list);
            p[0xB0] = 0;
            /* measured: field typing changes 6038 normalized bytes in the full owner. */
            nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x3E);
            p[1] = 0xAA;
        }
        break;
    case 0xAA:
        /* measured: field typing changes 27 normalized bytes in the full owner. */
        ((FclCombineMenu *)p)->unkB0 = fclAddClamped(*(s8 *)(p + 0xB0), 1, 0x14, 0, 1);
        /* measured: field typing changes 5466 normalized bytes in the full owner. */
        if (*(s8 *)(p + 0xB0) == 0xF) {
            sdkSndStartStream(1, 3, 3, 1);
        }
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 5414 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
        } else {
            /* measured: field typing changes 5414 normalized bytes in the full owner. */
            nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
            p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            for (i8 = 0; i8 < 0x20; i8++) {
                name[i8] = 0;
                text[i8] = 0;
            }
            sprintf(text, (const char *)&iGpffffa8a4, (const char *)D_00641B90[((FclCombineMenu *)p)->unk13E]);
            frFontExCopyString(text, name, 0x20);
            /* measured: field typing changes 5414 normalized bytes in the full owner. */
            nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 0, name);
            for (i9 = 0; i9 < 0x20; i9++) {
                name[i9] = 0;
                text[i9] = 0;
            }
            sprintf(text, &iGpffffa8a0, ((FclCombineMenu *)p)->unk13C);
            /* measured: field typing changes 5414 normalized bytes in the full owner. */
            nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 1, text);
            /* measured: field typing changes 5414 normalized bytes in the full owner. */
            nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x3E);
            p[1] = 0xAB;
            p[0xB0] = 0;
        }
        break;
    case 0xAB:
        /* measured: field typing changes 27 normalized bytes in the full owner. */
        ((FclCombineMenu *)p)->unkB0 = fclAddClamped(*(s8 *)(p + 0xB0), 1, 0x14, 0, 1);
        /* measured: field typing changes 5174 normalized bytes in the full owner. */
        if (*(s8 *)(p + 0xB0) == 0xF) {
            sdkSndStartStream(1, 3, 3, 1);
        }
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 5122 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
        } else {
            /* measured: field typing changes 5122 normalized bytes in the full owner. */
            nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
            p[1] = 0xBF;
            if (fclCombineCheckIds(task) == 1) {
                if (fclCombineHasSlotKind(task, 0xA) == 1) {
                    p[1] = 0xB2;
                    p[0x22] = 0xB2;
                    if (((FclCombineMenu *)p)->unk21 == 0) {
                        p[1] = 0xBD;
                    }
                } else {
                    for (j4 = 0; j4 < 6; j4++) {
                        /* measured: field typing changes 9162 normalized bytes in the full owner. */
                        q4 = *(s8 **)(task + 0x38);
                        for (k4 = 0; k4 < q4[0x2DF]; k4++) {
                            if (q4[k4 + 0x2DA] == (s8)(j4 + 1)) {
                                found4 = 1;
                                goto checked4;
                            }
                        }
                        found4 = 0;
                    checked4:
                        if (found4 == 1) {
                            p[1] = 0xAC;
                            return;
                        }
                    }
                    if (fclCombineHasSlotKind(task, 9) == 1) {
                        p[1] = 0xB8;
                    }
                }
            }
        }
        break;
    case 0xB2:
        row = D_0063FCA0 + ((FclCombineMenu *)p)->ruleIndex * 28;
        cal = (FclCombineSlot *)(D_006406F0 + (s8)calGetDayEntryForMonthDay(fclCalendarMonth(), (u8)fclCalendarDay()) * 20);
        /* measured: field typing changes 4758 normalized bytes in the full owner. */
        if (*(s8 *)(p + 0x2D4) == -1) {
            for (i10 = 0; i10 < 5; i10++) {
                if (((FclCombineMenu *)p)->outcomeIds[i10] == 0xA) {
                    ((FclCombineMenu *)p)->outcome.signedValue = cal[i10].item;
                    break;
                }
            }
        } else {
            for (i11 = 0; i11 < ((FclCombineMenu *)p)->outcomeIdCount; i11++) {
                if (((FclCombineMenu *)p)->outcomeIds[i11] == 0xA) {
                    ((FclCombineMenu *)p)->outcome.signedValue = ((FclCombineSlot *)(row + 8))[i11].item;
                    break;
                }
            }
        }
        shdPersonaSetPendingSkill(fclDrawGetResource(((FclCombineMenu *)p)->drawTask.task), ((FclCombineMenu *)p)->outcome.value);
        ((FclCombineMenu *)p)->f2D8 = 0;
        p[1] = 0xB3;
        break;
    case 0xB3:
        /* measured: field typing changes 29 normalized bytes in the full owner. */
        ((FclCombineMenu *)p)->f2D8 = fclAddClamped(*(s16 *)(p + 0x2D8), 1, 0x14, 0, 1);
        /* measured: field typing changes 4506 normalized bytes in the full owner. */
        if (*(s16 *)(p + 0x2D8) >= 0x14) {
            p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
            nmMesWindowSetSlotString(((FclCombineMenu *)p)->fD, 1, text);
            sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(((FclCombineMenu *)p)->outcome.value));
            /* measured: field typing changes 4426 normalized bytes in the full owner. */
            nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 0, text);
            /* measured: field typing changes 4426 normalized bytes in the full owner. */
            nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x51);
            p[1] = 0xB6;
        }
        break;
    case 0xB5:
        if (datBlockStageIsEight(((FclCombineMenu *)p)->skillReplaceTask) == 1) {
            /* measured: field typing changes 4356 normalized bytes in the full owner. */
            kwlnTaskDestroyWithHierarchy((KwlnTask *)*(u8 **)(p + 0x2A8));
            /* measured: field typing changes 4356 normalized bytes in the full owner. */
            *(u8 **)(p + 0x2A8) = 0;
            shdPersonaArmSkillReveal(fclDrawGetResource(((FclCombineMenu *)p)->drawTask.task));
            p[1] = 0xBF;
            for (j5 = 0; j5 < 6; j5++) {
                /* measured: field typing changes 9008 normalized bytes in the full owner. */
                q5 = *(s8 **)(task + 0x38);
                for (k5 = 0; k5 < q5[0x2DF]; k5++) {
                    if (q5[k5 + 0x2DA] == (s8)(j5 + 1)) {
                        found5 = 1;
                        goto checked5;
                    }
                }
                found5 = 0;
            checked5:
                if (found5 == 1) {
                    p[1] = 0xAC;
                    p[0x22] = 0xAC;
                    if (((FclCombineMenu *)p)->unk21 == 0) {
                        p[1] = 0xBD;
                    }
                    return;
                }
            }
            if (fclCombineHasSlotKind(task, 9) == 1) {
                p[1] = 0xB8;
                p[0x22] = 0xB8;
                if (((FclCombineMenu *)p)->unk21 == 0) {
                    p[1] = 0xBD;
                }
            }
        }
        break;
    case 0xB6:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 4057 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
        } else {
            /* measured: field typing changes 4057 normalized bytes in the full owner. */
            nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
            ((FclCombineMenu *)p)->f2D8 = 0;
            p[1] = 0xB7;
            /* measured: field typing changes 9076 normalized bytes in the full owner. */
            e = yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA));
            {
                u16 selectedSkill;
                selectedSkill = ((FclCombineMenu *)p)->outcome.value;
                if (datPersonaFindSkillSlot(e, selectedSkill) != -1) {
                    p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                    /* measured: field typing changes 4006 normalized bytes in the full owner. */
                    sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(*(u16 *)(p + 0x1C)));
                    /* measured: field typing changes 4057 normalized bytes in the full owner. */
                    nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 0, text);
                    /* measured: field typing changes 4057 normalized bytes in the full owner. */
                    nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x52);
                    p[1] = 0xB4;
                /* measured: field typing changes 9076 normalized bytes in the full owner. */
                } else if ((s32)datPersonaCountSkills(yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA))) >= 8) {
                    p[1] = 0xB5;
                    ((FclCombineMenu *)p)->skillReplaceTask = shdPersonaSkillReplaceCreate((s32)task, fclDrawGetResource(((FclCombineMenu *)p)->drawTask.task), fclCombineGetMesWindow(), D_00641AD0);
                }
            }
        }
        break;
    case 0xB4:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 3840 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
        } else {
            /* measured: field typing changes 3840 normalized bytes in the full owner. */
            nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
            p[1] = 0xBF;
            shdPersonaArmSkillReveal(fclDrawGetResource(((FclCombineMenu *)p)->drawTask.task));
            for (j6 = 0; j6 < 6; j6++) {
                /* measured: field typing changes 9008 normalized bytes in the full owner. */
                q6 = *(s8 **)(task + 0x38);
                for (k6 = 0; k6 < q6[0x2DF]; k6++) {
                    if (q6[k6 + 0x2DA] == (s8)(j6 + 1)) {
                        found6 = 1;
                        goto checked6;
                    }
                }
                found6 = 0;
            checked6:
                if (found6 == 1) {
                    p[1] = 0xAC;
                    p[0x22] = 0xAC;
                    if (((FclCombineMenu *)p)->unk21 == 0) {
                        p[1] = 0xBD;
                    }
                    return;
                }
            }
            if (fclCombineHasSlotKind(task, 9) == 1) {
                p[1] = 0xB8;
                p[0x22] = 0xB8;
                if (((FclCombineMenu *)p)->unk21 == 0) {
                    p[1] = 0xBD;
                }
            }
        }
        break;
    case 0xB7:
        /* measured: field typing changes 29 normalized bytes in the full owner. */
        ((FclCombineMenu *)p)->f2D8 = fclAddClamped(*(s16 *)(p + 0x2D8), 1, 0x28, 0, 1);
        /* measured: field typing changes 3630 normalized bytes in the full owner. */
        if (*(s16 *)(p + 0x2D8) == 0x14) {
            {
                u8 *personaTask;
                u16 skill;
                personaTask = fclDrawGetResource(((FclCombineMenu *)p)->drawTask.task);
                skill = ((FclCombineMenu *)p)->outcome.value;
                shdPersonaAddSkill(personaTask, skill);
            }
            /* measured: field typing changes 3499 normalized bytes in the full owner. */
            shdPersonaArmSkillReveal(fclDrawGetResource(*(u8 **)(p + 0x148)));
            sdkSndStartStream(1, 3, 3, 2);
        /* measured: field typing changes 3473 normalized bytes in the full owner. */
        } else if (*(s16 *)(p + 0x2D8) >= 0x28) {
            p[1] = 0xBF;
            for (j7 = 0; j7 < 6; j7++) {
                /* measured: field typing changes 9008 normalized bytes in the full owner. */
                q7 = *(s8 **)(task + 0x38);
                for (k7 = 0; k7 < q7[0x2DF]; k7++) {
                    if (q7[k7 + 0x2DA] == (s8)(j7 + 1)) {
                        found7 = 1;
                        goto checked7;
                    }
                }
                found7 = 0;
            checked7:
                if (found7 == 1) {
                    p[1] = 0xAC;
                    p[0x22] = 0xAC;
                    if (((FclCombineMenu *)p)->unk21 == 0) {
                        p[1] = 0xBD;
                    }
                    return;
                }
            }
            if (fclCombineHasSlotKind(task, 9) == 1) {
                p[1] = 0xB8;
                p[0x22] = 0xB8;
                if (((FclCombineMenu *)p)->unk21 == 0) {
                    p[1] = 0xBD;
                }
            }
        }
        break;
    case 0xAC:
        p[0x20] = 0;
        for (i12 = 0; i12 < ((FclCombineMenu *)p)->outcomeIdCount; i12++) {
            if (((FclCombineMenu *)p)->outcomeIds[i12] > 0 && ((FclCombineMenu *)p)->outcomeIds[i12] < 7) {
                slot = (s8 *)(p + 0x2DA) + i12;
                p[0x1F] = ((FclCombineMenu *)p)->outcomeIds[i12];
                *slot = 0;
                break;
            }
        }
        /* measured: field typing changes 9076 normalized bytes in the full owner. */
        ((FclCombineMenu *)p)->outcome.signedValue = fclCombineRollOutcome(task, ((u8 *)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))[4], ((FclCombineMenu *)p)->stageKind);
        /* measured: field typing changes 3093 normalized bytes in the full owner. */
        item = *(u16 *)(p + 0x1C);
        /* measured: field typing changes 9076 normalized bytes in the full owner. */
        if (datPersonaFindSkillSlot((u8 *)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)), fclItemHalf(&item)) == -1) {
            p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
            nmMesWindowSetSlotString(((FclCombineMenu *)p)->fD, 1, text);
            sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(item));
            /* measured: field typing changes 2992 normalized bytes in the full owner. */
            nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 0, text);
        } else {
            /* measured: field typing changes 3092 normalized bytes in the full owner. */
            kind = *(s8 *)(p + 0x1F);
            roll = fclAddClamped(((FclCombineMenu *)p)->outcomeCount, 1, 9, 0, 1);
            item = (u16)fclCombinePickItem(kind, roll);
            /* measured: field typing changes 9076 normalized bytes in the full owner. */
            if (datPersonaFindSkillSlot((u8 *)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)), fclItemHalf(&item)) == -1) {
                p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
                nmMesWindowSetSlotString(((FclCombineMenu *)p)->fD, 1, text);
                sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(item));
                /* measured: field typing changes 2667 normalized bytes in the full owner. */
                nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 0, text);
                /* measured: field typing changes 3093 normalized bytes in the full owner. */
                *(s16 *)(p + 0x1C) = item;
            } else {
                /* measured: field typing changes 3092 normalized bytes in the full owner. */
                kind = *(s8 *)(p + 0x1F);
                /* measured: field typing changes 2940 normalized bytes in the full owner. */
                roll = fclSubClamped(*(s8 *)(p + 0x1E), 1, 0, 9, 1);
                item = (u16)fclCombinePickItem(kind, roll);
                /* measured: field typing changes 9076 normalized bytes in the full owner. */
                if (datPersonaFindSkillSlot((u8 *)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)), fclItemHalf(&item)) == -1) {
                    p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                    sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
                    nmMesWindowSetSlotString(((FclCombineMenu *)p)->fD, 1, text);
                    sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(item));
                    /* measured: field typing changes 2336 normalized bytes in the full owner. */
                    nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 0, text);
                    /* measured: field typing changes 3093 normalized bytes in the full owner. */
                    *(s16 *)(p + 0x1C) = item;
                } else {
                    p[0x20] = 1;
                    p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                    sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
                    nmMesWindowSetSlotString(((FclCombineMenu *)p)->fD, 1, text);
                    /* measured: field typing changes 3093 normalized bytes in the full owner. */
                    sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(*(u16 *)(p + 0x1C)));
                    /* measured: field typing changes 2235 normalized bytes in the full owner. */
                    nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 0, text);
                }
            }
        }
        /* measured: field typing changes 3093 normalized bytes in the full owner. */
        shdPersonaSetPendingSkill(fclDrawGetResource(((FclCombineMenu *)p)->drawTask.task), *(u16 *)(p + 0x1C));
        p[1] = 0xB0;
        break;
    case 0xAD:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 2154 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
        } else {
            /* measured: field typing changes 2154 normalized bytes in the full owner. */
            nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
            if (((FclCombineMenu *)p)->unk20 == 1) {
                for (j8 = 0; j8 < 8; j8++) {
                    /* measured: field typing changes 9378/9381 normalized bytes in the full owner. */
                    if (((u16 *)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))[j8 + 6] != 0 &&
                        /* measured: field typing changes 9378/9381 normalized bytes in the full owner. */
                        ((FclCombineMenu *)p)->outcome.signedValue == ((u16 *)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))[j8 + 6]) {
                        p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                        /* measured: field typing changes 9117 normalized bytes in the full owner. */
                        sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(*(u16 *)(p + 0x1C)));
                        /* measured: field typing changes 9117 normalized bytes in the full owner. */
                        nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 0, text);
                        /* measured: field typing changes 9117 normalized bytes in the full owner. */
                        nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x52);
                        p[1] = 0xAE;
                    }
                }
                if (p[1] != 0xAE) {
                    p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
                    sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(((FclCombineMenu *)p)->outcome.value));
                    /* measured: field typing changes 9117 normalized bytes in the full owner. */
                    nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 0, text);
                    sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
                    /* measured: field typing changes 9117 normalized bytes in the full owner. */
                    nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 1, text);
                    /* measured: field typing changes 9117 normalized bytes in the full owner. */
                    nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x53);
                    p[1] = 0xAE;
                }
            } else {
                p[1] = 0xB1;
                ((FclCombineMenu *)p)->f2D8 = 0;
                /* measured: field typing changes 9076 normalized bytes in the full owner. */
                if ((s32)datPersonaCountSkills(yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA))) >= 8) {
                    p[1] = 0xAF;
                    ((FclCombineMenu *)p)->skillReplaceTask = shdPersonaSkillReplaceCreate((s32)task, fclDrawGetResource(((FclCombineMenu *)p)->drawTask.task), fclCombineGetMesWindow(), D_00641AD0);
                }
            }
        }
        break;
    case 0xAF:
        if (datBlockStageIsEight(((FclCombineMenu *)p)->skillReplaceTask) == 1) {
            /* measured: field typing changes 1760 normalized bytes in the full owner. */
            kwlnTaskDestroyWithHierarchy((KwlnTask *)*(u8 **)(p + 0x2A8));
            /* measured: field typing changes 1760 normalized bytes in the full owner. */
            *(u8 **)(p + 0x2A8) = 0;
            shdPersonaArmSkillReveal(fclDrawGetResource(((FclCombineMenu *)p)->drawTask.task));
            for (i13 = 0; i13 < ((FclCombineMenu *)p)->outcomeIdCount; i13++) {
                if (((FclCombineMenu *)p)->outcomeIds[i13] > 0 && ((FclCombineMenu *)p)->outcomeIds[i13] < 7) {
                    p[1] = 0xAC;
                    return;
                }
            }
            p[1] = 0xBF;
            if (fclCombineHasSlotKind(task, 9) == 1) {
                p[1] = 0xB8;
            }
        }
        break;
    case 0xB0:
        /* measured: field typing changes 27 normalized bytes in the full owner. */
        ((FclCombineMenu *)p)->unkE = fclAddClamped(*(s16 *)(p + 0xE), 1, 0x28, 0, 1);
        /* measured: field typing changes 1553 normalized bytes in the full owner. */
        if (*(s16 *)(p + 0xE) >= 0x28) {
            p[1] = 0xAD;
            nmMesWindowShowSlotRecord(((FclCombineMenu *)p)->fD, 0x51);
        }
        break;
    case 0xB1:
        /* measured: field typing changes 29 normalized bytes in the full owner. */
        ((FclCombineMenu *)p)->f2D8 = fclAddClamped(*(s16 *)(p + 0x2D8), 1, 0x28, 0, 1);
        /* measured: field typing changes 1494 normalized bytes in the full owner. */
        if (*(s16 *)(p + 0x2D8) == 0xF) {
            {
                u8 *personaTask;
                u16 skill;
                personaTask = fclDrawGetResource(((FclCombineMenu *)p)->drawTask.task);
                skill = ((FclCombineMenu *)p)->outcome.value;
                shdPersonaAddSkill(personaTask, skill);
            }
            sdkSndStartStream(1, 3, 3, 2);
        }
        /* measured: field typing changes 32 normalized bytes in the full owner. */
        if (*(s16 *)(p + 0x2D8) >= 0x28) {
            shdPersonaArmSkillReveal(fclDrawGetResource(((FclCombineMenu *)p)->drawTask.task));
            for (i14 = 0; i14 < ((FclCombineMenu *)p)->outcomeIdCount; i14++) {
                if (((FclCombineMenu *)p)->outcomeIds[i14] > 0 && ((FclCombineMenu *)p)->outcomeIds[i14] < 7) {
                    p[1] = 0xAC;
                    return;
                }
            }
            p[1] = 0xBF;
            if (fclCombineHasSlotKind(task, 9) == 1) {
                p[1] = 0xB8;
            }
        }
        break;
    case 0xAE:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 1223 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
        } else {
            /* measured: field typing changes 1223 normalized bytes in the full owner. */
            nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
            for (i15 = 0; i15 < ((FclCombineMenu *)p)->outcomeIdCount; i15++) {
                if (((FclCombineMenu *)p)->outcomeIds[i15] > 0 && ((FclCombineMenu *)p)->outcomeIds[i15] < 7) {
                    p[1] = 0xAC;
                    return;
                }
            }
            p[1] = 0xBF;
        }
        break;
    case 0xB8:
        p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
        do {
            /* measured: field typing changes 9076 normalized bytes in the full owner. */
            count = datPersonaCountSkills(yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)));
            p[0x27] = RpRandom() % count;
        /* measured: field typing changes 9076 normalized bytes in the full owner. */
        } while ((s16)datGetSelectorByte(((s16 *)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))[((FclCombineMenu *)p)->unk27 + 6]) == 0);
        /* measured: field typing changes 1064/9076 normalized bytes in the full owner. */
        sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(((u16 *)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))[*(s8 *)(p + 0x27) + 6]));
        /* measured: field typing changes 1064/9076 normalized bytes in the full owner. */
        ((FclCombineMenu *)p)->outcome.signedValue = ((u16 *)yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))[*(s8 *)(p + 0x27) + 6];
        nmMesWindowSetSlotString(((FclCombineMenu *)p)->fD, 0, text);
        /* measured: field typing changes 957 normalized bytes in the full owner. */
        nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x56);
        /* measured: field typing changes 957 normalized bytes in the full owner. */
        nmMesWindowSetSlotParam(*(s8 *)(p + 0xD), 0);
        /* measured: field typing changes 957 normalized bytes in the full owner. */
        nmMesWindowSetSlotFlag(*(s8 *)(p + 0xD), 0);
        nmMesWindowRequestRefresh();
        p[1] = 0xB9;
        break;
    case 0xB9:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 894 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
        /* measured: field typing changes 894 normalized bytes in the full owner. */
        } else if (nmMesWindowGetSlotState(*(s8 *)(p + 0xD)) == 0) {
            /* measured: field typing changes 894 normalized bytes in the full owner. */
            nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
            /* measured: field typing changes 9074/9076 normalized bytes in the full owner. */
            yListSlotCopyEntry((u8 *)&info, *(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA));
            ((FclCombineMenu *)p)->unk24.signedValue = fclCombinePickCandidateId(info, ((FclCombineMenu *)p)->outcome.signedValue);
            ((FclCombineMenu *)p)->f2D8 = 0;
            p[1] = 0xBA;
        } else {
            /* measured: field typing changes 894 normalized bytes in the full owner. */
            nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
            p[1] = 0xBF;
        }
        break;
    case 0xBA:
        /* measured: field typing changes 29 normalized bytes in the full owner. */
        ((FclCombineMenu *)p)->f2D8 = fclAddClamped(*(s16 *)(p + 0x2D8), 1, 0x28, 0, 1);
        /* measured: field typing changes 790 normalized bytes in the full owner. */
        if (*(s16 *)(p + 0x2D8) == 0x14) {
            {
                u8 *personaTask;
                u16 originalSkill;
                personaTask = fclDrawGetResource(((FclCombineMenu *)p)->drawTask.task);
                originalSkill = ((FclCombineMenu *)p)->outcome.value;
                shdPersonaReplaceSkill(personaTask, originalSkill, ((FclCombineMenu *)p)->unk24.value);
            }
            /* measured: field typing changes 742/744/9076 normalized bytes in the full owner. */
            datPersonaReplaceSkill(yListSlotEntry(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)), *(s16 *)(p + 0x1C), *(u16 *)(p + 0x24));
            sdkSndStartStream(1, 3, 3, 2);
        }
        /* measured: field typing changes 32 normalized bytes in the full owner. */
        if (*(s16 *)(p + 0x2D8) >= 0x28) {
            p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(((FclCombineMenu *)p)->unk24.value));
            nmMesWindowSetSlotString(((FclCombineMenu *)p)->fD, 1, text);
            sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(((FclCombineMenu *)p)->outcome.value));
            /* measured: field typing changes 641 normalized bytes in the full owner. */
            nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 0, text);
            /* measured: field typing changes 641 normalized bytes in the full owner. */
            nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x57);
            p[1] = 0xBB;
        }
        break;
    case 0xBB:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 574 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
        } else {
            /* measured: field typing changes 574 normalized bytes in the full owner. */
            nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
            p[1] = 0xBF;
        }
        break;
    case 0xBC:
        p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
        sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
        nmMesWindowSetSlotString(((FclCombineMenu *)p)->fD, 0, text);
        /* measured: field typing changes 494 normalized bytes in the full owner. */
        nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x47);
        p[1] = 0xBE;
        break;
    case 0xBD:
        p[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
        sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
        nmMesWindowSetSlotString(((FclCombineMenu *)p)->fD, 0, text);
        /* measured: field typing changes 419 normalized bytes in the full owner. */
        nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x48);
        p[1] = 0xBE;
        break;
    case 0xBE:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 384 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
        } else {
            /* measured: field typing changes 384 normalized bytes in the full owner. */
            nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
            p[0x21] = 1;
            p[1] = p[0x22];
        }
        break;
    case 0xBF:
        ((FclCombineMenu *)p)->f2D8 = 0;
        p[1] = 0xC0;
        /* fallthrough */
    case 0xC0:
        /* measured: field typing changes 29 normalized bytes in the full owner. */
        ((FclCombineMenu *)p)->f2D8 = fclAddClamped(*(s16 *)(p + 0x2D8), 1, 0x3C, 0, 1);
        /* measured: field typing changes 332 normalized bytes in the full owner. */
        if (*(s16 *)(p + 0x2D8) >= 0x3C &&
            fclDrawGetState(((FclCombineMenu *)p)->drawTask.task) != 0xE) {
            /* measured: field typing changes 292 normalized bytes in the full owner. */
            fclDrawSetStateByte(*(u8 **)(p + 0x148), 0xB);
            pos.position = fclMakeVec2(0.0f, 0.0f);
            fclSpriteCreate(0x1E8, pos.position, 6.0f, 0xAA);
            fclSpriteSetFlag(0x1E8, 0, 0);
            fclSpriteStartAlphaAt(0x1E8, 0xFF, 0, 0, 0x32, 0xA);
            p[1] = 0xC1;
        }
        break;
    case 0xC1:
        if (fclDrawGetState(((FclCombineMenu *)p)->drawTask.task) == 0xE) {
            /* measured: field typing changes 175 normalized bytes in the full owner. */
            fclDrawSetState(*(u8 **)(p + 0x148), 1);
            p[0] = 0xE;
            p[1] = 0xD2;
        }
        break;
    }
}
#pragma pop
/* measured: MWCC b210 -O2, 348B / 352B window; executable bytes exact.
 * Halfword counters/bound and loop-invariant motion recover the narrowing.
 * Direct identifier comparisons let the compiler cache the masked key;
 * an explicit second identifier local instead rotates three saved registers. */
// Fcl combine consume materials: removes the material personas in materials (count at work+0x1A, where 7 means 12) from the roster, except the lead persona, then inserts the result record. If the lead persona was a material, the result is selected in its place and the lead is removed; the selected roster member is removed last.
// FUN_0030F4F0
#pragma push
#pragma opt_loop_invariants on
/* Historical whole-layout probe: 250 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
void fclCombineConsumeMaterials(u8 *task, s16 *materials) {
    s16 materialIndex;
    s16 searchIndex;
    s16 count;
    s32 equippedId;
    u8 *work;

    work = ((KwlnTask *)task)->work;
    equippedId = datPersonaLeadPersonaId();
    count = ((FclCombineMenu *)work)->sourceCount;
    if (count == 7) {
        count = 0xC;
    }
    materialIndex = 0;
    while (materialIndex < count) {
        if ((u16)equippedId != materials[materialIndex]) {
            datPersonaRemoveRosterMemberById(materials[materialIndex] & 0xFFFF);
        }
        materialIndex++;
    }
    datPersonaInsertRosterRecord((u8 *)yListSlotEntry(((FclCombineMenu *)work)->f2F9, ((FclCombineMenu *)work)->f2FA));
    searchIndex = 0;
    while (searchIndex < count) {
        if ((u16)equippedId == materials[searchIndex]) {
            /* measured: field typing changes 137 normalized bytes in the full owner. */
            datPersonaSelectRosterMemberById(((DatPersonaRecord *)yListSlotEntry(*(s8 *)(work + 0x2F9), *(s8 *)(work + 0x2FA)))->id);
            datPersonaRemoveRosterMemberById(equippedId);
            break;
        }
        searchIndex++;
    }
    datPersonaRemoveSelectedRosterMember();
}
#pragma pop
/* MATCHED: struct colour copies straight into fclSpriteEntry(...) + 0x85;
   evtGetEventFrame takes no argument and fclSpriteStartTweenAt ends in two floats
   (0.0f, -360.0f); the second constructor coordinates for 0x20C are
   (f32)347 / (f32)267 (retail converts them with cvt.s.w). Stored bytes
   are re-read (*(s16 *)(p + 0x2D8), *(s8 *)(p + 0xD)) so b210 forwards
   them as retail does; the D_00640C50/C58/41660 pairs go through a named
   FclVec2f base; the table rows use the fclCombineBuildRows offset spelling; the
   material switch keeps the 6 -> 5 -> 4 fallthrough labels (jump table);
   i is s8 and declared first, then cls, then p (saved-register order). */
// Fcl combine menu finish (state 0x0E): the post-fusion completion sequence. 0xD2-0xD4 wait for the draw and 720 frames, then tear down the linked task; 0xD5-0xD6 show the completion line; 0xD7 rebuilds the menu sprites and the dialogue queue, then returns to state 0 at sub-state 0x1A.
// FUN_0030F650
/* Historical whole-layout probe: 2483 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
void fclCombineMenuFinish(u8 *task) {
    s8 i;
    s16 cls;
    u8 *p;
    u8 kind;
    s16 mats[12];
    FclVec2 w0;
    FclVec2 w1;
    FclVec2 w2;
    FclVec2 w3;
    FclVec2 w4;
    FclVec2 w5;
    FclVec2 w6;
    FclVec2 w7;
    FclVec2 w8;
    FclVec2 w9;
    FclDrawColor c0;
    FclDrawColor c1;
    FclDrawColor c2;
    FclVec2f *base;

    p = ((KwlnTask *)task)->work;
    cls = (s16)((DatPersonaRecord *)yListSlotEntry(((FclCombineMenu *)p)->f2F9, ((FclCombineMenu *)p)->f2FA))->id;
    kind = *(p + 1);
    switch (kind) {
    case 0xD2:
        if (fclDrawIsActive(((FclCombineMenu *)p)->drawTask.handle) == 1) {
            break;
        }
        *(p + 1) = 0xD3;
        ((FclCombineMenu *)p)->f2D8 = 0;
    case 0xD3:
        /* measured: field typing changes 29 normalized bytes in the full owner. */
        ((FclCombineMenu *)p)->f2D8 = fclAddClamped(*(s16 *)(p + 0x2D8), 1, 0xF, 0, 1);
        /* measured: field typing changes 2430 normalized bytes in the full owner. */
        if (*(s16 *)(p + 0x2D8) >= 0xF) {
            datSetFlag(0x5F, 1);
            datSetFlag(0x59, 0);
            datSetFlag(0x5B, 0);
            *(p + 1) = 0xD4;
        }
        break;
    case 0xD4:
        if (evtGetEventFrame() >= 0x2D0) {
            if (*((s8 *)fclCombineGetWork(((FclCombineMenu *)p)->detailTask.task)) != 0) {
                /* measured: field typing changes 2331 normalized bytes in the full owner. */
                *((s8 *)fclCombineGetWork(*(u8 **)(p + 0x254))) = 4;
            }
            if (datGetPersonaArcanaCommunityValue((u16)cls) > 0) {
                if (kwlnTaskIsLinked(((FclCombineMenu *)p)->cardSpriteTask) != 0) {
                    /* measured: field typing changes 2283 normalized bytes in the full owner. */
                    kwlnTaskDestroyWithHierarchy((KwlnTask *)(u32)*(s32 *)(p + 0x308));
                    /* measured: field typing changes 2282 normalized bytes in the full owner. */
                    *(s32 *)(p + 0x308) = 0;
                }
            }
            *(p + 1) = 0xD5;
        }
        break;
    case 0xD5:
        if (datGetFlag(0x5B) != 0) {
            ((FclCombineMenu *)p)->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
            /* measured: field typing changes 2231 normalized bytes in the full owner. */
            nmMesWindowSetSlotString(*(s8 *)(p + 0xD), 0, iGpffffb440 + cls * 0x11);
            /* measured: field typing changes 187 normalized bytes in the full owner. */
            nmMesWindowShowSlotRecord(*(s8 *)(p + 0xD), 0x49);
            *(p + 1) = 0xD6;
        }
        break;
    case 0xD6:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 2164 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
        } else {
            /* measured: field typing changes 2164 normalized bytes in the full owner. */
            nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
            *(p + 1) = 0xD7;
            datSetFlag(0x59, 1);
        }
        break;
    case 0xD7:
        if (kwlnTaskIsLinked(((FclCombineMenu *)p)->eventTask) == 1) {
            break;
        }
        if (kwlnTaskGetTaskByName(D_00641BB0) != 0) {
            kwlnTaskDestroyWithHierarchy((KwlnTask *)(u32)((FclCombineMenu *)p)->cardEffectTask);
            /* measured: field typing changes 2081 normalized bytes in the full owner. */
            *(s32 *)(p + 0x304) = 0;
        }
        if (func_00459760() == -1) {
            sdkSndPlayCue(0x14, 1);
        }
        switch (((FclCombineMenu *)p)->sourceCount) {
        case 2:
            mats[0] = ((DatPersonaRecord *)yListSlotEntry(0, ((FclCombineMenu *)p)->f128))->id;
            mats[1] = ((DatPersonaRecord *)yListSlotEntry(0, ((FclCombineMenu *)p)->f11E))->id;
            break;
        case 3:
            mats[0] = ((DatPersonaRecord *)yListSlotEntry(0, ((FclCombineMenu *)p)->f128))->id;
            mats[1] = ((DatPersonaRecord *)yListSlotEntry(0, ((FclCombineMenu *)p)->f129))->id;
            mats[2] = ((DatPersonaRecord *)yListSlotEntry(0, ((FclCombineMenu *)p)->f11E))->id;
            break;
        case 6:
            mats[5] = ((DatPersonaRecord *)yListSlotEntry(((FclCombineMenu *)p)->f11E + 1, 5))->id;
        case 5:
            mats[4] = ((DatPersonaRecord *)yListSlotEntry(((FclCombineMenu *)p)->f11E + 1, 4))->id;
        case 4:
            mats[0] = ((DatPersonaRecord *)yListSlotEntry(((FclCombineMenu *)p)->f11E + 1, 0))->id;
            /* measured: field typing changes 1863 normalized bytes in the full owner. */
            mats[1] = ((DatPersonaRecord *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, 1))->id;
            /* measured: field typing changes 1892 normalized bytes in the full owner. */
            mats[2] = ((DatPersonaRecord *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, 2))->id;
            /* measured: field typing changes 1892 normalized bytes in the full owner. */
            mats[3] = ((DatPersonaRecord *)yListSlotEntry(*(s16 *)(p + 0x11E) + 1, 3))->id;
            break;
        case 7:
            for (i = 0; i < 0xC; i++) {
                mats[i] = ((DatPersonaRecord *)yListSlotEntry(0, i))->id;
            }
            break;
        }
        fclCombineConsumeMaterials(task, mats);
        if (((FclCombineMenu *)p)->cardEffectTask != 0) {
            kwlnTaskDestroyWithHierarchy((KwlnTask *)(u32)((FclCombineMenu *)p)->cardEffectTask);
            /* measured: field typing changes 1679 normalized bytes in the full owner. */
            *(s32 *)(p + 0x304) = 0;
        }
        fclSpriteSetFlag(0x84, 0, 0);
        fclSpriteSetFlag(0x85, 0, 0);
        fclSpriteSetFlag(0x1C6, 0, 0);
        if (fclCombineClaimSlot(task) == 0) {
            if (((FclCombineMenu *)p)->drawTask.handle != 0) {
                /* measured: field typing changes 1610 normalized bytes in the full owner. */
                *(s32 *)(p + 0x148) = 0;
            }
            /* measured: field typing changes 1610 normalized bytes in the full owner. */
            *(s32 *)(p + 0x148) = fclDrawTaskCreate(task);
            fclCombineCreateSlotIcons(task, 0);
            w0 = fclMakeVec2(-78.0f, -82.0f);
            fclSpriteCreate(0x80, w0, 220.0f, 0x3F);
            c0 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(0x80))->color = c0;
            fclSpriteStartTweenAt(0x80, 0, 0x5A0, 0, 0.0f, -360.0f);
            fclSpriteSetFlag(0x80, 6, 0);
            *(fclSpriteEntry(0x80) + 0xDB) = 1;
            w1 = fclMakeVec2(2.0f, -2.0f);
            w2 = fclMakeVec2(-78.0f, -82.0f);
            fclSpriteStartPositionAt(0x80, w1, w2, 1, 0xA, 0);
            fclSpriteStartAlphaAt(0x80, 0, 0xFF, 2, 0xA, 0);
            w3 = fclMakeVec2(540.0f, (f32)347);
            fclSpriteCreate(0x20C, w3, 220.0f, 0x3F);
            c1 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(0x20C))->color = c1;
            fclSpriteStartTweenAt(0x20C, 0, 0x5A0, 0, 0.0f, -360.0f);
            fclSpriteSetFlag(0x20C, 6, 0);
            *(fclSpriteEntry(0x20C) + 0xDB) = 1;
            w4 = fclMakeVec2(460.0f, (f32)267);
            w5 = fclMakeVec2(540.0f, (f32)347);
            fclSpriteStartPositionAt(0x20C, w4, w5, 1, 0xA, 0);
            fclSpriteStartAlphaAt(0x20C, 0, 0xFF, 2, 0xA, 0);
            w6 = fclMakeVec2(-190.0f, 200.0f);
            fclSpriteCreate(0x81, w6, 215.0f, 0x56);
            c2 = fclMakeDrawColor(0x49, 0x72, 0xFF, 0xFF);
            ((FclCombineRowSprite *)fclSpriteEntry(0x81))->color = c2;
            ((FclCombineMenuSprite *)fclSpriteEntry(0x81))->value = 90.0f;
            base = (FclVec2f *)D_00640C50;
            w7 = fclMakeVec2(base->x, base->y);
            fclSpriteCreate(0x84, w7, 217.0f, 0x40);
            base = (FclVec2f *)D_00640C58;
            w8 = fclMakeVec2(base->x, base->y);
            fclSpriteCreate(0x85, w8, 218.0f, 0x40);
            fclCombineLayoutDetailSprites(task, 0);
            fclCombineFadeLabelSprites(task, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0);
            base = (FclVec2f *)D_00641660;
            w9 = fclMakeVec2(base->x, base->y);
            fclSpriteCreate(0x1C6, w9, 242.0f, 0x3D);
            fclSpriteStartAlphaAt(0x1C6, 0, 0x64, 0, 0xA, 0);
            ((FclCombineMenu *)p)->commandCursor = 0;
            ((FclCombineMenu *)p)->commandCount = 0;
            /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
            *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC4) = 1;
            /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
            *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC6) = 0x23;
            /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
            *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC8) = 0;
            ((FclCombineMenu *)p)->commandCount = ((FclCombineMenu *)p)->commandCount + 1;
            /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
            *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC4) = 2;
            /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
            *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC6) = 0x38;
            /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
            *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC8) = 1;
            ((FclCombineMenu *)p)->commandCount = ((FclCombineMenu *)p)->commandCount + 1;
            if (datGetFlag(0x1301) != 0) {
                /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
                *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC4) = 3;
                /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
                *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC6) = 0x51;
                /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
                *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC8) = 2;
                ((FclCombineMenu *)p)->commandCount = ((FclCombineMenu *)p)->commandCount + 1;
            }
            if (datGetFlag(0x1302) != 0) {
                /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
                *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC4) = 4;
                /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
                *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC6) = 0x51;
                /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
                *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC8) = 3;
                ((FclCombineMenu *)p)->commandCount = ((FclCombineMenu *)p)->commandCount + 1;
            }
            if (datGetFlag(0x1303) != 0) {
                /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
                *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC4) = 5;
                /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
                *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC6) = 0x51;
                /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
                *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC8) = 4;
                ((FclCombineMenu *)p)->commandCount = ((FclCombineMenu *)p)->commandCount + 1;
            }
            if (datGetFlag(0x1304) != 0) {
                /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
                *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC4) = 6;
                /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
                *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC6) = 0x63;
                /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
                *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC8) = 5;
                ((FclCombineMenu *)p)->commandCount = ((FclCombineMenu *)p)->commandCount + 1;
            }
            /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
            *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC4) = 7;
            /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
            *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC6) = 0x6E;
            /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
            *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC8) = 6;
            ((FclCombineMenu *)p)->commandCount = ((FclCombineMenu *)p)->commandCount + 1;
            /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
            *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC4) = 9;
            /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
            *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC6) = 0xC2;
            /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
            *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC8) = 7;
            ((FclCombineMenu *)p)->commandCount = ((FclCombineMenu *)p)->commandCount + 1;
            /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
            *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC4) = 0xB;
            /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
            *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC6) = 0xD8;
            /* measured: commandRows indexing reverses addu operands (2 normalized bytes). */
            *(s16 *)((u8 *)(((FclCombineMenu *)p)->commandCount * 10) + (u32)p + 0xC8) = 8;
            ((FclCombineMenu *)p)->commandCount = ((FclCombineMenu *)p)->commandCount + 1;
            fclCombineLayoutTransition(task, 0);
            fclCombineSlideInSlotSprites(task, 0x96, 0);
            *p = 0;
            *(p + 1) = 0x1A;
        }
        break;
    case 0x97:
        if (nmMesWindowSlotStatus(((FclCombineMenu *)p)->fD) != 0) {
            /* measured: field typing changes 90 normalized bytes in the full owner. */
            nmMesWindowStepSlotRelease(*(s8 *)(p + 0xD));
        } else {
            /* measured: field typing changes 90 normalized bytes in the full owner. */
            nmMesWindowDestroySlot(*(s8 *)(p + 0xD));
            if (fclCombineClaimSlot(task) == 0) {
                *p = 0;
                *(p + 1) = 0x17;
            }
        }
        break;
    }
}

// Fcl combine recipe unlocked: returns 1 when all four prerequisite records of recipe slot 0x14 hold, else 0.
// FUN_00310480
s32 fclCombineRecipeUnlocked(void) {
    u16 *p;
    s8 *base;
    s16 i;
    s8 *e;

    if (!(cmmCommunityRecordValue(0x14) & 0xFFFF)) {
        return 0;
    }
    if ((cmmCommunityRecordValue(0x14) & 0xFFFF) == 0xA) {
        return 0;
    }
    base = (s8 *)D_00641880 + ((cmmCommunityRecordValue(0x14) & 0xFFFF) - 1) * 48;
    for (i = 0; i < 4; i++) {
        e = base + i * 12;
        switch (e[0]) {
        case 0:
            p = (u16 *)datPersonaFindRosterRecordById(((FclCombineRequirement *)e)->key.id);
            if (p != 0) {
                if (datPersonaFindSkillSlot((u8 *)p, (u16)((FclCombineRequirement *)e)->value.skillId) == -1) {
                    return 0;
                }
                break;
            }
            return 0;
        case 1:
            if ((datItemCount(((FclCombineRequirement *)base)[i].key.itemId) & 0xFF) < ((FclCombineRequirement *)base)[i].value.threshold) {
                return 0;
            }
            break;
        case 2:
            if ((cmmCommunityRecordValue(((FclCombineRequirement *)base)[i].key.id) & 0xFFFF) > ((FclCombineRequirement *)base)[i].value.threshold) {
                return 0;
            }
            break;
        case 4:
            if (((FclCombineRequirement *)e)->value.threshold == 0) {
                if (datGetFlag(((FclCombineRequirement *)e)->key.flag) != 0) {
                    return 0;
                }
                break;
            }
            if (((FclCombineRequirement *)e)->value.threshold == 1 && datGetFlag(((FclCombineRequirement *)e)->key.flag) == 0) {
                return 0;
            }
            break;
        case 3:
            if (datGetPersonaCacheCompletionPercent() > ((FclCombineRequirement *)e)->value.threshold) {
                return 0;
            }
            break;
        }
    }
    return 1;
}
// Fcl combine snapshot save: copies the persona records and the four combine flags into a work buffer.
// FUN_00310700
void fclCombineSaveSnapshot(void)
{
    s16 i;
    s16 j;

    chkmemAllocSiteTag(&D_00641B00[0], 0x2ABD);
    iGpffffb594 = D_008873F4[0](1, 0x3004, 0x40000);
    memset(iGpffffb594, 0, 0x3000);
    i = 0;
    while (i < 0x100) {
        if (datPersonaCachedRecord(i) != 0) {
            j = (s16)i;
            memcpy(iGpffffb594 + (s32)j * 0x30, datPersonaCachedRecord(j), 0x30);
        }
        i++;
    }
    i = 0;
    while (i < 4) {
        ((FclCombineSnapshot *)iGpffffb594)->claimedSlots[i] = 0;
        if (datGetFlag((s16)i + 0x1309) != 0) {
            ((FclCombineSnapshot *)iGpffffb594)->claimedSlots[i] = 1;
        }
        i++;
    }
}

// Fcl combine snapshot restore: writes back the saved persona records and flags, then frees the buffer.
// FUN_00310850
void fclCombineRestoreSnapshot(void)
{
    s16 i;

    if (iGpffffb594 == NULL) {
        return;
    }
    i = 0;
    while (i < 0x100) {
        datPersonaCacheRecord(iGpffffb594 + i * 0x30);
        i++;
    }
    i = 0;
    while (i < 4) {
        if ((s8)((FclCombineSnapshot *)iGpffffb594)->claimedSlots[i] == 1) {
            datItemSetCount((s16)(i + 0x464), 1);
            datSetFlag(i + 0x1309, 1);
        }
        i++;
    }
    jtbl_008873EC[0](iGpffffb594);
    iGpffffb594 = NULL;
}

/* Open messageId; refreshWindow == 1 initializes its parameters and refreshes it. */
// FUN_00310960
/* Historical whole-layout probe: 109 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
void fclCombinePlayCue(u8 *task, s32 messageId, s32 refreshWindow)
{
    u8 *p;
    s8 t;

    p = ((KwlnTask *)task)->work;
    ((FclCombineMenu *)p)->fD = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
    /* measured: field typing changes 109 normalized bytes in the full owner. */
    t = *(s8 *)(p + 0xD);
    nmMesWindowShowSlotRecord(t, (s8)messageId);
    if ((s8)refreshWindow == 1) {
        /* measured: field typing changes 110 normalized bytes in the full owner. */
        nmMesWindowSetSlotParam(*(s8 *)(p + 0xD), 0);
        /* measured: field typing changes 110 normalized bytes in the full owner. */
        nmMesWindowSetSlotFlag(*(s8 *)(p + 0xD), 0);
        nmMesWindowRequestRefresh();
    }
}
/* measured: u16 class id, as its three callers pass it (raw lhu). With
   func_00109280(u16), the row index masks into a temp, as retail does. */
/* Choose message 0x2B/0x2C/0x2D from today's date and the persona arcana's date window. */
// FUN_00310A10
void fclCombinePlayResultCue(u8 *task, u16 personaId) {
    s8 *menuWork = ((s8*)((KwlnTask *)task)->work);
    s8 *windowDates;
    s32 currentDate;
    s32 startDate;
    s32 endDate;
    u8 arcana;

    currentDate = D_00749480[fclCalendarMonth() & 0xFF] * 100 + (fclCalendarDay() & 0xFF);
    arcana = iGpffffb3d4[personaId * 14 + 2];
    windowDates = D_00641A60 + arcana * 4;
    startDate = D_00749480[windowDates[0]] * 100 + windowDates[1];
    endDate = D_00749480[windowDates[2]] * 100 + windowDates[3];
    menuWork[0xD] = nmMesWindowAcquire((void *)fclCombineGetMesWindow());
    nmMesWindowSetSlotString(menuWork[0xD], 0, iGpffffb44c + (datPersonaGetArcana(personaId) & 0xFF) * 21);
    if (currentDate < startDate) {
        nmMesWindowShowSlotRecord(menuWork[0xD], 0x2B);
    } else if (currentDate >= endDate) {
        nmMesWindowShowSlotRecord(menuWork[0xD], 0x2D);
    } else {
        nmMesWindowShowSlotRecord(menuWork[0xD], 0x2C);
    }
    nmMesWindowSetSlotParam(menuWork[0xD], 0);
    nmMesWindowSetSlotFlag(menuWork[0xD], 0);
    nmMesWindowRequestRefresh();
}

// Fcl combine task update: state dispatch registered with the combine task; runs the current state (0-15).
// FUN_00310BF0
/* Historical whole-layout probe: 926 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
s32 fclCombineTaskUpdate(u8 *task) {
    s8 *p = ((s8*)((KwlnTask *)task)->work);
    u8 *q;
    u8 *t2;
    s32 r2;

    switch (p[0]) {
    case 1:
        p[0] = 2;
        if (((FclCombineTaskState *)p)->childTask != 0) {
            /* measured: field typing changes 944 normalized bytes in the full owner. */
            *(u32 *)(p + 0x1C) = 0;
        }
        /* measured: field typing changes 922 normalized bytes in the full owner. */
        *(u32 *)(p + 0x1C) = fclCombineMenuCreate(task);
        break;
    case 2:
        if (kwlnTaskIsLinked(((FclCombineTaskState *)p)->childTask) == 0) {
            p[0] = 0;
            p[0] = 5;
        }
        break;
    case 3:
        fadeBeginReturnTransition(1, 0);
        p[0] = 4;
        /* fallthrough */
    case 4:
        if (fadeStatus() != 0) {
            p[0] = 1;
        }
        break;
    case 5:
        fadeBeginTransition(1, 0);
        p[0] = 6;
        /* fallthrough */
    case 6:
        if (fadeStatus() != 0) {
            return -1;
        }
        break;
    case 7:
        if (nmMesWindowSlotStatus(p[0xD]) != 0) {
            nmMesWindowStepSlotRelease(p[0xD]);
        } else {
            nmMesWindowDestroySlot(p[0xD]);
            p[0] = 1;
        }
        break;
    case 8:
        if (H_Cdvd_IsFileLoaded(((FclCombineTaskState *)p)->directory.pointer) != 0) {
            if ((fclCalendarMonth() & 0xFF) == 3 && (fclCalendarDay() & 0xFF) >= 0x14 && (fclCalendarDay() & 0xFF) < 0x20) {
                if (datGetFlag(0x1459) == 0) {
                    fieldSceneLoad(8, 3);
                    fieldSceneRequestRoom(1);
                }
                p[0] = 9;
                return 0;
            }
            if (datGetFlag(0x413) == 0 && datGetFlag(0x96F) != 0 && datCategoryRank(1) >= 3) {
                if (((FclCombineTaskState *)p)->childTask != 0) {
                    /* measured: field typing changes 627 normalized bytes in the full owner. */
                    *(u32 *)(p + 0x1C) = 0;
                }
                /* measured: field typing changes 958 normalized bytes in the full owner. */
                *(u32 *)(p + 0x1C) = fclCombineEventSceneCreate(task, 0x294, 0xA);
                datSetFlag(0x413, 1);
                if (!(cmmCommunityRecordValue(0x14) & 0xFFFF)) {
                    cmmCommunityAllocRecord(0x14);
                }
                p[0] = 0xB;
                sdkSndPlayCue(0x14, 1);
                return 0;
            }
            if (datGetFlag(0x1459) == 0) {
                fieldSceneLoad(8, 3);
                fieldSceneRequestRoom(1);
            }
            p[0] = 9;
        }
        break;
    case 9:
        if (fieldSceneLoadStep() != 0) {
            q = MT_Scene_GetResListHead(3);
            while (q != 0) {
                if ((*(u16 *)q & 0x3FF) == 0x38) {
                    mdlDispatchAnimIfPresent((u8*)(u32)((SceneCharacterUpdate *)q)->model, 0, 0xD, 0, 1);
                }
                q = (u8 *)((SceneUpdateResource *)q)->next;
            }
            if (datGetFlag(0x1459) == 0) {
                K_View_SetFov(kwlnGetCamera(), MT_Scene_GetCameraFov());
                t2 = kwlnGetCamera();
                r2 = MT_Scene_GetCameraResFirst();
                func_003e9cb0(((FclCombineCamera *)t2)->unk4, r2, 0);
            }
            fclCombineCdvdTaskCreate();
            sdkSndPlayCue(0x14, 1);
            p[0] = 0xA;
        }
        break;
    case 10:
        if (fclCombineInPreviewState() != 0) {
            if ((fclCalendarMonth() & 0xFF) == 3 && (fclCalendarDay() & 0xFF) >= 0x14 && (fclCalendarDay() & 0xFF) < 0x20) {
                p[0] = 0;
                p[0] = 3;
            } else if (fclCombineRecipeUnlocked() == 1) {
                if (((FclCombineTaskState *)p)->childTask != 0) {
                    /* measured: field typing changes 267 normalized bytes in the full owner. */
                    *(u32 *)(p + 0x1C) = 0;
                }
                /* measured: field typing changes 999 normalized bytes in the full owner. */
                *(u32 *)(p + 0x1C) = fclCombineEventSceneCreate(task, 0x294, 1);
                p[0] = 0xE;
            } else {
                p[0] = 0;
                p[0] = 3;
            }
        }
        break;
    case 11:
        if (kwlnTaskIsLinked(((FclCombineTaskState *)p)->childTask) == 0) {
            return -1;
        }
        break;
    case 12:
        if (fadeStatus() != 0) {
            return -1;
        }
        break;
    case 14:
        if (kwlnTaskIsLinked(((FclCombineTaskState *)p)->childTask) == 0) {
            p[0xD] = nmMesWindowAcquire((void *)(u32)((HCdvdRequest *)((FclCombineTaskState *)p)->directory.pointer)->data);
            nmMesWindowShowSlotRecord(p[0xD], (cmmCommunityRecordValue(0x14) & 0xFFFF) - 2);
            p[0] = 0xF;
        }
        break;
    case 15:
        if (nmMesWindowSlotStatus(p[0xD]) != 0) {
            nmMesWindowStepSlotRelease(p[0xD]);
        } else {
            nmMesWindowDestroySlot(p[0xD]);
            if ((cmmCommunityRecordValue(0x14) & 0xFFFF) == 0xA) {
                datItemSetCount(0x4A2, ((datItemCount(0x4A2) & 0xFF) + 1) & 0xFF);
            }
            p[0] = 0;
            p[0] = 1;
        }
        break;
    }
    return 0;
}
// Fcl combine task destroy: releases the CDVD handle and frees the task work block.
// FUN_003111D0
/* Historical whole-layout probe: 5 normalized bytes differed (2026-10-18).
   Access-site typing now isolates only the measured raw exceptions below. */
void fclCombineTaskDestroy(u8 *task)
{
    u8 *p;

    p = ((KwlnTask *)task)->work;
    if (datGetFlag(0x1459) == 0) {
        fieldSceneUnload();
    }
    if (kwlnTaskGetTaskByName(D_00641BC8) != 0) {
        fclCombineRequestRefresh();
    }
    H_Cdvd_Destroy(((FclCombineTaskState *)p)->directory.pointer);
    /* measured: field typing changes 5 normalized bytes in the full owner. */
    jtbl_008873EC[0](*(u8 **)(task + 0x38));
}

/* measured: full body now MATCH (object 1688B, retail window 1696B).
   Retail reuses the resource pointer register as the first loop index, then
   rotates the later loop index/flag pair. Separate first/later locals,
   explicit skip labels for the b5b0 threshold guard, and the <=-equivalent
   `found > b5b0` spelling reproduce the saved-register and slt shapes. */
// Fcl combine task create: creates the combine task with fclCombineTaskUpdate/Destroy, initialises its state, and runs the unlock and roster setup when flag 0x1463 is set.
// FUN_00311260
s32 fclCombineTaskCreate(u8 *parentTask)
{
    u8 *p;
    s32 i;
    s32 found;
    s32 found2;
    s32 i2;
    s32 result;

    result = (s32)parentTask;
    found = 0;
    chkmemAllocSiteTag(&D_00641B00[0], 0x2C88);
    p = D_008873F4[0](1, 0x2C, 0x40000);
    result = (s32)kwlnTaskCreateChild((void *)((void *)(result)), (const void *)(D_00641BE0), 0xF, 0, 0, fclCombineTaskUpdate, fclCombineTaskDestroy, (u8 *)(p));
    p[0] = 8;
    func_00440b68(&iGpffffa8c8, D_00641B00, 0x2C96);
    ((FclCombineTaskState *)p)->directory.handle = H_Cdvd_AcquireDirectory(D_00641C00, 0);
    sdkSndFadeOutChannelFrames(3, 0, 0x1E);
    ((FclCombineTaskState *)p)->unk4 = 0x41000000;
    ((FclCombineTaskState *)p)->unk8 = 0x41200000;
    ((FclCombineTaskState *)p)->unkC = 0;
    ((FclCombineTaskState *)p)->unk14 = 0;
    ((FclCombineTaskState *)p)->unk20 = 0x41000000;
    ((FclCombineTaskState *)p)->unk24 = 0x41200000;
    ((FclCombineTaskState *)p)->unk28 = 0;
    if (datGetClearedWord() != 0 &&
        datGetFlag(0x1DD) != 0 &&
        datGetFlag(0x1301) != 0 &&
        datGetFlag(0x1302) != 0 &&
        datGetFlag(0x1303) != 0) {
        datSetFlag(0x1304, 1);
    }
    if (datGetFlag(0x1463) != 0) {
        datSetHeroLevel(1, 0x63);
        datSetMoney(0xF4240);
        datSetFlag(0x1202, 1);
        datSetFlag(0x1305, 1);
        datSetFlag(0x1301, 1);
        datSetFlag(0x1302, 1);
        datSetFlag(0x1303, 1);
        datSetFlag(0x1304, 1);
        datSetFlag(0x131A, 1);
        datSetFlag(0x131B, 1);
        datSetFlag(0x131C, 1);
        datSetFlag(0x131D, 1);
        datSetFlag(0x131E, 1);
        datSetFlag(0x131F, 1);
        datSetFlag(0x1320, 1);
        datSetFlag(0x1321, 1);
        datSetFlag(0x1322, 1);
        i = 0;
        while (i < (u16)datPersonaCountValidMembers()) {
            if (((DatPersonaRecord *)(datPersonaRosterSlot((s16)i)))->id == 0x36) {
                found = 1;
            }
            i++;
        }
        if ((s8)found == 0) {
            found = (u16)datPersonaCountValidMembers();
            if (found > (u16)datPersonaRosterCapacity()) {
                goto loop_92;
            }
            datPersonaAddRosterMember(0x36);
        }
loop_92:
        found2 = 0;
        i2 = 0;
        while (i2 < (u16)datPersonaCountValidMembers()) {
            if (((DatPersonaRecord *)(datPersonaRosterSlot((s16)i2)))->id == 0x92) {
                found2 = 1;
            }
            i2++;
        }
        if ((s8)found2 == 0) {
            found2 = (u16)datPersonaCountValidMembers();
            if (found2 > (u16)datPersonaRosterCapacity()) {
                goto loop_17;
            }
            datPersonaAddRosterMember(0x92);
        }
loop_17:
        found2 = 0;
        i2 = 0;
        while (i2 < (u16)datPersonaCountValidMembers()) {
            if (((DatPersonaRecord *)(datPersonaRosterSlot((s16)i2)))->id == 0x17) {
                found2 = 1;
            }
            i2++;
        }
        if ((s8)found2 == 0) {
            found2 = (u16)datPersonaCountValidMembers();
            if (found2 > (u16)datPersonaRosterCapacity()) {
                goto loop_16;
            }
            datPersonaAddRosterMember(0x17);
        }
loop_16:
        found2 = 0;
        i2 = 0;
        while (i2 < (u16)datPersonaCountValidMembers()) {
            if (((DatPersonaRecord *)(datPersonaRosterSlot((s16)i2)))->id == 0x16) {
                found2 = 1;
            }
            i2++;
        }
        if ((s8)found2 == 0) {
            found2 = (u16)datPersonaCountValidMembers();
            if (found2 > (u16)datPersonaRosterCapacity()) {
                goto loop_D;
            }
            datPersonaAddRosterMember(0x16);
        }
loop_D:
        found2 = 0;
        i2 = 0;
        while (i2 < (u16)datPersonaCountValidMembers()) {
            if (((DatPersonaRecord *)(datPersonaRosterSlot((s16)i2)))->id == 0xD) {
                found2 = 1;
            }
            i2++;
        }
        if ((s8)found2 == 0) {
            found2 = (u16)datPersonaCountValidMembers();
            if (found2 > (u16)datPersonaRosterCapacity()) {
                goto loop_E;
            }
            datPersonaAddRosterMember(0xD);
        }
loop_E:
        found2 = 0;
        i2 = 0;
        while (i2 < (u16)datPersonaCountValidMembers()) {
            if (((DatPersonaRecord *)(datPersonaRosterSlot((s16)i2)))->id == 0xE) {
                found2 = 1;
            }
            i2++;
        }
        if ((s8)found2 == 0) {
            found2 = (u16)datPersonaCountValidMembers();
            if (found2 > (u16)datPersonaRosterCapacity()) {
                goto loop_70;
            }
            datPersonaAddRosterMember(0xE);
        }
loop_70:
        found2 = 0;
        i2 = 0;
        while (i2 < (u16)datPersonaCountValidMembers()) {
            if (((DatPersonaRecord *)(datPersonaRosterSlot((s16)i2)))->id == 0x70) {
                found2 = 1;
            }
            i2++;
        }
        if ((s8)found2 == 0) {
            found2 = (u16)datPersonaCountValidMembers();
            if (found2 > (u16)datPersonaRosterCapacity()) {
                goto done_70;
            }
            datPersonaAddRosterMember(0x70);
        }
done_70:;
    }
    return result;
}

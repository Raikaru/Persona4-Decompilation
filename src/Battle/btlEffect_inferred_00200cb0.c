#include "btl_ui_task_internal.h"
#include "datCalc_internal.h"
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

extern f32 sdkSpriteScaledWidth(u8 *arg0);
extern f32 sdkSpriteScaledHeight(u8 *arg0);

extern void btlEncounterInitParams(s32 arg0, u8 *arg1);
extern void btlGaugeInit(u8 *arg0, u8 *arg1);

extern void memset(void *destination, s32 value, u32 size);

static inline u8 *btlUiAddByteOffset(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}


extern u32 kwlnTaskGetWork();
extern f32 fGpffff815c;
extern f32 fGpffff83b0;

extern void btlUiDrawSpriteEntry(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1);
extern void btlEntryListFlush(u8 *arg0);
extern u8 *D_0076449C;
extern s32 iGpffffb448;
extern s32 D_0062656C[];
extern void btlPanelStartEntry(s32 arg0, s32 arg1);
extern void btlPanelStartValues(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void btlPanelMarkEntryStarted(s32 task);





extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00626C30[];
extern u8 D_00626500[];
extern u8 D_006265B0[];
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void memset(void *dst, s32 value, u32 size);

extern s32 btlUiTaskInit(u8 *task);
extern void btlUiTaskDestroy(u8 *task);
extern void btlUiInitComponents(s32 arg0, u8 *arg1);
extern s32 btlPacketBuildHitFlags(u8 *arg0);
extern void itfMesWindowReleaseIfActive(s32 arg0);
extern void sdkSpriteRelease(void *arg0);
extern void EffBattleSetHandlerTable(void *arg0, void *arg1);
extern u8 D_00625240[];
extern f32 fGpffff8184;
extern f32 fGpffff84a4;
extern f32 fGpffff81a8;
extern s32 btlUiIsOverlayReady(void);
typedef void (*BattleSelectionDraw)(u8 *work, s32 slot, f32 x, f32 y,
                                    u8 opacity, s32 highlighted, s32 showDetail);
extern void btlSelectionDrawSlideIn(u8 *work, u8 *state, f32 x, f32 y,
                         BattleSelectionDraw drawSelection);

extern void btlSelectionDrawList(u8 *arg0, u8 *arg1, f32 farg0, f32 farg1,
                          BattleSelectionDraw callback);
extern void btlPanelDrawEntry(u8 *work, s32 slot, f32 x, f32 y,
                         u8 opacity, s32 highlighted, s32 show_detail);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void (*D_00887300[])(u32 arg0, u32 arg1);
extern f32 fGpffff82e0, fGpffff82e4;
extern f32 D_008872F8[];
extern f32 D_00626890[][2];
extern s32 (*D_00887310[])(s32 primType, void *vertices, s32 count);


extern void btlUiSetRenderMode(s32 arg0);
extern void btlPanelDrawPersonaName(u8 *work, s32 slot, f32 x, f32 y,
                          u8 opacity, s32 highlighted, s32 showDetail);
extern void btlPanelDrawPersonaLevel(u8 *work, s32 slot, f32 x, f32 y,
                          u8 opacity, s32 highlighted, s32 showDetail);
extern u8 *iGpffffb3ac;

extern s32 D_00881444_abs[];
extern void func_0021be70(void *arg0);
extern void btlEncounterUpdateEntries(void *arg0);
extern void btlPanelNoOp(void *arg0);
extern void btlEntryListPrune(void *arg0);
extern void btlPanelUpdate(void *arg0);
extern f32 fGpffff8478;
extern f32 fGpffffb478;
extern void btlSelectionUpdateTransition(u8 *arg0);
extern void btlPanelLoadModels(void *arg0);
extern void func_0021b1e0(void *arg0);
extern void PrimAppendNode(u8 *arg0, u8 *arg1);
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
extern void btlEntryInit(u8 *arg0, s32 arg1);
extern void btlDamageDrawList(u8 *arg0, u8 *arg1);
extern void btlDamageDrawBadStatus(void);
extern void btlDamageDrawBars(s32 arg0, u8 *arg1);
extern void btlEncounterInitEntry(u8 *arg0, s32 arg1);
extern void btlPortraitDrawRoster(void);
extern void btlPanelInitRecord(u8 *arg0, s32 arg1);
extern void btlMessageDrawTimed(void);
extern void btlPanelClear(u8 *arg0, s32 arg1);
extern void btlPanelAnimate(void);
extern void btlPanelDrawFlourish(u8 *task, u8 *state);
extern void btlGaugeInitValue(u8 *arg0, s32 arg1);
extern void btlGaugeStepAll(s32 arg0, s32 *arg1);
extern void btlEffectInit(u8 *arg0, s32 arg1);
extern void btlAdvantageDrawPanel(u8 *drawPayload, s32 workAddress, void *callback);
extern s32 itfMesWindowInstall(void *arg0);
extern u8 D_006253B0[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0020; members 00200cb0-00201b00 */

extern void btlPanelInitWork(u8 *arg0, s32 arg1);
extern void btlPanelUpdate(void *arg0);
extern void btlPanelDrawFrame(s32 arg0, u8 *arg1);
extern void btlPanelDrawBackdropGrid(s32 arg0, u8 *arg1);
extern void func_0020b5a0(void);
extern void btlPanelDrawSkyFrame(s32 arg0, u8 *arg1);
extern void btlSelectionInitTransition(u8 *arg0, s32 arg1);
extern void btlSelectionUpdateTransition(u8 *arg0);
extern void btlSelectionDrawTargetFrame(u8 *arg0, u8 *arg1);
extern void btlSelectionPushEntry(u8 *arg0, s32 arg1, s32 *arg2, f32 *arg3, u16 arg4);
extern u8 *iGpffffb3b8;
f32 btlUiSpriteWidth(u8 *arg0, s32 arg1, s32 arg2);
f32 btlUiSpriteHeight(u8 *arg0, s32 arg1, s32 arg2);
// Intent: register the overlay-ready callback for the UI object. [inferred]
// FUN_00200CB0
void btlUiRegisterAvailability(void) {
    EffBattleSetHandlerTable((void *)&D_00625240, (void *)btlUiIsOverlayReady);
}

// Intent: report whether the overlay work block exists (used as availability callback). [inferred]
// FUN_00200CE0
s32 btlUiIsOverlayReady(void)
{
    return D_0076449C != NULL;
}

// Intent: task init callback; clears the per-component state blocks of the battle UI task. [inferred]
// FUN_00200CF0
s32 btlUiTaskInit(u8 *unusedTask)
{
    u8 *work;

    work = (u8 *)kwlnTaskGetWork();
    /* measured: typed node addresses schedule argument setup ahead of the link clears. */
    func_0021be70(((BtlUiTaskWork *)work)->advantage);
    ((BtlUiTaskWork *)work)->advantageNode.unk00 = 0;
    ((BtlUiTaskWork *)work)->advantageNode.unk04 = 0;
    PrimAppendNode(D_00795020, work + 0x9F0);
    ((BtlUiTaskWork *)work)->barsNode.unk00 = 0;
    ((BtlUiTaskWork *)work)->barsNode.unk04 = 0;
    PrimAppendNode(D_00795020, work + 0x7DC);
    if (((s32)((BtlBattleState *)iGpffffb3ac)->flags & 0x800) == 0) {
        return 0;
    }
    ((BtlUiTaskWork *)work)->badStatusNode.unk00 = 0;
    ((BtlUiTaskWork *)work)->badStatusNode.unk04 = 0;
    PrimAppendNode(D_00794FF0, work + 0x7AC);
    btlEncounterUpdateEntries(((BtlUiTaskWork *)work)->encounter);
    ((BtlUiTaskWork *)work)->portraitNode.unk00 = 0;
    ((BtlUiTaskWork *)work)->portraitNode.unk04 = 0;
    PrimAppendNode(D_00795020, work + 0x81C);
    btlPanelNoOp(((BtlUiTaskWork *)work)->message);
    ((BtlUiTaskWork *)work)->messageNode.unk00 = 0;
    ((BtlUiTaskWork *)work)->messageNode.unk04 = 0;
    PrimAppendNode(D_00795080, work + 0x88C);
    btlEntryListPrune(((BtlUiTaskWork *)work)->damage);
    ((BtlUiTaskWork *)work)->damageNode.unk00 = 0;
    ((BtlUiTaskWork *)work)->damageNode.unk04 = 0;
    PrimAppendNode(D_00795080, work + 0x77C);
    btlPanelUpdate(((BtlUiTaskWork *)work)->panel);
    ((BtlUiTaskWork *)work)->skyFrameNode.unk00 = 0;
    ((BtlUiTaskWork *)work)->skyFrameNode.unk04 = 0;
    PrimAppendNode(D_00794810, work + 0x6E0);
    ((BtlUiTaskWork *)work)->detailNode.unk00 = 0;
    ((BtlUiTaskWork *)work)->detailNode.unk04 = 0;
    PrimAppendNode(D_00794870, work + 0x6B0);
    ((BtlUiTaskWork *)work)->backdropNode.unk00 = 0;
    ((BtlUiTaskWork *)work)->backdropNode.unk04 = 0;
    PrimAppendNode(D_00794FF0, work + 0x680);
    ((BtlUiTaskWork *)work)->frameNode.unk00 = 0;
    ((BtlUiTaskWork *)work)->frameNode.unk04 = 0;
    PrimAppendNode(D_00795020, work + 0x650);
    btlSelectionUpdateTransition(((BtlUiTaskWork *)work)->selection);
    ((BtlUiTaskWork *)work)->selectionNode.unk00 = 0;
    ((BtlUiTaskWork *)work)->selectionNode.unk04 = 0;
    PrimAppendNode(D_00795020, work + 0x72C);
    btlPanelLoadModels(((BtlUiTaskWork *)work)->models);
    ((BtlUiTaskWork *)work)->flourishNode.unk00 = 0;
    ((BtlUiTaskWork *)work)->flourishNode.unk04 = 0;
    PrimAppendNode(D_00794FF0, work + 0x980);
    ((BtlUiTaskWork *)work)->animateNode.unk00 = 0;
    ((BtlUiTaskWork *)work)->animateNode.unk04 = 0;
    PrimAppendNode(D_00795020, work + 0x950);
    func_0021b1e0(((BtlUiTaskWork *)work)->gauge);
    ((BtlUiTaskWork *)work)->gaugeNode.unk00 = 0;
    ((BtlUiTaskWork *)work)->gaugeNode.unk04 = 0;
    PrimAppendNode(D_00795020, work + 0x9B4);
    return 0;
}

// Intent: task destroy callback; releases the sprites and window, then frees the task block. [inferred]
// FUN_00200F30
void btlUiTaskDestroy(u8 *unusedTask)
{
    u8 *work;
    s32 sprite;
    s32 slotIndex;
    work = (u8 *)kwlnTaskGetWork();
    btlEntryListFlush(((BtlUiTaskWork *)work)->damage);
    slotIndex = 0;
    goto loop_test;
loop_body:
    sprite = ((BtlUiSprite *)work)->sprites[slotIndex];
    if (sprite != 0) {
        sdkSpriteRelease((void *)sprite);
    }
    slotIndex += 1;
loop_test:
    if (slotIndex < 0xC) {
        goto loop_body;
    }
    goto loop_done;
loop_done:
    itfMesWindowReleaseIfActive(((BtlUiTaskWork *)work)->messageWindow);
    jtbl_008873EC[0](work);
}

// Intent: wire each battle UI component's init and owner pointers, then install its message window. [inferred]
// FUN_00200FD0
void btlUiInitComponents(s32 task, u8 *work)
{
    u8 *panel;
    u8 *damage;
    u8 *models;

    /* measured: repeating typed component addresses keeps them live across init calls in s0. */
    btlPanelInitWork(((BtlUiTaskWork *)work)->panel, task);
    ((BtlUiTaskWork *)work)->frameNode.callback = (void *)btlPanelDrawFrame;
    panel = work + 0x9C;
    ((BtlUiTaskWork *)work)->frameNode.work = panel;
    ((BtlUiTaskWork *)work)->backdropNode.callback = (void *)btlPanelDrawBackdropGrid;
    ((BtlUiTaskWork *)work)->backdropNode.work = panel;
    ((BtlUiTaskWork *)work)->detailNode.callback = (void *)func_0020b5a0;
    ((BtlUiTaskWork *)work)->detailNode.work = panel;
    ((BtlUiTaskWork *)work)->skyFrameNode.callback = (void *)btlPanelDrawSkyFrame;
    ((BtlUiTaskWork *)work)->skyFrameNode.work = panel;
    btlSelectionInitTransition(((BtlUiTaskWork *)work)->selection, task);
    ((BtlUiTaskWork *)work)->selectionNode.callback = (void *)btlSelectionDrawTargetFrame;
    ((BtlUiTaskWork *)work)->selectionNode.work = work + 0x710;
    btlEntryInit(((BtlUiTaskWork *)work)->damage, task);
    ((BtlUiTaskWork *)work)->damageNode.callback = (void *)btlDamageDrawList;
    damage = work + 0x75C;
    ((BtlUiTaskWork *)work)->damageNode.work = damage;
    ((BtlUiTaskWork *)work)->badStatusNode.callback = (void *)btlDamageDrawBadStatus;
    ((BtlUiTaskWork *)work)->badStatusNode.work = damage;
    ((BtlUiTaskWork *)work)->barsNode.callback = (void *)btlDamageDrawBars;
    ((BtlUiTaskWork *)work)->barsNode.work = damage;
    btlEncounterInitEntry(((BtlUiTaskWork *)work)->encounter, task);
    ((BtlUiTaskWork *)work)->portraitNode.callback = (void *)btlPortraitDrawRoster;
    ((BtlUiTaskWork *)work)->portraitNode.work = work + 0x80C;
    btlPanelInitRecord(((BtlUiTaskWork *)work)->message, task);
    ((BtlUiTaskWork *)work)->messageNode.callback = (void *)btlMessageDrawTimed;
    ((BtlUiTaskWork *)work)->messageNode.work = work + 0x84C;
    btlPanelClear(((BtlUiTaskWork *)work)->models, task);
    ((BtlUiTaskWork *)work)->animateNode.callback = (void *)btlPanelAnimate;
    models = work + 0x8C0;
    ((BtlUiTaskWork *)work)->animateNode.work = models;
    ((BtlUiTaskWork *)work)->flourishNode.callback = (void *)btlPanelDrawFlourish;
    ((BtlUiTaskWork *)work)->flourishNode.work = models;
    btlGaugeInitValue(((BtlUiTaskWork *)work)->gauge, task);
    ((BtlUiTaskWork *)work)->gaugeNode.callback = (void *)btlGaugeStepAll;
    ((BtlUiTaskWork *)work)->gaugeNode.work = work + 0x9B0;
    btlEffectInit(((BtlUiTaskWork *)work)->advantage, task);
    ((BtlUiTaskWork *)work)->advantageNode.callback = (void *)btlAdvantageDrawPanel;
    ((BtlUiTaskWork *)work)->advantageNode.work = work + 0x9E4;
    ((BtlUiSprite *)work)->red = 0xFF;
    ((BtlUiSprite *)work)->green = 0xFF;
    ((BtlUiSprite *)work)->blue = 0xFF;
    ((BtlUiSprite *)work)->factorX = 1.0f;
    ((BtlUiSprite *)work)->factorY = 1.0f;
    ((BtlUiSprite *)work)->scaleX = 1.0f;
    ((BtlUiSprite *)work)->scaleY = 1.0f;
    ((BtlUiTaskWork *)work)->messageWindow = itfMesWindowInstall(D_006253B0);
}

// Intent: allocate the battle UI task block and create its child task. [inferred]
// FUN_002011C0
s32 btlUiCreateTask(s32 parentTask)
{
    u8 *work;
    s32 task;

    chkmemAllocSiteTag(&D_006265B0, 0x3A);
    work = (u8 *)(*jtbl_008873E8)(0xA20, 0x40000);
    memset(work, 0, 0xA20);
    task = (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(&D_00626500), 0xF, 0, 0, btlUiTaskInit, btlUiTaskDestroy, (u8 *)(work));
    btlUiInitComponents(task, work);
    return task;
}

// Intent: initialise the sprite pair at offset +0x18 of a UI component. [inferred]
// FUN_00201280
void btlUiInitSpritePair(u8 *task, u8 *work) {
    btlEncounterInitParams((s32)task, work);
    btlGaugeInit(task, work + 0x18);
}

// Intent: store two floats as integer origin and clear the following offset words. [inferred]
// FUN_002012D0
void btlUiSetOrigin(u8 *work, f32 x, f32 y) {
    ((BtlUiSprite *)work)->originX = (s32)x;
    ((BtlUiSprite *)work)->originY = (s32)y;
    ((BtlUiSprite *)work)->width = 0;
    ((BtlUiSprite *)work)->height = 0;
}

// Intent: store four float values as integer rectangle fields. [inferred]
// FUN_00201300
void btlUiSetRect(s32 *work, f32 x, f32 y, f32 width, f32 height) {
    ((BtlUiSprite *)work)->originX = (s32)x;
    ((BtlUiSprite *)work)->originY = (s32)y;
    ((BtlUiSprite *)work)->width = (s32)width;
    ((BtlUiSprite *)work)->height = (s32)height;
}

/* measured: caching D_00887300 in s0 reproduces retail's one-time
   lui/addiu vtable materialization across these callback calls. */
/* measured: btlUiSetRenderStates MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// Intent: set the fixed battle render-state sequence through the D_00887300 table. [inferred]
// FUN_00201350
void btlUiSetRenderStates(void)
{
    void (**base)(u32, u32);

    btlUiSetRenderMode(0);
    base = D_00887300;
    base[0](7, 2);
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](1, 0);
}

/* measured: close the vtable propagation probe and restore default state. */
/* measured: btlUiDrawSpriteEntry, btlUiSetScale MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// Intent: draw the sprite for a table entry at the given screen position and scale. [inferred]
// FUN_00201410
void btlUiDrawSpriteEntry(u8 *work, s32 slot, s32 segment, f32 x, f32 y)
{
    u8 *entry;
    u32 offset;
    f32 value;

    /* measured: typed slot indexing reverses addu operands; repeated typed sprite fields
     * hoist field addresses across the draw call (596 vs 576 bytes). */
    offset = (u32)(slot * 4);
    entry = btlUiAddByteOffset(offset, work);
    ((BtlUiSprite *)work)->sprite = *(s32 *)(entry + 0x2C);
    ((BtlUiSprite *)work)->segment = segment;
    if ((((BtlUiSprite *)work)->factorX == 1.0f) &&
        (((BtlUiSprite *)work)->factorY == 1.0f)) {

        ((BtlUiSprite *)work)->x = (f32)((BtlUiSprite *)work)->originX + x;
        ((BtlUiSprite *)work)->y = (f32)((BtlUiSprite *)work)->originY + y;
        sdkSpriteDraw(work + 0x6C, 0);
        return;
    }
    *(f32 *)(work + 0x74) =
        (f32)*(s32 *)(work + 0x4) +
        ((f32)((BtlUiSprite *)work)->width *
         (1.0f - *(f32 *)(work + 0x14))) * 0.5f +
        *(f32 *)(work + 0x14) * x;
    *(f32 *)(work + 0x78) =
        (f32)*(s32 *)(work + 0x8) +
        ((f32)((BtlUiSprite *)work)->height *
         (1.0f - *(f32 *)(work + 0x18))) * 0.5f +
        *(f32 *)(work + 0x18) * y;
    value = *(f32 *)(work + 0x14) * 4096.0f * ((BtlUiSprite *)work)->scaleX;
    ((BtlUiSprite *)work)->fixedScaleX = (u16)value;
    value = *(f32 *)(work + 0x18) * 4096.0f * ((BtlUiSprite *)work)->scaleY;
    ((BtlUiSprite *)work)->fixedScaleY = (u16)value;
    if (((BtlUiSprite *)work)->tileFactor != 0.0f) {
        ((BtlUiSprite *)work)->tileX =
            (s16)(((BtlUiSprite *)work)->tileOffsetX * *(f32 *)(work + 0x14));
        ((BtlUiSprite *)work)->tileY =
            (s16)(((BtlUiSprite *)work)->tileOffsetY * *(f32 *)(work + 0x18));
    }
    sdkSpriteDraw(work + 0x6C, 0);
    *(u16 *)(work + 0x8C) = 0;
    *(u16 *)(work + 0x8E) = 0;
}

/* Keep the opacity base ahead of byte promotion, matching retail order. */
#pragma push
/* measured: btlUiDrawSpriteFaded MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// Intent: draw a battle sprite with per-channel colour and fade parameters. [inferred]
// FUN_00201650
void btlUiDrawSpriteFaded(u8 *work, s32 slot, s32 segment, f32 x, f32 y,
                   u8 red, u8 green, u8 blue, u8 opacity) {
    ((BtlUiSprite *)work)->red = (u8)red;
    ((BtlUiSprite *)work)->green = (u8)green;
    ((BtlUiSprite *)work)->blue = (u8)blue;
    {
        s32 maximum = 0xFF;
        ((BtlUiSprite *)work)->fade = maximum - (opacity & 0xFF);
    }
    btlUiDrawSpriteEntry(work, slot, segment, x, y);
    /* measured: typed resets retain four field addresses across draw (128 vs 96 bytes). */
    work[0x94] = 0xFF;
    work[0x95] = 0xFF;
    work[0x96] = 0xFF;
    work[0x7D] = 0;
}

#pragma pop
// Intent: add a delta to the tile-offset field of a segment. [inferred]
// FUN_002016B0
void btlUiAdjustTileOffset(s32 work, s32 slot, s32 segmentIndex, s32 delta) {
    u8 *table;
    u8 *base;
    u32 index;
    u32 offset;
    u8 *segment;

    /* measured: typed sprite-slot indexing changes addition/register allocation (10 differing bytes). */
    index = (u32)(slot * 4);
    table = (u8 *)(index + (u32)work + 0x2C);
    table = *(u8 **)table;
    offset = (u32)(segmentIndex << 7);
    base = ((SdkSpriteResource *)table)->segments;
    segment = (u8 *)(offset + (u32)base);
    ((SdkSpriteSegment *)segment)->tileOffset = delta + ((SdkSpriteSegment *)segment)->originalTileOffset;
}

/* The tile offset is converted from its full signed word for drawing;
 * only the stored halfword truncates it. Shared with cursor segments. */
// Intent: store the tile offset and its float mirror (see the note above). [inferred]
// FUN_002016E0
void btlUiSetTileOffset(u8 *work, s16 x, s32 y, f32 factor)
{
    ((BtlUiSprite *)work)->tileX = x;
    ((BtlUiSprite *)work)->tileY = y;
    ((BtlUiSprite *)work)->tileFactor = factor;
    ((BtlUiSprite *)work)->tileOffsetX = (f32)x;
    ((BtlUiSprite *)work)->tileOffsetY = (f32)y;
}

// Intent: set the x/y scale fields and their 4096-based fixed-point mirrors. [inferred]
// FUN_00201720
void btlUiSetScale(u8 *work, f32 x, f32 y)
{
    if ((x == 1.0f) && (y == 1.0f)) {
        ((BtlUiSprite *)work)->fixedScaleX = 0;
        ((BtlUiSprite *)work)->fixedScaleY = 0;
    } else {
        ((BtlUiSprite *)work)->fixedScaleX = (u16)(4096.0f * x);
        ((BtlUiSprite *)work)->fixedScaleY = (u16)(4096.0f * y);
    }
    ((BtlUiSprite *)work)->scaleX = x;
    ((BtlUiSprite *)work)->scaleY = y;
}

// Intent: select a render-state set by mode index. [inferred]
// FUN_00201820
void btlUiSetRenderMode(s32 mode)
{
    s32 modeIndex;

    modeIndex = mode & 0xFFFF;
    switch (modeIndex) {
    case 0:
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x717FB);
        return;
    case 1:
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x717FB);
        return;
    case 2:
        RpSkyRenderStateSet(2, 0x48);
        RpSkyRenderStateSet(3, 0x71801);
        return;
    case 3:
        RpSkyRenderStateSet(2, 0x42);
        RpSkyRenderStateSet(3, 0x71801);
        return;
    case 4:
        RpSkyRenderStateSet(2, 6);
        RpSkyRenderStateSet(3, 0x71801);
        return;
    }
}

// Intent: set the sprite id at the unit's slot and return the scaled sprite width. [inferred]
// FUN_00201950
f32 btlUiSpriteWidth(u8 *work, s32 slot, s32 segment)
{
    ((BtlUiSprite *)work)->sprite =
        /* measured: typed indexing reverses the retail addu operands. */
        *(s32 *)((u8 *)(slot * 4) + (u32)work + 0x2C);
    ((BtlUiSprite *)work)->segment = segment;
    return sdkSpriteScaledWidth(work + 0x6C);
}

// Intent: set the sprite id at the unit's slot and return the scaled sprite height. [inferred]
// FUN_00201990
f32 btlUiSpriteHeight(u8 *work, s32 slot, s32 segment)
{
    ((BtlUiSprite *)work)->sprite =
        /* measured: typed indexing reverses the retail addu operands. */
        *(s32 *)((u8 *)(slot * 4) + (u32)work + 0x2C);
    ((BtlUiSprite *)work)->segment = segment;
    return sdkSpriteScaledHeight(work + 0x6C);
}

// Intent: store the x/y scale factors used by the sprite draw path. [inferred]
// FUN_002019D0
void btlUiSetFactorXY(u8 *work, f32 x, f32 y)
{
    ((BtlUiSprite *)work)->factorX = x;
    ((BtlUiSprite *)work)->factorY = y;
}

// Intent: store the alpha value of a UI component. [inferred]
// FUN_002019E0
void btlUiSetAlpha(u8 *work, f32 alpha)
{
    ((BtlUiSprite *)work)->alpha = alpha;
}

// Intent: select the effect entry for a state index and start its playback. [inferred]
// FUN_002019F0
void btlUiSelectEffect(s32 unit, u32 entryId)
{
    u8 *battle;

    if (entryId < 0x1000U) {
        battle = D_0076449C;
        btlPanelStartValues(((BtlBattleState *)battle)->uiTask, unit,
                      ((BtlBattleState *)battle)->messageWindow, entryId);
        return;
    }
    btlPanelStartEntry(((BtlBattleState *)D_0076449C)->uiTask,
                  iGpffffb448 + (((entryId - 0x1000) & 0xFFFF) * 0x13));
    btlPanelMarkEntryStarted(((BtlBattleState *)D_0076449C)->uiTask);
}

// Intent: packet callback; bumps both unit counters and flags a bad-status hit. [inferred]
// FUN_00201A80
void btlPacketHitStatusCheck(u8 *work) {
    s32 unitData;
    u8 *source;
    u8 *target;

    source = (u8 *)((BtlHitDisplayWork *)work)->source;
    ((BtlUnit *)source)->pendingPacketCount = (u16) (((BtlUnit *)source)->pendingPacketCount + 1);
    target = (u8 *)((BtlHitDisplayWork *)work)->target;
    ((BtlUnit *)target)->pendingPacketCount = (u16) (((BtlUnit *)target)->pendingPacketCount + 1);
    unitData = (s32)((BtlUnit *)((BtlHitDisplayWork *)work)->target)->datUnit;
    if ((unitData != 0) && (datCalcChkBadStatus((DatUnit *)unitData, 0x100000) != 0)) {
        ((BtlHitDisplayWork *)work)->useHudAnchor = 1;
        return;
    }
    ((BtlHitDisplayWork *)work)->useHudAnchor = 0;
}

/* Measured: 676/688 bytes, seven resolved relocations and twelve zero alignment bytes.
 * Snapshot inputs before providers; reload the skill fields and final output
 * metadata at their retail callback boundaries. */
#pragma push
/* measured: btlPacketBuildHitFlags MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// Intent: packet callback; builds the hit display flags from the skill and status fields. [inferred]
// FUN_00201B00
s32 btlPacketBuildHitFlags(u8 *work)
{
    u16 flags;
    u32 inputFlags;
    s32 empty;
    s32 value0;
    s32 value1;
    struct { s32 value0; s32 value1; u16 flags; } result;
    f32 position[3];
    s32 value;
    u8 *table;
    s32 offset;

    extern u8 *iGpffffb3b8;
    extern s32 datCalcSkillElement(u8 *arg0, u16 arg1);
    extern s32 datCalcElementBit(s16 arg0);
    extern void btlUnitGetHudAnchor(BtlUnit *unit, RwV3d *position);
    extern void btlUnitGetAnimBoundsWorldCenter(BtlUnit *unit, RwV3d *position);
    extern void btlSelectionPushEntry(u8 *arg0, s32 arg1, s32 *arg2, f32 *arg3, u16 arg4);

    flags = 0;
    inputFlags = ((BtlHitDisplayWork *)work)->effect;
    if ((inputFlags & 4) ||
        (((BtlHitDisplayWork *)work)->value0 == 0 && ((BtlHitDisplayWork *)work)->value1 == 0 &&
         ((BtlHitDisplayWork *)work)->status == 0 && ((BtlHitDisplayWork *)work)->value3 == 0 &&
         ((BtlHitDisplayWork *)work)->value4 == 0)) {
        empty = 1;
    } else {
        empty = 0;
    }

    value0 = ((BtlHitDisplayWork *)work)->value0;
    if (value0 != 0) {
        flags |= 0x10;
    } else {
        value0 = 0;
    }

    value1 = ((BtlHitDisplayWork *)work)->value1;
    if (value1 != 0) {
        flags |= 0x20;
    } else {
        value1 = 0;
    }

    if (((BtlHitDisplayWork *)work)->hitCount == ((BtlHitDisplayWork *)work)->hitIndex + 1) {
        if (empty == 0) {
            value = ((BtlHitDisplayWork *)work)->targetFlags;
            if (value & 2) {
                flags |= 1;
            }
            if (value & 4) {
                flags |= 2;
            }
        }

        if (inputFlags & 0x100) {
            value = ((BtlHitDisplayWork *)work)->skill;
            if (value != -1 && (u8 *)((BtlUnit *)(u8 *)((BtlHitDisplayWork *)work)->source)->datUnit != NULL) {
                value = datCalcSkillElement((u8 *)((BtlUnit *)(u8 *)((BtlHitDisplayWork *)work)->source)->datUnit, value & 0xFFFF);
                value = datCalcElementBit((s16)value);
            } else {
                value = 0;
            }
            if (!(value & 0x1FE00)) {
                flags |= 8;
            } else {
                flags |= 4;
            }
        } else if (empty != 0) {
            flags |= 4;
        }

        if (((BtlHitDisplayWork *)work)->status & 0x100000) {
            flags |= 0x40;
        }
    }

    offset = ((BtlHitDisplayWork *)work)->skill;
    if (offset >= 0) {
        offset *= 0x28;
        table = iGpffffb3b8;
        value = ((DatSkillEntry *)((u32)offset + (u32)table))->unknown04[4];
        switch (value) {
        case 1:
        case 2:
            flags |= 0x80;
            break;
        }
        if (((DatSkillEntry *)(table + offset))->flags00 & 0x20) {
            flags &= 0xFFFB;
        }
    }

    result.value0 = value0;
    result.value1 = value1;
    result.flags = flags;
    if (((BtlHitDisplayWork *)work)->useHudAnchor != 0) {
        btlUnitGetHudAnchor((BtlUnit *)(u8 *)((BtlHitDisplayWork *)work)->target, (RwV3d *)position);
    } else {
        btlUnitGetAnimBoundsWorldCenter((BtlUnit *)(u8 *)((BtlHitDisplayWork *)work)->target, (RwV3d *)position);
    }

    /* measured: typing the final target reload hoists +4 across the anchor callback (684 vs 676 bytes). */
    btlSelectionPushEntry((u8 *)((BtlBattleState *)D_0076449C)->uiTask, *(s32 *)(work + 4),
                  (s32 *)&result, position, ((BtlHitDisplayWork *)work)->flags);
    return 1;
}
#pragma pop

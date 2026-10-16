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

extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern void btlEncounterInitParams(s32 arg0, u8 *arg1);
extern void btlGaugeInit(u8 *arg0, u8 *arg1);

extern void memset(void *destination, s32 value, u32 size);

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
extern void func_00216e50(void *arg0);
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

/* Source unit: src/promoted/code1_0020.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0020.c; members 00200cb0-00201b00 */

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
    u8 *temp_2;

    temp_2 = (u8 *)kwlnTaskGetWork();
    func_0021be70(temp_2 + 0x9E4);
    *(s32 *)(temp_2 + 0x9F0) = 0;
    *(s32 *)(temp_2 + 0x9F4) = 0;
    PrimAppendNode(D_00795020, temp_2 + 0x9F0);
    *(s32 *)(temp_2 + 0x7DC) = 0;
    *(s32 *)(temp_2 + 0x7E0) = 0;
    PrimAppendNode(D_00795020, temp_2 + 0x7DC);
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x800) == 0) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x7AC) = 0;
    *(s32 *)(temp_2 + 0x7B0) = 0;
    PrimAppendNode(D_00794FF0, temp_2 + 0x7AC);
    btlEncounterUpdateEntries(temp_2 + 0x80C);
    *(s32 *)(temp_2 + 0x81C) = 0;
    *(s32 *)(temp_2 + 0x820) = 0;
    PrimAppendNode(D_00795020, temp_2 + 0x81C);
    func_00216e50(temp_2 + 0x84C);
    *(s32 *)(temp_2 + 0x88C) = 0;
    *(s32 *)(temp_2 + 0x890) = 0;
    PrimAppendNode(D_00795080, temp_2 + 0x88C);
    btlEntryListPrune(temp_2 + 0x75C);
    *(s32 *)(temp_2 + 0x77C) = 0;
    *(s32 *)(temp_2 + 0x780) = 0;
    PrimAppendNode(D_00795080, temp_2 + 0x77C);
    btlPanelUpdate(temp_2 + 0x9C);
    *(s32 *)(temp_2 + 0x6E0) = 0;
    *(s32 *)(temp_2 + 0x6E4) = 0;
    PrimAppendNode(D_00794810, temp_2 + 0x6E0);
    *(s32 *)(temp_2 + 0x6B0) = 0;
    *(s32 *)(temp_2 + 0x6B4) = 0;
    PrimAppendNode(D_00794870, temp_2 + 0x6B0);
    *(s32 *)(temp_2 + 0x680) = 0;
    *(s32 *)(temp_2 + 0x684) = 0;
    PrimAppendNode(D_00794FF0, temp_2 + 0x680);
    *(s32 *)(temp_2 + 0x650) = 0;
    *(s32 *)(temp_2 + 0x654) = 0;
    PrimAppendNode(D_00795020, temp_2 + 0x650);
    btlSelectionUpdateTransition(temp_2 + 0x710);
    *(s32 *)(temp_2 + 0x72C) = 0;
    *(s32 *)(temp_2 + 0x730) = 0;
    PrimAppendNode(D_00795020, temp_2 + 0x72C);
    btlPanelLoadModels(temp_2 + 0x8C0);
    *(s32 *)(temp_2 + 0x980) = 0;
    *(s32 *)(temp_2 + 0x984) = 0;
    PrimAppendNode(D_00794FF0, temp_2 + 0x980);
    *(s32 *)(temp_2 + 0x950) = 0;
    *(s32 *)(temp_2 + 0x954) = 0;
    PrimAppendNode(D_00795020, temp_2 + 0x950);
    func_0021b1e0(temp_2 + 0x9B0);
    *(s32 *)(temp_2 + 0x9B4) = 0;
    *(s32 *)(temp_2 + 0x9B8) = 0;
    PrimAppendNode(D_00795020, temp_2 + 0x9B4);
    return 0;
}

// Intent: task destroy callback; releases the sprites and window, then frees the task block. [inferred]
// FUN_00200F30
void btlUiTaskDestroy(u8 *unusedTask)
{
    u8 *temp_2;
    s32 temp_4;
    s32 var_16;
    temp_2 = (u8 *)kwlnTaskGetWork();
    btlEntryListFlush(temp_2 + 0x75C);
    var_16 = 0;
    goto loop_test;
loop_body:
    temp_4 = *(s32 *)(temp_2 + (var_16 * 4) + 0x2C);
    if (temp_4 != 0) {
        sdkSpriteRelease((void *)temp_4);
    }
    var_16 += 1;
loop_test:
    if (var_16 < 0xC) {
        goto loop_body;
    }
    goto loop_done;
loop_done:
    itfMesWindowReleaseIfActive(*(s32 *)(temp_2 + 0x98));
    jtbl_008873EC[0](temp_2);
}

// Intent: wire each battle UI component's init and owner pointers, then install its message window. [inferred]
// FUN_00200FD0
void btlUiInitComponents(s32 arg0, u8 *arg1)
{
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;

    btlPanelInitWork(arg1 + 0x9C, arg0);
    *(void **)(arg1 + 0x658) = (void *)btlPanelDrawFrame;
    temp_3 = arg1 + 0x9C;
    *(u8 **)(arg1 + 0x660) = temp_3;
    *(void **)(arg1 + 0x688) = (void *)btlPanelDrawBackdropGrid;
    *(u8 **)(arg1 + 0x690) = temp_3;
    *(void **)(arg1 + 0x6B8) = (void *)func_0020b5a0;
    *(u8 **)(arg1 + 0x6C0) = temp_3;
    *(void **)(arg1 + 0x6E8) = (void *)btlPanelDrawSkyFrame;
    *(u8 **)(arg1 + 0x6F0) = temp_3;
    btlSelectionInitTransition(arg1 + 0x710, arg0);
    *(void **)(arg1 + 0x734) = (void *)btlSelectionDrawTargetFrame;
    *(u8 **)(arg1 + 0x73C) = arg1 + 0x710;
    btlEntryInit(arg1 + 0x75C, arg0);
    *(void **)(arg1 + 0x784) = (void *)btlDamageDrawList;
    temp_3_2 = arg1 + 0x75C;
    *(u8 **)(arg1 + 0x78C) = temp_3_2;
    *(void **)(arg1 + 0x7B4) = (void *)btlDamageDrawBadStatus;
    *(u8 **)(arg1 + 0x7BC) = temp_3_2;
    *(void **)(arg1 + 0x7E4) = (void *)btlDamageDrawBars;
    *(u8 **)(arg1 + 0x7EC) = temp_3_2;
    btlEncounterInitEntry(arg1 + 0x80C, arg0);
    *(void **)(arg1 + 0x824) = (void *)btlPortraitDrawRoster;
    *(u8 **)(arg1 + 0x82C) = arg1 + 0x80C;
    btlPanelInitRecord(arg1 + 0x84C, arg0);
    *(void **)(arg1 + 0x894) = (void *)btlMessageDrawTimed;
    *(u8 **)(arg1 + 0x89C) = arg1 + 0x84C;
    btlPanelClear(arg1 + 0x8C0, arg0);
    *(void **)(arg1 + 0x958) = (void *)btlPanelAnimate;
    temp_3_3 = arg1 + 0x8C0;
    *(u8 **)(arg1 + 0x960) = temp_3_3;
    *(void **)(arg1 + 0x988) = (void *)btlPanelDrawFlourish;
    *(u8 **)(arg1 + 0x990) = temp_3_3;
    btlGaugeInitValue(arg1 + 0x9B0, arg0);
    *(void **)(arg1 + 0x9BC) = (void *)btlGaugeStepAll;
    *(u8 **)(arg1 + 0x9C4) = arg1 + 0x9B0;
    btlEffectInit(arg1 + 0x9E4, arg0);
    *(void **)(arg1 + 0x9F8) = (void *)btlAdvantageDrawPanel;
    *(u8 **)(arg1 + 0xA00) = arg1 + 0x9E4;
    *(u8 *)(arg1 + 0x94) = 0xFF;
    *(u8 *)(arg1 + 0x95) = 0xFF;
    *(u8 *)(arg1 + 0x96) = 0xFF;
    *(f32 *)(arg1 + 0x14) = 1.0f;
    *(f32 *)(arg1 + 0x18) = 1.0f;
    *(f32 *)(arg1 + 0x1C) = 1.0f;
    *(f32 *)(arg1 + 0x20) = 1.0f;
    *(s32 *)(arg1 + 0x98) = itfMesWindowInstall(D_006253B0);
}

// Intent: allocate the battle UI task block and create its child task. [inferred]
// FUN_002011C0
s32 btlUiCreateTask(s32 arg0)
{
    u8 *temp_2_2;
    s32 temp_2;

    chkmemAllocSiteTag(&D_006265B0, 0x3A);
    temp_2_2 = (u8 *)(*jtbl_008873E8)(0xA20, 0x40000);
    memset(temp_2_2, 0, 0xA20);
    temp_2 = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(&D_00626500), 0xF, 0, 0, btlUiTaskInit, btlUiTaskDestroy, (u8 *)(temp_2_2));
    btlUiInitComponents(temp_2, temp_2_2);
    return temp_2;
}

// Intent: initialise the sprite pair at offset +0x18 of a UI component. [inferred]
// FUN_00201280
void btlUiInitSpritePair(u8 *arg0, u8 *arg1) {
    btlEncounterInitParams((s32)arg0, arg1);
    btlGaugeInit(arg0, arg1 + 0x18);
}

// Intent: store two floats as integer origin and clear the following offset words. [inferred]
// FUN_002012D0
void btlUiSetOrigin(u8 *arg0, f32 fparg0, f32 fparg1) {
    *(s32 *)(arg0 + 4) = (s32)fparg0;
    *(s32 *)(arg0 + 8) = (s32)fparg1;
    *(s32 *)(arg0 + 0xC) = 0;
    *(s32 *)(arg0 + 0x10) = 0;
}

// Intent: store four float values as integer rectangle fields. [inferred]
// FUN_00201300
void btlUiSetRect(s32 *arg0, f32 fp0, f32 fp1, f32 fp2, f32 fp3) {
    arg0[1] = (s32)fp0;
    arg0[2] = (s32)fp1;
    arg0[3] = (s32)fp2;
    arg0[4] = (s32)fp3;
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
void btlUiDrawSpriteEntry(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1)
{
    u8 *entry;
    u32 offset;
    f32 value;

    offset = (u32)(arg1 * 4);
    entry = p4_002091f0_add(offset, arg0);
    *(s32 *)(arg0 + 0x6C) = *(s32 *)(entry + 0x2C);
    *(s32 *)(arg0 + 0x70) = arg2;
    if ((*(f32 *)(arg0 + 0x14) == 1.0f) &&
        (*(f32 *)(arg0 + 0x18) == 1.0f)) {

        *(f32 *)(arg0 + 0x74) = (f32)*(s32 *)(arg0 + 4) + fparg0;
        *(f32 *)(arg0 + 0x78) = (f32)*(s32 *)(arg0 + 8) + fparg1;
        sdkSpriteDraw(arg0 + 0x6C, 0);
        return;
    }
    *(f32 *)(arg0 + 0x74) =
        (f32)*(s32 *)(arg0 + 4) +
        ((f32)*(s32 *)(arg0 + 0x0C) *
         (1.0f - *(f32 *)(arg0 + 0x14))) * 0.5f +
        *(f32 *)(arg0 + 0x14) * fparg0;
    *(f32 *)(arg0 + 0x78) =
        (f32)*(s32 *)(arg0 + 8) +
        ((f32)*(s32 *)(arg0 + 0x10) *
         (1.0f - *(f32 *)(arg0 + 0x18))) * 0.5f +
        *(f32 *)(arg0 + 0x18) * fparg1;
    value = *(f32 *)(arg0 + 0x14) * 4096.0f * *(f32 *)(arg0 + 0x1C);
    *(u16 *)(arg0 + 0x8C) = (u16)value;
    value = *(f32 *)(arg0 + 0x18) * 4096.0f * *(f32 *)(arg0 + 0x20);
    *(u16 *)(arg0 + 0x8E) = (u16)value;
    if (*(f32 *)(arg0 + 0x84) != 0.0f) {
        *(s16 *)(arg0 + 0x88) =
            (s16)(*(f32 *)(arg0 + 0x24) * *(f32 *)(arg0 + 0x14));
        *(s16 *)(arg0 + 0x8A) =
            (s16)(*(f32 *)(arg0 + 0x28) * *(f32 *)(arg0 + 0x18));
    }
    sdkSpriteDraw(arg0 + 0x6C, 0);
    *(u16 *)(arg0 + 0x8C) = 0;
    *(u16 *)(arg0 + 0x8E) = 0;
}

/* Keep the opacity base ahead of byte promotion, matching retail order. */
#pragma push
/* measured: btlUiDrawSpriteFaded MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// Intent: draw a battle sprite with per-channel colour and fade parameters. [inferred]
// FUN_00201650
void btlUiDrawSpriteFaded(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1,
                   u8 arg5, u8 arg6, u8 arg7, u8 arg8) {
    arg0[0x94] = (u8)arg5;
    arg0[0x95] = (u8)arg6;
    arg0[0x96] = (u8)arg7;
    {
        s32 maximum = 0xFF;
        arg0[0x7D] = maximum - (arg8 & 0xFF);
    }
    btlUiDrawSpriteEntry(arg0, arg1, arg2, fparg0, fparg1);
    arg0[0x94] = 0xFF;
    arg0[0x95] = 0xFF;
    arg0[0x96] = 0xFF;
    arg0[0x7D] = 0;
}

#pragma pop
// Intent: add a delta to the tile-offset field of a segment. [inferred]
// FUN_002016B0
void btlUiAdjustTileOffset(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *table;
    u8 *base;
    u32 index;
    u32 offset;
    u8 *temp_4;

    index = (u32)(arg1 * 4);
    table = (u8 *)(index + (u32)arg0 + 0x2C);
    table = *(u8 **)table;
    offset = (u32)(arg2 << 7);
    base = *(u8 **)(table + 0x204);
    temp_4 = (u8 *)(offset + (u32)base);
    *(s32 *)(temp_4 + 0x5C) = arg3 + *(s32 *)(temp_4 + 0x54);
}

/* The tile offset is converted from its full signed word for drawing;
 * only the stored halfword truncates it. Shared with cursor segments. */
// Intent: store the tile offset and its float mirror (see the note above). [inferred]
// FUN_002016E0
void btlUiSetTileOffset(u8 *arg0, s16 arg1, s32 arg2, f32 fparg0)
{
    *(s16 *)(arg0 + 0x88) = arg1;
    *(s16 *)(arg0 + 0x8A) = arg2;
    *(f32 *)(arg0 + 0x84) = fparg0;
    *(f32 *)(arg0 + 0x24) = (f32)arg1;
    *(f32 *)(arg0 + 0x28) = (f32)arg2;
}

// Intent: set the x/y scale fields and their 4096-based fixed-point mirrors. [inferred]
// FUN_00201720
void btlUiSetScale(u8 *arg0, f32 fparg0, f32 fparg1)
{
    if ((fparg0 == 1.0f) && (fparg1 == 1.0f)) {
        *(s16 *)(arg0 + 0x8C) = 0;
        *(s16 *)(arg0 + 0x8E) = 0;
    } else {
        *(u16 *)(arg0 + 0x8C) = (u16)(4096.0f * fparg0);
        *(u16 *)(arg0 + 0x8E) = (u16)(4096.0f * fparg1);
    }
    *(f32 *)(arg0 + 0x1C) = fparg0;
    *(f32 *)(arg0 + 0x20) = fparg1;
}

// Intent: select a render-state set by mode index. [inferred]
// FUN_00201820
void btlUiSetRenderMode(s32 arg0)
{
    s32 temp_5;

    temp_5 = arg0 & 0xFFFF;
    switch (temp_5) {
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
f32 btlUiSpriteWidth(u8 *arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(arg0 + 0x6C) =
        *(s32 *)((u8 *)(arg1 * 4) + (u32)arg0 + 0x2C);
    *(s32 *)(arg0 + 0x70) = arg2;
    return sdkSpriteScaledWidth(arg0 + 0x6C);
}

// Intent: set the sprite id at the unit's slot and return the scaled sprite height. [inferred]
// FUN_00201990
f32 btlUiSpriteHeight(u8 *arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(arg0 + 0x6C) =
        *(s32 *)((u8 *)(arg1 * 4) + (u32)arg0 + 0x2C);
    *(s32 *)(arg0 + 0x70) = arg2;
    return sdkSpriteScaledHeight(arg0 + 0x6C);
}

// Intent: store the x/y scale factors used by the sprite draw path. [inferred]
// FUN_002019D0
void btlUiSetFactorXY(u8 *arg0, f32 fparg0, f32 fparg1)
{
    *(f32 *)(arg0 + 0x14) = fparg0;
    *(f32 *)(arg0 + 0x18) = fparg1;
}

// Intent: store the alpha value of a UI component. [inferred]
// FUN_002019E0
void btlUiSetAlpha(u8 *arg0, f32 fparg0)
{
    *(f32 *)(arg0 + 0x90) = fparg0;
}

// Intent: select the effect entry for a state index and start its playback. [inferred]
// FUN_002019F0
void btlUiSelectEffect(s32 arg0, u32 arg1)
{
    u8 *temp_2;

    if (arg1 < 0x1000U) {
        temp_2 = D_0076449C;
        btlPanelStartValues(*(s32 *)(temp_2 + 0xDD4), arg0,
                      *(s32 *)(temp_2 + 0xC60), arg1);
        return;
    }
    btlPanelStartEntry(*(s32 *)(D_0076449C + 0xDD4),
                  iGpffffb448 + (((arg1 - 0x1000) & 0xFFFF) * 0x13));
    btlPanelMarkEntryStarted(*(s32 *)(D_0076449C + 0xDD4));
}

// Intent: packet callback; bumps both unit counters and flags a bad-status hit. [inferred]
// FUN_00201A80
void btlPacketHitStatusCheck(u8 *arg0) {
    s32 temp_4;
    u8 *temp_5;
    u8 *temp_5_2;

    temp_5 = (u8 *)(*(u8 **)(arg0 + 0));
    *(u16 *)(temp_5 + 0xA0) = (u16) (*(u16 *)(temp_5 + 0xA0) + 1);
    temp_5_2 = (u8 *)(*(u8 **)(arg0 + 4));
    *(u16 *)(temp_5_2 + 0xA0) = (u16) (*(u16 *)(temp_5_2 + 0xA0) + 1);
    temp_4 = (s32)(*(s32 *)((u8 *)(*(u8 **)(arg0 + 4)) + 0xA64));
    if ((temp_4 != 0) && (datCalcChkBadStatus(temp_4, 0x100000) != 0)) {
        *(s32 *)(arg0 + 0x34) = 1;
        return;
    }
    *(s32 *)(arg0 + 0x34) = 0;
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
    u32 input_flags;
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
    input_flags = *(u16 *)(work + 0x2C);
    if ((input_flags & 4) ||
        (*(s32 *)(work + 8) == 0 && *(s32 *)(work + 0xC) == 0 &&
         *(s32 *)(work + 0x10) == 0 && *(s32 *)(work + 0x14) == 0 &&
         *(s32 *)(work + 0x18) == 0)) {
        empty = 1;
    } else {
        empty = 0;
    }

    value0 = *(s32 *)(work + 8);
    if (value0 != 0) {
        flags |= 0x10;
    } else {
        value0 = 0;
    }

    value1 = *(s32 *)(work + 0xC);
    if (value1 != 0) {
        flags |= 0x20;
    } else {
        value1 = 0;
    }

    if (*(u16 *)(work + 0x32) == *(u16 *)(work + 0x30) + 1) {
        if (empty == 0) {
            value = *(u16 *)(work + 0x2E);
            if (value & 2) {
                flags |= 1;
            }
            if (value & 4) {
                flags |= 2;
            }
        }

        if (input_flags & 0x100) {
            value = *(s32 *)(work + 0x28);
            if (value != -1 && *(u8 **)(*(u8 **)work + 0xA64) != NULL) {
                value = datCalcSkillElement(*(u8 **)(*(u8 **)work + 0xA64), value & 0xFFFF);
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

        if (*(s32 *)(work + 0x10) & 0x100000) {
            flags |= 0x40;
        }
    }

    offset = *(s32 *)(work + 0x28);
    if (offset >= 0) {
        offset *= 0x28;
        table = iGpffffb3b8;
        value = *(u8 *)((u32)offset + (u32)table + 8);
        switch (value) {
        case 1:
        case 2:
            flags |= 0x80;
            break;
        }
        if (*(u8 *)(table + offset) & 0x20) {
            flags &= 0xFFFB;
        }
    }

    result.value0 = value0;
    result.value1 = value1;
    result.flags = flags;
    if (*(s32 *)(work + 0x34) != 0) {
        btlUnitGetHudAnchor((BtlUnit *)*(u8 **)(work + 4), (RwV3d *)position);
    } else {
        btlUnitGetAnimBoundsWorldCenter((BtlUnit *)*(u8 **)(work + 4), (RwV3d *)position);
    }

    btlSelectionPushEntry(*(u8 **)(D_0076449C + 0xDD4), *(s32 *)(work + 4),
                  (s32 *)&result, position, *(u16 *)(work + 0x38));
    return 1;
}


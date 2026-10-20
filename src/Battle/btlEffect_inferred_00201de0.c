#include "btl_ui_task_internal.h"
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

extern s32 btlPacketFinishEffect(void);
extern void btlGaugeRefreshAll(s32);
extern void btlSelectionFlushEntries();


extern f32 fGpffff815c;
extern f32 fGpffff83b0;

extern u8 *D_0076449C;
extern s32 iGpffffb448;
extern s32 D_0062656C[];
extern void btlPanelStartEntry(s32 task, s32 text);
extern void btlPanelMarkEntryStarted(s32 task);


extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);


extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00626C30[];
extern u8 D_00626500[];
extern u8 D_006265B0[];

extern s32 btlPacketBuildHitFlags(u8 *work);
extern void btlUnitRotateTowardUnitPacketDestroy(void *work);
extern void memcpy(void *dst, const void *src, u32 size);
extern u8 D_00625240[];
extern f32 fGpffff8184;
extern f32 fGpffff84a4;
extern f32 fGpffff81a8;
typedef void (*BattleSelectionDraw)(u8 *work, s32 slot, f32 x, f32 y,
                                    u8 opacity, s32 highlighted, s32 showDetail);
extern void btlSelectionDrawSlideIn(u8 *work, u8 *selection, f32 x, f32 y,
                         BattleSelectionDraw drawSelection);

extern void btlSelectionDrawList(u8 *state, u8 *selectionState, f32 inputScaleX, f32 scaleY,
                          BattleSelectionDraw callback);
extern void btlPanelDrawEntry(u8 *work, s32 slot, f32 x, f32 y,
                         u8 opacity, s32 highlighted, s32 showDetail);
extern void (*D_00887300[])(u32 arg0, u32 arg1);
extern f32 fGpffff82e0, fGpffff82e4;
extern f32 D_008872F8[];
extern f32 D_00626890[][2];
extern s32 (*D_00887310[])(s32 primType, void *vertices, s32 count);


extern void btlPanelDrawPersonaName(u8 *work, s32 slot, f32 x, f32 y,
                          u8 opacity, s32 highlighted, s32 showDetail);
extern void btlPanelDrawPersonaLevel(u8 *work, s32 slot, f32 x, f32 y,
                          u8 opacity, s32 highlighted, s32 showDetail);
extern u8 *iGpffffb3ac;

extern s32 D_00881444_abs[];
extern f32 fGpffff8478;
extern f32 fGpffffb478;
extern u8 D_00794810[];
extern u8 D_00794870[];
extern u8 D_00794FF0[];
extern u8 D_00795020[];
extern u8 D_00795080[];

extern u8 D_006253B0[];

extern void btlPacketHitStatusCheck(u8 *work);
extern s32 btlPacketBuildHitFlags(u8 *work);
extern void btlSelectionFlushEntries();
/* measured: retail loads the vtable address once across these callback calls and computes the
 * opacity base before byte promotion. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Allocates a hit-display packet (type 0x50A) and fills its result record; flags and hit
 * index/count are unsigned halfwords, and the result record is copied unchanged. */
// FUN_00201DE0
u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags,
                  u16 hitIndex, u16 hitCount, const void *result, u16 flags)
{
    u8 *createdPacket;
    u8 *display;
    u8 *packet;

    packet = (u8 *)btlPacketAlloc(0x50A, 0x3C);
    createdPacket = packet;
    ((BtlPacket *)packet)->initFunc = (BtlPacketFunc)btlPacketHitStatusCheck;
    ((BtlPacket *)packet)->updateFunc = (BtlPacketFunc)btlPacketBuildHitFlags;
    ((BtlPacket *)packet)->destroyFunc = (BtlPacketFunc)btlUnitRotateTowardUnitPacketDestroy;
    display = (u8 *)((BtlPacket *)packet)->workData;
    memcpy(&((BtlHitDisplayWork *)display)->value0, result, 0x20);
    ((BtlHitDisplayWork *)display)->source = source;
    ((BtlHitDisplayWork *)display)->target = target;
    ((BtlHitDisplayWork *)display)->skill = id;
    ((BtlHitDisplayWork *)display)->effect = effect;
    ((BtlHitDisplayWork *)display)->targetFlags = targetFlags;
    ((BtlHitDisplayWork *)display)->hitIndex = hitIndex;
    ((BtlHitDisplayWork *)display)->hitCount = hitCount;
    ((BtlHitDisplayWork *)display)->flags = flags;
    return createdPacket;
}

// Packet callback; finishes the effect and the associated panel.
// FUN_00201EE0
s32 btlPacketFinishEffect(void)
{
    btlSelectionFlushEntries(((BtlBattleState *)D_0076449C)->uiTask);
    btlGaugeRefreshAll(((BtlBattleState *)D_0076449C)->uiTask);
    return 1;
}

// Allocates the finish-effect packet (type 0x50B).
// FUN_00201F20
u8 *btlPacketCreateFinishEffect(void)
{
    u8 *packet;

    packet = (u8 *)btlPacketAlloc(0x50B, 0);
    ((BtlPacket *)packet)->updateFunc = (BtlPacketFunc)btlPacketFinishEffect;
    return packet;
}

/* Packet callback that steps a sprite frame over 32 ticks, selecting the sprite from the table. */
// FUN_00201F60
s32 btlPacketStepSpriteFrame(u8 *work)
{
    u8 *battle;
    u32 elapsed;

    battle = D_0076449C;
    if (((s32)((BtlBattleState *)battle)->flags & 0x200) == 0) {
        return 1;
    }
    if (((BtlPanelPacketWork *)work)->elapsed == 0) {
        btlPanelStartEntry(((BtlBattleState *)battle)->uiTask,
                      iGpffffb448 + (((BtlPanelPacketWork *)work)->selector.index * 0x13));
        btlPanelMarkEntryStarted(((BtlBattleState *)D_0076449C)->uiTask);
    }
    elapsed = ((BtlPanelPacketWork *)work)->elapsed + 1;
    ((BtlPanelPacketWork *)work)->elapsed = elapsed;
    if (elapsed >= 0x20U) {
        return 1;
    }
    return 0;
}


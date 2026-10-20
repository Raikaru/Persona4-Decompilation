#include "member_access.h"
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


extern void btlPacketIncUnitCounter(u8 *work);
extern void btlPacketDecUnitCounter(u8 *work);


extern f32 fGpffff815c;
extern f32 fGpffff83b0;

extern u8 *D_0076449C;
extern s32 iGpffffb448;
extern s32 D_0062656C[];


extern s32 btlPacketSetHpRatio(u8 **work);
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00626C30[];
extern u8 D_00626500[];
extern u8 D_006265B0[];

extern s32 datCalcGetHp(s32 unit);
extern s32 datCalcMaxHp(s32 unit);
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

extern void btlPacketIncUnitCounter(u8 *work);
extern void btlPacketDecUnitCounter(u8 *work);
/* measured: retail loads the vtable address once across these callback calls and computes the
 * opacity base before byte promotion. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Second increment callback for the unit counter; same body as btlPacketIncUnitCounter. */
// FUN_00202620
void btlPacketIncUnitCounterAlt(u8 *work)
{
    ((BtlUnit *)((BtlHpRatioWork *)work)->unit)->pendingPacketCount = ((BtlUnit *)((BtlHpRatioWork *)work)->unit)->pendingPacketCount + 1;
}

// Packet callback; sets the HP ratio from the current HP and resets the marker fields.
// FUN_00202640
s32 btlPacketSetHpRatio(u8 **work)
{
    f32 maximumHp;
    f32 hp;
    u8 *unit;

    unit = *work;
    hp = (f32)(u32)datCalcGetHp((s32)((BtlUnit *)unit)->datUnit);
    maximumHp = (f32)(u32)datCalcMaxHp(MEMBER(s32, unit, BtlUnit, datUnit));
    ((BtlUnit *)unit)->hpRatio = hp / maximumHp;
    ((BtlUnit *)unit)->hpGauge.bits = (s32)0xBF800000;
    ((BtlUnit *)unit)->hpGaugeMarker = -1;
    return 1;
}

// Second decrement callback for the unit's pending packet count; same body as
// btlPacketDecUnitCounter.
// FUN_00202720
void btlPacketDecUnitCounterAlt(u8 *work)
{
    ((BtlUnit *)((BtlHpRatioWork *)work)->unit)->pendingPacketCount = ((BtlUnit *)((BtlHpRatioWork *)work)->unit)->pendingPacketCount + -1;
}


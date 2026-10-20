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






extern f32 fGpffff815c;
extern f32 fGpffff83b0;

extern u8 *D_0076449C;
extern s32 iGpffffb448;
extern s32 D_0062656C[];
extern void btlPanelStartEntry(s32 task, s32 text);
extern void btlPanelStartValues(s32 task, s32 unit, s32 window, s32 record);
extern void btlPanelMarkEntryStarted(s32 task);



extern s32 btlPacketStepEffectCounter(u8 *work);


extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00626C30[];
extern u8 D_00626500[];
extern u8 D_006265B0[];

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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0020; members 00202340-00202340 */

/* measured: caching D_00887300 in s0 reproduces retail's one-time
   lui/addiu vtable materialization across these callback calls. */
/* measured: close the vtable propagation probe and restore default state. */
/* Keep the opacity base ahead of byte promotion, matching retail order. */
#pragma push
#pragma pop
/* Measured: 676/688 bytes, seven resolved relocations and twelve zero alignment bytes.
 * Snapshot inputs before providers; reload the skill fields and final output
 * metadata at their retail callback boundaries. */
#pragma push
#pragma pop
/* measured: opt_rebuildconditionals off tested for callback completion. */
/* measured: restore conditional rebuilding after callback completion. */
// Intent: packet callback; steps an effect counter and redraws the effect entry. [inferred]
// FUN_00202340
s32 btlPacketStepEffectCounter(u8 *work)
{
    u32 elapsed;
    u32 entryId;
    s32 unit;
    u8 *battle;

    if (((BtlPanelPacketWork *)work)->elapsed == 0) {
        entryId = ((BtlPanelPacketWork *)work)->selector.value;
        unit = ((BtlPanelPacketWork *)work)->unit;
        if (entryId < 0x1000U) {
            battle = D_0076449C;
            btlPanelStartValues(((BtlBattleState *)battle)->uiTask,
                          unit,
                          ((BtlBattleState *)battle)->messageWindow, entryId);
        } else {
            btlPanelStartEntry(((BtlBattleState *)D_0076449C)->uiTask,
                          iGpffffb448 +
                              (((entryId - 0x1000) & 0xFFFF) * 0x13));
            btlPanelMarkEntryStarted(((BtlBattleState *)D_0076449C)->uiTask);
        }
    }
    elapsed = ((BtlPanelPacketWork *)work)->elapsed + 1;
    ((BtlPanelPacketWork *)work)->elapsed = elapsed;
    return elapsed >= 0x21U;
}


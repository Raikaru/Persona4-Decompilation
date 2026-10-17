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


extern f32 fGpffff815c;
extern f32 fGpffff83b0;

extern u8 *D_0076449C;
extern s32 iGpffffb448;
extern s32 D_0062656C[];
extern void btlPanelSetCountdown(s32 arg0, s32 arg1);
extern s32 datCalcUnitClass(u8 *arg0);
extern void btlPanelStartEntry(s32 arg0, s32 arg1);
extern void btlPanelMarkEntryStarted(s32 task);



extern s32 btlPacketStepSpriteTable(u8 *arg0);


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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0020; members 00202180-00202180 */

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
// Intent: packet callback; steps the sprite table for a unit, 16 or 32 ticks depending on class. [inferred]
// FUN_00202180
s32 btlPacketStepSpriteTable(u8 *arg0)
{
    s64 temp_4;
    s32 var_16;
    u16 temp_2;
    u8 *temp_3;

    if ((*(u16 *)(arg0 + 4) != 7) ||
        ((temp_3 = *(u8 **)arg0, (*(s32 *)(temp_3 + 0x9C) & 0x4000) == 0)) ||
        ((s16)datCalcUnitClass(*(u8 **)(temp_3 + 0xA64)) != 4)) {
        var_16 = 0;
    } else {
        var_16 = 1;
    }
    if (*(u32 *)(arg0 + 8) == 0) {
        temp_2 = *(u16 *)(arg0 + 4);
        if (temp_2 == 0) {
            return 1;
        }
        btlPanelStartEntry(*(s32 *)(D_0076449C + 0xDD4), D_0062656C[temp_2]);
        if (var_16 == 0) {
            btlPanelSetCountdown(*(s32 *)(D_0076449C + 0xDD4), 0x20);
        } else {
            btlPanelSetCountdown(*(s32 *)(D_0076449C + 0xDD4), 0x10);
        }
        btlPanelMarkEntryStarted(*(s32 *)(D_0076449C + 0xDD4));
    }
    *(u32 *)(arg0 + 8) = *(u32 *)(arg0 + 8) + 1;
    if (var_16 == 0) {
        if (*(u32 *)(arg0 + 8) >= 0x20U) {
            return 1;
        }
    } else if (*(u32 *)(arg0 + 8) >= 0x10U) {
        return 1;
    }
    return 0;
}


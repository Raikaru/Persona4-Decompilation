#include "btl_sound_internal.h"
#include "btl_target_internal.h"
#include "datCalc_unit_internal.h"
#include "list_item_internal.h"
#include "btl_camera_palette_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "rw/plcore/barenderstate.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "sdk_snd_internal.h"
#include "btl_target_state_packet_internal.h"
#include "g_data_internal.h"


extern RwRenderState D_00625210[];
typedef s32 (*BattleRenderStateFunction)(RwRenderState state, void *value);
extern BattleRenderStateFunction D_00887300[];
extern BattleRenderStateFunction D_00887304[];
extern u16 D_0076455C;
extern u16 D_0076455A;
extern f32 D_007613E0;
extern f32 D_007613E4;
extern f32 D_008872FC_abs[];
extern u32 datCalcChkBadStatus(s32, u32);
extern u8 *iGpffffb3c4;
extern s32 datTestBitmapBit(s32, s32);
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *, s32, s32);

extern void memset(void *destination, s32 value, u32 size);


extern u8 D_0060AB08[];
extern u8 D_0060AC00[];
extern u8 D_00618AC0[];
extern u8 D_0061F000[];

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern u8 *iGpffffb414;
extern s32 iGpffffb460;
extern u8 *D_0076449C;
extern u16 D_00624FC0[];
extern u16 D_00624FD8[];
extern u8 D_00624B20[];
extern u8 D_00624B22[];



extern u8 iGpffffb468;
extern u8 iGpffffb469;
extern s16 iGpffffb46e;
extern u8 D_006251F0[];







extern s32 iGpffffb464;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00624F50[];
extern u8 D_00624F60[];
extern u8 D_00624F80[];
extern u8 D_00624FA0[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001f; members 001f0620-001f0a10 */

extern s32 btlActionIsPendingBit(s32);
#pragma push
/* measured: baseline nd4 in shared-return branches; explicit result/break joins leave nd386. */
#pragma opt_rebuildconditionals off
// FUN_001F0620
/* Evaluate a target-command availability mode, including encounter and protagonist restrictions. */
s32 btlTargetCheckCommandAvailability(u8 *action, s64 kind)
{
    /* Encounter rule rows have a 0x18-byte stride and a signed leading flag word. */
    s32 encounterFlags;
    s64 mode;
    u16 encounterId;
    u8 *unit;
    u8 *actor;

    encounterId = ((BtlSoundEncounterRecord *)((u8 *)(((BtlBattleState *)iGpffffb3ac)->encounterRecord) ))->trackRule;
    if ((encounterId == 0x215) && ((s16)kind != 2)) {
        return 0;
    }
    mode = (s16)kind;
    switch (mode) {
    case 1:
        return 1;
    case 2:
        return !datCalcChkBadStatus((s32)(((BtlUnit *)((u8 *)(((BtlAction *)action)->unit)))->datUnit), 8);
    case 3:
        return !datGetFlag(0x1438);
    case 4:
        unit = (u8 *)(((BtlAction *)action)->unit);
        if (unit[0xA2] != 0) return 0;
        if (((BtlUnit *)unit)->charId != 1) return 0;
        if ((func_001ef720(1, 0) & 0xFFFF) < 2) return 0;
        return !datGetFlag(0x1438);
    case 5:
        actor = (u8 *)(((BtlAction *)action)->unit);
        if (actor[0xA2] != 0) return 0;
        if (((BtlUnit *)actor)->charId != 1) return 0;
        if ((((BtlAction *)action)->flags & 0x400) == 0) return 0;
        if (datCalcChkBadStatus((s32)(((BtlUnit *)actor)->datUnit), 8) != 0) return 0;
        return !datGetFlag(0x1438);
    case 6:
        encounterFlags = (((BtlSoundTrackRule *)(iGpffffb414))[(encounterId & 0xFFFF)].flags);
        if (encounterFlags & 0x20) return 0;
        if ((encounterFlags & 1) == 0) return 0;
        return !btlActionIsPendingBit(0);
    case 7:
    case 8:
    case 11:
    case 12:
        return 1;
    case 10:
        if (((BtlUnit *)((u8 *)(((BtlAction *)action)->unit)))->genus != 0) return 0;
        return !datGetFlag(0x1438);
    case 13:
        return 1;
    default:
        return 0;
    }
}
#pragma pop

/* Accept party IDs 1, 2, 7 and 8; every other ID is rejected. */
// FUN_001F08C0
/* Recognize the four unit IDs accepted by this target predicate. */
s32 btlTargetCheckUnitIdGroup(u8 *unit)
{
    u16 unitId;

    unitId = ((BtlUnit *)unit)->charId;
    switch (unitId) {
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 0;
    case 4:
        return 0;
    case 6:
        return 0;
    case 7:
        return 1;
    case 8:
        return 1;
    default:
        return 0;
    }
}

/* Honor the encounter overrides before testing the requested unit bitmap bit. */
// FUN_001F0950
/* Apply the encounter flag override before querying the requested bitmap bit. */
s32 btlTargetTestUnitFlag(s32 unitId, s32 bitIndex)
{
    if (((((BtlSoundEnemyStatusRow *)iGpffffb3c4)[unitId & 0xFFFF].flags & 0x4004) == 0) &&
        (datGetFlag(0x1403) != 0)) {
        if (datGetFlag(0x1408) != 0) {
            return 1;
        }
        if (datGetFlag(0x1409) != 0) {
            return 0;
        }
    }
    return datTestBitmapBit(unitId, bitIndex);
}

// FUN_001F0A10
void btlTargetClearResultBuffer(u8 *result) {
    memset(result, 0, 0x20);
}


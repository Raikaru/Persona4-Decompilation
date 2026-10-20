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
extern s32 datCalcEnemyHasTableFlag(s32);
extern u8 *iGpffffb3c4;
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *, s32, s32);


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

/* Return the status-effect message code for the acting unit's character, using an alternate code
 * for character 3 when the target's enemy has the table flag. */
// FUN_001F01A0
/* Select the party status-message code, with a target-dependent variant for unit three. */
s32 btlTargetGetStatusEffectMsgCode(u8 *action, u8 *target)
{
    u16 unitId;

    unitId = ((BtlUnit *)((u8 *)(((BtlAction *)action)->unit)))->charId;
    switch (unitId) {
    case 2:
        return 0x104;
    case 3:
        if ((target != NULL) &&
            (datCalcEnemyHasTableFlag((s32)(((BtlUnit *)((u8 *)(((BtlAction *)target)->unit)))->datUnit)) != 0)) {
            return 0x10A;
        }
        return 0x105;
    case 4:
        return 0x106;
    case 6:
        return 0x107;
    case 7:
        return 0x109;
    case 8:
        return 0x108;
    default:
        return 0;
    }
}

// FUN_001F0260
/* Map supported skill IDs to their effect codes; unsupported IDs return zero. */
s64 btlTargetSkillEffectCode(s32 skill) {
    switch (skill) {                                 /* irregular */
    case 0xDA:
    case 0xDB:
        return 0x40;
    case 0xDC:
    case 0xDD:
        return 0x42;
    case 0xDE:
    case 0xDF:
        return 0x44;
    case 0xE0:
        return 0x60;
    case 0xD3:
    case 0xD4:
        return 0x5A;
    case 0xD5:
    case 0xD6:
        return 0x5C;
    case 0xD7:
    case 0xD8:
        return 0x5E;
    case 0xD9:
        return 0x62;
    case 0xEA:
        return 0x4A;
    case 0xEB:
        return 0x4C;
    case 0xE3:
        return 0x64;
    case 0xE4:
        return 0x66;
    case 0x63:
    case 0x64:
        return 0x4E;
    case 0xEC:
        return 0x6A;
    case 0xED:
        return 0x6C;
    case 0xEE:
        return 0x70;
    case 0xEF:
        return 0x6E;
    case 0x103:
        return 0x72;
    case 0xE7:
        return 0x74;
    case 0xE8:
        return 0x76;
    case 0xF0:
        return 0x7A;
    case 0xF1:
        return 0x7C;
    case 0xF2:
        return 0x7E;
    case 0xF3:
        return 0x80;
    case 0xE1:
        return 0x46;
    case 0xE2:
        return 0x48;
    case 0x169:
        return 0xA5;
    case 0x17F:
        return 0xB0;
    case 0x180:
        return 0xB1;
    case 0x165:
        return 0xA3;
    case 0x16B:
        return 0xA6;
    case 0x17A:
        return 0xAE;
    case 0x178:
        return 0xA8;
    case 0x186:
        return 0xB5;
    case 0x181:
        return 0xB7;
    default:
        return 0;
    }
}


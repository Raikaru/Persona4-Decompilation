#include "list_item_internal.h"
#include "rw_geometry_internal.h"
#include "btl_equipment_count_internal.h"
#include "model_callbacks_internal.h"
#include "btl_camera_palette_internal.h"
#include "effect_geometry_internal.h"
#include "btl_motion_internal.h"
#include "effect_instance_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_camera_sequence_internal.h"

typedef struct RwV3d { f32 x, y, z; } RwV3d;
typedef struct RtQuat { RwV3d imag; f32 real; } RtQuat;
#include "btl_skill_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
extern s32 func_00106600(s16 id);
typedef struct KwlnTask KwlnTask;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct DatUnitEc DatUnitEc;
typedef struct DatUnit DatUnit;
typedef struct BtlAction BtlAction;
extern void (*D_00887300[])();
extern void func_00213b80(u8 *arg0);
extern s32 btlEncountRollChance(u8 *arg0);
extern s32 btlShuffleSelectMember(u8 *arg0, s16 arg1, s32 arg2);
extern s32 datCalcGetBadStatus(s32 arg0);
extern void btlEncounterStart(u8 *arg0);
extern s32 btlShuffleCreate(s32 arg0, u8 *arg1);
extern void btlShuffleCancel(s32 arg0);
extern s32 datCalcGetLevel(s32 arg0);
extern s32 func_00193260(u8 *arg0);
extern void memset(void *dst, s32 value, s32 size);
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern void btlMainLoadBattleFieldScene();
extern void func_00193d30(void);
extern s32 func_00122640(s32 arg0, s32 arg1);
extern s32 btlFormationAllocWork(s32 arg0);
extern BtlPacket *btlFormationCreateNamedPacket(u32 arg0, const char *arg1, u16 arg2);
extern u8 *btlSoundCreateSkillSEPacket(s32 arg0, s32 arg1);
extern u8 *btlMainCreateColorLerpPacket(s32 arg0, s32 arg1, s32 arg2);
extern BtlPacket *btlMainCreateColorWorkPacket(s32 first, s32 second, s32 third, u32 frames, u16 mode);
extern u8 *btlMainCreateTintPacket(s32 arg0, s32 arg1);
extern void func_001f0a10(u8 *arg0);
extern u8 *btlPacketCreateHpRatio(u8 *arg0);
extern BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);
extern BtlPacket *btlUnitCreateAnimPacket(BtlUnit *unit, s16 id, u16 blendFrameCount, f32 speed, u16 mode);
extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 kind, s16 value);
extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
extern u8 *btlCreateTimingPacket(s32 arg0);
extern u8 *btlMainCreateFadePacket(s32 arg0, s32 arg1);
extern u8 *btlMainCreateColorFadePacket(s32 arg0);
extern u16 datCalcGetHp(s32 unit);
extern u16 datCalcGetSp(s32 unit);
extern void btlMainSkillColorPairDefaults(u32 arg0, s32 *arg1, s32 *arg2);
extern s32 btlMainSkillColorDefault(s32 arg0);
extern s32 btlMainSkillTintDefault(s32 arg0);
extern void btlMainSkillColorPairDefaultsAlt(u32 arg0, s32 *arg1, s32 *arg2);
extern void btlFormationSetPlacement(s32 arg0);
extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *arg0);
extern u32 kwlnTaskGetWork(s32 arg0);
extern s32 func_00459760(s32 arg0);
extern void func_0045a3e0(s32 arg0, s32 arg1);
extern void btlEncounterSetFinish(s32 task);
extern u32 datCalcIsDead(s32 arg0, s32 arg1);
extern u8 *func_00193bf0(u64 arg0, u64 arg1);
extern s32 func_001f6290(void);
extern void (*jtbl_008873EC[])(void *);
extern f32 D_00922CA0[];
extern f32 D_00922CA4[];
extern f32 D_00922CA8[];
extern f32 D_00922CAC[];
extern f32 D_00922CB0[];
extern f32 D_00922CB4[];
extern f32 D_00922CB8[];
extern f32 D_00922CBC[];
extern s32 D_00922CC0[];
extern void func_00194ff0(u8 *unit, u8 *position, f32 *rotation, f32 *direction);
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *direction, u32 flags);
extern s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
extern void btlActionSetState(BtlAction *arg0, u16 arg1);
extern void func_002bbcc0(void);
extern s32 func_002bb600(void);
extern s32 func_002bb140(void);
extern void func_002bb380(void);
extern void func_002bb4e0(void);

extern u8 *D_0076449C;
extern s32 func_0022bd20(void);
extern void btlEncounterInitGlobals(void);
extern s32 func_001fadc0(u8 *arg0);
extern u32 btlCountUnitRecords(void);
extern BtlPacket *btlTargetCreateTargetPacket(u32 arg0, u16 arg1, u32 arg2, u32 arg3, u32 arg4);
extern void btlUnitShowModel(u8 *arg0);
extern void btlUnitHideModel(u8 *arg0);
extern s32 btlCurrentUnitId(void);
extern void func_002aaaa0(void);
extern void btlFadeStart(s32 arg0);
extern s32 func_001faaa0(u8 *arg0);
extern s32 btlBossIsAllowedAction(void);
extern s32 func_001fae10(void);
extern void func_0045a9a0(s32 arg0, s32 arg1);
extern void func_00122520(s32 arg0, s32 arg1);
extern void H_Fade_SetCustomColor(s32 arg0, s32 arg1, s32 arg2);
extern void func_001b69c0(void);
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *arg0);
extern u32 datCalcRandomBelow(u32 arg0);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern void btlBossCollectTargets(u8 *arg0);
extern s32 datCalcUnitClass(u8 *arg0);
extern void func_001b1020(s32 arg0);
extern void func_001b1280(s32 arg0);
extern u32 iGpffffa0b8;
extern void func_0014a2e0(u32 arg0);
extern void func_001b6120(void);
extern u32 datGetFlag(s32 arg0);
extern BtlPacket *btlVoiceCreateIdPacket(u16 arg0);
extern u8 *btlSoundCreateWaitPacket(void);
extern u8 *btlBossCreateLoadPakPacket(void);
extern s32 func_00230790(void);
extern BtlPacket *func_002305c0(s32 arg0);
extern void func_002aaa80(void);
extern void hFadeSetCustomWhite(void);
s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
extern s32 btlShuffleIsIdle(s32 task);
extern void func_001eb7f0(void);
extern s32 func_001eb860(void);
extern s32 func_001faaf0(void);
extern s32 func_001fab40(u8 *arg0);
extern s32 func_001fab90(void);
extern void btlDamageSetSource(u8 *arg0, s32 arg1);
BtlPacket *btlFormationCreateSlotPacket(u16 arg0, u16 arg1);
extern u8 func_002baac0(u8 *message);
void func_002bad10(u32 arg0);
void func_002bb050(u32 arg0);
void func_002baf40(u32 arg0);
extern u8 D_005FB400[];
static inline u8 *func_001bf3a0_add(s32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
static inline f32 func_001ba790_mul(f32 left, f32 right)
{
    return left * right;
}
extern BtlPacket *btlFormationCreatePacket(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
extern u8 *func_00194b60(void);
extern BtlPacket *btlTargetCreateEmptyPacket(void);
extern void func_001f86d0(void);
extern void btlDamageStartFlash(s32 arg0);
extern void btlEncounterSetReady(s32 task);
extern s32 btlEncounterIsIntroDone(s32 task);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern s32 btlShuffleIsCanceled(s32 task);
extern s32 btlEncounterIsInactive(s32 arg0);
extern s32 btlShuffleIsBusy(s32 task);
extern s32 func_00122720(void);
extern BtlPacket *func_0019bbe0(BtlUnit *arg0, u32 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5);
extern void func_001bdd60(void);
extern u8 *datUnitGetRecord(s16 arg0);
extern u16 *datPersonaGetRecord(u16 arg0);
extern s32 datPersonaFindSkillSlot(u8 *arg0, u16 arg1);
extern void btlPanelReset(s32 arg0);
extern void datCalcSetHp(s32 arg0, u16 arg1);
extern void datCalcSetSp(s32 arg0, u16 arg1);
extern u16 datCalcMaxHp(DatUnit *arg0);
extern u16 datCalcMaxSp(DatUnit *arg0);
extern s32 datCalcAddHp(DatUnit *arg0, s32 arg1);
extern s32 datCalcAddSp(DatUnit *arg0, s32 arg1);
extern s32 datCalcHasSkill(u8 *arg0, s32 arg1);
extern u32 datCalcClearBadStatus(s32 arg0, u32 arg1);
extern void datCalcClearAllBuffs(u8 *arg0);
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
extern f32 fGpffff8430;
extern f32 fGpffff8048;
extern u8 D_005F74C0[];
extern u8 D_005F72B0[];
extern f32 fGpffff8314;
extern f32 fGpffff8318;
extern f32 fGpffff831c;
extern f32 fGpffff8320;
extern f32 fGpffff8324;
extern f32 fGpffff8328;
extern f32 fGpffff832c;
extern f32 fGpffff8184;
extern f32 fGpffff8104;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff805c;
extern f32 fGpffff8060;
extern f32 fGpffff8108;






extern u8 *func_001b0c80(s32 arg0);
#pragma push
#pragma pop

/* Source unit: src/promoted/code1_001b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001b.c; members 001b1510-001b5e40 */

typedef struct BtlCameraColorReal {
    f32 red, green, blue, alpha;
} BtlCameraColorReal;
static inline void btlCameraNormalizeColor(BtlCameraColorReal *result, const u8 *bytes)
{
    result->red = (1.0f / 255.0f) * (f32)bytes[0];
    result->green = (1.0f / 255.0f) * (f32)bytes[1];
    result->blue = (1.0f / 255.0f) * (f32)bytes[2];
    result->alpha = (1.0f / 255.0f) * (f32)bytes[3];
}
static inline void btlCameraMultiplyColor(BtlCameraColorReal *result, const BtlCameraColorReal *base, const BtlCameraColorReal *ambient)
{
    result->red = base->red * ambient->red;
    result->green = base->green * ambient->green;
    result->blue = base->blue * ambient->blue;
    result->alpha = base->alpha * ambient->alpha;
}
static inline s32 btlCameraBlendAmbient(f32 ambientRed, f32 ambientGreen,
                                       f32 ambientBlue, f32 ambientAlpha)
{
    union BtlCameraPackedColor { s32 word; u8 bytes[4]; } color;
    BtlCameraColorReal normalized;
    BtlCameraColorReal ambient;
    s32 redByte, greenByte, blueByte, alphaByte;
    color.word = (s32)0xFF808080U;
    btlCameraNormalizeColor(&normalized, color.bytes);
    ambient.red = ambientRed;
    ambient.green = ambientGreen;
    ambient.blue = ambientBlue;
    ambient.alpha = ambientAlpha;
    btlCameraMultiplyColor(&normalized, &normalized, &ambient);
    redByte = (s32)(normalized.red * 255.0f + 0.5f);
    color.bytes[0] = redByte;
    greenByte = (s32)(normalized.green * 255.0f + 0.5f);
    color.bytes[1] = greenByte;
    blueByte = (s32)(normalized.blue * 255.0f + 0.5f);
    color.bytes[2] = blueByte;
    alphaByte = (s32)(normalized.alpha * 255.0f + 0.5f);
    color.bytes[3] = alphaByte;
    return color.word;
}
struct RwV3d;
// FUN_001B1510
s32 func_001b1510(void)
{
    s32 *var_4;
    u8 *temp_3;

    temp_3 = D_0076449C;
    var_4 = (s32 *)(temp_3 + 0x2CC);
    if (*(s32 *)(temp_3 + 0x2CC) == 0) {
        var_4 = (s32 *)(temp_3 + 0x29C);
    }
    return *var_4;
}

// FUN_001B1540
s32 func_001b1540(void)
{
    return *(s32 *)(iGpffffb3ac + 0x29C);
}

// FUN_001B1550
s32 func_001b1550(void)
{
    return *(s32 *)(iGpffffb3ac + 0x2CC);
}

// FUN_001B1560
s32 func_001b1560(void)
{
    return *(s32 *)(iGpffffb3ac + 0x2A0);
}

// FUN_001B1570
s32 func_001b1570(u16 arg0) {
    if (arg0 >= 0xC) {
        return 0;
    }
    return ((s32 *)(D_0076449C + 0x29C))[arg0];
}

// FUN_001B15B0
void func_001b15b0(void)
{
    u16 temp_7;
    u8 *temp_3;
    u8 *temp_4;
    u8 *temp_4_2;
    u8 *temp_4_3;
    u8 *temp_4_4;
    u8 *temp_4_5;
    u8 *temp_4_6;
    u8 *temp_4_7;
    u8 *temp_4_8;
    u8 *temp_5;
    u8 *temp_5_2;
    u8 *temp_6;
    u8 *temp_8;

    temp_8 = D_0076449C;
    temp_7 = *(u16 *)(temp_8 + 0x290);
    if ((temp_7 & 1) == 0) goto done;
    if ((*(s32 *)(temp_8 + 0xC) & 0x80000) != 0) goto done;
    if ((temp_7 & 8) == 0) goto done;
    temp_6 = temp_8 + 0x2CC;
    temp_5 = *(u8 **)temp_6;
    if (temp_5 != NULL) {
        if (*(u16 *)(temp_5 + 0xC) != 1) goto done;
        *(u16 *)(temp_5 + 0x18) |= 4;
        temp_4 = *(u8 **)temp_6;
        btlActionSetState((BtlAction *)temp_4, *(u16 *)(temp_4 + 0x16));
        temp_4_2 = D_0076449C;
        *(s32 *)(temp_4_2 + 0x294) += 1;
        temp_4_3 = D_0076449C;
        *(u16 *)(temp_4_3 + 0x290) &= 0xFFF7;
        goto done;
    }
    temp_6 = D_0076449C + 0x29C;
    if (*(s32 *)(D_0076449C + 0x294) == 0) goto after_count;
    if ((temp_7 & 2) != 0) {
        temp_5 = *(u8 **)temp_6;
        if (*(u8 *)(*(u8 **)(temp_5 + 0x30) + 0xA2) == 1) {
            func_001b1020(1);
            func_001b1280(1);
            temp_4_4 = D_0076449C;
            *(u16 *)(temp_4_4 + 0x290) &= 0xFFFD;
        }
    }
    if ((*(u16 *)(D_0076449C + 0x290) & 4) != 0) {
        temp_5 = *(u8 **)temp_6;
        if (*(u8 *)(*(u8 **)(temp_5 + 0x30) + 0xA2) == 0) {
            func_001b1020(1);
            func_001b1280(1);
            temp_4_5 = D_0076449C;
            *(u16 *)(temp_4_5 + 0x290) &= 0xFFFB;
        }
    }
    temp_5_2 = D_0076449C;
    if ((*(s32 *)(temp_5_2 + 0xC) & 0x200000) != 0 &&
        (*(u16 *)(temp_5_2 + 0x290) & 0x10) != 0) {
        btlBossCollectTargets(0);
        temp_4_6 = D_0076449C;
        *(u16 *)(temp_4_6 + 0x290) &= 0xFFEF;
    }
after_count:
    temp_5 = *(u8 **)temp_6;
    if (temp_5 == NULL) goto done;
    if (*(u16 *)(temp_5 + 0xC) != 1) goto done;
    temp_3 = *(u8 **)(temp_5 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) == 0) {
        if ((s16)datCalcUnitClass(*(u8 **)(temp_3 + 0xA64)) == 4) {
            *(s16 *)(*(u8 **)temp_6 + 0x14) = 5;
        } else {
            *(s16 *)(*(u8 **)temp_6 + 0x14) = 8;
        }
    } else {
        *(s16 *)(*(u8 **)temp_6 + 0x14) = 8;
    }
    btlActionSetState((BtlAction *)*(u8 **)temp_6, 2);
    temp_4_7 = D_0076449C;
    *(u16 *)(temp_4_7 + 0x290) &= 0xFFF7;
    temp_4_8 = D_0076449C;
    *(s32 *)(temp_4_8 + 0x294) += 1;
done:
    ;
}

// FUN_001B1800
void func_001b1800(void)
{
    u8 *temp_4;
    u8 *temp_4_2;

    temp_4 = D_0076449C;
    *(u16 *)(temp_4 + 0x290) |= 8;
    temp_4_2 = D_0076449C;
    *(u16 *)(temp_4_2 + 0x290) |= 1;
}

// FUN_001B1830
void func_001b1830(void) {
    *(u16 *)(D_0076449C + 0x290) &= 0xFFFE;
}

// FUN_001B1850
void func_001b1850(void)
{
    memset(D_0076449C + 0x290, 0, 0x6C);
}

// FUN_001B1880
void func_001b1880(void)
{
    *(u16 *)(D_0076449C + 0x290) = 0;
    *(s32 *)(D_0076449C + 0x298) = 0;
    memset(D_0076449C + 0x2CC, 0, 0x30);
}

// FUN_001B18C0
void btlMainNonInit(void)
{
}

// FUN_001B18D0
s32 btlMainNonUpdate(void)
{
    return 0;
}

// FUN_001B18E0
void btlMainInitInit(void) {
    btlSoundFadeChannel(2, 0);
    btlSoundFadeChannel(3, 0);
    btlSoundFadeOutBgm(0);
    func_00106550(0x78, func_001064f0(0x78) + 1);
}

// FUN_001B1940
s32 btlMainInitUpdate(void) {
    u8 *b = D_0076449C;
    s32 off = *(u16 *)(b + 0xC6C) << 2;

    *(s32 *)(b + 0xC68) = *(s32 *)(off + (s32)b + 0xC84);
    b = D_0076449C;
    *(u16 *)(b + 0xC6C) = *(u16 *)(b + 0xC6C) + 1;
    if (func_0022bd20() != 0) {
        btlEncounterInitGlobals();
    }
    return 3;
}

// FUN_001B19A0
void btlMainSceneSetInit(void)
{
    btlMainLoadBattleFieldScene();
}

/* measured: opt_rebuildconditionals off for func_001b19c0 branch-fed scalar. */
/* measured: btlMainSceneSetUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
// FUN_001B19C0
s32 btlMainSceneSetUpdate(void)
{
    extern s32 func_001b6a00(void);
    extern u32 btlCountUnitRecords(void);
    extern void func_0014a2e0(u32 arg0);
    extern void func_001b6120(void);
    extern u32 datGetFlag(s32 arg0);
    extern BtlPacket *btlVoiceCreateIdPacket(u16 arg0);
    extern s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
    extern u8 *btlSoundCreateWaitPacket(void);
    extern s32 func_0022bd20(void);
    extern u8 *btlBossCreateLoadPakPacket(void);
    extern s32 func_00230790(void);
    extern s32 btlCurrentUnitId(void);
    extern void func_002aaa80(void);
    extern void hFadeSetCustomWhite(void);
    s32 var_2;
    s32 temp_2_3;
    s32 temp_2_4;
    u8 *temp_2;
    u8 *temp_2_2;

    if (func_001b6a00() == 0) {
        goto done;
    }
    if (btlCountUnitRecords() != 0) {
        goto done;
    }
    func_0014a2e0(1);
    func_001b6120();
    if (datGetFlag(0x38) == 0) {
        goto set_zero;
    }
    var_2 = 1;
    goto got_var;
set_zero:
    var_2 = 0;
got_var:
    temp_2 = (u8 *)btlVoiceCreateIdPacket((u16)(var_2 & 0xFFFF));
    btlPacketEnqueue(temp_2, 1);
    temp_2_2 = btlSoundCreateWaitPacket();
    *(s8 *)(temp_2_2 + 0) = 4;
    *(s64 *)(temp_2_2 + 8) = *(s64 *)(temp_2 + 0x58);
    btlPacketEnqueue(temp_2_2, 1);
    if (func_0022bd20() != 0) {
        btlPacketEnqueue(btlBossCreateLoadPakPacket(), 1);
        temp_2_3 = func_00230790();
        if (temp_2_3 != -1) {
            btlPacketEnqueue((u8 *)func_002305c0(temp_2_3), 1);
        }
    }
    temp_2_4 = btlCurrentUnitId();
    switch (temp_2_4) {
    case 0x20B:
    case 0x215:
        func_002aaa80();
        hFadeSetCustomWhite();
        break;
    }
    return 5;
done:
    return 0;
}

/* measured: close opt_rebuildconditionals off for func_001b19c0. */
/* measured: btlMainWinInit MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals on
// FUN_001B1B20
void btlMainContinuousInit(void)
{
}

// FUN_001B1B30
s32 btlMainContinuousUpdate(void)
{
    extern u8 *btlTargetCreateTargetPacket(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern void btlDamageSetSource(u8 *arg0, s32 arg1);
    extern void btlSelectionClearTargetFlag(s32 arg0);
    extern void func_00213b50(s32 task);
    extern void func_00213c40(s32 task);
    extern void func_001eb7f0(void);
    u8 *node;
    s32 state;
    u8 *unit;
    u8 *work;
    u8 *next;

    state = 1;
    node = *(u8 **)((u8 *)iGpffffb3ac + 0x174);
    goto first_check;
first_body:
    if ((*(u16 *)(node + 0x1A) & 1) != 0) {
        unit = *(u8 **)(node + 0x30);
        if (*(u8 *)(unit + 0xA2) == 1) {
            state = 0;
        } else {
            btlActionSetState((BtlAction *)node, 1);
            *(u16 *)(node + 0x18) &= 0x7FFF;
            *(u16 *)(node + 0x18) &= 0xFFFB;
        }
    }
    node = *(u8 **)(node + 0x450);
first_check:
    if (node != NULL) goto first_body;
    *(s32 *)((u8 *)iGpffffb3ac + 0xC) &= 0xFFFFFF7F;
    *(s32 *)((u8 *)iGpffffb3ac + 0xC) &= 0xFFF7FFFF;
    if (state == 0) goto done;
    *(u16 *)((u8 *)iGpffffb3ac + 0x1C) = 0;
    work = (u8 *)iGpffffb3ac;
    *(s32 *)(work + 0xC68) =
        *(s32 *)(((*(u16 *)(work + 0xC6C) << 2) + (s32)work) + 0xC84);
    work = (u8 *)iGpffffb3ac;
    *(u16 *)(work + 0xC6C) = *(u16 *)(work + 0xC6C) + 1;
    func_001b1880();
    work = (u8 *)iGpffffb3ac;
    *(s32 *)(work + 0xC) &= 0xFFFEFFFF;
    btlSelectionClearTargetFlag(*(s32 *)((u8 *)iGpffffb3ac + 0xDD4));
    btlPacketEnqueue(
        (u8 *)btlTargetCreateTargetPacket(*(u8 **)((u8 *)iGpffffb3ac + 0x170),
                            0x1F, 0, 0, 0),
        1);
    next = *(u8 **)((u8 *)iGpffffb3ac + 0x174);
    goto second_check;
second_body:
    if ((*(u16 *)(next + 0x1A) & 1) != 0) {
        unit = *(u8 **)(next + 0x30);
        if (*(u8 *)(unit + 0xA2) == 0 &&
            *(s32 *)(unit + 0xA64) != 0) {
            btlPacketEnqueue(btlTargetCreateActionPacket(next, 2), 1);
        }
    }
    next = *(u8 **)(next + 0x450);
second_check:
    if (next != NULL) goto second_body;
    func_00213c40(*(s32 *)((u8 *)iGpffffb3ac + 0xDD4));
    func_00213b50(*(s32 *)((u8 *)iGpffffb3ac + 0xDD4));
    if (func_001eb860() == 1) {
        work = (u8 *)iGpffffb3ac;
        *(s32 *)(work + 0xC) |= 0x2000;
        btlDamageSetSource(*(u8 **)((u8 *)iGpffffb3ac + 0xDD4), 1);
        func_001eb7f0();
    }
    return 5;
done:
    return 0;
}

/* Round-3 reconstruction: retain the u16 model ID, table-entry reloads,
 * switch dispatch and full-width status-roll locals.
 * See docs/probe_archive/BattleSetup_001b1d70_20260926_body.c and the
 * corrected model-ID contract survey, Prototype_mismatch_00477c40_00478140_20260926.md. */
// FUN_001B1D70
void btlMainUnitCreateInit(void) {
    extern s32 iGpffffb414;
    extern u8 *btlActionCreateWork(s32 arg0, u16 arg1, u16 *arg2);
    extern u32 datCalcClearBadStatus(s32 arg0, u32 arg1);
    extern void *mdlFindModelObject(u32 arg0, u16 arg1, u32 arg2);
    extern u8 *btlUnitCreateModelLoadPacket(u8 *arg0, u16 arg1, s16 arg2);
    extern void func_0014a460(u16 arg0, u32 arg1);
    extern void btlUnitApplyModelState(u8 *arg0, s32 arg1);
    extern void btlUnitSetRandomAnimFrame(u8 *arg0);
    extern void mdlRunDataCallback(void *model);
    extern u8 *mdlGetClump(u8 *arg0);
    extern void mdlClumpSetEnvMapState(u8 *arg0);
    extern s32 btlUnitGetMoveStateCode(void);
    extern void func_001b11c0(s32 arg0);
    extern s32 func_001b0f20(s32 arg0);
    extern s32 datCalcStatusElement(s32 arg0, s32 arg1);
    extern s32 datCalcStatusResistance(u8 *arg0, s32 arg1);
    extern u32 datCalcSetBadStatus(s32 unit, u32 badStatus);
    extern void func_001d1680(s32 arg0, s32 arg1);
    extern void btlUnitSetPos(u8 *arg0, f32 *arg1);
    u8 *tmp;
    u8 *unit;
    u32 k;
    f32 st[3];
    s32 w2;
    u32 *entry;
    u8 *list;
    s64 v1;
    s32 r1;
    s32 r2;
    u8 *j;
    u32 i;
    u8 *pkt;
    u16 id;
    s32 f;

    v1 = 0;
    if ((*(u32 *)(D_0076449C + 0xC) & 0x20000000) == 0) {
        i = 0;
        while (i < 4) {
            w2 = *(s32 *)((u32)D_0076449C + i * 4 + 0xC74);
            if (w2 == 0)
                break;
            tmp = *(u8 **)(w2 + 4);
            id = *(u16 *)(tmp + 2);
            pkt = btlActionCreateWork(0, id, (u16 *)tmp);
            unit = *(u8 **)(pkt + 0x30);
            datCalcClearBadStatus(*(s32 *)(unit + 0xA64), 0xFFF7FFFF);
            *(u16 *)(*(u8 **)(unit + 0xA64)) &= 0xFFDF;
            *(u16 *)(*(u8 **)(unit + 0xA64)) &= 0xFFF7;
            *(u16 *)(*(u8 **)(unit + 0xA64)) &= 0xFFEF;
            w2 = (s32)mdlFindModelObject((u16)(*(u8 *)(unit + 0xA2) + 1), id, 0);
            *(s32 *)(unit + 0xA00) = w2;
            if (w2 == 0) {
                pkt = btlUnitCreateModelLoadPacket(unit, id, 0x36);
                *pkt = 4;
                *(s64 *)(pkt + 8) = v1;
                btlPacketEnqueue(pkt, 1);
                v1 = *(s64 *)(pkt + 0x58);
            } else {
                f = *(s32 *)(unit + 0x98) | 2;
                *(s32 *)(unit + 0x98) = f;
                *(s32 *)(unit + 0x98) = f | 8;
                *(u16 *)(unit + 0x9FE) = MT_Scene_CreateModelCharRes(id, *(void **)(unit + 0xA00));
                func_0014a460(*(u16 *)(unit + 0x9FE), 1);
                btlUnitApplyModelState(unit, 1);
                btlUnitUpdateStatusMotion(unit, 0);
                func_00198920(unit, *(s16 *)(unit + 0x9EC), 0, *(f32 *)(unit + 0x9F0), *(s8 *)(unit + 0x9F4));
                btlUnitSetRandomAnimFrame(unit);
                tmp = *(u8 **)(unit + 0xA00);
                if (*(s32 *)(tmp + 0x2D0) == 0) {
                    mdlRunDataCallback(tmp);
                }
                btlUnitApplyModelState(unit, 4);
                btlUnitShowModel(unit);
                *(s32 *)(*(u8 **)(unit + 0xA00) + 0xD8) |= 0x400;
                mdlClumpSetEnvMapState(mdlGetClump(*(u8 **)(unit + 0xA00)));
            }
            i++;
        }
        *(u8 *)(D_0076449C + 0xC64) = (u8)i;
    }
    list = *(u8 **)(*(u8 **)(D_0076449C + 0xC68) + 4);
    k = 0;
    while (k < 6) {
        if (*(u16 *)(list + 2) != 0 && datCalcIsDead((s32)list, 0) == 0) {
            btlActionCreateWork(1, *(s16 *)(list + 2), (u16 *)list);
        }
        k++;
        list += 0x30;
    }
    if ((*(u32 *)(D_0076449C + 0xC) & 0x100) != 0) {
        entry = (u32 *)((u8 *)iGpffffb414 + (u32)*(u16 *)(*(u8 **)(D_0076449C + 0xC68) + 8) * 0x18);
        if ((*entry & 0x20) != 0) {
            if ((*entry & 0x10) == 0) {
                *(u16 *)(D_0076449C + 0x1A) = 0;
            }
            btlBossCollectTargets((u8 *)0);
        } else {
            *(u16 *)(D_0076449C + 0x1A) = btlUnitGetMoveStateCode();
            switch (*(u16 *)(D_0076449C + 0x1A)) {
            case 0:
                func_001b1020(1);
                func_001b1280(1);
                if ((*(u32 *)(D_0076449C + 0xC) & 0x20000000) != 0) {
                    func_001b0f20(*(s32 *)(D_0076449C + 0x170));
                }
                break;
            case 1:
                func_001b1020(0);
                func_001b11c0(0);
                func_001b0f20(*(s32 *)(D_0076449C + 0x170));
                *(u16 *)(D_0076449C + 0x290) |= 2;
                if ((*entry & 0x200) == 0) {
                    *(u32 *)(D_0076449C + 0xC) |= 0x100000;
                }
                break;
            case 2:
                func_001b1020(0);
                func_001b11c0(1);
                func_001b1280(1);
                *(u16 *)(D_0076449C + 0x290) |= 4;
                if ((*entry & 0x200) == 0) {
                    *(u32 *)(D_0076449C + 0xC) |= 0x100000;
                }
                break;
            }
        }
        if (((*(u16 *)(D_0076449C + 0xC70) & 8) != 0) && ((*entry & 0x100) == 0) &&
            ((*(u32 *)(D_0076449C + 0xC) & 0x20000000) == 0)) {
            r1 = (s16)datCalcStatusElement(-1, 4);
            r2 = (s16)datCalcStatusElement(-1, 2);
            for (j = *(u8 **)(D_0076449C + 0x180); j != NULL; j = *(u8 **)(j + 0xA6C)) {
                if (*(u8 **)(j + 0xA64) != NULL) {
                    if ((datCalcStatusResistance(*(u8 **)(j + 0xA64), r2) & 0x27000000) == 0 && (s32)datCalcRandomBelow(100) < 0) {
                        datCalcSetBadStatus(*(s32 *)(j + 0xA64), 2);
                    }
                    if ((datCalcStatusResistance(*(u8 **)(j + 0xA64), r1) & 0x27000000) == 0 && (s32)datCalcRandomBelow(100) < 0) {
                        datCalcSetBadStatus(*(s32 *)(j + 0xA64), 4);
                    }
                }
            }
        }
    }
    if ((*(u32 *)(D_0076449C + 0xC) & 0x20000000) == 0) {
        func_001d1680(1, 0);
        return;
    }
    func_001d1680(0, 0);
    st[1] = 0.0f;
    for (j = *(u8 **)(D_0076449C + 0x180); j != NULL; j = *(u8 **)(j + 0xA6C)) {
        st[0] = (f32)(*(s16 *)(j + 0x94) * 0x19 - 0x6D6);
        st[2] = (f32)(*(s16 *)(j + 0x96) * 0x19 - 0x6D6);
        btlUnitSetPos(j, st);
    }
}

/* Opening positions use complete vectors and a quaternion: the formation and
 * sphere-center providers write all components. The two list rows are eight
 * bytes apart and are reloaded between passes. Packets wait on full 64-bit UIDs.
 * Retail keeps the redundant actor comparison at 001b2aa0. The unreachable
 * inner block is retained as source rather than changing the surrounding test. */
/* measured: scoped opt_lifetimes on with these disjoint work-pointer
 * lifetimes reproduces the complete 4156-byte retail body; all 122 owner
 * siblings, allocated data and 122 exact-position references are preserved.
 * The separate retained-height caller-domain proof remains required. */
#pragma push
/* measured: btlMainUnitCreateUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
// FUN_001B2380
s32 btlMainUnitCreateUpdate(void)
{
    extern void func_001f73d0(void);
    extern void btlShuffleStart(s32 task);
    extern s32 iGpffffb414;
    extern s32 func_001b1540(void);
    extern void btlUnitGetGridSphereCenter(BtlUnit *unit, RwV3d *dst);
    extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter, f32 *outTop, f32 *outBottom, u32 options);
    extern void func_001ee250(u8 *arg0, u8 *arg1);
    extern void btlTargetBlendVectors(u8 *rotation, u8 *from, u8 *to);
    extern void btlUnitSetRot(BtlUnit *unit, const RtQuat *rotation);
    extern void btlUnitSetPos(BtlUnit *unit, const RwV3d *position);
    extern BtlPacket *btlUnitCreateModelFramePacket(BtlUnit *unit, s16 value);
    extern BtlPacket *btlUnitCreateMotionRequestPacket(BtlUnit *unit, u16 value);
    extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *unit, const RwV3d *targetPos, f32 speed, u32 flags);
    extern BtlPacket *btlUnitCreateRotateTowardUnitPacket(BtlUnit *unit, BtlUnit *targetUnit, u32 flags);
    extern void btlFadeStartImmediate(void);
    extern u32 datCalcSetBadStatus(s32 unit, u32 badStatus);
    extern u32 datCalcIsLowHp(s32 unit);
        extern void datCalcApplyBuffMask(u8 *arg0, s32 arg1, s64 arg2);
    extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
    extern f32 fGpffff8128;
    extern f32 fGpffff8170;
    extern f32 fGpffff82cc;
    /* ENCOUNT rows are 0x18 bytes: flags, two halfword result fields,
     * five enemy IDs and three remaining halfwords. No local copy is made. */
    typedef struct BattleOpeningEncounter {
        u32 flags;
        u16 field04;
        u16 field06;
        u16 enemyIds[5];
        u16 field12[3];
    } BattleOpeningEncounter;
    u8 *action;
    u32 hasSkill213;
    u32 hasSkill214;
    u32 hasSkill215;
    s16 unitClassOrFrames;
    u16 mode;
    /* Rotation finishes before packet construction. This work pointer is
     * reassigned before every later actor/packet use; unit independently
     * traverses the party placement and both bonus scans. */
    u8 *nodeOrPacket;
    u16 animationFrames;
    u8 *movePacket;
    u8 *rotatePacket;
    u8 *recoveryPacket;
    s32 hasSkill;
    u32 group;
    u8 *unit;
    u32 nextState;
    s32 value;
    BattleOpeningEncounter *formation;
    f32 spacingIncrement;
    f32 scale;
    f32 approachDistance;
    f32 distance;
    RtQuat rotation;
    RwV3d position;
    RwV3d targetDirection;
    RwV3d groupCenter;
    RwV3d actorCenter;
    RwV3d offset;

    if (btlCountUnitRecords() == 0) {
      /* Valid special continuations have a fresh, nonempty enemy row from
       * the authenticated normal encounter queue. That prepass supplies Y
       * before a dead party unit reuses it. Script/direct descriptors have
       * one wave: their normal dead-unit path never reads this position,
       * and their live-unit path receives a complete formation vector.
       * The separate resource/history review proves this caller boundary;
       * arbitrary fabricated special/empty-row states are outside it. */
      func_001f73d0();
      formation = (BattleOpeningEncounter *)((u32)iGpffffb414 + (u32)*(u16 *)(*(s32 *)(D_0076449C + 0xc68) + 8) * 0x18);
      action = (u8 *)func_001b1540();
      if ((((action == 0) || (*(u8 *)(*(s32 *)(action + 0x30) + 0xa2) == 1)) ||
          (value = datCalcIsDead(*(u32 *)(*(s32 *)(action + 0x30) + 0xa64),0), value == 1)) ||
         (value = datCalcChkBadStatus(*(u32 *)(*(s32 *)(action + 0x30) + 0xa64),0x100000), value == 1
         )) {
        action = *(u8 **)(D_0076449C + 0x170);
      }
      btlUnitGetGridSphereCenter((BtlUnit *)*(void **)(action + 0x30), &groupCenter);
      for (group = 0; (s32)(group & 0xffff) < 2; group = (group + 1) & 0xffff) {
        if (((*(u32 *)(D_0076449C + 0xc) & 0x20000000) == 0) || ((group & 0xffff) != 0)) {
          for (nodeOrPacket = *(u8 **)(D_0076449C + (u16)group * 8 + 0x178); nodeOrPacket != NULL;
              nodeOrPacket = *(u8 **)(nodeOrPacket + 0xa6c)) {
            func_001ee250(nodeOrPacket,NULL);
            if ((group & 0xffff) == 0) {
              func_00194ff0(nodeOrPacket,NULL,(f32 *)&rotation,NULL);
            }
            else {
              position.x = (f32)(*(s16 *)(nodeOrPacket + 0x94) * 0x19 - 0x6d6);
              position.y = *(f32 *)(nodeOrPacket + 8);
              position.z = (f32)(*(s16 *)(nodeOrPacket + 0x96) * 0x19 - 0x6d6);
              btlTargetBlendVectors((u8 *)&rotation,(u8 *)&position,(u8 *)&groupCenter);
            }
            btlUnitSetRot((BtlUnit *)nodeOrPacket, &rotation);
          }
        }
      }
      btlUnitGetGroupBounds(2,0,&groupCenter,NULL,NULL,1);
      spacingIncrement = 0.0f;
      for (unit = *(u8 **)(D_0076449C + 0x178); unit != NULL;
          unit = *(u8 **)(unit + 0xa6c)) {
        btlUnitShowModel(unit);
        value = datCalcIsDead(*(u32 *)(unit + 0xa64),0);
        if (value != 0) {
          datCalcSetBadStatus(*(s32 *)(unit + 0xa64),0x80000);
          datCalcSetHp(*(u32 *)(unit + 0xa64),0);
          *(u32 *)(unit + 0x9c) |= 1;
          btlUnitUpdateStatusMotion(unit,0);
          btlPacketEnqueue((u8 *)btlSoundCreateUnitFlagSetPacket((BtlUnit *)unit),1);
          btlPacketEnqueue((u8 *)btlUnitCreateAnimPacket((BtlUnit *)unit, 0x13, 0, 1.0f, 2),1);
          btlPacketEnqueue((u8 *)btlUnitCreateModelFramePacket((BtlUnit *)unit,
              btlUnitMotionModelFrames(unit,0x13,1.0f)),1);
          btlPacketEnqueue((u8 *)btlSoundCreateUnitFlagClearPacket((BtlUnit *)unit),1);
          if ((*(u32 *)(D_0076449C + 0xc) & 0x20000000) != 0) {
            position.x = (f32)(*(s16 *)(unit + 0x94) * 0x19 - 0x6d6);
            position.z = (f32)(*(s16 *)(unit + 0x96) * 0x19 - 0x6d6);
            btlUnitSetPos((BtlUnit *)unit, &position);
          }
        } else {
          func_00194ff0(unit,(u8 *)&position,NULL,(f32 *)&targetDirection);
          btlUnitGetGroupBounds(2,0,&groupCenter,NULL,NULL,1);
          if ((*(u32 *)(D_0076449C + 0xc) & 0x20000000) == 0) {
            mode = *(u16 *)(D_0076449C + 0x1a);
            switch (mode) {
            case 2:
            {
              if ((formation->flags & 0x200) != 0) goto normal_opening;
              if (*(u8 **)(*(s32 *)(D_0076449C + 0x170) + 0x30) != unit) {
                offset.x = groupCenter.x - position.x;
                offset.z = groupCenter.z - position.z;
                offset.y = 0.0f;
                approachDistance = fGpffff8170 * RwV3dNormalize(&offset,&offset);
                if (approachDistance <= 150.0f) {
                  btlUnitSetPos((BtlUnit *)unit, &position);
                }
                else {
                  if (!(approachDistance <= 300.0f)) {
                    approachDistance = 300.0f;
                  }
                  offset.x = offset.x * approachDistance;
                  offset.y = offset.y * approachDistance;
                  offset.z = offset.z * approachDistance;
                  offset.x = offset.x + position.x;
                  offset.y = offset.y + position.y;
                  offset.z = offset.z + position.z;
                  offset.y = position.y;
                  btlUnitSetPos((BtlUnit *)unit, &offset);
                }
                btlPacketEnqueue((u8 *)btlUnitCreateRotateTowardUnitPacket((BtlUnit *)unit, (BtlUnit *)*(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30), 2),1);
              } else {
                offset.x = position.x - groupCenter.x;
                offset.z = position.z - groupCenter.z;
                offset.y = 0.0f;
                RwV3dNormalize(&offset,&offset);
                offset.x = offset.x * 300.0f;
                offset.y = offset.y * 300.0f;
                offset.z = offset.z * 300.0f;
                offset.x = offset.x + position.x;
                offset.y = offset.y + position.y;
                offset.z = offset.z + position.z;
                offset.y = position.y;
                btlUnitSetPos((BtlUnit *)unit, &offset);
              }
              animationFrames = btlUnitMotionModelFrames(unit,0xb,1.0f);
              nodeOrPacket = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)unit, 0xb, 0, 1.0f, 0);
              if (animationFrames > 8) {
                value = animationFrames - 8;
              } else {
                value = 0;
              }
              *(s16 *)(nodeOrPacket + 0x4a) = value;
              btlPacketEnqueue(nodeOrPacket,1);
              movePacket = (u8 *)btlUnitCreateMovePacket((BtlUnit *)unit, &position, fGpffff82cc, 8);
              *movePacket = 4;
              *(u64 *)(movePacket + 8) = *(u64 *)(nodeOrPacket + 0x58);
              btlPacketEnqueue(movePacket,1);
              rotatePacket = (u8 *)btlUnitCreateRotatePacket((BtlUnit *)unit, &targetDirection, 0);
              *rotatePacket = 4;
              *(u64 *)(rotatePacket + 8) = *(u64 *)(movePacket + 0x58);
              btlPacketEnqueue(rotatePacket,1);
            }
            goto unit_done;
            case 0:
            case 1:
              goto normal_opening;
            default:
              goto unit_done;
            }
normal_opening:
            {
              if ((D_0076449C[0xc64] != 1) && ((*(u32 *)(D_0076449C + 0x10) & 1) == 0)) {
                nodeOrPacket = *(u8 **)(action + 0x30);
                if (nodeOrPacket == unit) {
                  distance = 500.0f;
                  if (nodeOrPacket != unit) {
                    btlUnitGetGridSphereCenter((BtlUnit *)nodeOrPacket, &actorCenter);
                    offset.x = groupCenter.x - actorCenter.x;
                    offset.y = groupCenter.y - actorCenter.y;
                    offset.z = groupCenter.z - actorCenter.z;
                    scale = fGpffff8128 * RwV3dNormalize(&offset,&offset);
                    offset.x = offset.x * scale;
                    offset.y = offset.y * scale;
                    offset.z = offset.z * scale;
                    groupCenter.x = actorCenter.x + offset.x;
                    groupCenter.y = actorCenter.y + offset.y;
                    groupCenter.z = actorCenter.z + offset.z;
                    spacingIncrement = spacingIncrement + 75.0f;
                    distance = distance + spacingIncrement;
                  }
                  groupCenter.y = position.y;
                  offset.x = position.x - groupCenter.x;
                  offset.y = position.y - position.y;
                  offset.z = position.z - groupCenter.z;
                  RwV3dNormalize(&offset,&offset);
                  offset.x = offset.x * distance;
                  offset.y = offset.y * distance;
                  offset.z = offset.z * distance;
                  offset.x = offset.x + position.x;
                  offset.y = offset.y + position.y;
                  offset.z = offset.z + position.z;
                  btlUnitSetPos((BtlUnit *)unit, &offset);
                }
                else {
                  btlUnitGetGridSphereCenter((BtlUnit *)nodeOrPacket, &groupCenter);
                  groupCenter.y = position.y;
                  offset.x = groupCenter.x - position.x;
                  offset.y = position.y - position.y;
                  offset.z = groupCenter.z - position.z;
                  distance = (f32)RwV3dNormalize(&offset,&offset);
                  if (!(distance <= 600.0f)) {
                    offset.x = offset.x * 500.0f;
                    offset.y = offset.y * 500.0f;
                    offset.z = offset.z * 500.0f;
                  }
                  else {
                    distance = distance - 100.0f;
                    offset.x = offset.x * distance;
                    offset.y = offset.y * distance;
                    offset.z = offset.z * distance;
                  }
                  offset.x = offset.x + position.x;
                  offset.y = offset.y + position.y;
                  offset.z = offset.z + position.z;
                  btlUnitSetPos((BtlUnit *)unit, &offset);
                }
                nodeOrPacket = (u8 *)btlUnitCreateMovePacket((BtlUnit *)unit, &position, fGpffff82cc, 8);
                btlPacketEnqueue(nodeOrPacket,1);
                rotatePacket = (u8 *)btlUnitCreateRotatePacket((BtlUnit *)unit, &targetDirection, 0);
                *rotatePacket = 4;
                *(u64 *)(rotatePacket + 8) = *(u64 *)(nodeOrPacket + 0x58);
                btlPacketEnqueue(rotatePacket,1);
                value = datCalcChkBadStatus(*(u32 *)(unit + 0xa64),0xfffff);
                if (((value == 0) &&
                    (value = datCalcIsLowHp(*(s32 *)(unit + 0xa64)), value == 0)) &&
                   ((*(u8 **)(action + 0x30) != unit ||
                    (unitClassOrFrames = datCalcUnitClass(*(u8 **)(unit + 0xa64)), unitClassOrFrames == 4)))) {
                  recoveryPacket = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)unit, 0x11, 4, 1.0f, 0);
                  *recoveryPacket = 4;
                  *(u64 *)(recoveryPacket + 8) = *(u64 *)(nodeOrPacket + 0x58);
                  *(u16 *)(recoveryPacket + 0x48) = 4;
                  btlPacketEnqueue(recoveryPacket,1);
                }
              }
            }
          }
          else {
            value = datCalcChkBadStatus(*(u32 *)(unit + 0xa64),0x180001);
            if (value != 0) {
              btlTargetBlendVectors((u8 *)&rotation,(u8 *)&position,(u8 *)&groupCenter);
              btlPacketEnqueue(btlUnitCreateOverridePacket(unit,(u8 *)&position,(u8 *)&rotation,0),0);
              btlPacketEnqueue((u8 *)btlUnitCreateMotionRequestPacket((BtlUnit *)unit, 0),0);
            } else {
              offset.x = position.x - groupCenter.x;
              offset.z = position.z - groupCenter.z;
              offset.y = 0.0f;
              RwV3dNormalize(&offset,&offset);
              offset.x = offset.x * 100.0f;
              offset.y = offset.y * 100.0f;
              offset.z = offset.z * 100.0f;
              offset.x = offset.x + groupCenter.x;
              offset.y = offset.y + groupCenter.y;
              offset.z = offset.z + groupCenter.z;
              offset.y = position.y;
              btlTargetBlendVectors((u8 *)&rotation,(u8 *)&offset,(u8 *)&position);
              btlPacketEnqueue(btlUnitCreateOverridePacket(unit,(u8 *)&offset,(u8 *)&rotation,0),0);
              nodeOrPacket = (u8 *)btlUnitCreateMovePacket((BtlUnit *)unit, &position, fGpffff82cc, 8);
              btlPacketEnqueue(nodeOrPacket,0);
              rotatePacket = (u8 *)btlUnitCreateRotatePacket((BtlUnit *)unit, &targetDirection, 0);
              *rotatePacket = 4;
              *(u64 *)(rotatePacket + 8) = *(u64 *)(nodeOrPacket + 0x58);
              btlPacketEnqueue(rotatePacket,1);
              value = datCalcChkBadStatus(*(u32 *)(unit + 0xa64),0xfffff);
              if (((value == 0) &&
                  (value = datCalcIsLowHp(*(s32 *)(unit + 0xa64)), value == 0)) &&
                 ((*(u8 **)(action + 0x30) != unit ||
                  (unitClassOrFrames = datCalcUnitClass(*(u8 **)(unit + 0xa64)), unitClassOrFrames == 4)))) {
                recoveryPacket = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)unit, 0x11, 4, 1.0f, 0);
                *recoveryPacket = 4;
                *(u64 *)(recoveryPacket + 8) = *(u64 *)(nodeOrPacket + 0x58);
                *(u16 *)(recoveryPacket + 0x48) = 4;
                btlPacketEnqueue(recoveryPacket,1);
              }
            }
          }
        }
unit_done:
        ;
      }
      for (group = 0; (s32)(group & 0xffff) < 2; group = (group + 1) & 0xffff) {
        hasSkill213 = 0;
        hasSkill214 = 0;
        hasSkill215 = 0;
        for (unit = *(u8 **)(D_0076449C + (u16)group * 8 + 0x178); unit != 0;
            unit = *(u8 **)(unit + 0xa6c)) {
          if (*(u8 **)(unit + 0xa64) != NULL) {
            hasSkill = datCalcHasSkill(*(u8 **)(unit + 0xa64),0x213);
            if (hasSkill != 0) {
              hasSkill213 = 1;
            }
            hasSkill = datCalcHasSkill(*(u8 **)(unit + 0xa64),0x214);
            if (hasSkill != 0) {
              hasSkill214 = 1;
            }
            hasSkill = datCalcHasSkill(*(u8 **)(unit + 0xa64),0x215);
            if (hasSkill != 0) {
              hasSkill215 = 1;
            }
          }
        }
        for (unit = *(u8 **)(D_0076449C + (u16)group * 8 + 0x178); unit != 0;
            unit = *(u8 **)(unit + 0xa6c)) {
          if (*(u8 **)(unit + 0xa64) != NULL) {
            hasSkill = datCalcHasSkill(*(u8 **)(unit + 0xa64),0x202);
            if (((hasSkill != 0) || (datCalcCountSlotsWithValue(*(u8 **)(unit + 0xa64),0x53) != 0)
                ) || (hasSkill214 == 1)) {
              datCalcApplyBuffMask(*(u8 **)(unit + 0xa64),5,1);
            }
            hasSkill = datCalcHasSkill(*(u8 **)(unit + 0xa64),0x203);
            if (((hasSkill != 0) || (datCalcCountSlotsWithValue(*(u8 **)(unit + 0xa64),0x54) != 0)
                ) || (hasSkill213 == 1)) {
              datCalcApplyBuffMask(*(u8 **)(unit + 0xa64),0x40,1);
            }
            hasSkill = datCalcHasSkill(*(u8 **)(unit + 0xa64),0x204);
            if (((hasSkill != 0) || (datCalcCountSlotsWithValue(*(u8 **)(unit + 0xa64),0x55) != 0)
                ) || (hasSkill215 == 1)) {
              datCalcApplyBuffMask(*(u8 **)(unit + 0xa64),0x110,1);
            }
            **(u16 **)(unit + 0xa64) = **(u16 **)(unit + 0xa64) & 0xf3ff;
          }
        }
      }
      if ((formation->field04 != 0) && (formation->field06 > 0)) {
        *(s16 *)(D_0076449C + 0xcd0) = formation->field04;
        *(u16 *)(D_0076449C + 0xcd2) = formation->field06;
        *(u32 *)(D_0076449C + 0xcdc) = 1;
      }
      btlPacketEnqueue((u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 2),0);
      if ((*(u32 *)(D_0076449C + 0xc) & 0x100000) != 0) {
        btlShuffleStart(*(s32 *)(D_0076449C + 0xdd4));
        *(u32 *)(D_0076449C + 0xc) = *(u32 *)(D_0076449C + 0xc) & 0xffefffff;
      }
      if ((*(u32 *)(D_0076449C + 0x10) & 1) == 0) {
        value = btlCurrentUnitId();
        switch (value) {
        case 0x20b:
        case 0x215:
          func_002aaaa0();
          break;
        }
        btlFadeStartImmediate();
        value = func_001eb860();
        if (value == 1) {
          *(u32 *)(D_0076449C + 0xc) = *(u32 *)(D_0076449C + 0xc) | 0x2000;
          btlDamageSetSource(*(u8 **)(D_0076449C + 0xdd4),1);
        }
        else {
          u8 *battle = D_0076449C;
          *(u32 *)(battle + 0xc) = *(u32 *)(battle + 0xc) & 0xffffdfff;
          func_001eb7f0();
        }
      }
      nextState = 6;
    }
    else {
      nextState = 0;
    }
    return nextState;
}

#pragma pop
/* 744/752 bytes; twenty resolved relocations; eight zero alignment bytes.
 * Keep full-width dependency snapshots and branch-materialized final mode. */
#pragma push
/* measured: btlMainUnitLoadInit MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
// FUN_001B33C0
void btlMainUnitLoadInit(void)
{
    extern u8 *btlUnitCreateModelLoadPacket(u8 *arg0, u16 arg1, s16 arg2);
    extern u8 *btlEffectCreateFormationPacket(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4);
    extern u8 *btlEffectCreateLoadPacket(void);
    extern u8 *func_00202b60(s32 arg0);
    extern u8 *func_001f6710(s32 arg0);
    extern s32 iGpffffb450;
    s32 group_mode;
    s32 first;
    u8 *unit_packet;
    u8 *motion_packet;
    s64 previous_unit_uid;
    s64 previous_motion_uid;
    u8 *unit;
    u8 *cursor;
    u16 unit_count;
    u8 *followup_packet;
    u8 *simple_packet;
    u8 *effect_packet;
    u8 *panel_packet;
    u8 *finish_packet;
    s32 flags;
    s32 finish_mode;
    s16 motion_mode;

    first = 1;
    previous_unit_uid = 0;
    previous_motion_uid = 0;
    unit_count = 0;
    unit = *(u8 **)(D_0076449C + 0x180);
    cursor = unit;
    while (cursor != NULL) {
        unit_count++;
        cursor = *(u8 **)(cursor + 0xA6C);
    }
    group_mode = (unit_count < 4) + 1;
    while (unit != NULL) {
        unit_packet = btlUnitCreateModelLoadPacket(unit, *(u16 *)(unit + 0xA4), 0x3E);
        *(s8 *)(unit_packet + 0) = 4;
        *(s64 *)(unit_packet + 8) = previous_unit_uid;
        btlPacketEnqueue(unit_packet, 1);
        previous_unit_uid = *(s64 *)(unit_packet + 0x58);
        if (!(*(s32 *)(D_0076449C + 0x10) & 1)) {
            motion_packet = btlEffectCreateFormationPacket(iGpffffb450, (s32)unit, 0, 0, 0);
            motion_mode = 4;
            *(s8 *)(motion_packet + 0) = 4;
            *(s64 *)(motion_packet + 8) = *(s64 *)(unit_packet + 0x58);
            if (first == 1) {
                *(s16 *)(motion_packet + 0x48) = 1;
            } else {
                *(s8 *)(motion_packet + 0x10) = 5;
                *(s64 *)(motion_packet + 0x18) = previous_motion_uid;
                if (group_mode) {
                    motion_mode = 8;
                }
                *(s16 *)(motion_packet + 0x48) = motion_mode;
            }
            btlPacketEnqueue(motion_packet, 2);
            previous_motion_uid = *(s64 *)(motion_packet + 0x58);
            followup_packet = (u8 *)func_0019bbe0((BtlUnit *)unit, 0xFFFFFFFF, 0xC, 0, 3, 1);
            *(s8 *)(followup_packet + 0) = 4;
            *(s64 *)(followup_packet + 8) = *(s64 *)(unit_packet + 0x58);
            *(s8 *)(followup_packet + 0x10) = 5;
            *(s64 *)(followup_packet + 0x18) = previous_motion_uid;
            *(s16 *)(followup_packet + 0x48) = 0x1D;
            btlPacketEnqueue(followup_packet, 1);
        } else {
            simple_packet = (u8 *)func_0019bbe0((BtlUnit *)unit, 0xFFFFFFFF, 0, 0, 3, 1);
            *(s8 *)(simple_packet + 0) = 4;
            *(s64 *)(simple_packet + 8) = *(s64 *)(unit_packet + 0x58);
            *(s16 *)(simple_packet + 0x48) = 2;
            btlPacketEnqueue(simple_packet, 1);
            previous_motion_uid = *(s64 *)(simple_packet + 0x58);
        }
        first = 0;
        unit = *(u8 **)(unit + 0xA6C);
    }
    flags = *(s32 *)(D_0076449C + 0xC);
    if (!(flags & 0x20000000)) {
        effect_packet = btlEffectCreateLoadPacket();
        *(s8 *)(effect_packet + 0) = 4;
        *(s64 *)(effect_packet + 8) = previous_unit_uid;
        btlPacketEnqueue(effect_packet, 1);
        panel_packet = func_00202b60(*(s32 *)(D_0076449C + 0xDD4));
        *(s8 *)(panel_packet + 0) = 4;
        *(s64 *)(panel_packet + 8) = *(s64 *)(effect_packet + 0x58);
        btlPacketEnqueue(panel_packet, 1);
        if (datGetFlag(0x38) != 0) {
            finish_mode = 1;
        } else {
            finish_mode = 0;
        }
        finish_packet = func_001f6710((u16)finish_mode);
        *(s8 *)(finish_packet + 0) = 4;
        *(s64 *)(finish_packet + 8) = *(s64 *)(panel_packet + 0x58);
        btlPacketEnqueue(finish_packet, 1);
    }
}

#pragma pop
// FUN_001B36B0
s32 btlMainUnitLoadUpdate(void)
{
    s32 temp3;
    u8 *temp4;
    u8 *var16;

    if (btlCountUnitRecords() == 0) {
        temp4 = D_0076449C;
        temp3 = *(s32 *)(temp4 + 0xC);
        if ((temp3 & 0x100000) == 0) {
            if ((temp3 & 0x20000000) == 0) {
                btlPacketEnqueue((u8 *)btlTargetCreateTargetPacket((u32)*(u8 **)(temp4 + 0x170), 0, 0, 0, 0), 1);
            }
            var16 = *(u8 **)(D_0076449C + 0x180);
            goto check;
loop:
            if ((*(s32 *)(var16 + 0x9C) & 8) != 0) {
                btlUnitShowModel(var16);
            } else {
                btlUnitHideModel(var16);
            }
            var16 = *(u8 **)(var16 + 0xA6C);
check:
            if (var16 != NULL) {
                goto loop;
            }
            return 7;
        }
    }
    return 0;
}

// FUN_001B3790
void btlMainStartInit(void)
{
    s32 temp2;
    u8 *var16;

    if ((*(s32 *)(D_0076449C + 0x10) & 1) == 0) {
        goto done;
    }
    temp2 = btlCurrentUnitId();
    switch (temp2) {
    case 0x20B:
    case 0x215:
        func_002aaaa0();
        break;
    default:
        break;
    }
    btlFadeStart(3);
    if (func_001faaa0((u8 *)*(s32 *)(D_0076449C + 0x170)) == 0) {
        goto done;
    }
    if (btlBossIsAllowedAction() == 0) {
        goto done;
    }
    var16 = *(u8 **)(D_0076449C + 0x17C);
    goto check;
loop:
    *(u16 *)(var16 + 0x9D8) = *(u16 *)(var16 + 0x9D8) | 0x40;
    func_00198920(var16, 0, 0, 1.0f, 1);
    var16 = *(u8 **)(var16 + 0xA68);
check:
    if (var16 != NULL) {
        goto loop;
    }
done:
    return;
}

/* measured: narrowing func_00198920's integer parameter declaration to the
   retail s16/u16/s16 widths reorders the loop call's argument loads; object
   372 bytes in the 384-byte window, normalized_diff 0. */
// FUN_001B3870
s32 btlMainStartUpdate(void)
{
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_4;
    u8 *var_16;

    if (btlShuffleIsIdle(*(s32 *)(D_0076449C + 0xDD4)) != 1) goto done;
    if (btlCountUnitRecords() != 0) goto done;
    if (func_001faaf0() != 0) goto done;
    if (func_001fab90() != 0) goto done;
    if (func_001fab40(*(u8 **)(D_0076449C + 0x170)) != 0) {
        return 0;
    }
    if (btlBossIsAllowedAction() != 0) {
        var_16 = *(u8 **)(D_0076449C + 0x17C);
        goto check;
loop:
        *(u16 *)(var_16 + 0x9D8) &= 0xFFBF;
        btlUnitUpdateStatusMotion(var_16, 0);
        func_00198920(var_16, *(s16 *)(var_16 + 0x9EC), 8, *(f32 *)(var_16 + 0x9F0), *(s8 *)(var_16 + 0x9F4));
        var_16 = *(u8 **)(var_16 + 0xA68);
check:
        if (var_16 != NULL) goto loop;
    }
    if (func_001eb860() == 1) {
        temp_3 = D_0076449C;
        *(s32 *)(temp_3 + 0xC) |= 0x2000;
        btlDamageSetSource(*(u8 **)(D_0076449C + 0xDD4), 1);
    } else {
        temp_4 = D_0076449C;
        *(s32 *)(temp_4 + 0xC) &= ~0x2000;
        func_001eb7f0();
    }
    func_001b1800();
    temp_3_2 = D_0076449C;
    *(s32 *)(temp_3_2 + 0xC) |= 0x800;
    return 8;
done:
    return 0;
}

// FUN_001B39F0
void btlMainActionInit(void)
{
}

/* 1268/1280 bytes (retail ends in three words of padding); relocations:
   iGpffffb3ac / D_0076449C (the same battle-work pointer under both of this
   file's names), iGpffffb414, iGpffffb410 and the called functions.
   Levers: the state switch falls from the 1/3 body into case 2 so the final
   test reuses `state`; the "slot occupied" read goes through D_0076449C,
   which is what makes retail reload the pointer there; the two unit loops
   use separate cursors; the rank is taken before the CE0 load; the s32 at
   0xCE4 is passed straight to the s16 parameter; the declaration order
   pick/unit/alive/total/hurt gives retail's saved-register colouring. */
// FUN_001B3A00
s32 btlMainActionUpdate(void)
{
    extern s32 iGpffffb414;
    extern s32 iGpffffb410;
    u16 state;
    u8 *pick;
    u8 *unit;
    u16 alive;
    u16 total;
    s32 hurt;
    u8 *member;
    s32 status;
    s16 diff;
    s16 rank;

    if ((*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x80) != 0) {
        func_001b1830();
        func_00213b80(*(u8 **)((u8 *)iGpffffb3ac + 0xDD4));
        btlDamageSetSource(*(u8 **)((u8 *)iGpffffb3ac + 0xDD4), 0);
        state = *(u16 *)((u8 *)iGpffffb3ac + 0x1C);
        switch (state) {
        case 1:
        case 3:
            if (state == 3) {
                memset((u8 *)iGpffffb3ac + 0xCAC, 0, 0x58);
                *(s32 *)((u8 *)iGpffffb3ac + 0xC) &= 0xDFFFFFFF;
            } else {
                u16 id = *(u16 *)((u8 *)iGpffffb3ac + 0xC6C);

                if (id < 3 && ((s32 *)(D_0076449C + 0xC84))[id] != 0) {
                    *(s32 *)((u8 *)iGpffffb3ac + 0xC) |= 0x20000000;
                    return 11;
                }
                *(s32 *)((u8 *)iGpffffb3ac + 0xC) &= 0xDFFFFFFF;
            }
            pick = (u8 *)func_001b1510();
            hurt = 0;
            if (pick != NULL) {
                switch (*(u16 *)(pick + 0x6E)) {
                case 0x100:
                case 0x101:
                case 0x102:
                    *(u16 *)((u8 *)iGpffffb3ac + 0xCAC) |= 2;
                    hurt = 1;
                    break;
                }
            }
            total = 0;
            alive = 0;
            for (unit = *(u8 **)((u8 *)iGpffffb3ac + 0x17C); unit != NULL; unit = *(u8 **)(unit + 0xA68)) {
                if (datCalcIsDead(*(s32 *)(unit + 0xA64), 0) != 0) {
                    total++;
                } else {
                    *(u16 *)((u8 *)iGpffffb3ac + alive * 2 + 0xCBE) = *(u16 *)(*(u8 **)(unit + 0xA64) + 2);
                    alive++;
                    total++;
                }
            }
            *(s32 *)((u8 *)iGpffffb3ac + 0xCCC) = total;
            *(s32 *)((u8 *)iGpffffb3ac + 0xCC8) = alive;
            *(s32 *)((u8 *)iGpffffb3ac + 0xCE8) = *(u16 *)((u8 *)iGpffffb3ac + 0xC5A);
            if (*(u16 *)((u8 *)iGpffffb3ac + 0xC5A) > 0) {
                *(s32 *)((u8 *)iGpffffb3ac + 0xCE4) /= *(u16 *)((u8 *)iGpffffb3ac + 0xC5A);
            }
            if (*(u16 *)((u8 *)iGpffffb3ac + 0x1C) != 3 && btlEncountRollChance(pick) != 0 &&
                btlShuffleSelectMember((u8 *)iGpffffb3ac + 0xCEC, *(s32 *)((u8 *)iGpffffb3ac + 0xCE4), hurt) != 0) {
                *(u16 *)((u8 *)iGpffffb3ac + 0xCAC) |= 1;
            }
            if (func_0022bd20() != 0) {
                *(u16 *)((u8 *)iGpffffb3ac + 0xCAC) |= 8;
            }
            *(s32 *)((u8 *)iGpffffb3ac + 0xCB8) = btlCurrentUnitId();
            if (*(s32 *)((u8 *)iGpffffb414 + btlCurrentUnitId() * 0x18) & 0x2000) {
                rank = datCalcGetLevel(*(s32 *)(*(u8 **)(*(u8 **)((u8 *)iGpffffb3ac + 0x170) + 0x30) + 0xA64)) & 0xFF;
                diff = *(s16 *)((u8 *)iGpffffb3ac + 0xCE0) - rank;
                if (diff < 0) {
                    diff = 0;
                } else if (diff > 5) {
                    diff = 5;
                }
                *(u16 *)((u8 *)iGpffffb3ac + 0xCBC) = *(u8 *)((u8 *)iGpffffb410 + diff);
            }
            for (member = *(u8 **)((u8 *)iGpffffb3ac + 0x17C); member != NULL; member = *(u8 **)(member + 0xA68)) {
                if (*(s32 *)(member + 0xA64) != 0) {
                    status = datCalcGetBadStatus(*(s32 *)(member + 0xA64));
                    datCalcClearBadStatus(*(s32 *)(member + 0xA64), 0xFFF7FFFF);
                    if ((status & 0x100000) == 0) {
                        btlUnitUpdateStatusMotion(member, 6);
                    }
                }
            }
            if ((*(u16 *)((u8 *)iGpffffb3ac + 0xCAC) & 1) != 0 &&
                (*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x20000000) == 0) {
                btlEncounterStart(*(u8 **)((u8 *)iGpffffb3ac + 0xDD4));
            }
            *(s32 *)((u8 *)iGpffffb3ac + 0xDD0) =
                btlShuffleCreate(*(s32 *)((u8 *)iGpffffb3ac + 0xDC8), (u8 *)iGpffffb3ac + 0xCAC);
            btlShuffleCancel(*(s32 *)((u8 *)iGpffffb3ac + 0xDD0));
            state = *(u16 *)((u8 *)iGpffffb3ac + 0x1C);
            if (state == 1) {
                return (*(s32 *)((u8 *)iGpffffb3ac + 0x10) & 2) ? 12 : 11;
            }
            /* fallthrough */
        case 2:
            if (state == 2) {
                if (*(s32 *)((u8 *)iGpffffb3ac + 0x10) & 0x20000000) {
                    return 12;
                }
                return func_00193260((u8 *)iGpffffb3ac) ? 9 : 13;
            }
            return 14;
        }
    }
    return 0;
}

// FUN_001B3F00
void btlMainRevivalMesInit(void) {
    s64 *p = *(s64 **)(D_0076449C + 0x170);
    u8 *t;

    func_002baac0((u8 *)(&D_005F7000));
    func_002bad10(1);
    func_002bb050(0);
    func_002baf40(0);
    t = (u8 *)btlFormationCreateSlotPacket(3, 0xFFF);
    *(s64 *)(t + 0x60) = *p;
    btlPacketEnqueue(t, 0);
    btlPacketEnqueue((u8 *)btlCameraCreateSetStatePacket((BtlAction *)(NULL), (u16)(0x2B)), 0);
}

// FUN_001B3FB0
s32 btlMainRevivalMesUpdate(void)
{
    func_002bbcc0();
    if (func_002bb600() == 0) {
        if (func_002bb140() == 0) {
            func_00213b50(*(s32 *)(iGpffffb3ac + 0xDD4));
            func_002bb380();
            func_002bb4e0();
            return 10;
        }
        *(s32 *)(iGpffffb3ac + 0xC) &= 0xFF7FFFFF;
        func_002bb380();
        func_002bb4e0();
        return 8;
    }
    return 0;
}

/* measured: MATCH. Each follow-up packet chains to the +0x58 of the packet
   it follows (the SE packet, the per-unit formation packet, the result
   packet), not to its own. Short-lived packets use `next` so they never
   take a saved register; locals are declared in retail's $s7..$s0 order. */
// FUN_001B4060
void btlMainRevivalInit(void)
{
    union {
        u8 bytes[0x20];
        s32 words[8];
    } result;
    char formation[0x80];
    s32 camA;
    s32 camB;
    u16 maxSp;
    u8 *sePacket;
    u8 *unitAction;
    u8 *unit;
    s64 last;
    s32 form;
    u8 *packet;
    u8 *action;
    u8 *next;
    u8 *camera;
    u16 maxHp;
    s32 id;
    u32 target;

    action = *(u8 **)(iGpffffb3ac + 0x170);
    last = 0;
    form = btlFormationAllocWork(0);
    btlFormationFormatName(0x13D, formation);
    packet = (u8 *)btlFormationCreateNamedPacket(form, formation, 0);
    *(s64 *)(packet + 0x60) = *(s64 *)action;
    btlPacketEnqueue(packet, 1);
    sePacket = btlSoundCreateSkillSEPacket(0x13D, 0);
    *sePacket = 4;
    *(s64 *)(sePacket + 8) = *(s64 *)(packet + 0x58);
    *(s64 *)(sePacket + 0x60) = *(s64 *)action;
    btlPacketEnqueue(sePacket, 1);
    btlMainSkillColorPairDefaults(0x13D, &camA, &camB);
    next = btlMainCreateColorLerpPacket(camA, camB, 0x10);
    *(s64 *)(next + 0x60) = *(s64 *)action;
    btlPacketEnqueue(next, 1);
    id = btlMainSkillColorDefault(0x13D);
    btlMainSkillColorPairDefaultsAlt(0x13D, &camA, &camB);
    next = (u8 *)btlMainCreateColorWorkPacket(id, camA, camB, 0x10, 0);
    *(s64 *)(next + 0x60) = *(s64 *)action;
    btlPacketEnqueue(next, 1);
    next = btlMainCreateTintPacket(btlMainSkillTintDefault(0x13D), 0x10);
    *(s64 *)(next + 0x60) = *(s64 *)action;
    btlPacketEnqueue(next, 1);
    target = *(u32 *)(action + 0x30);
    packet = (u8 *)btlFormationCreatePacket(form, target, target, 0, 0);
    *packet = 4;
    *(s64 *)(packet + 8) = *(s64 *)(sePacket + 0x58);
    *(s64 *)(packet + 0x60) = *(s64 *)action;
    btlPacketEnqueue(packet, 2);
    next = (u8 *)btlSoundCreateCueQueuePacket(0);
    *next = 5;
    *(s64 *)(next + 8) = *(s64 *)(packet + 0x58);
    btlPacketEnqueue(next, 1);
    for (unit = *(u8 **)(iGpffffb3ac + 0x178); unit != NULL; unit = *(u8 **)(unit + 0xA6C)) {
        unitAction = func_001b0c80((s32)unit);
        func_001f0a10(result.bytes);
        maxHp = datCalcMaxHp(*(DatUnit **)(unit + 0xA64));
        maxSp = datCalcMaxSp(*(DatUnit **)(unit + 0xA64));
        result.words[0] = maxHp - datCalcGetHp(*(s32 *)(unit + 0xA64));
        result.words[1] = maxSp - datCalcGetSp(*(s32 *)(unit + 0xA64));
        if (datCalcIsDead(*(s32 *)(unit + 0xA64), 0) != 0) {
            result.words[3] = 0x80000;
        }
        next = btlPacketCreateHpRatio(unit);
        *(s64 *)(next + 0x60) = *(s64 *)action;
        btlPacketEnqueue(next, 1);
        packet = (u8 *)btlFormationCreatePacket(form, (u32)unit, (u32)unit, 1, 0);
        packet[0] = 4;
        *(s64 *)(packet + 8) = *(s64 *)(sePacket + 0x58);
        packet[0x10] = 4;
        *(s64 *)(packet + 0x18) = last;
        *(s64 *)(packet + 0x60) = *(s64 *)action;
        btlPacketEnqueue(packet, 2);
        next = (u8 *)btlSoundCreateCueQueuePacket(1);
        *next = 5;
        *(s64 *)(next + 8) = *(s64 *)(packet + 0x58);
        btlPacketEnqueue(next, 1);
        camera = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)(unitAction), (u16)(0x1B));
        camera[0] = 5;
        *(s64 *)(camera + 8) = *(s64 *)(packet + 0x58);
        camera[0x20] = 0xB;
        *(s64 *)(camera + 0x28) = *(s64 *)(packet + 0x58);
        *(s16 *)(camera + 0x4A) = 0x12;
        *(s64 *)(camera + 0x60) = *(s64 *)action;
        btlPacketEnqueue(camera, 0);
        last = *(s64 *)(camera + 0x58);
        if ((result.words[3] & 0x80000) != 0 && (*(s32 *)(unit + 0x9C) & 0x200) != 0) {
            next = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)(unit), (s16)(0x14), (u16)(0), 1.0f, (u16)(0));
            *next = 0xB;
            *(s64 *)(next + 8) = *(s64 *)(packet + 0x58);
            *(s64 *)(next + 0x60) = *(s64 *)action;
            btlPacketEnqueue(next, 1);
        }
        unitAction = (u8 *)btlTargetCreateDataPacket((s32)unitAction, (s32)unitAction, result.bytes, 1, 1);
        *unitAction = 0xB;
        *(s64 *)(unitAction + 8) = *(s64 *)(packet + 0x58);
        *(s64 *)(unitAction + 0x60) = *(s64 *)action;
        btlPacketEnqueue(unitAction, 1);
        if (result.words[0] != 0) {
            next = btlPacketCreateUnitCounter((s32)unit, 0, 0);
            *next = 4;
            *(s64 *)(next + 8) = *(s64 *)(unitAction + 0x58);
            next[0x47] &= 0xDF;
            btlPacketEnqueue(next, 3);
        }
        next = btlPacketCreateHitDisplay((s32)unit, (s32)unit, -1, 0, 0, 0, 1, result.bytes, 0);
        *next = 4;
        *(s64 *)(next + 8) = *(s64 *)(unitAction + 0x58);
        next[0x47] &= 0xDF;
        btlPacketEnqueue(next, 3);
    }
    next = btlCreateTimingPacket(0x10);
    *next = 4;
    *(s64 *)(next + 8) = last;
    *(s64 *)(next + 0x60) = *(s64 *)action;
    btlPacketEnqueue(next, 1);
    next = btlMainCreateFadePacket(0x10, 0);
    *next = 4;
    *(s64 *)(next + 8) = last;
    *(s64 *)(next + 0x60) = *(s64 *)action;
    btlPacketEnqueue(next, 1);
    next = btlMainCreateColorFadePacket(0x10);
    *next = 4;
    *(s64 *)(next + 8) = last;
    *(s64 *)(next + 0x60) = *(s64 *)action;
    btlPacketEnqueue(next, 1);
    btlFormationSetPlacement(form);
}

// FUN_001B4630
s32 btlMainRevivalUpdate(void)
{
    s64 *temp_16;
    u8 *temp_3;
    u8 *temp_4;
    u8 *temp_4_2;

    temp_16 = (s64 *)(*(u8 **)(D_0076449C + 0x170));
    if (func_00193bf0(*temp_16, (s64)0x3FFFFFFFFFFFFFFF) == 0) {
        func_00106620(0x31E, ((func_00106600(0x31E) & 0xFF) - 1) & 0xFF);
        func_001b1800();
        if (btlCheckBattleEnd() == 0) {
            temp_4 = D_0076449C;
            *(s32 *)(temp_4 + 0xC) &= ~0x80;
            if (func_001eb860() == 1) {
                btlDamageSetSource(*(u8 **)(D_0076449C + 0xDD4), 1);
            }
            btlPacketEnqueue((u8 *)btlCameraCreateSetStatePacket((BtlAction *)(temp_16), (u16)(0x24)), 0);
        } else {
            temp_3 = D_0076449C;
            *(s32 *)(temp_3 + 0xC) |= 0x80;
            temp_4_2 = D_0076449C;
            *(s32 *)(temp_4_2 + 0xC) |= 0x80000;
        }
        return 8;
    }
    return 0;
}

// FUN_001B4760
void btlMainEnemyDeadInit(void)
{
    func_001fadc0((u8 *)*(s32 *)(D_0076449C + 0x170));
    *(s32 *)(D_0076449C + 0xC) |= 0x80000;
}

// FUN_001B47A0
s32 btlMainEnemyDeadUpdate(void)
{
    s32 var2;
    u8 *temp4;

    if (func_001fae10() == 0) {
        temp4 = D_0076449C;
        *(s32 *)(temp4 + 0xC) = *(s32 *)(temp4 + 0xC) & 0xFFF7FFFF;
        func_0045a9a0(2, 0);
        if ((*(s32 *)(D_0076449C + 0xC) & 0x400) == 0) {
            func_00122520(1, 0x1E);
            H_Fade_SetCustomColor(0xFF, 0xFF, 0xFF);
        }
        if ((*(s32 *)(D_0076449C + 0xC) & 0x80) != 0) {
            var2 = 0xE;
        } else {
            var2 = 8;
        }
        return var2;
    }
    return 0;
}

// FUN_001B4860
s32 func_001b4860(s32 *arg0)
{
    return *arg0 != 0xB;
}

/* Complete packet and color phases preserve the live group dependency, all four
 * palette samples and the quaternion's W lane. The color helper follows the SDK
 * normalization, in-place channel product and byte-quantization operation graph.
 * measured b210 -O2: 2688 live bytes, frame0x90; all75 references resolved exactly.
 * The return delay instruction is included; there is no alignment tail.
 * See docs/Battle_camera_sequence_20261005.md for the finite source/native scope. */
// FUN_001B4880
void btlMainWinInit(u8 *arg0) {
    extern void func_001eb7f0(void);
    extern void btlDamageSetSource(u8 *arg0, s32 arg1);
    extern void func_001eb3b0(u8 *arg0);
    extern u8 *btlUnitCreateResourceFreePacket(u8 *arg0);
    extern u8 *func_00194c90(void *arg0, void *arg1);
    extern u8 *btlEffectCreateFormationPacket(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4);
    extern struct RtQuat *func_003dc740(struct RtQuat *rotation, const struct RwV3d *axis, f32 angle, s32 mode);
    extern s8 *func_00457160(void);
    extern BtlPacket *func_001f99c0(BtlAction *action, u16 voice, s32 option, s32 argument, s32 flags);
    extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *unit, const struct RwV3d *target, f32 speed, u32 flags);
    extern BtlPacket *btlUnitCreateHidePacket(BtlUnit *unit);
    extern BtlPacket *btlUnitCreateAnimPacket(BtlUnit *unit, s16 id, u16 blendFrames, f32 speed, u16 mode);
    extern BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);
    extern u32 datCalcIsDead(s32 arg0, s32 arg1);
    extern f32 fGpffff82cc;
    extern f32 D_0060A110[];
    extern u8 D_0060A0E0[];
    u8 *livingUnit;
    u8 *base;
    u8 *unit;
    u8 *pkt;
    u8 *pkt3;
    u8 *palette;
    s32 livingCount;
    u16 animationFrames;
    s32 t16;
    s32 t16b;
    struct CameraRotation { BtlCameraSequenceRotation value; } __attribute__((aligned(16)));
    struct CameraRotation rotation;
    BtlCameraSequenceWork *work;
    f32 ambientRed;
    f32 ambientGreen;
    f32 ambientBlue;
    f32 ambientAlpha;
    s32 color;
    work = (BtlCameraSequenceWork *)arg0;
    base = (u8 *)func_001b1510();
    if ((base == 0) || (*(u8 *)(*(u8 **)(base + 0x30) + 0xA2) == 1)) {
        base = *(u8 **)(iGpffffb3ac + 0x170);
    }
    livingCount = 0;
    livingUnit = *(u8 **)(iGpffffb3ac + 0x17C);
    while (livingUnit != 0) {
        if (((*(u32 *)(livingUnit + 0x9C) & 8) != 0) && (datCalcIsDead(*(s32 *)(livingUnit + 0xA64), 0) == 0)) {
            livingCount = (livingCount + 1) & 0xFFFF;
        }
        livingUnit = *(u8 **)(livingUnit + 0xA68);
    }
    if (((livingCount & 0xFFFF) > 1) && ((*(u16 *)(iGpffffb3ac + 0xCAC) & 3) != 0)) {
        work->singleUnit = 0;
    } else {
        work->singleUnit = 1;
    }
    animationFrames = btlUnitMotionModelFrames(*(u8 **)(base + 0x30), 0x15, 1.0f);
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0) {
        if (animationFrames > 0x28) {
            if (animationFrames > 8) {
                t16 = animationFrames - 8;
            } else {
                t16 = 0;
            }
            work->animationFrames = t16;
            if (animationFrames > 0x28) {
                t16b = animationFrames - 0x28;
            } else {
                t16b = 0;
            }
            work->soundFrame = t16b;
        } else {
            work->animationFrames = 0x28;
            work->soundFrame = 0;
        }
        work->duration = work->animationFrames;
    } else {
        func_001eb7f0();
        *(s32 *)(iGpffffb3ac + 0xC) = *(s32 *)(iGpffffb3ac + 0xC) & 0xFFFFDFFF;
        btlDamageSetSource(*(u8 **)(iGpffffb3ac + 0xDD4), 0);
        work->animationFrames = animationFrames;
        work->duration = 0x14;
    }
    work->delay = 0xC;
    work->interrupted = 0;
    func_001eb3b0(base + 0x38);
    *(u8 **) (base + 0x38) = base;
    *(u16 *)(base + 0x6A) = 1;
    {
        u8 *actionNode = *(u8 **)(iGpffffb3ac + 0x174);
        while (actionNode != 0) {
            if ((*(u16 *)(actionNode + 0x1A) & 1) != 0) {
                unit = *(u8 **)(actionNode + 0x30);
                if ((*(u8 *)(unit + 0xA2) == 1) && (datCalcIsDead(*(s32 *)(unit + 0xA64), 0) != 0)) {
                    pkt = btlUnitCreateResourceFreePacket(*(u8 **)(actionNode + 0x30));
                    *(s64 *)(pkt + 0x60) = *(s64 *)base;
                    *(u16 *)(pkt + 0x48) = work->delay;
                    btlPacketEnqueue(pkt, 0);
                }
            }
            actionNode = *(u8 **)(actionNode + 0x450);
        }
    }
    pkt = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(base + 0x30), 0x15, 0, 1.0f, 2);
    *(u16 *)(pkt + 0x48) = work->delay;
    *(s64 *)(pkt + 0x60) = *(s64 *)base;
    btlPacketEnqueue(pkt, 0);
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0) {
        u8 *const callbackPacket = func_00194c90(func_001b4860, arg0);
        btlPacketEnqueue(callbackPacket, 1);
        {
            u8 *const transitionPacket = btlEffectCreateFormationPacket(*(s32 *)(iGpffffb3ac + 0xDC0), *(s32 *)(base + 0x30), 0, *(s64 *)(callbackPacket + 0x58), 0x34100);
            s32 transitionDelay;
            if (work->delay > 2) {
                transitionDelay = work->delay - 2;
            } else {
                transitionDelay = 0;
            }
            *(s16 *)(transitionPacket + 0x48) = transitionDelay;
            *(s16 *)(transitionPacket + 0x4A) = 6;
            *(s64 *)(transitionPacket + 0x60) = *(s64 *)base;
            btlPacketEnqueue(transitionPacket, 2);
        }
        if (work->singleUnit == 1) {
            unit = *(u8 **)(base + 0x30);
            rotation.value = *(BtlCameraSequenceRotation *)(unit + 0x1C);
        } else {
            rotation = *(struct CameraRotation *)D_0060A110;
        }
        func_003dc740((struct RtQuat *)&rotation, (const struct RwV3d *)D_0060A0E0, 180.0f, 2);
        pkt = func_001ba710((f32 *)&rotation, 0);
        *(s16 *)(pkt + 0x48) = work->delay + 1;
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        btlPacketEnqueue(pkt, 1);
        pkt = (u8 *)btlMainCreateColorWorkPacket((s32)0xFF808080U, (s32)0xFF88C3FFU, (s32)0xFFCFFCF6U, 0, 0);
        *(s16 *)(pkt + 0x48) = work->delay + 1;
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        btlPacketEnqueue(pkt, 1);
        palette = (u8 *)func_00457160();
        ambientRed = (1.0f / 255.0f) * (f32)palette[0];
        palette = (u8 *)func_00457160();
        ambientGreen = (1.0f / 255.0f) * (f32)palette[1];
        palette = (u8 *)func_00457160();
        ambientBlue = (1.0f / 255.0f) * (f32)palette[2];
        palette = (u8 *)func_00457160();
        ambientAlpha = (1.0f / 255.0f) * (f32)palette[3];
        color = btlCameraBlendAmbient(ambientRed, ambientGreen, ambientBlue, ambientAlpha);
        pkt = func_001ba530(color, 0);
        *(u16 *)(pkt + 0x48) = work->delay;
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        btlPacketEnqueue(pkt, 1);
    }
    if (work->singleUnit == 0) {
        u8 *const dependencyPacket = btlFormationCreateActionPacket(base);
        u8 *pkt2;
        u8 *node;
        *(u16 *)(dependencyPacket + 0x48) = work->delay;
        *(s64 *)(dependencyPacket + 0x60) = *(s64 *)base;
        btlPacketEnqueue(dependencyPacket, 0);
        if (((*(u16 *)(iGpffffb3ac + 0xCAC) & 1) == 0) && ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0)) {
            pkt = (u8 *)func_001f99c0((BtlAction *)base, 4, 0, 0, 0);
            *(u16 *)(pkt + 0x48) = work->delay;
            *(s64 *)(pkt + 0x60) = *(s64 *)base;
            btlPacketEnqueue(pkt, 1);
        }
        node = *(u8 **)(iGpffffb3ac + 0x17C);
        while (node != 0) {
            if ((*(u32 *)(node + 0x9C) & 8) != 0) {
                if (datCalcIsDead(*(s32 *)(node + 0xA64), 0) != 0) {
                    u8 *deadPacket = (u8 *)btlUnitCreateHidePacket((BtlUnit *)node);
                    *(u8 *)(deadPacket + 0) = 4;
                    *(s64 *)(deadPacket + 8) = *(s64 *)(dependencyPacket + 0x58);
                    *(s64 *)(deadPacket + 0x60) = *(s64 *)base;
                    btlPacketEnqueue(deadPacket, 0);
                } else if (*(u8 **)(base + 0x30) != node) {
                    pkt2 = (u8 *)btlUnitCreateMovePacket((BtlUnit *)node, NULL, fGpffff82cc, 0x18);
                    *(u8 *)(pkt2 + 0) = 4;
                    *(s64 *)(pkt2 + 8) = *(s64 *)(dependencyPacket + 0x58);
                    *(s64 *)(pkt2 + 0x60) = *(s64 *)base;
                    btlPacketEnqueue(pkt2, 0);
                    pkt3 = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)node, 0x15, 0, 1.0f, 2);
                    *(u8 *)(pkt3 + 0) = 4;
                    *(s64 *)(pkt3 + 8) = *(s64 *)(pkt2 + 0x58);
                    *(s64 *)(pkt3 + 0x60) = *(s64 *)base;
                    btlPacketEnqueue(pkt3, 0);
                }
            }
            node = *(u8 **)(node + 0xA68);
        }
        pkt = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)base, 0x26);
        *(u16 *)(pkt + 0x48) = work->delay;
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        btlPacketEnqueue(pkt, 0);
        return;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0) {
        pkt = (u8 *)btlTargetCreateTargetPacket((u32)base, 0xF, 0, 0, 3);
        *(u16 *)(pkt + 0x48) = work->delay;
        btlPacketEnqueue(pkt, 1);
        pkt = (u8 *)func_001f99c0((BtlAction *)base, 4, 0, 0, 0);
        *(u16 *)(pkt + 0x48) = work->delay;
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        btlPacketEnqueue(pkt, 1);
    }
    {
        u8 *singleUnit = *(u8 **)(iGpffffb3ac + 0x17C);
        while (singleUnit != 0) {
            if (((*(u32 *)(singleUnit + 0x9C) & 8) != 0) && (*(u8 **)(base + 0x30) != singleUnit)) {
                pkt = (u8 *)btlUnitCreateHidePacket((BtlUnit *)singleUnit);
                *(u16 *)(pkt + 0x48) = work->delay;
                *(s64 *)(pkt + 0x60) = *(s64 *)base;
                btlPacketEnqueue(pkt, 0);
            }
            singleUnit = *(u8 **)(singleUnit + 0xA68);
        }
        pkt = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)base, 0x25);
        *(u16 *)(pkt + 0x48) = work->delay;
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        btlPacketEnqueue(pkt, 0);
    }
}

// FUN_001B5300
s32 btlMainWinUpdate(u8 *arg0)
{
    u8 *p;
    u16 limit;
    s32 hit;

    p = arg0;
    if ((*(s32 *)(p + 8) > (*(u16 *)(p + 0xC) + *(u16 *)(p + 0xE))) &&
        (*(s32 *)(p + 0x14) == 0) &&
        ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0) &&
        ((D_008C024C[0] & 0x10) != 0 ||
         (D_008C024E[0] & 0x40) != 0)) {
        u8 *work;

        work = (u8 *)btlTargetCreateEmptyPacket();
        *(u16 *)(work + 0x4A) = 0xC;
        btlPacketEnqueue(work, 1);
        func_001f86d0();
        *(s32 *)(p + 0x14) = 1;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0 &&
        (*(s32 *)(p + 8) == *(u16 *)(p + 0x12))) {
        btlDamageStartFlash(*(s32 *)(iGpffffb3ac + 0xDD4));
    }
    if ((*(u16 *)(iGpffffb3ac + 0xCAC) & 1) == 0) {
        goto after_cac;
    }
    limit = *(u16 *)(p + 0xC);
    hit = *(s32 *)(p + 8) < limit;
    if (hit != 0) {
        goto after_cac;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0) {
        goto after_cac;
    }
    if (*(s32 *)(p + 8) == limit) {
        btlEncounterSetReady(*(s32 *)(iGpffffb3ac + 0xDD4));
        return 0;
    }
    if (btlEncounterIsIntroDone(*(s32 *)(iGpffffb3ac + 0xDD4)) == 0) {
        return 0;
    }
after_cac:
    if ((u32)btlCountUnitRecords() < 3) {
        if (*(s32 *)(p + 0x14) == 0) {
            hit = *(s32 *)(p + 8);
            hit = hit < (*(u16 *)(p + 0xC) + *(u16 *)(p + 0x10));
            if (hit != 0) {
                goto return_zero;
            }
        }
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0) {
            return 0xE;
        }
        return 4;
    }
return_zero:
    return 0;
}

// FUN_001B54E0
void btlMainLoseInit(void)
{
    u8 *p;
    u8 *work;

    p = *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30);
    if ((datCalcIsDead(*(s32 *)(p + 0xA64), 0) != 0) &&
        ((*(s32 *)(iGpffffb3ac + 0x10) & 0x20000000) == 0)) {
        work = (u8 *)btlFormationCreatePacket((u32)*(s32 *)(iGpffffb3ac + 0xDBC), (u32)p, (u32)p, 1, 0);
        *(s64 *)(work + 0x60) = *(s64 *)(*(u8 **)(iGpffffb3ac + 0x170));
        *(u16 *)(work + 0x48) = 0xF;
        btlPacketEnqueue(work, 2);
        return;
    }
    work = func_00194b60();
    *(s64 *)(work + 0x60) = *(s64 *)(*(u8 **)(iGpffffb3ac + 0x170));
    *(u16 *)(work + 0x48) = 0x2A;
    btlPacketEnqueue(work, 1);
    func_00122520(1, 0x1E);
    switch (btlCurrentUnitId()) {
    case 0x214:
        H_Fade_SetCustomColor(0, 0, 0);
        break;
    default:
        H_Fade_SetCustomColor(0xFF, 0xFF, 0xFF);
        break;
    }
}

// FUN_001B5620
s32 btlMainLoseUpdate(u8 *arg0)
{
    if ((*(s32 *)(arg0 + 8) == 0x6E) &&
        (datCalcIsDead(*(s32 *)(*(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30) + 0xA64), 0) != 0) &&
        ((*(s32 *)(D_0076449C + 0x10) & 0x20000000) == 0)) {
        func_00122520(1, 1);
        H_Fade_SetCustomColor(0xFF, 0xFF, 0xFF);
    }
    if (func_00193bf0(*(s64 *)(*(u8 **)(D_0076449C + 0x170)),
                     (s64)0x3FFFFFFFFFFFFFFF) != 0) {
        return 0;
    }
    if (func_001f6290() != 0) {
        return 0;
    }
    return 0xE;
}

// FUN_001B5710
void btlMainFadeOutInit(u8 *arg0)
{
s32 temp4;

    temp4 = *(s32 *)(D_0076449C + 0xC);
    temp4 = temp4 & ~0x800;
    *(s32 *)(D_0076449C + 0xC) = temp4;
    if (*(u16 *)(D_0076449C + 0x1C) == 2) {
        goto done;
    }
    temp4 = *(s32 *)(D_0076449C + 0xC);
    if ((temp4 & 0x400) == 0) {
        goto fallback;
    }
    if ((temp4 & 0x40) != 0) {
        if (func_00459760(temp4) != 7) {
            func_0045a3e0(7, 1);
        }
    }
    *(s32 *)kwlnTaskGetWork(*(s32 *)(D_0076449C + 0xDD0)) |= 1;
    *(s32 *)(arg0 + 0xC) = 0;
    goto done;
fallback:
    if ((*(u16 *)(D_0076449C + 0xCAC) & 1) == 0) {
        goto done;
    }
    if ((temp4 & 0x20000000) != 0) {
        goto done;
    }
    btlEncounterSetFinish(*(s32 *)(D_0076449C + 0xDD4));
done:
    return;
}

// FUN_001B57F0
s32 btlMainFadeOutUpdate(u8 *arg0)
{
    if (*(u16 *)(iGpffffb3ac + 0x1C) == 2) {
        goto state_two;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x400) == 0) {
        goto no_four_hundred;
    }
    if (*(s32 *)(arg0 + 0xC) != 0) {
        goto check_status;
    }
    if (btlShuffleIsCanceled(*(s32 *)(iGpffffb3ac + 0xDD0)) != 0) {
        goto check_status;
    }
    if ((*(u16 *)(iGpffffb3ac + 0xCAC) & 1) == 0) {
        goto set_status;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0) {
        goto set_status;
    }
    btlEncounterSetFinish(*(s32 *)(iGpffffb3ac + 0xDD4));
set_status:
    *(s32 *)(arg0 + 0xC) = 1;
check_status:
    if (*(s32 *)(arg0 + 0xC) != 1) {
        goto return_zero;
    }
    if ((*(u16 *)(iGpffffb3ac + 0xCAC) & 1) == 0) {
        goto status_fallback;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0) {
        goto status_fallback;
    }
    if (btlEncounterIsInactive(*(s32 *)(iGpffffb3ac + 0xDD4)) != 0) {
        goto status_fallback;
    }
    return 0;
status_fallback:
    if (btlShuffleIsBusy(*(s32 *)(iGpffffb3ac + 0xDD0)) != 0) {
        goto return_zero;
    }
    return 0xF;
no_four_hundred:
    if (func_00122720() == 0) {
        goto return_zero;
    }
    return 0xF;
state_two:
    if ((*(s32 *)(iGpffffb3ac + 0x10) & 0x20000000) == 0) {
        goto state_two_f;
    }
    if (func_00122720() == 0) {
        goto return_zero;
    }
    return 0xF;
state_two_f:
    return 0xF;
return_zero:
    return 0;
}

/* 952/960 bytes; forty resolved relocations and eight zero alignment bytes.
 * Preserve full-restoration precedence and signed percentage arithmetic.
 * Reload the battle context, unit list and final task after cleanup callbacks. */
// FUN_001B5970
void btlMainEndInit(void)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_2;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 var_2;
    u16 var_16_2;
    u8 *temp_5;
    u8 *var_16;
    u8 *var_16_3;
    u8 *var_18;

    if (*(u16 *)(D_0076449C + 0x1C) == 1) {
        if (datGetFlag(0x38) != 0) var_2 = 5; else var_2 = 8;
        temp_2 = (s32)datPersonaGetRecord(var_2 & 0xFFFF);
        temp_17 = datPersonaFindSkillSlot((u8 *)temp_2, 0x10E) != -1;
        temp_16 = datPersonaFindSkillSlot((u8 *)temp_2, 0x10F) != -1;
        var_18 = *(u8 **)(D_0076449C + 0x178);
        goto loop_16_check;
loop_16:
        if ((*(s32 *)(var_18 + 0xA64) != 0) &&
            (datCalcIsDead(*(s32 *)(var_18 + 0xA64), 0) == 0)) {
            if (datCalcHasSkill((u8 *)*(s32 *)(var_18 + 0xA64), 0x224) != 0) {
                datCalcSetHp(*(s32 *)(var_18 + 0xA64), datCalcMaxHp(*(DatUnit **)(var_18 + 0xA64)));
                datCalcSetSp(*(s32 *)(var_18 + 0xA64), datCalcMaxSp(*(DatUnit **)(var_18 + 0xA64)));
            } else if (datCalcHasSkill((u8 *)*(s32 *)(var_18 + 0xA64), 0x223) != 0) {
                datCalcAddHp((DatUnit *)*(s32 *)(var_18 + 0xA64), ((datCalcMaxHp(*(DatUnit **)(var_18 + 0xA64)) & 0xFFFF) * 100) / 1250);
                datCalcAddSp((DatUnit *)*(s32 *)(var_18 + 0xA64), ((datCalcMaxSp(*(DatUnit **)(var_18 + 0xA64)) & 0xFFFF) * 100) / 1250);
            }
            if (temp_17 != 0) datCalcAddHp((DatUnit *)*(s32 *)(var_18 + 0xA64), ((datCalcMaxHp(*(DatUnit **)(var_18 + 0xA64)) & 0xFFFF) * 100) / 2000);
            if (temp_16 != 0) datCalcAddSp((DatUnit *)*(s32 *)(var_18 + 0xA64), ((datCalcMaxSp(*(DatUnit **)(var_18 + 0xA64)) & 0xFFFF) * 100) / 2000);
        }
        var_18 = *(u8 **)(var_18 + 0xA6C);
loop_16_check:
        if (var_18 != NULL) goto loop_16;
    }
    func_001bdd60();
    btlPanelReset(*(s32 *)(D_0076449C + 0xDD4));
    var_16 = *(u8 **)(D_0076449C + 0x178);
    goto loop_21_check;
loop_21:
    temp_4_2 = *(s32 *)(var_16 + 0xA64);
    if (temp_4_2 != 0) datCalcClearAllBuffs((u8 *)temp_4_2);
    var_16 = *(u8 **)(var_16 + 0xA6C);
loop_21_check:
    if (var_16 != NULL) goto loop_21;
    if (datGetFlag(0x3D) == 0) {
        for (var_16_2 = 1; var_16_2 < 0xB; ++var_16_2)
            *(s8 *)(datUnitGetRecord(var_16_2) + 0x10) = 0;
    }
    var_16_3 = *(u8 **)(D_0076449C + 0x174);
    goto loop_30_check;
loop_30:
    if (*(u16 *)(var_16_3 + 0xC) != 0x24) btlActionSetState((BtlAction *)var_16_3, 0x24);
    var_16_3 = *(u8 **)(var_16_3 + 0x450);
loop_30_check:
    if (var_16_3 != NULL) goto loop_30;
    func_00193d30();
    temp_5 = D_0076449C;
    if ((*(s32 *)(temp_5 + 0x10) & 0x20000000) &&
        datCalcIsDead(*(s32 *)(*(u8 **)(*(u8 **)(temp_5 + 0x170) + 0x30) + 0xA64), 0) != 0) {
        datCalcSetHp(*(s32 *)(*(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30) + 0xA64), 1);
        datCalcClearBadStatus(*(s32 *)(*(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30) + 0xA64), 0x80000);
    }
    temp_4_3 = *(s32 *)(D_0076449C + 0xDD4);
    if (temp_4_3 != 0) {
        kwlnTaskDestroyWithHierarchy((KwlnTask *)temp_4_3);
        *(s32 *)(D_0076449C + 0xDD4) = 0;
    }
}

// FUN_001B5D30
s32 btlMainEndUpdate(void) {
    u8 *p;

    if (*(s32 *)(D_0076449C + 0x174) != 0) {
        return 0;
    }
    func_001b69c0();
    p = D_0076449C;
    if ((*(s32 *)(p + 0xC) & 0x400) != 0 &&
        *(u16 *)(p + 0x1C) != 2) {
        return 0x10;
    }
    return 0x11;
}

// FUN_001B5DA0
void btlMainResultInit(void) {
}

// FUN_001B5DB0
s32 btlMainResultUpdate(void)
{
    u8 *temp_3;

    if (*(s32 *)(kwlnTaskGetWork(*(s32 *)(iGpffffb3ac + 0xDD0)) + 4) != 0) {
        return 0;
    }
    kwlnTaskDestroyWithHierarchy((KwlnTask *)*(s32 *)(iGpffffb3ac + 0xDD0));
    *(s32 *)(iGpffffb3ac + 0xDD0) = 0;
    temp_3 = (u8 *)iGpffffb3ac;
    if ((*(u8 *)(temp_3 + 0xC65) == 1) &&
        (*(s32 *)(temp_3 + 0xC) & 0x400)) {
        func_00122640(1, 0xC);
    }
    return 0x11;
}

// FUN_001B5E40
void btlMainExitInit(void)
{
    func_00193d30();
}


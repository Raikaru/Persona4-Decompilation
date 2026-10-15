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
extern s32 RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void func_00213b80(u8 *arg0);
extern s32 func_001ef7e0(u8 *arg0);
extern s32 func_0036ee60(u8 *arg0, s16 arg1, s32 arg2);
extern s32 datCalcGetBadStatus(s32 arg0);
extern void func_002138a0(u8 *arg0);
extern s32 func_0021d980(s32 arg0, u8 *arg1);
extern void func_0021dab0(s32 arg0);
extern s32 datCalcGetLevel(s32 arg0);
extern s32 func_00193260(u8 *arg0);
extern void memset(void *dst, s32 value, s32 size);
extern void func_001fc1b0(s16 arg0);
extern s32 mcIconTaskCreate(u8 *parent, s32 mode);
extern void fieldSceneLoad(s32 arg0, s32 arg1);
extern s32 func_003bbb60(u8 *arg0);
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern void *SceneDraw_GetList4FirstColor(void);
extern s32 func_001b0d70(u8 *arg0);
extern s32 func_001b0dd0(u8 *arg0);
extern void *SceneDraw_GetList4SecondColor(void);
extern void func_001b6990();
extern void func_00193d30(void);
extern s32 func_00122640(s32 arg0, s32 arg1);
extern s32 func_001d3d50(s32 arg0);
extern BtlPacket *func_001d5eb0(u32 arg0, const char *arg1, u16 arg2);
extern u8 *btlSoundCreateSkillSEPacket(s32 arg0, s32 arg1);
extern u8 *btlMainCreateColorLerpPacket(s32 arg0, s32 arg1, s32 arg2);
extern BtlPacket *btlMainCreateColorWorkPacket(s32 first, s32 second, s32 third, u32 frames, u16 mode);
extern u8 *btlMainCreateTintPacket(s32 arg0, s32 arg1);
extern void func_001f0a10(u8 *arg0);
extern u8 *func_00202740(u8 *arg0);
extern BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);
extern BtlPacket *btlUnitCreateAnimPacket(BtlUnit *unit, s16 id, u16 blendFrameCount, f32 speed, u16 mode);
extern BtlPacket *func_001f36e0(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
extern u8 *func_00202590(s32 unit, s8 kind, s16 value);
extern u8 *func_00201de0(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
extern u8 *btlCreateTimingPacket(s32 arg0);
extern u8 *btlMainCreateFadePacket(s32 arg0, s32 arg1);
extern u8 *btlMainCreateColorFadePacket(s32 arg0);
extern u16 datCalcGetHp(s32 unit);
extern u16 datCalcGetSp(s32 unit);
extern void func_001b7060(u32 arg0, s32 *arg1, s32 *arg2);
extern s32 func_001b7080(s32 arg0);
extern s32 func_001b7090(s32 arg0);
extern void func_001b70a0(u32 arg0, s32 *arg1, s32 *arg2);
extern void func_001d3e00(s32 arg0);
extern void btlUnitSetFlags(u8 *arg0, s32 arg1);
extern void btlUnitClearFlags(u8 *arg0, s32 arg1);
extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *arg0);
extern u32 func_00452560(s32 arg0);
extern s32 func_00459760(s32 arg0);
extern void func_0045a3e0(s32 arg0, s32 arg1);
extern void func_00213a10(s32 task);
extern u32 datCalcIsDead(s32 arg0, s32 arg1);
extern u8 *func_00193bf0(u64 arg0, u64 arg1);
extern s32 func_001f6290(void);
extern s32 func_00144f60(void);
extern void (*jtbl_008873EC[])(void *);
extern void func_004833f0(void *arg0);
extern f32 D_00922CA0[];
extern f32 D_00922CA4[];
extern f32 D_00922CA8[];
extern f32 D_00922CAC[];
extern f32 D_00922CB0[];
extern f32 D_00922CB4[];
extern f32 D_00922CB8[];
extern f32 D_00922CBC[];
extern s32 D_00922CC0[];
extern s32 btlUnitIsMoving(u8 *arg0);
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
extern void func_0022bd60(void);
extern s32 func_001fadc0(u8 *arg0);
extern u32 btlCountUnitRecords(void);
extern BtlPacket *func_001f5f70(u32 arg0, u16 arg1, u32 arg2, u32 arg3, u32 arg4);
extern void btlUnitShowModel(u8 *arg0);
extern void btlUnitHideModel(u8 *arg0);
extern s32 func_001ef9a0(void);
extern void func_002aaaa0(void);
extern void btlFadeStart(s32 arg0);
extern s32 func_001faaa0(u8 *arg0);
extern s32 func_00230210(void);
extern s32 func_001fae10(void);
extern void func_0045a9a0(s32 arg0, s32 arg1);
extern void func_00122520(s32 arg0, s32 arg1);
extern void H_Fade_SetCustomColor(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_002aa3f0(void);
extern void func_00192b20(void);
extern void func_00145080();
extern s32 func_001ba0e0(struct ColorBlendWork *work);
extern u8 *btlPacketAlloc(s32 size, s32 align);
extern void func_001ec5e0(u8 *arg0, f32 fp);
extern void func_001b69c0(void);
extern s32 func_001ba590(u8 *arg0);
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *arg0);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void func_001eb380(u8 *arg0);
extern s64 btlGetUID(void);
extern u32 datCalcRandomBelow(u32 arg0);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern u32 datCalcGetBattleStat(u8 *arg0, s32 arg1);
extern void func_0022fdc0(u8 *arg0);
extern s32 datCalcUnitClass(u8 *arg0);
extern void func_001b1020(s32 arg0);
extern void func_001b1280(s32 arg0);
extern u32 iGpffffa0b8;
extern void func_0014a2e0(u32 arg0);
extern void func_001b6120(void);
extern u32 datGetFlag(s32 arg0);
extern BtlPacket *func_001f9b80(u16 arg0);
extern u8 *func_001f97b0(void);
extern u8 *btlBossCreateLoadPakPacket(void);
extern s32 func_00230790(void);
extern BtlPacket *func_002305c0(s32 arg0);
extern void func_002aaa80(void);
extern void func_001fc280(void);
s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
extern s32 func_0021d470(s32 task);
extern void func_001eb7f0(void);
extern s32 func_001eb860(void);
extern s32 func_001faaf0(void);
extern s32 func_001fab40(u8 *arg0);
extern s32 func_001fab90(void);
extern void func_00212240(u8 *arg0, s32 arg1);
BtlPacket *func_001d3700(u16 arg0, u16 arg1);
extern u8 func_002baac0(u8 *message);
void func_002bad10(u32 arg0);
void func_002bb050(u32 arg0);
void func_002baf40(u32 arg0);
extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
extern void func_001bcd40(u8 *arg0, u8 *arg1, f32 *arg2, f32 arg4, u16 arg3);
extern void func_001b73f0(u8 *arg0);
extern void func_001bdd80(u8 *arg0, u8 *arg1, s32 arg2);
extern s32 func_001be990(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern u8 D_005FB400[];
static inline u8 *func_001bf3a0_add(s32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
static inline f32 func_001ba790_mul(f32 left, f32 right)
{
    return left * right;
}
extern void *SceneDraw_GetList4Matrix(void);
extern u8 *resrcMngGetColorValue(void);
extern u8 *resrcMngGetColorTarget(void);
extern s32 func_001d07e0(u8 *arg0, u8 *arg1);
extern u8 *func_001d1200(u8 *arg0);
extern void func_001d10f0(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4);
extern void func_001bdeb0(u8 *arg0);
extern BtlPacket *func_001d6240(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
extern u8 *func_00194b60(void);
extern BtlPacket *func_001f60c0(void);
extern void func_001f86d0(void);
extern void func_00212100(s32 arg0);
extern void func_00213990(s32 task);
extern s32 func_002139d0(s32 task);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern s32 func_0021db10(s32 task);
extern s32 func_00213a50(s32 arg0);
extern s32 func_0021db40(s32 task);
extern s32 func_00122720(void);
extern BtlPacket *func_0019bbe0(BtlUnit *arg0, u32 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5);
extern BtlPacket *func_001f7c20(u16 arg0, u16 arg1, u16 arg2);
extern void btlUnitUnlinkAndFree(u8 *arg0);
extern void func_001b08f0(void *arg0);
extern void func_001bc800(u8 *arg0);
extern void datUnitRemoveEncounterUnit(DatUnitEc *arg0, DatUnit *arg1);
extern void func_001bdd60(void);
extern u8 *func_00105510(s16 arg0);
extern u16 *datPersonaGetRecord(u16 arg0);
extern s32 datPersonaFindSkillSlot(u8 *arg0, u16 arg1);
extern void func_002038c0(s32 arg0);
extern void datCalcSetHp(s32 arg0, u16 arg1);
extern void datCalcSetSp(s32 arg0, u16 arg1);
extern u16 datCalcMaxHp(DatUnit *arg0);
extern u16 datCalcMaxSp(DatUnit *arg0);
extern s32 datCalcAddHp(DatUnit *arg0, s32 arg1);
extern s32 datCalcAddSp(DatUnit *arg0, s32 arg1);
extern s32 datCalcHasSkill(u8 *arg0, s32 arg1);
extern u32 datCalcClearBadStatus(s32 arg0, u32 arg1);
extern void datCalcClearAllBuffs(u8 *arg0);
extern void btlUnitSetColor(u8 *arg0, s32 arg1);
extern void func_001bc660(s32 state, BtlAction *action, u32 param_3);
extern void func_001bd780(void *arg0, const void *arg1, const void *arg2, const void *arg3);
extern void func_001bd560(f32 *arg0, f32 *arg1);
extern void func_001ba790(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3);
extern u32 btlMainCurveAppendKeyframe(u16 *arg0, f32 *arg1, f32 *arg2);
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
extern f32 func_001ec630(f32 value, f32 *state);
extern u32 btlCameraSampleKeyframes(u8 *arg0, f32 *arg1, f32 *arg2);
extern u32 btlCameraAdvanceKeyframes(u8 *arg0, f32 arg1);
extern f32 fGpffff8430;
extern void primQuad3D(f32 *arg0, u8 *arg1, s32 arg2, f32 arg3);
extern void primAxisLine3D(f32 *arg0, s32 arg1, f32 arg2);
extern u8 *func_0022cdb0(s32 arg0);
extern void func_003e9cb0(void *arg0, void *arg1, s32 arg2);
extern s32 func_00457120(void);
extern void K_View_SetFov(void *arg0, f32 arg1);
extern f32 fGpffff8048;
extern u8 D_005F74C0[];
extern void func_001bd390(void);
extern u8 *func_003e8180(u8 *arg0, f32 arg1);
extern s32 func_003bbbe0(s32 arg0, s32 arg1, void *arg2);
extern void func_001d12e0(void *arg0);
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
extern void func_003dcc70(f32 *arg0, f32 *arg1, f32 *arg2);

s32 func_001f2f90(u8 *arg0);

void func_004b1680(s32 arg0, s16 arg1, s32 arg2, s32 arg3);




extern u8 *func_001b0c80(s32 arg0);
#pragma opt_propagation off
#pragma opt_propagation on
#pragma push
#pragma opt_common_subs off
#pragma pop

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
        func_0022fdc0(0);
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
void func_001b18c0(void)
{
}

// FUN_001B18D0
s32 func_001b18d0(void)
{
    return 0;
}

// FUN_001B18E0
void func_001b18e0(void) {
    func_001f7620(2, 0);
    func_001f7620(3, 0);
    func_001f7570(0);
    func_00106550(0x78, func_001064f0(0x78) + 1);
}

// FUN_001B1940
s32 func_001b1940(void) {
    u8 *b = D_0076449C;
    s32 off = *(u16 *)(b + 0xC6C) << 2;

    *(s32 *)(b + 0xC68) = *(s32 *)(off + (s32)b + 0xC84);
    b = D_0076449C;
    *(u16 *)(b + 0xC6C) = *(u16 *)(b + 0xC6C) + 1;
    if (func_0022bd20() != 0) {
        func_0022bd60();
    }
    return 3;
}

// FUN_001B19A0
void func_001b19a0(void)
{
    func_001b6990();
}

/* measured: opt_rebuildconditionals off for func_001b19c0 branch-fed scalar. */
#pragma opt_rebuildconditionals off
// FUN_001B19C0
s32 func_001b19c0(void)
{
    extern s32 func_001b6a00(void);
    extern u32 btlCountUnitRecords(void);
    extern void func_0014a2e0(u32 arg0);
    extern void func_001b6120(void);
    extern u32 datGetFlag(s32 arg0);
    extern BtlPacket *func_001f9b80(u16 arg0);
    extern s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
    extern u8 *func_001f97b0(void);
    extern s32 func_0022bd20(void);
    extern u8 *btlBossCreateLoadPakPacket(void);
    extern s32 func_00230790(void);
    extern s32 func_001ef9a0(void);
    extern void func_002aaa80(void);
    extern void func_001fc280(void);
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
    temp_2 = (u8 *)func_001f9b80((u16)(var_2 & 0xFFFF));
    btlPacketEnqueue(temp_2, 1);
    temp_2_2 = func_001f97b0();
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
    temp_2_4 = func_001ef9a0();
    switch (temp_2_4) {
    case 0x20B:
    case 0x215:
        func_002aaa80();
        func_001fc280();
        break;
    }
    return 5;
done:
    return 0;
}
/* measured: close opt_rebuildconditionals off for func_001b19c0. */
#pragma opt_rebuildconditionals on
// FUN_001B1B20
void func_001b1b20(void)
{
}
// FUN_001B1B30
s32 func_001b1b30(void)
{
    extern u8 *func_001f5f70(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern void func_00212240(u8 *arg0, s32 arg1);
    extern void func_0020bf90(s32 arg0);
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
    func_0020bf90(*(s32 *)((u8 *)iGpffffb3ac + 0xDD4));
    btlPacketEnqueue(
        (u8 *)func_001f5f70(*(u8 **)((u8 *)iGpffffb3ac + 0x170),
                            0x1F, 0, 0, 0),
        1);
    next = *(u8 **)((u8 *)iGpffffb3ac + 0x174);
    goto second_check;
second_body:
    if ((*(u16 *)(next + 0x1A) & 1) != 0) {
        unit = *(u8 **)(next + 0x30);
        if (*(u8 *)(unit + 0xA2) == 0 &&
            *(s32 *)(unit + 0xA64) != 0) {
            btlPacketEnqueue(func_001f3870(next, 2), 1);
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
        func_00212240(*(u8 **)((u8 *)iGpffffb3ac + 0xDD4), 1);
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
void func_001b1d70(void) {
    extern s32 iGpffffb414;
    extern u8 *func_0019f5f0(s32 arg0, u16 arg1, u16 *arg2);
    extern u32 datCalcClearBadStatus(s32 arg0, u32 arg1);
    extern void *mdlFindModelObject(u32 arg0, u16 arg1, u32 arg2);
    extern u8 *btlUnitCreateModelLoadPacket(u8 *arg0, u16 arg1, s16 arg2);
    extern void func_0014a460(u16 arg0, u32 arg1);
    extern void btlUnitApplyModelState(u8 *arg0, s32 arg1);
    extern void func_001987a0(u8 *arg0);
    extern void func_0047d170(void *model);
    extern u8 *mdlGetClump(u8 *arg0);
    extern void mdlClumpSetEnvMapState(u8 *arg0);
    extern s32 func_001ef8c0(void);
    extern void func_001b11c0(s32 arg0);
    extern s32 func_001b0f20(s32 arg0);
    extern s32 datCalcStatusElement(s32 arg0, s32 arg1);
    extern s32 func_0023a6b0(u8 *arg0, s32 arg1);
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
            pkt = func_0019f5f0(0, id, (u16 *)tmp);
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
                func_001987a0(unit);
                tmp = *(u8 **)(unit + 0xA00);
                if (*(s32 *)(tmp + 0x2D0) == 0) {
                    func_0047d170(tmp);
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
            func_0019f5f0(1, *(s16 *)(list + 2), (u16 *)list);
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
            func_0022fdc0((u8 *)0);
        } else {
            *(u16 *)(D_0076449C + 0x1A) = func_001ef8c0();
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
                    if ((func_0023a6b0(*(u8 **)(j + 0xA64), r2) & 0x27000000) == 0 && (s32)datCalcRandomBelow(100) < 0) {
                        datCalcSetBadStatus(*(s32 *)(j + 0xA64), 2);
                    }
                    if ((func_0023a6b0(*(u8 **)(j + 0xA64), r1) & 0x27000000) == 0 && (s32)datCalcRandomBelow(100) < 0) {
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
#pragma opt_lifetimes on
// FUN_001B2380
s32 func_001b2380(void)
{
    extern void func_001f73d0(void);
    extern void func_0021d440(s32 task);
    extern s32 iGpffffb414;
    extern s32 func_001b1540(void);
    extern void func_001958f0(BtlUnit *unit, RwV3d *dst);
    extern f32 func_00196040(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter, f32 *outTop, f32 *outBottom, u32 options);
    extern void func_001ee250(u8 *arg0, u8 *arg1);
    extern void func_001ec1c0(u8 *rotation, u8 *from, u8 *to);
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
      func_001958f0((BtlUnit *)*(void **)(action + 0x30), &groupCenter);
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
              func_001ec1c0((u8 *)&rotation,(u8 *)&position,(u8 *)&groupCenter);
            }
            btlUnitSetRot((BtlUnit *)nodeOrPacket, &rotation);
          }
        }
      }
      func_00196040(2,0,&groupCenter,NULL,NULL,1);
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
          btlPacketEnqueue((u8 *)func_001f8330((BtlUnit *)unit),1);
          btlPacketEnqueue((u8 *)btlUnitCreateAnimPacket((BtlUnit *)unit, 0x13, 0, 1.0f, 2),1);
          btlPacketEnqueue((u8 *)btlUnitCreateModelFramePacket((BtlUnit *)unit,
              btlUnitMotionModelFrames(unit,0x13,1.0f)),1);
          btlPacketEnqueue((u8 *)func_001f82b0((BtlUnit *)unit),1);
          if ((*(u32 *)(D_0076449C + 0xc) & 0x20000000) != 0) {
            position.x = (f32)(*(s16 *)(unit + 0x94) * 0x19 - 0x6d6);
            position.z = (f32)(*(s16 *)(unit + 0x96) * 0x19 - 0x6d6);
            btlUnitSetPos((BtlUnit *)unit, &position);
          }
        } else {
          func_00194ff0(unit,(u8 *)&position,NULL,(f32 *)&targetDirection);
          func_00196040(2,0,&groupCenter,NULL,NULL,1);
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
                    func_001958f0((BtlUnit *)nodeOrPacket, &actorCenter);
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
                  func_001958f0((BtlUnit *)nodeOrPacket, &groupCenter);
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
              func_001ec1c0((u8 *)&rotation,(u8 *)&position,(u8 *)&groupCenter);
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
              func_001ec1c0((u8 *)&rotation,(u8 *)&offset,(u8 *)&position);
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
        func_0021d440(*(s32 *)(D_0076449C + 0xdd4));
        *(u32 *)(D_0076449C + 0xc) = *(u32 *)(D_0076449C + 0xc) & 0xffefffff;
      }
      if ((*(u32 *)(D_0076449C + 0x10) & 1) == 0) {
        value = func_001ef9a0();
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
          func_00212240(*(u8 **)(D_0076449C + 0xdd4),1);
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
#pragma opt_rebuildconditionals off
// FUN_001B33C0
void func_001b33c0(void)
{
    extern u8 *btlUnitCreateModelLoadPacket(u8 *arg0, u16 arg1, s16 arg2);
    extern u8 *func_001d65d0(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4);
    extern u8 *func_001d7880(void);
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
            motion_packet = func_001d65d0(iGpffffb450, (s32)unit, 0, 0, 0);
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
        effect_packet = func_001d7880();
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
s32 func_001b36b0(void)
{
    s32 temp3;
    u8 *temp4;
    u8 *var16;

    if (btlCountUnitRecords() == 0) {
        temp4 = D_0076449C;
        temp3 = *(s32 *)(temp4 + 0xC);
        if ((temp3 & 0x100000) == 0) {
            if ((temp3 & 0x20000000) == 0) {
                btlPacketEnqueue((u8 *)func_001f5f70((u32)*(u8 **)(temp4 + 0x170), 0, 0, 0, 0), 1);
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
void func_001b3790(void)
{
    s32 temp2;
    u8 *var16;

    if ((*(s32 *)(D_0076449C + 0x10) & 1) == 0) {
        goto done;
    }
    temp2 = func_001ef9a0();
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
    if (func_00230210() == 0) {
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
s32 func_001b3870(void)
{
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_4;
    u8 *var_16;

    if (func_0021d470(*(s32 *)(D_0076449C + 0xDD4)) != 1) goto done;
    if (btlCountUnitRecords() != 0) goto done;
    if (func_001faaf0() != 0) goto done;
    if (func_001fab90() != 0) goto done;
    if (func_001fab40(*(u8 **)(D_0076449C + 0x170)) != 0) {
        return 0;
    }
    if (func_00230210() != 0) {
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
        func_00212240(*(u8 **)(D_0076449C + 0xDD4), 1);
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
void func_001b39f0(void)
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
s32 func_001b3a00(void)
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
        func_00212240(*(u8 **)((u8 *)iGpffffb3ac + 0xDD4), 0);
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
            if (*(u16 *)((u8 *)iGpffffb3ac + 0x1C) != 3 && func_001ef7e0(pick) != 0 &&
                func_0036ee60((u8 *)iGpffffb3ac + 0xCEC, *(s32 *)((u8 *)iGpffffb3ac + 0xCE4), hurt) != 0) {
                *(u16 *)((u8 *)iGpffffb3ac + 0xCAC) |= 1;
            }
            if (func_0022bd20() != 0) {
                *(u16 *)((u8 *)iGpffffb3ac + 0xCAC) |= 8;
            }
            *(s32 *)((u8 *)iGpffffb3ac + 0xCB8) = func_001ef9a0();
            if (*(s32 *)((u8 *)iGpffffb414 + func_001ef9a0() * 0x18) & 0x2000) {
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
                func_002138a0(*(u8 **)((u8 *)iGpffffb3ac + 0xDD4));
            }
            *(s32 *)((u8 *)iGpffffb3ac + 0xDD0) =
                func_0021d980(*(s32 *)((u8 *)iGpffffb3ac + 0xDC8), (u8 *)iGpffffb3ac + 0xCAC);
            func_0021dab0(*(s32 *)((u8 *)iGpffffb3ac + 0xDD0));
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
void func_001b3f00(void) {
    s64 *p = *(s64 **)(D_0076449C + 0x170);
    u8 *t;

    func_002baac0((u8 *)(&D_005F7000));
    func_002bad10(1);
    func_002bb050(0);
    func_002baf40(0);
    t = (u8 *)func_001d3700(3, 0xFFF);
    *(s64 *)(t + 0x60) = *p;
    btlPacketEnqueue(t, 0);
    btlPacketEnqueue((u8 *)btlCameraCreateSetStatePacket((BtlAction *)(NULL), (u16)(0x2B)), 0);
}



// FUN_001B3FB0
s32 func_001b3fb0(void)
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
void func_001b4060(void)
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
    form = func_001d3d50(0);
    func_001d69f0(0x13D, formation);
    packet = (u8 *)func_001d5eb0(form, formation, 0);
    *(s64 *)(packet + 0x60) = *(s64 *)action;
    btlPacketEnqueue(packet, 1);
    sePacket = btlSoundCreateSkillSEPacket(0x13D, 0);
    *sePacket = 4;
    *(s64 *)(sePacket + 8) = *(s64 *)(packet + 0x58);
    *(s64 *)(sePacket + 0x60) = *(s64 *)action;
    btlPacketEnqueue(sePacket, 1);
    func_001b7060(0x13D, &camA, &camB);
    next = btlMainCreateColorLerpPacket(camA, camB, 0x10);
    *(s64 *)(next + 0x60) = *(s64 *)action;
    btlPacketEnqueue(next, 1);
    id = func_001b7080(0x13D);
    func_001b70a0(0x13D, &camA, &camB);
    next = (u8 *)btlMainCreateColorWorkPacket(id, camA, camB, 0x10, 0);
    *(s64 *)(next + 0x60) = *(s64 *)action;
    btlPacketEnqueue(next, 1);
    next = btlMainCreateTintPacket(func_001b7090(0x13D), 0x10);
    *(s64 *)(next + 0x60) = *(s64 *)action;
    btlPacketEnqueue(next, 1);
    target = *(u32 *)(action + 0x30);
    packet = (u8 *)func_001d6240(form, target, target, 0, 0);
    *packet = 4;
    *(s64 *)(packet + 8) = *(s64 *)(sePacket + 0x58);
    *(s64 *)(packet + 0x60) = *(s64 *)action;
    btlPacketEnqueue(packet, 2);
    next = (u8 *)func_001f8140(0);
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
        next = func_00202740(unit);
        *(s64 *)(next + 0x60) = *(s64 *)action;
        btlPacketEnqueue(next, 1);
        packet = (u8 *)func_001d6240(form, (u32)unit, (u32)unit, 1, 0);
        packet[0] = 4;
        *(s64 *)(packet + 8) = *(s64 *)(sePacket + 0x58);
        packet[0x10] = 4;
        *(s64 *)(packet + 0x18) = last;
        *(s64 *)(packet + 0x60) = *(s64 *)action;
        btlPacketEnqueue(packet, 2);
        next = (u8 *)func_001f8140(1);
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
        unitAction = (u8 *)func_001f36e0((s32)unitAction, (s32)unitAction, result.bytes, 1, 1);
        *unitAction = 0xB;
        *(s64 *)(unitAction + 8) = *(s64 *)(packet + 0x58);
        *(s64 *)(unitAction + 0x60) = *(s64 *)action;
        btlPacketEnqueue(unitAction, 1);
        if (result.words[0] != 0) {
            next = func_00202590((s32)unit, 0, 0);
            *next = 4;
            *(s64 *)(next + 8) = *(s64 *)(unitAction + 0x58);
            next[0x47] &= 0xDF;
            btlPacketEnqueue(next, 3);
        }
        next = func_00201de0((s32)unit, (s32)unit, -1, 0, 0, 0, 1, result.bytes, 0);
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
    func_001d3e00(form);
}
// FUN_001B4630
s32 func_001b4630(void)
{
    s64 *temp_16;
    u8 *temp_3;
    u8 *temp_4;
    u8 *temp_4_2;

    temp_16 = (s64 *)(*(u8 **)(D_0076449C + 0x170));
    if (func_00193bf0(*temp_16, (s64)0x3FFFFFFFFFFFFFFF) == 0) {
        func_00106620(0x31E, ((func_00106600(0x31E) & 0xFF) - 1) & 0xFF);
        func_001b1800();
        if (func_00193060() == 0) {
            temp_4 = D_0076449C;
            *(s32 *)(temp_4 + 0xC) &= ~0x80;
            if (func_001eb860() == 1) {
                func_00212240(*(u8 **)(D_0076449C + 0xDD4), 1);
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
void func_001b4760(void)
{
    func_001fadc0((u8 *)*(s32 *)(D_0076449C + 0x170));
    *(s32 *)(D_0076449C + 0xC) |= 0x80000;
}
// FUN_001B47A0
s32 func_001b47a0(void)
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
#include "btl_camera_sequence_internal.h"

typedef struct BtlCameraColorReal {
    f32 red, green, blue, alpha;
} BtlCameraColorReal;

/* Complete the four byte-to-real conversions before in-place modulation. */
static inline void btlCameraNormalizeColor(BtlCameraColorReal *result, const u8 *bytes)
{
    result->red = (1.0f / 255.0f) * (f32)bytes[0];
    result->green = (1.0f / 255.0f) * (f32)bytes[1];
    result->blue = (1.0f / 255.0f) * (f32)bytes[2];
    result->alpha = (1.0f / 255.0f) * (f32)bytes[3];
}
/* Input and result may share the same real-color record, component by component. */
static inline void btlCameraMultiplyColor(BtlCameraColorReal *result, const BtlCameraColorReal *base, const BtlCameraColorReal *ambient)
{
    result->red = base->red * ambient->red;
    result->green = base->green * ambient->green;
    result->blue = base->blue * ambient->blue;
    result->alpha = base->alpha * ambient->alpha;
}
/* The SDK byte-to-real factor is the existing retail 0x3b808081 literal.
 * Keep four palette calls in the caller; this phase consumes their snapshots. */
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
/* Complete packet and color phases preserve the live group dependency, all four
 * palette samples and the quaternion's W lane. The color helper follows the SDK
 * normalization, in-place channel product and byte-quantization operation graph.
 * measured b210 -O2: 2688 live bytes, frame0x90; all75 references resolved exactly.
 * The return delay instruction is included; there is no alignment tail.
 * See docs/Battle_camera_sequence_20261005.md for the finite source/native scope. */
// FUN_001B4880
void func_001b4880(u8 *arg0) {
    extern void func_001eb7f0(void);
    extern void func_00212240(u8 *arg0, s32 arg1);
    extern void func_001eb3b0(u8 *arg0);
    extern u8 *btlUnitCreateResourceFreePacket(u8 *arg0);
    extern u8 *func_00194c90(void *arg0, void *arg1);
    extern u8 *func_001d65d0(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4);
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
        func_00212240(*(u8 **)(iGpffffb3ac + 0xDD4), 0);
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
            u8 *const transitionPacket = func_001d65d0(*(s32 *)(iGpffffb3ac + 0xDC0), *(s32 *)(base + 0x30), 0, *(s64 *)(callbackPacket + 0x58), 0x34100);
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
        u8 *const dependencyPacket = func_001d3b50(base);
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
        pkt = (u8 *)func_001f5f70((u32)base, 0xF, 0, 0, 3);
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
s32 func_001b5300(u8 *arg0)
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

        work = (u8 *)func_001f60c0();
        *(u16 *)(work + 0x4A) = 0xC;
        btlPacketEnqueue(work, 1);
        func_001f86d0();
        *(s32 *)(p + 0x14) = 1;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0 &&
        (*(s32 *)(p + 8) == *(u16 *)(p + 0x12))) {
        func_00212100(*(s32 *)(iGpffffb3ac + 0xDD4));
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
        func_00213990(*(s32 *)(iGpffffb3ac + 0xDD4));
        return 0;
    }
    if (func_002139d0(*(s32 *)(iGpffffb3ac + 0xDD4)) == 0) {
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
void func_001b54e0(void)
{
    u8 *p;
    u8 *work;

    p = *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30);
    if ((datCalcIsDead(*(s32 *)(p + 0xA64), 0) != 0) &&
        ((*(s32 *)(iGpffffb3ac + 0x10) & 0x20000000) == 0)) {
        work = (u8 *)func_001d6240((u32)*(s32 *)(iGpffffb3ac + 0xDBC), (u32)p, (u32)p, 1, 0);
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
    switch (func_001ef9a0()) {
    case 0x214:
        H_Fade_SetCustomColor(0, 0, 0);
        break;
    default:
        H_Fade_SetCustomColor(0xFF, 0xFF, 0xFF);
        break;
    }
}
// FUN_001B5620
s32 func_001b5620(u8 *arg0)
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
void func_001b5710(u8 *arg0)
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
    *(s32 *)func_00452560(*(s32 *)(D_0076449C + 0xDD0)) |= 1;
    *(s32 *)(arg0 + 0xC) = 0;
    goto done;
fallback:
    if ((*(u16 *)(D_0076449C + 0xCAC) & 1) == 0) {
        goto done;
    }
    if ((temp4 & 0x20000000) != 0) {
        goto done;
    }
    func_00213a10(*(s32 *)(D_0076449C + 0xDD4));
done:
    return;
}
// FUN_001B57F0
s32 func_001b57f0(u8 *arg0)
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
    if (func_0021db10(*(s32 *)(iGpffffb3ac + 0xDD0)) != 0) {
        goto check_status;
    }
    if ((*(u16 *)(iGpffffb3ac + 0xCAC) & 1) == 0) {
        goto set_status;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0) {
        goto set_status;
    }
    func_00213a10(*(s32 *)(iGpffffb3ac + 0xDD4));
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
    if (func_00213a50(*(s32 *)(iGpffffb3ac + 0xDD4)) != 0) {
        goto status_fallback;
    }
    return 0;
status_fallback:
    if (func_0021db40(*(s32 *)(iGpffffb3ac + 0xDD0)) != 0) {
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
void func_001b5970(void)
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
    func_002038c0(*(s32 *)(D_0076449C + 0xDD4));
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
            *(s8 *)(func_00105510(var_16_2) + 0x10) = 0;
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
s32 func_001b5d30(void) {
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
void func_001b5da0(void) {
}

// FUN_001B5DB0
s32 func_001b5db0(void)
{
    u8 *temp_3;

    if (*(s32 *)(func_00452560(*(s32 *)(iGpffffb3ac + 0xDD0)) + 4) != 0) {
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
void func_001b5e40(void)
{
    func_00193d30();
}






#pragma push
#pragma opt_loop_invariants on

#pragma pop
#pragma opt_propagation off
#pragma opt_propagation on









#pragma push
#pragma opt_propagation off
#pragma pop
#pragma push
#pragma opt_propagation off
#pragma pop
typedef struct { u8 r; u8 g; u8 b; u8 a; } BlendColor;
typedef struct ColorBlendWork {
    BlendColor target;
    BlendColor start;
    u32 frames;
    u32 frame;
} ColorBlendWork;
static inline u8 blendChannel(u8 start, u8 target, f32 t, f32 inv)
{
    f32 s = (1.0f / 255.0f) * (f32)start;
    f32 e = (1.0f / 255.0f) * (f32)target;
    f32 m = s * inv + e * t;
    return ((s32)(m * 255.0f + 0.5f)) & 0xFF;
}
/* measured: MATCH. The 1/255 scale is the pooled literal, not a global;
   with it written as a literal no pragmas are needed. The start colour is
   one struct copy (retail loads all four bytes, then stores them). */
// FUN_001BA0E0
s32 func_001ba0e0(ColorBlendWork *work)
{
    extern u8 *func_00457130(void);
    extern void func_00457140(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
    f32 t;
    f32 inv;
    u8 r;
    u8 g;
    u8 b;
    u8 a;

    if (work->frame == 0) {
        work->start = *(BlendColor *)func_00457130();
    }
    if (work->frame < work->frames) {
        t = (f32)work->frame / (f32)work->frames;
        inv = 1.0f - t;
        r = blendChannel(work->start.r, work->target.r, t, inv);
        g = blendChannel(work->start.g, work->target.g, t, inv);
        b = blendChannel(work->start.b, work->target.b, t, inv);
        a = blendChannel(work->start.a, work->target.a, t, inv);
        func_00457140(r, g, b, a);
    } else {
        func_00457140(work->target.r, work->target.g, work->target.b, work->target.a);
        return 1;
    }
    work->frame++;
    return 0;
}
// FUN_001BA530
u8 *func_001ba530(s32 arg0, s32 arg1) {
    u8 *o = btlPacketAlloc(0x608, 0x10);
    u8 *p;

    *(void (**)(void))(o + 0x6C) = (void (*)(void))func_001ba0e0;
    p = *(u8 **)(o + 0x78);
    *(s32 *)p = arg0;
    *(s32 *)(p + 8) = arg1;
    return o;
}

// FUN_001BA590
s32 func_001ba590(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Ba590Vec3;
    typedef struct {
        Ba590Vec3 right;
        u32 flags;
        Ba590Vec3 up;
        u32 pad1;
        Ba590Vec3 at;
        u32 pad2;
        Ba590Vec3 pos;
        u32 pad3;
    } Ba590Matrix;
    Ba590Matrix matrix;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f10;
    f32 temp_f11;
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f5;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;
    u32 temp_3;
    s32 temp_3_2;
    s32 temp_4;
    u8 *var_6;
    s32 var_5;
    u8 *var_2;

    if (*(s32 *)(arg0 + 0x24) == 0) {
        var_2 = (u8 *)iGpffffb3ac;
        temp_f3 = *(f32 *)(var_2 + 0x20C);
        temp_f2 = *(f32 *)(var_2 + 0x210);
        temp_f1 = *(f32 *)(var_2 + 0x214);
        temp_f0 = *(f32 *)(var_2 + 0x218);
        *(f32 *)(arg0 + 0x10) = temp_f3;
        *(f32 *)(arg0 + 0x14) = temp_f2;
        *(f32 *)(arg0 + 0x18) = temp_f1;
        *(f32 *)(arg0 + 0x1C) = temp_f0;
    }
    temp_3 = *(s32 *)(arg0 + 0x24);
    if (temp_3 >= *(u32 *)(arg0 + 0x20)) {
    temp_f4 = *(f32 *)(arg0 + 4);
    temp_f12 = *(f32 *)(arg0 + 0);
    temp_f11 = *(f32 *)(arg0 + 8);
    temp_f3 = *(f32 *)(arg0 + 0xC);
    temp_f0 =
        2.0f / ((temp_f12 * temp_f12) +
                (temp_f4 * temp_f4) +
                (temp_f11 * temp_f11) +
                (temp_f3 * temp_f3));
    temp_f2 = temp_f12 * temp_f0;
    temp_f1 = temp_f4 * temp_f0;
    temp_f0_2 = temp_f11 * temp_f0;
    temp_f10 = temp_f2 * temp_f3;
    temp_f9 = temp_f1 * temp_f3;
    temp_f8 = temp_f0_2 * temp_f3;
    temp_f7 = temp_f12 * temp_f2;
    temp_f6 = temp_f4 * temp_f1;
    temp_f5 = temp_f11 * temp_f0_2;
    temp_f4_2 = temp_f4 * temp_f0_2;
    temp_f3_2 = temp_f11 * temp_f2;
    temp_f2_2 = temp_f12 * temp_f1;
    matrix.right.x = 1.0f - (temp_f6 + temp_f5);
    matrix.right.y = temp_f2_2 + temp_f8;
    matrix.right.z = temp_f3_2 - temp_f9;
    matrix.up.x = temp_f2_2 - temp_f8;
    matrix.up.y = 1.0f - (temp_f5 + temp_f7);
    matrix.up.z = temp_f4_2 + temp_f10;
    matrix.at.x = temp_f3_2 + temp_f9;
    matrix.at.y = temp_f4_2 - temp_f10;
    matrix.at.z = 1.0f - (temp_f7 + temp_f6);
    matrix.pos.x = 0.0f;
    matrix.pos.y = 0.0f;
    matrix.pos.z = 0.0f;
    matrix.flags = 3;
    var_2 = SceneDraw_GetList4Matrix();
    var_6 = (u8 *)&matrix;
    var_5 = 8;
    do {
        temp_4 = *(s32 *)(var_6 + 0);
        temp_3_2 = *(s32 *)(var_6 + 4);
        var_6 += 8;
        var_5 -= 1;
        *(s32 *)(var_2 + 0) = temp_4;
        *(s32 *)(var_2 + 4) = temp_3_2;
        var_2 += 8;
    } while (var_5 > 0);
    return 1;
    }
    *(s32 *)(arg0 + 0x24) = temp_3 + 1;
    return 0;
}
// FUN_001BA710
u8 *func_001ba710(f32 *arg0, s32 arg1) {
    struct F4 {
        f32 x0;
        f32 x1;
        f32 x2;
        f32 x3;
    } value;
    u8 *o = btlPacketAlloc(0x60A, 0x28);
    f32 *p;

    *(void (**)(void))(o + 0x6C) = (void (*)(void))func_001ba590;
    p = *(f32 **)(o + 0x78);
    value = *(struct F4 *)arg0;
    *(struct F4 *)p = value;
    *(s32 *)(p + 8) = arg1;
    return o;
}

// FUN_001BA790
void func_001ba790(f32 *arg0, f32 *arg1, f32 *arg2, f32 fparg0)
{
    struct Ba790Local {
        f32 f50;
        f32 f54;
        f32 f58;
        f32 f5C;
        f32 f60;
        f32 f64;
        f32 f68;
        f32 f6C;
        f32 f70;
        s32 flag;
    } local;
    f32 var_f20;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;

    var_f20 = 1.0f - fparg0;
    temp_f5 = arg1[1] * var_f20;
    temp_f4 = arg1[2] * var_f20;
    temp_f3 = arg2[1] * fparg0;
    temp_f2 = arg2[2] * fparg0;
    arg0[0] = (arg1[0] * var_f20) + (arg2[0] * fparg0);
    arg0[1] = temp_f5 + temp_f3;
    arg0[2] = temp_f4 + temp_f2;
    func_003dcc70(arg1 + 3, arg2 + 3, &local.f50);
    if (fparg0 <= 0.0f) {
        temp_f3 = arg1[3];
        temp_f2 = arg1[4];
        temp_f1 = arg1[5];
        temp_f0 = arg1[6];
        arg0[3] = temp_f3;
        arg0[4] = temp_f2;
        arg0[5] = temp_f1;
        arg0[6] = temp_f0;
        goto done;
    }
    if (1.0f <= fparg0) {
        temp_f3 = arg2[3];
        temp_f2 = arg2[4];
        temp_f1 = arg2[5];
        temp_f0 = arg2[6];
        arg0[3] = temp_f3;
        arg0[4] = temp_f2;
        arg0[5] = temp_f1;
        arg0[6] = temp_f0;
        goto done;
    }
    if (local.flag == 0) {
        temp_f0 = var_f20 * local.f70;
        temp_f1 = temp_f0 * temp_f0;
        temp_f2 = fGpffff8104 * temp_f1 + fGpffff8054;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8058;
        temp_f2 = temp_f1 * temp_f2 + fGpffff805c;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8060;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8108;
        var_f20 = temp_f0 + func_001ba790_mul(temp_f1 * temp_f0, temp_f2);
        temp_f0 = fparg0 * local.f70;
        temp_f1 = temp_f0 * temp_f0;
        temp_f2 = fGpffff8104 * temp_f1 + fGpffff8054;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8058;
        temp_f2 = temp_f1 * temp_f2 + fGpffff805c;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8060;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8108;
        fparg0 = temp_f0 + func_001ba790_mul(temp_f1 * temp_f0, temp_f2);
    }
    arg0[3] = local.f50 * var_f20;
    arg0[4] = local.f54 * var_f20;
    arg0[5] = local.f58 * var_f20;
    arg0[3] = local.f60 * fparg0 + arg0[3];
    arg0[4] = local.f64 * fparg0 + arg0[4];
    arg0[5] = local.f68 * fparg0 + arg0[5];
    arg0[6] = local.f5C * var_f20 + local.f6C * fparg0;
done:
    ;
}



#pragma opt_propagation off
#pragma opt_propagation on



// FUN_001BC980
s32 func_001bc980(u8 *arg0)
{
    struct C980Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct C980Frame {
        f32 v30[4];
        u8 gap40[0x10];
        f32 v50[3];
        f32 v5C[4];
        f32 v6C[3];
        f32 v78[4];
        u8 tail[8];
    } frame;
    s32 temp_17;
    u8 *temp_3;
    u8 *temp_3_2;

    func_001bc660(1, *(BtlAction **)(arg0 + 0), 1);
    if (*(s32 *)(arg0 + 0x40) != 0) {
        func_001bd560(frame.v50, (f32 *)(D_0076449C + 0xC0));
    } else {
        func_001bd780(frame.v5C, arg0 + 4, arg0 + 0x10, D_0060A0E0);
        *(struct C980Vec3 *)frame.v50 =
            *(struct C980Vec3 *)(arg0 + 4);
    }
    func_001bd780(frame.v78, arg0 + 0x1C, arg0 + 0x28, D_0060A0E0);
    *(struct C980Vec3 *)frame.v6C =
        *(struct C980Vec3 *)(arg0 + 0x1C);
    temp_3 = D_0076449C;
    temp_17 = (s32)(temp_3 + 0x24);
    *(u16 *)(temp_3 + 0x24) = 1;
    *(s16 *)(temp_3 + 0x98) = 0;
    *(s16 *)(temp_3 + 0x9A) = 0;
    *(s16 *)(temp_3 + 0x9C) = 0;
    *(s32 *)(temp_3 + 0xA4) = 0;
    *(s32 *)(temp_3 + 0xA0) = 0;
    btlMainCurveAppendKeyframe((u16 *)temp_17, frame.v50, frame.v5C);
    func_001ba790(frame.v30, frame.v50, frame.v6C, fGpffff82f8);
    btlMainCurveAppendKeyframe((u16 *)temp_17, frame.v30, frame.v30 + 3);
    func_001ba790(frame.v30, frame.v50, frame.v6C, fGpffff80c8);
    btlMainCurveAppendKeyframe((u16 *)temp_17, frame.v30, frame.v30 + 3);
    btlMainCurveAppendKeyframe((u16 *)temp_17, frame.v6C, frame.v78);
    temp_3_2 = D_0076449C;
    *(f32 *)(temp_3_2 + 0xA8) =
        (60.0f * (2.0f * *(f32 *)(arg0 + 0x3C))) / 2.0f;
    *(s32 *)(temp_3_2 + 0xB8) = 0x3F000000;
    *(u16 *)(temp_3_2 + 0x24) &= 0xFFF5;
    *(u16 *)(temp_3_2 + 0x24) |= 4;
    return 1;
}
// FUN_001BCB50
u8 *func_001bcb50(s32 arg0, u8 *arg1, u8 *arg2, f32 fparg0,
                  u8 *arg3, u8 *arg4, f32 fparg1, f32 fparg2)
{
    struct Bcb50Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    u8 *temp_2;
    u8 *temp_4;

    temp_2 = (u8 *)(btlPacketAlloc(0x201, 0x44));
    *(s32 (**)(u8 *))(temp_2 + 0x6C) =
        (s32 (*)(u8 *))((s32 (**)(u8 *))(func_001bc980));
    temp_4 = *(u8 **)(temp_2 + 0x78);
    *(s32 *)(temp_4 + 0) = arg0;
    *(f32 *)(temp_4 + 0x3C) = fparg2;
    if ((arg1 != NULL) && (arg2 != NULL)) {
        *(struct Bcb50Vec3 *)(temp_4 + 4) =
            *(struct Bcb50Vec3 *)arg1;
        *(struct Bcb50Vec3 *)(temp_4 + 0x10) =
            *(struct Bcb50Vec3 *)arg2;
        *(s32 *)(temp_4 + 0x40) = 0;
    } else {
        *(s32 *)(temp_4 + 0x40) = 1;
    }
    *(struct Bcb50Vec3 *)(temp_4 + 0x1C) =
        *(struct Bcb50Vec3 *)arg3;
    *(struct Bcb50Vec3 *)(temp_4 + 0x28) =
        *(struct Bcb50Vec3 *)arg4;
    *(f32 *)(temp_4 + 0x34) = fparg0;
    *(f32 *)(temp_4 + 0x38) = fparg1;
    return temp_2;
}
// FUN_001BCC80
s32 func_001bcc80(u8 *arg0) {
    func_004b1680(*(s32 *)(arg0 + 0), *(s16 *)(arg0 + 4), *(s32 *)(arg0 + 8),
                  *(s32 *)(arg0 + 0xC));
    return 1;
}



// FUN_001BCCC0
u8 *func_001bccc0(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    u8 *temp_2;
    u8 *temp_3;

    temp_2 = (u8 *)(btlPacketAlloc(0x202, 0x10));
    *(s32 (**)(u8 *))(temp_2 + 0x6C) = (s32 (*)(u8 *))((s32 (**)(u8 *))(func_001bcc80));
    temp_3 = (u8 *)(*(u8 **)(temp_2 + 0x78));
    *(s32 *)(temp_3 + 0) = arg0;
    *(s16 *)(temp_3 + 4) = arg1;
    *(s32 *)(temp_3 + 8) = arg2;
    *(s32 *)(temp_3 + 0xC) = arg3;
    return temp_2;
}

/* Apply ordered visibility rules before testing the XZ camera segment.
 * Unit group IDs come from the 0019d210 constructors (0, 1, or 2).
 * measured b210 -O2: 1472/1472 bytes, all 22 relocations resolved.
 * Loop invariants retain the flag tests; separate target ordinals and
 * the u16 accessor preserve each search's index conversions. */
static inline u8 *cameraVisibilityTarget(u8 *action, u16 index)
{
    return *(u8 **)(action + index * 4 + 0x38);
}

struct RwV3d;

#pragma push
#pragma opt_loop_invariants on
// FUN_001BCD40
void func_001bcd40(u8 *action, u8 *first, f32 *second, f32 radius, u16 mode)
{
    extern void btlUnitSetFlags(BtlUnit *unit, u16 flags);
    extern void btlUnitClearFlags(BtlUnit *unit, u16 flags);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, struct RwV3d *out);
    extern f32 func_001ec3d0(u8 *first, u8 *second, u8 *point, u8 *out);
    struct {
        f32 first[2];
        f32 second[2];
        f32 point[2];
        f32 closest[2];
        f32 center[3];
    } geometry;
    u8 *current;
    u8 *unit;
    u16 targetGroups;
    f32 distance;

    if ((*(u32 *)(D_0076449C + 0x10) & 4) != 0)
        return;

    if (first != NULL && second != NULL) {
        geometry.first[0] = ((f32 *)first)[0];
        geometry.first[1] = ((f32 *)first)[2];
        geometry.second[0] = second[0];
        geometry.second[1] = second[2];
    } else {
        radius = 0.0f;
    }

    targetGroups = 0;
    if ((mode & 0x10) != 0) {
        s32 index;
        index = 0;
        while ((index & 0xFFFF) < *(u16 *)(action + 0x6A)) {
            targetGroups |= (u16)(1u << *(u8 *)(*(u8 **)(
                cameraVisibilityTarget(action, index) + 0x30) + 0xA2));
            index = (index + 1) & 0xFFFF;
        }
    }

    for (current = *(u8 **)(D_0076449C + 0x174); current != NULL;
         current = *(u8 **)(current + 0x450)) {
        if ((*(u16 *)(current + 0x1A) & 1) == 0)
            continue;
        unit = *(u8 **)(current + 0x30);
        if ((*(u32 *)(unit + 0x9C) & 8) == 0)
            continue;

        if ((mode & 0x20) != 0 && current != action) {
            btlUnitClearFlags((BtlUnit *)unit, 2);
            btlUnitSetFlags((BtlUnit *)unit, 4);
            if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
            continue;
        }
        if ((mode & 0x100) != 0) {
            btlUnitClearFlags((BtlUnit *)unit, 2);
            if ((mode & 0x400) != 0) btlUnitSetFlags((BtlUnit *)unit, 4);
            if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
            continue;
        }
        if (current == *(u8 **)(D_0076449C + 0x170) && (mode & 4) != 0) {
            btlUnitClearFlags((BtlUnit *)unit, 2);
            btlUnitSetFlags((BtlUnit *)unit, 4);
            if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
            continue;
        }
        if (action != NULL) {
            if (current == action && (mode & 1) != 0) {
                btlUnitClearFlags((BtlUnit *)unit, 2);
                btlUnitSetFlags((BtlUnit *)unit, 4);
                if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
                continue;
            }
            if ((targetGroups & (1u << *(u8 *)(unit + 0xA2))) != 0) {
                btlUnitClearFlags((BtlUnit *)unit, 2);
                btlUnitSetFlags((BtlUnit *)unit, 4);
                if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
                continue;
            }
            if ((mode & 0x800) != 0 && current == (u8 *)(uintptr_t)func_001b1560()) {
                btlUnitClearFlags((BtlUnit *)unit, 2);
                btlUnitSetFlags((BtlUnit *)unit, 4);
                if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
                continue;
            }
            if ((mode & 2) != 0) {
                s32 index;
                index = 0;
                while ((index & 0xFFFF) < *(u16 *)(action + 0x6A)) {
                    if (current == cameraVisibilityTarget(action, index)) {
                        btlUnitClearFlags((BtlUnit *)unit, 2);
                        btlUnitSetFlags((BtlUnit *)unit, 4);
                        if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
                        break;
                    }
                    index = (index + 1) & 0xFFFF;
                }
                if ((index & 0xFFFF) != *(u16 *)(action + 0x6A) ||
                    current == *(u8 **)(action + 0x88))
                    continue;
            }
            if (*(u8 *)(unit + 0xA2) == *(u8 *)(*(u8 **)(action + 0x30) + 0xA2) &&
                (mode & 8) != 0) {
                btlUnitClearFlags((BtlUnit *)unit, 2);
                if ((mode & 0x40) == 0) *(u8 *)(unit + 0x37) = 0xFF;
                continue;
            }
        }

        if (first != NULL && second != NULL) {
            btlUnitGetSphereWorldCenter((BtlUnit *)unit, (struct RwV3d *)geometry.center);
            geometry.point[0] = geometry.center[0];
            geometry.point[1] = geometry.center[2];
            distance = func_001ec3d0((u8 *)geometry.first, (u8 *)geometry.second,
                                     (u8 *)geometry.point, (u8 *)geometry.closest);
            distance = 0.0f + distance - *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
            if (((geometry.first[0] < geometry.closest[0] ||
                  !(geometry.second[0] <= geometry.closest[0])) &&
                 (!(geometry.first[0] <= geometry.closest[0]) ||
                  geometry.second[0] < geometry.closest[0])) ||
                ((geometry.first[1] < geometry.closest[1] ||
                  !(geometry.second[1] <= geometry.closest[1])) &&
                 (!(geometry.first[1] <= geometry.closest[1]) ||
                  geometry.second[1] < geometry.closest[1])))
                continue;
        } else {
            distance = 0.0f;
        }
        if (distance <= radius) {
            btlUnitSetFlags((BtlUnit *)unit, 2);
            if ((mode & 0x80) == 0) *(u8 *)(unit + 0x37) = 0;
            if ((mode & 0x200) != 0) btlUnitClearFlags((BtlUnit *)unit, 4);
        }
    }
}
#pragma pop
/* measured: disabling propagation preserves retail's independent outer-index
   materialisation after the preheader branch. */
#pragma opt_propagation off
/* measured: disabling common-subexpression folding preserves retail's second
   masked loop-counter use. */
#pragma opt_common_subs off
// FUN_001BD300
void func_001bd300(void)
{
    s32 var_16;
    s32 index;
    u8 *var_17;

    var_16 = 0;
    goto outer_check;
outer_body:
    index = var_16 & 0xFFFF;
    var_17 = *(u8 **)(iGpffffb3ac + (index * 8) + 0x178);
    goto inner_check;
inner_body:
    btlUnitClearFlags(var_17, 0xF);
    var_17 = *(u8 **)(var_17 + 0xA6C);
inner_check:
    if (var_17 != NULL) goto inner_body;
    var_16 = (var_16 + 1) & 0xFFFF;
outer_check:
    if ((var_16 & 0xFFFF) < 2) goto outer_body;
}
/* measured: closes opt_common_subs for the following translation-unit code. */
#pragma opt_common_subs on
/* measured: closes opt_propagation for the following translation-unit code. */
#pragma opt_propagation on
/* measured: opt_common_subs off preserves the retail per-use masked index. */
#pragma opt_common_subs off
// FUN_001BD390
void func_001bd390(void)
{
    extern void btlUnitSetFlags();
    extern s32 func_00243d80(u8 *arg0);
    extern f32 RwV3dLength(f32 *arg0);
    u8 *current;
    s32 counter;
    u8 *base;
    s32 index;
    s32 ability;
    f32 values[3];
    f32 delta[3];

    base = *(u8 **)(((u8 *)func_00457120()) + 4) + 0x10;
    counter = 0;
    goto outer_check;
outer_body:
    index = counter & 0xFFFF;
    current = *(u8 **)(iGpffffb3ac + (index * 8) + 0x178);
    goto inner_check;
inner_body:
    ability = *(s32 *)(current + 0xA64);
    if ((ability != 0 && func_00243d80((u8 *)ability) != 0) ||
        (*(s32 *)(current + 0x9C) & 8) != 0) {
        btlUnitGetSphereWorldCenter(current, values);
        delta[0] = *(f32 *)(base + 0x30) - values[0];
        delta[1] = *(f32 *)(base + 0x34) - values[1];
        delta[2] = *(f32 *)(base + 0x38) - values[2];
        if (RwV3dLength(delta) <=
            0.0f + 200.0f +
            *(f32 *)(current + 0x90) * *(f32 *)(current + 0x2C)) {
            btlUnitSetFlags(current, 1);
        } else {
            btlUnitClearFlags(current, 1);
        }
    }
    current = *(u8 **)(current + 0xA6C);
inner_check:
    if (current != NULL) goto inner_body;
    counter = (counter + 1) & 0xFFFF;
outer_check:
    if ((counter & 0xFFFF) < 2) goto outer_body;
}
/* measured: restore common-subexpression optimization after func_001bd390. */
#pragma opt_common_subs on
// FUN_001BD4F0
void func_001bd4f0(u8 *arg0) {
    btlUnitSetFlags(arg0, 0xA);
    btlUnitClearFlags(arg0, 4);
}



// FUN_001BD530
void func_001bd530(u32 arg0) {
    btlUnitClearFlags((u8 *)arg0, 0xA);
}




#pragma opt_propagation off
#pragma opt_propagation on
/* Camera providers use a four-float P4 quaternion holder and the RenderWare
 * vector/quaternion ABI. The backend vector transform reads exactly sixteen
 * quaternion bytes and returns its original output pointer. */
typedef struct P4Vec4_001EC2B0 { f32 x, y, z, w; } P4Vec4_001EC2B0;
typedef struct P4Vec4Holder_001EC2B0 { P4Vec4_001EC2B0 quat; } P4Vec4Holder_001EC2B0;
extern f32 func_001ec2b0(P4Vec4Holder_001EC2B0 *, P4Vec4Holder_001EC2B0 *);
extern RwV3d *RtQuatTransformVectors(RwV3d *, const RwV3d *, s32, const RtQuat *);
extern void btlMainCurveSetPoses(u16 *, f32 *, f32 *, u16);

// FUN_001BE900
void func_001be900(u8 *arg0)
{
    struct {
        f32 value;
        u8 pad[0xC];
    } local;
    u8 *temp16;
    u8 *temp4;

    temp4 = *(u8 **)(arg0 + 0xE0);
    if ((temp4 != NULL) && ((*(u16 *)(temp4 + 0x1A) & 1) != 0)) {
        temp16 = *(u8 **)(temp4 + 0x30);
        btlUnitGetSphereWorldCenter(temp16, &local.value);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, &local.value, 0.5f * (*(f32 *)(temp16 + 0x90) * *(f32 *)(temp16 + 0x2C)),
                      0xC1);
    }
}
/* Exact P4 general action camera, ported from P3 FES btlCameraFrameAction
   (04d95e2) with the P4 rejection path, literals and interpolation state.
   2564/2576 bytes; all 73 relocations and the duration literal resolved.
   See docs/probe_archive/Action_camera_frame_action_20260920.md. */
// FUN_001BE990
s32 func_001be990(u8 *camera, s32 closeView, s32 nearScale, s32 farScale)
{

    typedef struct RwMatrixTag { RwV3d right; u32 flags; RwV3d up; u32 pad1; RwV3d at; u32 pad2; RwV3d pos; u32 pad3; } RwMatrix;
    typedef enum RwOpCombineType { rwCOMBINEREPLACE, rwCOMBINEPRECONCAT, rwCOMBINEPOSTCONCAT, rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7FFFFFFF } RwOpCombineType;
    typedef P4Vec4Holder_001EC2B0 ActionQuat;
    typedef struct { RwV3d pos; ActionQuat rot; } ActionFrame;
    typedef struct { ActionQuat first, second; f32 scalar; s32 flag; } ActionBlend;
    struct BtlTarget;
    extern u16 func_001eb440(struct BtlTarget *);
    extern s32 func_001f0ff0(u32);
    extern void func_001ec1c0(u8 *,u8 *,u8 *);
    extern f32 func_00196040(u32,u32,RwV3d *,f32 *,f32 *,u32);
    extern f32 RwV3dNormalize(RwV3d *, const RwV3d *);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *, RwV3d *);
    extern RwMatrix *RwMatrixRotate(RwMatrix *,const RwV3d *,f32,RwOpCombineType);
    extern RwV3d *func_003e4320(RwV3d *,const RwV3d *,const RwMatrix *);
    extern f32 tanf(f32);
    extern void btlCameraSetDuration(u8 *,f32);
    extern f32 fGpffff8190,fGpffff8194,fGpffff8170,fGpffff8110,fGpffff8168,fGpffff8130,fGpffff8128;
    extern u8 D_0060A0D0[],D_0060A0F0[],D_0060A100[];
    f32 maxY;
    RwV3d scaled;
    RwV3d forward;
    RwV3d sphereCenter;
    RwV3d rotated;
    RwV3d center;
    RwV3d candidate;
    RwV3d targetCenter;
    RwMatrix rotation;
    ActionQuat blendedRot;
    ActionQuat quaternion;
    ActionBlend blend;
    ActionFrame frames[2];
    f32 distance;
    f32 fovDistance;
    f32 nearDistance;
    f32 radius;
    f32 half;
    f32 angle;
    f32 nearAngle;
    f32 ratio;
    f32 firstWeight;
    f32 x;
    f32 xSquared;
    f32 r;
    f32 r2;
    u8* unit;
    s32 targetAction;
    unit = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
    if (closeView == 0)
    {
        func_001bd560((f32*)&frames[0], (f32*)((u8*)camera + 0x9c));
        distance = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
        btlUnitGetSphereWorldCenter((BtlUnit *)unit, &sphereCenter);
        RtQuatTransformVectors(&forward, (const RwV3d *)(&D_0060A0F0), 1, (const RtQuat *)(unit + 0x1C));
        half = 0.5f * distance;
        scaled.x = forward.x * half;
        scaled.y = forward.y * half;
        scaled.z = forward.z * half;
        candidate.x = sphereCenter.x + scaled.x;
        candidate.y = sphereCenter.y + scaled.y;
        candidate.z = sphereCenter.z + scaled.z;
        candidate.y += 0.25f * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
        func_00196040(3, 0, 0, &maxY, 0, 1);
        scaled = frames[0].pos;
        if (maxY < scaled.y)
        {
            scaled.y = maxY;
        }
        else
        {
            x = *(f32 *)(unit + 0x2C);
            half = *(f32 *)(unit + 0x8C) * x;
            if (!(half <= scaled.y))
            {
                scaled.y = half;
            }
        }
        func_001bd780(&frames[1].rot, &scaled, &candidate, &D_0060A0E0);
        angle = func_001ec2b0(&frames[0].rot, &frames[1].rot);
        x = (f32)nearScale;
        nearDistance = fGpffff8190 * x;
        if (!(angle <= nearDistance))
        {
            if (!(angle <= fGpffff8190 * (f32)farScale)) return 0;
            radius = nearDistance / angle;
            func_003dcc70((f32*)&frames[0].rot, (f32*)&frames[1].rot,
                         (f32*)&blend);
            if (radius <= 0.0f)
            {
                blendedRot = frames[0].rot;
            }
            else if (1.0f <= radius)
            {
                blendedRot = frames[1].rot;
            }
            else
            {
                firstWeight = 1.0f - radius;
                if (blend.flag == 0)
                {
                    x = firstWeight * blend.scalar;
                    xSquared = x * x;
                    r = fGpffff8054 + fGpffff8194 * xSquared;
                    r = fGpffff8058 + xSquared * r;
                    r = fGpffff805c + xSquared * r;
                    r = fGpffff8060 + xSquared * r;
                    r2 = fGpffff8108 + xSquared * r;
                    r = xSquared * x;
                    firstWeight = r * r2 + x;
                    x = radius * blend.scalar;
                    xSquared = x * x;
                    r = fGpffff8054 + fGpffff8194 * xSquared;
                    r = fGpffff8058 + xSquared * r;
                    r = fGpffff805c + xSquared * r;
                    r = fGpffff8060 + xSquared * r;
                    r2 = fGpffff8108 + xSquared * r;
                    r = xSquared * x;
                    radius = r * r2 + x;
                }
                blendedRot.quat.x = blend.first.quat.x * firstWeight;
                blendedRot.quat.y = blend.first.quat.y * firstWeight;
                blendedRot.quat.z = blend.first.quat.z * firstWeight;
                blendedRot.quat.x = 0.0f + blendedRot.quat.x +
                                    blend.second.quat.x * radius;
                blendedRot.quat.y = 0.0f + blendedRot.quat.y +
                                    blend.second.quat.y * radius;
                blendedRot.quat.z = 0.0f + blendedRot.quat.z +
                                    blend.second.quat.z * radius;
                blendedRot.quat.w = blend.first.quat.w * firstWeight +
                                  blend.second.quat.w * radius;
            }
            RtQuatTransformVectors(&forward, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&blendedRot));
            scaled.x = candidate.x + forward.x;
            scaled.y = candidate.y + forward.y;
            scaled.z = candidate.z + forward.z;
            func_001bd780(&frames[1].rot, &scaled, &candidate,
                         &D_0060A0E0);

        }
        forward.x = frames[0].pos.x - candidate.x;
        forward.y = frames[0].pos.y - candidate.y;
        forward.z = frames[0].pos.z - candidate.z;
        radius = RwV3dNormalize(&forward, &forward);
        radius = radius * fGpffff8170;
        half = 0.5f * *(f32 *)(camera + 0xB8);
        fovDistance = 1.5f * distance / tanf(half);
        if (!(fovDistance <= radius))
        {
            radius = fovDistance;
        }
        if (radius < (f32)0x226)
        {
            radius = (f32)0x226;
        }
        RtQuatTransformVectors(&forward, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&frames[1].rot));
        scaled.x = forward.x * radius;
        scaled.y = forward.y * radius;
        scaled.z = forward.z * radius;
        frames[1].pos.x = candidate.x + scaled.x;
        frames[1].pos.y = candidate.y + scaled.y;
        frames[1].pos.z = candidate.z + scaled.z;
        if (frames[0].pos.y < 25.0f)
        {
            frames[0].pos.y = 25.0f;
        }
        if (frames[1].pos.y < 25.0f)
        {
            frames[1].pos.y = 25.0f;
        }
        angle = func_001ec2b0(&frames[0].rot, &frames[1].rot);
        radius = 2.15f;
        if (!(angle <= 0.0f)) {
            ratio = nearDistance / angle;
            if (!(ratio <= 1.0f)) radius = ratio * fGpffff8168;
            else radius = fGpffff8168;
            if (!(radius <= 2.15f)) radius = 2.15f;
        }
        btlMainCurveSetPoses((u16*)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
        btlCameraSetDuration(camera, radius);
        goto action_done;
    }

    targetAction = func_001f0ff0((u32)*(u8 **)(camera + 0xE0));
    btlUnitGetSphereWorldCenter((BtlUnit *)unit, &candidate);
    candidate.y = 0.0f + candidate.y + fGpffff8128 * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
    if (*(u16 *)(*(u8 **)(camera + 0xE0) + 0x6A) == 1 &&
        unit == *(u8 **)(*(u8 **)(*(u8 **)(camera + 0xE0) + 0x38) + 0x30))
    {
        RtQuatTransformVectors(&rotated, (const RwV3d *)(&D_0060A0F0), 1, (const RtQuat *)(unit + 0x1C));
    }
    else
    {
        if (targetAction != 0)
        {
            btlUnitGetSphereWorldCenter(
                (BtlUnit *)*(u8 **)(*(u8 **)(*(u8 **)(camera + 0xE0) + 0x38) + 0x30),
                &targetCenter);
        }
        else
        {
            func_00196040((s32)func_001eb440((struct BtlTarget *)(*(u8 **)(camera + 0xE0) + 0x38)) & 0xffff,
                         1, &targetCenter, 0, 0, 1);
        }
        func_001ec1c0((u8 *)&quaternion, (u8 *)&candidate, (u8 *)&targetCenter);
        RtQuatTransformVectors(&rotated, (const RwV3d *)(&D_0060A0F0), 1, (const RtQuat *)(&quaternion));
    }
    nearAngle = 4.0f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C));
    half = 2.5f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C));
    switch (datCalcRandomBelow(3))
    {
    case 0:
        radius = 30.0f;
        break;
    case 1:
        radius = -30.0f;
        break;
    default:
        radius = 0.0f;
        break;
    }
    switch (datCalcRandomBelow(3))
    {
    case 0:
        angle = 15.0f;
        break;
    case 1:
        angle = -15.0f;
        break;
    default:
        angle = 0.0f;
        break;
    }
    RwMatrixRotate(&rotation, (const RwV3d *)D_0060A0D0, angle, 0);
    RwMatrixRotate(&rotation, (const RwV3d *)D_0060A0E0, radius, 2);
    func_003e4320(&forward, &rotated, &rotation);
    distance = nearAngle / tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    forward.x *= distance;
    forward.y *= distance;
    forward.z *= distance;
    center.x = candidate.x;
    center.y = candidate.y;
    center.z = candidate.z;
    frames[0].pos.x = center.x + forward.x;
    frames[0].pos.y = center.y + forward.y;
    frames[0].pos.z = center.z + forward.z;
    func_001bd780(&frames[0].rot, &frames[0].pos, &center,
                 &D_0060A0E0);
    distance = half / tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    forward.x = rotated.x * distance;
    forward.y = rotated.y * distance;
    forward.z = rotated.z * distance;
    center.x = candidate.x;
    center.y = candidate.y;
    center.z = candidate.z;
    frames[1].pos.x = center.x + forward.x;
    frames[1].pos.y = center.y + forward.y;
    frames[1].pos.z = center.z + forward.z;
    func_001bd780(&frames[1].rot, &frames[1].pos, &center,
                 &D_0060A0E0);
    func_001b73f0(unit);
    func_001bcd40(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 1);
    if (frames[0].pos.y < 25.0f)
    {
        frames[0].pos.y = 25.0f;
    }
    if (frames[1].pos.y < 25.0f)
    {
        frames[1].pos.y = 25.0f;
    }
    btlMainCurveSetPoses((u16*)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    btlCameraSetDuration(camera, 1.75f);
action_done:
    return 1;
}
// FUN_001BF3A0
void func_001bf3a0(u8 *arg0)
{
    u8 *var_3;
    u16 temp_16;
    u8 *temp_17;

    switch (*(u16 *)(D_0076449C + 0x108)) {
    case 0x22:
        var_3 = 0;
        goto first_done;
    default:
        goto first_random;
    }
first_random:
    if (datCalcRandomBelow(0x64) <= 0x19) goto first_random_zero;
    var_3 = (u8 *)func_001be990(arg0, 0, 0x23, 0x3C);
    goto first_done;
first_random_zero:
    var_3 = 0;
first_done:
    if (var_3 != NULL) goto done;
    if (datCalcRandomBelow(0x64) <= 0x19) goto second_random;
    temp_17 = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    temp_16 = *(u16 *)(temp_17 + 0xA4);
    func_001b73f0(temp_17);
    func_001bdd80(arg0,
                  func_001bf3a0_add((effMiscRand(0) & 1) * 0xF4,
                                    (u8 *)((s32)D_005FB400 +
                                           ((temp_16 & 0xFFFF) * 0x1E8))),
                  2);
    func_001b73f0(temp_17);
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 1);
    *(s32 *)(arg0 + 0x144) = 1;
    goto finish;
second_random:
    func_001be990(arg0, 1, 0x23, 0x3C);
    *(s32 *)(arg0 + 0x144) = 0;
    goto finish;
done:
    *(s32 *)(arg0 + 0x144) = 0;
finish:
    ;
}
// FUN_001BF530
void func_001bf530(u8 *arg0)
{
    struct {
        f32 value;
        u8 pad[0xC];
    } local;
    u8 *temp16;
    u8 *temp4;

    if (*(s32 *)(arg0 + 0x144) == 0) goto process;
    func_001bdeb0(arg0);
    goto done;
process:
    temp4 = *(u8 **)(arg0 + 0xE0);
    if ((temp4 != NULL) && ((*(u16 *)(temp4 + 0x1A) & 1) != 0)) {
        temp16 = *(u8 **)(temp4 + 0x30);
        btlUnitGetSphereWorldCenter(temp16, &local.value);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, &local.value, 0.25f * (*(f32 *)(temp16 + 0x90) * *(f32 *)(temp16 + 0x2C)),
                      0xC1);
    }
done:
    ;
}
/* Adapted from P3 FES btlCameraFrameActionPair at 04d95e2.
   P4 unit fields, lens constants and radius choices are verified against retail.
   See docs/probe_archive/Action_camera_pair_duel_20260920.md. */
// FUN_001BF5E0
void func_001bf5e0(u8 *camera)
{

    typedef RwV3d PairVec3;
    typedef P4Vec4Holder_001EC2B0 PairQuat;
    typedef struct { PairVec3 pos; PairQuat rot; } PairFrame;
    typedef struct { PairQuat first, second; f32 scalar; s32 flag; } PairBlend;
    extern f32 RwV3dLength(f32 *);
    extern f32 func_003e41e0(f32 *, f32 *);
    extern f32 RwV3dNormalize(PairVec3 *, const PairVec3 *);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *, PairVec3 *);
    extern void btlCameraSetDuration(u8 *, f32);
    extern f32 fGpffff803c, fGpffff80fc, fGpffff8158;
    extern u8 D_0060A100[];
    PairVec3 secondPos;
    PairVec3 dir;
    PairVec3 firstPos;
    PairVec3 center1;
    PairVec3 center2;
    PairQuat blended;
    PairBlend blend;
    PairFrame frames[2];
    f32 hs[4];
    u8* action;
    u8* unit;
    u8* unit2;
    f32 len2;
    f32 ratio;
    f32 w1;
    f32 x;
    f32 x2;
    f32 r;
    f32 r2;
    f32 dot;
    f32 angle;

    action = *(u8 **)(camera + 0xE0);
    unit = *(u8 **)(action + 0x30);
    unit2 = *(u8**)(*(int*)((u8*)action + 0x38) + 0x30);
    func_001bd560((f32*)&frames[0], (f32*)((u8*)camera + 0x9c));
    btlUnitGetSphereWorldCenter((BtlUnit *)unit, &center1);
    btlUnitGetSphereWorldCenter((BtlUnit *)unit2, &center2);
    center1.y = 0.0f + center1.y + fGpffff803c * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
    if (center1.y < 100.0f)
    {
        center1.y = 100.0f;
    }
    dir.x = frames[0].pos.x - center1.x;
    dir.y = frames[0].pos.y - center1.y;
    dir.z = frames[0].pos.z - center1.z;
    len2 = RwV3dLength((f32 *)&dir);
    len2 = len2 * fGpffff80fc;
    hs[2] = dir.x;
    hs[3] = dir.z;
    func_003e41e0(hs + 2, hs + 2);
    center2.y = center1.y;
    dir.x = center2.x - center1.x;
    dir.y = center2.y - center1.y;
    dir.z = center2.z - center1.z;
    RwV3dNormalize(&dir, &dir);
    hs[0] = dir.x;
    hs[1] = dir.z;
    dot = dir.x * hs[2] + dir.z * hs[3];
    if (dot < 0.0f)
    {
        dir.x = -dir.x;
        dir.y = -dir.y;
        dir.z = -dir.z;
    }
    secondPos.x = dir.x * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C));
    secondPos.y = dir.y * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C));
    secondPos.z = dir.z * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C));
    firstPos.x = center1.x + secondPos.x;
    firstPos.y = center1.y + secondPos.y;
    firstPos.z = center1.z + secondPos.z;
    dir.x = dir.x * (5.0f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C)));
    dir.y = dir.y * (5.0f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C)));
    dir.z = dir.z * (5.0f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C)));
    secondPos.x = center1.x + dir.x;
    secondPos.y = center1.y + dir.y;
    secondPos.z = center1.z + dir.z;
    secondPos.y = 0.0f + center2.y + 0.5f * (*(f32 *)(unit2 + 0x8C) * *(f32 *)(unit2 + 0x2C));
    dir.x = secondPos.x - center1.x;
    dir.y = secondPos.y - center1.y;
    dir.z = secondPos.z - center1.z;
    RwV3dNormalize(&dir, &dir);
    func_001bd780(&frames[1].rot, &secondPos, &firstPos, &D_0060A0E0);
    angle = func_001ec2b0(&frames[0].rot, &frames[1].rot);
    if (angle > fGpffff8158)
    {
        ratio = fGpffff8158 / angle;
        func_003dcc70((f32*)&frames[0].rot, (f32*)&frames[1].rot, (f32*)&blend);
        if (ratio <= 0.0f)
        {
            blended = frames[0].rot;
        }
        else if (1.0f <= ratio)
        {
            blended = frames[1].rot;
        }
        else
        {
            w1 = 1.0f - ratio;
            if (blend.flag == 0)
            {
                x = w1 * blend.scalar;
                x2 = x * x;
                r = fGpffff8054 + fGpffff8104 * x2;
                r = fGpffff8058 + x2 * r;
                r = fGpffff805c + x2 * r;
                r = fGpffff8060 + x2 * r;
                r2 = fGpffff8108 + x2 * r;
                r = x2 * x;
                w1 = x + r * r2;
                x = ratio * blend.scalar;
                x2 = x * x;
                r = fGpffff8054 + fGpffff8104 * x2;
                r = fGpffff8058 + x2 * r;
                r = fGpffff805c + x2 * r;
                r = fGpffff8060 + x2 * r;
                r2 = fGpffff8108 + x2 * r;
                r = x2 * x;
                ratio = x + r * r2;
            }
            blended.quat.x = blend.first.quat.x * w1;
            blended.quat.y = blend.first.quat.y * w1;
            blended.quat.z = blend.first.quat.z * w1;
            blended.quat.x = 0.0f + blended.quat.x +
                             blend.second.quat.x * ratio;
            blended.quat.y = 0.0f + blended.quat.y +
                             blend.second.quat.y * ratio;
            blended.quat.z = 0.0f + blended.quat.z +
                             blend.second.quat.z * ratio;
            blended.quat.w = blend.first.quat.w * w1 +
                           blend.second.quat.w * ratio;
        }
        RtQuatTransformVectors(&dir, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&blended));
        secondPos.x = firstPos.x + dir.x;
        secondPos.y = firstPos.y + dir.y;
        secondPos.z = firstPos.z + dir.z;
        func_001bd780(&frames[1].rot, &secondPos, &firstPos, &D_0060A0E0);
    }
    if (len2 < 600.0f)
    {
        len2 = 600.0f;
    }
    dir.x = dir.x * len2;
    dir.y = dir.y * len2;
    dir.z = dir.z * len2;
    frames[1].pos.x = firstPos.x + dir.x;
    frames[1].pos.y = firstPos.y + dir.y;
    frames[1].pos.z = firstPos.z + dir.z;
    btlMainCurveSetPoses((u16*)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    btlCameraSetDuration(camera, 1.0f);
}
// FUN_001BFB70
void func_001bfb70(u8 *arg0)
{
    struct {
        f32 value;
        u8 pad[0xC];
    } local;
    u8 *temp16;
    u8 *temp4;

    temp4 = *(u8 **)(arg0 + 0xE0);
    if ((temp4 != NULL) && ((*(u16 *)(temp4 + 0x1A) & 1) != 0)) {
        temp16 = *(u8 **)(temp4 + 0x30);
        btlUnitGetSphereWorldCenter(temp16, &local.value);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, &local.value, 0.25f * (*(f32 *)(temp16 + 0x90) * *(f32 *)(temp16 + 0x2C)),
                      0xC3);
    }
}
/* Adapted from P3 FES btlCameraFrameActionDuel at 04d95e2.
   P4 unit fields, lens constants and radius choices are verified against retail.
   See docs/probe_archive/Action_camera_pair_duel_20260920.md. */
// FUN_001BFC00
void btlAct_SKILL_RECITE_E(u8 *camera)
{

    typedef RwV3d DuelVec3;
    typedef P4Vec4Holder_001EC2B0 DuelQuat;
    typedef struct { DuelVec3 pos; DuelQuat rot; } DuelFrame;
    typedef struct { DuelQuat first, second; f32 scalar; s32 flag; } DuelBlend;
    extern f32 RwV2dLength(f32 *);
    extern f32 func_003e41e0(f32 *, f32 *);
    extern f32 RwV3dNormalize(DuelVec3 *, const DuelVec3 *);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *, DuelVec3 *);
    extern void *func_003dc740(void *, const void *, f32, s32);
    extern u32 func_001bc3a0(f32 *, f32 *);
    extern void btlCameraSetDuration(u8 *, f32);
    extern f32 tanf(f32);
    extern f32 fabsf(f32);
    extern f32 fGpffff8118, fGpffff815c, fGpffff804c, fGpffff8160;
    extern f32 fGpffff8110, fGpffff8180;
    extern u8 D_0060A100[];
    f32 horiz[2];
    DuelVec3 candidate;
    DuelVec3 eyeAdj;
    DuelVec3 direction;
    DuelVec3 sideDirection;
    DuelVec3 center;
    DuelVec3 selectedCenter;
    DuelVec3 unitPoint;
    DuelVec3 targetCenter;
    DuelQuat blended;
    DuelQuat rots[2];
    DuelBlend blend;
    DuelFrame frames[2];
    u8* unit;
    u8* target;
    f32 radius;
    f32 sideOffset;
    f32 height;
    f32 angle;
    f32 ratio;
    f32 w1;
    f32 x;
    f32 x2;
    f32 r;
    f32 r2;
    f32 dist;
    f32 selectedRadius;
    f32 dot;
    f32 sideLength;
    unit = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
    target = *(u8 **)(*(u8 **)(*(u8 **)(camera + 0xE0) + 0x38) + 0x30);
    func_001bd560((f32*)&frames[0], (f32*)((u8*)camera + 0x9c));
    unitPoint.x = *(f32 *)(unit + 0xDC);
    unitPoint.y = *(f32 *)(unit + 0x84) * *(f32 *)(unit + 0x2C);
    unitPoint.z = *(f32 *)(unit + 0xE4);
    btlUnitGetSphereWorldCenter((BtlUnit *)target, &targetCenter);
    {
        f32 targetHeight;
    height = *(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C);
    height = unitPoint.y + fGpffff8118 * height;
    ratio = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
    targetHeight = targetCenter.y + fGpffff8118 * ratio;
    height = height + targetHeight;
    radius = *(f32*)((u8*)unit + 0xe8);
    radius += *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
    radius += *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
    targetCenter.y = 0.0f;
    unitPoint.y = 0.0f;
    direction.x = *(f32 *)(unit + 0xDC) - targetCenter.x;
    direction.y = *(f32*)((u8*)unit + 0xe0) - unitPoint.y;
    direction.z = *(f32 *)(unit + 0xE4) - targetCenter.z;
    RwV3dNormalize(&direction, &direction);
    targetHeight = 0.25f * radius;
    center.x = direction.x * targetHeight;
    center.y = direction.y * targetHeight;
    center.z = direction.z * targetHeight;
    center.x = targetCenter.x + center.x;
    center.y = targetCenter.y + center.y;
    center.z = targetCenter.z + center.z;
    {
        f32 halfHeight;
    halfHeight = 0.5f * height;
    center.y = halfHeight;
    eyeAdj = frames[0].pos;
    eyeAdj.y = height;
    *(f32*)((u8 *)camera + 0x10c) =
        0.5f * *(f32*)((uintptr_t)unit + 0xe8);
    *(DuelVec3*)((u8*)camera + 0x100) = center;
    func_001bd780(&frames[1].rot, &eyeAdj, &center, &D_0060A0E0);
    height = radius;
    height += *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
    height += *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
    angle = func_001ec2b0(&frames[0].rot, &frames[1].rot);
    if (angle > fGpffff815c)
    {
        ratio = fGpffff815c / angle;
        func_003dcc70((f32*)&frames[0].rot, (f32*)&frames[1].rot, (f32*)&blend);
        if (ratio <= 0.0f)
        {
            blended = frames[0].rot;
        }
        else if (1.0f <= ratio)
        {
            blended = frames[1].rot;
        }
        else
        {
            w1 = 1.0f - ratio;
            if (blend.flag == 0)
            {
                x = w1 * blend.scalar;
                x2 = x * x;
                r = fGpffff8054 + fGpffff8180 * x2;
                r = fGpffff8058 + x2 * r;
                r = fGpffff805c + x2 * r;
                r = fGpffff8060 + x2 * r;
                r2 = fGpffff8108 + x2 * r;
                r = x2 * x;
                w1 = x + r * r2;
                x = ratio * blend.scalar;
                x2 = x * x;
                r = fGpffff8054 + fGpffff8180 * x2;
                r = fGpffff8058 + x2 * r;
                r = fGpffff805c + x2 * r;
                r = fGpffff8060 + x2 * r;
                r2 = fGpffff8108 + x2 * r;
                r = x2 * x;
                ratio = x + r * r2;
            }
            blended.quat.x = blend.first.quat.x * w1;
            blended.quat.y = blend.first.quat.y * w1;
            blended.quat.z = blend.first.quat.z * w1;
            blended.quat.x = 0.0f + blended.quat.x + blend.second.quat.x * ratio;
            blended.quat.y = 0.0f + blended.quat.y + blend.second.quat.y * ratio;
            blended.quat.z = 0.0f + blended.quat.z + blend.second.quat.z * ratio;
            blended.quat.w = blend.first.quat.w * w1 + blend.second.quat.w * ratio;
        }
        RtQuatTransformVectors(&eyeAdj, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&blended));
        eyeAdj.x = eyeAdj.x + center.x;
        eyeAdj.y = eyeAdj.y + center.y;
        eyeAdj.z = eyeAdj.z + center.z;
        func_001bd780(&frames[1].rot, &eyeAdj, &center, &D_0060A0E0);
    }
    else if (angle < fGpffff804c)
    {
        func_003dc740((f32*)&frames[1].rot, (const f32*)&D_0060A0E0, fGpffff8160, 2);
    }
    if (height < 600.0f)
    {
        height = 600.0f;
    }
    dist = (1.5f * (0.5f * height)) /
           tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    RtQuatTransformVectors(&eyeAdj, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&frames[1].rot));
    direction.y = eyeAdj.y;
    RwV3dNormalize(&direction, &direction);
    angle = eyeAdj.x * direction.x +
            eyeAdj.y * direction.y +
            eyeAdj.z * direction.z;
    if (angle >= 0.0f)
    {
        selectedRadius = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
        selectedCenter = unitPoint;
    }
    else
    {
        selectedRadius = *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
        selectedCenter = targetCenter;
    }
    candidate.x = targetCenter.x + direction.z * selectedRadius;
    candidate.y = center.y;
    candidate.z = targetCenter.z - direction.x * selectedRadius;
    sideDirection.x = candidate.x - center.x;
    sideDirection.y = candidate.y - center.y;
    sideDirection.z = candidate.z - center.z;
    RwV3dNormalize(&sideDirection, &sideDirection);
    dot = 0.0f +
          sideDirection.x * direction.x +
          sideDirection.y * direction.y +
          sideDirection.z * direction.z;
    if (fabsf(angle) > fabsf(dot) &&
        dot != 0.0f && angle != 0.0f)
    {
        horiz[0] = center.x - selectedCenter.x;
        horiz[1] = center.z - selectedCenter.z;
        sideLength = RwV2dLength(horiz);
        candidate.y = center.y + halfHeight * sideLength / dist;
        candidate.x = selectedCenter.x + direction.z * selectedRadius;
        candidate.z = selectedCenter.z - direction.x * selectedRadius;
        func_001bd780(&rots[0], &candidate, &center, &D_0060A0E0);
        angle = func_001ec2b0(&frames[0].rot, &rots[0]);
        candidate.x = selectedCenter.x - direction.z * selectedRadius;
        candidate.z = selectedCenter.z + direction.x * selectedRadius;
        func_001bd780(&rots[1], &candidate, &center, &D_0060A0E0);
        ratio = func_001ec2b0(&frames[0].rot, &rots[1]);
        if (angle < ratio)
        {
            frames[1].rot = rots[0];
        }
        else
        {
            frames[1].rot = rots[1];
        }
        RtQuatTransformVectors(&eyeAdj, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&frames[1].rot));
    }
    eyeAdj.x = eyeAdj.x * dist;
    eyeAdj.y = eyeAdj.y * dist;
    eyeAdj.z = eyeAdj.z * dist;
    sideOffset = dist * tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    sideOffset = sideOffset * 0.21875f;
    horiz[0] = eyeAdj.x;
    horiz[1] = eyeAdj.z;
    func_003e41e0(horiz, horiz);
    center.x = 0.0f + center.x + horiz[1] * sideOffset;
    center.z = 0.0f + center.z - horiz[0] * sideOffset;
    frames[1].pos.x = center.x + eyeAdj.x;
    frames[1].pos.y = center.y + eyeAdj.y;
    frames[1].pos.z = center.z + eyeAdj.z;
    func_001bc3a0((f32*)&frames[0], (f32*)&frames[0]);
    func_001bc3a0((f32*)&frames[1], (f32*)&frames[1]);
    btlMainCurveSetPoses((u16*)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    btlCameraSetDuration(camera, 2.0f);
    }
    }
}
// FUN_001C04D0
void func_001c04d0(void)
{
}

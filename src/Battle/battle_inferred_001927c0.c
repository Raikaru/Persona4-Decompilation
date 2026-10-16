#include "btl_skill_target_internal.h"
#include "rw_geometry_internal.h"
#include "model_motion_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_packet_create_internal.h"
#include "effect_instance_internal.h"
#include "btl_skill_internal.h"
#include "btl_battle_internal.h"
#include "rw_types_internal.h"
typedef RwV3d P4_95730_Vec3;
typedef struct P4_95730_Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} P4_95730_Vec4;
typedef struct P4_95730_Bytes4 {
    u8 x;
    u8 y;
    u8 z;
    u8 w;
} P4_95730_Bytes4;
typedef struct DatUnit DatUnit;

extern void datSetFlag(s32 arg0, s32 arg1);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void mdlEffectEmitMaskedTagPair(void);
extern void func_0045c870(void *arg0, s32 arg1);
extern void mdlEffectEmitTagPair(void);
extern f32 fGpffff8474;
extern void func_003c22f0(void *arg0);
extern u8 D_005F6CA0[];
extern f32 D_005F6C10[];
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern u8 *iGpffffb3c0;
extern u8 *iGpffffb3cc;

extern s64 scrGetParamInt(s32 arg0);
extern u8 *datUnitGetRecord(s16 arg0);

extern u8 *iGpffff9db0;
extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern s32 datGetPartyId(s32 arg0);
/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
extern s32 datUnitCreatePc(s32 arg0);
/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
extern s32 datUnitCreateEncounterGroup(s32 arg0);
extern void func_001029a0(s32 id, void *data, s32 size, s32 flag);
extern u8 *iGpffffb3e0;
extern s32 iGpffffb430;
extern s32 iGpffffb434;
extern s32 iGpffffb438;
extern u8 D_005F6BF0[];
extern u8 D_005F66C0[];
extern u64 iGpffffa090;
extern u16 iGpffffa098;
extern s32 iGpffffb43c;
extern u8 D_005F65D0[];
extern u8 D_005F65B0[];
extern u8 D_005F65C0[];

extern void memcpy(void *dst, void *src, s32 size);
extern s32 btlUiCreateTask(s32 arg0);
extern s32 datGetFlag(s32 arg0);
extern void btlMainSetPhase(s32 arg0);
extern s32 btlUpdateTask(u8 *task);
extern s32 btlUpdateDraw3DTask(u8 *task);
extern s32 btlUpdateDraw2DTask(u8 *task);
extern s32 datCalcIsDead(u8 *arg0, s32 arg1);
extern s32 btlUnitReactToDeath(void);
extern s32 iGpffffb3b0;
extern s32 iGpffffb284;
extern s32 iGpffffb280;
extern s32 scrGetCmdTimer(void);
extern u8 *scrGetContext(void);
extern void datCalcIsDeadById(s16 arg0);
extern void datSetUnitHp(s16 arg0, s16 arg1);
extern void datCalcClearBadStatusById(s16 arg0, s32 arg1);
extern void KMisc_CreateScrShutdown(s32 arg0);
extern void sdlSchedulerEnable(void);
extern u8 iGpffffa0a0;
extern u8 D_005F6BE0[];
extern u8 D_007F17B0[];
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter,
                         f32 *outTop, f32 *outBottom, u32 options);
extern void RtQuatTransformVectors(void *out, const void *in, s32 count,
                          const void *quat);
extern P4_95730_Vec3 D_0060A0D0;
extern f32 fGpffff82d0;
extern f32 fGpffff811c;
extern f32 fGpffff8198;
extern f32 fGpffff82d8;
extern f32 fGpffff82d4;
extern f32 fGpffff80f0;
extern f32 fGpffff82dc;
extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern P4_95730_Vec3 D_0060A100;
extern u8 *(*D_008873E8[])(s32 arg0, s32 arg1);
extern void btlTargetResetRadiusState(void);
extern void func_00194660(void);
extern void btlCameraInitSystem(void);
extern void btlSoundResetSlotQueue(void);
extern void btlVoiceResetPlaybackState(void);
extern void func_001d6a60(void);
extern void btlActionResetQueueState(void);
extern void btlMainReset(void);
extern void btlSoundResetPlaybackState(void);
extern s32 itfMesWindowInstall(u8 *arg0);

extern void memset(void *arg0, s32 arg1, s32 arg2);
extern u8 *kwlnTaskGetTaskByName(void *arg0);
extern void kwlnTaskDestroyWithHierarchy(s32 arg0);

/* Retail computes the unit record address as index-times-stride plus base;
   MWCCPS2 emits a commutative addu in the order the operands reach it, so the
   order has to come from an inline's parameter list. */
static inline u8 *p4_unit_00195530(s32 offset, u8 *base)
{
    return (u8 *)(offset + (s32)base);
}
static inline s32 p4_base_add_0019f050(s32 offset, s32 base)
{
    return base + offset;
}
static inline s32 *p4_entries_001900a0(s32 offset, s32 *base)
{
    return (s32 *)((s32)base + offset);
}
static inline s32 p4_base_add_00194590(s32 offset, s32 base)
{
    return offset + base;
}
static inline u8 p4_one_00194470(void)
{
    return 1;
}
static inline s64 p4_sign16_001991c0(s16 value)
{
    return value;
}
static inline s32 p4_table_001951f0(s32 modeOffset, s32 charOffset,
                                    s32 base)
{
    return modeOffset + charOffset + base;
}
static inline f32 p4_add_0019a680(f32 left, f32 right)
{
    return left + right;
}
static inline void p4_d550_store(u8 *value, u8 *base, u32 index, u32 offset)
{
    u8 *address;
    u8 *stored;

    stored = value;
    address = base;
    address = (u8 *)((u32)(index << 3) + (u32)(address, address));
    *(u8 **)(address + offset) = stored;
}

static inline void p4_call_00198920(s16 arg1, u8 *arg0, u16 arg2, f32 arg3, u16 arg4)
{
    btlUnitSetMotion(arg0, arg1, arg2, arg3, arg4);
}
extern s32 scrStartProcedureChecked(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
static inline void p4_call_0029db50(s32 arg2, s32 arg0, s32 arg1, s32 arg3)
{
    scrStartProcedureChecked(arg0, arg1, arg2, arg3);
}
extern u8 iGpffffa4d8;
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;






extern s32 iGpffffb444;
extern s32 datCalcIsStandardUnit(s32 arg0, s32 arg1);

static inline void p4_call_0019ef30(u16 arg1, u8 *arg0)
{
    btlUnitInitChild(arg0, arg1);
}
extern u8 *kwlnTaskGetTaskByName(void *arg0);
extern void kwlnTaskDestroyWithHierarchy(s32 arg0);
extern s32 btlRelease(void);
extern void btlPacketFlushAll(void);
extern void btlUnitFreeRemovedUnits(void);
extern void datUnitFree(s32 arg0);
extern void (*jtbl_008873EC[])(void *arg0);
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void hFadeTaskStart(s16 arg0);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* Source unit: src/promoted/code1_0019.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0019.c; members 001927c0-001935c0 */

/* measured: opt_propagation off is scoped to btlRenderStateSetup. */
/* measured: btlRenderStateSetup MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001927C0
void btlRenderStateSetup(void)
{
    u8 color[4];
    void (**base)(s32, s32);

    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x717FB);
    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](1, 0);
    mdlEffectEmitMaskedTagPair();
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    color[3] = 0xFF;
    func_0045c870(color, 0);
    mdlEffectEmitTagPair();
}

/* measured: closes opt_propagation around btlRenderStateSetup. */
/* measured: opt_propagation off is scoped to btlSkyScroll. */
/* measured: opt_loop_invariants on is scoped to btlSkyScroll. */
/* measured: btlSkyScroll MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_001928C0
void btlSkyScroll(void)
{
    f32 delta;
    u32 i;
    u32 j;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_3;
    u8 *temp_4;
    u8 *var_4;
    void (**base)(s32, s32);
    void (*callback)(u8 *);

    if (*(s32 *)(iGpffffb3ac + 0xE78) != 0) {
        RpSkyRenderStateSet(2, 0x54);
        RpSkyRenderStateSet(3, 0x757FB);
        base = D_00887300;
        base[0](7, 2);
        base[0](0xE, 0);
        base[0](6, 1);
        base[0](8, 0);
        base[0](9, 2);
        base[0](0xC, 1);
        RpGeometryLock(
            *(RpGeometry **)(*(u8 **)(*(u8 **)(iGpffffb3ac + 0xE7C) + 0x10) + 0x18),
            0xFF0);
        temp_3 = iGpffffb3ac;
        var_4 = *(u8 **)(*(u8 **)(*(u8 **)(temp_3 + 0xE7C) + 0x10) + 0x18);
        var_4 = *(u8 **)(var_4 + 0x34);
        *(f32 *)(temp_3 + 0xE80) =
            *(f32 *)(temp_3 + 0xE80) - (delta = fGpffff8474);
        if (*(f32 *)(iGpffffb3ac + 0xE80) <= -1.0f) {
            i = 0;
            while (i < 0x59U) {
                *(f32 *)(var_4 + 4) = *(f32 *)(var_4 + 4) + 1.0f;
                var_4 += 8;
                i++;
            }
            *(f32 *)(iGpffffb3ac + 0xE80) = 0.0f;
        } else {
            j = 0;
            while (j < 0x59U) {
                *(f32 *)(var_4 + 4) =
                    *(f32 *)(var_4 + 4) - delta;
                var_4 += 8;
                j++;
            }
        }
        temp_17 = *(u8 **)(iGpffffb3ac + 0xE7C);
        temp_16 = *(u8 **)(*(u8 **)(temp_17 + 0x10) + 0x18);
        func_003c22f0(temp_16);
        if ((*(u16 *)temp_17 & 4) != 0) {
            *(u16 *)(temp_16 + 0xC) |= 1;
        }
        temp_4 = *(u8 **)(*(u8 **)(iGpffffb3ac + 0xE7C) + 0x10);
        callback = *(void (**)(u8 *))(temp_4 + 0x48);
        callback(temp_4);
    }
}

/* measured: closes opt_loop_invariants around btlSkyScroll. */
/* measured: closes opt_propagation around btlSkyScroll. */
/* measured: btlRelease, func_001932f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// FUN_00192AC0
void btlReleaseTask(u8 *unusedTask) {
    btlRelease();
}

// FUN_00192AE0
void btlDestroyTask(void) {
    if (kwlnTaskGetTaskByName(&iGpffffa088) != 0) {
        kwlnTaskDestroyWithHierarchy(*(s32 *)(iGpffffb3ac + 0xDC8));
    }
}

// FUN_00192B20
void btlResetEffectSlots(void) {
    s32 i;

    for (i = 0x15C0; i <= 0x15FF; i++) {
        datSetFlag(i, 0);
    }
    datSetFlag(0x1435, 0);
    datSetFlag(0x1438, 0);
}

// FUN_00192B90
void btlInit(void)
{
    s32 i;
    *(u64 *)&iGpffffa090 = 1;
    iGpffffa098 = 0x100;
    chkmemAllocSiteTag(D_005F65D0, 0x3A);
    iGpffffb3ac = (u8 *)D_008873E8[0](0xE88, 0x40000);
    memset(iGpffffb3ac, 0, 0xE88);
    *(s32 *)(iGpffffb3ac + 0xC60) = itfMesWindowInstall((u8 *)iGpffffb43c);
    for (i = 0x15C0; i <= 0x15FF; i++) {
        datSetFlag(i, 0);
    }
    datSetFlag(0x1435, 0);
    datSetFlag(0x1438, 0);
    btlTargetResetRadiusState();
    func_00194660();
    btlCameraInitSystem();
    btlSoundResetSlotQueue();
    btlVoiceResetPlaybackState();
    func_001d6a60();
    btlActionResetQueueState();
    btlMainReset();
    btlSoundResetPlaybackState();
    *(s32 *)(iGpffffb3ac + 0xC) |= 0x1480877C;
}

// FUN_00192CD0
s32 btlRelease(void)
{
    u32 i;
    s32 temp;
    s32 *base;
    btlActionListDestroyAll();
    btlUnitFreeRemovedUnits();
    btlMainSaveFieldSnapshotAndUnload();
    func_001b6110();
    btlEffectFreeAllNodes();
    btlVoiceFreePlaybackBuffers();
    func_001f73c0();
    btlCameraResetWorkList();
    btlSoundStopAndReleaseHandle();
    btlFormationClearSlots();
    btlPacketFlushAll();
    itfMesWindowReleaseIfActive(*(s32 *)(iGpffffb3ac + 0xC60));
    if ((*(s32 *)(iGpffffb3ac + 0xC) & BTL_FLAG_FREE_UNITS) != 0) {
        for (i = 0; (u16)i < 4; i = (u16)(i + 1)) {
            base = (s32 *)iGpffffb3ac;
            temp = *(s32 *)((s32)base + (i & 0xFFFF) * 4 + 0xC74);
            if (temp != 0) {
                datUnitFree(temp);
            }
        }
        for (i = 0; (u16)i < 3; i = (u16)(i + 1)) {
            base = (s32 *)iGpffffb3ac;
            temp = *(s32 *)((s32)base + (i & 0xFFFF) * 4 + 0xC84);
            if (temp != 0) {
                datUnitFree(temp);
            }
        }
        for (i = 0; (u16)i < (u32)3; i = (u16)(i + 1)) {
            base = (s32 *)iGpffffb3ac;
            temp = *(s32 *)((s32)base + (i & 0xFFFF) * 8 + 0xC94);
            if (temp != 0) {
                datUnitFree(temp);
            }
        }
    }
    if (kwlnTaskGetTaskByName(&iGpffffa088) != 0) {
        kwlnTaskDestroyWithHierarchy(*(s32 *)(iGpffffb3ac + 0xDC8));
    }
    jtbl_008873EC[0](iGpffffb3ac);
    iGpffffb3ac = NULL;
    return 0;
}

// FUN_00192E90
s32 btlTaskCreate(s32 arg0)
{
    s32 temp_16;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_4;

    btlInit();
    *(s32 *)(iGpffffb3ac + 0xDC8) =
        (s32)kwlnTaskCreate((const void *)(&iGpffffa088), 0x10, arg0 == 0, 0, btlUpdateTask, btlReleaseTask, (u8 *)(0));
    (s32)kwlnTaskCreateChild((void *)(*(u8 **)(iGpffffb3ac + 0xDC8)), (const void *)(D_005F65B0), 0x11, arg0 == 0, 0, btlUpdateDraw3DTask, 0, (u8 *)(NULL));
    (s32)kwlnTaskCreateChild((void *)(*(u8 **)(iGpffffb3ac + 0xDC8)), (const void *)(D_005F65C0), 0x11, arg0 == 0, 0, btlUpdateDraw2DTask, 0, (u8 *)(NULL));
    *(void **)(iGpffffb3ac + 0xE20) = (void *)btlRenderStateSetup;
    temp_2 = iGpffffb3ac;
    *(u8 **)(temp_2 + 0xE28) = temp_2;
    *(void **)(iGpffffb3ac + 0xE50) = (void *)btlSkyScroll;
    temp_2_2 = iGpffffb3ac;
    *(u8 **)(temp_2_2 + 0xE58) = temp_2_2;
    *(s32 *)(iGpffffb3ac + 0xDD4) =
        btlUiCreateTask(*(s32 *)(iGpffffb3ac + 0xDC8));
    temp_3 = iGpffffb3ac;
    temp_16 = *(s32 *)(temp_3 + 0xDC8);
    if (arg0 != 0) {
        *(s8 *)(temp_3 + 0xC65) = 0;
        memcpy(iGpffffb3ac + 0xC70, (void *)arg0, 0x3C);
        temp_3_2 = iGpffffb3ac;
        *(u16 *)(temp_3_2 + 0x26C) = *(u16 *)(temp_3_2 + 0xC90);
        temp_3_3 = iGpffffb3ac;
        *(u16 *)(temp_3_3 + 0x26E) = *(u16 *)(temp_3_3 + 0xC92);
        btlMainSetPhase(2);
    } else {
        *(s8 *)(temp_3 + 0xC65) = 1;
        if (datGetFlag(0x1436) == 0) {
            btlMainSetPhase(0x12);
        } else {
            btlMainSetPhase(0x13);
        }
    }
    temp_3_4 = iGpffffb3ac;
    *(s32 *)(temp_3_4 + 0xC) |= 1;
    return temp_16;
}

// FUN_00193060
s32 btlCheckBattleEnd(void)
{
    u8 *var_20;
    s32 var_19;
    s32 var_18;
    s32 var_17;
    s32 var_21;
    u8 temp_3_2;
    u8 *temp_16;
    u8 *temp_3;
    u8 *temp_4;

    *(s16 *)(iGpffffb3ac + 0x1C) = 0;
    var_19 = 0;
    var_18 = 0;
    var_17 = 0;
    var_21 = 1;
    temp_4 = iGpffffb3ac;
    if (*(s32 *)(temp_4 + 0x10) & 0x10000000) {
        *(s16 *)(temp_4 + 0x1C) = 2;
        return 1;
    }
    var_20 = *(u8 **)(temp_4 + 0x174);
    goto loop_18_check;
loop_18_body:
    if ((*(u16 *)(var_20 + 0x1A) & 1) &&
        !(*(u16 *)(var_20 + 0x18) & 0x20)) {
        temp_16 = *(u8 **)(var_20 + 0x30);
        if ((datCalcIsDead(*(u8 **)(temp_16 + 0xA64), 0) != 0) &&
            (temp_3 = *(u8 **)(temp_16 + 0xA64),
             (*(u16 *)(temp_3 + 0) & 0x20) == 0)) {
            if (*(u8 *)(temp_16 + 0xA2) == 0 &&
                *(u16 *)(temp_3 + 2) == 1) {
                var_21 = 0;
            }
            var_17 += 1;
        } else {
            temp_3_2 = *(u8 *)(temp_16 + 0xA2);
            switch (temp_3_2) {
            case 0:
                var_19 += 1;
                break;
            case 1:
                if (*(s32 *)(temp_16 + 0x9C) & 8) {
                    var_18 += 1;
                }
                break;
            }
        }
    }
    var_20 = *(u8 **)(var_20 + 0x450);
loop_18_check:
    if (var_20 != NULL) {
        goto loop_18_body;
    }
    if (var_21 == 0 || (var_19 == 0 && var_17 != 0)) {
        *(s16 *)(iGpffffb3ac + 0x1C) = 2;
        return 1;
    }
    if (var_19 == 0) {
        *(s16 *)(iGpffffb3ac + 0x1C) = 3;
        return 1;
    }
    if (btlUnitReactToDeath() != 0) {
        *(s16 *)(iGpffffb3ac + 0x1C) = 1;
        return 1;
    }
    if (var_18 == 0) {
        *(s16 *)(iGpffffb3ac + 0x1C) = 1;
        return 1;
    }
    return 0;
}

// FUN_00193260
s32 btlIsLeaderStandardUnit(void)
{
    u8 *base;
    s32 flags;

    base = iGpffffb3ac;
    flags = *(s32 *)(base + 0x10);
    if ((flags & 0x20000000) != 0) {
        return 0;
    }
    if ((flags & 0x10000000) != 0) {
        return 0;
    }
    if ((*(s32 *)(base + 0xC) & 0x800000) != 0) {
        return datCalcIsStandardUnit(
            *(s32 *)(*(u8 **)(*(u8 **)(base + 0x170) + 0x30) + 0xA64),
            0x31E);
    }
    return 0;
}

// AI script command 0x20DC (AI command table entry, VA 0x0063DCC0). AI library name: AI_FUNCTION_00DC.
// FUN_001932F0
s32 btlScriptStartEncounter(void)
{
    u8 sp50[0x3C];
    s32 var_19;
    u16 var_18;
    u16 temp_17;
    s32 temp_4;
    u16 temp_4_2;
    u16 temp_3;
    u8 *temp_16;

    hFadeTaskStart(1);
    temp_17 = scrGetParamInt(0) & 0xFFFF;
    temp_16 = (u8 *)(iGpffffb414 + (temp_17 * 0x18));
    memset(sp50, 0, 0x3C);
    *(s32 *)(sp50 + 4) = datUnitCreatePc(1);
    var_18 = 1;
    var_19 = 0;
    goto loop_5_check;
loop_5_body:
    temp_4_2 = datGetPartyId(temp_4) & 0xFFFF;
    if ((temp_4_2 != 0) && (var_18 < 4)) {
        ((s32 *)(sp50 + 4))[var_18++] = datUnitCreatePc(temp_4_2);
    }
    var_19 = (var_19 + 1) & 0xFFFF;
loop_5_check:
    temp_4 = var_19 & 0xFFFF;
    if (temp_4 < 4) {
        goto loop_5_body;
    }
    *(s32 *)(sp50 + 0x14) = datUnitCreateEncounterGroup(temp_17);
    temp_3 = *(u16 *)(temp_16 + 0x12);
    if ((temp_3 == 0) && (*(u16 *)(temp_16 + 0x14) == 0)) {
        *(u16 *)(sp50 + 0x20) = 0xF0;
        *(u16 *)(sp50 + 0x22) = 1;
    } else {
        *(u16 *)(sp50 + 0x20) = temp_3;
        *(u16 *)(sp50 + 0x22) = *(u16 *)(temp_16 + 0x14);
    }
    func_001029a0(6, sp50, 0x3C, 4);
    return 1;
}

// AI script command 0x20DD (AI command table entry, VA 0x0063DCC8). AI library name: AI_FUNCTION_00DD.
/* Measured: the archived body compiles to object 356B in the 368B window. Retail words at offsets 356, 360, and 364 are all 00000000 (nop); verify therefore accepts the zero-padded tail and reports MATCH. */
// FUN_00193450
s32 btlScriptResolvePartyDeath(void)
{
    extern s16 datGetPartyId(s32 idx);
    extern u32 datCalcIsDeadById(s16 character);
    extern void datSetUnitHp(s16 character, s16 value);
    extern void datCalcClearBadStatusById(s16 character, u32 mask);
    u32 var_16;
    u32 dep;

    if (scrGetCmdTimer() > 0xA) {
        if (iGpffffb3ac != NULL) {
            iGpffffb3b0 = 0;
            return 0;
        }
        if (iGpffffb3b0 == 0) {
            if (datCalcIsDead(datUnitGetRecord(1), 0) != 0) {
                dep = iGpffffb280;
                scrStartProcedureChecked(0xF, iGpffffb284, dep, 0);
                KMisc_CreateScrShutdown(*(s32 *)(scrGetContext() + 0x148));
                sdlSchedulerEnable();
                iGpffffb3b0 = 1;
                goto block_13;
            }
            var_16 = 0;
            goto loop_11_check;
loop_11_body:
            if (((s16)datGetPartyId((s32)var_16) != 0) &&
                (datCalcIsDeadById(datGetPartyId((s32)var_16)) != 0)) {
                datSetUnitHp(datGetPartyId((s32)var_16), 1);
                datCalcClearBadStatusById(datGetPartyId((s32)var_16), 0x80000);
            }
            var_16 += 1;
loop_11_check:
            if (var_16 < 3U) {
                goto loop_11_body;
            }
            return 1;
        }
    }
block_13:
    return 0;
}

// AI script command 0x20DE (AI command table entry, VA 0x0063DCD0). AI library name: AI_FUNCTION_00DE.
// FUN_001935C0
s32 btlScriptFadeOut(void) {
    hFadeTaskStart(1);
    return 1;
}


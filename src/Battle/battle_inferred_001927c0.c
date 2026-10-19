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
#include "btl_effect_internal.h"
#include "btl_action_internal.h"
#include "rw_atomic_layout_internal.h"
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
extern void effMiscDrawScreenColor(void *arg0, s32 arg1);
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
extern void sequenceRequest(s32 id, void *data, s32 size, s32 flag);
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
extern void btlEffectInitializeNodeSystem(void);
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

extern s32 scrStartProcedureChecked(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern u8 iGpffffa4d8;
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;






extern s32 iGpffffb444;
extern s32 datCalcIsStandardUnit(s32 arg0, s32 arg1);

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


/* The sky path locks the atomic geometry, advances 89 eight-byte UV pairs,
 * then marks its lock word and calls the atomic renderer (SDK bageomet.h). */
typedef struct BtlSkyTexCoord {
    f32 u;
    f32 v;
} BtlSkyTexCoord;
struct RpGeometry {
    u8 pad00[0xC];
    u16 lockedSinceLastInst;
    u8 pad0E[0x34 - 0xE];
    BtlSkyTexCoord *texCoords;
};
typedef struct BtlSky {
    u16 flags;
    u8 pad02[0xE];
    struct RpAtomic *atomic;
} BtlSky;

/* Encounter table stride is 0x18; these halfwords feed the setup formation. */
typedef struct BtlEncounterRecord {
    u8 pad00[0x12];
    u16 formation;
    u16 formationVariant;
    u8 pad16[2];
} BtlEncounterRecord;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 001927c0-001935c0 */

/* measured: opt_propagation off is scoped to btlRenderStateSetup. */
/* measured: btlRenderStateSetup MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* Initialize render state and opaque black colour before the battle draw pass. */
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
    effMiscDrawScreenColor(color, 0);
    mdlEffectEmitTagPair();
}

/* measured: closes opt_propagation around btlRenderStateSetup. */
/* measured: opt_propagation off is scoped to btlSkyScroll. */
/* measured: opt_loop_invariants on is scoped to btlSkyScroll. */
/* measured: btlSkyScroll MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* Scroll the sky texture V coordinates, wrapping after one texture period. */
// FUN_001928C0
void btlSkyScroll(void)
{
    f32 delta;
    u32 i;
    u32 j;
    RpGeometry *geometry;
    BtlSky *sky;
    u8 *battle;
    struct RpAtomic *atomic;
    BtlSkyTexCoord *texCoords;
    void (**base)(s32, s32);
    struct RpAtomic *(*callback)(struct RpAtomic *);

    if (((BtlBattleState *)iGpffffb3ac)->skyActive != 0) {
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
            ((BtlSky *)((BtlBattleState *)iGpffffb3ac)->sky)->atomic->geometry,
            0xFF0);
        battle = iGpffffb3ac;
        texCoords = ((BtlSky *)((BtlBattleState *)battle)->sky)->atomic->geometry->texCoords;
        ((BtlBattleState *)battle)->skyScroll =
            ((BtlBattleState *)battle)->skyScroll - (delta = fGpffff8474);
        if (((BtlBattleState *)iGpffffb3ac)->skyScroll <= -1.0f) {
            i = 0;
            while (i < 0x59U) {
                texCoords->v = texCoords->v + 1.0f;
                texCoords++;
                i++;
            }
            ((BtlBattleState *)iGpffffb3ac)->skyScroll = 0.0f;
        } else {
            j = 0;
            while (j < 0x59U) {
                texCoords->v =
                    texCoords->v - delta;
                texCoords++;
                j++;
            }
        }
        sky = (BtlSky *)((BtlBattleState *)iGpffffb3ac)->sky;
        geometry = sky->atomic->geometry;
        func_003c22f0(geometry);
        if ((sky->flags & 4) != 0) {
            geometry->lockedSinceLastInst |= 1;
        }
        atomic = ((BtlSky *)((BtlBattleState *)iGpffffb3ac)->sky)->atomic;
        callback = atomic->renderCallBack;
        callback(atomic);
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

/* Destroy the battle task hierarchy when its named root still exists. */
// FUN_00192AE0
void btlDestroyTask(void) {
    if (kwlnTaskGetTaskByName(&iGpffffa088) != 0) {
        kwlnTaskDestroyWithHierarchy(((BtlBattleState *)iGpffffb3ac)->cutinTaskParent);
    }
}

/* Clear the battle effect-slot flag range and the two auxiliary flags. */
// FUN_00192B20
void btlResetEffectSlots(void) {
    s32 i;

    for (i = 0x15C0; i <= 0x15FF; i++) {
        datSetFlag(i, 0);
    }
    datSetFlag(0x1435, 0);
    datSetFlag(0x1438, 0);
}

/* Allocate the 0xE88 battle runtime and initialize its subsystems and flags. */
// FUN_00192B90
void btlInit(void)
{
    s32 i;
    *(u64 *)&iGpffffa090 = 1;
    iGpffffa098 = 0x100;
    chkmemAllocSiteTag(D_005F65D0, 0x3A);
    iGpffffb3ac = (u8 *)D_008873E8[0](0xE88, 0x40000);
    memset(iGpffffb3ac, 0, 0xE88);
    ((BtlBattleState *)iGpffffb3ac)->messageWindow = itfMesWindowInstall((u8 *)iGpffffb43c);
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
    btlEffectInitializeNodeSystem();
    btlActionResetQueueState();
    btlMainReset();
    btlSoundResetPlaybackState();
    ((BtlBattleState *)iGpffffb3ac)->flags |= 0x1480877C;
}

/* Release battle-owned resources and optional encounter units, then free the runtime. */
// FUN_00192CD0
s32 btlRelease(void)
{
    u32 i;
    s32 temp;
    s32 *base;
    btlActionListDestroyAll();
    btlUnitFreeRemovedUnits();
    btlMainSaveFieldSnapshotAndUnload();
    btlMainRelease();
    btlEffectFreeAllNodes();
    btlVoiceFreePlaybackBuffers();
    func_001f73c0();
    btlCameraResetWorkList();
    btlSoundStopAndReleaseHandle();
    btlFormationClearSlots();
    btlPacketFlushAll();
    itfMesWindowReleaseIfActive(((BtlBattleState *)iGpffffb3ac)->messageWindow);
    if ((((BtlBattleState *)iGpffffb3ac)->flags & BTL_FLAG_FREE_UNITS) != 0) {
        for (i = 0; (u16)i < 4; i = (u16)(i + 1)) {
            base = (s32 *)iGpffffb3ac;
            temp = ((BtlBattleState *)base)->encounter.partyUnits[i & 0xFFFF];
            if (temp != 0) {
                datUnitFree(temp);
            }
        }
        for (i = 0; (u16)i < 3; i = (u16)(i + 1)) {
            base = (s32 *)iGpffffb3ac;
            temp = ((BtlBattleState *)base)->encounter.enemyUnits[i & 0xFFFF];
            if (temp != 0) {
                datUnitFree(temp);
            }
        }
        for (i = 0; (u16)i < (u32)3; i = (u16)(i + 1)) {
            base = (s32 *)iGpffffb3ac;
            temp = ((BtlBattleState *)base)->encounter.units[i & 0xFFFF].unit;
            if (temp != 0) {
                datUnitFree(temp);
            }
        }
    }
    if (kwlnTaskGetTaskByName(&iGpffffa088) != 0) {
        kwlnTaskDestroyWithHierarchy(((BtlBattleState *)iGpffffb3ac)->cutinTaskParent);
    }
    jtbl_008873EC[0](iGpffffb3ac);
    iGpffffb3ac = NULL;
    return 0;
}

/* Create the update and draw task hierarchy and copy an optional 0x3C encounter setup. */
// FUN_00192E90
s32 btlTaskCreate(s32 setupAddress)
{
    s32 battleTask;
    u8 *renderStateBattle;
    u8 *skyBattle;
    u8 *battle;
    u8 *formationBattle;
    u8 *variantBattle;
    u8 *activeBattle;

    btlInit();
    ((BtlBattleState *)iGpffffb3ac)->cutinTaskParent =
        (s32)kwlnTaskCreate((const void *)(&iGpffffa088), 0x10, setupAddress == 0, 0, btlUpdateTask, btlReleaseTask, (u8 *)(0));
    (s32)kwlnTaskCreateChild((void *)(((BtlBattleState *)iGpffffb3ac)->cutinTaskParent), (const void *)(D_005F65B0), 0x11, setupAddress == 0, 0, btlUpdateDraw3DTask, 0, (u8 *)(NULL));
    (s32)kwlnTaskCreateChild((void *)(((BtlBattleState *)iGpffffb3ac)->cutinTaskParent), (const void *)(D_005F65C0), 0x11, setupAddress == 0, 0, btlUpdateDraw2DTask, 0, (u8 *)(NULL));
    ((BtlBattleState *)iGpffffb3ac)->renderStateNode.callback = (void *)btlRenderStateSetup;
    renderStateBattle = iGpffffb3ac;
    ((BtlBattleState *)renderStateBattle)->renderStateNode.work = renderStateBattle;
    ((BtlBattleState *)iGpffffb3ac)->skyNode.callback = (void *)btlSkyScroll;
    skyBattle = iGpffffb3ac;
    ((BtlBattleState *)skyBattle)->skyNode.work = skyBattle;
    ((BtlBattleState *)iGpffffb3ac)->uiTask =
        btlUiCreateTask(((BtlBattleState *)iGpffffb3ac)->cutinTaskParent);
    battle = iGpffffb3ac;
    battleTask = ((BtlBattleState *)battle)->cutinTaskParent;
    if (setupAddress != 0) {
        ((BtlBattleState *)battle)->isFieldEncounter = 0;
        memcpy(&((BtlBattleState *)iGpffffb3ac)->encounter, (void *)setupAddress, 0x3C);
        formationBattle = iGpffffb3ac;
        ((BtlBattleState *)formationBattle)->formation = ((BtlBattleState *)formationBattle)->encounter.formation;
        variantBattle = iGpffffb3ac;
        ((BtlBattleState *)variantBattle)->formationVariant = ((BtlBattleState *)variantBattle)->encounter.formationVariant;
        btlMainSetPhase(2);
    } else {
        ((BtlBattleState *)battle)->isFieldEncounter = 1;
        if (datGetFlag(0x1436) == 0) {
            btlMainSetPhase(0x12);
        } else {
            btlMainSetPhase(0x13);
        }
    }
    activeBattle = iGpffffb3ac;
    ((BtlBattleState *)activeBattle)->flags |= 1;
    return battleTask;
}

/* Count participating living/dead actions and store the battle-end result code. */
/* BtlBattleState/BtlAction/BtlUnit/DatUnit establish these offsets; retain
 * byte addressing because shared-member typing changed MWCC allocation (nd 335). */
// FUN_00193060
s32 btlCheckBattleEnd(void)
{
    u8 *action;
    s32 livingPartyCount;
    s32 livingEnemyCount;
    s32 deadCount;
    s32 leaderAlive;
    u8 genus;
    u8 *unit;
    u8 *data;
    u8 *battle;

    *(s16 *)(iGpffffb3ac + 0x1C) = 0;
    livingPartyCount = 0;
    livingEnemyCount = 0;
    deadCount = 0;
    leaderAlive = 1;
    battle = iGpffffb3ac;
    if (*(s32 *)(battle + 0x10) & 0x10000000) {
        *(s16 *)(battle + 0x1C) = 2;
        return 1;
    }
    action = *(u8 **)(battle + 0x174);
    goto loop_18_check;
loop_18_body:
    if ((*(u16 *)(action + 0x1A) & 1) &&
        !(*(u16 *)(action + 0x18) & 0x20)) {
        unit = *(u8 **)(action + 0x30);
        if ((datCalcIsDead(*(u8 **)(unit + 0xA64), 0) != 0) &&
            (data = *(u8 **)(unit + 0xA64),
             (*(u16 *)(data + 0) & 0x20) == 0)) {
            if (*(u8 *)(unit + 0xA2) == 0 &&
                *(u16 *)(data + 2) == 1) {
                leaderAlive = 0;
            }
            deadCount += 1;
        } else {
            genus = *(u8 *)(unit + 0xA2);
            switch (genus) {
            case 0:
                livingPartyCount += 1;
                break;
            case 1:
                if (*(s32 *)(unit + 0x9C) & 8) {
                    livingEnemyCount += 1;
                }
                break;
            }
        }
    }
    action = *(u8 **)(action + 0x450);
loop_18_check:
    if (action != NULL) {
        goto loop_18_body;
    }
    if (leaderAlive == 0 || (livingPartyCount == 0 && deadCount != 0)) {
        *(s16 *)(iGpffffb3ac + 0x1C) = 2;
        return 1;
    }
    if (livingPartyCount == 0) {
        *(s16 *)(iGpffffb3ac + 0x1C) = 3;
        return 1;
    }
    if (btlUnitReactToDeath() != 0) {
        *(s16 *)(iGpffffb3ac + 0x1C) = 1;
        return 1;
    }
    if (livingEnemyCount == 0) {
        *(s16 *)(iGpffffb3ac + 0x1C) = 1;
        return 1;
    }
    return 0;
}

/* Test whether the selected leader uses standard unit data under the active battle flags. */
// FUN_00193260
s32 btlIsLeaderStandardUnit(void)
{
    u8 *base;
    s32 flags;

    base = iGpffffb3ac;
    flags = ((BtlBattleState *)base)->battleFlags;
    if ((flags & 0x20000000) != 0) {
        return 0;
    }
    if ((flags & 0x10000000) != 0) {
        return 0;
    }
    if ((((BtlBattleState *)base)->flags & 0x800000) != 0) {
        return datCalcIsStandardUnit(
            (s32)((BtlAction *)((BtlBattleState *)base)->selectedAction)->unit->datUnit,
            0x31E);
    }
    return 0;
}

// AI script command 0x20DC (AI command table entry, VA 0x0063DCC0). AI library name: AI_FUNCTION_00DC.
/* Build an encounter setup from party slots and encounter formation defaults. */
// FUN_001932F0
s32 btlScriptStartEncounter(void)
{
    BtlEncounterSetup setup;
    s32 partyIndex;
    u16 partyCount;
    u16 encounterId;
    s32 slotIndex;
    u16 partyId;
    u16 formation;
    BtlEncounterRecord *encounter;

    hFadeTaskStart(1);
    encounterId = scrGetParamInt(0) & 0xFFFF;
    encounter = &((BtlEncounterRecord *)iGpffffb414)[encounterId];
    memset(&setup, 0, 0x3C);
    setup.partyUnits[0] = (s32)datUnitCreatePc(1);
    partyCount = 1;
    partyIndex = 0;
    goto loop_5_check;
loop_5_body:
    partyId = datGetPartyId(slotIndex) & 0xFFFF;
    if ((partyId != 0) && (partyCount < 4)) {
        setup.partyUnits[partyCount++] = (s32)datUnitCreatePc(partyId);
    }
    partyIndex = (partyIndex + 1) & 0xFFFF;
loop_5_check:
    slotIndex = partyIndex & 0xFFFF;
    if (slotIndex < 4) {
        goto loop_5_body;
    }
    setup.enemyUnits[0] = (s32)datUnitCreateEncounterGroup(encounterId);
    formation = encounter->formation;
    if ((formation == 0) && (encounter->formationVariant == 0)) {
        setup.formation = 0xF0;
        setup.formationVariant = 1;
    } else {
        setup.formation = formation;
        setup.formationVariant = encounter->formationVariant;
    }
    sequenceRequest(6, &setup, 0x3C, 4);
    return 1;
}

// AI script command 0x20DD (AI command table entry, VA 0x0063DCC8). AI library name: AI_FUNCTION_00DD.
/* Measured: the archived body compiles to object 356B in the 368B window. Retail words at offsets 356, 360, and 364 are all 00000000 (nop); verify therefore accepts the zero-padded tail and reports MATCH. */
/* After teardown, start the leader-death script or revive defeated party members to one HP. */
// FUN_00193450
s32 btlScriptResolvePartyDeath(void)
{
    extern s16 datGetPartyId(s32 idx);
    extern u32 datCalcIsDeadById(s16 character);
    extern void datSetUnitHp(s16 character, s16 value);
    extern void datCalcClearBadStatusById(s16 character, u32 mask);
    u32 partyIndex;
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
                /* Script context is opaque here; +0x148 supplies its shutdown-task handle. */
                KMisc_CreateScrShutdown(*(s32 *)(scrGetContext() + 0x148));
                sdlSchedulerEnable();
                iGpffffb3b0 = 1;
                goto block_13;
            }
            partyIndex = 0;
            goto loop_11_check;
loop_11_body:
            if (((s16)datGetPartyId((s32)partyIndex) != 0) &&
                (datCalcIsDeadById(datGetPartyId((s32)partyIndex)) != 0)) {
                datSetUnitHp(datGetPartyId((s32)partyIndex), 1);
                datCalcClearBadStatusById(datGetPartyId((s32)partyIndex), 0x80000);
            }
            partyIndex += 1;
loop_11_check:
            if (partyIndex < 3U) {
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


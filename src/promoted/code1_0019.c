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
typedef struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
} P4_95730_Vec3;
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
extern u32 datUnitInit(DatUnit *unit, u8 genus, u16 id);

extern void func_00106390(s32 arg0, s32 arg1);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void func_00489f80(void);
extern void func_0045c870(void *arg0, s32 arg1);
extern void func_0048a000(void);
extern f32 fGpffff8474;
extern void func_003c22f0(void *arg0);
extern u8 D_005F6CA0[];
extern f32 D_005F6C10[];
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern s32 btlActionAnyTargetHitRowFlagged(u8 *arg0);
extern s32 func_001f11e0(s16 arg0);
extern s32 datCalcSkillElement(u8 *arg0, u16 arg1);
extern u8 *iGpffffb3c0;
extern u8 *iGpffffb3cc;
extern s64 btlGetUID(void);

extern s64 scrGetParamInt(s32 arg0);
extern u8 *datUnitGetRecord(s16 arg0);
extern void datCalcSetUnitClass(u8 *arg0, s16 arg1);
extern s32 datCalcUnitClass(u8 *arg0);
extern void scrSetReturnInt(s32 arg0);

extern u8 *iGpffff9db0;
extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern s32 datGetPartyId(s32 arg0);
extern s32 datUnitCreatePc(s32 arg0);
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
extern void func_001b5f70(s32 arg0);
extern s32 func_00192610(u8 *task);
extern s32 func_001926c0(u8 *task);
extern s32 btlUpdateDraw2DTask(u8 *task);
extern s32 datCalcIsDead(u8 *arg0, s32 arg1);
extern s32 btlUnitReactToDeath(void);
extern s32 iGpffffb3b0;
extern s32 iGpffffb284;
extern s32 iGpffffb280;
extern s32 func_0029d020(void);
extern u8 *func_0029d040(void);
extern void datCalcIsDeadById(s16 arg0);
extern void func_001056e0(s16 arg0, s16 arg1);
extern void datCalcClearBadStatusById(s16 arg0, s32 arg1);
extern void KMisc_CreateScrShutdown(s32 arg0);
extern void sdlSchedulerEnable(void);
extern u8 iGpffffa0a0;
extern u8 D_005F6BE0[];
extern u8 D_007F17B0[];
extern void func_00440b68(void *msg, const void *file, s32 line);
extern s32 func_00454a60(s32 arg0, s32 arg1);
extern void H_Cdvd_ReadSync(s32 arg0);
extern s32 H_Cdvd_IsFileLoaded(s32 arg0);
extern void H_Cdvd_Destroy(s32 arg0);
typedef struct RwV3d RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter,
                         f32 *outTop, f32 *outBottom, u32 options);
extern void btlUnitGetGridSphereCenter(void *arg0, void *arg1);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern s32 btlUnitGetEntryPosition(u8 *arg0, f32 *arg1, s32 arg2);
extern u8 *btlActionGetActiveOrQueueFront(void);
extern void btlTargetBlendVectors(void *arg0, void *arg1, void *arg2);
extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
extern void btlUnitGetSphereCenterTowardTarget(void *arg0, void *arg1, void *arg2);
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
extern f32 func_0044b950(f32 x, f32 y);
extern f32 fGpffff8048;
extern void func_003dc740(void *dst, const void *src, s32 mode, f32 angle);
extern u8 D_0060A0E0[];
extern void btlUnitRequestLookAt(u8 *arg0);
extern P4_95730_Vec3 D_0060A100;
extern u8 *(*D_008873E8[])(s32 arg0, s32 arg1);
extern void btlTargetResetRadiusState(void);
extern void func_00194660(void);
extern void btlCameraInitSystem(void);
extern void btlSoundResetSlotQueue(void);
extern void btlVoiceResetPlaybackState(void);
extern void func_001d6a60(void);
extern void btlActionResetQueueState(void);
extern void func_001b60a0(void);
extern void btlSoundResetPlaybackState(void);
extern s32 itfMesWindowInstall(u8 *arg0);
extern s32 btlUnitLoadStep(u8 *task);

extern s32 btlUnitLoadBlocksFromFile(u8 *arg0, s32 arg1);
extern void func_0010d480(void);
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern void btlUnitOverridePacketUpdate(u8 *arg0);
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

extern f32 mdlGetLayerWeight(s32 arg0, s32 arg1);
extern void mdlSetLayerTime(void *arg0, s32 arg1, f32 arg2);
static inline void p4_call_00198920(s16 arg1, u8 *arg0, u16 arg2, f32 arg3, u16 arg4)
{
    func_00198920(arg0, arg1, arg2, arg3, arg4);
}
extern s32 func_0029db50(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
static inline void p4_call_0029db50(s32 arg2, s32 arg0, s32 arg1, s32 arg3)
{
    func_0029db50(arg0, arg1, arg2, arg3);
}
extern void MT_Scene_DestroyRes(u16 arg0);
extern void mdlDestroyModelObject(void *arg0);
extern void mdlSetColor(void *arg0, s32 *arg1);
extern void mdlSetLayerWeight(u8 *arg0, s32 arg1, f32 arg2);
extern u8 iGpffffa4d8;
extern void func_001d1540(u8 *arg0, s32 arg1, s32 arg2);
extern void btlTargetRemoveRadiusNode(u8 *arg0);
extern void btlEffectDestroyPlacementEntry(s32 arg0);
extern void btlEffectFreeNodePool(s32 arg0);
extern void btlPacketStep(u8 *arg0);
extern int mdlHasActiveMode(void *arg0);
extern void mdlSetLookAtActive(void *arg0);
extern void btlUnitUnlinkAndFree(u8 *arg0);
extern void mdlSetLookAtRequested(void *arg0);
extern u8 *resrcMngFindResById(u8 *arg0, u16 arg1);
extern void btlUnitApplyModelState(u8 *arg0, s32 arg1);
extern void mdlSetBattleStateFlag(void *arg0);
extern void mdlSetAlphaBlend(void *arg0);
extern void mdlSetLookStateWord(void *arg0, u16 arg1);
extern u16 mdlGetLookStateWord(void *arg0);
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern void mdlClearBattleStateFlag(void *arg0);
extern void mdlClearAlphaBlend(void *arg0);
extern void mdlSetBlendWeight(void *arg0, float arg1);
extern void mdlLookAtSetupSetRange(void *arg0, float arg1, float arg2);
extern f32 DAT_0076112c;


extern void btlUnitClearModelState(u8 *arg0, s32 arg1);
extern void btlUnitApplyModelState(u8 *arg0, s32 arg1);
extern u8 *func_001f7650(u8 *arg0);
extern void SceneDraw_SetResVisibleChecked(u16 arg0, u32 arg1);

extern u8 *btlUnitCreate(s32 arg0);
extern void btlUnitInitFromRecord(u8 *arg0, s32 arg1);



extern s32 btlUnitResourceFreePacketUpdate(u8 *arg0);
extern s32 func_0010d6d0(s16 arg0);
extern u8 *btlPacketAlloc(s32 arg0, s32 arg1);
extern float btlFormationGetScale(int arg0);
extern s32 btlUnitArcMovePacketUpdate(u8 *arg0);
extern s32 func_0010d740(s16 arg0);
extern u8 *datPersonaGetRow(u16 arg0);
extern s32 iGpffffb444;
extern s32 btlUnitIsMoving(u8 *arg0);
extern s32 btlUnitIdleAnimTick(u8 *arg0);
extern s32 datCalcIsStandardUnit(s32 arg0, s32 arg1);
extern u8 *btlUnitCreateLookAtPacket(u8 *arg0, f32 *arg1, s32 arg2);
extern s32 datCalcIsLowHp(u8 *arg0);
extern s32 datCalcIsStatusBlocked(s32 arg0);
extern void mdlSetLayerHandleFlag(void *arg0);
extern void mdlClearLayerHandleFlag(void *arg0);
extern u8 *btlUnitCreateAnimPacket(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);
extern u16 *datPersonaGetRecord(u16 character);
extern s32 datPersonaGetRosterSlot(s32 arg0);
extern void btlActionSetState(u8 *arg0, u32 arg1);
extern void func_001b08d0(void *arg0);
extern void btlActionSetUnit(u8 *arg0, u8 *arg1);
extern u8 *btlActionCreate(void);
extern s32 btlActionQueuePush(u8 *arg0);
extern s32 btlUnitApplyEncounterRoster(u8 *arg0);
extern s32 func_00243d80(u8 *arg0);
extern void btlUnitInitChild(u8 *arg0, u16 arg1);
extern void func_0019f1d0(u8 *arg0);

static inline void p4_call_0019ef30(u16 arg1, u8 *arg0)
{
    btlUnitInitChild(arg0, arg1);
}
extern void btlUnitHoldPendingLookAt(u8 *arg0);
extern s32 btlUnitLookAtSidePacketUpdate(u8 *arg0);
extern void btlUnitReleasePendingLookAt(u8 *arg0);
extern u8 *func_00457120(void);
extern s32 func_003e8120(u8 *arg0);
extern void func_003c1bd0(s32 arg0);
extern s32 func_003e8110(u8 *arg0);
extern u8 *kwlnTaskGetTaskByName(void *arg0);
extern void kwlnTaskDestroyWithHierarchy(s32 arg0);
extern s32 btlRelease(void);
extern void btlPacketFlushAll(void);
extern void btlUnitFreeRemovedUnits(void);
extern void datUnitFree(s32 arg0);
extern void func_003ef3a0(s32 arg0);
extern void (*jtbl_008873EC[])(void *arg0);
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 func_0018f950(u8 *task);
extern void btlEffectLoadFilesSync(void);
extern void btlUiRegisterAvailability(void);
extern void btlSoundLoadBanks(void);
extern void btlPanelLoadSync(void);
extern void mdlRunDataCallback(void *model);
extern s32 func_0047e6f0(void **owner);
extern void btlUnitUpdateLookAtTarget(u8 *arg0);
extern void hFadeTaskStart(s16 arg0);
extern s32 btlBossRemapSkillPair();
extern void btlUnitModelLoadPacketInit(u8 *arg0);
extern s32 btlUnitModelMotionPacketUpdate();
extern void func_001d6ee0(s32 arg0);
extern void btlUnitReleaseModel(u8 *arg0);
extern void btlUnitHideModel();
extern void btlUnitShowModel(u8 *arg0);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern void mdlQueueModelForDraw(void *arg0, void *arg1);
extern u8 D_00794150[];


extern s64 btlUnitGetMotionId(u8 *arg0, u16 arg1);
extern s16 btlUnitMotionFrames(u8 *arg0, u16 arg1, f32 fparg0);
extern void btlPacketStepSide(s32 arg0);
extern void func_00198920(u8 *arg0, s16 arg1, u16 arg2, f32 arg3, u16 arg4);
// FUN_001900A0
void func_001900a0(u8 *arg0)
{
    s32 *entries;
    s32 value;
    s32 i;

    entries = *(s32 **)(arg0 + 0x38);
    i = 0;
    while (i < 9) {
        value = p4_entries_001900a0(i * 4, entries)[1];
        if (value != 0) {
            func_003ef3a0(value);
        }
        i++;
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
// FUN_00190130
s32 func_00190130(s32 arg0)
{
    s32 *work;

    chkmemAllocSiteTag(D_005F6010, 0x184);
    work = (s32 *)D_008873F4[0](1, 0x1CD20, 0x40000);
    if (work == NULL) {
        return 0;
    }
    return (s32)kwlnTaskCreateChild((void *)((u8 *)arg0), (const void *)(D_005F6020), 0xF, 0, 0, func_0018f950, func_001900a0, (u8 *)(work));
}
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_propagation on




















#pragma opt_loop_invariants on
static inline u8 *search_58_10(u64 uid)
{
    u8 *node;
    u8 *btl;
    u32 i;
    u64 mask = (1ULL << 62) - 1;
    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        node = *(u8 **)(btl + i * 8 + 0x19C);
        while (node != NULL) {
            if (uid == (*(u64 *)(node + 0x58) & mask) && (*(u8 *)(node + 0x47) & 0x20) != 0) {
                return node;
            }
            node = *(u8 **)(node + 0x7C);
        }
        i++;
    }
    return NULL;
}
static inline u8 *search_60_10(u64 uid)
{
    u8 *node;
    u8 *btl;
    u32 i;
    u64 mask = (1ULL << 62) - 1;
    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        node = *(u8 **)(btl + i * 8 + 0x19C);
        while (node != NULL) {
            if (uid == (*(u64 *)(node + 0x60) & mask) && (*(u8 *)(node + 0x47) & 0x20) != 0) {
                return node;
            }
            node = *(u8 **)(node + 0x7C);
        }
        i++;
    }
    return NULL;
}
static inline u8 *search_40_10(u16 key)
{
    u8 *node;
    u8 *btl;
    u32 i;
    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        node = *(u8 **)(btl + i * 8 + 0x19C);
        while (node != NULL) {
            if (*(u16 *)(node + 0x40) == key && (*(u8 *)(node + 0x47) & 0x20) != 0) {
                return node;
            }
            node = *(u8 **)(node + 0x7C);
        }
        i++;
    }
    return NULL;
}
#pragma opt_loop_invariants off

#pragma optimization_level 1
#pragma optimization_level 2
#pragma opt_propagation off
#pragma opt_propagation on

static inline u32 packetListOffset(u32 offset, u32 base)
{
    return offset + base;
}


typedef struct {
    u8 *head;
    u8 *tail;
} PacketList;
extern s32 btlPacketWaitConditionMet(u8 *arg0, s32 arg1);


/* measured: opt_propagation off is scoped to func_001949d0. */
#pragma opt_propagation off

/* measured: closes opt_propagation for func_001949d0. */
#pragma opt_propagation on


#pragma optimization_level 1
#pragma optimization_level 2
#pragma opt_propagation off
#pragma opt_propagation on





extern void btlTargetResetWork(void *work);
extern s32 btlRouteFindPath(u8 *route, f32 *start, f32 *end, f32 radius);
extern s32 btlRouteBuildArc(u8 *route, const f32 *startXZ, const f32 *endXZ, const f32 *centerXZ);
extern f32 RwV3dNormalize(f32 *arg0, f32 *arg1);

#pragma opt_propagation off
#pragma opt_propagation on


extern s32 btlUnitGetMotionState(u8 *arg0);
extern u32 func_00198840(u8 *arg0);
extern u32 func_001988b0(u8 *arg0);
extern s64 btlUnitModelAnimFrame(u8 *arg0);
static inline u32 p4_add_index_base(u32 offset, u32 base)
{
    return offset + base;
}



typedef struct MotionTableEntry {
    s16 followMotion;
    s16 ratePercent;
    s16 followFrame;
    s16 unknown6;
    s16 nextMotion;
} MotionTableEntry;
static inline u16 motionModeFlags(u16 option)
{
    switch (option) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
        return 0;
    default:
        return 1;
    }
}
#pragma push
#pragma opt_propagation off
#pragma pop
#pragma opt_propagation off
#pragma opt_propagation on




#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma push
#pragma opt_propagation off
#pragma pop






















typedef struct BattlePacketRgba {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} BattlePacketRgba;

typedef struct BattleColorUnit {
    u8 unknown00[0x30];
    BattlePacketRgba color;
    u8 unknown34[0x64];
    u32 flags;
} BattleColorUnit;

typedef struct BattleColorPacket {
    BattleColorUnit *unit;
    u32 startColor;
    u32 targetColor;
    s16 alphaDuration;
    s16 rgbDuration;
    u8 mode;
    u8 flags;
    s16 counter;
} BattleColorPacket;

extern f32 fGpffff81f4;

/* Mirrors the actual color-by-value setter at 00194f60. */
static inline void battleColorPublish(BattleColorUnit *unit, BattlePacketRgba color)
{
    unit->color = color;
    unit->flags |= 4;
}

/* Packed-word/VU bridge, matching model_normalize_packed_color. C owns the
 * source words and packed output; the hardware computes all four color lanes.
 * The final 0x437f0000 bit pattern transfers the real 255.0f scale to VF2.x. */
static inline u32 battleColorBlendWords(const u32 *start, const u32 *target, f32 factor)
{
    u32 targetColor;
    u32 startColor;
    u32 packedColor;
    const u32 *source;
    f32 scale;
    f32 inverse;
    u32 bits;

    targetColor = *target;
    source = &targetColor;
    scale = fGpffff81f4;
    {
        u32 bits;
        __asm__ volatile(
            "lw $2, 0(%1)\n"
            "pextlb $2, $zero, $2\n"
            "pextlh $2, $zero, $2\n"
            "qmtc2 $2, $vf11\n"
            "vitof0.xyzw $vf11, $vf11\n"
            "mfc1 %0, %2\n"
            "nop\n"
            "qmtc2 %0, $vf2\n"
            "vmulx.xyzw $vf11, $vf11, $vf2x\n"
            : "=&r"(bits)
            : "r"(source), "f"(scale), "m"(*source)
            : "$2", "$vf2", "$vf11", "memory");
    }
    startColor = *start;
    source = &startColor;
    {
        u32 bits;
        __asm__ volatile(
            "lw $2, 0(%1)\n"
            "pextlb $2, $zero, $2\n"
            "pextlh $2, $zero, $2\n"
            "qmtc2 $2, $vf10\n"
            "vitof0.xyzw $vf10, $vf10\n"
            "mfc1 %0, %2\n"
            "nop\n"
            "qmtc2 %0, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            : "=&r"(bits)
            : "r"(source), "f"(scale), "m"(*source)
            : "$2", "$vf2", "$vf10", "memory");
    }
    inverse = 1.0f - factor;
    {
        u32 bits;
        __asm__ volatile(
            "mfc1 %0, %1\n"
            "nop\n"
            "qmtc2 %0, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "mfc1 %0, %2\n"
            "nop\n"
            "qmtc2 %0, $vf2\n"
            "vmulx.xyzw $vf11, $vf11, $vf2x\n"
            "vadd.xyzw $vf10, $vf10, $vf11\n"
            : "=&r"(bits)
            : "f"(inverse), "f"(factor)
            : "$vf2", "$vf10", "$vf11", "memory");
    }
    bits = 0x437F0000U;
    __asm__ volatile(
        "qmtc2 %0, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "vftoi0.xyzw $vf10, $vf10\n"
        "qmfc2 %0, $vf10\n"
        "ppach %0, $zero, %0\n"
        "ppacb %0, $zero, %0\n"
        "sw %0, packedColor\n"
        : "+r"(bits), "=m"(packedColor)
        : : "$vf2", "$vf10", "memory");
    return packedColor;
}

#pragma push
#pragma opt_propagation off

#pragma pop











/* Retail reloads the 1/255 colour scale (0x3B808081, written here as a
 * literal) for every factor; with default optimisation b210 does the same.
 * `v41` and `chk` are function-scope locals so they keep retail's saved
 * registers. On the `i == 2 && alpha < 0xFE` path retail compares 0xE8
 * against the `mode` left from an earlier entry (0x0019CDE0); the C reads
 * `mode` uninitialised there in the same way. */
#pragma push
typedef struct { u8 r, g, b, a; } Col4_0019;
typedef struct {
    f32 right[3];
    s32 flags;
    f32 up[3];
    s32 pad1;
    f32 at[3];
    s32 pad2;
    f32 pos[3];
    s32 pad3;
} Mtx_0019;

static inline void colMul_0019(Col4_0019 *dst, const u8 *src)
{
    f32 scale;
    f32 bias;
    f32 g = (0.003921569f * (f32)(u32)dst->g) * (0.003921569f * (f32)(u32)src[1]);
    f32 b = (0.003921569f * (f32)(u32)dst->b) * (0.003921569f * (f32)(u32)src[2]);
    f32 a = (0.003921569f * (f32)(u32)dst->a) * (0.003921569f * (f32)(u32)src[3]);
    f32 r = (0.003921569f * (f32)(u32)dst->r) * (0.003921569f * (f32)(u32)src[0]);

    scale = 255.0f;
    bias = 0.5f;
    dst->r = (s32)(scale * r + bias);
    dst->g = (s32)(scale * g + bias);
    dst->b = (s32)(scale * b + bias);
    dst->a = (s32)(scale * a + bias);
}

#pragma pop






#pragma push
#pragma opt_propagation off
#pragma pop


#pragma opt_propagation off
#pragma opt_propagation on

#pragma push
#pragma opt_propagation off
#pragma opt_rebuildconditionals off
#pragma opt_common_subs off

#pragma pop
#pragma push
#pragma opt_propagation off
#pragma pop
#pragma opt_propagation off
#pragma opt_propagation on

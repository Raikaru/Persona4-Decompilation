#include "datCalc_unit_internal.h"
#include "btl_equipment_count_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "btl_cond_internal.h"
typedef struct BtlPacket BtlPacket;
typedef signed __int128 s128;
typedef struct P4Vec4_001EC2B0 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} P4Vec4_001EC2B0;
typedef struct P4Vec4Holder_001EC2B0 {
    P4Vec4_001EC2B0 quat;
} P4Vec4Holder_001EC2B0;
typedef struct P4RouteSlerp_001EF110 {
    P4Vec4_001EC2B0 first;
    P4Vec4_001EC2B0 second;
    f32 angle;
    s32 mode;
} P4RouteSlerp_001EF110;
extern void btlCameraLookAtQuat(void *out, const void *first,
                          const void *second, const void *up);
extern f32 RwV3dLength(f32 *vector);
extern void func_003dcc70(const void *first, const void *second, void *result);
extern void *RtQuatTransformVectors(void *out, const void *in, s32 count, const void *rotation);
extern f32 sqrtf(f32 arg0);
extern u8 *btlActionFindById();
extern void *D_00609850[];
extern s32 datCalcMaxHp();
extern s64 scrGetParamInt();
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
extern s32 scrGetParamIntS32(s32 index);
static inline u8 *p4_slot_001eb320(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}
extern s32 datCalcGetHp();
extern u16 datCalcMaxSp();
extern s32 datCalcGetSp();

extern s32 datCalcSkillElement(u8 *unit, u16 skill);
extern u32 datCalcGetTableLength(u8 *arg0);
extern s32 datCalcThresholdTrigger(u8 *unit, s32 skill);
extern s32 datCalcDefaultSkillId(u8 *unit);
extern s32 datCalcAilmentChance(u8 *arg0, s32 arg1);
extern u8 *btlActionGetActiveOrQueueFront(void);
extern u8 *scrGetAiState();

extern void memset(void *destination, s32 value, u32 size);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern void btlEncounterEntrySetRetracted(s32 task);
extern void btlEncounterEntryClearRetracted(s32 task);
extern s32 func_001eb860(void);
extern void btlDamageSetSource(u8 *arg0, s32 arg1);
extern void btlDamageEndPhase(s32 task);
extern s32 btlCurrentUnitId(void);
extern s32 D_00724504;
extern void func_001eb7f0(void);
extern s32 func_001eb860(void);
extern void btlActionFinishPresentation(s32 arg0);
extern BtlPacket *btlFormationCreateSlotPacket(u16 arg0, u16 arg1);
extern u8 *btlCameraCreateSetStatePacket(s32 arg0, s32 arg1);
extern s32 btlAICommandSelectCandidates();
extern u32 datCalcRandomBelow(u32 arg0);
extern u8 *btlEffectFindUnitByIdAndStatus();
extern u8 *btlEffectFindUnitByKey();
extern u8 *btlAICommandPickUnitByHpWeight();
extern s32 btlAICommandCollectSkillCandidates();
extern s32 btlAICommandCollectCommandsOfType();
extern s32 btlSideSelectUnits();
extern s32 btlAICommandAlwaysTrue(void);


extern void btlPacketEnqueue(u8 *arg0, s32 arg1);
extern u8 *btlTargetCreateEmptyPacket(void);
extern u8 *func_001f6030(s32 arg0, s64 arg1);
extern s32 btlUnitRecordFindByUID(s64 arg0, s64 arg1);
extern void func_003dc740(void *arg0, void *arg1, f32 arg3, s32 arg2);
extern f32 func_0044b950(f32 arg0, f32 arg1);
extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern f32 D_00761430;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff8060;
extern f32 D_00761438;


extern u8 *btlActionGetQueueSecond(void);
extern void btlTargetResetRecordCounter(u8 *arg0);
extern u32 datCalcRandomBelow(u32 arg0);



extern void btlUnitInitChild(u8 *arg0, u64 arg1);
extern void btlAICommandSetActionCode(u8 *arg0, u8 *arg1, u16 arg2);
extern s32 btlAICommandPickTableAction(u8 *arg0);
extern u8 *btlAISelectWeightedEntry(u8 *arg0, u32 arg1);
extern void *D_00609CE0[];
extern void *D_00609D20[];
extern f32 scrGetParamFloat(s32 arg0);
extern f32 D_00881400[];
extern f32 D_00881404[];
extern f32 D_00881408[];
extern f32 D_00881420[];
extern f32 D_00881424[];
extern f32 D_00881428[];
extern f32 fGpffffb458;
extern u8 *iGpffffb3b8;
extern void kAssertFail(void *arg0, s32 arg1);
extern u8 D_00609E30[];
extern f32 D_008813F0[];
extern f32 D_008813F4[];
extern f32 D_008813F8[];
extern f32 D_00881410[];
extern f32 D_00881414[];
extern f32 D_00881418[];
extern f32 fGpffffb454;
extern u8 *btlCameraCreatePoseSequencePacket(s32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 arg6, f32 arg7);
extern BtlPacket *btlBossCreateStepEndBgmPacket(void);
extern u8 *btlSoundCreateStreamPacket(s32 arg0, void *arg1);
extern void sprintf(void *arg0, void *arg1, s64 arg2);
extern u8 D_00609E40[];
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern s32 datCalcGetBattleStat(s32 arg0, s32 arg1);
extern s32 datCalcGetHp(s32 arg0);
extern s32 datCalcIsDead(s32 arg0, s32 arg1);
extern s32 datGetFlag(s32 arg0);
extern s32 btlUnitFindInSideById(s32 arg0, s32 arg1);
extern s32 btlActionFindByUnit(s32 arg0);
extern void func_001fae60(s32 initialize, s32 update, s32 packet);
extern void btlActionRunFormationSequence(u8 *action);
extern s32 btlEncounterFinishSetup(u8 *action);
extern void btlAICommandSpawnActionProc(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
extern s32 kwlnTaskIsLinked(s32 arg0);
extern u8 *btlPacketAlloc(s32 arg0, s32 arg1);
extern u8 *btlFormationGetRecord(s32 arg0);
extern s32 scrFindPrcdIdxByName(s32 arg0, s32 arg1);
extern s32 btlTargetSpawnActionProc(u8 *arg0);
extern u8 *iGpffffb428;
extern u16 cmmCommunityRecordValue(s32 arg0);
extern void func_00106550(s32 arg0, s32 arg1);
extern s32 datCalcIsStatusBlocked(u16 *arg0);
extern u16 cmmCommunityForArcana(s64 arg0);
extern u8 *iGpffffb42c;
extern s32 btlAiSetGlobal(void);
// FUN_001E6B90
s32 func_001e6b90(void) {
    u32 a = scrGetParamIntS32(0);
    u32 b = scrGetParamIntS32(1);
    u8 *p = btlActionFindById(a & 0xFFFFFFF);
    u32 v = (b & 0xFFFFFF) | 0x48000000;
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = (b | 0x48000000) & 0xFFFFFF;
    s32 x;

    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}
// FUN_001E6C60
s32 func_001e6c60(void) {
    u8 *temp_2;
    u32 index;

    temp_2 = scrGetAiState();
    if ((btlSkillClassifyTargets(temp_2, 0, *(u16 *)(temp_2 + 0x6E), 0) & 0xFFFF) == 0) {
        index = scrGetParamIntS32(0);
        *(u8 **)(temp_2 + 0x38) = btlActionFindById(index & 0xFFFFFFF);
        *(s16 *)(temp_2 + 0x6A) = 1;
    } else if (((s32 (*)(u8 *, s32))D_00609CE0[0])(temp_2, 0) == 0) {
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(temp_2, 0);
    }
    return 1;
}

// FUN_001E6FA0
s32 func_001e6fa0(void) {
    u16 count;
    u8 *work;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0x100000, 0x2E, 0, &btlCond_MYWEAK) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            scrSetReturnInt(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}
// FUN_001E7080
s32 func_001e7080(void) {
    u16 count;
    u8 *work;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2F, 0, &btlCond_MYWEAK) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            scrSetReturnInt(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}
// FUN_001E7160
s32 func_001e7160(void) {
    u16 count;
    u8 *work;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            scrSetReturnInt(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}
// FUN_001E7240
s32 func_001e7240(void) {
    u16 count;
    u8 *work;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0x100000, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            scrSetReturnInt(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}
// FUN_001E7320
s32 func_001e7320(void)
{
    int count;
    u8 *work;
    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2D, 0, &btlCond_MYNOMAL) == 1)
    {
        count = *(u16 *)(work + 0x6A);
        if (count == 1)
        {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        }
        else
        {
            scrSetReturnInt(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    }
    else
    {
        scrSetReturnInt(-1);
    }
    return 1;
}
#pragma push
#pragma opt_rebuildconditionals off
static inline u16 p4_formation_get_opposing_genus(u32 unit)
{
    u32 side;
    if (*(u8 *)(*(s32 *)(unit + 0x30) + 0xA2) != 0)
        goto nonzero;
    side = 1;
    goto done;
nonzero:
    side = 0;
done:
    return side;
}
#pragma pop













// FUN_001E8BB0
s32 func_001e8bb0(void) {
    u64 temp_16;
    u64 temp_17;
    u8 *temp_19;
    u64 temp_18;

    temp_19 = scrGetAiState();
    temp_17 = scrGetParamInt(0);
    temp_16 = scrGetParamInt(1);
    temp_18 = scrGetParamInt(2);
    scrSetReturnInt(btlAICommandCollectCommandsOfType(temp_19, btlActionFindById((u64)(temp_17 << 0x24) >> 0x24), (s16)temp_16, temp_18));
    return 1;
}

// FUN_001E8CD0
s32 func_001e8cd0(void) {
    u64 temp_16;
    u8 *temp_19;
    u64 temp_18;
    u64 temp_17;

    temp_19 = scrGetAiState();
    temp_16 = scrGetParamInt(0);
    temp_18 = scrGetParamInt(1);
    temp_17 = scrGetParamInt(2);
    scrSetReturnInt(btlAICommandCollectSkillCandidates(temp_19, btlActionFindById((u64)(temp_16 << 0x24) >> 0x24), temp_18, temp_17));
    return 1;
}



// FUN_001EA2D0
s32 func_001ea2d0(void) {
    u64 temp_16;
    u8 *temp_18;
    u64 temp_17;

    temp_18 = scrGetAiState();
    temp_17 = scrGetParamInt(0);
    temp_16 = scrGetParamInt(1);
    btlUnitInitChild(*(u8 **)(temp_18 + 0x30), temp_17);
    btlAICommandSetActionCode(temp_18, temp_18 + 0x38, temp_16 & 0xFFFF);
    return 1;
}








#pragma push
#pragma opt_rebuildconditionals off
#pragma pop
#pragma push
#pragma opt_rebuildconditionals off
#pragma pop

/* measured: the typed call view removes the dead s64 narrowing pair; the
   volatile gp load and offset helper reproduce retail's load/shift/addu order. */



#pragma optimization_level 1
#pragma optimization_level 2
#pragma opt_propagation off
/* measured: closes opt_propagation probe for btlAiSetGlobal. */
#pragma opt_propagation on



#pragma opt_common_subs off
#pragma opt_common_subs on
#pragma opt_propagation off
#pragma opt_propagation on
typedef struct P4NeighborNode {
    s32 unknown0;
    s32 unknown4;
    f32 x;
    f32 z;
    f32 unknown10;
    f32 active;
    f32 clearance;
    u8 rest[0x114];
} P4NeighborNode;
typedef struct P4NeighborGroup {
    s32 unknown0;
    s32 unknown4;
    P4NeighborNode nodes[4];
    struct P4NeighborGroup *previous;
    struct P4NeighborGroup *next;
} P4NeighborGroup;
extern s32 btlTargetRangeCheck(u8 *first, u8 *second);
extern f32 RwV2dLength(f32 *vector);
typedef struct P4NeighborWorld {
    u8 prefix[0x318];
    P4NeighborGroup *groups;
    P4NeighborNode nodes[4];
    P4NeighborNode start;
    P4NeighborNode goal;
} P4NeighborWorld;

/* Field-group corner layout: bounding corners over the group list, then each
 * group corner and each world corner is linked to its nearest neighbour.
 * Matching notes: the bounding loop reuses `group` and the last search reuses
 * `other`; the z of each stack pair is read after the list head
 * (`curZ = cur[1]` / `wposZ = wpos[1]`) so b210 reloads it; tests with the
 * local on the left are spelled `corners[n].x <= tx` (branch through $at);
 * `(float *)(entry += 8)` keeps the advanced pointer in $s7; and a
 * block-scoped `base = iGpffffb3ac` orders the global load before the
 * index arithmetic. The pragmas are measured: without opt_loop_invariants
 * the D_0060A120 row address and the 7000.0f bound are not hoisted (432
 * edits), and without opt_lifetimes the loop locals share registers (205). */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
#pragma opt_dead_assignments off
#pragma pop
extern s32 btlTargetLineClear(f32 *first, f32 *second, f32 margin);
extern void btlTargetRebuildRadiusLinks(f32 radius);
extern s32 btlTargetBuildSmoothRoute(u8 *route, f32 radius);

typedef struct RoutePoint {
    f32 x;
    f32 z;
} RoutePoint;

typedef struct RouteNode {
    u8 unknown00[8];
    RoutePoint pos;
    u8 unknown10[0xC];
    f32 g;
    f32 f;
    struct RouteNode *openNext;
    struct RouteNode *closedNext;
    struct RouteNode *parent;
    struct RouteNode *neighbors[32];
    f32 distances[32];
} RouteNode;

#pragma push
#pragma opt_loop_invariants on
#pragma pop

/* Retail indexes the neighbour and distance arrays as base + index * 4 + field. */
#define ROUTE_NEIGHBOR(n, i) (*(RouteNode **)((u8 *)(n) + (i) * 4 + 0x30))
#define ROUTE_DISTANCE(n, i) (*(f32 *)((u8 *)(n) + (i) * 4 + 0xB0))

static inline s32 routeInOpenList(RouteNode *scan, RouteNode *node)
{
    for (; scan != NULL; scan = scan->openNext) {
        if (scan == node) {
            return 1;
        }
    }
    return 0;
}

static inline s32 routeInClosedList(RouteNode *scan, RouteNode *node)
{
    for (; scan != NULL; scan = scan->closedNext) {
        if (scan == node) {
            return 1;
        }
    }
    return 0;
}

#pragma push
#pragma opt_propagation off

#pragma pop
#pragma opt_common_subs off
#pragma opt_common_subs on
#pragma opt_common_subs off
#pragma opt_common_subs on

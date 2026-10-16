#include "list_item_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
#include "btl_motion_internal.h"
#include "effect_instance_internal.h"

#include "include_asm.h"
#include "type.h"
#include "btl_target_state_packet_internal.h"
#include "btl_action_internal.h"
typedef struct BtlPacket BtlPacket;
extern BtlPacket *btlFormationCreateNamedPacket(u32 formation, const char *text, u16 mode);
u32 datCalcRandomBelow(u32 bound);
typedef struct BtlTarget BtlTarget;
extern BtlPacket *btlUnitCreateLookAtDeactivatePacket(BtlUnit *unit, u16 flags);
extern BtlPacket *btlUnitCreateAnimPacket(BtlUnit *unit, s16 id, u16 blendFrames, f32 speed, u16 mode);

/* Existing byte-view callers use these adapters to the provider definitions. */
extern BtlPacket *btlTargetCreateTargetPacket(u32 action, u16 kind, u32 a, u32 b, u32 c);
static inline u8 *actionTargetPacketBytes(u8 *action, u16 kind, u32 a, u32 b, u32 c)
{
    return (u8 *)btlTargetCreateTargetPacket((u32)action, kind, a, b, c);
}
extern void btlActionSetStateWithDelay(BtlAction *action, u16 state, u16 delay);
static inline void actionSetDelayBytes(u8 *action, s32 state, s32 delay)
{
    btlActionSetStateWithDelay((BtlAction *)action, (u16)state, (u16)delay);
}
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rot, u32 flags);
static inline u8 *actionRotatePacketBytes(u8 *unit, void *rot, s32 flags)
{
    return (u8 *)btlUnitCreateRotatePacket((BtlUnit *)unit, (const RwV3d *)rot, (u32)flags);
}
extern BtlPacket *btlUnitCreateMotionSettlePacket(BtlUnit *unit);
static inline u8 *actionRecoveryPacketBytes(BtlUnit *unit)
{
    return (u8 *)btlUnitCreateMotionSettlePacket(unit);
}
extern BtlPacket *btlPacketCreateEffectCounter(s32 unit, s32 message);
static inline void *actionMessagePacketBytes(s32 unit, s32 message)
{
    return btlPacketCreateEffectCounter(unit, message);
}
extern BtlPacket *btlVoiceCreatePacket(BtlAction *action, u16 cue, s32 unitId, s32 a, s32 b);
extern void func_00194ff0(u8 *, u8 *, f32 *, f32 *);
extern f32 btlTargetVectorDistance(const RwV3d *, const RwV3d *);
extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *, const RwV3d *, f32, u32);
extern u8 *iGpffffb3cc;
extern f32 D_005F6D20[];

void btlActionSetState(BtlAction *action, u16 state);
u8 *func_00193bf0(u64 arg0, u64 arg1);
static inline s32 func_001a_add_offset(s32 offset, s32 base)
{
    return offset + base;
}
static inline s32 func_001a_fix_var(s32 value)
{
    if (value == 0) {
        value = -1;
    }
    return value;
}
void func_001f6cd0(void);

void func_001f14f0(u8 *arg0);
void func_001eb3b0(u8 *arg0);
extern void func_001d7c60(u8 *arg0, u8 *arg1, u32 arg2, u32 arg3, u32 arg4);
void func_001d8cb0(void *arg0, void *arg1);

s32 btlUnitIsMoving(u8 *arg0);

void btlActionFinishPresentation(BtlAction *action);
void btlAICommandPickAiTarget(void *arg0, s32 arg1);
BtlPacket *btlFormationCreateSlotPacket(u16 arg0, u16 arg1);
s64 btlPacketEnqueue(u8 *arg0, u32 arg1);

extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;
extern void func_001eb4a0(u8 *arg0, u8 *arg1, u32 status);
extern s32 func_001f6930(u8 *arg0);
extern s32 func_001f6bf0(u8 *arg0);
extern s32 func_001f6f60(u8 *arg0);
extern s32 func_001f7140(u8 *arg0);
extern void func_001f62b0(void);
extern s32 func_001f62f0(u8 *arg0);
extern void func_001f86d0(void);
extern void func_001f9a50(s32 arg0, s32 arg1);
extern void func_001f9a90(void);
extern void func_00213bb0(s32 arg0);
extern void func_00213be0(s32 arg0);
extern void btlMessageSetup(u8 *arg0, u8 *arg1);
extern s32 btlMessageIsIdle(s32 arg0);
extern void btlMessageSetPendingValue(u8 *arg0, s32 arg1);
extern void btlMessageSetDone(s32 arg0);
extern void btlMessageSetHidden(s32 arg0);
extern u8 *func_0019bbe0(u8 *arg0, u32 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5);
extern u8 *btlUnitCreateShowPacket(u8 *arg0);
extern u8 *btlUnitCreateHidePacket(u8 *arg0);
extern u16 btlSelectionGetTargetMark(s32 task);
extern u32 btlEffectCollectGenusMask(s32 formation);
extern void btlSelectionResetUnitFlags(s32 arg0);
extern u32 btlSelectionGetFormationEntryAlt(s32 task);
extern u32 btlSelectionGetFormationEntry(s32 task);
extern s32 func_001faf70(u8 *arg0, s32 arg1, s32 arg2);
extern void btlSelectionClearTargetMark(s32 arg0);
extern void func_00203880(s32 arg0, s32 arg1);
extern BtlPacket *btlUnitCreateModelReleasePacket(BtlUnit *unit);
BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);
u32 func_001deeb0(void *arg0);
void btlAICommandSetUnitAction();
u32 btlAICommandTryReleaseProc();
s32 datCalcDefaultSkillId(u8 *unit);
u32 func_001d8bc0(void *arg0);
void func_001d8be0(s32 formation, u64 *unit);

extern u8 *iGpffffb3b8;
void func_001d8e50(u8 *arg0, u8 *arg1);
void btlSelectionMarkTargets(s32 arg0, u8 *arg1, u8 *arg2, s16 arg3);
extern void btlDamageSetActive(s32 task);
void btlUnitRequestLookAtOthers(u8 *arg0);
u8 func_0023e1f0(u8 *unitData);
extern BtlPacket *btlUnitCreateLookAtUnitPacket(BtlUnit *unit, BtlUnit *target, u16 flags);
static inline u8 *actionLookAtUnit(u8 *unit, u8 *target, s32 flags)
{
    return (u8 *)btlUnitCreateLookAtUnitPacket((BtlUnit *)unit, (BtlUnit *)target, (u16)flags);
}
u8 *btlUnitCreateMotionRequestPacket(u8 *arg0, u16 arg1);
extern void func_001eb410(u8 *arg0);
extern BtlPacket *btlUnitCreateMoveToUnitPacket(BtlUnit *unit, BtlUnit *target, f32 distance, f32 speed, u32 flags);
extern BtlPacket *btlFormationCreateWaitPacket(u32 source, u32 target, u16 mode);
extern f32 fGpffff811c;
extern u32 datCalcGetBadStatus(s32 arg0);
extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 kind, s16 value);
extern void func_001f0a10(u8 *arg0);
extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
extern u8 *btlPacketCreateHpRatio(u8 *arg0);
extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
u8 *func_00194b60(void);
extern BtlPacket *btlFormationCreateReturnPacket(u16 arg0);
BtlPacket *btlMainCreateColorSetPacket(s32 arg0);
BtlPacket *btlEffectCreateReleasePacket(u16 mode);
u8 *btlPacketCreateFinishEffect(void);
u32 datCalcIsDead(s32 unit, s32 hpDelta);
extern s32 datCalcAilmentChance(u8 *unit, s32 element);
u8 *func_001fa720(const void *data);
s32 func_001eb860(void);
extern void btlMessageInstallWindow(s32 task, u8 *arg1);
u8 *func_001fa8f0(void);
extern s32 btlMessageIsActiveAlt2(s32 task);
extern s32 btlMessageGetResultAlt2(s32 task);
u8 *func_001faa60(void);
extern void btlMessageRelease(s32 task);
extern void btlDamageSetSource(u8 *arg0, s32 arg1);
s32 func_0019ff60(u8 *arg0);
s64 *func_001b1540(void);
s32 func_001d94d0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                  s32 (*arg5)(u8 *arg0, s64 arg1));
s32 func_001f01a0(u8 *arg0, u8 *arg1);
s32 datCalcSkillElement(u8 *arg0, u16 arg1);
u8 *func_001fa9c0(void);
s32 btlAICommandNomalStatusCheck(u8 *arg0, s64 arg1);
u32 btlCountUnitRecordsById(u32 arg0);
u8 *btlCutinCreatePacket(u8 *arg0);
extern void btlMessageStartLong(u8 *arg0, u8 *arg1);
u8 *btlUnitCreateRotateTowardUnitPacket(u8 *arg0, u8 *arg1, s32 arg2);
u8 *btlPacketAllocZeroed(s32 arg0, s32 arg1);
u8 *func_001d65d0(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4);
extern s32 btlMessageIsActiveAlt(s32 task);
extern s32 btlMessageGetResultAlt(s32 task);
u8 *func_001f99c0(u8 *arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4);
u8 *btlCutinCreateEndPacket(void);
u8 *btlCutinCreateStartPacket(void);
u8 *btlFormationCreateDefaultPacket(void);
extern void btlMessageResetAlt(s32 task);
s16 func_001d15a0(void);
s32 btlSideCountNotBad(s32 arg0, s32 arg1);
u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
s64 datCalcFindStrongBuff(u8 *arg0);
s32 func_001f6770(u8 *arg0);
s32 btlActionGetCounter420(BtlAction *action);

u8 *btlPacketCreateSpriteTable(u32 arg0, u16 arg1);
s32 datPersonaSelectRosterMemberById(s32 arg0);
extern void btlUnitInitChild(u8 *arg0, u16 arg1);
extern void datPersonaRemoveSelectedRosterMember(void);
extern s32 datGetFlag(s32 arg0);
BtlPacket *btlFormationCreatePacket(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
BtlPacket *btlSoundCreateChannelCuePacket(u16 arg0, u16 arg1, u16 arg2);
extern f32 D_0076144C;

/* Source unit: src/promoted/code1_001a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001a.c; members 001a1450-001adb80 */

extern s32 func_001a0140(u8 *arg0);
extern void func_001a0290(BtlAction *action, u16 arg1, u8 *arg2);
extern void btlActionFinishPresentation(BtlAction *action);
extern s32 func_001a05f0(BtlAction *action);
static inline void actionCopySelectedTarget(u8 *action, const u16 *index)
{
    u8 *slot = action + *index * 4;
    *(u8 **)(slot + 0x38) = *(u8 **)(slot + 0x98);
}
static inline u8 *actionSelectionOffset(u32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
typedef struct ActionRecoveryResourceView {
    u8 beforeResources[0xD04];
    u32 resources[0x30];
} ActionRecoveryResourceView;
static inline u32 actionRecoveryResourceAt(
    const ActionRecoveryResourceView *snappedBase, s32 signedSlot)
{
    return snappedBase->resources[signedSlot];
}
static inline u8 *actionReadCandidate(u8 *action, const u16 *index)
{
    return *(u8 **)(action + 0x98 + *index * 4);
}
typedef struct ActionState001a4800 {
    u8 pad0[0x1A];
    u16 kind;
    u8 pad1C[0x290 - 0x1C];
    u16 flags;
} ActionState001a4800;
static inline u8 *btlHitResult_001a59a0(u8 *action, const u16 *index)
{
    return action + (u32)*index * 0x20 + 0xF0;
}
static inline s16 btlCameraField_001a59a0(u16 unitId, s16 *firstField)
{
    return *(s16 *)((u8 *)firstField + (u16)unitId * 0xE8);
}
static inline s32 btlCloseCamera_001a59a0(u8 *unit, s32 noPartner)
{
    extern u8 *iGpffffb3bc;
    extern u8 *iGpffffb3cc;
    u8 *ctx = *(u8 **)(unit + 0xA64);
    u16 unitId = *(u16 *)(ctx + 2);
    s32 result;

    switch (*(u8 *)(unit + 0xA2)) {
    case 0:
        {
            s32 state = func_0023e1f0(ctx) & 0xFF;

            if (state == 5) {
                result = 1;
                break;
            }
            if (state != 3) {
                goto fail;
            }
            if (!(*(u16 *)(iGpffffb3bc + 2) & 0x8000) && noPartner != 0) {
                goto fail;
            }
            result = 1;
        }
        break;
    case 1:
        if (btlCameraField_001a59a0(unitId, (s16 *)(iGpffffb3cc + 0x22)) == 1) {
            result = 1;
        } else {
            goto fail;
        }
        break;
    default:
    fail:
        result = 0;
        break;
    }
    return result;
}
static inline s64 btlPacketUID_001a59a0(u8 *packet)
{
    return *(s64 *)(packet + 0x58);
}
static inline u8 btlUnitKind_001a59a0(u8 *unit)
{
    return unit[0xA2];
}
static inline s32 btlEffectDelay_001a7720(s32 frames)
{
    s32 delay;
    delay = frames + 6;
    return delay;
}
static inline u8 *btlHitRow_001a7720(u8 *action, const u16 *index)
{
    return action + (*index << 5);
}
typedef struct ActionResourcePrefix {
    u8 beforeResources[0xD04];
    s32 resources[0x22];
} ActionResourcePrefix;
static inline s32 actionResourceAt(ActionResourcePrefix *table, u16 index)
{
    return table->resources[index];
}
/* measured: loop-invariant probe for 001A0140 preheader materialization. */
/* measured: close loop-invariant probe for 001A0140. */
#pragma push
#pragma pop
/* measured: opt_propagation off plus one named local per address term. mwcc
   keeps source operand order for `named + named` (addu off,base / addu idx,sum
   as retail) but commutes an inline product on the left (`a * k + b` emits
   addu b,a*k); the table base must be copied first so its lw leads the block. */
/* measured: restore propagation for the rest of the unit. */
// FUN_001A1450
void btlActionCommandInit(s64 *arg0)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    } sp40;
    struct Vec3 sp30;
    u16 actionType;
    u16 actionTypeAfter;
    u8 *rotatePacket;
    u8 *rotatePacketB;
    u8 *ambientPacket;
    u8 *targetPacket;
    u8 *lookAtPacket;
    u8 *lookAtDeactivatePacket;
    u8 *cameraPacket;
    u8 *listUnit;
    u8 *listUnit2;

    extern void btlUnitGetGridSphereCenter(u8 *arg0, f32 *arg1);
    extern s32 btlUnitIsMoving(u8 *arg0);

    extern void btlPacketEnqueue(u8 *arg0, s32 arg1);
    extern void btlPanelInit(s32 arg0, u8 *arg1);
    extern void func_00213c10(s32 task);

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) &&
        (*(u16 *)((u8 *)arg0 + 0x1A) & 1) &&
        (*(u8 **)((u8 *)arg0 + 0x30))[0xA2] == 0) {
        btlActionSetState((BtlAction *)arg0, 9);
        return;
    }
    btlActionFinishPresentation((BtlAction *)arg0);
    actionType = *(u16 *)((u8 *)arg0 + 0x10);
    if ((actionType != 0x25) && (actionType != 4) && (actionType != 6) &&
        (actionType != 5) && (*(u16 *)(iGpffffb3ac + 0xF4) != 2)) {
        func_00194ff0(
            *(u8 **)((u8 *)arg0 + 0x30), NULL, 0, (f32 *)&sp40);
        listUnit = *(u8 **)(iGpffffb3ac + 0x17C);
        goto loop_14_test;
loop_14_body:
        if (datCalcChkBadStatus((s32)*(u8 **)(listUnit + 0xA64), 0x100) != 0) {
            btlUnitGetGridSphereCenter(
                *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30),
                (f32 *)&sp30);
        } else {
            sp30 = sp40;
        }
        rotatePacket = actionRotatePacketBytes(listUnit, &sp30, 2);
        *(s64 *)(rotatePacket + 0x60) = *arg0;
        btlPacketEnqueue(rotatePacket, 0);
        listUnit = *(u8 **)(listUnit + 0xA68);
loop_14_test:
        if (listUnit != NULL) {
            goto loop_14_body;
        }
        listUnit2 = *(u8 **)(iGpffffb3ac + 0x184);
        goto loop_19_test;
loop_19_body:
        if (btlUnitIsMoving(listUnit2) == 0) {
            func_00194ff0(listUnit2, NULL, 0, (f32 *)&sp40);
            rotatePacketB = actionRotatePacketBytes(listUnit2, &sp40, 2);
            *(s64 *)(rotatePacketB + 0x60) = *arg0;
            btlPacketEnqueue(rotatePacketB, 0);
        }
        listUnit2 = *(u8 **)(listUnit2 + 0xA68);
loop_19_test:
        if (listUnit2 != NULL) {
            goto loop_19_body;
        }
        ambientPacket = (u8 *)btlFormationCreateSlotPacket(3, 0x8001);
        *(s64 *)(ambientPacket + 0x60) = *arg0;
        btlPacketEnqueue(ambientPacket, 0);
        if (*(u8 *)((u8 *)arg0 + 0x28) == 0) {
            targetPacket = actionTargetPacketBytes((u8 *)arg0, 0x1D, 0, 0, 0);
            *(s64 *)(targetPacket + 0x60) = *arg0;
            btlPacketEnqueue(targetPacket, 1);
        }
    }
    {
        u8 *battleUnit;

        battleUnit = *(u8 **)((u8 *)arg0 + 0x30);
        if (battleUnit[0xA2] == 0) {
            lookAtPacket = actionLookAtUnit(NULL, battleUnit, 2);
            *(s64 *)(lookAtPacket + 0x60) = *arg0;
            btlPacketEnqueue(lookAtPacket, 1);
        } else {
            lookAtDeactivatePacket = (u8 *)btlUnitCreateLookAtDeactivatePacket(0, 2);
            *(s64 *)(lookAtDeactivatePacket + 0x60) = *arg0;
            btlPacketEnqueue(lookAtDeactivatePacket, 1);
        }
    }
    btlPacketEnqueue(
        (u8 *)btlUnitCreateLookAtDeactivatePacket(
            (BtlUnit *)*(s32 *)(u8 *)func_001a_add_offset(0x30, (s32)arg0), 0),
        1);
    cameraPacket = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x21);
    *(s64 *)(cameraPacket + 0x60) = *arg0;
    btlPacketEnqueue(cameraPacket, 0);
    func_001eb3b0((u8 *)arg0 + 0x38);
    actionTypeAfter = *(u16 *)(u8 *)func_001a_add_offset(0x10, (s32)arg0);
    if ((actionTypeAfter != 0x25) && (actionTypeAfter != 6) && (actionTypeAfter != 5)) {
        btlPanelInit(*(s32 *)(iGpffffb3ac + 0xDD4), (u8 *)arg0);
        func_00213c10(*(s32 *)(iGpffffb3ac + 0xDD4));
    }
    btlUnitRequestLookAtOthers((u8 *)arg0);
    *(s32 *)(iGpffffb3ac + 0xC) |= 0x20000;
    *(u16 *)((u8 *)arg0 + 0x41C) = 0;
    *(s32 *)((u8 *)arg0 + 0x420) = 0;
}

/* measured 001a17d0: obj 1192B/window 1200B (-8B, -0.7% inside, 2-instr slack); 0 words via `python3 tools/measure_guarded.py src/promoted/code1_001a.c func_001a17d0`, 0 edits (+28 reloc-only) 298/298 via `python3 tools/fnalign.py src/promoted/code1_001a.c func_001a17d0 --candidate /tmp/candF_f32.c --quiet`; Jal 36 both sides. Switch v4 &0xFFFF reverse 2,0/default (compiler checks 0 first, matching retail layout; was if/else with bne losing andi+beq+b); switch v10 numeric 1,2,3,10 (compiler checks 10,3,2,1, matching retail; was reverse 10,3,2/1 checking 1 first); s32 f (was u16, fixes $a0 vs $v1 + extra andi); tail before check9 (was 9 before tail, fixing 37/37 pure hole/lump exactly equal, 294/297 inside hiding swap, edits 120->0). Production MATCH. */
// FUN_001A17D0
void btlActionCommandUpdate(u8 *arg0)
{
    extern u8 *btlCameraCreateSetStatePacket(u8 *arg0, s32 arg1);
    extern u16 D_008C024C[];
    s32 v4;
    u16 t;
    u16 v10;
    s32 f;
    s32 bVar;
    s16 sVar2;
    u8 *w;
    u8 *i;

    func_0019fc60();
    btlUnitTickIdleAnims();
    btlDamageSetActive(*(s32 *)(iGpffffb3ac + 0xDD4));
    if (*(s32 *)(arg0 + 0x420) == 1) {
        t = *(u16 *)(arg0 + 0x41C);
        if (t == 0) {
            btlPanelSetActive(*(s32 *)(iGpffffb3ac + 0xDD4));
            *(s32 *)(arg0 + 0x420) = 0;
        } else {
            *(u16 *)(arg0 + 0x41C) = t - 1;
        }
        return;
    }
    v4 = btlPanelGetState(*(s32 *)(iGpffffb3ac + 0xDD4)) & 0xFFFF;
    if ((D_008C024C[0] & 8) != 0 && (v4 & 0xFFFF) == 1 && (*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) == 0) {
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000) != 0) {
            if (func_00203810(*(s32 *)(iGpffffb3ac + 0xDD4)) == 1) {
                if (btlPanelIsReady(*(s32 *)(iGpffffb3ac + 0xDD4)) == 0) {
                    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x10000) == 0) {
                        btlSelectionSetTargetFlag(*(s32 *)(iGpffffb3ac + 0xDD4));
                        *(s32 *)(iGpffffb3ac + 0xC) = *(s32 *)(iGpffffb3ac + 0xC) | 0x10000;
                        func_00213b80(*(s32 *)(iGpffffb3ac + 0xDD4));
                        btlPanelSetFlag(*(s32 *)(iGpffffb3ac + 0xDD4));
                        w = btlCameraCreateSetStatePacket(arg0, 40);
                        *(s64 *)(w + 0x60) = *(s64 *)arg0;
                        btlPacketEnqueue(w, 0);
                    }
                    return;
                }
            }
        }
    } else {
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x10000) != 0) {
            btlSelectionClearTargetFlag(*(s32 *)(iGpffffb3ac + 0xDD4));
            *(s32 *)(iGpffffb3ac + 0xC) = *(s32 *)(iGpffffb3ac + 0xC) & ~0x10000;
            func_00213b50(*(s32 *)(iGpffffb3ac + 0xDD4));
            btlPanelClearFlag(*(s32 *)(iGpffffb3ac + 0xDD4));
            w = btlCameraCreateSetStatePacket(arg0, 33);
            *(s64 *)(w + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(w, 0);
        }
    }
    switch (v4 & 0xFFFF) {
    case 2: {
        v10 = *(u16 *)(arg0 + 0x6C);
        switch (v10) {
        case 1:
        case 2:
            f = (u16)func_001fae80(arg0, *(u16 *)(arg0 + 0x6E), 0);
            bVar = 1;
            break;
        case 3:
            f = (u16)func_001fae80(arg0, *(u16 *)(arg0 + 0x6E), 1);
            bVar = 1;
            break;
        case 10:
            f = 0;
            bVar = 1;
            break;
        default:
            f = 0;
            bVar = 0;
            break;
        }
        if (bVar != 0) {
            sVar2 = func_001fb170(f);
            if (sVar2 != 0) {
                func_0045af60(0, 15, 0, 8);
                btlUiSelectEffect(*(s32 *)(arg0 + 0x30), sVar2);
                *(u16 *)(arg0 + 0x41C) = 6;
                *(s32 *)(arg0 + 0x420) = 1;
                btlPanelSetClosing(*(s32 *)(iGpffffb3ac + 0xDD4));
                return;
            } else {
                func_00213c40(*(s32 *)(iGpffffb3ac + 0xDD4));
                btlPanelSetFlag(*(s32 *)(iGpffffb3ac + 0xDD4));
                btlActionSetState((BtlAction *)arg0, 6);
                return;
            }
        }
        goto tail;
    }
    case 0:
        goto tail;
    default:
        goto check9;
    }
tail:
    *(u16 *)(arg0 + 0x18) = *(u16 *)(arg0 + 0x18) | 2;
    btlDamageClearActive(*(s32 *)(iGpffffb3ac + 0xDD4));
    btlPanelReleaseText(*(s32 *)(iGpffffb3ac + 0xDD4));
    btlPanelReset(*(s32 *)(iGpffffb3ac + 0xDD4));
    func_00213c40(*(s32 *)(iGpffffb3ac + 0xDD4));
    for (i = *(u8 **)(iGpffffb3ac + 0x174); i != 0; i = *(u8 **)(i + 0x450)) {
    }
    btlActionSetState((BtlAction *)arg0, 15);
    return;
check9:
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) != 0) {
        btlDamageClearActive(*(s32 *)(iGpffffb3ac + 0xDD4));
        btlPanelReleaseText(*(s32 *)(iGpffffb3ac + 0xDD4));
        btlPanelReset(*(s32 *)(iGpffffb3ac + 0xDD4));
        func_00213c40(*(s32 *)(iGpffffb3ac + 0xDD4));
        for (i = *(u8 **)(iGpffffb3ac + 0x174); i != 0; i = *(u8 **)(i + 0x450)) {
        }
        btlActionSetState((BtlAction *)arg0, 9);
    }
    return;
}

// FUN_001A1C80
void btlActionTargetInit(u8 *arg0)
{
    u8 *lookAtUnit;
    s32 unitIndex;
    u8 entryType;
    u8 *packet;

    switch (*(u16 *)(arg0 + 0x6C)) {
    case 4:
        func_001d7c60(arg0, arg0 + 0x98, 2, 0, 0);
        unitIndex = func_001a_fix_var(*(u16 *)(arg0 + 0x6E));
        break;
    default:
        unitIndex = *(u16 *)(arg0 + 0x6E);
        entryType = *(u8 *)(func_001a_add_offset(unitIndex * 0x28,
                                               (u32)iGpffffb3b8) + 8);
        switch (entryType) {
        case 1:
        case 2:
            {
                extern void func_001d7c60(
                    u8 *arg0, u8 *arg1, u8 arg2, u8 arg3, u32 arg4);
                func_001d7c60(
                    arg0,
                    arg0 + 0x98,
                    *(u8 *)(func_001a_add_offset(unitIndex * 0x28,
                                                  (u32)iGpffffb3b8) + 9),
                    *(u8 *)(func_001a_add_offset(unitIndex * 0x28,
                                                  (u32)iGpffffb3b8) + 0xA),
                    0);
            }
            break;
        default:
            btlSkillClassifyTargets(arg0, arg0 + 0x98, unitIndex & 0xFFFF, 0);
            break;
        }
        break;
    }
init_1c80:
    func_001d8cb0(arg0, arg0 + 0x98);
    entryType = *(u8 *)(func_001a_add_offset(
        *(u16 *)(arg0 + 0x6E) * 0x28, (u32)iGpffffb3b8) + 8);
    switch (entryType) {
    case 1:
    case 2:
        goto type12_2_1c80;
    default:
        goto typeother_2_1c80;
    }
type12_2_1c80:
    lookAtUnit = NULL;
    goto after_type_1c80;
typeother_2_1c80:
    func_001d8e50(arg0, arg0 + 0x98);
after_type_1c80:
    btlSelectionMarkTargets(
        *(s32 *)(D_0076449C + 0xDD4),
        arg0,
        arg0 + 0x98,
        (s64)(s16)unitIndex);
    packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x22);
    *(s64 *)(packet + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(packet, 0);
    btlDamageSetActive(*(s32 *)(D_0076449C + 0xDD4));
    btlUnitRequestLookAtOthers(arg0);
    if (lookAtUnit != NULL) {
        packet = actionLookAtUnit(NULL, *(u8 **)(lookAtUnit + 0x30), 1);
        btlPacketEnqueue(packet, 1);
        packet = (u8 *)btlUnitCreateLookAtDeactivatePacket((BtlUnit *)*(s32 *)(lookAtUnit + 0x30), 0);
        btlPacketEnqueue(packet, 1);
    }
}

#pragma push
// FUN_001A1EA0
void btlActionTargetUpdate(u8 *action) {
    extern u16 D_008C024C[];
    extern void btlUnitTickIdleAnims(void);
    extern void func_0019fc60(void);
    extern s32 func_001fb170(s32 condition);
    extern void btlUiSelectEffect(s32 unit, u32 message);
    extern void btlPanelSetActive(s32 task);
    extern void btlPanelReset(s32 task);
    extern void btlPanelClearFlag(s32 task);
    extern void btlSelectionSetTargetFlag(s32 task);
    extern void btlSelectionClearTargetFlag(s32 task);
    extern void btlDamageClearActive(s32 task);
    extern void func_00213b50(s32 task);
    extern void func_00213b80(s32 task);
    extern void func_00213c10(s32 task);
    extern void func_00213c40(s32 task);
    extern void btlPanelReleaseText(s32 task);
    s32 selectionState;
    s32 selectedAddress;
    s32 battleFlags;
    s32 selectionMode;
    u16 targetIndex;
    s32 condition;
    s32 messageId;
    u16 targetCount;
    u16 actionKind;
    u8 *enterCamera;
    u8 *exitCamera;
    u8 *selectedAction;
    u8 *selectedUnit;
    u8 targetMode;
    u8 *selectionBattle;
    u8 *enteredBattle;
    u8 *exitedBattle;
    u8 *battle;
    u8 *actionCursor;
    u8 *clearCursor;

    func_0019fc60();
    btlUnitTickIdleAnims();
    selectionState = btlSelectionGetTargetMark((s32)(*(u8**)(iGpffffb3ac + 0xDD4))) & 0xFFFF;
    if ((D_008C024C[0] & 8) && !(selectionState & 0xFFFF)) {
        battleFlags = (*(s32*)(iGpffffb3ac + 0xC));
        if (battleFlags & 0x20000) {
            if (!(battleFlags & 0x10000) && ((btlEffectCollectGenusMask((s32)(action + 0x98)) & 0xFFFF) != 1)) {
                btlSelectionSetTargetFlag((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
                enteredBattle = iGpffffb3ac;
                (*(s32*)(enteredBattle + 0xC)) = (s32) ((*(s32*)(enteredBattle + 0xC)) | 0x10000);
                func_00213b80((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
                enterCamera = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x28);
                (*(s64*)(enterCamera + 0x60)) = (s64) (*(s64*)action);
                btlPacketEnqueue(enterCamera, 0U);
            }
            return;
        }
        goto select_action;
    }
    battle = iGpffffb3ac;
    if ((*(s32*)(battle + 0xC)) & 0x10000) {
        btlSelectionClearTargetFlag((s32)(*(u8**)(battle + 0xDD4)));
        exitedBattle = iGpffffb3ac;
        (*(s32*)(exitedBattle + 0xC)) = (s32) ((*(s32*)(exitedBattle + 0xC)) & 0xFFFEFFFF);
        func_00213b50((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
        exitCamera = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x22);
        (*(s64*)(exitCamera + 0x60)) = (s64) (*(s64*)action);
        btlPacketEnqueue(exitCamera, 0U);
    }
select_action:
    selectionMode = selectionState & 0xFFFF;
    switch (selectionMode) {
    case 0:
        selectionBattle = iGpffffb3ac;
        if ((*(s32*)(selectionBattle + 0xC)) & 0x1000) {
            btlDamageClearActive((s32)(*(u8**)(selectionBattle + 0xDD4)));
            btlPanelReleaseText((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            btlSelectionResetUnitFlags((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            btlPanelReset((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_00213c40((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            actionCursor = (*(u8**)(iGpffffb3ac + 0x174));
            while (actionCursor != NULL) {
                actionCursor = *(u8 **)(actionCursor + 0x450);
            }
            btlActionSetState((BtlAction *)action, 9);
            btlPacketEnqueue((u8*)btlUnitCreateLookAtDeactivatePacket(0, 1), 1U);
            return;
        }
        selectedAction = (u8 *)btlSelectionGetFormationEntryAlt((s32)(*(u8**)(selectionBattle + 0xDD4)));
        if (selectedAction != NULL) {
            selectedUnit = (*(u8**)(selectedAction + 0x30));
            if ((*(u8*)(selectedUnit + 0xA2)) == 1) {
                btlPacketEnqueue((u8*)actionLookAtUnit(NULL, selectedUnit, 1), 1U);
                btlPacketEnqueue((u8*)btlUnitCreateLookAtDeactivatePacket(*(BtlUnit **)(selectedAction + 0x30), 0), 1U);
                return;
            }
        }
        btlPacketEnqueue((u8*)btlUnitCreateLookAtDeactivatePacket(0, 3), 1U);
        return;
    case 1:
        targetMode = *(u8 *)(actionSelectionOffset(*(u16 *)(action + 0x6E) * 0x28, iGpffffb3b8) + 8);
        switch (targetMode) {
        case 1:
        case 2: {
            targetIndex = 0;
            while ((targetCount = *(u16 *)(action + 0xD0), targetIndex < (s32)targetCount)) {
                actionCopySelectedTarget(action, &targetIndex);
                targetIndex++;
            }
            (*(u16*)(action + 0x6A)) = targetCount;
        } break;
        default: {
            selectedAddress = (s32)btlSelectionGetFormationEntry((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            (*(u8**)(action + 0x38)) = (u8*)selectedAddress;
            (*(u16*)(action + 0x6A)) = 1U;
            func_001d8be0((s32)(action + 0x98), (u64 *)(u32)selectedAddress);
        } break;
        }
        actionKind = (*(u16*)(action + 0x6C));
        switch (actionKind) {
        case 1:
        case 2:
            condition = func_001faf70(action, (s32) (*(u16*)(action + 0x6E)), 0) & 0xFFFF;
            break;
        case 3:
            condition = func_001faf70(action, (s32) (*(u16*)(action + 0x6E)), 1) & 0xFFFF;
            break;
        default:
            condition = 0;
            break;
        }
        messageId = (s16)func_001fb170(condition);
        if (messageId != 0) {
            func_0045af60(0, 0xF, 0, 8);
            btlUiSelectEffect(*(s32 *)(action + 0x30), (u32)messageId);
            btlSelectionClearTargetMark((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            return;
        }
        switch (*(u16 *)(action + 0x6C)) {
        case 4: {
            btlSelectionResetUnitFlags((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_00203880((s32)(*(u8**)(iGpffffb3ac + 0xDD4)), (s32)(*(u8**)(action + 0x38)));
            btlActionSetState((BtlAction *)action, 5);
            return;
        } break;
        default: {
            (*(u16*)(action + 0x18)) = (u16) ((*(u16*)(action + 0x18)) | 2);
            btlDamageClearActive((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            btlPanelReleaseText((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            btlSelectionResetUnitFlags((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            btlPanelReset((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_00213c40((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            clearCursor = (*(u8**)(iGpffffb3ac + 0x174));
            while (clearCursor != NULL) {
                clearCursor = *(u8 **)(clearCursor + 0x450);
            }
            btlActionSetState((BtlAction *)action, 0xF);
            return;
        } break;
        }
    case 2:
        btlPacketEnqueue((u8*)btlUnitCreateLookAtDeactivatePacket(0, 1), 1U);
        btlSelectionResetUnitFlags((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
        func_00213c10(*(s32 *)(iGpffffb3ac + 0xDD4));
        btlPanelClearFlag((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
        btlPanelSetActive((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
        btlActionSetState((BtlAction *)action, 5);
        /* fallthrough */
    case 3:
        return;
    }
}

#pragma pop
// FUN_001A24A0
void btlActionAnalyzeInit(BtlAction *action)
{
    *(s32 *)((u8 *)action + 0x41C) = 1;
}

/* measured: 1564/1568 bytes, 47 resolved relocations, four zero tail bytes.
 * Loop invariants hoist the first scan's true value and each unsigned wrap
 * bound as retail does. Stored short cursor and widened index stay distinct. */
// FUN_001A24B0
#pragma push
/* measured: func_001a24b0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
void btlActionAnalyzeUpdate(u8 *action)
{
    extern u16 D_008C024C[];
    extern s32 func_0045af60(s16 index, s16 stream, s16 arg2, s16 arg3);

    if (btlCountUnitRecordsById(0x800) != 0) {
        return;
    }
    switch (*(s32 *)(action + 0x41C)) {
    case 1: {
        u8 *openingPacket;
        u8 *iter;
        s32 hasOther;
        u8 *selected;
        s16 index;

        openingPacket = (u8 *)btlFormationCreateSlotPacket(3, 0xFFF);
        *(s64 *)(openingPacket + 0x60) = *(s64 *)action;
        btlPacketEnqueue(openingPacket, 0);
        iter = *(u8 **)(D_0076449C + 0x174);
        while (iter != NULL) {
            u8 *packet;
            if (*(u16 *)(iter + 0x1A) & 1) {
                if (action == iter || !(*(u16 *)(iter + 0x1A) & 8)) {
                    packet = btlUnitCreateHidePacket(*(u8 **)(iter + 0x30));
                } else {
                    packet = func_0019bbe0(*(u8 **)(iter + 0x30), 0xFFFFFF, 8, 0, 4, 0);
                }
                *(s64 *)(packet + 0x60) = *(s64 *)action;
                btlPacketEnqueue(packet, 0);
            }
            iter = *(u8 **)(iter + 0x450);
        }
        selected = *(u8 **)(action + 0x38);
        func_001d7c60(action, action + 0x98, 2, 0, 0);
        hasOther = 0;
        *(u16 *)(action + 0xD2) = *(u16 *)(action + 0xD0);
        index = 0;
        while ((s16)index < *(u16 *)(action + 0xD0)) {
            u8 **slot = (u8 **)(action + (s16)index * 4 + 0x98);
            if (*slot == selected) {
                *(u16 *)(action + 0xD2) = index;
            }
            if (*(u16 *)(*(u8 **)(*slot + 0x30) + 0xA4) !=
                *(u16 *)(*(u8 **)(selected + 0x30) + 0xA4)) {
                hasOther = 1;
            }
            index++;
        }
        func_00213be0(*(s32 *)(D_0076449C + 0xDD4));
        btlMessageSetup(*(u8 **)(D_0076449C + 0xDD4), selected);
        if (hasOther) {
            btlMessageSetHidden(*(s32 *)(D_0076449C + 0xDD4));
        }
        btlActionFinishPresentation((BtlAction *)action);
        {
            u8 *cameraPacket = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)selected, 1);
            *(s64 *)(cameraPacket + 0x60) = *(s64 *)action;
            btlPacketEnqueue(cameraPacket, 0);
        }
        func_001f62b0();
        func_001f86d0();
        if (func_001eb860() == 1) {
            *(s32 *)(D_0076449C + 0xC) &= ~0x2000;
            btlDamageSetSource(*(u8 **)(D_0076449C + 0xDD4), 0);
        }
        *(s32 *)(action + 0x41C) = 2;
        break;
    }
    case 2: {
        if (btlMessageIsIdle(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
            u8 *unit = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
            if (unit != NULL) {
                s32 resource = func_001f62f0(unit);
                if (resource >= 0) {
                    func_001f9a50((u16)resource, 1);
                }
            }
            *(s32 *)(action + 0x41C) = 3;
        }
        break;
    }
    case 3: {
        u16 input = D_008C024C[1];
        if ((input & 8) || (input & 4)) {
            u8 *selected = *(u8 **)(action + 0x38);
            u16 previous = *(u16 *)(action + 0xD2);
            s32 selectedIndex;
            s16 cursor = (s16)previous;
            if (input & 8) {
                s32 count = *(u16 *)(action + 0xD0);
                while ((selectedIndex = (s16)cursor) < count) {
                    u8 *candidate = *(u8 **)(action + selectedIndex * 4 + 0x98);
                    if (*(u16 *)(*(u8 **)(candidate + 0x30) + 0xA4) !=
                        *(u16 *)(*(u8 **)(selected + 0x30) + 0xA4)) {
                        break;
                    }
                    cursor++;
                }
                if (count == selectedIndex) {
                    cursor = 0;
                    while ((selectedIndex = (s16)cursor) < (u16)previous) {
                        u8 *candidate = *(u8 **)(action + selectedIndex * 4 + 0x98);
                        if (*(u16 *)(*(u8 **)(candidate + 0x30) + 0xA4) !=
                            *(u16 *)(*(u8 **)(selected + 0x30) + 0xA4)) {
                            break;
                        }
                        cursor++;
                    }
                }
            } else {
                while ((selectedIndex = (s16)cursor) >= 0) {
                    u8 *candidate = *(u8 **)(action + selectedIndex * 4 + 0x98);
                    if (*(u16 *)(*(u8 **)(candidate + 0x30) + 0xA4) !=
                        *(u16 *)(*(u8 **)(selected + 0x30) + 0xA4)) {
                        break;
                    }
                    cursor--;
                }
                if (selectedIndex < 0) {
                    cursor = *(u16 *)(action + 0xD0) - 1;
                    while ((selectedIndex = (s16)cursor) > (u16)previous) {
                        u8 *candidate = *(u8 **)(action + selectedIndex * 4 + 0x98);
                        if (*(u16 *)(*(u8 **)(candidate + 0x30) + 0xA4) !=
                            *(u16 *)(*(u8 **)(selected + 0x30) + 0xA4)) {
                            break;
                        }
                        cursor--;
                    }
                }
            }
            if ((u16)previous != selectedIndex) {
                func_0045af60(0, 0, 0, 5);
                *(u8 **)(action + 0x38) = *(u8 **)((u8 *)func_001a_add_offset(selectedIndex * 4, (s32)action) + 0x98);
                *(u16 *)(action + 0xD2) = cursor;
                btlMessageSetPendingValue(*(u8 **)(D_0076449C + 0xDD4), *(s32 *)(action + 0x38));
            }
        } else if ((input & 0x40) || (input & 0x20)) {
            func_0045af60(0, 0, 0, 4);
            if (func_001eb860() == 1) {
                *(s32 *)(D_0076449C + 0xC) |= 0x2000;
                btlDamageSetSource(*(u8 **)(D_0076449C + 0xDD4), 1);
            }
            *(s32 *)(action + 0x41C) = 4;
        }
        break;
    }
    case 4: {
        u8 *iter;
        u8 *packet;
        func_001f9a90();
        iter = *(u8 **)(D_0076449C + 0x174);
        while (iter != NULL) {
            if ((*(u16 *)(iter + 0x1A) & 1) && !(*(u16 *)(iter + 0x1A) & 0x400)) {
                if (action == iter) {
                    packet = btlUnitCreateShowPacket(*(u8 **)(iter + 0x30));
                } else {
                    packet = func_0019bbe0(*(u8 **)(iter + 0x30), (u32)-1, 0, 0, 3, 0);
                }
                *(s64 *)(packet + 0x60) = *(s64 *)action;
                btlPacketEnqueue(packet, 0);
            }
            iter = *(u8 **)(iter + 0x450);
        }
        func_00213bb0(*(s32 *)(D_0076449C + 0xDD4));
        btlMessageSetDone(*(s32 *)(D_0076449C + 0xDD4));
        btlActionSetState((BtlAction *)action, *(u16 *)(action + 0x14));
        *(s32 *)(action + 0x41C) = 0;
        break;
    }
    }
}

#pragma pop
// FUN_001A2AD0
void btlActionAiInit(BtlAction *action) {
    func_001eb3b0((u8 *)action + 0x38);
    if ((*(s32 *)(D_0076449C + 0xC) & 0x1000) == 0) {
        return;
    }
    if ((*(u16 *)((u8 *)action + 0x1A) & 1) == 0) {
        return;
    }
    if (*(*(u8 **)((u8 *)action + 0x30) + 0xA2) != 0) {
        return;
    }
    btlActionSetState(action, 9);
}

// FUN_001A2B50
void btlActionAiUpdate(u8 *arg0)
{
    s32 battleFlags;

    if (func_001deeb0(arg0 + 0x38) == 0) {
        btlAICommandSetUnitAction(arg0, arg0 + 0x38);
    }
    if (btlAICommandTryReleaseProc(arg0 + 0x38) != 0) {
        battleFlags = *(s32 *)(D_0076449C + 0xC);
        if ((battleFlags & 0x1000) &&
            (battleFlags & 0x04000000) &&
            (*(u8 **)(arg0 + 0x30))[0xA2] == 1) {
            *(u16 *)(arg0 + 0x18) |= 0x4000;
        }
        *(u16 *)(arg0 + 0x18) |= 2;
        btlActionSetState((BtlAction *)arg0, 0xF);
    }
}

// FUN_001A2C10
void btlActionAutoInit(s64 *arg0) {
    func_001eb3b0((u8 *)arg0 + 0x38);
    btlSkillClassifyTargets((u8 *)arg0, (u8 *)arg0 + 0x98, 0, 0);
    func_001d8cb0(NULL, arg0 + 0x13);
}

// FUN_001A2C70
void btlActionAutoUpdate(u8 *arg0)
{
    u8 *battleUnit;

    *(s16 *)(arg0 + 0x6C) = 1;
    *(s16 *)(arg0 + 0x6E) =
        datCalcDefaultSkillId(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
    *(s32 *)(arg0 + 0x38) = func_001d8bc0(arg0 + 0x98);
    *(s16 *)(arg0 + 0x6A) = 1;
    func_001d8be0((s32)(arg0 + 0x98), *(u64 **)(arg0 + 0x38));
    battleUnit = *(u8 **)(arg0 + 0x30);
    if ((battleUnit[0xA2] == 0) && (*(u16 *)(battleUnit + 0xA4) == 1)) {
        btlPacketEnqueue(actionTargetPacketBytes(arg0, 1, 0, 0, 0), 1);
    }
    if (*(s32 *)(D_0076449C + 0xC) & 0x04000000) {
        *(u16 *)(arg0 + 0x18) |= 0x4000;
    }
    *(u16 *)(arg0 + 0x18) |= 2;
    btlActionSetState((BtlAction *)arg0, 0xF);
}

// FUN_001A2D60
void btlActionSupportInit(void)
{
}

/* MATCHED: 1072 bytes of code and the 64-byte table at 0x00746FD0 resolve
   exactly.  This is D_005f6e20[10].update, a void action callback, so the
   packet UID that func_00194590 returns is discarded here.  The u8
   conversion plus the explicit signed guard reproduce retail's redundant
   `bltz` range check - the two words an earlier pass could not place -
   and opt_propagation off with opt_common_subs off keep that lowering
   together with the repeated `*(u8 **)(unit + 0xA64)` loads that retail
   reloads rather than folding. */
// FUN_001A2D70
#pragma push
/* measured: func_001a2d70 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
void btlActionSupportUpdate(u8 *arg0) {
    extern void btlActionSetState(u8 *, u16);
    extern u8 *btlCameraCreateSetStatePacket(u8 *, u16);

    s32 state;
    s32 kind;
    u8 *unit;
    u8 *packet;

    void datCalcClearBuffLevel(u8 *arg0, s32 arg1);


    if (btlCountUnitRecordsById(0x506) == 0) {
        unit = *(u8 **)((u8 *)arg0 + 0x30);
        kind = (u8)datCalcFindStrongBuff(*(u8 **)(unit + 0xA64));
        if (kind < 0) {
            goto fallback;
        }
        switch (kind) {
        case 0:
        case 1:
            if (unit[0xA2] == 0) {
                state = 30;
            } else {
                state = 31;
            }
            datCalcClearBuffLevel(*(u8 **)(unit + 0xA64), 0);
            datCalcClearBuffLevel(*(u8 **)(unit + 0xA64), 1);
            break;
        case 2:
        case 4:
            if (unit[0xA2] == 0) {
                state = 32;
            } else {
                state = 33;
            }
            datCalcClearBuffLevel(*(u8 **)(unit + 0xA64), 4);
            datCalcClearBuffLevel(*(u8 **)(unit + 0xA64), 2);
            break;
        case 3:
            if (unit[0xA2] == 0) {
                state = 34;
            } else {
                state = 35;
            }
            datCalcClearBuffLevel(*(u8 **)(unit + 0xA64), 3);
            break;
        case 5:
            if (unit[0xA2] == 0) {
                state = 36;
            } else {
                state = 37;
            }
            datCalcClearBuffLevel(*(u8 **)(unit + 0xA64), 5);
            break;
        case 6:
            if (unit[0xA2] == 0) {
                state = 38;
            } else {
                state = 39;
            }
            datCalcClearBuffLevel(*(u8 **)(unit + 0xA64), 6);
            break;
        case 7:
            if (unit[0xA2] == 0) {
                state = 40;
            } else {
                state = 41;
            }
            datCalcClearBuffLevel(*(u8 **)(unit + 0xA64), 7);
            break;
        case 8:
            if (unit[0xA2] == 0) {
                state = 80;
            } else {
                state = 81;
            }
            datCalcClearBuffLevel(*(u8 **)(unit + 0xA64), 8);
            break;
        case 9:
            if (unit[0xA2] == 0) {
                state = 82;
            } else {
                state = 83;
            }
            datCalcClearBuffLevel(*(u8 **)(unit + 0xA64), 9);
            break;
        case 10:
            if (unit[0xA2] == 0) {
                state = 84;
            } else {
                state = 85;
            }
            datCalcClearBuffLevel(*(u8 **)(unit + 0xA64), 10);
            break;
        case 11:
            if (unit[0xA2] == 0) {
                state = 86;
            } else {
                state = 87;
            }
            datCalcClearBuffLevel(*(u8 **)(unit + 0xA64), 11);
            break;
        case 12:
            if (unit[0xA2] == 0) {
                state = 130;
            } else {
                state = 131;
            }
            datCalcClearBuffLevel(*(u8 **)(unit + 0xA64), 12);
            break;
        case 13:
            if (unit[0xA2] == 0) {
                state = 132;
            } else {
                state = 133;
            }
            datCalcClearBuffLevel(*(u8 **)(unit + 0xA64), 13);
            break;
        case 14:
            if (unit[0xA2] == 0) {
                state = 134;
            } else {
                state = 135;
            }
            datCalcClearBuffLevel(*(u8 **)(unit + 0xA64), 14);
            break;
        case 15:
            if (unit[0xA2] == 0) {
                state = 136;
            } else {
                state = 137;
            }
            datCalcClearBuffLevel(*(u8 **)(unit + 0xA64), 15);
            break;
        default:
            state = 0;
            break;
        }
        if (state != 0) {
            btlActionFinishPresentation((BtlAction *)arg0);
            packet = btlCameraCreateSetStatePacket((u8 *)arg0, 10);
            *(s64 *)(packet + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(packet, 0);
            packet = actionMessagePacketBytes(*(s32 *)((u8 *)arg0 + 0x30), (s32)state);
            *(s64 *)(packet + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(packet, 3);
        } else {
fallback:
            if (func_001f6770((u8 *)arg0) != 0) {
                btlActionSetState((u8 *)arg0, 11);
            } else {
                btlActionSetState((u8 *)arg0, 3);
            }
        }
    }
}

#pragma pop
// FUN_001A31A0
void btlActionBadInit(u8 *arg0)
{
    func_001f6cd0();
    *(s32 *)(arg0 + 0x41C) = 1;
    *(s32 *)(arg0 + 0x420) = 0;
}

#pragma push
/* Recover an incapacitated action or select its next state. The unit status
 * remains a 32-bit word through the low20 selector. Camera and animation
 * packets remain alive until their published UIDs have been consumed. */
// FUN_001A31E0
void btlActionBadUpdate(BtlAction *actionState)
{
    u8 *action = (u8 *)actionState;
    u32 badStatus;
    s32 allowRecovery;
    s32 resultFlags;
    u8 *cameraPacket;
    u8 *animationPacket;
    u16 animationDelay;
    u16 animationDuration;
    f32 animationSpeed;
    f32 rotation[3];
    struct { s32 words[8]; } result;

    if (btlCountUnitRecordsById(0x506) == 0 && btlCountUnitRecordsById(0x105) == 0) {
        btlActionFinishPresentation((BtlAction *)action);
        badStatus = datCalcGetBadStatus(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64));
        if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 0x100000) != 0 &&
            *(s32 *)(action + 0x420) == 0) {
            allowRecovery = 1;
            if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 1) != 0 &&
                func_001f6bf0(action) == 0) {
                allowRecovery = 0;
            }
            if (allowRecovery != 0) {
                cameraPacket = (u8 *)btlCameraCreateSetStatePacket(actionState, 0x31);
                *(s64 *)(cameraPacket + 0x60) = *(s64 *)action;
                btlPacketEnqueue(cameraPacket, 0);
                if (*(u32 *)(iGpffffb3ac + 0xC) & 0x200000) {
                    u8 *packet;
                    func_00194ff0(*(u8 **)(action + 0x30), NULL, NULL, rotation);
                    packet = (u8 *)btlUnitCreateRotatePacket(*(BtlUnit **)(action + 0x30),
                                                            (const RwV3d *)rotation, 2);
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    btlPacketEnqueue(packet, 0);
                }
                {
                    u32 flags = *(u32 *)(iGpffffb3ac + 0xC);
                    if ((flags & 0x1000) && (flags & 0x04000000)) {
                        animationSpeed = 1.75f;
                        animationDelay = 12;
                        animationDuration = 4;
                    } else {
                        animationSpeed = 1.0f;
                        animationDelay = 30;
                        animationDuration = 8;
                    }
                }
                animationPacket = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(action + 0x30),
                                                               11, 0, animationSpeed, 0);
                animationPacket[0] = 4;
                *(s64 *)(animationPacket + 8) = *(s64 *)(cameraPacket + 0x58);
                *(u16 *)(animationPacket + 0x48) = animationDelay;
                *(s64 *)(animationPacket + 0x60) = *(s64 *)action;
                btlPacketEnqueue(animationPacket, 0);
                {
                    u8 *packet = (u8 *)btlVoiceCreatePacket(actionState, 3, 0, 0, 0);
                    packet[0] = 4;
                    *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
                    btlPacketEnqueue(packet, 1);
                }
                func_001f0a10((u8 *)&result);
                result.words[3] = 0x100001;
                {
                    u8 *packet = (u8 *)btlTargetCreateDataPacket((s32)action, (s32)action, &result, 1, 1);
                    packet[0] = 4;
                    *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    btlPacketEnqueue(packet, 1);
                }
                {
                    u8 *packet = (u8 *)btlUnitCreateMotionSettlePacket(*(BtlUnit **)(action + 0x30));
                    packet[0] = 4;
                    *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
                    *(u16 *)(packet + 0x4A) = animationDuration;
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    btlPacketEnqueue(packet, 0);
                }
                {
                    u8 *packet = (u8 *)btlTargetCreateTargetPacket((u32)action, 0x11, 0, 0, 0);
                    packet[0] = 4;
                    *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    btlPacketEnqueue(packet, 1);
                }
                *(s32 *)(action + 0x41C) = 1;
            } else {
                {
                    u8 *packet = (u8 *)btlCameraCreateSetStatePacket(actionState, 10);
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    btlPacketEnqueue(packet, 0);
                }
                {
                    u8 *packet = (u8 *)btlTargetCreateTargetPacket((u32)action, 0x12, 0, 0, 0);
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    btlPacketEnqueue(packet, 1);
                }
                {
                    u8 *unit = *(u8 **)(action + 0x30);
                    u8 *packet;
                    s32 message;
                    if (unit[0xA2] == 0) {
                        message = 0x68;
                    } else {
                        message = 0x69;
                    }
                    packet = (u8 *)btlPacketCreateEffectCounter((s32)unit, message);
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    btlPacketEnqueue(packet, 3);
                }
                *(s32 *)(action + 0x41C) = 0;
            }
            btlPacketEnqueue((u8 *)btlUnitCreateLookAtUnitPacket(NULL, *(BtlUnit **)(action + 0x30), 1), 1);
            btlPacketEnqueue((u8 *)btlUnitCreateLookAtDeactivatePacket(*(BtlUnit **)(action + 0x30), 0), 1);
            *(u16 *)(action + 0x18) |= 0x200;
            *(s32 *)(action + 0x420) = 1;
            return;
        }
        resultFlags = func_001f6930(action);
        if (resultFlags != 0) {
            s32 message;
            {
                u8 *packet = (u8 *)btlCameraCreateSetStatePacket(actionState, 10);
                *(s64 *)(packet + 0x60) = *(s64 *)action;
                btlPacketEnqueue(packet, 0);
            }
            func_001f0a10((u8 *)&result);
            result.words[3] = resultFlags;
            {
                u8 *packet = (u8 *)btlTargetCreateDataPacket((s32)action, (s32)action, &result, 1, 1);
                *(u16 *)(packet + 0x48) = 0x12;
                btlPacketEnqueue(packet, 1);
            }
            message = func_001f7140(action);
            if (message > 0) {
                u8 *packet = (u8 *)btlPacketCreateEffectCounter(*(s32 *)(action + 0x30), message);
                *(s64 *)(packet + 0x60) = *(s64 *)action;
                btlPacketEnqueue(packet, 3);
            }
            return;
        }
        if (*(s32 *)(action + 0x41C) != 0) {
            if (badStatus & 0x116) {
                s32 message;
                func_001eb4a0(action, action + 0x38, badStatus);
                *(u16 *)(action + 0x18) |= 2;
                message = func_001f6f60(action);
                if (message > 0) {
                    {
                        u8 *packet = (u8 *)btlCameraCreateSetStatePacket(actionState, 10);
                        *(s64 *)(packet + 0x60) = *(s64 *)action;
                        btlPacketEnqueue(packet, 0);
                    }
                    {
                        u8 *packet = (u8 *)btlPacketCreateEffectCounter(*(s32 *)(action + 0x30), message);
                        *(s64 *)(packet + 0x60) = *(s64 *)action;
                        btlPacketEnqueue(packet, 3);
                    }
                }
                {
                    u8 *packet = (u8 *)btlTargetCreateTargetPacket((u32)action, 0x1E, 0, 0, 0);
                    *(u16 *)(packet + 0x48) = 0x18;
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    btlPacketEnqueue(packet, 1);
                }
                btlActionSetState(actionState, 15);
                return;
            }
            btlActionSetStateWithDelay(actionState, 3, 1);
            return;
        }
        func_001eb3b0(action + 0x38);
        *(u16 *)(action + 0x18) &= 0xFFF7;
        if (func_001f68e0(action) != 0) {
            btlActionSetState(actionState, 27);
            return;
        }
        btlActionSetState(actionState, 32);
    }
}

#pragma pop
#pragma push
/* The mode is established by the action selector before entering this state.
   Movement and target-animation packets are separate dependency owners. */
// FUN_001A3840
void btlActionCooperateInit(register BtlAction *actionState)
{
    u8 *action;
    u8 *movementPacket;
    u8 *animationPacket;
    u8 *target;
    s16 mode;
    s32 resultFlags;
    f32 distance;
    struct { s16 slot; } selectedEffect;
    u16 targetFrame;
    u16 targetAnimation;
    u16 sourceAnimation;
    u16 beforeVoice;
    u16 afterVoice;
    u16 formationMode;
    u16 displayMode;
    struct {
        s32 values[8];
    } result;
    s32 delayedFrame;

    action = (u8 *)actionState;
    target = *(u8 **)(action + 0x444);
    mode = *(s16 *)(action + 0x448);
    switch (mode) {
    case 1:
        resultFlags = 0x100001;
        sourceAnimation = 27;
        targetAnimation = 28;
        targetFrame = 0;
        {
            u8 *targetUnit = *(u8 **)(target + 0x30);
            u8 *sourceUnit = *(u8 **)(action + 0x30);
            f32 sourceRadius = *(f32 *)(sourceUnit + 0x90);
            f32 sourceScale = *(f32 *)(sourceUnit + 0x2C);
            f32 targetRadius = *(f32 *)(targetUnit + 0x90);
            f32 targetScale = *(f32 *)(targetUnit + 0x2C);
            distance = 50.0f + (sourceRadius * sourceScale + targetRadius * targetScale);
        }
        selectedEffect.slot = -1;
        displayMode = 14;
        formationMode = 1;
        beforeVoice = 0;
        afterVoice = 12;
        *(u16 *)(action + 0x1A) |= 0x800;
        break;
    case 0:
        resultFlags = 30;
        sourceAnimation = 29;
        targetAnimation = 2;
        targetFrame = (u16)btlUnitMotionFrames(*(u8 **)(action + 0x30), 29, 1.0f);
        distance = 50.0f + func_00196bd0(*(u8 **)(action + 0x30),
                                        *(u8 **)(target + 0x30), 29);
        displayMode = 15;
        selectedEffect.slot = 40;
        formationMode = 0;
        beforeVoice = 10;
        afterVoice = 11;
        *(u16 *)(action + 0x1A) |= 0x1000;
        break;
    }
    btlActionFinishPresentation((BtlAction *)action);
    func_001eb410(action + 0x38);
    *(u8 **)(action + 0x38) = target;
    *(s16 *)(action + 0x6A) = 1;
    if ((u16)beforeVoice != 0) {
        {
            u8 *packet;
            packet = (u8 *)btlVoiceCreatePacket((BtlAction *)action, beforeVoice,
                             *(u16 *)(*(u8 **)(target + 0x30) + 0xA4), 0, 0);
            *(s64 *)(packet + 0x60) = *(s64 *)action;
            btlPacketEnqueue(packet, 1);
        }
    }
    if ((*(u32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0) {
        {
            u8 *packet;
            packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 25);
            *(s64 *)(packet + 0x60) = *(s64 *)action;
            btlPacketEnqueue(packet, 0);
        }
        movementPacket = (u8 *)btlUnitCreateMoveToUnitPacket(*(BtlUnit **)(action + 0x30),
                        *(BtlUnit **)(target + 0x30), distance, fGpffff811c, 10);
        *(s64 *)(movementPacket + 0x60) = *(s64 *)action;
        btlPacketEnqueue(movementPacket, 0);
    } else {
        movementPacket = func_00194b60();
        *(s64 *)(movementPacket + 0x60) = *(s64 *)action;
        btlPacketEnqueue(movementPacket, 0);
    }
    {
        u8 *packet;
        packet = btlPacketCreateSpriteTable(*(u32 *)(action + 0x30), displayMode);
        packet[0] = 4;
        *(s64 *)(packet + 8) = *(s64 *)(movementPacket + 0x58);
        *(s64 *)(packet + 0x60) = *(s64 *)action;
        btlPacketEnqueue(packet, 3);
    }
    {
        u8 *packet;
        packet = (u8 *)btlFormationCreateWaitPacket(*(u32 *)(action + 0x30), *(u32 *)(target + 0x30), formationMode);
        packet[0] = 4;
        *(s64 *)(packet + 8) = *(s64 *)(movementPacket + 0x58);
        *(s64 *)(packet + 0x60) = *(s64 *)action;
        btlPacketEnqueue(packet, 0);
    }
    {
        u8 *packet;
        packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 42);
        packet[0] = 4;
        *(s64 *)(packet + 8) = *(s64 *)(movementPacket + 0x58);
        *(s64 *)(packet + 0x60) = *(s64 *)action;
        btlPacketEnqueue(packet, 0);
    }
    if ((u16)afterVoice != 0) {
        {
            u8 *packet;
            packet = (u8 *)btlVoiceCreatePacket((BtlAction *)action, afterVoice,
                             *(u16 *)(*(u8 **)(target + 0x30) + 0xA4), 0, 0);
            packet[0] = 4;
            *(s64 *)(packet + 8) = *(s64 *)(movementPacket + 0x58);
            *(s64 *)(packet + 0x60) = *(s64 *)action;
            btlPacketEnqueue(packet, 1);
        }
    }
    {
        u8 *packet;
        packet = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(action + 0x30),
                                             (s16)sourceAnimation, 0, 1.0f, 0);
        packet[0] = 4;
        *(s64 *)(packet + 8) = *(s64 *)(movementPacket + 0x58);
        *(s64 *)(packet + 0x60) = *(s64 *)action;
        *(s16 *)(packet + 0x4A) = btlUnitMotionModelFrames(*(u8 **)(action + 0x30), sourceAnimation, 1.0f);
        btlPacketEnqueue(packet, 0);
    }
    animationPacket = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(target + 0x30),
                                                  (s16)targetAnimation, 0, 1.0f, 0);
    animationPacket[0] = 4;
    *(s64 *)(animationPacket + 8) = *(s64 *)(movementPacket + 0x58);
    *(s64 *)(animationPacket + 0x60) = *(s64 *)action;
    delayedFrame = (s16)targetFrame;
    *(s16 *)(animationPacket + 0x48) = targetFrame;
    btlPacketEnqueue(animationPacket, 0);
    if (selectedEffect.slot != -1) {
        {
            u8 *packet;
            const ActionRecoveryResourceView *resourceBase;
            resourceBase = (const ActionRecoveryResourceView *)iGpffffb3ac;
            packet = (u8 *)btlFormationCreatePacket(actionRecoveryResourceAt(resourceBase, selectedEffect.slot),
                                        *(u32 *)(action + 0x30), *(u32 *)(target + 0x30), 1, 0);
            packet[0] = 4;
            *(s64 *)(packet + 8) = *(s64 *)(movementPacket + 0x58);
            *(s64 *)(packet + 0x60) = *(s64 *)action;
            *(s16 *)(packet + 0x48) = delayedFrame;
            btlPacketEnqueue(packet, 2);
        }
    }
    func_001f0a10((u8 *)&result);
    result.values[3] = resultFlags;
    {
        u8 *packet;
        packet = (u8 *)btlTargetCreateDataPacket((s32)target, (s32)target, &result, 1, 1);
        packet[0] = 4;
        *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
        *(s16 *)(packet + 0x48) = delayedFrame;
        *(s64 *)(packet + 0x60) = *(s64 *)action;
        btlPacketEnqueue(packet, 1);
    }
}

#pragma pop
// FUN_001A3D50
void btlActionCooperateUpdate(BtlAction *action)
{
    if (func_00193bf0(*(s64 *)action, 0x3FFFFFFFFFFFFFFFLL) == 0) {
        *(s16 *)((u8 *)action + 0x448) = -1;
        *(s32 *)(D_0076449C + 0xC) |= 0x400000;
        *(u16 *)(D_0076449C + 0x18) |= 7;
        btlActionSetState(action, 0x20);
    }
}

// FUN_001A3DE0
s32 btlActionGetCounter420(BtlAction *action)
{
    return *(s32 *)((u8 *)action + 0x420);
}

// FUN_001A3DF0
void btlActionPursuitMesInit(BtlAction *action)
{
    s32 status;
    u8 *iter;
    u8 *temp;
    s64 *current;

    iter = *(u8 **)(D_0076449C + 0x174);
    goto loop_test;
loop_body:
    if (func_001a05f0((BtlAction *)iter) != 0) {
        temp = (u8 *)btlUnitCreateModelReleasePacket(*(BtlUnit **)(*(u8 **)(iter + 0x30) + 0xA0C));
        *(s64 *)(temp + 0x60) = *(s64 *)iter;
        btlPacketEnqueue(temp, 1);
    }
    iter = *(u8 **)(iter + 0x450);
loop_test:
    if (iter != NULL) {
        goto loop_body;
    }
    status = 1;
    current = func_001b1540();
    if ((*(u16 *)((u8 *)current + 0x18) & 8) != 0 &&
        func_0019ff60((u8 *)current) != 0) {
        status = 0;
    }
    if (status == 1) {
        status = func_001d94d0(
            (u8 *)action,
            datCalcSkillElement(
                *(u8 **)(*(u8 **)((u8 *)action + 0x30) + 0xA64),
                func_001f01a0((u8 *)action, *(u8 **)((u8 *)action + 0x90)) & 0xFFFF) & 0xFFFF,
            2, 0x80000, 2, btlAICommandNomalStatusCheck);
    }
    if (status == 0) {
        temp = func_001fa9c0();
        *(s64 *)(temp + 0x60) = *(s64 *)action;
        btlPacketEnqueue(temp, 1);
        btlActionSetState(action, 0x20);
        return;
    }
    if (func_001eb860() == 1) {
        *(s32 *)(D_0076449C + 0xC) &= ~0x2000;
        btlDamageSetSource(*(u8 **)(D_0076449C + 0xDD4), 0);
    }
    *(s32 *)((u8 *)action + 0x41C) = 0;
    *(s32 *)((u8 *)action + 0x420) = 0;
}

// FUN_001A3F90
void btlActionPursuitMesUpdate(u8 *arg0)
{
    u8 frame[0x10];
    struct {
        u8 pad[0x30];
        s32 field_30;
    } *partner;
    s64 *targetUnit;
    u16 waitFrames;
    u8 *waitPacket;
    u8 *effectPacket;

    if (*(s32 *)(arg0 + 0x41C) == 0) {
        if ((btlCountUnitRecordsById(0xC00) == 0) && (btlCountUnitRecordsById(0xC04) == 0)) {
            *(s16 *)(frame + 0) = 2;
            *(u16 *)(frame + 2) =
                *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4);
            btlPacketEnqueue(btlCutinCreatePacket(frame), 1);
            btlActionFinishPresentation((BtlAction *)arg0);
            btlPacketEnqueue(btlPacketCreateEndSequence(), 1);
            btlPacketEnqueue(func_001fa8f0(), 1);
            btlMessageStartLong(*(u8 **)(D_0076449C + 0xDD4), (u8 *)arg0);
            btlPacketEnqueue((u8 *)btlFormationCreateSlotPacket(3, 0xFFF), 0);
            partner = (void *)func_001b1540();
            btlPacketEnqueue(
                btlUnitCreateRotateTowardUnitPacket((u8 *)partner->field_30,
                              *(u8 **)(arg0 + 0x30), 2),
                0);
            btlPacketEnqueue(
                btlUnitCreateRotateTowardUnitPacket(*(u8 **)(arg0 + 0x30),
                              (u8 *)partner->field_30, 2),
                0);
            btlPacketEnqueue(
                (u8 *)btlUnitCreateLookAtDeactivatePacket((BtlUnit *)partner->field_30, 0),
                1);
            btlPacketEnqueue(
                actionLookAtUnit(*(u8 **)(arg0 + 0x30),
                              (u8 *)partner->field_30, 0),
                1);
            btlPacketEnqueue((u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x30), 0);
            waitPacket = btlPacketAllocZeroed((s32)btlActionGetCounter420, (s32)arg0);
            btlPacketEnqueue(waitPacket, 1);
            btlPacketEnqueue(
                func_001d65d0(*(s32 *)(D_0076449C + 0xD90),
                              *(s32 *)(arg0 + 0x30), 0,
                              *(s64 *)(waitPacket + 0x58), 0xC000),
                2);
            if (func_001eb860() == 1) {
                *(s32 *)(D_0076449C + 0xC) |= 0x2000;
                btlDamageSetSource(*(u8 **)(D_0076449C + 0xDD4), 1);
            }
            *(s32 *)(arg0 + 0x41C) = 1;
        }
    } else if (*(s32 *)(arg0 + 0x420) == 0) {
        if (btlMessageIsActiveAlt(*(s32 *)(D_0076449C + 0xDD4)) != 0) {
            if (btlMessageGetResultAlt(*(s32 *)(D_0076449C + 0xDD4)) != 0) {
                btlPacketEnqueue(func_001f99c0((u8 *)arg0, 8, 0, 0, 0), 1);
                effectPacket = btlCutinCreateStartPacket();
                *(s8 *)(effectPacket + 0) = 0xA;
                *(s16 *)(effectPacket + 8) = 0xC00;
                *(s64 *)(effectPacket + 0x60) = *(s64 *)arg0;
                btlPacketEnqueue(effectPacket, 1);
                btlPacketEnqueue(btlFormationCreateDefaultPacket(), 1);
            }
            btlPacketEnqueue(func_001faa60(), 1);
            *(s32 *)(arg0 + 0x420) = 1;
            *(u16 *)(arg0 + 0x424) = 6;
        }
    } else {
        waitFrames = *(u16 *)(arg0 + 0x424);
        if (waitFrames == 0) {
            btlPacketEnqueue((u8 *)btlUnitCreateLookAtDeactivatePacket(0, 3), 1);
            if (btlMessageGetResultAlt(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
                targetUnit = func_001b1540();
                btlPacketEnqueue(btlTargetCreateActionPacket((u8 *)targetUnit, 2), 1);
                *(u16 *)((u8 *)targetUnit + 0x18) |= 0x8000;
                btlActionSetState((BtlAction *)arg0, 0xE);
            } else {
                btlActionSetState((BtlAction *)arg0, 0x20);
            }
            btlMessageResetAlt(*(s32 *)(D_0076449C + 0xDD4));
            return;
        }
        *(u16 *)(arg0 + 0x424) = waitFrames - 1;
    }
}

// FUN_001A4390
void btlActionPursuitInit(void)
{
}

/* Recovered action selection. Configured b210 -O2 emits 1092 retail bytes
 * plus 12 zero alignment bytes. The workspace keeps the signed element in
 * actual halfword storage and both twelve-entry target lists at their observed
 * 16-byte alignment. Scalarization is disabled for this storage; propagation
 * is disabled to preserve the unit load before the element's signed-word
 * promotion. The affinity provider retains its canonical s32 input. */
#pragma push
/* Keep the promoted shuffle count and output base at their explicit
 * phase boundaries. The index reference preserves each narrow read. */
/* Select eligible targets, preserving the reference action when required,
 * then queue voice, cut-in and dependent formation packets. Both local
 * target lists hold twelve entries; single-target selection requires
 * a nonempty eligible set. */
/* measured: func_001a43a0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001A43A0
void btlActionPursuitUpdate(u8 *action)
{
    extern s8 datCalcGetBuffStatus(u8 *action, s32 arg1);
    extern BtlPacket *btlVoiceCreatePacket(BtlAction *action, u16 kind, s32 id, s32 flags, s32 mode);
    struct {
        s16 element;
        u8 *preferred[12] __attribute__((aligned(16)));
        u8 *other[12] __attribute__((aligned(16)));
    } targets;
    u8 *candidate;
    u8 *referenceAction;
    u16 scanIndex;
    u16 otherCount;
    u16 preferredCount;
    u8 *workspace;
    u16 skill;
    s32 hasReferenceAction;
    u16 targetMode;
    s32 rawElement;
    u8 *task;

    if (btlCountUnitRecordsById(0xC00) != 0) {
        return;
    }
    referenceAction = *(u8 **)(action + 0x90);
    skill = func_001f01a0(action, referenceAction);
    targetMode = btlSkillClassifyTargets(action, action + 0x98, skill, 0);
    rawElement = datCalcSkillElement(*(u8 **)(*(u8 **)(action + 0x30) + 0xA64), skill);
    hasReferenceAction = 0;
    otherCount = 0;
    preferredCount = 0;
    scanIndex = 0;
    targets.element = (s16)rawElement;
    for (; scanIndex < *(u16 *)(action + 0xD0); scanIndex++) {
        candidate = actionReadCandidate(action, &scanIndex);
        if (!(*(u16 *)(candidate + 0x1A) & 1)) {
            continue;
        }
        workspace = *(u8 **)(candidate + 0x30);
        if (datCalcIsDead(*(s32 *)(workspace + 0xA64), 0) != 0) {
            continue;
        }
        if (datCalcGetBuffStatus(*(u8 **)(workspace + 0xA64), 0x10) > 0) {
            continue;
        }
        {
            u8 *affinityUnit = *(u8 **)(workspace + 0xA64);
            s32 affinityElement = targets.element;

            if (datCalcAilmentChance(affinityUnit, affinityElement) & 0x7000000) {
                continue;
            }
        }
        if (datCalcChkBadStatus(*(s32 *)(workspace + 0xA64), 0x100000) == 0) {
            targets.preferred[preferredCount++] = candidate;
        }
        if (referenceAction != candidate) {
            targets.other[otherCount++] = candidate;
        } else {
            hasReferenceAction = 1;
        }
    }
    func_001eb3b0(action + 0x38);
    *(s16 *)(action + 0x6C) = 2;
    *(u16 *)(action + 0x6E) = skill;
    if (targetMode == 0) {
        if (preferredCount > 0) {
            *(u8 **)(action + 0x38) = targets.preferred[datCalcRandomBelow(preferredCount)];
        } else if (hasReferenceAction) {
            *(u8 **)(action + 0x38) = referenceAction;
        } else {
            *(u8 **)(action + 0x38) = targets.other[datCalcRandomBelow(otherCount)];
        }
        *(u16 *)(action + 0x6A) = 1;
    } else {
        s32 availableCount;
        s32 shuffleLimit;
        u16 outputStart;
        u16 shuffleIndex;

        shuffleIndex = 0;
        availableCount = otherCount;
        shuffleLimit = availableCount * 3;
        for (; shuffleIndex < shuffleLimit; shuffleIndex++) {
            u16 firstIndex = datCalcRandomBelow(availableCount);
            u16 secondIndex = datCalcRandomBelow(availableCount);

            if (firstIndex != secondIndex) {
                u8 *savedTarget = targets.other[firstIndex];

                targets.other[firstIndex] = targets.other[secondIndex];
                targets.other[secondIndex] = savedTarget;
            }
        }
        if (hasReferenceAction) {
            *(u8 **)(action + 0x38) = referenceAction;
            *(u16 *)(action + 0x6A) = 1;
            outputStart = 1;
        } else {
            *(u16 *)(action + 0x6A) = 0;
            outputStart = 0;
        }
        if (availableCount > 1) {
            if (availableCount == 2) {
                otherCount = 1;
            } else {
                otherCount = datCalcRandomBelow(availableCount - 1) + 1;
            }
        }
        {
            u16 copyIndex;
            u8 *outputBase;
            s32 appendCount;

            copyIndex = 0;
            outputBase = action + outputStart * 4;
            appendCount = otherCount;
            for (; copyIndex < appendCount; copyIndex++) {
                *(u8 **)(outputBase + copyIndex * 4 + 0x38) = targets.other[copyIndex];
            }
        }
        *(u16 *)(action + 0x6A) += otherCount;
    }
    *(u16 *)(action + 0x18) |= 2;
    task = (u8 *)btlVoiceCreatePacket((BtlAction *)action, 9, 0, 0, 0);
    *(u64 *)(task + 0x60) = *(u64 *)action;
    btlPacketEnqueue(task, 1);
    workspace = btlCutinCreateEndPacket();
    *(u64 *)(workspace + 0x60) = *(u64 *)action;
    btlPacketEnqueue(workspace, 1);
    task = btlFormationCreateDefaultPacket();
    task[0] = 4;
    *(u64 *)(task + 8) = *(u64 *)(workspace + 0x58);
    btlPacketEnqueue(task, 1);
    btlActionSetState((BtlAction *)action, 0xF);
}

#pragma pop
// FUN_001A47F0
void btlActionReadyInit(void)
{
}

#pragma push
/* measured: b210 -O2 with this scoped setting emits 1148/1152 exact bytes.
 * The ushort counter wrap and offset-first helper preserve retail's operation
 * order. All 39 code relocations and the 52-byte switch table were resolved. */
/* measured: func_001a4800 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
// FUN_001A4800
/* Wait for the participating actions before dispatching the selected action
 * type and submitting its target-state and camera packets. */
void btlActionReadyUpdate(u8 *arg0)
{
    extern void func_001eb420(u8 *target);
    extern u16 *datPersonaGetRecord(u16 personaId);
    extern s32 datPersonaFindSkillSlot(u8 *persona, u16 skillId);
    extern s32 btlActionSkillReachesTargets(u8 *action);
    extern void btlActionRollGroupRatio(s32 state);
    extern s32 func_001f68e0(u8 *action);
    extern void btlUnitApplyPacketFlags(u8 *action);
    s32 loopIndex;
    s32 delayFlag;
    s32 actionIndex;
    s32 personaId;
    u16 actionKind;
    u8 *otherAction;
    ActionState001a4800 *battleState;
    if (((s32)(btlCountUnitRecordsById(0x506)) == (s32)(0)) && ((s32)(btlCountUnitRecordsById(0xC05)) == (s32)(0))) {
        actionIndex = 0;
        while ((s32)(loopIndex = actionIndex & 0xFFFF) < (s32)(*(u16 *)((u8 *)arg0 + 0x6A))) {
            otherAction = (u8 *)((*(u8 **)((u8 *)(((s32)(arg0) + ((actionIndex & 0xFFFF) * 4))) + 0x38)));
            if ((s32)(arg0) == (s32)(otherAction)) {
                goto incr;
            }
            if (!((*(u16 *)((u8 *)(otherAction) + 0x1A)) & 1)) {
                goto incr;
            }
            if (((s32)(datCalcIsDead((*(s32 *)((u8 *)((*(s32 *)((u8 *)(otherAction) + 0x30))) + 0xA64)), 0)) != (s32)(0))) {
                goto incr;
            }
            if ((*(u16 *)((u8 *)(otherAction) + 0xC)) != 1) {
                goto donecheck;
            }
incr:
            actionIndex = (actionIndex + 1) & 0xFFFF;
        }
donecheck:
        if (loopIndex == (*( u16*)((u8 *)(arg0) + 0x6A))) {
            if (!((*( u16*)((u8 *)(arg0) + 0x18)) & 4)) {
                func_001eb420(arg0 + 0x38);
            }
            (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) & 0xFFFD));
            delayFlag = 0;
            actionKind = (u16)((u16)((*( u16*)((u8 *)(arg0) + 0x6C))));
            switch (actionKind) {
            case 1:
            case 2:
            case 3:
                delayFlag = 1;
                /* fallthrough */
            case 9:
                func_001f14f0(arg0);
                if ((*( u8*)((u8 *)(func_001a_add_offset(*(u16 *)(arg0 + 0x6E) * 0x28, (s32)iGpffffb3b8)) + 0x24)) == 5) {
                    btlActionSetState((BtlAction *)arg0, 0x20U);
                } else if ((*( s32*)((u8 *)(arg0) + 0xE8)) == 1) {
                    btlActionSetState((BtlAction *)arg0, 0x17U);
                } else if ((s32)(btlActionSkillReachesTargets(arg0)) != (s32)(0)) {
                    (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) & 0xFFEF));
                    btlActionSetState((BtlAction *)arg0, 0x10U);
                } else {
                    (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) | 0x10));
                    btlActionSetState((BtlAction *)arg0, 0x11U);
                }
                break;
            case 7:
            case 8:
            case 11:
                btlActionSetState((BtlAction *)arg0, 0x19U);
                break;
            case 6:
                if ((s32)((*( u8*)((*( u8**)((u8 *)(arg0) + 0x30)) + 0xA2))) == (s32)(0)) {
                    if ((s32)(datGetFlag(0x38)) != (s32)(0)) {
                        personaId = 5;
                    } else {
                        personaId = 8;
                    }
                    if (((s32)(datPersonaFindSkillSlot((u8 *)datPersonaGetRecord(personaId & 0xFFFF), 0x114)) != (s32)(-1)) || ((battleState = (ActionState001a4800 *)iGpffffb3ac)->kind == 1 && (battleState->flags & 2))) {
                        btlPacketEnqueue(actionTargetPacketBytes(arg0, 8, 0, 0, 3), 1);
                        btlPacketEnqueue((u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 8), 0);
                        actionSetDelayBytes(arg0, 0x1D, 0xC);
                    } else {
                        btlActionRollGroupRatio(0);
                        btlPacketEnqueue(actionTargetPacketBytes(arg0, 3, 0, 0, 2), 1);
                        btlPacketEnqueue(btlTargetCreateActionPacket(arg0, 0U), 1);
                        btlPacketEnqueue((u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 1), 0);
                        if ((s32)(func_001f68e0(arg0)) != (s32)(0)) {
                            actionSetDelayBytes(arg0, 0x1B, 0xC);
                        } else {
                            actionSetDelayBytes(arg0, 0x20, 0xC);
                        }
                    }
                } else {
                    btlActionSetState((BtlAction *)arg0, 0x1DU);
                }
                break;
            case 12:
                btlActionSetState((BtlAction *)arg0, 0x1DU);
                break;
            case 5:
                btlActionSetState((BtlAction *)arg0, 0x1AU);
                break;
            case 10:
                btlActionSetState((BtlAction *)arg0, 7U);
                break;
            }
            if ((delayFlag != 0) && ((s32)(func_001a0140(arg0)) != (s32)(0))) {
                (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) | 8));
            } else {
                (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) & 0xFFF7));
            }
            btlUnitApplyPacketFlags(arg0);
        }
    }
}

#pragma pop
/* Measured 2026-09-30 with the coherent motion-provider family: 2336 bytes,
 * zero instruction differences. Both motion locals use the provider's u16
 * selector domain; no wide temporary or local ABI override is needed.
 * Scoped lifetime optimization and preserved assignments retain the range
 * predicate and speed-table control flow. Position and rotation providers
 * consume three and four floats respectively. Action actors are kind 0/1,
 * created by 0019f5f0; the selector's other retail cases remain intact. */
// FUN_001A4C80
#pragma push
/* measured: func_001a4c80 MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
/* measured: func_001a4c80 MATCH -> MISMATCH without this pragma. */
#pragma opt_dead_assignments off
void btlActionMoveTargetInit(u8 *actionBytes)
{
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
    extern void func_00195c50(BtlUnit *unit, BtlUnit *target, RwV3d *out);
    extern void func_001951f0(u8 *subunit, u8 *unit, u8 *target, s32 motion,
                            f32 *position, f32 *rotation, s32 placement);
    extern void btlTargetBlendVectors(u8 *rotation, u8 *from, u8 *to);
    extern f32 RwV3dLength(const RwV3d *vector);
    extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *vector);
    extern s32 func_00243d80(u8 *unitData);
    extern s32 btlActionAnyTargetHitRowFlagged(u8 *actionBytes);
    extern s32 btlActionAnyTargetFlagged(u8 *actionBytes);
    extern s32 btlActionHasNoTargetClass(u32 action);
    extern s32 btlEncounterSkipsPresentation(void);
    extern u8 *iGpffffb3bc;
    extern f32 fGpffff8360;
    typedef struct UnitView {
        u8 unknown00[8];
        f32 y;
        u8 unknown0C[0x2C - 0x0C];
        f32 scale;
        u8 unknown30[0x90 - 0x30];
        f32 radius;
        u8 unknown94[0xA2 - 0x94];
        u8 kind;
        u8 unknownA3[0xA64 - 0xA3];
        u8 *data;
    } UnitView;
    typedef struct ActionView {
        s64 uid;
        u8 unknown08[0x10];
        u16 flags;
        u8 unknown1A[0x16];
        UnitView *unit;
        u8 unknown34[4];
        struct ActionView *target;
        u8 unknown3C[0x30];
        u16 mode;
        u16 skill;
    } ActionView;
    union { RwV3d vector; f32 values[3]; } destination;
    RwV3d awayDirection;
    RwV3d homeOffset;
    RwV3d unitCenter;
    RwV3d targetCenter;
    f32 rotation[4];
    ActionView *action;
    UnitView *unit;
    UnitView *targetUnit;
    u16 skill;
    s32 skillOffset;
    u8 *subunit;
    s32 proceed;
    s32 reposition;
    s32 inRange;
    s32 canPosition;
    f32 distance;
    f32 speed;

    action = (ActionView *)actionBytes;
    skill = action->skill;
    skillOffset = skill * 4;
    if ((*(u16 *)((u32)skillOffset + (u32)iGpffffb3bc + 2) & 0x8000) != 0) {
        return;
    }
    if ((*(s32 *)(iGpffffb3ac + 0x10) & 0x2000) != 0) {
        return;
    }
    proceed = 1;
    inRange = 0;
    reposition = 0;
    {
        u8 *packet;
        packet = (u8 *)btlUnitCreateLookAtUnitPacket(NULL, (BtlUnit *)action->unit, 3);
        *(s64 *)(packet + 0x60) = action->uid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlUnitCreateLookAtDeactivatePacket((BtlUnit *)action->unit, 0);
        *(s64 *)(packet + 0x60) = action->uid;
        btlPacketEnqueue(packet, 1);
    }
    action->flags |= 0x200;
    if ((*(u8 *)(iGpffffb3b8 + skill * 0x28) & 2) != 0) {
        s32 pairedTargets;
        UnitView *predicateUnit;
        pairedTargets = btlActionAnyTargetFlagged((u8 *)action);
        predicateUnit = action->unit;
        do {
            switch (predicateUnit->kind) {
            case 0: {
                u8 *data;
                u16 unitId;
                s32 ranged;
                u32 rangeTable;
                u32 rangeOffset;
                data = predicateUnit->data;
                unitId = *(u16 *)(data + 2);
                ranged = 1;
                switch (predicateUnit->kind) {
                case 0:
                    {
                        s32 classification;
                        classification = func_0023e1f0(data) & 0xFF;
                        if (classification == 5) {
                            ranged = 1;
                        } else if (classification == 3 && ((*(u16 *)((u32)skillOffset + (u32)iGpffffb3bc + 2) & 0x8000) != 0 || pairedTargets == 0)) {
                            ranged = 1;
                        } else {
                            goto range_ineligible;
                        }
                    }
                    break;
                case 1:
                    rangeTable = (u32)iGpffffb3cc;
                    rangeOffset = (u32)unitId * 0xE8;
                    if (*(s16 *)(rangeOffset + rangeTable + 0x22) == 1) {
                        ranged = 1;
                    } else {
                        goto range_ineligible;
                    }
                    break;
                default:
range_ineligible:
                    ranged = 0;
                    break;
                }
                if (ranged != 0) {
                    ActionView *rangeTarget;
                    rangeTarget = action->target;
                    unit = action->unit;
                    targetUnit = rangeTarget->unit;
                    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0 && unit->kind != targetUnit->kind) {
                        proceed = 0;
                    } else {
                        btlUnitGetSphereWorldCenter((BtlUnit *)unit, &unitCenter);
                        func_00195c50((BtlUnit *)targetUnit, (BtlUnit *)unit, &targetCenter);
                        if (btlTargetVectorDistance(&unitCenter, &targetCenter) < 500.0f) {
                            inRange = 1;
                            proceed = 0;
                        } else {
                            distance = 500.0f;
                        }
                    }
                    goto range_done;
                }
            }
            default:
                break;
            }
            {
                u16 motion;
                unit = action->unit;
                if (unit->kind == 0) {
                    if ((*(u16 *)((u32)skillOffset + (u32)iGpffffb3bc + 2) & 0x8000) != 0) {
                        motion = 7;
                    } else if (pairedTargets != 0) {
                        motion = 5;
                    } else {
                        motion = (u16)(btlActionAnyTargetHitRowFlagged((u8 *)action) != 0 ? 0xC : 4);
                    }
                } else {
                    motion = (u16)(btlActionAnyTargetHitRowFlagged((u8 *)action) != 0 ? 0xC : 4);
                }
                distance = func_00196bd0((u8 *)action->unit, (u8 *)action->target->unit, motion);
            }
range_done:
            ;
        } while (0);
        if ((action->flags & 0x4000) != 0) {
            reposition = 1;
        }
    } else {
        unit = action->unit;
        switch (unit->kind) {
        case 0:
            {
                s32 paired;
                s32 openingMotion;
                targetUnit = action->target->unit;
                subunit = *(u8 **)((u8 *)unit + 0xA0C);
                paired = btlActionHasNoTargetClass((u32)action);
                openingMotion = btlUnitOpeningMotionMode((s32)subunit, (u8 *)unit, (s16)skill, paired) & 0xFFFF;
                canPosition = func_001f1210(subunit, (s16)skill, paired);
                btlUnitGetSphereWorldCenter((BtlUnit *)unit, &unitCenter);
                func_00195c50((BtlUnit *)targetUnit, (BtlUnit *)unit, &targetCenter);
                speed = btlTargetVectorDistance(&unitCenter, &targetCenter);
                speed = speed - unit->radius * unit->scale;
                speed = speed - targetUnit->radius * targetUnit->scale;
                if (canPosition == 0 || btlEncounterSkipsPresentation() == 0 || speed < 300.0f || speed - 300.0f < 200.0f) {
                    action->flags |= 0x10;
                    proceed = 0;
                } else {
                    speed = speed + unit->radius * unit->scale;
                    speed = speed + targetUnit->radius * targetUnit->scale;
                    func_001951f0(subunit, (u8 *)unit, (u8 *)targetUnit, (s16)openingMotion, destination.values, NULL, 2);
                    distance = btlTargetVectorDistance(&destination.vector, &targetCenter);
                    {
                        f32 limit;
                        limit = 300.0f;
                        limit = limit + unit->radius * unit->scale;
                        limit = limit + targetUnit->radius * targetUnit->scale;
                        if (distance < limit) {
                            distance = limit;
                        }
                    }
                    func_001951f0(subunit, (u8 *)unit, NULL, -1, destination.values, NULL, 0);
                    homeOffset.x = destination.vector.x - unitCenter.x;
                    homeOffset.z = destination.vector.z - unitCenter.z;
                    homeOffset.y = 0.0f;
                    distance = distance + RwV3dLength(&homeOffset);
                    if (speed < distance) {
                        action->flags |= 0x10;
                        proceed = 0;
                    }
                }
            }
            break;
        case 1:
            {
                u16 motion;
                motion = (u16)(btlActionAnyTargetHitRowFlagged((u8 *)action) != 0 ? 0xC : 4);
                distance = func_00196bd0((u8 *)action->unit, (u8 *)action->target->unit, motion);
            }
            break;
        }
    }
    if (proceed == 0) {
        return;
    }
    btlActionFinishPresentation((BtlAction *)action);
    {
        u16 speedIndex;
        u16 unitId;
        u16 speedVariant;
        u8 kind;
        u32 table;
        u32 offset;
        u32 record;
        u32 selector;
        u8 *packet;
        proceed = 0;
        speedIndex = 2;
        speedVariant = (u16)(!(*(u8 *)(iGpffffb3b8 + action->skill * 0x28) & 2));
        unit = action->unit;
        unitId = *(u16 *)(unit->data + 2);
        kind = unit->kind;
        switch (kind) {
        case 0:
            break;
        case 1:
            table = (u32)iGpffffb3cc;
            offset = (u32)unitId * 0xE8;
            record = offset + table;
            selector = (u16)speedVariant * 4;
            speedIndex = *(u16 *)(selector + record + 0x24);
            break;
        }
        speed = D_005F6D20[speedIndex];
        if (reposition == 1) {
            if (inRange == 0) {
                targetUnit = action->target->unit;
                btlUnitGetSphereWorldCenter((BtlUnit *)unit, &unitCenter);
                func_00195c50((BtlUnit *)targetUnit, (BtlUnit *)unit, &targetCenter);
                awayDirection.x = unitCenter.x - targetCenter.x;
                awayDirection.z = unitCenter.z - targetCenter.z;
                awayDirection.y = 0.0f;
                RwV3dNormalize(&awayDirection, &awayDirection);
                {
                    f32 span;
                    span = unit->radius * unit->scale;
                    span = span + targetUnit->radius * targetUnit->scale;
                    span = span + distance;
                    span = span + 50.0f;
                    awayDirection.x = awayDirection.x * span;
                    awayDirection.y = awayDirection.y * span;
                    awayDirection.z = awayDirection.z * span;
                }
                destination.vector.x = targetCenter.x + awayDirection.x;
                destination.vector.y = targetCenter.y + awayDirection.y;
                destination.vector.z = targetCenter.z + awayDirection.z;
                destination.vector.y = unit->y;
                btlTargetBlendVectors((u8 *)rotation, (u8 *)destination.values, (u8 *)&targetCenter);
                packet = btlUnitCreateOverridePacket((u8 *)unit, (u8 *)destination.values, (u8 *)rotation, NULL);
                *(s64 *)(packet + 0x60) = action->uid;
                btlPacketEnqueue(packet, 0);
                speed = speed * fGpffff8360;
                proceed = proceed | 8;
            } else {
                speed = speed * 1.25f;
            }
        }
        if (func_00243d80(action->target->unit->data) == 0) {
            proceed = proceed | 0x40;
        }
        packet = (u8 *)btlUnitCreateMoveToUnitPacket((BtlUnit *)action->unit, (BtlUnit *)action->target->unit, distance, speed, proceed);
        *(s64 *)(packet + 0x60) = action->uid;
        btlPacketEnqueue(packet, 0);
        if (packet != NULL && inRange == 0) {
            if (reposition == 0) {
                packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x16);
                *(s64 *)(packet + 0x60) = action->uid;
                btlPacketEnqueue(packet, 0);
            } else {
                packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x17);
                *(s64 *)(packet + 0x60) = action->uid;
                btlPacketEnqueue(packet, 0);
            }
        }
        action->flags &= 0xFFEF;
    }
}

#pragma pop
// FUN_001A55A0
void btlActionMoveTargetUpdate(BtlAction *action) {
    u16 actionState;

    if (btlUnitIsMoving(*(u8 **)((u8 *)action + 0x30)) == 0) {
        switch (*(u16 *)((u8 *)action + 0x6C)) {
        case 1:
            actionState = 0x12;
            break;
        case 2:
        case 3:
            actionState = 0x13;
            break;
        case 9:
            actionState = 0x14;
            break;
        default:
            actionState = 0;
            break;
        }
        btlActionSetState(action, actionState);
    }
}

/* Measured: 656/656 bytes and 15 resolved relocations match retail.
 * Preserve unit/UID reloads across queue callbacks and the ordered distance test. */
#pragma push
/* measured: func_001a5650 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: func_001a5650 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001A5650
void btlActionMoveHomeInit(s64 *arg0)
{
    RwV3d sp30;
    u32 source_offset, sum, idx4;
    f32 speed, scale;
    u16 slotIndex;
    u16 actionKind;
    u16 actionState;
    u16 speedIndex;
    u16 nextState;
    u16 recordIndex;
    u8 unitMode;
    u8 *battleUnit;
    u8 *movePacket;
    u8 *cameraPacket;
    u8 *ctx;
    u8 *actionUnit;

    battleUnit = *(u8 **)((u8 *)arg0 + 0x30);
    ctx = D_0076449C;
    if ((*(s32 *)(ctx + 0xC) & 0x400000) &&
        (*(u16 *)(ctx + 0x18) & 2)) {
        recordIndex = *(u16 *)((u8 *)arg0 + 0x6C);
        switch (recordIndex) {
        case 1:
            actionState = 0x12;
            break;
        case 2:
        case 3:
            actionState = 0x13;
            break;
        case 9:
            actionState = 0x14;
            break;
        default:
            actionState = 0;
            break;
        }
        btlActionSetState((BtlAction *)arg0, actionState);
        return;
    }
    func_00194ff0(battleUnit, (u8 *)&sp30, NULL, NULL);
    if (!(btlTargetVectorDistance((RwV3d *)(battleUnit + 4), &sp30) <= 75.0f)) {
        btlActionFinishPresentation((BtlAction *)arg0);
        speedIndex = 2;
        slotIndex = (!(iGpffffb3b8[
            (*(u16 *)((u8 *)arg0 + 0x6E) * 0x28)] & 2)) & 0xFFFF;
        actionUnit = *(u8 **)((u8 *)arg0 + 0x30);
        recordIndex = *(u16 *)(*(u8 **)(actionUnit + 0xA64) + 2);
        unitMode = *(u8 *)(actionUnit + 0xA2);
        switch (unitMode) {
        case 0:
            break;
        case 1:
            ctx = iGpffffb3cc;
            source_offset = recordIndex * 0xE8;
            sum = source_offset + (u32)ctx;
            idx4 = slotIndex * 4;
            speedIndex = *(u16 *)(idx4 + sum + 0x24);
            break;
        }
        speed = D_005F6D20[speedIndex];
        scale = D_0076144C;
        movePacket = (u8 *)btlUnitCreateMovePacket(
            (BtlUnit *)actionUnit, &sp30,
            speed * scale, 0);
        *(s64 *)(movePacket + 0x60) = *arg0;
        btlPacketEnqueue(movePacket, 1);
        cameraPacket = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x18);
        *(s64 *)(cameraPacket + 0x60) = *arg0;
        btlPacketEnqueue(cameraPacket, 0);
        return;
    }
    actionKind = *(u16 *)((u8 *)arg0 + 0x6C);
    switch (actionKind) {
    case 1:
        nextState = 0x12;
        break;
    case 2:
    case 3:
        nextState = 0x13;
        break;
    case 9:
        nextState = 0x14;
        break;
    default:
        nextState = 0;
        break;
    }
    btlActionSetState((BtlAction *)arg0, nextState);
}

#pragma pop
// FUN_001A58E0
void btlActionMoveHomeUpdate(BtlAction *action) {
    u16 actionState;

    if (btlUnitIsMoving(*(u8 **)((u8 *)action + 0x30)) == 0) {
        switch (*(u16 *)((u8 *)action + 0x6C)) {
        case 1:
            actionState = 0x12;
            break;
        case 2:
        case 3:
            actionState = 0x13;
            break;
        case 9:
            actionState = 0x14;
            break;
        default:
            actionState = 0;
            break;
        }
        btlActionSetState(action, actionState);
    }
}

// FUN_001A5990
void btlActionAttackInit(void)
{
}

/* 2026-10-03 storage repair: preserve action/packet UIDs as doublewords
   and select true 0x20-byte hit records. The old narrowing measurements above
   are historical, not type evidence. See Large_Battle_storage_20261003.md.
   2026-10-08: opt_loop_invariants on lowers fnalign from 837 to 752 edits.
 * 2026-10-09: 752 -> 709: the m2c label loops are while loops.
 * 696: range tests in retail's slti $at form.
 * 666: type sweep.
 * 660: swap sweep.
 * 652: type sweep.
 * 651: type sweep.
 * 646: conversion lever (temp_18:(0, 2)).
 * 642: conversion lever (var_6:(0, 2)).
 * 2026-10-10: 642 -> 614 aligned edits by replacing seven undefined or
 * redundant sign-extension shifts with explicit signed-halfword/byte casts.
 * The local 001d15a0 provider returns s16; measured in battle lane scratch.
 * sdiff struct 413 -> 395: arg0 accessed through a u8 * local; the (u8 *)(s64 *) cast at every use made MWCC CSE and spill field addresses.
 * sdiff struct 395 -> 393: the two close-camera decisions through one inline helper (btlCloseCamera_001a59a0) instead of m2c's switch/goto copies.
 * fnalign 575 -> 545: the 0x13/0x10 selection as a var_2_8 flag test with the 0x13 call first (no goto block_224), as in func_001a7720.
 * fnalign 545 -> 527: the tail state switch (cases 1,3,2 and default both set state 0x20) as in the matched-path sibling 001a7720, with the real btlActionSetState(BtlAction *, u16) prototype (retail daddiu per arm, one shared call).
 * fnalign 527 -> 521: btlCloseCamera reads the unit id before the switch, sends every failing path to one shared result = 0 (default arm, goto fail) and tests the 0x8000 flag first (retail polarity).
 * fnalign 521 -> 493: integer-cast +0x30 unit reads at selected sites (b210 does not CSE the address across calls, as retail).
 * fnalign 493 -> 455: integer-cast field-base reads (no cross-call address CSE).
 * fnalign 455 -> 453: integer-cast field-base reads (second pass).
 * 2026-10-12 measured: fnalign 453 -> 452; the hit-effect flag is a word (retail sw/lw), not s16.
 * 2026-10-12 measured: fnalign 452 -> 405; let the timing APIs narrow their u16 motion argument, without a shared masked temporary.
 * 2026-10-12 measured: fnalign 405 -> 343; captured regalloc requires the source unit before the phase locals. Sound query contracts now match their providers.
 * 2026-10-12 frame audit: fnalign 343 -> 340, frame 0x3C0 -> 0x3B0; voice option is s32 and the target count is already bounded by u16, so no masked spill is needed.
 * 2026-10-12 row lifetime: fnalign 340 -> 335; retain the unbiased target-plus-hit-stride base, restoring retail's separate row spill and +0xF0 payload address (frame 0x3C0).
 * 2026-10-12 UID accessor: fnalign 335 -> 331, frame 0x3C0 -> 0x3B0; inline packet UID reads eliminate the cross-call +0x58 address spill.
 * 2026-10-12 kind accessor: fnalign 331 -> 327, frame 0x3B0 -> 0x3A0; reload the source-unit kind directly rather than spilling its field address.
 * 2026-10-12 effect-unit accessor: fnalign 327 -> 325; inline unit reads in the effect phase replace one spilled-address reload with retail's direct +0x30 load.
 * 2026-10-12 paired-effect unit: fnalign 325 -> 322; the first paired-effect constructor reloads its unit through the existing accessor rather than a spilled field address.
 * 2026-10-12 target layout: fnalign 322 -> 318, frame 0x3A0 -> 0x380; type the target action's effect/flags at 0xDC/0xDE, removing both hoisted field-address spills.
 * 2026-10-12 target unit member: fnalign 318 -> 309, frame 0x380 -> 0x370; recover the target's +0x30 unit field and remove its cross-call address spill.
 * 2026-10-12 selected-action layout: fnalign 309 -> 239, frame 0x370 -> 0x340; the selected action shares the typed +0x30 unit member, eliminating three quadword field-address spills and the redundant accessor.
 * 2026-10-12 animation packet type: fnalign 239 -> 218, frame 0x340 -> retail 0x330; keep the constructor's BtlPacket pointer type, avoiding a coalesced 16-byte byte-pointer spill.
 * 2026-10-12 hit-count consumers: fnalign 218 -> 214; preserve the signed-halfword normalization of the byte-loaded hit count and its conditional snapshot, matching retail's two sign extensions.
 * 2026-10-12 captured spill order: fnalign 214 -> 93, every frameslots offset now agrees at 0x330; declare the surviving packet/result pointers beside their aliases (b210 graph replay preserves their spill choices).
 * 2026-10-12 count/selector joins: fnalign 93 -> 88; keep the repeat-count snapshot signed and the branch-selected effect-table index full-width, removing two non-retail masks.
 * 2026-10-12 row phases: fnalign 88 -> 82; use unsigned byte-address indices inside both loops and recompute the hit-result view after the repeat phase, separate from the retained hitRow snapshot.
 * 2026-10-12 opening scan index: fnalign 82 -> 74; narrow the row index independently from the masked loop bound, preserving retail's separate halfword normalizations.
 * 2026-10-12 opening packet contract: fnalign 74 -> 72; use the matched sibling's BtlPacket *(u32, u16) constructor signature to preserve native halfword argument evaluation.
 * 2026-10-12 paired-target flag: fnalign 72 -> 70; normalize the masked flag before inverting it, matching retail's sltu/xori sequence.
 * 2026-10-12 motion dispatch: fnalign 70 -> 62; recover the two-case switch instead of the empty negated if, preserving retail's two positive tests and default jump.
 * 2026-10-12 camera table order: fnalign 62 -> 56; place the table base before the native halfword index so b210 evaluates the global load before scaling, as in both retail camera checks.
 * 2026-10-12 animation timing dispatch: fnalign 56 -> 54; restore the two-case delay switch, including its explicit default packet-delay path.
 * 2026-10-12 distance-packet address word: fnalign 54 -> 52; read the existing unit-address word at the integer ABI boundary instead of hoisting a pointer-to-integer conversion across the distance branch.
 * 2026-10-12 result-packet address word: fnalign 52 -> 50; likewise read the selected unit as the constructor's native integer address, restoring source/target argument materialization order.
 * 2026-10-12 camera reaching definitions: fnalign 50 -> 23; assign the predicate in each successful case rather than eagerly initializing it, matching both retail constant/load order and the case-1 success jump.
 * 2026-10-12 reaction reaching definitions: fnalign 23 -> 15; retain the truthy byte/random gate values and the ID comparison's shared one until the common decision test, without an extra boolean-result block.
 * 2026-10-12 post-repeat row accessor: fnalign 15 -> 8; reread the halfword index through the byte-row accessor, then retain the caller's typed result snapshot. Retail's lhu/move and every 0x330-frame offset now agree.
 * 2026-10-12 effect-index API: fnalign 8 -> 6; the canonical callee consumes only the skill key's low halfword and remains byte-exact with u16. Its sole C caller now materializes the native halfword argument in retail order.
 * 2026-10-12 camera field origin: fnalign 6 -> 4; pass the first signed-halfword field to the strided reader, preserving the GP load and both retail index-first addu operands. Four branch-target differences remain.
 * 2026-10-12 selected-target join: fnalign 4 -> 3; select into a separate target local before handing it to the packet phase. The coalesced copy retains retail's intermediate branch-only join without emitting an instruction.
 * 2026-10-12 reaction short circuits: fnalign 3 -> 0; stage the real gate values and jump directly to reaction construction on each shortcut. Only the fallback predicate passes through the common boolean test.
 */
#pragma push
/* measured: initial loop-invariant hoisting reduced fnalign from 837 to 752 edits. */
/* measured: func_001a59a0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_001A59A0
void btlActionAttackUpdate(s64 *arg0_) {
    u8 *arg0 = (u8 *)arg0_;
    u8 *battleUnit;
    extern s64 btlPacketEnqueue(u8 *packet, u32 mode);
    extern f32 func_00196040(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter, f32 *outTop, f32 *outBottom, u32 options);
    extern u8 *btlUnitCreateArcMovePacket();
    extern u8 *btlUnitCreateRotateTowardUnitPacket();
    extern u8 *btlCameraCreateSetStatePacket();
    /* Retail's call at 0x001A6F38 returns the packet in $v0, consumed by
       the +0/+8/+0x60 stores at 0x001A6F48..58. The provider's existing
       void spelling omits that live return; this pointer result is required. */
    extern u8 *func_001bccc0(s32 kind, s16 duration, s32 argument, s32 flags);
    extern BtlPacket *btlFormationCreateMovePacket(u32 source, u32 target, f32 distance, u16 mode);
    extern u8 *btlFormationCreateWaitPacket();
    extern u8 *btlFormationCreatePacket();
    extern u16 btlTargetGetUnitIndex(BtlTarget *target);
    extern s32 func_001f08c0();
    extern void func_001f0a10(u8 *result);
    extern s32 btlActionAnyTargetSpecialHit();
    extern s32 func_001f0dd0();
    extern u32 func_001f0f70(u8 *action);
    extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
    extern u8 *btlTargetCreateRecordPacket();
    extern u8 *btlTargetCreateTargetPacket();
    extern s32 func_001f68e0();
    extern void func_001f7830(u8 *unit, s32 hit, s32 paired, s16 *cue, s16 *variant);
    extern void func_001f7910(u8 *unit, u32 hit, s32 paired, s16 *cue, s16 *variant);
    extern BtlPacket *btlSoundCreateChannelCuePacket(u16 channel, u16 cue, u16 variant);
    extern u8 *func_001f99c0(u8 *action, u16 voice, s32 option, s32 argument, s32 flags);
    extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
    extern BtlPacket *btlEffectCreateSpriteFramePacket(u32 unit, u16 skill);
    extern u8 *btlPacketCreateEffectCounter();
    extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 kind, s16 value);
    extern u8 *iGpffffb3ac;
    extern u8 *iGpffffb3bc;
    extern u8 *iGpffffb3cc;
    extern f32 fGpffff8128;
    extern f32 fGpffff8358;

    typedef struct ActionTargetView {
        u8 prefix[0x30];
        u8 *unit;         /* 0x30 */
        u8 unknown34[0xDC - 0x34];
        u16 effect;       /* 0xDC */
        u16 targetFlags;  /* 0xDE */
    } ActionTargetView;
    typedef struct ActionHitRowView {
        u8 actionPrefix[0xF0];
        LargeBattleHitResult result;
    } ActionHitRowView;
    s16 hitCue;
    s16 hitVariant;
    /* 001a0290 writes both signed halfword effect indices. */
    s16 effectIndices[2];
    /* The constructor copies ten bytes; mode 3 uses the first four. */
    struct { u16 mode, unitId; u8 reserved[6]; } cutin;
    RwV3d targetPosition;
    LargeBattleHitResult result;
    BtlPacket *hitAnimPacketSaved;
    BtlPacket *hitAnimPacket;
    u8 *leadPacketSaved;
    u8 *leadPacket;
    u8 *counterAnimPacketSaved;
    u8 *counterAnimPacket;
    s64 hitPacketUid;
    s32 hitTiming;
    s32 hitMotion;
    s32 reactionUnitCount;
    s32 earlyDelta;
    s32 lateDelta;
    u16 hitIndexCounter;
    s32 unitFlag10E;
    s32 hasReaction;
    s32 hasTargetE4;
    s32 hasTargetFlags6;
    s32 isPrimaryHit;
    s32 setEffectFlags;
    s32 counterPending;
    s32 shortRangeFlag;
    u32 hitIndex;
    LargeBattleHitResult *hitResultSaved;
    LargeBattleHitResult *hitResultPtr;
    u16 targetIndex;
    u16 hitRowIndex;
    s32 actionFlagSaved;
    s32 hasCounterUnit;
    s32 baseDurationSaved;
    s32 animDuration;
    s32 timingValueWide;
    s32 timingValueShifted;
    s16 hitRowCount;
    s32 targetFlagDASaved;
    s32 hitCount;
    s32 lastHitIndex;
    s32 hitRowLimit;
    ActionHitRowView *hitRow;
    u32 *addedStatus;
    s32 reactionRoll;
    s32 counterUnitId;
    s32 hitRowNumber;
    s32 targetNumber;
    f32 timeScale;
    s32 timingAdjustment;
    f32 shortRangeDistance;
    s32 actionFlag;
    s16 counterUnitId16;
    s16 auxEffectIndex;
    s16 auxEffectIndexTarget;
    s32 hitTimingBase;
    s32 startDelay;
    s32 animDelay;
    s32 timingRemaining;
    s32 hitDelay;
    s32 counterDuration;
    s32 timingDelta;
    s32 targetRowIndex;
    s32 actionVariant;
    s32 hasStatusFlag;
    s32 hitEffectIndex;
    s32 reactionCueFlag;
    s32 closeCameraResult;
    s32 closeCameraResultB;
    s32 unitIndex;
    ActionTargetView *targetView;
    ActionTargetView *focusTarget;
    ActionTargetView *selectedTarget;
    s64 animUid;
    s64 actionUid;
    s32 timingValue16;
    s16 hitCountShort;
    s32 baseDuration;
    s32 reactionRemaining;
    s16 scaledBase;
    s32 timingValue;
    s32 actionDuration;
    s32 actionKind;
    s8 rowMotion;
    u16 targetCount;
    u32 randomRoll;
    s16 targetFlagDA;
    u8 *cameraEventPacket;
    u8 *cuePacket;
    u8 *effectPacket;
    u8 *effectPacketB;
    u8 *resultPacket;
    u8 *reactionPacket;
    u8 *rotatePacketTarget;
    u8 *actionPacket;
    u8 *rotatePacketFocus;
    u8 *cameraPacketFocus;
    u8 *movePacket;
    u8 *animPacketFocus;
    u8 *animPacketTarget;
    u8 *nearMovePacket;
    u8 *cuePacketB;
    u8 *rotatePacket;
    u8 *effectPacketC;
    u8 *cuePacketC;
    u8 *effectPacketD;
    u8 *cuePacketD;
    u8 *cuePacketE;
    u8 *cuePacketF;
    u8 *effectPacketE;
    u8 *effectPacketF;
    u8 *cuePacketG;
    u8 *cuePacketH;
    u8 *rotateToPointPacket;
    u8 *cuePacketI;
    u8 *effectPacketG;
    u8 *effectPacketH;
    u8 *effectPacketI;
    u8 *effectPacketJ;
    u8 *hitPacket;
    u8 *shakePacket;
    u8 *resultPacketB;
    u8 *statusPacket;
    u8 *statPacket;
    u8 *cuePacketJ;
    u8 *actionPacketB;
    u8 *reactionPacketB;
    u8 *reactionPacketC;
    u8 *actionPacketC;
    u8 *actionPacketD;
    u8 *unitStatePacket;
    u8 *unitStatePacketB;
    u8 *unitStatePacketC;
    u8 *unitStatePacketD;
    u8 *statePacket;
    u8 *battleStatePtrD;
    u8 *battleStatePtrB;
    u8 *cutinUnit;
    u8 *unitEntry;
    u8 *focusUnit;
    u8 *battleStatePtr;
    u8 *battleStatePtrC;
    u8 *focusUnitB;
    u8 *focusUnitC;
    u8 *focusUnitD;
    u8 *focusUnitE;
    u8 *targetRow;
    u8 *cameraPacket;
    u8 *effectPacketK;

    /* hitTimingBase init removed */
    btlActionFinishPresentation((BtlAction *)arg0);
    actionUid = (s64)((*(s64 *)(arg0 + (0))));
    hitPacketUid = 0;
    battleUnit = (u8 *)((*(u8 **)(arg0 + (0x30))));
    actionFlag = (s32)(s32)(((*(u16 *)(arg0 + (0x18))) & 0x4000) != 0);
    actionFlagSaved = actionFlag;
    hasCounterUnit = (s32)(s32)((*(s64 **)(arg0 + (0x88))) != NULL);
    if (actionFlag != 0) {
        timeScale = 1.75f;
    } else {
        timeScale = 1.0f;
    }
    reactionUnitCount = 0;
    unitFlag10E = 0;
    hasReaction = 0;
    hasStatusFlag = 0;
    hasTargetE4 = 0;
    hasTargetFlags6 = 0;
    counterPending = 0;
    setEffectFlags = 0;
    btlPacketEnqueue((u8 *)btlEffectCreateSpriteFramePacket((u32)battleUnit, (*(u16 *)(arg0 + (0x6E)))), 3);
    func_001a0290((BtlAction *)arg0, (*(u16 *)(arg0 + (0x6E))), (u8 *)effectIndices);
    if ((*(u16 *)(arg0 + (0x6A))) == 1) {
        rotatePacket = (u8 *)(btlUnitCreateRotateTowardUnitPacket((*(u8 **)(arg0 + (0x30))), (*(u8 **)((u8 *)((*(u8 **)(arg0 + (0x38)))) + (0x30))), 0));
        (*(s64 *)((u8 *)(rotatePacket) + (0x60))) = actionUid;
        btlPacketEnqueue(rotatePacket, 0);
    } else {
        func_00196040(btlTargetGetUnitIndex((BtlTarget *)(arg0 + 0x38)) & 0xFFFF, 1, &targetPosition, 0, 0, 1);
        rotateToPointPacket = (u8 *)(btlUnitCreateRotatePacket((*(BtlUnit **)(arg0 + (0x30))), &targetPosition, 0));
        (*(s64 *)((u8 *)(rotateToPointPacket) + (0x60))) = actionUid;
        btlPacketEnqueue(rotateToPointPacket, 0);
    }
    unitIndex = 0;
    targetCount = (u16)((*(u16 *)(arg0 + (0x6A))));
    while (((s32)unitIndex & 0xFFFF) < (s32) targetCount) {
        unitEntry = (u8 *)((*(u8 **)((u8 *)((arg0 + ((unitIndex & 0xFFFF) * 4))) + (0x38))));
        targetRowIndex = 0;
        while ((targetRowIndex & 0xFFFF) < (s32) (*(u8 *)((u8 *)(unitEntry) + (0xD9)))) {
            targetRow = (u8 *)(unitEntry + ((u16)targetRowIndex << 5));
            if ((*(s32 *)((u8 *)(targetRow) + (0xF8))) & 0x100000) {
                hasStatusFlag = 1;
            }
            if ((*(u16 *)((u8 *)(targetRow) + (0x10E))) & 4) {
                unitFlag10E = 1;
            }
            targetRowIndex = (targetRowIndex + 1) & 0xFFFF;
        }
        if ((*(s32 *)((u8 *)(unitEntry) + (0xE0))) != 0) {
            hasReaction = 1;
            reactionUnitCount += 1;
        }
        if ((*(s32 *)((u8 *)(unitEntry) + (0xE4))) != 0) {
            hasTargetE4 = 1;
        }
        if ((*(u16 *)((u8 *)(unitEntry) + (0xDE))) & 6) {
            hasTargetFlags6 = 1;
        }
        unitIndex = ((s32)unitIndex + 1) & 0xFFFF;
    }
    if (unitFlag10E != 0) {
        actionKind = 0xC;
        actionVariant = 0;
        setEffectFlags = 1;
    } else if (actionFlagSaved != 0) {
        actionKind = 4;
        actionVariant = 0;
    } else if (hasTargetFlags6 != 0) {
        actionKind = 5;
        actionVariant = 2;
        setEffectFlags = 1;
    } else {
        actionKind = 4;
        actionVariant = 0;
    }
    if ((hasStatusFlag == 1) && (actionFlagSaved == 0) && (targetCount == 1) && !((*(s32 *)((u8 *)(iGpffffb3ac) + (0x10))) & 0x2000)) {
        counterPending = 1;
    }
    if ((btlUnitKind_001a59a0(battleUnit) != 0) || (actionKind == 4) || (actionKind == 0xC)) {
        actionDuration = btlUnitMotionFrames(battleUnit, actionKind, timeScale);
    } else {
        actionDuration = btlUnitMotionHitFrames(battleUnit, actionKind, timeScale, 0);
    }
    baseDuration = btlUnitMotionModelFrames(battleUnit, actionKind, timeScale);
    baseDurationSaved = (s32) baseDuration;
    /* Retail truncates the scaled difference, caps it at 25, then narrows each sum. */
    timingValue = (s16)actionDuration;
    if (actionDuration < baseDuration) {
        timingAdjustment = (s32)(fGpffff8128 * (f32)(baseDuration - actionDuration));
        if (timingAdjustment > 0x19) {
            timingAdjustment = 25;
        }
        timingValue = (s16)(timingValue + (s16)timingAdjustment);
    }
    if ((hasReaction != 0) || (hasTargetE4 != 0)) {
        timingValue = (s16)(timingValue + 8);
    }
    if (hasCounterUnit != 0) {
        counterDuration = (btlUnitMotionModelFrames((*(u8 **)((u8 *)((*(s64 **)(arg0 + (0x88)))) + (0x30))), 0x1A, 1.0f)) - 4;
        if (actionDuration < counterDuration) {
            earlyDelta = counterDuration - actionDuration;
            lateDelta = 0;
        } else {
            earlyDelta = 0;
            lateDelta = actionDuration - counterDuration;
        }
        timingValue = (s16)(timingValue + 0xC);
    } else {
        earlyDelta = 0;
        lateDelta = 0;
    }
    leadPacket = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)battleUnit, (s16)actionKind, 0, timeScale, actionVariant & 0xFFFF));
    leadPacketSaved = (u8 *)(leadPacket);
    (*(s16 *)((u8 *)(leadPacket) + (0x48))) = (s16) earlyDelta;
    (*(s64 *)((u8 *)(leadPacket) + (0x60))) = actionUid;
    btlPacketEnqueue(leadPacket, 0);
    animUid = *(s64 *)(leadPacket + 0x58);
    if (hasCounterUnit == 0) {
        if ((*(u16 *)(arg0 + (0x6A))) == 1) {
            if (btlUnitKind_001a59a0(battleUnit) == 0) {
                if (((hasTargetFlags6 == 0) && (hasStatusFlag == 0)) || (actionFlagSaved == 1)) {
                    closeCameraResult = btlCloseCamera_001a59a0(*(u8 **)(arg0 + 0x30), hasTargetFlags6);
                    if (closeCameraResult != 0) {
                        cameraPacket = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0xC));
                    } else {
                        cameraPacket = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0xB));
                    }
                } else {
                    cameraPacket = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0x10));
                }
            } else if ((hasStatusFlag == 0) || (actionFlagSaved == 1)) {
                closeCameraResultB = btlCloseCamera_001a59a0(*(u8 **)(arg0 + 0x30), hasTargetFlags6);
                if (closeCameraResultB != 0) {
                    cameraPacket = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0xC));
                } else {
                    cameraPacket = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0xB));
                }
            } else {
                cameraPacket = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0xD));
            }
        } else {
            cameraPacket = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0x2C));
        }
        (*(s8 *)((u8 *)(cameraPacket) + (0))) = 5;
        (*(s64 *)((u8 *)(cameraPacket) + (8))) = animUid;
        (*(s64 *)((u8 *)(cameraPacket) + (0x60))) = actionUid;
        btlPacketEnqueue(cameraPacket, 0);
    }
    if (unitFlag10E != 0) {
        if (actionDuration > 6) {
            startDelay = actionDuration - 6;
        } else {
            startDelay = 0;
        }
        animDuration = (s32) (btlUnitMotionFollowFrames(battleUnit, actionKind, timeScale));
        if (btlUnitKind_001a59a0(battleUnit) == 0) {
            cameraEventPacket = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0xE));
            (*(s8 *)((u8 *)(cameraEventPacket) + (0))) = 4;
            (*(s64 *)((u8 *)(cameraEventPacket) + (8))) = (s64) (*(s64 *)((u8 *)(leadPacketSaved) + (0x58)));
            (*(s16 *)((u8 *)(cameraEventPacket) + (0x48))) = startDelay;
            (*(s64 *)((u8 *)(cameraEventPacket) + (0x60))) = actionUid;
            btlPacketEnqueue(cameraEventPacket, 0);
        }
        cuePacket = (u8 *)(btlSoundCreateChannelCuePacket(0xC, 2, 9));
        (*(s8 *)((u8 *)(cuePacket) + (0))) = 5;
        (*(s64 *)((u8 *)(cuePacket) + (8))) = animUid;
        if (animDuration > 8) {
            animDelay = animDuration - 8;
        } else {
            animDelay = 0;
        }
        (*(s16 *)((u8 *)(cuePacket) + (0x48))) = animDelay;
        (*(s64 *)((u8 *)(cuePacket) + (0x60))) = actionUid;
        btlPacketEnqueue(cuePacket, 1);
        effectPacket = (u8 *)(btlFormationCreatePacket((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD80))), battleUnit, battleUnit, 1, 0));
        (*(s8 *)((u8 *)(effectPacket) + (0))) = 5;
        (*(s64 *)((u8 *)(effectPacket) + (8))) = animUid;
        (*(s16 *)((u8 *)(effectPacket) + (0x48))) = (s16) animDuration;
        (*(s64 *)((u8 *)(effectPacket) + (0x60))) = actionUid;
        btlPacketEnqueue(effectPacket, 2);
        effectPacketB = (u8 *)(btlFormationCreatePacket((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD74))), battleUnit, battleUnit, 1, 0));
        (*(s8 *)((u8 *)(effectPacketB) + (0))) = 5;
        (*(s64 *)((u8 *)(effectPacketB) + (8))) = animUid;
        (*(s16 *)((u8 *)(effectPacketB) + (0x48))) = startDelay;
        (*(s64 *)((u8 *)(effectPacketB) + (0x60))) = actionUid;
        btlPacketEnqueue(effectPacketB, 2);
        func_001f0a10((u8 *)&result);
        result.addedStatus = 0x100000;
        resultPacket = (u8 *)(btlTargetCreateDataPacket((s32)(arg0), (s32)(arg0), &result, 1U, 1U));
        (*(s8 *)((u8 *)(resultPacket) + (0))) = 5;
        (*(s64 *)((u8 *)(resultPacket) + (8))) = animUid;
        scaledBase = (s16)baseDurationSaved;
        (*(s16 *)((u8 *)(resultPacket) + (0x48))) = (s16) (scaledBase - (scaledBase >> 2));
        (*(s64 *)((u8 *)(resultPacket) + (0x60))) = actionUid;
        btlPacketEnqueue(resultPacket, 1);
        if ((actionFlagSaved == 0) && ((*(u8 *)((u8 *)((*(u8 **)(arg0 + (0x30)))) + (0xA2))) == 0)) {
            reactionPacket = (u8 *)(btlTargetCreateTargetPacket(arg0, 0x19, 0, 0, 0));
            (*(s8 *)((u8 *)(reactionPacket) + (0))) = 4;
            (*(s64 *)((u8 *)(reactionPacket) + (8))) = (s64) (*(s64 *)((u8 *)(resultPacket) + (0x58)));
            (*(s64 *)((u8 *)(reactionPacket) + (0x60))) = actionUid;
            btlPacketEnqueue(reactionPacket, 1);
        }
    }
    targetIndex = 0;
    timingValue16 = (s16)timingValue;
    timingValueWide = (s32) timingValue16;
    timingValueShifted = timingValue16 + 0xC;
    while ((targetNumber = (s32) targetIndex) < (s32) (*(u16 *)(arg0 + (0x6A)))) {
        targetView = (ActionTargetView *)((*(u8 **)((u8 *)((arg0 + ((u32)targetIndex * 4))) + (0x38))));
        hitRowCount = *(u8 *)((u8 *)targetView + 0xD9);
        if (actionFlagSaved != 0) {
            targetFlagDA = 1;
        } else {
            targetFlagDA = (u8)((*(u8 *)((u8 *)(targetView) + (0xDA))));
        }
        targetFlagDASaved = targetFlagDA;
        hitTiming = (s32) actionDuration;
        if (actionDuration > 3) {
            hitTimingBase = actionDuration - 3;
        } else {
            hitTimingBase = 0;
        }
        if (hasCounterUnit == 0) {
            rotatePacketTarget = (u8 *)(btlUnitCreateRotateTowardUnitPacket(targetView->unit, battleUnit, 2));
            (*(s8 *)((u8 *)(rotatePacketTarget) + (0))) = 5;
            (*(s64 *)((u8 *)(rotatePacketTarget) + (8))) = animUid;
            (*(s16 *)((u8 *)(rotatePacketTarget) + (0x48))) = hitTimingBase;
            (*(u8 *)((u8 *)(rotatePacketTarget) + (0x47))) = (u8) ((*(u8 *)((u8 *)(rotatePacketTarget) + (0x47))) & 0xDF);
            (*(s64 *)((u8 *)(rotatePacketTarget) + (0x60))) = actionUid;
            btlPacketEnqueue(rotatePacketTarget, 1);
            if ((*(s32 *)((u8 *)(targetView) + (0xE4))) != 0) {
                selectedTarget = (ActionTargetView *)arg0;
            } else {
                selectedTarget = targetView;
            }
            focusTarget = selectedTarget;
        } else {
            focusTarget = (ActionTargetView *)((*(u8 **)(arg0 + (0x88))));
            actionPacket = (u8 *)(func_001f99c0((u8 *)focusTarget, 0xD, 0U, 0, 0));
            (*(s16 *)((u8 *)(actionPacket) + (0x48))) = (s16) lateDelta;
            (*(s64 *)((u8 *)(actionPacket) + (0x60))) = actionUid;
            btlPacketEnqueue(actionPacket, 1);
            rotatePacketFocus = (u8 *)(btlUnitCreateRotateTowardUnitPacket(targetView->unit, battleUnit, 2));
            (*(s16 *)((u8 *)(rotatePacketFocus) + (0x48))) = (s16) lateDelta;
            (*(s64 *)((u8 *)(rotatePacketFocus) + (0x60))) = actionUid;
            btlPacketEnqueue(rotatePacketFocus, 0);
            cameraPacketFocus = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0x11));
            (*(s16 *)((u8 *)(cameraPacketFocus) + (0x48))) = (s16) lateDelta;
            (*(s64 *)((u8 *)(cameraPacketFocus) + (0x60))) = actionUid;
            (*(s16 *)((u8 *)(cameraPacketFocus) + (0x4A))) = (s16) timingValueShifted;
            btlPacketEnqueue(cameraPacketFocus, 0);
            movePacket = (u8 *)(btlFormationCreateWaitPacket(focusTarget->unit, targetView->unit, 2));
            (*(s16 *)((u8 *)(movePacket) + (0x48))) = (s16) lateDelta;
            (*(s64 *)((u8 *)(movePacket) + (0x60))) = actionUid;
            btlPacketEnqueue(movePacket, 0);
            animPacketFocus = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)focusTarget->unit, 0x1A, 0, 1.0f, 0));
            (*(s16 *)((u8 *)(animPacketFocus) + (0x48))) = (s16) lateDelta;
            (*(s64 *)((u8 *)(animPacketFocus) + (0x60))) = actionUid;
            btlPacketEnqueue(animPacketFocus, 0);
            animPacketTarget = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)targetView->unit, 0x1A, 0, 1.0f, 2));
            (*(s16 *)((u8 *)(animPacketTarget) + (0x48))) = (s16) lateDelta;
            (*(s64 *)((u8 *)(animPacketTarget) + (0x60))) = actionUid;
            btlPacketEnqueue(animPacketTarget, 0);
            setEffectFlags = 1;
        }
        if (btlUnitKind_001a59a0(battleUnit) == 0) {
            if ((func_001f08c0(battleUnit) != 0) && (focusUnit = focusTarget->unit, ((*(u8 *)((u8 *)(focusUnit) + (0xA2))) == 1))) {
                shortRangeFlag = (s32)(((*(s16 *)((u8 *)((((s32)iGpffffb3cc) + ((*(u16 *)((u8 *)(focusUnit) + (0xA4))) * 0xE8))) + (0x18))) & 0x40) != 0) ^ 1;
            } else {
                shortRangeFlag = 0;
            }
        } else {
            shortRangeFlag = 0;
        }
        if ((counterPending == 1) && (targetNumber == 0) && (btlUnitKind_001a59a0(battleUnit) == 0) && ((*(u16 *)(arg0 + (0x6A))) == 1) && (hasReaction == 0)) {
            if (shortRangeFlag != 0) {
                shortRangeDistance = fGpffff8358;
            } else {
                shortRangeDistance = 400.0f;
            }
            nearMovePacket = (u8 *)(btlFormationCreateMovePacket((u32)battleUnit, *(u32 *)&targetView->unit, shortRangeDistance, 3));
            (*(s8 *)((u8 *)(nearMovePacket) + (0))) = 5;
            (*(s64 *)((u8 *)(nearMovePacket) + (8))) = animUid;
            (*(s64 *)((u8 *)(nearMovePacket) + (0x60))) = actionUid;
            btlPacketEnqueue(nearMovePacket, 0);
            setEffectFlags = 1;
        }
        hitRowIndex = 0;
        hitCountShort = (s16)targetFlagDASaved;
        hitCount = (s32) hitCountShort;
        lastHitIndex = hitCountShort - 1;
        hitRowLimit = (s16)hitRowCount;
        while ((hitRowNumber = (s32) hitRowIndex) < hitRowLimit) {
            hitIndexCounter = 0;
            hitRow = (ActionHitRowView *)((u8 *)targetView + ((u32)hitRowIndex << 5));
            while ((s32)(hitIndex = (s32) hitIndexCounter) < hitCount) {
                rowMotion = hitRow->result.motion;
                hitMotion = (s32) rowMotion;
                switch (rowMotion) {
                case 9:
                case 0x13:
                    if (hitIndex != lastHitIndex) {
                        hitMotion = 2;
                    }
                    break;
                }
                if ((targetView->effect & 0x404) || (hitRow->result.flags & 4)) {
                    isPrimaryHit = 0;
                } else {
                    isPrimaryHit = 1;
                }
                hitAnimPacket = (BtlPacket *)(btlUnitCreateAnimPacket((BtlUnit *)focusTarget->unit, (s16)hitMotion, 0, 1.0f, 0));
                hitAnimPacketSaved = hitAnimPacket;
                (*(s8 *)((u8 *)(hitAnimPacket) + (0))) = 5;
                (*(s64 *)((u8 *)(hitAnimPacket) + (8))) = animUid;
                switch (hitMotion) {
                case 0x17:
                case -3:
                    if (hitTiming > 6) {
                        hitDelay = hitTiming - 6;
                    } else {
                        hitDelay = 0;
                    }
                    (*(s16 *)((u8 *)(hitAnimPacketSaved) + (0x48))) = hitDelay;
                    break;
                default:
                    (*(s16 *)((u8 *)(hitAnimPacketSaved) + (0x48))) = (s16) hitTiming;
                    break;
                }
                if ((*(s32 *)((u8 *)(u32)(targetView) + (0xE4))) != 0) {
                    (*(s16 *)((u8 *)(hitAnimPacketSaved) + (0x48))) = (s16) ((*(s16 *)((u8 *)(hitAnimPacketSaved) + (0x48))) + 5);
                    hitTimingBase += 5;
                }
                (*(s64 *)((u8 *)(hitAnimPacketSaved) + (0x60))) = actionUid;
                btlPacketEnqueue((u8 *)hitAnimPacketSaved, 0);
                hitPacketUid = *(s64 *)((u8 *)hitAnimPacketSaved + 0x58);
                if ((targetView->effect & 4) && (unitFlag10E == 0)) {
                    cuePacketB = (u8 *)(btlSoundCreateChannelCuePacket(0xD, 1, 0xF));
                    (*(s8 *)((u8 *)(cuePacketB) + (0))) = 5;
                    (*(s64 *)((u8 *)(cuePacketB) + (8))) = animUid;
                    (*(s16 *)((u8 *)(cuePacketB) + (0x48))) = (s16) hitTiming;
                    btlPacketEnqueue(cuePacketB, 1);
                }
                if ((*(s32 *)((u8 *)(targetView) + (0xE4))) != 0) {
                    effectPacketC = (u8 *)(btlFormationCreatePacket((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD28))), battleUnit, targetView->unit, 1, 0));
                    (*(s8 *)((u8 *)(effectPacketC) + (0))) = 5;
                    (*(s64 *)((u8 *)(effectPacketC) + (8))) = animUid;
                    (*(s16 *)((u8 *)(effectPacketC) + (0x48))) = (s16) hitTiming;
                    btlPacketEnqueue(effectPacketC, 1);
                    cuePacketC = (u8 *)(btlSoundCreateChannelCuePacket(0xD, 2, 0xB));
                    (*(s8 *)((u8 *)(cuePacketC) + (0))) = 5;
                    (*(s64 *)((u8 *)(cuePacketC) + (8))) = animUid;
                    (*(s16 *)((u8 *)(cuePacketC) + (0x48))) = (s16) hitTiming;
                    btlPacketEnqueue(cuePacketC, 1);
                }
                if (targetView->effect == 0x400) {
                    effectPacketD = (u8 *)(btlFormationCreatePacket((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD2C))), battleUnit, focusTarget->unit, 1, 0));
                    (*(s8 *)((u8 *)(effectPacketD) + (0))) = 5;
                    (*(s64 *)((u8 *)(effectPacketD) + (8))) = hitPacketUid;
                    btlPacketEnqueue(effectPacketD, 1);
                    cuePacketD = (u8 *)(btlSoundCreateChannelCuePacket(0xC, 2, 0xC));
                    (*(s8 *)((u8 *)(cuePacketD) + (0))) = 5;
                    (*(s64 *)((u8 *)(cuePacketD) + (8))) = hitPacketUid;
                    btlPacketEnqueue(cuePacketD, 1);
                }
                func_001f7830(battleUnit, hitIndex, hasTargetFlags6, &hitCue, &hitVariant);
                if ((hitCue >= 0) && (hitVariant >= 0)) {
                    cuePacketE = (u8 *)(btlSoundCreateChannelCuePacket(0xD, hitCue, hitVariant));
                    (*(s8 *)((u8 *)(cuePacketE) + (0))) = 5;
                    (*(s64 *)((u8 *)(cuePacketE) + (8))) = animUid;
                    (*(s16 *)((u8 *)(cuePacketE) + (0x48))) = hitTimingBase;
                    btlPacketEnqueue(cuePacketE, 1);
                }
                if (isPrimaryHit != 0) {
                    if ((targetView->targetFlags & 6) && (actionFlagSaved == 0)) {
                        if (hitIndex != lastHitIndex) {
                            effectPacketK = (u8 *)(btlFormationCreatePacket((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD1C))), battleUnit, focusTarget->unit, 1, 0));
                        } else {
                            effectPacketK = (u8 *)(btlFormationCreatePacket((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD20))), battleUnit, focusTarget->unit, 1, 0));
                        }
                        (*(s8 *)((u8 *)(effectPacketK) + (0))) = 5;
                        (*(s64 *)((u8 *)(effectPacketK) + (8))) = animUid;
                        (*(s16 *)((u8 *)(effectPacketK) + (0x48))) = hitTimingBase;
                        (*(s64 *)((u8 *)(effectPacketK) + (0x60))) = actionUid;
                        btlPacketEnqueue(effectPacketK, 2);
                        if (hitIndex == lastHitIndex) {
                            cuePacketF = (u8 *)(btlSoundCreateChannelCuePacket(0xC, 0, 9));
                            (*(s8 *)((u8 *)(cuePacketF) + (0))) = 5;
                            (*(s64 *)((u8 *)(cuePacketF) + (8))) = animUid;
                            (*(s16 *)((u8 *)(cuePacketF) + (0x48))) = hitTimingBase;
                            btlPacketEnqueue(cuePacketF, 1);
                        }
                    }
                    effectPacketE = (u8 *)(btlFormationCreatePacket((*(s32 *)((u8 *)((iGpffffb3ac + (effectIndices[0] * 4))) + (0xD04))), battleUnit, focusTarget->unit, 1, 0));
                    (*(s8 *)((u8 *)(effectPacketE) + (0))) = 5;
                    (*(s64 *)((u8 *)(effectPacketE) + (8))) = animUid;
                    (*(s16 *)((u8 *)(effectPacketE) + (0x48))) = hitTimingBase;
                    btlPacketEnqueue(effectPacketE, 2);
                    if (effectIndices[1] >= 0) {
                        effectPacketF = (u8 *)(btlFormationCreatePacket((*(s32 *)((u8 *)((iGpffffb3ac + (effectIndices[1] * 4))) + (0xD04))), battleUnit, focusTarget->unit, 1, 0));
                        (*(s8 *)((u8 *)(effectPacketF) + (0))) = 5;
                        (*(s64 *)((u8 *)(effectPacketF) + (8))) = animUid;
                        (*(s16 *)((u8 *)(effectPacketF) + (0x48))) = hitTimingBase;
                        btlPacketEnqueue(effectPacketF, 2);
                    }
                    if (actionFlagSaved == 0) {
                        func_001f7910(battleUnit, hitIndex, hasTargetFlags6, &hitCue, &hitVariant);
                        if ((hitCue >= 0) && (hitVariant >= 0)) {
                            cuePacketG = (u8 *)(btlSoundCreateChannelCuePacket(0xA, hitCue, hitVariant));
                            (*(s8 *)((u8 *)(cuePacketG) + (0))) = 5;
                            (*(s64 *)((u8 *)(cuePacketG) + (8))) = animUid;
                            (*(s16 *)((u8 *)(cuePacketG) + (0x48))) = hitTimingBase;
                            btlPacketEnqueue(cuePacketG, 1);
                        }
                        if ((hitIndex == lastHitIndex) && ((*(s32 *)((u8 *)(targetView) + (0xE0))) == 0) && (hitRow->result.addedStatus & 0x7FFFE)) {
                            cuePacketH = (u8 *)(btlSoundCreateChannelCuePacket(0xF, 2, 0xF));
                            (*(s8 *)((u8 *)(cuePacketH) + (0))) = 5;
                            (*(s64 *)((u8 *)(cuePacketH) + (8))) = animUid;
                            (*(s16 *)((u8 *)(cuePacketH) + (0x48))) = hitTimingBase;
                            btlPacketEnqueue(cuePacketH, 1);
                        }
                    } else {
                        cuePacketI = (u8 *)(btlSoundCreateChannelCuePacket(0xA, 2, 0x14));
                        (*(s8 *)((u8 *)(cuePacketI) + (0))) = 5;
                        (*(s64 *)((u8 *)(cuePacketI) + (8))) = animUid;
                        (*(s16 *)((u8 *)(cuePacketI) + (0x48))) = hitTimingBase;
                        btlPacketEnqueue(cuePacketI, 1);
                    }
                    effectPacketG = (u8 *)(btlFormationCreatePacket((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD24))), battleUnit, focusTarget->unit, 1, 0));
                    (*(s8 *)((u8 *)(effectPacketG) + (0))) = 5;
                    (*(s64 *)((u8 *)(effectPacketG) + (8))) = animUid;
                    (*(s16 *)((u8 *)(effectPacketG) + (0x48))) = hitTimingBase;
                    btlPacketEnqueue(effectPacketG, 2);
                }
                if (hitIndex != lastHitIndex) {
                    timingDelta = (btlUnitMotionHitFrames(battleUnit, actionKind, timeScale, (hitIndex + 1) & 0xFFFF)) - hitTiming;
                    hitTiming += timingDelta;
                    hitTimingBase += timingDelta;
                } else if ((counterPending != 0) && ((*(s32 *)((u8 *)(targetView) + (0xE0))) == 0)) {
                    if (shortRangeFlag != 0) {
                        hitEffectIndex = 0x1D;
                    } else {
                        hitEffectIndex = 0x1E;
                    }
                    focusUnitB = (u8 *)(focusTarget->unit);
                    counterAnimPacket = (u8 *)(btlFormationCreatePacket((*(s32 *)((u8 *)((iGpffffb3ac + (hitEffectIndex * 4))) + (0xD04))), focusUnitB, focusUnitB, 1, 0));
                    counterAnimPacketSaved = (u8 *)(counterAnimPacket);
                    (*(s8 *)((u8 *)(counterAnimPacket) + (0))) = 5;
                    (*(s64 *)((u8 *)(counterAnimPacket) + (8))) = hitPacketUid;
                    (*(s16 *)((u8 *)(counterAnimPacket) + (0x48))) = 1;
                    (*(s64 *)((u8 *)(counterAnimPacket) + (0x60))) = actionUid;
                    btlPacketEnqueue(counterAnimPacket, 2);
                    if (shortRangeFlag != 0) {
                        focusUnitC = (u8 *)(focusTarget->unit);
                        effectPacketH = (u8 *)(btlFormationCreatePacket((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD84))), focusUnitC, focusUnitC, 1, 0));
                        (*(s8 *)((u8 *)(effectPacketH) + (0))) = 5;
                        (*(s64 *)((u8 *)(effectPacketH) + (8))) = (s64) btlPacketUID_001a59a0(counterAnimPacketSaved);
                        (*(s64 *)((u8 *)(effectPacketH) + (0x60))) = actionUid;
                        btlPacketEnqueue(effectPacketH, 2);
                        focusUnitD = (u8 *)(focusTarget->unit);
                        effectPacketI = (u8 *)(btlFormationCreatePacket((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD80))), focusUnitD, focusUnitD, 1, 0));
                        (*(s8 *)((u8 *)(effectPacketI) + (0))) = 5;
                        (*(s64 *)((u8 *)(effectPacketI) + (8))) = (s64) btlPacketUID_001a59a0(counterAnimPacketSaved);
                        (*(s16 *)((u8 *)(effectPacketI) + (0x48))) = 0x14;
                        (*(s64 *)((u8 *)(effectPacketI) + (0x60))) = actionUid;
                        btlPacketEnqueue(effectPacketI, 2);
                        focusUnitE = (u8 *)(focusTarget->unit);
                        effectPacketJ = (u8 *)(btlFormationCreatePacket((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD80))), focusUnitE, focusUnitE, 1, 0));
                        (*(s8 *)((u8 *)(effectPacketJ) + (0))) = 5;
                        (*(s64 *)((u8 *)(effectPacketJ) + (8))) = (s64) btlPacketUID_001a59a0(counterAnimPacketSaved);
                        (*(s16 *)((u8 *)(effectPacketJ) + (0x48))) = 0x1A;
                        (*(s64 *)((u8 *)(effectPacketJ) + (0x60))) = actionUid;
                        btlPacketEnqueue(effectPacketJ, 2);
                    } else {
                        hitPacket = (u8 *)(btlUnitCreateArcMovePacket(focusTarget->unit, (s16) (*(u16 *)(arg0 + (0x6E))), 0));
                        (*(s8 *)((u8 *)(hitPacket) + (0))) = 5;
                        (*(s64 *)((u8 *)(hitPacket) + (8))) = (s64) btlPacketUID_001a59a0(counterAnimPacketSaved);
                        (*(s64 *)((u8 *)(hitPacket) + (0x60))) = actionUid;
                        btlPacketEnqueue(hitPacket, 1);
                        shakePacket = (u8 *)(func_001bccc0(0x14, 0x32, 0, 5));
                        (*(s8 *)((u8 *)(shakePacket) + (0))) = 5;
                        (*(s64 *)((u8 *)(shakePacket) + (8))) = (s64) btlPacketUID_001a59a0(counterAnimPacketSaved);
                        (*(s64 *)((u8 *)(shakePacket) + (0x60))) = actionUid;
                        btlPacketEnqueue(shakePacket, 1);
                    }
                }
                hitIndexCounter += 1;
            }
            hitResultPtr = (LargeBattleHitResult *)btlHitResult_001a59a0((u8 *)targetView, &hitRowIndex);
            hitResultSaved = hitResultPtr;
            resultPacketB = (u8 *)(btlTargetCreateDataPacket((s32)(arg0), (s32)(focusTarget), hitResultPtr, targetView->effect, targetView->targetFlags));
            (*(s8 *)((u8 *)(resultPacketB) + (0))) = 5;
            (*(s64 *)((u8 *)(resultPacketB) + (8))) = animUid;
            (*(s16 *)((u8 *)(resultPacketB) + (0x48))) = hitTimingBase;
            (*(s64 *)((u8 *)(resultPacketB) + (0x60))) = actionUid;
            btlPacketEnqueue(resultPacketB, 1);
            statusPacket = (u8 *)(btlPacketCreateHitDisplay((s32)(battleUnit), *(s32 *)&focusTarget->unit, (*(u16 *)(arg0 + (0x6E))), targetView->effect, targetView->targetFlags, 0, 1, hitResultSaved, 0));
            (*(s8 *)((u8 *)(statusPacket) + (0))) = 5;
            (*(s64 *)((u8 *)(statusPacket) + (8))) = animUid;
            (*(s16 *)((u8 *)(statusPacket) + (0x48))) = hitTimingBase;
            if (hitTimingBase < timingValueWide) {
                timingRemaining = timingValueWide - hitTimingBase;
            } else {
                timingRemaining = 0;
            }
            (*(s16 *)((u8 *)(statusPacket) + (0x4A))) = timingRemaining;
            (*(s64 *)((u8 *)(statusPacket) + (0x60))) = actionUid;
            btlPacketEnqueue(statusPacket, 3);
            if ((hitRowNumber == 0) && (hitResultSaved->hpDelta != 0)) {
                statPacket = (u8 *)(btlPacketCreateUnitCounter((s32)(focusTarget->unit), 0, 0));
                (*(s8 *)((u8 *)(statPacket) + (0))) = 5;
                (*(s64 *)((u8 *)(statPacket) + (8))) = animUid;
                (*(s16 *)((u8 *)(statPacket) + (0x48))) = hitTimingBase;
                (*(u8 *)((u8 *)(statPacket) + (0x47))) = (u8) ((*(u8 *)((u8 *)(statPacket) + (0x47))) & 0xDF);
                (*(s64 *)((u8 *)(statPacket) + (0x60))) = actionUid;
                btlPacketEnqueue(statPacket, 3);
            }
            /* Retail retains this address and reloads its word at the later branch. */
            addedStatus = &hitRow->result.addedStatus;
            if ((hitRow->result.addedStatus & 0x100000) && ((*(u8 *)((u8 *)(focusTarget->unit) + (0xA2))) == 1)) {
                cuePacketJ = (u8 *)(btlSoundCreateChannelCuePacket(0xD, 2, 8));
                (*(s8 *)((u8 *)(cuePacketJ) + (0))) = 5;
                (*(s64 *)((u8 *)(cuePacketJ) + (8))) = animUid;
                (*(s16 *)((u8 *)(cuePacketJ) + (0x48))) = hitTimingBase;
                (*(s64 *)((u8 *)(cuePacketJ) + (0x60))) = actionUid;
                btlPacketEnqueue(cuePacketJ, 1);
            }
            if ((actionFlagSaved == 0) && ((*(u8 *)((u8 *)(focusTarget->unit) + (0xA2))) == 1)) {
                if (reactionUnitCount > 0) {
                    if ((*(u8 *)((u8 *)((*(u8 **)(arg0 + (0x30)))) + (0xA2))) == 0) {
                        reactionRoll = btlSideCountNotBad(2, 0x80000) & 0xFFFF;
                        reactionCueFlag = *(u8 *)(arg0 + 0x28);
                        if (reactionCueFlag > 0) {
                            goto createReaction;
                        }
                        reactionCueFlag = 1;
                        if (*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4) == reactionCueFlag) {
                            goto createReaction;
                        }
                        reactionCueFlag = datCalcRandomBelow(0x64);
                        if ((u32)reactionCueFlag >= 0x32U) {
                            goto createReaction;
                        }
                        if ((*(u8 *)((u8 *)((*(u8 **)(arg0 + (0x30)))) + (0xA2))) != 0) {
                            reactionCueFlag = 0;
                        } else {
                            battleStatePtr = (u8 *)(iGpffffb3ac);
                            if ((*(s16 *)((u8 *)(battleStatePtr) + (0xA70))) != -1) {
                                reactionRemaining = (s16)(reactionRoll - reactionUnitCount);
                                if (reactionRemaining <= 0) {
                                    randomRoll = btlSideCountNotBad(2, 0x80000) & 0xFFFF;
                                    battleStatePtrD = (u8 *)(iGpffffb3ac);
                                    if (((u32) ((s16) (*(s16 *)((u8 *)(battleStatePtrD) + (0xA72))) >> 1) >= randomRoll) && (counterUnitId16 = (*(s16 *)((u8 *)(battleStatePtrD) + (0xA70))), counterUnitId = (s32) counterUnitId16, (counterUnitId16 != (s16)func_001d15a0()))) {
                                        reactionCueFlag = 1;
                                    } else {
                                        goto block_222;
                                    }
                                } else if (((s16) (*(s16 *)((u8 *)(battleStatePtr) + (0xA72))) >> 1) >= reactionRemaining) {
                                    reactionCueFlag = 1;
                                } else {
                                    goto block_222;
                                }
                            } else {
block_222:
                                reactionCueFlag = 0;
                            }
                        }
                        if (reactionCueFlag != 0) {
createReaction:
                            reactionPacketB = (u8 *)(btlTargetCreateTargetPacket(arg0, 0x13, reactionUnitCount, 0, 0));
                            (*(s8 *)((u8 *)(reactionPacketB) + (0))) = 4;
                            (*(s64 *)((u8 *)(reactionPacketB) + (8))) = hitPacketUid;
                            (*(s64 *)((u8 *)(reactionPacketB) + (0x60))) = actionUid;
                            btlPacketEnqueue(reactionPacketB, 1);
                        } else {
                            actionPacketB = (u8 *)(func_001f99c0(arg0, 0x10, reactionUnitCount, 0, 0));
                            (*(s8 *)((u8 *)(actionPacketB) + (0))) = 4;
                            (*(s64 *)((u8 *)(actionPacketB) + (8))) = hitPacketUid;
                            btlPacketEnqueue(actionPacketB, 1);
                        }
                    }
                } else if (*addedStatus & 0x100000) {
                    reactionPacketC = (u8 *)(btlTargetCreateTargetPacket(arg0, 0x18, (s32) targetView->targetFlags, 1, 0));
                    (*(s8 *)((u8 *)(reactionPacketC) + (0))) = 5;
                    (*(s64 *)((u8 *)(reactionPacketC) + (8))) = hitPacketUid;
                    (*(s64 *)((u8 *)(reactionPacketC) + (0x60))) = actionUid;
                    btlPacketEnqueue(reactionPacketC, 1);
                } else if (reactionUnitCount == 0) {
                    if (func_001f0dd0((s64 *)arg0, 1) != 0) {
                        actionPacketC = (u8 *)(func_001f99c0(arg0, 0xF, 0U, 0, 0));
                        (*(s8 *)((u8 *)(actionPacketC) + (0))) = 5;
                        (*(s64 *)((u8 *)(actionPacketC) + (8))) = hitPacketUid;
                        btlPacketEnqueue(actionPacketC, 1);
                    } else if ((func_001f0f70(arg0) == 1) && (btlActionAnyTargetSpecialHit(arg0) == 0)) {
                        actionPacketD = (u8 *)(func_001f99c0(arg0, 0x11, 0U, 0, 0));
                        (*(s8 *)((u8 *)(actionPacketD) + (0))) = 5;
                        (*(s64 *)((u8 *)(actionPacketD) + (8))) = hitPacketUid;
                        btlPacketEnqueue(actionPacketD, 1);
                    }
                }
            }
            hitRowIndex += 1;
        }
        unitStatePacket = (u8 *)(btlTargetCreateRecordPacket(targetView));
        (*(s8 *)((u8 *)(unitStatePacket) + (0))) = 5;
        (*(s64 *)((u8 *)(unitStatePacket) + (8))) = animUid;
        (*(s16 *)((u8 *)(unitStatePacket) + (0x48))) = hitTimingBase;
        (*(s64 *)((u8 *)(unitStatePacket) + (0x60))) = actionUid;
        btlPacketEnqueue(unitStatePacket, 1);
        auxEffectIndex = (s16)((*(s16 *)(arg0 + (0xEC))));
        if ((auxEffectIndex != 0) && !((*(u8 *)(arg0 + (0xD8))) & 1)) {
            unitStatePacketB = (u8 *)(btlPacketCreateEffectCounter((*(u8 **)(arg0 + (0x30))), auxEffectIndex));
            (*(s8 *)((u8 *)(unitStatePacketB) + (0))) = 5;
            (*(s64 *)((u8 *)(unitStatePacketB) + (8))) = animUid;
            (*(s16 *)((u8 *)(unitStatePacketB) + (0x48))) = hitTimingBase;
            (*(u8 *)((u8 *)(unitStatePacketB) + (0x47))) = (u8) ((*(u8 *)((u8 *)(unitStatePacketB) + (0x47))) & 0xDF);
            (*(s64 *)((u8 *)(unitStatePacketB) + (0x60))) = actionUid;
            btlPacketEnqueue(unitStatePacketB, 3);
        } else {
            auxEffectIndexTarget = (s16)((*(s16 *)((u8 *)(targetView) + (0xEC))));
            if (auxEffectIndexTarget != 0) {
                unitStatePacketC = (u8 *)(btlPacketCreateEffectCounter(targetView->unit, auxEffectIndexTarget));
                (*(s8 *)((u8 *)(unitStatePacketC) + (0))) = 5;
                (*(s64 *)((u8 *)(unitStatePacketC) + (8))) = animUid;
                (*(s16 *)((u8 *)(unitStatePacketC) + (0x48))) = hitTimingBase;
                (*(u8 *)((u8 *)(unitStatePacketC) + (0x47))) = (u8) ((*(u8 *)((u8 *)(unitStatePacketC) + (0x47))) & 0xDF);
                (*(s64 *)((u8 *)(unitStatePacketC) + (0x60))) = actionUid;
                btlPacketEnqueue(unitStatePacketC, 3);
            }
        }
        targetIndex += 1;
    }
    unitStatePacketD = (u8 *)(btlTargetCreateRecordPacket(arg0));
    (*(s8 *)((u8 *)(unitStatePacketD) + (0))) = 5;
    (*(s64 *)((u8 *)(unitStatePacketD) + (8))) = animUid;
    (*(s16 *)((u8 *)(unitStatePacketD) + (0x48))) = hitTimingBase;
    (*(s64 *)((u8 *)(unitStatePacketD) + (0x60))) = actionUid;
    btlPacketEnqueue(unitStatePacketD, 1);
    if (!((*(u16 *)(arg0 + (0x18))) & 4)) {
        statePacket = (u8 *)(btlTargetCreateActionPacket(arg0, (*(u8 *)(arg0 + (0xDB)))));
        (*(s8 *)((u8 *)(statePacket) + (0))) = 5;
        (*(s64 *)((u8 *)(statePacket) + (8))) = animUid;
        (*(s16 *)((u8 *)(statePacket) + (0x48))) = hitTimingBase;
        (*(s64 *)((u8 *)(statePacket) + (0x60))) = actionUid;
        btlPacketEnqueue(statePacket, 1);
    }
    if (setEffectFlags != 0) {
        battleStatePtrC = (u8 *)(iGpffffb3ac);
        (*(s32 *)((u8 *)(battleStatePtrC) + (0xC))) = (s32) ((*(s32 *)((u8 *)(battleStatePtrC) + (0xC))) | 0x400000);
        battleStatePtrB = (u8 *)(iGpffffb3ac);
        (*(u16 *)((u8 *)(battleStatePtrB) + (0x18))) = (u16) ((*(u16 *)((u8 *)(battleStatePtrB) + (0x18))) | 0xF);
    }
    cutinUnit = (u8 *)((*(u8 **)(arg0 + (0x8C))));
    if (cutinUnit != NULL) {
        cutin.mode = 3;
        cutin.unitId = (u16)((*(u16 *)((u8 *)((*(u8 **)((u8 *)(cutinUnit) + (0x30)))) + (0xA4))));
        btlPacketEnqueue(func_001fa720(&cutin), 1);
    }
    if (func_001f68e0((s64 *)arg0) != 0) {
        btlActionSetState((BtlAction *)arg0, 0x1BU);
        return;
    }
    {
        u16 state;

        switch (*(u16 *)(arg0 + 0x6C)) {
        case 1:
        case 3:
        case 2:
            state = 0x20;
            break;
        default:
            state = 0x20;
            break;
        }
        btlActionSetState((BtlAction *)arg0, state);
    }
}

#pragma pop
// FUN_001A7710
void btlActionSkillInit(void)
{
}

#pragma push
/* measured: loop-invariant hoisting is required for retail's hit-loop preheader (506 -> 33 edits when introduced). */
/* measured: func_001a7720 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_001A7720
void btlActionSkillUpdate(u8 *arg0) {

    extern s32 btlCreateSetFlagsPacket(u32);
    extern s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
    extern u8 *func_00194b60(void);
    extern u8 *btlPacketAllocZeroed(void *arg0, void *arg1);
    extern s32 func_00195530(u8 *arg0);
    extern void btlUnitGetGridSphereCenter(BtlUnit *unit, RwV3d *dst);
    extern f32 func_00196040(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter, f32 *outTop, f32 *outBottom, u32 options);
    extern u8 *btlUnitCreateArcMovePacket(s32 unit, s16 skill, s16 delay);
    extern s32 btlUnitCreateRotateTowardUnitPacket();
    extern s32 func_00198810(u8 *arg0);
    extern BtlPacket *btlUnitCreateMotionSettlePacket(BtlUnit *unit);
    extern BtlPacket *btlUnitCreateModelFramePacket(BtlUnit *unit, s16 value);
    extern BtlPacket *btlUnitCreateMotionSpeedPacket(BtlUnit *unit, u16 value, f32 speed, u16 mode);
    extern u8 *btlUnitCreateModelLoadPacket(u8 *arg0, u16 arg1, s16 arg2);
    extern BtlPacket *func_0019bbe0(BtlUnit *unit, u32 targetColor, s16 startFrame, s16 duration, u8 mode, u8 flags);
    extern BtlPacket *btlUnitCreateLookAtPacket(BtlUnit *unit, const RwV3d *targetPos, u16 flags);
    extern s32 btlUnitCreateLookAtDeactivatePacket(void *, u16);
    extern void btlActionFinishPresentation(BtlAction *arg0);
    extern void btlMainSkillColorPairDefaults(u16 skill, s32 *first, s32 *second); /* lint: allow H011 -- retail passes the lhu skill unconverted */
    extern s32 btlMainSkillColorDefault(u16 skill); /* lint: allow H011 -- retail passes the lhu skill unconverted */
    extern s32 btlMainSkillTintDefault(s32 arg0);
    extern void btlMainSkillColorPairDefaultsAlt(u16 skill, s32 *first, s32 *second); /* lint: allow H011 -- retail passes the lhu skill unconverted */
    extern BtlPacket* btlMainCreateColorLerpPacket(u32 param_1, u32 param_2, u32 param_3);
    extern BtlPacket* btlCreateTimingPacket(u32 value);
    extern BtlPacket *btlMainCreateColorWorkPacket(s32 first, s32 second, s32 third, u32 frames, u16 mode);
    /* lint: allow H011 -- retail zero-extends the mode with andi 0xffff: this caller saw a u16 parameter. */
    extern BtlPacket *btlMainCreateFadePacket(s32 arg, u16 mode);
    extern BtlPacket* btlMainCreateTintPacket(u32 param_1, u32 param_2);
    extern BtlPacket* btlMainCreateColorFadePacket(s32 arg);
    extern BtlPacket* btlMainCreateColorSetPacket(s32 arg);
    extern BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);
    extern u8 *func_001bccc0(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
    extern BtlPacket *btlFormationCreateStepPacket();
    extern BtlPacket *btlFormationCreateTurnPacket(u32 source, u32 action, u32 target, u16 skill);
    extern BtlPacket *btlFormationCreateWaitPacket(u32 param_1, u32 param_2, u16 param_3);
    extern s32 btlFormationAllocWork(u32 param_1);
    extern void btlFormationSetPlacement(u32 param_1);
    extern u32 btlFormationGetFlags(s32 param_1);
    extern BtlPacket *btlFormationCreatePacket(u32 param_1, u32 param_2, u32 param_3, u16 param_4, u32 param_5);
    extern u16 btlTargetGetUnitIndex(BtlTarget *target);
    extern s32 btlUnitSlotValueOrOne(u16 arg0); /* lint: allow H011 -- retail passes the lhu skill unconverted */
    /* lint: allow H011 -- retail passes these u16 arguments without conversion:
     * this caller saw u16 parameters (the definitions take u32/s32). */
    extern void btlFormationFormatName(u16 value, char *destination); /* lint: allow H011 -- retail passes the u16 unconverted */
    extern BtlPacket *btlMainCreateUnitTintPacket(BtlAction *action, u16 selector, u32 duration); /* lint: allow H011 -- retail passes the u16 unconverted */
    extern void func_001f0a10(u8 *result);
    extern s32 btlActionAnyTargetHitRowStatus(u8 *arg0);
    extern s32 btlActionAnyTargetSpecialHit(u8 *arg0);
    extern s32 btlActionSameGenusTargetsHaveDelta(u8 *arg0);
    extern s32 func_001f0d30(u8 *arg0);
    extern s32 func_001f0dd0(u8 *arg0, s32 arg1);
    extern u32 func_001f0f70(u8 *arg0);
    extern s32 btlActionHasNoTargetClass();
    extern s32 func_001f1030(u8 *arg0);
    extern s32 func_001f2f90(u8 *arg0);
    extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
    extern u8 * btlTargetCreateRecordPacket(u8 *arg0);
    extern u8 * btlTargetCreateHitPacket(u8 *arg0);
    extern s32 btlTargetCreateTargetPacket();
    extern s32 func_001f68e0(u8 *arg0);
    extern BtlPacket* btlSoundCreateChannelCuePacket(u16 channel, u16 cue, u16 variant);
    extern BtlPacket* btlSoundCreateSkillSEPacket(u16 skillId, u16 flags);
    extern u8 *func_001f83b0(u32 value);
    extern u8 *func_001f8430(u32 value);
    extern s32 func_001f99c0();
    extern u8 *btlCutinCreatePacket(u8 *data);
    extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
    extern u8 *btlPacketCreateFinishEffect(void);
    extern BtlPacket *btlEffectCreateSpriteFramePacket(u32 param_1, u16 param_2);
    extern BtlPacket *btlPacketCreateSpriteStep(u32 action, u16 arg1);
    extern BtlPacket *btlPacketCreateEffectCounter(s32 arg0, s32 arg1);
    extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 kind, s16 value);
    extern u8 *btlPacketCreateHpRatio(u8 *unit);
    extern void btlPanelSetValueText(u8 *arg0, s32 arg1);
    extern s32 btlActionSelectFormationSlot(u8 *action);
    extern s32 btlActionHasFormationSlot(u8 *action, u8 *handles);
    extern s32 btlActionMatchesSkill(u8 *arg0, s32 arg1);
    extern s32 btlUnitApplyPacketEffects(u8 *packet);
    extern s32 func_0022f8b0(u8 *arg0, s32 arg1);
    extern s32 btlUnitSkillBlocked(u8 *arg0, u8 *arg1);
    extern s32 btlBossActionBlocked();
    extern s32 btlBossSkillAllowed(u8 *arg0);
    extern u16 datCalcGetHp(s32 unit);
    extern s32 func_0023df70(s32 skill);
    /* lint: allow H011 -- the definition is an asm function returning int. */
    extern int func_0043c6a0(int param_1);
    extern u8 *iGpffffb3ac;
    extern u8 *iGpffffb3b8;
    extern u8 *iGpffffb3cc;
    extern u8 *iGpffffb3bc;

    /* Every queued battle packet carries this timing header. */
    typedef struct BtlPacketTiming {
        s8 queue;           /* 0x00 */
        u8 pad01[7];
        s64 startTime;      /* 0x08 */
        u8 pad10[0x37];
        u8 flags;           /* 0x47 */
        s16 delay;          /* 0x48 */
        s16 duration;       /* 0x4A */
        u8 pad4C[0xC];
        s64 endTime;        /* 0x58 */
        s64 ownerId;        /* 0x60 */
    } BtlPacketTiming;
    /* Action fields read here; offsets from the retail loads. */
    typedef struct ActionView7720 {
        u8 pad00[0x18];
        u16 flags;          /* 0x18 */
        u16 flags1A;        /* 0x1A */
        u8 pad1C[0x14];
        u8 *unit;           /* 0x30 */
        u8 pad34[4];
        s32 *target;        /* 0x38 */
        u8 pad3C[0x2E];
        u16 targetCount;    /* 0x6A */
        u16 kind;           /* 0x6C */
        s16 skill;          /* 0x6E */
        u16 field70;        /* 0x70 */
        u8 pad72[0x16];
        s32 *followAction;  /* 0x88 */
        u8 *cutinPartner;   /* 0x8C */
        u8 pad90[0x48];
        u8 fieldD8;         /* 0xD8 */
        u8 padD9[2];
        u8 stateBits;       /* 0xDB */
        u8 padDC[0x10];
        s16 fieldEC;        /* 0xEC */
        s16 fieldEE;        /* 0xEE */
    } ActionView7720;
    typedef struct UnitPartnerView {
        u8 unknown00[0x98];
        u32 flags98;
        u8 unknown9C[0xA0C - 0x9C];
        struct UnitPartnerView *partner;
    } UnitPartnerView;
    typedef struct ActionHitRowView {
        u8 actionPrefix[0xF0];
        LargeBattleHitResult result;
    } ActionHitRowView;
    s64 chainTime;
    BtlPacketTiming *animPacket;
    s32 cameraFirst;
    s32 cameraSecond;
    /* 0022d540 returns the three formation effect handles together. */
    s32 effectHandles[3];
    /* Both cut-in constructors copy ten bytes; modes 3/4 use four. */
    struct { u16 mode, unitId; u8 reserved[6]; } cutin;
    RwV3d targetPosition;
    LargeBattleHitResult result;
    /* Retail reserves 0x60 bytes for the formatted formation name. */
    char formation[96];
    u8 *spRow;
    u8 *primaryTarget;
    u8 *linkedUnit;
    BtlPacketTiming *skillSePkt;
    BtlPacket *followCameraPkt;
    BtlPacketTiming *formationFxPkt;
    BtlPacketTiming *sp4C0;
    BtlPacketTiming *sp4BC;
    BtlPacketTiming *sp4B8;
    s32 formationHandle;
    s64 sceneTime;
    s64 animEndTime;
    s64 formationEndTime;
    s64 cutinEndTime;
    s16 skill;
    s16 cameraState;
    s16 animMotion;
    s16 hitDelay;
    s16 hitWait;                                      /* compiler-managed */
    s32 damageFrames;
    s32 baseDelay;
    s32 crossSideHits;
    s32 statusHits;
    u16 targetIndex;
    u16 hitIndex;
    u16 rowHitCount;
    u16 hitTimer;
    u16 hitTimeTotal;
    u16 statusMask;
    u16 motionFrames;
    u16 windupFrames;
    s32 actionFlag4000;
    s32 rotateFirst;
    s32 randomFlag;
    /* 0/1 phase flags; named by their retail stack slot. */
    s32 sp310;
    s32 sp30C;
    s32 sp2F0;
    s32 sp2E0;
    s32 sp2D0;
    s32 sp2C0;
    s32 sp2B0;
    u16 skillKeyCopy;
    s32 skillS32;
    u16 skillU16;
    u16 skillKey;
    s32 targetIndexS32;
    s32 motionFramesS32;
    s32 *hitResultPtr;
    s32 hasFollowAction;
    s32 noOverride;
    s32 skillFlag2;
    s32 altCamera;
    s32 isKind3;
    s32 skillSpecial;
    s32 hasCutinPartner;
    s32 bossCheck;
    s32 hitModeDelay;
    s32 isSkill16;
    s64 formationEndTime2;
    u16 hitDelta;
    s32 hitFlags;
    s32 sameSideTarget;
    ActionHitRowView *hitRow;
    s8 *hitMotion;
    s16 *hpTransfer;
    s16 hitDelayS16;
    s32 hitIndexS32;
    u16 animBlend;
    s32 rotateFlags;
    f32 targetScale;
    f32 motionFramesF;
    f32 areaScale;
    f32 scaleLimit;
    f32 animSpeed;
    f32 motionSpeed;
    s16 lastActor;
    s32 skillIndex;
    s32 followSkill;
    s32 targetFieldEC;
    s32 timingFrames;
    s32 recoveryFrames;
    s32 animDuration;
    s16 colorDelay;
    s32 cameraDelay;
    s32 formationDelay;
    s32 *hitResult;
    s32 statusTotal;
    s32 cameraKind;
    s32 targetHitValue;
    s32 skillFlagsOffset;
    s32 skillEndFrame;
    s32 targetGroup2;
    s32 hitRowWord;
    s32 hitField14;
    s32 targetGroup;
    s32 hasCutin;
    s32 pendingFollow;
    s32 chanceMiss;
    s32 cameraMode;
    s32 cameraStateA;
    s32 cameraStateB;
    s32 cameraStateC;
    s32 followState;
    s32 hitDelayBase;
    u8 *targetAction;
    u8 *followActionPtr;
    u8 *firstTarget;
    u8 *firstTargetEntry;
    u8 *effectiveAction;
    s32 *targetList;
    s64 actionId;
    s64 lateChainTime;
    s32 recoveryBase;
    s16 skillFramesKey;
    s64 side;
    s32 skillFrames;
    s16 skillKind;
    s16 skillKindRow;
    s16 skillKindUnit;
    s32 motionId;
    s32 statusRemaining;
    s32 motionState;
    s64 cutinTime;
    s32 blendFrames;
    s32 motionDelay;
    s32 motionIdRaw;
    s32 hitMode;
    s8 unitSide;
    u32 motionFramesCopy;
    u16 flagsSnapshot;
    u32 flags1ASnapshot;
    u32 statusTotal2;
    u8 stateBitsCopy;
    s32 hitSide;
    BtlPacketTiming *animPkt17;
    u8 *unit;
    BtlPacketTiming *formationPkt100;
    BtlPacketTiming *pkt101;
    u8 *targetUnit103;
    BtlPacketTiming *pkt104;
    BtlPacketTiming *pkt105;
    BtlPacketTiming *rotatePkt106;
    BtlPacketTiming *pkt107;
    BtlPacketTiming *pkt109;
    BtlPacketTiming *rotatePkt10;
    BtlPacketTiming *pkt110;
    BtlPacketTiming *pkt111;
    BtlPacketTiming *pkt112;
    BtlPacketTiming *pkt113;
    BtlPacketTiming *pkt114;
    BtlPacketTiming *pkt115;
    BtlPacketTiming *pkt116;
    BtlPacketTiming *soundPkt117;
    u8 *hitRowBase;
    BtlPacketTiming *hitPkt119;
    BtlPacketTiming *pkt11;
    BtlPacketTiming *pkt120;
    BtlPacketTiming *hitPkt121;
    BtlPacketTiming *pkt122;
    BtlPacketTiming *pkt123;
    BtlPacketTiming *pkt124;
    BtlPacketTiming *pkt125;
    BtlPacketTiming *pkt126;
    BtlPacketTiming *pkt127;
    BtlPacketTiming *pkt128;
    BtlPacketTiming *pkt129;
    BtlPacketTiming *pkt12;
    BtlPacketTiming *pkt130;
    BtlPacketTiming *hitPkt132;
    BtlPacketTiming *pkt133;
    BtlPacketTiming *pkt134;
    BtlPacketTiming *waitPkt135;
    BtlPacketTiming *colorPkt136;
    BtlPacketTiming *formationPkt137;
    BtlPacketTiming *soundPkt138;
    BtlPacketTiming *pkt139;
    u8 *lookAtPkt13;
    BtlPacketTiming *pkt140;
    BtlPacketTiming *pkt141;
    BtlPacketTiming *pkt142;
    BtlPacketTiming *pkt143;
    BtlPacketTiming *cameraPkt144;
    BtlPacketTiming *cameraPkt145;
    BtlPacketTiming *colorPkt146;
    BtlPacketTiming *colorPkt147;
    BtlPacketTiming *effectPkt148;
    BtlPacketTiming *pkt149;
    BtlPacketTiming *cutinPkt14;
    BtlPacketTiming *pkt150;
    BtlPacketTiming *cutinPkt15;
    BtlPacketTiming *pkt16;
    BtlPacketTiming *soundPkt17;
    BtlPacketTiming *formationPkt18;
    BtlPacketTiming *pkt19;
    BtlPacketTiming *pkt20;
    u8 *linkedMotionPkt;
    u8 *waitPkt22;
    BtlPacketTiming *waitPkt23;
    BtlPacketTiming *effectPkt24;
    BtlPacketTiming *soundPkt25;
    BtlPacketTiming *animPkt27;
    BtlPacketTiming *pkt28;
    BtlPacketTiming *pkt29;
    BtlPacketTiming *effectPkt30;
    BtlPacketTiming *soundPkt31;
    BtlPacketTiming *effectPkt32;
    BtlPacketTiming *colorPkt33;
    BtlPacketTiming *animPkt34;
    BtlPacketTiming *colorPkt35;
    BtlPacketTiming *soundPkt36;
    BtlPacketTiming *cameraPkt37;
    u8 *lookAtPkt38;
    BtlPacketTiming *animPkt39;
    BtlPacketTiming *formationPkt40;
    BtlPacketTiming *cameraPkt41;
    BtlPacketTiming *cameraPkt42;
    BtlPacketTiming *effectPkt43;
    u8 *lookAtPkt44;
    BtlPacketTiming *animPkt45;
    BtlPacketTiming *waitPkt46;
    BtlPacketTiming *cameraPkt47;
    BtlPacketTiming *waitPkt48;
    BtlPacketTiming *formationPkt49;
    BtlPacketTiming *rotatePkt4;
    BtlPacketTiming *cameraPkt50;
    BtlPacketTiming *effectPkt51;
    BtlPacketTiming *soundPkt52;
    BtlPacketTiming *effectPkt53;
    BtlPacketTiming *soundPkt54;
    BtlPacketTiming *cameraPkt55;
    BtlPacketTiming *animPkt56;
    BtlPacketTiming *formationPkt58;
    BtlPacketTiming *cameraPkt59;
    BtlPacketTiming *pkt5;
    BtlPacketTiming *cameraPkt60;
    BtlPacketTiming *cameraPkt61;
    BtlPacketTiming *cameraPkt62;
    BtlPacketTiming *cameraPkt63;
    BtlPacketTiming *cameraPkt66;
    BtlPacketTiming *pkt67;
    BtlPacketTiming *animPkt68;
    BtlPacketTiming *animPkt69;
    BtlPacketTiming *pkt6;
    BtlPacketTiming *cameraPkt70;
    BtlPacketTiming *formationPkt71;
    BtlPacketTiming *rotatePkt72;
    BtlPacketTiming *animPkt73;
    BtlPacketTiming *rotatePkt74;
    BtlPacketTiming *waitPkt75;
    BtlPacketTiming *formationPkt76;
    BtlPacketTiming *pkt77;
    BtlPacketTiming *pkt79;
    u8 *lookAtPkt7;
    BtlPacketTiming *pkt80;
    BtlPacketTiming *formationPkt81;
    BtlPacketTiming *pkt83;
    BtlPacketTiming *lookAtPkt84;
    BtlPacketTiming *lookAtPkt85;
    BtlPacketTiming *pkt86;
    BtlPacketTiming *pkt87;
    BtlPacketTiming *colorPkt88;
    BtlPacketTiming *colorPkt89;
    u8 *lookAtPkt8;
    BtlPacketTiming *rotatePkt90;
    BtlPacketTiming *pkt91;
    BtlPacketTiming *soundPkt93;
    BtlPacketTiming *soundPkt94;
    BtlPacketTiming *animPkt98;
    BtlPacketTiming *pkt99;
    u8 *lookAtPkt9;
    u8 *btlState10_310;
    u8 *btlState11_311;
    u8 *btlState12;
    u8 *btlState18;
    u8 *actUnit20_320;
    u8 *btlState3_33;
    u8 *btlState4;
    u8 *btlState7_37;
    u8 *btlState8_38;
    u8 *btlState9_39;
    u8 *btlState10_410;
    u8 *btlState11_411;
    u8 *targetUnit12;
    u8 *actUnit16;
    u8 *btlState17;
    u8 *actUnit19;
    u8 *actUnit20_420;
    u8 *btlState2;
    u8 *btlState3_43;
    u8 *btlState5;
    u8 *btlState6;
    u8 *btlState7_47;
    u8 *btlState8_48;
    u8 *btlState9_49;
    u8 *actUnit5_5;
    u8 *targetUnit2;
    u8 *targetUnit3;
    u8 *actUnit5_55;
    BtlPacketTiming *waitPkt2;
    BtlPacketTiming *animChainPkt;
    BtlPacketTiming *formationPkt6;
    BtlPacketTiming *pkt4;
    BtlPacketTiming *anchorPkt;
    BtlPacketTiming *formationNamePkt;
    BtlPacketTiming *pkt10;
    BtlPacketTiming *soundPkt9;

    ActionView7720 *act = (ActionView7720 *)arg0;

    unit = (u8 *)(act->unit);
    unitSide = (s8)(*(s8 *)(unit + 0xA2));
    linkedUnit = (u8 *)(*(u8 **)(unit + 0xA0C));
    skill = (s16)(act->skill);
    primaryTarget = (u8 *)(act->target);
    actionFlag4000 = (s32)((act->flags & 0x4000)) != (s32)(0);
    formationEndTime = 0;
    cutinEndTime = 0;
    crossSideHits = 0;
    statusHits = 0;
    statusMask = 0;
    hitDelay = 0;
    baseDelay = 0;
    hasCutin = 0;
    randomFlag = 0;
    sp310 = 0;
    sp30C = 0;
    sp2F0 = 0;
    sp2E0 = 0;
    sp2D0 = 0;
    sp2C0 = 0;
    sp2B0 = 0;
    hasFollowAction = (s32)(s32)(act->followAction) != (s32)(0);
    noOverride = (s32)(func_001f2f90(arg0)) == (s32)(0);
    windupFrames = 6;
    skillIndex = skill;
    skillFlag2 = (s32)(s32)((*(iGpffffb3b8 + skillIndex * 0x28) & 2)) != (s32)(0);
    altCamera = ((act->flags1A & 0x10) != 0) && skillFlag2 == 0;
    isKind3 = (s32)(s32)(act->kind == 3);
    rotateFirst = (s32)(btlActionHasNoTargetClass(arg0));
    skillSpecial = (s32)(func_001f11e0(skill));
    hasCutinPartner = (s32)(s32)(act->cutinPartner) != (s32)(0);
    formationFxPkt = 0;
    actionId = *(s64 *)(arg0 + 0);
    btlActionFinishPresentation((BtlAction *)arg0);
    side = (s8)unitSide;
    if ((side == 1) && (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000)) {
        actionFlag4000 = 0;
    }
    if (actionFlag4000 == 0) {
        formationHandle = (s32)(btlFormationAllocWork(1));
    } else {
        skillKind = (s16)datCalcSkillElement(NULL, (u16)skill);
        switch (skillKind) {                           /* switch 1; irregular */
        case 16:                                    /* switch 1 */
            formationHandle = (s32)(*(s32 *)(iGpffffb3ac + 0xD9C));
            break;
        case 17:                                    /* switch 1 */
            formationHandle = (s32)(*(s32 *)(iGpffffb3ac + 0xDA0));
            break;
        default:                                    /* switch 1 */
            formationHandle = (s32)(*(s32 *)(iGpffffb3ac + 0xD98));
            break;
        }
    }
    flags1ASnapshot = (u16)(act->flags1A);
    if (!(flags1ASnapshot & 1)) {
        pendingFollow = 0;
    } else {
        UnitPartnerView *partner = (*(UnitPartnerView **)(arg0 + 0x30))->partner;
        if (!(flags1ASnapshot & 0x10)) {
            pendingFollow = 0;
        } else if (partner->flags98 & 2) {
            pendingFollow = 1;
        } else {
            pendingFollow = 0;
        }
    }
    if (pendingFollow != 0) {
        sp2B0 = 1;
    }
    bossCheck = (s32)(s32)(btlBossSkillAllowed(arg0));
    if (side >= 0) {
        if (sp2B0 != 0) {
            rotateFlags = 0x1002;
        } else {
            rotateFlags = 0;
        }
        if (rotateFirst != 0) {
            rotatePkt4 = (BtlPacketTiming *)(btlUnitCreateRotateTowardUnitPacket(act->unit, (*( u8 ** )((u8 *)(act->target) + (0x30))), rotateFlags));
            rotatePkt4->ownerId = actionId;
            btlPacketEnqueue((u8 *)rotatePkt4, 0);
        } else if (side == 0) {
            func_00196040((u16)btlTargetGetUnitIndex((BtlTarget *)(arg0 + 0x38)), 1, &targetPosition, 0, 0, 1);
            pkt5 = (BtlPacketTiming *)(btlUnitCreateRotatePacket(*(BtlUnit **)(arg0 + 0x30), &targetPosition, rotateFlags));
            pkt5->ownerId = actionId;
            btlPacketEnqueue((u8 *)pkt5, 0);
        } else {
            btlState2 = (u8 *)(iGpffffb3ac);
            if (*(s32 *)(btlState2 + 0xC) & 0x200000) {
                btlUnitGetGridSphereCenter((*( BtlUnit ** )((u8 *)(*(u8 **)(btlState2 + 0x170)) + (0x30))), &targetPosition);
                pkt6 = (BtlPacketTiming *)(btlUnitCreateRotatePacket(*(BtlUnit **)(arg0 + 0x30), &targetPosition, rotateFlags));
                pkt6->ownerId = actionId;
                btlPacketEnqueue((u8 *)pkt6, 0);
            }
        }
        if (bossCheck != 0) {
            lookAtPkt7 = (u8 *)(actionLookAtUnit(0, act->unit, 3));
            *(s64 *)(lookAtPkt7 + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue((u8 *)lookAtPkt7, 1);
            lookAtPkt8 = (u8 *)(btlUnitCreateLookAtDeactivatePacket(act->unit, 0));
            *(s64 *)(lookAtPkt8 + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue((u8 *)lookAtPkt8, 1);
        } else {
            lookAtPkt9 = (u8 *)(btlUnitCreateLookAtDeactivatePacket(0, 3));
            *(s64 *)(lookAtPkt9 + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue((u8 *)lookAtPkt9, 1);
        }
        act->flags = (u16) (act->flags | 0x200);
        rotatePkt10 = (BtlPacketTiming *)(btlTargetCreateHitPacket(arg0));
        rotatePkt10->ownerId = actionId;
        btlPacketEnqueue((u8 *)rotatePkt10, 1);
    }
    skillFlagsOffset = skillIndex * 4;
    if ((*( u16 * )((u8 *)(skillFlagsOffset + (s32)iGpffffb3bc) + (2))) & 0x100) {
        hitMode = 3;
    } else {
        hitMode = 1;
    }
    hitModeDelay = (s16)hitMode;
    if (isKind3 == 0) {
        pkt11 = (BtlPacketTiming *)(btlEffectCreateSpriteFramePacket(*(u32 *)(arg0 + 0x30), (u16) skill));
        pkt11->delay = (s16) hitModeDelay;
        pkt11->ownerId = actionId;
        btlPacketEnqueue((u8 *)pkt11, 3);
    } else {
        pkt12 = (BtlPacketTiming *)(btlPacketCreateSpriteStep(*(u32 *)(arg0 + 0x30), act->field70));
        pkt12->delay = (s16) hitModeDelay;
        pkt12->ownerId = actionId;
        btlPacketEnqueue((u8 *)pkt12, 3);
    }
    if (altCamera == 1) {
        if ((isKind3 == 0) && (noOverride == 0)) {
            if ((hasCutinPartner == 0) && (sp2B0 == 0)) {
                if (side == 0) {
                    if (!(act->flags & 0x40) && ((((s32)(btlActionAnyTargetHitRowStatus(arg0)) != (s32)(0)) && (datCalcRandomBelow(0x64U) < 0x14U)) || (*(s32 *)(iGpffffb3ac + 0x10) & 0x1000))) {
                        hasCutin = 1;
                        act->flags = (u16) (act->flags | 0x40);
                        btlState3_43 = (u8 *)(iGpffffb3ac);
                        *(s32 *)(btlState3_43 + 0x10) = (s32) (*(s32 *)(btlState3_43 + 0x10) & ~0x1000);
                    }
                } else if ((side == 1) && (*(s32 *)(iGpffffb3ac + 0x10) & 0x800)) {
                    flagsSnapshot = (u16)(act->flags);
                    if (!(flagsSnapshot & 0x40)) {
                        hasCutin = 1;
                        act->flags = (u16) (flagsSnapshot | 0x40);
                    }
                }
            }
            skillU16 = skill;
            isSkill16 = ((s16)datCalcSkillElement(NULL, (u16)skillU16) == 0x10);
            if ((s32)(btlActionHasFormationSlot(arg0, (u8 *)effectHandles)) == (s32)(0)) {
                btlState3_33 = (u8 *)(iGpffffb3ac);
                effectHandles[0] = (*(s32 *)((u8 *)btlState3_33 + 0xD30));
                effectHandles[1] = (*(s32 *)((u8 *)btlState3_33 + 0xD34));
                effectHandles[2] = (*(s32 *)((u8 *)btlState3_33 + 0xD38));
            }
            if (((s32)(func_001f11e0(skill)) == (s32)(0)) && ((s32)(btlActionAnyTargetSpecialHit(arg0)) == (s32)(0))) {
                targetGroup = (s32)((u16)btlTargetGetUnitIndex((BtlTarget *)(arg0 + 0x38)));
                if ((side == 0) && (((u16)targetGroup) == 2)) {
                    randomFlag = (s32)((effMiscRand(0) & 1)) != (s32)(0);
                } else if ((side == 1) && (((u16)targetGroup) == 1)) {
                    randomFlag = 1;
                }
            }
            if (((s32)(btlUnitSkillBlocked(arg0, linkedUnit)) != (s32)(0)) || (*(s32 *)(iGpffffb3ac + 0x10) & 0x40)) {
                randomFlag = 1;
            }
            if ((*( u16 * )((u8 *)(skillFlagsOffset + (s32)iGpffffb3bc) + (2))) & 0x4000) {
                randomFlag = 1;
                baseDelay = 2;
            }
            if ((side == 0) && (func_001f1030(arg0) != 0) && (skillIndex != 0xF4)) {
                sp2D0 = 1;
                randomFlag = 1;
                hasCutin = 0;
                lookAtPkt13 = (u8 *)(btlUnitCreateLookAtDeactivatePacket(0, 3));
                *(s64 *)(lookAtPkt13 + 0x60) = *(s64 *)arg0;
                btlPacketEnqueue((u8 *)lookAtPkt13, 1);
                btlState5 = (u8 *)(iGpffffb3ac);
                *(s32 *)(btlState5 + 0xC) = (s32) (*(s32 *)(btlState5 + 0xC) | 0x400000);
                btlState4 = (u8 *)(iGpffffb3ac);
                *(u16 *)(btlState4 + 0x18) = (u16) (*(u16 *)(btlState4 + 0x18) | 6);
            }
            motionState = (s16)func_00198810(act->unit);
            switch (motionState) {
            case 0:
            case 0x11:
                blendFrames = 0;
                break;
            default:
                blendFrames = 6;
                break;
            }
            if (hasCutin != 0) {
                btlPacketEnqueue((u8 *)btlSoundCreateUnitFlagSetPacket((BtlUnit *)act->unit), 0);
            } else if (isSkill16 != 0) {
                btlPacketEnqueue((u8 *)(func_001f83b0((u32)act->unit)), 0);
            }
            if (sp2B0 != 0) {
                waitPkt2 = (BtlPacketTiming *)(func_00194b60());
            } else {
                waitPkt2 = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)act->unit, 0xD, (u16)blendFrames, 1.0f, 4));
            }
            waitPkt2->ownerId = actionId;
            btlPacketEnqueue((u8 *)waitPkt2, 0);
            cutinTime = waitPkt2->endTime;
            if (sp2B0 == 0) {
                recoveryFrames = btlUnitMotionModelFrames(act->unit, 0xD, 1.0f);
                recoveryFrames += (s16)blendFrames;
            } else {
                recoveryFrames = 0;
            }
            if (sp2B0 != 0) {
                anchorPkt = (BtlPacketTiming *)(func_00194b60());
            } else {
                if (side == 0) {
                    cameraStateB = 0x14;
                } else {
                    cameraStateB = 0x15;
                }
                anchorPkt = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)arg0, (u16)cameraStateB));
            }
            anchorPkt->ownerId = actionId;
            btlPacketEnqueue((u8 *)anchorPkt, 0);
            sceneTime = anchorPkt->endTime;
            if (hasCutin != 0) {
                cutin.mode = 4;
                cutin.unitId = (u16)((*( u16 * )((u8 *)(act->unit) + (0xA4))));
                cutinPkt14 = (BtlPacketTiming *)(btlCutinCreatePacket((u8 *)&cutin));
                cutinPkt14->queue = 4;
                cutinPkt14->startTime = cutinTime;
                cutinPkt14->ownerId = actionId;
                btlPacketEnqueue((u8 *)cutinPkt14, 1);
                cutinPkt15 = (BtlPacketTiming *)btlCutinCreateEndPacket();
                cutinPkt15->queue = 4;
                cutinPkt15->startTime = cutinPkt14->endTime;
                cutinPkt15->ownerId = actionId;
                btlPacketEnqueue((u8 *)cutinPkt15, 1);
                pkt16 = (BtlPacketTiming *)(func_001f99c0(arg0, 1, *(u16 *)(linkedUnit + 0xA4), 0, 1));
                pkt16->queue = 5;
                pkt16->startTime = cutinPkt15->endTime;
                pkt16->ownerId = actionId;
                btlPacketEnqueue((u8 *)pkt16, 1);
                soundPkt17 = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xA, 2, 0xB));
                soundPkt17->queue = 5;
                soundPkt17->startTime = cutinPkt15->endTime;
                soundPkt17->ownerId = *(s64 *)arg0;
                btlPacketEnqueue((u8 *)soundPkt17, 1);
                cutinTime = cutinPkt15->endTime;
                cutinEndTime = cutinTime;
                recoveryFrames = 0;
            }
            formationPkt18 = (BtlPacketTiming *)(btlFormationCreateStepPacket(arg0,(s32)((act->flags & 0x10)) != (s32)(0), 1));
            formationPkt18->queue = 4;
            formationPkt18->startTime = cutinTime;
            formationPkt18->delay = (s16) (recoveryFrames - (recoveryFrames >> 3));
            formationPkt18->ownerId = actionId;
            btlPacketEnqueue((u8 *)formationPkt18, 0);
            formationEndTime = formationPkt18->endTime;
            if (rotateFirst != 0) {
                targetList = (s32 *)(act->target);
            } else {
                targetList = 0;
            }
            pkt19 = (BtlPacketTiming *)(btlFormationCreateTurnPacket((u32)linkedUnit, (u32)arg0, (u32)targetList, skillU16));
            pkt19->queue = 5;
            pkt19->startTime = formationEndTime;
            pkt19->ownerId = actionId;
            btlPacketEnqueue((u8 *)pkt19, 0);
            if (sp2B0 == 0) {
                if (hasCutin != 0) {
                    pkt20 = (BtlPacketTiming *)(btlUnitCreateModelLoadPacket((u8 *)linkedUnit, *(u16 *)(linkedUnit + 0xA4), 0x1D));
                    animChainPkt = (BtlPacketTiming *)((u8 *)pkt20);
                    pkt20->queue = 5;
                    pkt20->startTime = cutinEndTime;
                    (*( s8 * )((u8 *)pkt20 + (0x20))) = 5;
                    (*( s64 * )((u8 *)pkt20 + (0x28))) = formationEndTime;
                } else {
                    linkedMotionPkt = (u8 *)(btlUnitCreateModelLoadPacket((u8 *)linkedUnit, *(u16 *)(linkedUnit + 0xA4), 0xD));
                    animChainPkt = (BtlPacketTiming *)(linkedMotionPkt);
                    *(s16 *)(linkedMotionPkt + 0x48) = recoveryFrames;
                }
                animChainPkt->ownerId = actionId;
                btlPacketEnqueue((u8 *)animChainPkt, 1);
            } else {
                waitPkt22 = (u8 *)(func_00194b60());
                animChainPkt = (BtlPacketTiming *)(waitPkt22);
                *(s16 *)(waitPkt22 + 0x48) = recoveryFrames;
                btlPacketEnqueue((u8 *)animChainPkt, 0);
            }
            waitPkt23 = (BtlPacketTiming *)(func_00194b60());
            waitPkt23->queue = 4;
            waitPkt23->startTime = animChainPkt->endTime;
            waitPkt23->delay = 0xC;
            waitPkt23->ownerId = actionId;
            btlPacketEnqueue((u8 *)waitPkt23, 1);
            effectPkt24 = (BtlPacketTiming *)(func_001d65d0(effectHandles[0], (*(s32 *)(arg0 + 0x30)), 0, (waitPkt23->endTime), 0x100));
            effectPkt24->ownerId = actionId;
            btlPacketEnqueue((u8 *)effectPkt24, 2);
            soundPkt25 = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xA, 2, 3));
            soundPkt25->ownerId = actionId;
            btlPacketEnqueue((u8 *)soundPkt25, 1);
            actUnit5_5 = (u8 *)(act->unit);
            skillFramesKey = (s16)btlUnitOpeningMotionMode(*(s32 *)(actUnit5_5 + 0xA0C), actUnit5_5, skill, rotateFirst);
            skillFrames = (s32)(btlUnitMotionFrames((*( u8 ** )((u8 *)(act->unit) + (0xA0C))), (u16)skillFramesKey, 1.0f));
            damageFrames = (s32) skillFrames;
            windupFrames = (u16)(func_001996d0(act->unit, 0x10));
            chainTime = animChainPkt->endTime;
            skillEndFrame = skillFrames + 0x12;
            if (baseDelay < skillEndFrame) {
                timingFrames = skillEndFrame - baseDelay;
            } else {
                timingFrames = 0;
            }
            animPkt27 = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)act->unit, 0xF, 0, 1.0f, 5));
            animPkt27->queue = 4;
            animPkt27->startTime = chainTime;
            animPkt27->ownerId = actionId;
            btlPacketEnqueue((u8 *)animPkt27, 0);
            if (hasCutin != 0) {
                pkt28 = (BtlPacketTiming *)(btlSoundCreateUnitFlagClearPacket((BtlUnit *)act->unit));
                pkt28->queue = 4;
                pkt28->startTime = animPkt27->endTime;
                pkt28->ownerId = actionId;
                btlPacketEnqueue((u8 *)pkt28, 0);
            } else if (isSkill16 != 0) {
                pkt29 = (BtlPacketTiming *)(func_001f8430((u32)act->unit));
                pkt29->queue = 4;
                pkt29->startTime = animPkt27->endTime;
                pkt29->ownerId = actionId;
                btlPacketEnqueue((u8 *)pkt29, 0);
            }
            recoveryBase = (s32)(btlUnitMotionFrames(act->unit, 0xFU, 1.0f));
            effectPkt30 = (BtlPacketTiming *)(func_001d65d0(effectHandles[1], (*(s32 *)(arg0 + 0x30)), 0, 0, 0x100));
            effectPkt30->queue = 4;
            effectPkt30->startTime = chainTime;
            effectPkt30->delay = (s16) recoveryBase;
            effectPkt30->ownerId = actionId;
            btlPacketEnqueue((u8 *)effectPkt30, 2);
            soundPkt31 = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xC, 2, 4));
            soundPkt31->queue = 4;
            soundPkt31->startTime = chainTime;
            soundPkt31->delay = (s16)recoveryBase + 2;
            soundPkt31->ownerId = actionId;
            btlPacketEnqueue((u8 *)soundPkt31, 1);
            effectPkt32 = (BtlPacketTiming *)(func_001d65d0(effectHandles[2], (*(s32 *)(arg0 + 0x30)), 0, 0, 0x100));
            effectPkt32->queue = 4;
            effectPkt32->startTime = chainTime;
            effectPkt32->ownerId = actionId;
            btlPacketEnqueue((u8 *)effectPkt32, 2);
            colorPkt33 = (BtlPacketTiming *)(func_0019bbe0((BtlUnit *)act->unit, 0xFF808080, 0, 0xC, 4, 0));
            colorPkt33->queue = 4;
            colorPkt33->startTime = chainTime;
            colorPkt33->ownerId = actionId;
            btlPacketEnqueue((u8 *)colorPkt33, 1);
            animPkt34 = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)linkedUnit, skillFramesKey, 0, 1.0f, 2));
            animPacket = (BtlPacketTiming *)(animPkt34);
            animPkt34->queue = 4;
            animPkt34->startTime = chainTime;
            animPkt34->delay = 0xF;
            animPkt34->ownerId = actionId;
            btlPacketEnqueue((u8 *)animPacket, 0);
            colorPkt35 = (BtlPacketTiming *)(func_0019bbe0((BtlUnit *)linkedUnit, (u32)(func_00195530(linkedUnit)), 8, 0, 3, 1));
            colorPkt35->queue = 4;
            colorPkt35->startTime = animPacket->endTime;
            colorPkt35->ownerId = actionId;
            btlPacketEnqueue((u8 *)colorPkt35, 1);
            soundPkt36 = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xD, 2, 5));
            soundPkt36->queue = 4;
            soundPkt36->startTime = animPacket->endTime;
            soundPkt36->ownerId = actionId;
            btlPacketEnqueue((u8 *)soundPkt36, 1);
            if ((randomFlag == 1) && (sp2D0 == 0) && !((*( u16 * )((u8 *)(skillFlagsOffset + (s32)iGpffffb3bc) + (2))) & 0x40)) {
                if (side == 0) {
                    cameraStateC = 0x19;
                } else {
                    cameraStateC = 0x1A;
                }
                cameraPkt37 = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)arg0, (u16)cameraStateC));
                cameraPkt37->queue = 4;
                cameraPkt37->startTime = animPacket->endTime;
                if (damageFrames >= baseDelay) {
                    cameraDelay = damageFrames - baseDelay;
                } else {
                    cameraDelay = 0;
                }
                cameraPkt37->delay = cameraDelay;
                cameraPkt37->ownerId = actionId;
                btlPacketEnqueue((u8 *)cameraPkt37, 0);
            }
            animEndTime = animPacket->endTime;
        } else if ((isKind3 == 1) || (noOverride == 1)) {
            if ((side == 0) && (func_001f1030(arg0) != 0) && (skillIndex != 0xF4)) {
                sp2D0 = 1;
                randomFlag = 1;
                lookAtPkt38 = (u8 *)(btlUnitCreateLookAtDeactivatePacket(0, 3));
                *(s64 *)(lookAtPkt38 + 0x60) = *(s64 *)arg0;
                btlPacketEnqueue((u8 *)lookAtPkt38, 1);
                btlState6 = (u8 *)(iGpffffb3ac);
                *(s32 *)(btlState6 + 0xC) = (s32) (*(s32 *)(btlState6 + 0xC) | 0x400000);
                btlState7_37 = (u8 *)(iGpffffb3ac);
                *(u16 *)(btlState7_37 + 0x18) = (u16) (*(u16 *)(btlState7_37 + 0x18) | 6);
            }
            animPkt39 = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)act->unit, 0x16, 6, 1.0f, 0));
            animPacket = (BtlPacketTiming *)(animPkt39);
            animPkt39->ownerId = actionId;
            btlPacketEnqueue((u8 *)animPacket, 0);
            sceneTime = animPacket->endTime;
            chainTime = 0;
                    timingFrames = btlUnitMotionFrames(act->unit, 0x16U, 1.0f) + 6;
            if (!((*( u16 * )((u8 *)(skillFlagsOffset + (s32)iGpffffb3bc) + (2))) & 0x40)) {
                if ((s32)(btlActionHasNoTargetClass(arg0)) == (s32)(1)) {
                    formationPkt40 = (BtlPacketTiming *)(btlFormationCreateStepPacket(arg0, 0, 1));
                    formationPkt40->queue = 4;
                    formationPkt40->startTime = animPacket->endTime;
                    formationPkt40->ownerId = actionId;
                    btlPacketEnqueue((u8 *)formationPkt40, 0);
                }
                if (randomFlag == 0) {
                    cameraPkt41 = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x19));
                    cameraPkt41->queue = 4;
                    cameraPkt41->startTime = animPacket->endTime;
                    cameraPkt41->ownerId = actionId;
                    btlPacketEnqueue((u8 *)cameraPkt41, 0);
                } else {
                    cameraPkt42 = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x1B));
                    cameraPkt42->queue = 4;
                    cameraPkt42->startTime = animPacket->endTime;
                    cameraPkt42->ownerId = actionId;
                    btlPacketEnqueue((u8 *)cameraPkt42, 0);
                }
            }
            if (noOverride == 0) {
                effectPkt43 = (BtlPacketTiming *)(func_001d65d0(*(s32 *)(iGpffffb3ac + 0xD88), (*(s32 *)(arg0 + 0x30)), btlEffectDelay_001a7720(timingFrames), 0, 0x100));
                effectPkt43->queue = 4;
                effectPkt43->startTime = animPacket->endTime;
                btlPacketEnqueue((u8 *)effectPkt43, 1);
            }
        }
    } else if ((altCamera == 0) && (side == 1)) {
        sp30C = 1;
        if ((s32)(func_0022f8b0(arg0, skillIndex)) != (s32)(0)) {
            sp2D0 = 1;
            hasCutin = 0;
            lookAtPkt44 = (u8 *)(btlUnitCreateLookAtDeactivatePacket(0, 3));
            *(s64 *)(lookAtPkt44 + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue((u8 *)lookAtPkt44, 1);
            btlState7_47 = (u8 *)(iGpffffb3ac);
            *(s32 *)(btlState7_47 + 0xC) = (s32) (*(s32 *)(btlState7_47 + 0xC) | 0x400000);
            btlState8_38 = (u8 *)(iGpffffb3ac);
            *(u16 *)(btlState8_38 + 0x18) = (u16) (*(u16 *)(btlState8_38 + 0x18) | 6);
        }
        if (actionFlag4000 == 0) {
            animSpeed = 1.0f;
        } else {
            animSpeed = 2.0f;
            sp2C0 = 1;
            btlState8_48 = (u8 *)(iGpffffb3ac);
            *(s32 *)(btlState8_48 + 0xC) = (s32) (*(s32 *)(btlState8_48 + 0xC) | 0x400000);
            btlState9_39 = (u8 *)(iGpffffb3ac);
            *(u16 *)(btlState9_39 + 0x18) = (u16) (*(u16 *)(btlState9_39 + 0x18) | 0x47);
        }
        if ((skillFlag2 == 1) || ((s32)(func_001f11e0(skill)) != (s32)(0))) {
            animMotion = 4;
            animBlend = 2;
        } else {
            animMotion = 8;
            animBlend = 3;
        }
        if ((s32)((*( u8 * )((u8 *)(act->unit) + (0xA2)))) == (s32)(1)) {
            if ((s32)(btlActionMatchesSkill(arg0, skillIndex)) != (s32)(0)) {
                animBlend = 2;
                sp30C = 0;
                sp2C0 = 1;
                btlState9_49 = (u8 *)(iGpffffb3ac);
                *(s32 *)(btlState9_49 + 0xC) = (s32) (*(s32 *)(btlState9_49 + 0xC) | 0x400000);
                btlState10_310 = (u8 *)(iGpffffb3ac);
                *(u16 *)(btlState10_310 + 0x18) = (u16) (*(u16 *)(btlState10_310 + 0x18) | 7);
            } else if (btlCameraField_001a59a0(*(u16 *)(act->unit + 0xA4), (s16 *)(iGpffffb3cc + 0x18)) & 1) {
                animBlend = 0;
                sp2F0 = 1;
                sp30C = 0;
            }
        }
        if (!((*( u16 * )((u8 *)(skillFlagsOffset + (s32)iGpffffb3bc) + (2))) & 0x100)) {
            if ((s32)(btlUnitSlotIsOpen(arg0, animMotion)) != (s32)(0)) {
                animPkt45 = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)act->unit, animMotion, 6, animSpeed, animBlend));
                animPacket = (BtlPacketTiming *)(animPkt45);
                animPkt45->ownerId = actionId;
                btlPacketEnqueue((u8 *)animPacket, 0);
            } else {
                waitPkt46 = (BtlPacketTiming *)(func_00194b60());
                animPacket = (BtlPacketTiming *)(waitPkt46);
                waitPkt46->ownerId = actionId;
                btlPacketEnqueue((u8 *)animPacket, 0);
            }
            if ((actionFlag4000 == 0) && ((s32)(btlBossActionBlocked(arg0, skillIndex)) != (s32)(0))) {
                cameraPkt47 = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x15));
                cameraPkt47->queue = 4;
                cameraPkt47->startTime = animPacket->endTime;
                cameraPkt47->ownerId = actionId;
                btlPacketEnqueue((u8 *)cameraPkt47, 0);
            }
        } else {
            waitPkt48 = (BtlPacketTiming *)(func_00194b60());
            animPacket = (BtlPacketTiming *)(waitPkt48);
            waitPkt48->ownerId = actionId;
            btlPacketEnqueue((u8 *)animPacket, 0);
        }
        sceneTime = animPacket->endTime;
        chainTime = 0;
            timingFrames = btlUnitMotionFrames(act->unit, (u16) animMotion, animSpeed) + 6;
        if (!((*( u16 * )((u8 *)(skillFlagsOffset + (s32)iGpffffb3bc) + (2))) & 0x40) && (sp2D0 == 0)) {
            formationPkt49 = (BtlPacketTiming *)(btlFormationCreateStepPacket(arg0,(s32)((act->flags & 0x10)) != (s32)(0), 1));
            formationPkt49->queue = 4;
            formationPkt49->startTime = animPacket->endTime;
            if (actionFlag4000 == 0) {
                if (timingFrames > 0xc) {
                    formationDelay = timingFrames - 0xC;
                } else {
                    formationDelay = 0;
                }
                formationPkt49->delay = formationDelay;
            }
            formationPkt49->ownerId = actionId;
            btlPacketEnqueue((u8 *)formationPkt49, 0);
            formationEndTime = formationPkt49->endTime;
            cameraPkt50 = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x1A));
            cameraPkt50->queue = 4;
            cameraPkt50->startTime = formationEndTime;
            cameraPkt50->ownerId = actionId;
            btlPacketEnqueue((u8 *)cameraPkt50, 0);
        }
        if ((skillFlag2 == 0) && (noOverride == 0)) {
            followState = (s32)(btlActionSelectFormationSlot(arg0));
            if (followState == 0) {
                followState = *(s32 *)((u8 *)iGpffffb3ac + 0xD40);
            }
            effectPkt51 = (BtlPacketTiming *)(func_001d65d0(followState, (*(s32 *)(arg0 + 0x30)), btlEffectDelay_001a7720(timingFrames), 0, 0x100));
            effectPkt51->queue = 4;
            effectPkt51->startTime = animPacket->endTime;
            btlPacketEnqueue((u8 *)effectPkt51, 1);
            soundPkt52 = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xA, 2, 7));
            soundPkt52->queue = 4;
            soundPkt52->startTime = animPacket->endTime;
            btlPacketEnqueue((u8 *)soundPkt52, 1);
        }
    } else if ((altCamera == 0) && (side == 0)) {
        sp2C0 = 1;
        effectPkt53 = (BtlPacketTiming *)(func_001d65d0(*(s32 *)(iGpffffb3ac + 0xDB8), (*(s32 *)(arg0 + 0x30)), 0, 0, 0x100));
        effectPkt53->ownerId = actionId;
        btlPacketEnqueue((u8 *)effectPkt53, 2);
        animPkt17 = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)act->unit, 6, 0, 1.0f, 2));
        animPkt17->duration = (s16)(btlUnitMotionModelFrames(act->unit, 6, 1.0f));
        animPkt17->ownerId = actionId;
        btlPacketEnqueue((u8 *)animPkt17, 0);
        soundPkt54 = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xA, 2, 0x11));
        soundPkt54->delay = 1;
        soundPkt54->ownerId = actionId;
        btlPacketEnqueue((u8 *)soundPkt54, 1);
        cameraPkt55 = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x12));
        cameraPkt55->ownerId = actionId;
        btlPacketEnqueue((u8 *)cameraPkt55, 0);
        animPkt56 = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)act->unit, 7, 6, 1.0f, 2));
        animPacket = (BtlPacketTiming *)(animPkt56);
        animPkt56->queue = 4;
        animPkt56->startTime = animPkt17->endTime;
        animPkt56->ownerId = actionId;
        btlPacketEnqueue((u8 *)animPacket, 0);
        sceneTime = 0;
        chainTime = animPacket->endTime;
        timingFrames = btlUnitMotionFrames(act->unit, 7U, 1.0f) + 6;
        if (act->targetCount == 1) {
            firstTarget = (u8 *)(act->target);
            if ((s32)(firstTarget) != (s32)(0)) {
                formationPkt58 = (BtlPacketTiming *)(btlFormationCreateWaitPacket((u32)act->unit, (u32)(*(u8 **)(firstTarget + 0x30)), 4));
                formationPkt58->queue = 4;
                formationPkt58->startTime = chainTime;
                formationPkt58->ownerId = actionId;
                btlPacketEnqueue((u8 *)formationPkt58, 0);
            }
        }
        cameraPkt59 = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x13));
        cameraPkt59->queue = 4;
        cameraPkt59->startTime = chainTime;
        cameraPkt59->ownerId = actionId;
        btlPacketEnqueue((u8 *)cameraPkt59, 0);
        btlState10_410 = (u8 *)(iGpffffb3ac);
        *(s32 *)(btlState10_410 + 0xC) = (s32) (*(s32 *)(btlState10_410 + 0xC) | 0x400000);
        btlState11_311 = (u8 *)(iGpffffb3ac);
        *(u16 *)(btlState11_311 + 0x18) = (u16) (*(u16 *)(btlState11_311 + 0x18) | 0xF);
    }
    skillKey = (s16)skill;
    btlMainSkillColorPairDefaults(skillKey, &cameraFirst, &cameraSecond);
    cameraPkt60 = (BtlPacketTiming *)(btlMainCreateColorLerpPacket(cameraFirst, cameraSecond, 0x10));
    cameraPkt60->queue = 4;
    cameraPkt60->startTime = sceneTime;
    cameraPkt60->ownerId = actionId;
    btlPacketEnqueue((u8 *)cameraPkt60, 1);
    cameraKind = (s32)(btlMainSkillColorDefault(skillKey));
    btlMainSkillColorPairDefaultsAlt(skillKey, &cameraFirst, &cameraSecond);
    cameraPkt61 = (BtlPacketTiming *)(btlMainCreateColorWorkPacket(cameraKind, cameraFirst, cameraSecond, 0x10, ((*(u16 *)((u8 *)(skillFlagsOffset + (s32)iGpffffb3bc) + 2) & 2) ? 1 : 0)));
    cameraPkt61->queue = 4;
    cameraPkt61->startTime = sceneTime;
    cameraPkt61->ownerId = actionId;
    btlPacketEnqueue((u8 *)cameraPkt61, 1);
    cameraPkt62 = (BtlPacketTiming *)(btlMainCreateTintPacket(btlMainSkillTintDefault((u16) skill), 0x10));
    cameraPkt62->queue = 4;
    cameraPkt62->startTime = sceneTime;
    cameraPkt62->ownerId = actionId;
    btlPacketEnqueue((u8 *)cameraPkt62, 1);
    cameraPkt63 = (BtlPacketTiming *)(btlMainCreateUnitTintPacket((BtlAction *)arg0, (u16) skill, 8));
    cameraPkt63->queue = 4;
    cameraPkt63->startTime = sceneTime;
    cameraPkt63->ownerId = actionId;
    btlPacketEnqueue((u8 *)cameraPkt63, 1);
    if (hasFollowAction != 0) {
        followActionPtr = (u8 *)(act->followAction);
        firstTargetEntry = (u8 *)(act->target);
        primaryTarget = (u8 *)(firstTargetEntry);
        sp4BC = (BtlPacketTiming *)(btlFormationCreateWaitPacket((u32)(*(u8 **)(followActionPtr + 0x30)), (u32)(*(u8 **)(firstTargetEntry + 0x30)), 2));
        sp4BC->queue = 4;
        sp4BC->startTime = chainTime;
        sp4BC->delay = timingFrames;
        sp4BC->duration = (s16) ((btlUnitMotionModelFrames((*( u8 ** )((u8 *)((s32 *)(u32)followActionPtr) + (0x30))), 0x1A, 1.0f)) - 1);
        sp4BC->ownerId = actionId;
        btlPacketEnqueue((u8 *)sp4BC, 0);
        cameraPkt66 = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x1E));
        cameraPkt66->queue = 4;
        cameraPkt66->startTime = chainTime;
        cameraPkt66->delay = timingFrames;
        cameraPkt66->ownerId = actionId;
        btlPacketEnqueue((u8 *)cameraPkt66, 0);
        pkt67 = (BtlPacketTiming *)(func_001f99c0((s32 *)(u32)followActionPtr, 0xD, 0U, 0, 0));
        pkt67->queue = 4;
        pkt67->startTime = chainTime;
        pkt67->delay = timingFrames;
        pkt67->ownerId = actionId;
        btlPacketEnqueue((u8 *)pkt67, 1);
        animPkt68 = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)*(u8 **)(followActionPtr + 0x30), 0x1A, 0, 1.0f, 0));
        animPkt68->queue = 4;
        animPkt68->startTime = chainTime;
        animPkt68->delay = timingFrames;
        animPkt68->ownerId = actionId;
        btlPacketEnqueue((u8 *)animPkt68, 0);
        animPkt69 = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)*(u8 **)(firstTargetEntry + 0x30), 0x1A, 0, 1.0f, 2));
        animPkt69->queue = 4;
        animPkt69->startTime = chainTime;
        animPkt69->delay = timingFrames;
        animPkt69->ownerId = actionId;
        btlPacketEnqueue((u8 *)animPkt69, 0);
        chainTime = sp4BC->endTime;
        timingFrames = 0;
        cameraPkt70 = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x1A));
        cameraPkt70->queue = 4;
        cameraPkt70->startTime = chainTime;
        cameraPkt70->delay = 0;
        cameraPkt70->ownerId = actionId;
        btlPacketEnqueue((u8 *)cameraPkt70, 0);
        formationPkt71 = (BtlPacketTiming *)(btlFormationCreateWaitPacket((u32)(*(u8 **)(followActionPtr + 0x30)), (u32)(*(u8 **)(firstTargetEntry + 0x30)), 3));
        formationPkt71->queue = 4;
        formationPkt71->startTime = chainTime;
        formationPkt71->delay = 0;
        formationPkt71->ownerId = actionId;
        btlPacketEnqueue((u8 *)formationPkt71, 0);
        rotatePkt72 = (BtlPacketTiming *)(btlUnitCreateRotateTowardUnitPacket(*(u8 **)(firstTargetEntry + 0x30), act->unit, 2));
        rotatePkt72->queue = 4;
        rotatePkt72->startTime = chainTime;
        rotatePkt72->delay = 0;
        rotatePkt72->ownerId = actionId;
        btlPacketEnqueue((u8 *)rotatePkt72, 1);
        animPkt73 = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)*(u8 **)(firstTargetEntry + 0x30), 0xA, 0, 1.0f, 1));
        animPkt73->queue = 4;
        animPkt73->startTime = chainTime;
        animPkt73->delay = 0;
        animPkt73->ownerId = actionId;
        btlPacketEnqueue((u8 *)animPkt73, 0);
        rotatePkt74 = (BtlPacketTiming *)(btlUnitCreateRotateTowardUnitPacket(*(u8 **)(followActionPtr + 0x30), act->unit, 2));
        rotatePkt74->queue = 4;
        rotatePkt74->startTime = chainTime;
        rotatePkt74->delay = 0;
        rotatePkt74->flags = (u8) (rotatePkt74->flags & 0xDF);
        rotatePkt74->ownerId = actionId;
        btlPacketEnqueue((u8 *)rotatePkt74, 1);
        btlState11_411 = (u8 *)(iGpffffb3ac);
        *(s32 *)(btlState11_411 + 0xC) = (s32) (*(s32 *)(btlState11_411 + 0xC) | 0x400000);
        btlState12 = (u8 *)(iGpffffb3ac);
        *(u16 *)(btlState12 + 0x18) = (u16) (*(u16 *)(btlState12 + 0x18) | 0xF);
    }
    btlFormationFormatName(skillKey, formation);
    if (hasCutin != 0) {
        waitPkt75 = (BtlPacketTiming *)(func_00194b60());
        waitPkt75->queue = 4;
        waitPkt75->startTime = chainTime;
        waitPkt75->delay = timingFrames;
        btlPacketEnqueue((u8 *)waitPkt75, 1);
        if (actionFlag4000 == 0) {
            formationNamePkt = (BtlPacketTiming *)(btlFormationCreateNamedPacket(formationHandle, formation, 1));
        } else {
            formationNamePkt = (BtlPacketTiming *)(func_00194b60());
        }
        formationNamePkt->queue = 5;
        formationNamePkt->startTime = cutinEndTime;
        (*( s8 * )((u8 *)formationNamePkt + (0x20))) = 5;
        *(s64 *)((u8 *)formationNamePkt + 0x28) = waitPkt75->endTime;
        formationNamePkt->ownerId = actionId;
        btlPacketEnqueue((u8 *)formationNamePkt, 1);
        if (actionFlag4000 == 0) {
            skillSePkt = (BtlPacketTiming *)(btlSoundCreateSkillSEPacket(skillKey, 1));
        } else {
            skillSePkt = (BtlPacketTiming *)(func_00194b60());
        }
        skillSePkt->queue = 5;
        skillSePkt->startTime = cutinEndTime;
        btlPacketEnqueue((u8 *)skillSePkt, 1);
    } else {
        if (actionFlag4000 == 0) {
            formationNamePkt = (BtlPacketTiming *)(btlFormationCreateNamedPacket(formationHandle, formation, 0));
        } else {
            formationNamePkt = (BtlPacketTiming *)(func_00194b60());
        }
        formationNamePkt->queue = 4;
        formationNamePkt->startTime = chainTime;
        formationNamePkt->delay = timingFrames;
        formationNamePkt->ownerId = actionId;
        btlPacketEnqueue((u8 *)formationNamePkt, 1);
        if (actionFlag4000 == 0) {
            skillSePkt = (BtlPacketTiming *)(btlSoundCreateSkillSEPacket(skillKey, 0));
        } else {
            skillSePkt = (BtlPacketTiming *)(func_00194b60());
        }
        skillSePkt->queue = 4;
        skillSePkt->startTime = formationNamePkt->endTime;
        btlPacketEnqueue((u8 *)skillSePkt, 1);
    }
    primaryTarget = (act->targetCount == 1) ? ((hasFollowAction != 0) ? (u8 *)(act->followAction) : primaryTarget) : (u8 *)(arg0);
    formationPkt76 = (BtlPacketTiming *)(btlFormationCreatePacket(formationHandle, *(u32 *)(arg0 + 0x30), *(u32 *)(primaryTarget + 0x30), 0, 0));
    formationPkt6 = (BtlPacketTiming *)(formationPkt76);
    formationPkt76->queue = 4;
    formationPkt76->startTime = formationNamePkt->endTime;
    (*( s8 * )((u8 *)formationPkt76 + (0x10))) = 4;
    *(s64 *)((u8 *)formationPkt76 + 0x18) = skillSePkt->endTime;
    if ((*( u16 * )((u8 *)(skillFlagsOffset + (s32)iGpffffb3bc) + (2))) & 0x80) {
        formationPkt6->ownerId = actionId;
    }
    btlPacketEnqueue((u8 *)formationPkt6, 2);
    formationEndTime2 = formationPkt6->endTime;
    if (actionFlag4000 == 0) {
        pkt77 = (BtlPacketTiming *)(btlSoundCreateCueQueuePacket(0));
        pkt77->queue = 5;
        pkt77->startTime = formationPkt6->endTime;
        btlPacketEnqueue((u8 *)pkt77, 1);
    }
    followCameraPkt = 0;
    cameraState = 0x18;
    hitTimeTotal = 0;
    if (actionFlag4000 != 0) {
        hitDelayBase = 4;
    } else {
        hitDelayBase = (s32)((u16)btlUnitSlotValueOrOne(skillKey));
    }
    hitDelta = (u16)hitDelayBase;
    hitWait = 0;
    targetIndex = 0;
    skillS32 = (s32)(u32)skill;
    skillKeyCopy = skillKey;
    while ((targetIndexS32 = (s32)targetIndex) < act->targetCount) {
            /* Per-target signed index, bound once like an inlined helper parameter; retail keeps targetIndexS32 as a word. */
            s32 targetPos = targetIndexS32;
            targetAction = (u8 *)((*( s32 ** )((u8 *)(((s32)(arg0) + ((u32)targetIndex * 4))) + (0x38))));
            rowHitCount = (u16) *(u8 *)(targetAction + 0xD9);
            hitTimer = 0;
            hitFlags = (s32)(s32)(btlFormationGetFlags((s32)(targetAction) + 0xD8));
            if (hasFollowAction != 0) {
                effectiveAction = (u8 *)(act->followAction);
            } else if (*(s32 *)(targetAction + 0xE4) != 0) {
                effectiveAction = (u8 *)(arg0);
            } else {
                effectiveAction = (u8 *)(targetAction);
            }
            targetHitValue = (s32)(*(s32 *)(targetAction + 0xE0));
            if ((targetHitValue != 0) && ((s32)((*( u8 * )((u8 *)(act->unit) + (0xA2)))) != (s32)((*( u8 * )((u8 *)(*(u8 **)(effectiveAction + 0x30)) + (0xA2)))))) {
                crossSideHits += 1;
            }
            if ((*( s32 * )((u8 *)(((s32)(targetAction) + ((u32)rowHitCount << 5))) + (0xD8))) & 0x100000) {
                statusHits += 1;
                statusMask |= *(u16 *)(targetAction + 0xDE);
            }
            targetUnit12 = (u8 *)(*(u8 **)(effectiveAction + 0x30));
            hitSide = (u8)(*(u8 *)(targetUnit12 + 0xA2));
            sameSideTarget = (hitSide == 1) ? ((*(s16 *)((u8 *)iGpffffb3cc + *(u16 *)(targetUnit12 + 0xA4) * 0xE8 + 0x18) & 0x40) != 0) ^ 1 : 1;
            if ((targetHitValue != 0) || (*(s32 *)(targetAction + 0xE4) != 0)) {
                cameraState = 0x1E;
            }
            pkt79 = (BtlPacketTiming *)(btlPacketCreateHpRatio(targetUnit12));
            pkt79->ownerId = actionId;
            btlPacketEnqueue((u8 *)pkt79, 1);
            if ((*(u16 *)(targetAction + 0xDC) != 0x400) && (*(s32 *)(targetAction + 0xE4) != 1)) {
                formationPkt6 = (BtlPacketTiming *)(btlFormationCreatePacket(formationHandle, *(u32 *)(arg0 + 0x30), *(u32 *)(effectiveAction + 0x30), 1, hitFlags | 0x1000));
                if ((s32)(followCameraPkt) == (s32)(0)) {
                    if (!((*( u16 * )((u8 *)(skillFlagsOffset + (s32)iGpffffb3bc) + (2))) & 0x2000)) {
                        formationPkt6->queue = 4;
                        formationPkt6->startTime = formationNamePkt->endTime;
                        (*( s8 * )((u8 *)formationPkt6 + (0x10))) = 4;
                        *(s64 *)((u8 *)formationPkt6 + 0x18) = skillSePkt->endTime;
                    } else {
                        formationPkt6->queue = 4;
                        formationPkt6->startTime = formationEndTime2;
                    }
                    (*( u16 * )((u8 *)formationPkt6 + (0x48))) = hitTimeTotal;
                } else {
                    formationPkt6->queue = 4;
                    formationPkt6->startTime = *(s64 *)((u8 *)followCameraPkt + 0x58);
                }
                if ((*( u16 * )((u8 *)(skillFlagsOffset + (s32)iGpffffb3bc) + (2))) & 0x80) {
                    formationPkt6->ownerId = actionId;
                }
                btlPacketEnqueue((u8 *)formationPkt6, 2);
                if (actionFlag4000 == 0) {
                    pkt80 = (BtlPacketTiming *)(btlSoundCreateCueQueuePacket(1));
                    pkt80->queue = 5;
                    pkt80->startTime = formationPkt6->endTime;
                    btlPacketEnqueue((u8 *)pkt80, 1);
                } else {
                    skillKindRow = (s16)datCalcSkillElement(NULL, skillKeyCopy);
                    switch (skillKindRow) {                /* switch 2; irregular */
                    case 16:                            /* switch 2 */
                        soundPkt9 = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xC, 2, 0x16));
                        break;
                    case 17:                            /* switch 2 */
                        soundPkt9 = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xC, 2, 0x19));
                        break;
                    default:                            /* switch 2 */
                        soundPkt9 = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xC, 2, 0x15));
                        break;
                    }
                    soundPkt9->queue = 5;
                    soundPkt9->startTime = formationPkt6->endTime;
                    btlPacketEnqueue((u8 *)soundPkt9, 1);
                }
            } else {
                formationPkt81 = (BtlPacketTiming *)(btlFormationCreatePacket(formationHandle, *(u32 *)(arg0 + 0x30), *(u32 *)(effectiveAction + 0x30), 1, hitFlags | 0xC00));
                formationPkt6 = (BtlPacketTiming *)(formationPkt81);
                formationPkt81->queue = 4;
                formationPkt81->startTime = formationNamePkt->endTime;
                (*( s8 * )((u8 *)formationPkt81 + (0x10))) = 4;
                *(s64 *)((u8 *)formationPkt81 + 0x18) = skillSePkt->endTime;
                (*( u16 * )((u8 *)formationPkt81 + (0x48))) = hitTimeTotal;
                if ((*( u16 * )((u8 *)(skillFlagsOffset + (s32)iGpffffb3bc) + (2))) & 0x80) {
                    formationPkt6->ownerId = actionId;
                }
                btlPacketEnqueue((u8 *)formationPkt6, 2);
                if ((*(u16 *)(targetAction + 0xDC) != 0x400) && (*(s32 *)(targetAction + 0xE4) == 1) && (targetPos == 0)) {
                    sp4C0 = (BtlPacketTiming *)(btlFormationCreatePacket(formationHandle, *(u32 *)(arg0 + 0x30), *(u32 *)(effectiveAction + 0x30), 1, hitFlags | 0x1000));
                    sp4C0->queue = 5;
                    sp4C0->startTime = formationPkt6->endTime;
                    if ((*(s32 *)(targetAction + 0xE4) != 0) && ((*( u16 * )((u8 *)(skillFlagsOffset + (s32)iGpffffb3bc) + (2))) & 8)) {
                        sp4C0->delay = 8;
                    }
                    sp4C0->ownerId = actionId;
                    btlPacketEnqueue((u8 *)sp4C0, 2);
                    if (actionFlag4000 == 0) {
                        pkt83 = (BtlPacketTiming *)(btlSoundCreateCueQueuePacket(1));
                        pkt83->queue = 5;
                        pkt83->startTime = sp4C0->endTime;
                        btlPacketEnqueue((u8 *)pkt83, 1);
                    }
                }
            }
            if (rotateFirst != 0) {
                if (bossCheck != 0) {
                    lookAtPkt84 = (BtlPacketTiming *)(actionLookAtUnit(0, *(u8 **)(effectiveAction + 0x30), 3));
                    lookAtPkt84->queue = 5;
                    lookAtPkt84->startTime = formationPkt6->endTime;
                    lookAtPkt84->ownerId = *(s64 *)arg0;
                    btlPacketEnqueue((u8 *)lookAtPkt84, 1);
                    if ((s32)(effectiveAction) != (s32)(arg0)) {
                        lookAtPkt85 = (BtlPacketTiming *)(actionLookAtUnit(*(u8 **)(effectiveAction + 0x30), act->unit, 0));
                        lookAtPkt85->queue = 5;
                        lookAtPkt85->startTime = formationPkt6->endTime;
                        lookAtPkt85->ownerId = *(s64 *)arg0;
                        btlPacketEnqueue((u8 *)lookAtPkt85, 1);
                    } else {
                        pkt86 = (BtlPacketTiming *)(btlUnitCreateLookAtDeactivatePacket(*(u8 **)(effectiveAction + 0x30), 0));
                        pkt86->queue = 5;
                        pkt86->startTime = formationPkt6->endTime;
                        pkt86->ownerId = *(s64 *)arg0;
                        btlPacketEnqueue((u8 *)pkt86, 1);
                    }
                    act->flags = (u16) (act->flags | 0x200);
                }
            } else if ((targetPos == 0) && (side == 0)) {
                targetGroup2 = (s32)((u16)btlTargetGetUnitIndex((BtlTarget *)(arg0 + 0x38)));
                if (targetGroup2 == 2) {
                    func_00196040(targetGroup2, 1, &targetPosition, 0, 0, 1);
                    pkt87 = (BtlPacketTiming *)(btlUnitCreateLookAtPacket(0, &targetPosition, 1));
                    pkt87->queue = 5;
                    pkt87->startTime = formationPkt6->endTime;
                    pkt87->ownerId = *(s64 *)arg0;
                    btlPacketEnqueue((u8 *)pkt87, 1);
                }
            }
            if (sp2D0 == 1) {
                if ((s32)(followCameraPkt) == (s32)(0)) {
                    if ((altCamera == 1) && (isKind3 == 0) && (noOverride == 0)) {
                        colorPkt88 = (BtlPacketTiming *)(func_0019bbe0((BtlUnit *)linkedUnit, 0, 0, 0, 4, 0));
                        colorPkt88->queue = 5;
                        colorPkt88->startTime = formationPkt6->endTime;
                        colorPkt88->ownerId = actionId;
                        btlPacketEnqueue((u8 *)colorPkt88, 0);
                    }
                    if (sp2C0 == 0) {
                        if (sp30C == 0) {
                            pkt10 = (BtlPacketTiming *)(btlUnitCreateMotionRequestPacket(act->unit, windupFrames));
                        } else {
                            /* Retail 001a9e5c/001ab480/001ab668 pass 1.0f in $f12. */
                            pkt10 = (BtlPacketTiming *)(btlUnitCreateMotionSpeedPacket((BtlUnit *)(*( u8 ** )(arg0 + 0x30)), 0, 1.0f, 0));
                        }
                        pkt10->queue = 5;
                        pkt10->startTime = formationPkt6->endTime;
                        pkt10->ownerId = actionId;
                        btlPacketEnqueue((u8 *)pkt10, 0);
                    }
                    colorPkt89 = (BtlPacketTiming *)(func_0019bbe0((BtlUnit *)act->unit, -1, 0, 0, 3, 0));
                    colorPkt89->queue = 5;
                    colorPkt89->startTime = formationPkt6->endTime;
                    colorPkt89->ownerId = actionId;
                    btlPacketEnqueue((u8 *)colorPkt89, 1);
                }
                if ((s32)(effectiveAction) != (s32)(arg0)) {
                    rotatePkt90 = (BtlPacketTiming *)(btlUnitCreateRotateTowardUnitPacket(*(u8 **)(effectiveAction + 0x30), act->unit, 2));
                    rotatePkt90->queue = 5;
                    rotatePkt90->startTime = formationPkt6->endTime;
                    rotatePkt90->ownerId = actionId;
                    btlPacketEnqueue((u8 *)rotatePkt90, 0);
                }
                pkt91 = (BtlPacketTiming *)(btlPacketCreateFinishEffect());
                pkt91->queue = 5;
                pkt91->startTime = formationPkt6->endTime;
                pkt91->ownerId = actionId;
                btlPacketEnqueue((u8 *)pkt91, 0);
                followCameraPkt = (BtlPacket *)(btlCameraCreateSetStatePacket((BtlAction *)effectiveAction, 0x1C));
                (*( s8 * )((u8 *)(followCameraPkt) + (0))) = 5;
                *(s64 *)((u8 *)followCameraPkt + 8) = formationPkt6->endTime;
                if (!((*( u16 * )((u8 *)(skillFlagsOffset + (s32)iGpffffb3bc) + (2))) & 0x80)) {
                    (*( s8 * )((u8 *)(followCameraPkt) + (0x20))) = 0xB;
                    *(s64 *)((u8 *)followCameraPkt + 0x28) = formationPkt6->endTime;
                    (*( s16 * )((u8 *)(followCameraPkt) + (0x4A))) = 0x12;
                } else {
                    (*( s8 * )((u8 *)(followCameraPkt) + (0x20))) = 4;
                    *(s64 *)((u8 *)followCameraPkt + 0x28) = formationPkt6->endTime;
                }
                (*( s64 * )((u8 *)(followCameraPkt) + (0x60))) = actionId;
                btlPacketEnqueue((u8 *)followCameraPkt, 0);
            }
            if (*(s32 *)(targetAction + 0xE4) != 0) {
                formationFxPkt = (BtlPacketTiming *)(btlFormationCreatePacket(*(u32 *)(iGpffffb3ac + 0xD28), *(u32 *)(arg0 + 0x30), *(u32 *)(targetAction + 0x30), 1, 0));
                if ((*( u16 * )((u8 *)(skillFlagsOffset + (s32)iGpffffb3bc) + (2))) & 4) {
                    formationFxPkt->queue = 0xB;
                    formationFxPkt->startTime = formationPkt6->endTime;
                } else {
                    formationFxPkt->queue = 5;
                    formationFxPkt->startTime = formationEndTime2;
                }
                btlPacketEnqueue((u8 *)formationFxPkt, 1);
                soundPkt93 = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xD, 2, 0xB));
                soundPkt93->queue = 5;
                soundPkt93->startTime = formationFxPkt->endTime;
                btlPacketEnqueue((u8 *)soundPkt93, 1);
            }
            if (*(u16 *)(targetAction + 0xDC) == 0x400) {
                formationFxPkt = (BtlPacketTiming *)(btlFormationCreatePacket(*(u32 *)(iGpffffb3ac + 0xD2C), *(u32 *)(arg0 + 0x30), *(u32 *)(effectiveAction + 0x30), 1, 0));
                if ((*( u16 * )((u8 *)(skillFlagsOffset + (s32)iGpffffb3bc) + (2))) & 4) {
                    formationFxPkt->queue = 0xB;
                    formationFxPkt->startTime = formationPkt6->endTime;
                } else {
                    formationFxPkt->queue = 5;
                    formationFxPkt->startTime = formationEndTime2;
                }
                btlPacketEnqueue((u8 *)formationFxPkt, 1);
                soundPkt94 = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xC, 2, 0xC));
                soundPkt94->queue = 5;
                soundPkt94->startTime = formationFxPkt->endTime;
                btlPacketEnqueue((u8 *)soundPkt94, 1);
                hitDelay = 0xA;
            }
            hitIndex = 0;
            while ((hitIndexS32 = (s32) hitIndex) < (s32)rowHitCount) {
                motionSpeed = 1.0f;
                                hitRow = (ActionHitRowView *)(targetAction + ((u32)hitIndex << 5));
                /* The two later predicates reload the signed byte after intervening calls. */
                hitMotion = &hitRow->result.motion;
                if (hitRow->result.motion == 9) {
                    motionFrames = (u16)btlUnitMotionFollowFrames(*(u8 **)((u8 *)effectiveAction + 0x30), 9, motionSpeed);
                    motionFramesCopy = motionFrames;
                    if (((s32) motionFramesCopy > 0) && ((s32) motionFramesCopy < 0xA)) {
                        motionFramesF = (f32) motionFramesCopy;
                        motionSpeed = motionFramesF / 10.0f;
                        motionFrames = 0xA;
                    }
                }
                animPkt98 = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)*(u8 **)(effectiveAction + 0x30), *hitMotion, 0, motionSpeed, 0));
                animPacket = (BtlPacketTiming *)(animPkt98);
                animPkt98->queue = 0xB;
                animPkt98->startTime = formationPkt6->endTime;
                (*( u16 * )((u8 *)animPkt98 + (0x48))) = hitTimer;
                if ((*(s32 *)(targetAction + 0xE4) != 0) && ((*( u16 * )((u8 *)(skillFlagsOffset + (s32)iGpffffb3bc) + (2))) & 8)) {
                    (*( u16 * )((u8 *)animPacket + (0x48))) = (u16) ((s16) (*( u16 * )((u8 *)animPacket + (0x48))) + 8);
                }
                animPacket->ownerId = actionId;
                btlPacketEnqueue((u8 *)animPacket, 0);
                if ((hitIndexS32 == (s32)rowHitCount - 1) && (hitRow->result.addedStatus & 0x100000) && (actionFlag4000 == 0) && (sameSideTarget == 1) && (*(s32 *)(targetAction + 0xE0) == 0) && (*hitMotion == 9) && ((s32)(func_0023df70(skillKeyCopy)) == (s32)(0))) {
                    motionFramesS32 = (s32) motionFrames;
                    if (motionFramesS32 >= 0x19) {
                        motionDelay = 0;
                    } else {
                        motionDelay = 0x19 - motionFramesS32;
                    }
                    pkt99 = (BtlPacketTiming *)(btlUnitCreateArcMovePacket(*(s32 *)(effectiveAction + 0x30), skill, (s16)motionDelay));
                    pkt99->queue = 4;
                    pkt99->startTime = animPacket->endTime;
                    pkt99->ownerId = actionId;
                    btlPacketEnqueue((u8 *)pkt99, 0);
                    if (act->targetCount == 1) {
                        skillKindUnit = (s16)datCalcSkillElement((u8 *)(u32)(*( s64 * )((u8 *)(act->unit) + (0xA64))), skillKeyCopy);
                        switch (skillKindUnit) {            /* switch 3; irregular */
                        case 1:                         /* switch 3 */
                            motionIdRaw = 0x29;
                            break;
                        case 2:                         /* switch 3 */
                            motionIdRaw = 0x2B;
                            break;
                        case 3:                         /* switch 3 */
                            motionIdRaw = 0x2A;
                            break;
                        case 4:                         /* switch 3 */
                            motionIdRaw = 0x2C;
                            break;
                        default:                        /* switch 3 */
                            motionIdRaw = -1;
                            break;
                        }
                        motionId = (s16)motionIdRaw;
                        if (motionId != -1) {
                            targetUnit2 = (u8 *)(*(u8 **)(effectiveAction + 0x30));
                            formationPkt100 = (BtlPacketTiming *)(btlFormationCreatePacket(*(u32 *)(iGpffffb3ac + motionId * 4 + 0xD04), (u32)targetUnit2, (u32)targetUnit2, 1, 0));
                            formationPkt100->queue = 4;
                            formationPkt100->startTime = animPacket->endTime;
                            formationPkt100->ownerId = actionId;
                            btlPacketEnqueue((u8 *)formationPkt100, 2);
                        }
                    }
                    if (motionFramesS32 > 0x19) {
                        pkt101 = (BtlPacketTiming *)(btlUnitCreateModelFramePacket((BtlUnit *)(*(u8 **)(effectiveAction + 0x30)), (s16)(motionFramesS32 - 0x19)));
                        pkt101->queue = 4;
                        pkt101->startTime = animPacket->endTime;
                        pkt101->ownerId = actionId;
                        btlPacketEnqueue((u8 *)pkt101, 0);
                    }
                    targetUnit3 = (u8 *)(*(u8 **)(effectiveAction + 0x30));
                    sp4B8 = (BtlPacketTiming *)(btlFormationCreatePacket(*(u32 *)(iGpffffb3ac + 0xD80), (u32)targetUnit3, (u32)targetUnit3, 1, 0));
                    sp4B8->queue = 4;
                    sp4B8->startTime = animPacket->endTime;
                    if (motionFramesS32 >= 0x19) {
                        motionFramesS32 = 0x19;
                    }
                    sp4B8->delay = (s16) motionFramesS32;
                    sp4B8->ownerId = actionId;
                    btlPacketEnqueue((u8 *)sp4B8, 2);
                    targetUnit103 = (u8 *)(*(u8 **)(effectiveAction + 0x30));
                    targetScale = *(f32 *)(targetUnit103 + 0x2C);
                    areaScale = ((*(f32 *)(targetUnit103 + 0x90) * targetScale * (*(f32 *)(targetUnit103 + 0x8C) * targetScale)) / (f32) 0x2710);
                    scaleLimit = 2.0f;
                    if (areaScale < scaleLimit) {
                        areaScale = scaleLimit;
                    } else {
                        scaleLimit = 5.0f;
                        if (!(areaScale <= scaleLimit)) {
                            areaScale = scaleLimit;
                        }
                    }
                    pkt104 = (BtlPacketTiming *)(func_001bccc0(0x12, (s16)(s32)((80.0f * areaScale) / 5.0f), 0, 6));
                    pkt104->queue = 5;
                    pkt104->startTime = sp4B8->endTime;
                    pkt104->ownerId = actionId;
                    btlPacketEnqueue((u8 *)pkt104, 1);
                    pkt105 = (BtlPacketTiming *)(btlUnitCreateMotionSettlePacket((BtlUnit *)(*(u8 **)(effectiveAction + 0x30))));
                    pkt105->queue = 5;
                    pkt105->startTime = animPacket->endTime;
                    pkt105->ownerId = actionId;
                    btlPacketEnqueue((u8 *)pkt105, 0);
                }
                if ((sp2D0 == 0) && ((*hitMotion != -1) || ((s32)((*( u8 * )((u8 *)(*(u8 **)(targetAction + 0x30)) + (0xA2)))) != (s32)((*( u8 * )((u8 *)(act->unit) + (0xA2)))))) && ((s32)(datCalcChkBadStatus((s32)(*( u8 ** )((u8 *)(*(u8 **)(targetAction + 0x30)) + (0xA64))), 0x180001)) == (s32)(0))) {
                    rotatePkt106 = (BtlPacketTiming *)(btlUnitCreateRotateTowardUnitPacket(*(u8 **)(targetAction + 0x30), act->unit, 2));
                    if ((*(s32 *)(targetAction + 0xE4) != 0) && ((s32)((u8 *)formationFxPkt) != (s32)(0))) {
                        rotatePkt106->queue = 5;
                        rotatePkt106->startTime = formationFxPkt->endTime;
                    } else {
                        rotatePkt106->queue = 5;
                        rotatePkt106->startTime = animPacket->endTime;
                    }
                    rotatePkt106->flags = (u8) (rotatePkt106->flags & 0xDF);
                    rotatePkt106->ownerId = actionId;
                    btlPacketEnqueue((u8 *)rotatePkt106, 1);
                }
                if (*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) {
                    pkt107 = (BtlPacketTiming *)(btlPacketAllocZeroed((void *)btlUnitApplyPacketEffects, (void *)arg0));
                    pkt107->queue = 5;
                    pkt107->startTime = animPacket->endTime;
                    pkt107->delay = hitDelay;
                    pkt107->ownerId = actionId;
                    btlPacketEnqueue((u8 *)pkt107, 1);
                }
                hitResult = (s32 *)&hitRow->result;
                hitResultPtr = (s32 *)(hitResult);
                pkt109 = (BtlPacketTiming *)(btlTargetCreateDataPacket((s32)(arg0), (s32)(effectiveAction), hitResult, *(u16 *)(targetAction + 0xDC), *(u16 *)(targetAction + 0xDE)));
                pkt109->queue = 5;
                pkt109->startTime = animPacket->endTime;
                pkt109->delay = hitDelay;
                pkt109->ownerId = actionId;
                btlPacketEnqueue((u8 *)pkt109, 1);
                pkt110 = (BtlPacketTiming *)(btlTargetCreateRecordPacket(targetAction));
                pkt110->queue = 5;
                pkt110->startTime = animPacket->endTime;
                pkt110->delay = hitDelay;
                pkt110->ownerId = actionId;
                btlPacketEnqueue((u8 *)pkt110, 1);
                if (((s32)(targetPos) == (s32)((act->targetCount - 1))) && (hitIndexS32 == (s32)((*(u8 *)(targetAction + 0xD9) - 1)))) {
                    pkt111 = (BtlPacketTiming *)(btlTargetCreateRecordPacket(arg0));
                    pkt111->queue = 5;
                    pkt111->startTime = animPacket->endTime;
                    pkt111->delay = hitDelay;
                    pkt111->ownerId = actionId;
                    btlPacketEnqueue((u8 *)pkt111, 1);
                }
                if ((targetPos == 0) && (hitIndexS32 == 0) && !(act->flags & 4)) {
                    pkt112 = (BtlPacketTiming *)(btlTargetCreateActionPacket(arg0, act->stateBits));
                    pkt112->queue = 5;
                    pkt112->startTime = animPacket->endTime;
                    pkt112->delay = hitDelay;
                    pkt112->ownerId = actionId;
                    btlPacketEnqueue((u8 *)pkt112, 1);
                }
                if (hitIndexS32 == (s32)((*(u8 *)(targetAction + 0xD9) - 1))) {
                    if ((act->fieldEC != 0) && !(act->fieldD8 & 1)) {
                        hitRowWord = (s32)((*( s32 * )((u8 *)(((s32)(arg0) + ((u32)hitIndex << 5))) + (0x104))));
                        if (hitRowWord != 0) {
                            btlPanelSetValueText((u8 *)(*(s32 *)(iGpffffb3ac + 0xC60)), func_0043c6a0(hitRowWord));
                        }
                        pkt113 = (BtlPacketTiming *)(btlPacketCreateEffectCounter(*(s32 *)(arg0 + 0x30), act->fieldEC));
                        pkt113->queue = 5;
                        pkt113->startTime = animPacket->endTime;
                        pkt113->flags = (u8) (pkt113->flags & 0xDF);
                        pkt113->ownerId = actionId;
                        btlPacketEnqueue((u8 *)pkt113, 3);
                    } else {
                        if (*(s16 *)(targetAction + 0xEC) != 0) {
                            hitField14 = hitRow->result.field14;
                            if (hitField14 != 0) {
                                btlPanelSetValueText((u8 *)(*(s32 *)(iGpffffb3ac + 0xC60)), func_0043c6a0(hitField14));
                            }
                            pkt114 = (BtlPacketTiming *)(btlPacketCreateEffectCounter(*(s32 *)(targetAction + 0x30), *(s16 *)(targetAction + 0xEC)));
                            pkt114->queue = 5;
                            pkt114->startTime = animPacket->endTime;
                            pkt114->flags = (u8) (pkt114->flags & 0xDF);
                            pkt114->ownerId = actionId;
                            btlPacketEnqueue((u8 *)pkt114, 3);
                        } else if (hasFollowAction != 0) {
                            targetFieldEC = (s16)(*(s16 *)(effectiveAction + 0xEC));
                            if (targetFieldEC != 0) {
                                pkt115 = (BtlPacketTiming *)(btlPacketCreateEffectCounter(*(s32 *)(effectiveAction + 0x30), targetFieldEC));
                                pkt115->queue = 5;
                                pkt115->startTime = animPacket->endTime;
                                pkt115->flags = (u8) (pkt115->flags & 0xDF);
                                pkt115->ownerId = actionId;
                                btlPacketEnqueue((u8 *)pkt115, 3);
                            }
                        }
                    }
                }
                if ((s32)(*hitResultPtr) != (s32)(0)) {
                    pkt116 = (BtlPacketTiming *)(btlPacketCreateUnitCounter((s32)(*(u8 **)(effectiveAction + 0x30)), 0, 0));
                    pkt116->queue = 5;
                    pkt116->startTime = animPacket->endTime;
                    pkt116->delay = hitDelay;
                    pkt116->flags = (u8) (pkt116->flags & 0xDF);
                    pkt116->ownerId = actionId;
                    btlPacketEnqueue((u8 *)pkt116, 3);
                }
                if ((hitRow->result.addedStatus & 0x100000) && ((s32)((*( u8 * )((u8 *)(*(u8 **)(effectiveAction + 0x30)) + (0xA2)))) == (s32)(1))) {
                    soundPkt117 = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xD, 2, 8));
                    soundPkt117->queue = 5;
                    soundPkt117->startTime = animPacket->endTime;
                    soundPkt117->delay = hitDelay;
                    soundPkt117->ownerId = actionId;
                    btlPacketEnqueue((u8 *)soundPkt117, 1);
                }
                if (*(u16 *)((u8 *)hitRow + 0x10E) & 0x20) {
                    sp310 = 1;
                    *(s16 *)(iGpffffb3ac + 0x1C) = 3;
                }
                if (*(u16 *)((u8 *)hitRow + 0x10E) & 0x40) {
                    sp2E0 = 1;
                }
                hitRowBase = btlHitRow_001a7720(targetAction, &hitIndex);
                hitPkt119 = (BtlPacketTiming *)(btlPacketCreateHitDisplay((s32)(act->unit), (s32)(*(u8 **)(effectiveAction + 0x30)), skillS32, *(u16 *)(targetAction + 0xDC), *(u16 *)(targetAction + 0xDE), hitIndex, rowHitCount, hitResultPtr, 0));
                hitPkt119->queue = 5;
                hitPkt119->startTime = animPacket->endTime;
                hitPkt119->delay = hitDelay;
                hitPkt119->flags = (u8) (hitPkt119->flags & 0xDF);
                hitPkt119->ownerId = actionId;
                btlPacketEnqueue((u8 *)hitPkt119, 3);
                hpTransfer = (s16 *)(hitRowBase + 0x108);
                if ((*(s16 *)(hitRowBase + 0x108) > 0) || (hitRow->result.spTransfer > 0)) {
                    hitDelayS16 = (s16)(hitDelay + 0x2B);
                    func_001f0a10((u8 *)&result);
                    spRow = btlHitResult_001a59a0(targetAction, &hitIndex);
                    result.hpDelta = *hpTransfer;
                    result.spDelta = (s32) *(s16 *)(spRow + 0x1A);
                    pkt120 = (BtlPacketTiming *)(btlTargetCreateDataPacket((s32)(arg0), (s32)(arg0), &result, 1U, 1U));
                    pkt120->queue = 4;
                    pkt120->startTime = animPacket->endTime;
                    pkt120->delay = hitDelayS16;
                    pkt120->ownerId = actionId;
                    btlPacketEnqueue((u8 *)pkt120, 1);
                    actUnit16 = (u8 *)(act->unit);
                    hitPkt121 = (BtlPacketTiming *)(btlPacketCreateHitDisplay((s32)(actUnit16), (s32)(actUnit16), -1, 1U, 1U, hitIndex, rowHitCount, &result, 0));
                    hitPkt121->queue = 4;
                    hitPkt121->startTime = animPacket->endTime;
                    hitPkt121->delay = hitDelayS16;
                    hitPkt121->ownerId = actionId;
                    btlPacketEnqueue((u8 *)hitPkt121, 3);
                    if (result.hpDelta != 0) {
                        if (hitIndexS32 == 0) {
                            pkt122 = (BtlPacketTiming *)(btlPacketCreateHpRatio(act->unit));
                            pkt122->ownerId = actionId;
                            btlPacketEnqueue((u8 *)pkt122, 1);
                        }
                        pkt123 = (BtlPacketTiming *)(btlPacketCreateUnitCounter((s32)(act->unit), 0, 0));
                        pkt123->queue = 4;
                        pkt123->startTime = animPacket->endTime;
                        pkt123->delay = hitDelayS16;
                        pkt123->ownerId = actionId;
                        btlPacketEnqueue((u8 *)pkt123, 3);
                    }
                }
                hitTimer += 7;
                hitIndex += 1;
            }
            if (hitWait < (s32) hitTimer) {
                hitWait = hitTimer;
            }
            hitTimeTotal += hitDelta;
            targetIndex += 1;
    }
    lateChainTime = animPacket->endTime;
    followSkill = (s16)(act->fieldEE);
    if (followSkill != -1) {
        pkt124 = (BtlPacketTiming *)(btlTargetCreateTargetPacket(arg0, (u16)followSkill, 0, 0, 0));
        pkt124->queue = 5;
        pkt124->startTime = lateChainTime;
        pkt124->delay = (s16) hitWait;
        pkt124->ownerId = actionId;
        btlPacketEnqueue((u8 *)pkt124, 1);
    } else if (crossSideHits > 0) {
        if (side == 0) {
            statusTotal = (s32)((u16)btlSideCountNotBad(2, 0x80000));
            if (*(u8 *)(arg0 + 0x28) <= 0 && *(u16 *)(act->unit + 0xA4) != 1 && datCalcRandomBelow(0x64U) < 0x32U) {
                if ((s32)((*( u8 * )((u8 *)(act->unit) + (0xA2)))) != (s32)(0)) {
                    chanceMiss = 0;
                } else {
                    btlState17 = (u8 *)(iGpffffb3ac);
                    if (*(s16 *)(btlState17 + 0xA70) != -1) {
                        statusRemaining = (s16)(statusTotal - crossSideHits);
                        if (statusRemaining <= 0) {
                            statusTotal2 = (u32)((u16)btlSideCountNotBad(2, 0x80000));
                            btlState18 = (u8 *)(iGpffffb3ac);
                            if (((u32)(*(s16 *)(btlState18 + 0xA72) >> 1) >= statusTotal2) && (lastActor = *(s16 *)(btlState18 + 0xA70), (lastActor != func_001d15a0()))) {
                                chanceMiss = 1;
                            } else {
                                goto block_406;
                            }
                        } else if ((*(s16 *)(btlState17 + 0xA72) >> 1) >= statusRemaining) {
                            chanceMiss = 1;
                        } else {
                            goto block_406;
                        }
                    } else {
block_406:
                        chanceMiss = 0;
                    }
                }
            } else {
                goto reactionPacket;
            }
            if (chanceMiss != 0) {
reactionPacket:
                pkt126 = (BtlPacketTiming *)(btlTargetCreateTargetPacket(arg0, 0x13, crossSideHits, 0, 0));
                pkt126->queue = 5;
                pkt126->startTime = lateChainTime;
                pkt126->delay = (s16) hitWait;
                pkt126->ownerId = actionId;
                btlPacketEnqueue((u8 *)pkt126, 1);
                        } else {
                pkt125 = (BtlPacketTiming *)(func_001f99c0(arg0, 0x10, crossSideHits, 0, 0));
                pkt125->queue = 5;
                pkt125->startTime = lateChainTime;
                pkt125->delay = (s16) hitWait;
                btlPacketEnqueue((u8 *)pkt125, 1);
            }
        }
    } else if ((statusHits > 0) && (stateBitsCopy = act->stateBits, ((stateBitsCopy & 1) != 0)) && !(stateBitsCopy & 2) && ((s64)((*( u8 * )((u8 *)(act->unit) + (0xA2)))) == (s64)(0))) {
        pkt127 = (BtlPacketTiming *)(btlTargetCreateTargetPacket(arg0, 0x18, (s32) statusMask, statusHits, 0));
        pkt127->queue = 5;
        pkt127->startTime = lateChainTime;
        pkt127->delay = (s16) hitWait;
        pkt127->ownerId = actionId;
        btlPacketEnqueue((u8 *)pkt127, 1);
    } else if ((rotateFirst != 0) && (side == 0) && (btlActionSameGenusTargetsHaveDelta(arg0) != 0) && (func_001f0d30(arg0) == 0)) {
        pkt128 = (BtlPacketTiming *)(func_001f99c0(act->target, 0x12, 0U, 0, 0));
        pkt128->queue = 5;
        pkt128->startTime = lateChainTime;
        pkt128->delay = (s16) hitWait;
        btlPacketEnqueue((u8 *)pkt128, 1);
    } else if (crossSideHits == 0) {
        if ((s32)(func_001f0dd0(arg0, 1)) != (s32)(0)) {
            pkt129 = (BtlPacketTiming *)(func_001f99c0(arg0, 0xF, 0U, 0, 0));
            pkt129->queue = 5;
            pkt129->startTime = lateChainTime;
            pkt129->delay = (s16) hitWait;
            btlPacketEnqueue((u8 *)pkt129, 1);
        } else if (((s32)(func_001f0f70(arg0)) == (s32)(1)) && ((s32)(btlActionAnyTargetSpecialHit(arg0)) == (s32)(0)) && (sp2E0 == 0)) {
            pkt130 = (BtlPacketTiming *)(func_001f99c0(arg0, 0x11, 0U, 0, 0));
            pkt130->queue = 5;
            pkt130->startTime = lateChainTime;
            pkt130->delay = (s16) hitWait;
            btlPacketEnqueue((u8 *)pkt130, 1);
        }
    }
    if (sp2E0 != 0) {
        if (sp2D0 == 1) {
            followCameraPkt = (BtlPacket *)(btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x1B));
            (*( s8 * )((u8 *)(followCameraPkt) + (0))) = 0xB;
            *(s64 *)((u8 *)followCameraPkt + 8) = formationPkt6->endTime;
            (*( s16 * )((u8 *)(followCameraPkt) + (0x48))) = 0x18;
            (*( s64 * )((u8 *)(followCameraPkt) + (0x60))) = actionId;
            btlPacketEnqueue((u8 *)followCameraPkt, 0);
        }
        if ((s32)((*( u8 * )((u8 *)(act->unit) + (0xA2)))) == (s32)(0)) {
            func_001f0a10((u8 *)&result);
            result.hpDelta = -((s32)(datCalcGetHp((*( s32 * )((u8 *)(act->unit) + (0xA64)))) & 0xFFFF) - 1);
            pkt4 = (BtlPacketTiming *)(btlTargetCreateDataPacket((s32)(arg0), (s32)(arg0), &result, 1U, 1U));
            if (sp2D0 == 1) {
                pkt4->queue = 4;
                pkt4->startTime = (s64)((s64) (*( s64 * )((u8 *)(followCameraPkt) + (0x58))));
            } else {
                pkt4->queue = 0xB;
                pkt4->startTime = (s64)((s64) formationPkt6->endTime);
            }
            pkt4->ownerId = actionId;
            btlPacketEnqueue((u8 *)pkt4, 1);
            actUnit19 = (u8 *)(act->unit);
            hitPkt132 = (BtlPacketTiming *)(btlPacketCreateHitDisplay((s32)(actUnit19), (s32)(actUnit19), -1, 0U, 0U, 0U, 1U, &result, 0));
            hitPkt132->queue = 4;
            hitPkt132->startTime = (s64)((s64) pkt4->endTime);
            hitPkt132->flags = (u8) (hitPkt132->flags & 0xDF);
            hitPkt132->ownerId = actionId;
            btlPacketEnqueue((u8 *)hitPkt132, 3);
            pkt133 = (BtlPacketTiming *)(btlPacketCreateUnitCounter((s32)(act->unit), 0, 0));
            pkt133->queue = 4;
            pkt133->startTime = (s64)((s64) pkt4->endTime);
            pkt133->flags = (u8) (pkt133->flags & 0xDF);
            pkt133->ownerId = actionId;
            btlPacketEnqueue((u8 *)pkt133, 3);
        } else {
            func_001f0a10((u8 *)&result);
            result.addedStatus = 0x80000;
            pkt4 = (BtlPacketTiming *)(btlTargetCreateDataPacket((s32)(arg0), (s32)(arg0), &result, 1U, 1U));
            if (sp2D0 == 1) {
                pkt4->queue = 4;
                pkt4->startTime = (s64)((s64) (*( s64 * )((u8 *)(followCameraPkt) + (0x58))));
            } else {
                pkt4->queue = 0xB;
                pkt4->startTime = (s64)((s64) formationPkt6->endTime);
            }
            pkt4->ownerId = actionId;
            btlPacketEnqueue((u8 *)pkt4, 1);
        }
        if (sp2C0 == 0) {
            if (sp2F0 == 0) {
                if (sp30C == 0) {
                    animPacket = (BtlPacketTiming *)(btlUnitCreateMotionRequestPacket(act->unit, windupFrames));
                } else {
                    animPacket = (BtlPacketTiming *)(btlUnitCreateMotionSpeedPacket((BtlUnit *)(*( u8 ** )(arg0 + 0x30)), 0, 1.0f, 0));
                }
                animPacket->queue = 4;
                animPacket->startTime = (s64)((s64) pkt4->endTime);
                animPacket->ownerId = actionId;
                btlPacketEnqueue((u8 *)animPacket, 0);
            } else {
                pkt134 = (BtlPacketTiming *)(btlUnitCreateMotionSettlePacket((BtlUnit *)act->unit));
                animPacket = (BtlPacketTiming *)(pkt134);
                pkt134->queue = 4;
                pkt134->startTime = (s64)((s64) pkt4->endTime);
                pkt134->ownerId = actionId;
                btlPacketEnqueue((u8 *)animPacket, 0);
            }
        }
        actUnit20_420 = (u8 *)(act->unit);
        if (*(s32 *)(actUnit20_420 + 0x9C) & 0x20) {
            waitPkt135 = (BtlPacketTiming *)(func_00194b60());
            waitPkt135->queue = 4;
            waitPkt135->startTime = (s64)((s64) pkt4->endTime);
            waitPkt135->duration = 0x3C;
            waitPkt135->ownerId = actionId;
            btlPacketEnqueue((u8 *)waitPkt135, 1);
        } else {
            colorPkt136 = (BtlPacketTiming *)(func_0019bbe0((BtlUnit *)actUnit20_420, 0xFFFFFF, 6, 0, 4, 0));
            colorPkt136->queue = 4;
            colorPkt136->startTime = (s64)((s64) pkt4->endTime);
            colorPkt136->ownerId = actionId;
            btlPacketEnqueue((u8 *)colorPkt136, 1);
            actUnit5_55 = (u8 *)(act->unit);
            formationPkt137 = (BtlPacketTiming *)(btlFormationCreatePacket(*(u32 *)(iGpffffb3ac + 0xD48), (u32)actUnit5_55, (u32)actUnit5_55, 0, 0));
            formationPkt137->queue = 4;
            formationPkt137->startTime = (s64)((s64) pkt4->endTime);
            formationPkt137->ownerId = actionId;
            btlPacketEnqueue((u8 *)formationPkt137, 2);
            soundPkt138 = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xA, 2, 0xA));
            soundPkt138->queue = 4;
            soundPkt138->startTime = (s64)((s64) pkt4->endTime);
            soundPkt138->ownerId = actionId;
            btlPacketEnqueue((u8 *)soundPkt138, 1);
            actUnit20_320 = (u8 *)(act->unit);
            *(u32 *)(actUnit20_320 + 0x9C) |= 0x100;
        }
    } else if (sp2C0 == 0) {
        if (sp2F0 == 0) {
            if (sp30C == 0) {
                animPacket = (BtlPacketTiming *)(btlUnitCreateMotionRequestPacket(act->unit, windupFrames));
            } else {
                animPacket = (BtlPacketTiming *)(btlUnitCreateMotionSpeedPacket((BtlUnit *)(*( u8 ** )(arg0 + 0x30)), 0, 1.0f, 0));
            }
            animPacket->queue = 0xB;
            animPacket->startTime = formationPkt6->endTime;
            if (side == 0) {
                animPacket->delay = cameraState;
            } else {
                animPacket->delay = 8;
                if (cameraState > 8) {
                    animDuration = cameraState - 8;
                } else {
                    animDuration = 0;
                }
                animPacket->duration = animDuration;
            }
            animPacket->ownerId = actionId;
            btlPacketEnqueue((u8 *)animPacket, 0);
        } else {
            pkt139 = (BtlPacketTiming *)(btlUnitCreateMotionSettlePacket((BtlUnit *)act->unit));
            animPacket = (BtlPacketTiming *)(pkt139);
            pkt139->queue = 0xB;
            pkt139->startTime = formationPkt6->endTime;
            pkt139->delay = cameraState;
            pkt139->ownerId = actionId;
            btlPacketEnqueue((u8 *)animPacket, 0);
        }
    }
    pkt140 = (BtlPacketTiming *)(btlCreateTimingPacket(0x10));
    pkt140->queue = 4;
    pkt140->startTime = animPacket->endTime;
    pkt140->flags = (u8) (pkt140->flags & 0xDF);
    pkt140->ownerId = actionId;
    btlPacketEnqueue((u8 *)pkt140, 1);
    if (sp310 != 0) {
        cameraMode = 2;
    } else {
        cameraMode = 0;
    }
    pkt141 = (BtlPacketTiming *)(btlMainCreateFadePacket(0x10, (u16)cameraMode));
    pkt141->queue = 4;
    pkt141->startTime = animPacket->endTime;
    pkt141->flags = (u8) (pkt141->flags & 0xDF);
    pkt141->ownerId = actionId;
    btlPacketEnqueue((u8 *)pkt141, 1);
    pkt142 = (BtlPacketTiming *)(btlMainCreateColorFadePacket(0x10));
    pkt142->queue = 4;
    pkt142->startTime = animPacket->endTime;
    pkt142->flags = (u8) (pkt142->flags & 0xDF);
    pkt142->ownerId = actionId;
    btlPacketEnqueue((u8 *)pkt142, 1);
    pkt143 = (BtlPacketTiming *)(btlMainCreateColorSetPacket(8));
    pkt143->queue = 4;
    pkt143->startTime = formationPkt6->endTime;
    pkt143->flags = (u8) (pkt143->flags & 0xDF);
    pkt143->ownerId = actionId;
    btlPacketEnqueue((u8 *)pkt143, 0);
    if ((altCamera == 1) && (isKind3 == 0) && (noOverride == 0)) {
        if (randomFlag == 0) {
            if (!((*( u16 * )((u8 *)(skillFlagsOffset + (s32)iGpffffb3bc) + (2))) & 0x40)) {
                if (side == 0) {
                    cameraStateA = 0x19;
                } else {
                    cameraStateA = 0x1A;
                }
                cameraPkt144 = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)arg0, (u16)cameraStateA));
                cameraPkt144->queue = 5;
                cameraPkt144->startTime = formationEndTime;
                cameraPkt144->ownerId = actionId;
                btlPacketEnqueue((u8 *)cameraPkt144, 0);
            }
        } else {
            cameraPkt145 = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x1D));
            cameraPkt145->queue = 5;
            cameraPkt145->startTime = formationEndTime;
            cameraPkt145->ownerId = actionId;
            btlPacketEnqueue((u8 *)cameraPkt145, 0);
        }
        if (sp310 == 0) {
            colorPkt146 = (BtlPacketTiming *)(func_0019bbe0((BtlUnit *)act->unit, -1, 0, 0xC, 3, 0));
            colorPkt146->queue = 0xB;
            colorPkt146->startTime = formationPkt6->endTime;
            colorPkt146->ownerId = actionId;
            btlPacketEnqueue((u8 *)colorPkt146, 1);
        }
        colorPkt147 = (BtlPacketTiming *)(func_0019bbe0((BtlUnit *)linkedUnit, 0xFFFFFF, 8, 0, 4, 0));
        colorPkt147->queue = 0xB;
        colorPkt147->startTime = formationPkt6->endTime;
        colorDelay = (rotateFirst != 0 && skillSpecial != 0) ? 7 : 0xF;
        colorPkt147->delay = colorDelay;
        colorPkt147->ownerId = actionId;
        btlPacketEnqueue((u8 *)colorPkt147, 1);
        effectPkt148 = (BtlPacketTiming *)(func_001d65d0(*(s32 *)(iGpffffb3ac + 0xD70), (s32)linkedUnit, damageFrames, 0, 0x2100));
        effectPkt148->queue = 4;
        effectPkt148->startTime = animEndTime;
        effectPkt148->ownerId = actionId;
        btlPacketEnqueue((u8 *)effectPkt148, 2);
    }
    if (sp310 == 1) {
        pkt149 = (BtlPacketTiming *)(btlCreateSetFlagsPacket(0x80));
        pkt149->queue = 4;
        pkt149->startTime = formationPkt6->endTime;
        pkt149->delay = 0xC;
        pkt149->ownerId = actionId;
        btlPacketEnqueue((u8 *)pkt149, 1);
        pkt150 = (BtlPacketTiming *)(btlPacketCreateEndSequence());
        pkt150->queue = 4;
        pkt150->startTime = animPacket->endTime;
        pkt150->flags = (u8) (pkt150->flags & 0xDF);
        pkt150->ownerId = actionId;
        btlPacketEnqueue((u8 *)pkt150, 1);
    }
    if (actionFlag4000 == 0) {
        btlFormationSetPlacement(formationHandle);
    }
    if (hasCutinPartner != 0) {
        u8 *partner = act->cutinPartner;

        cutin.mode = 3;
        cutin.unitId = *(u16 *)(*(u8 **)(partner + 0x30) + 0xA4);
        btlPacketEnqueue((u8 *)(func_001fa720((u8 *)&cutin)), 1);
    }
    if ((s32)(func_001f68e0(arg0)) != (s32)(0)) {
        btlActionSetState((BtlAction *)arg0, 0x1B);
        return;
    }
    {
        u16 state;

        switch (act->kind) {
        case 1:
        case 3:
        case 2:
            state = 0x20;
            break;
        default:
            state = 0x20;
            break;
        }
        btlActionSetState((BtlAction *)arg0, state);
    }
}

#pragma pop
// FUN_001ABBA0
void btlActionSummonInit(void)
{
}

/* Measured 2026-09-28: 2384/2384 bytes, resolved code/data references and
 * all 70 sibling functions unchanged. Packed colors, the halfword skill
 * selector, and packet/ID lifetimes retain the 0x170 frame. The formation
 * filename is a 128-byte string; encounter insertion returns DatUnit*. */
// FUN_001ABBB0
#pragma push
/* measured: func_001abbb0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
void btlActionSummonUpdate(s64 *arg0)
{
    typedef struct DatUnit DatUnit;
    typedef struct DatUnitEc DatUnitEc;
    extern s32 btlFormationAllocWork(u32 arg0);
    extern void btlFormationSetPlacement(u32 arg0);
    extern BtlPacket *btlEffectCreateSpriteFramePacket(u32 arg0, u16 arg1);
    extern u8 *btlTargetCreateHitPacket(u8 *arg0);
    extern void btlMainSkillColorPairDefaults(u32 arg0, s32 *arg1, s32 *arg2);
    extern s32 btlMainSkillColorDefault(s32 arg0);
    extern s32 btlMainSkillTintDefault(s32 arg0);
    extern void btlMainSkillColorPairDefaultsAlt(u32 arg0, s32 *arg1, s32 *arg2);
    extern BtlPacket *btlMainCreateColorLerpPacket(u32 arg0, u32 arg1, u32 arg2);
    extern BtlPacket *btlMainCreateColorWorkPacket(s32 first, s32 second, s32 third, u32 frames, u16 mode);
    extern BtlPacket *btlMainCreateTintPacket(u32 arg0, u32 arg1);
    extern BtlPacket *btlSoundCreateSkillSEPacket(u16 arg0, u16 arg1);
    extern u8 *func_00194b60(void);
    extern u8 *btlActionCreateWork(s32 arg0, u16 arg1, u16 *arg2);
    extern void btlUnitInitFromRecord(u8 *arg0, s32 arg1);
    extern u8 *btlUnitCreateModelLoadPacket(u8 *arg0, u16 arg1, s16 arg2);
    extern BtlPacket *btlUnitCreateResourceLoadPacket(BtlUnit *arg0, u16 arg1, u16 arg2);
    extern BtlPacket *btlCreateTimingPacket(u32 arg0);
    extern BtlPacket *btlMainCreateFadePacket(s32 arg0, s16 arg1);
    extern BtlPacket *btlMainCreateColorFadePacket(s32 arg0);
    extern s32 func_001f68e0(u8 *arg0);
    extern DatUnit *datUnitAddEncounterUnit(DatUnitEc *encounter, u16 id);
    extern u8 *iGpffffb3bc;
    typedef struct UnitView {
        u8 unknown00[4];
        RwV3d pos;
        u8 unknown10[0x94 - 0x10];
        s16 value94;
        s16 value96;
        u8 unknown98[0xA64 - 0x98];
        DatUnit *data;
    } UnitView;
    /* Unit APIs consume pointers; formation APIs consume their EE word representation. */
    typedef union UnitReference {
        UnitView *pointer;
        u32 address;
        s32 signedAddress;
    } UnitReference;
    typedef struct ActionView {
        s64 uid;
        u8 unknown08[0x28];
        UnitReference unitRef;
        u8 unknown34[0x38];
        u16 mode;
        s16 aux;
        u8 unknown70[6];
        u16 ids[3];
    } ActionView;
    s32 outHi;
    s32 outLo;
    char workBuf[128];
    s32 firstDone;
    s32 off;
    ActionView *action;
    s64 uid;
    s16 auxRaw;
    u8 *seqPkt;
    s64 evId;
    u16 selector;
    u32 aux;
    s32 handle;
    u8 *evPkt;
    UnitView *unit;
    s64 seqId;
    s32 scaleTmp;
    u8 *holdPkt;
    u8 *tailPkt;
    u32 idx;

    action = (ActionView *)arg0;
    auxRaw = action->aux;
    uid = action->uid;
    btlActionFinishPresentation((BtlAction *)arg0);
    handle = btlFormationAllocWork(1);
    selector = (u16)auxRaw;
    aux = selector;
    {
        u8 *pkt;
        pkt = (u8 *)btlEffectCreateSpriteFramePacket((u32)action->unitRef.pointer, selector);
        *(s64 *)(pkt + 0x60) = uid;
        btlPacketEnqueue(pkt, 3);
    }
    {
        u8 *pkt;
        pkt = btlTargetCreateHitPacket((u8 *)action);
        *(s64 *)(pkt + 0x60) = uid;
        btlPacketEnqueue(pkt, 1);
    }
    {
        u8 *pkt;
        pkt = btlTargetCreateActionPacket((u8 *)action, 0);
        *(s64 *)(pkt + 0x60) = uid;
        btlPacketEnqueue(pkt, 1);
    }
    evPkt = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)action->unitRef.pointer, 8, 6, 1.0f, 0);
    *(s64 *)(evPkt + 0x60) = uid;
    btlPacketEnqueue(evPkt, 0);
    {
        u8 *pkt;
        pkt = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x15);
        *pkt = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(evPkt + 0x58);
        *(s64 *)(pkt + 0x60) = uid;
        btlPacketEnqueue(pkt, 0);
    }
    evId = *(s64 *)(evPkt + 0x58);
    scaleTmp = btlUnitMotionFrames((u8 *)action->unitRef.pointer, 8, 1.0f);
    btlMainSkillColorPairDefaults(aux, &outHi, &outLo);
    {
        u8 *pkt;
        pkt = (u8 *)btlMainCreateColorLerpPacket((u32)outHi, (u32)outLo, 0x10);
        *pkt = 4;
        *(s64 *)(pkt + 8) = evId;
        *(s64 *)(pkt + 0x60) = uid;
        btlPacketEnqueue(pkt, 1);
    }
    {
        s32 kind;
        u8 *pkt;
        kind = btlMainSkillColorDefault(aux);
        btlMainSkillColorPairDefaultsAlt(aux, &outHi, &outLo);
        pkt = (u8 *)btlMainCreateColorWorkPacket(kind, outHi, outLo, 0x10, 0);
        *pkt = 4;
        *(s64 *)(pkt + 8) = evId;
        *(s64 *)(pkt + 0x60) = uid;
        btlPacketEnqueue(pkt, 1);
    }
    {
        u8 *pkt;
        pkt = (u8 *)btlMainCreateTintPacket(btlMainSkillTintDefault(aux), 0x10);
        *pkt = 4;
        *(s64 *)(pkt + 8) = evId;
        *(s64 *)(pkt + 0x60) = uid;
        btlPacketEnqueue(pkt, 1);
    }
    {
        u8 *pkt;
        pkt = (u8 *)btlMainCreateUnitTintPacket((BtlAction *)action, aux, 0x10);
        *pkt = 4;
        *(s64 *)(pkt + 8) = evId;
        *(s64 *)(pkt + 0x60) = uid;
        btlPacketEnqueue(pkt, 1);
    }
    btlFormationFormatName(aux, workBuf);
    seqPkt = (u8 *)btlFormationCreateNamedPacket(handle, workBuf, 0);
    *seqPkt = 4;
    *(s64 *)(seqPkt + 8) = 0;
    *(s16 *)(seqPkt + 0x48) = scaleTmp + 6;
    *(s64 *)(seqPkt + 0x60) = uid;
    btlPacketEnqueue(seqPkt, 1);
    holdPkt = (u8 *)btlSoundCreateSkillSEPacket(selector, 0);
    *holdPkt = 4;
    *(s64 *)(holdPkt + 8) = *(s64 *)(seqPkt + 0x58);
    btlPacketEnqueue(holdPkt, 1);
    {
        u8 *pkt;
        u8 *next;
        pkt = (u8 *)btlFormationCreatePacket(handle, action->unitRef.address, action->unitRef.address, 0, 0);
        *pkt = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(seqPkt + 0x58);
        *(pkt + 0x10) = 4;
        *(s64 *)(pkt + 0x18) = *(s64 *)(holdPkt + 0x58);
        btlPacketEnqueue(pkt, 2);
        next = (u8 *)btlSoundCreateCueQueuePacket(0);
        *next = 5;
        *(s64 *)(next + 8) = *(s64 *)(pkt + 0x58);
        btlPacketEnqueue(next, 1);
    }
    seqId = *(s64 *)(seqPkt + 0x58);
    tailPkt = func_00194b60();
    *tailPkt = 4;
    *(s64 *)(tailPkt + 8) = seqId;
    *(s16 *)(tailPkt + 0x48) = 0x18;
    *(s64 *)(tailPkt + 0x60) = uid;
    btlPacketEnqueue(tailPkt, 1);
    tailPkt = func_001d65d0(*(s32 *)(iGpffffb3ac + 0xD40), action->unitRef.signedAddress, 0, *(s64 *)(tailPkt + 0x58), 0x100);
    *tailPkt = 4;
    *(s64 *)(tailPkt + 8) = *(s64 *)(evPkt + 0x58);
    *(s64 *)(tailPkt + 0x60) = uid;
    btlPacketEnqueue(tailPkt, 1);
    {
        u8 *pkt;
        pkt = (u8 *)btlSoundCreateChannelCuePacket(10, 2, 7);
        *pkt = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(evPkt + 0x58);
        btlPacketEnqueue(pkt, 1);
    }
    firstDone = 0;
    idx = 0;
    off = (s32)auxRaw * 4;
    for (; (u16)idx < 3; idx = (u16)(idx + 1)) {
        u16 curId;
        u8 *loopPkt;
        curId = action->ids[(u16)idx];
        if (curId == 0) {
            break;
        }
        loopPkt = btlActionCreateWork(1, curId, NULL);
        unit = ((UnitReference *)(loopPkt + 0x30))->pointer;
        unit->data = datUnitAddEncounterUnit(*(DatUnitEc **)(iGpffffb3ac + 0xC68), curId);
        btlUnitInitFromRecord((u8 *)unit, curId & 0xFFFF);
        unit->value94 = action->unitRef.pointer->value94;
        unit->value96 = action->unitRef.pointer->value96;
        unit->pos = action->unitRef.pointer->pos;
        if (firstDone == 0) {
            {
                u8 *pkt;
                pkt = (u8 *)btlFormationCreateReturnPacket(0);
                *pkt = 4;
                *(s64 *)(pkt + 8) = seqId;
                *(s64 *)(pkt + 0x60) = uid;
                btlPacketEnqueue(pkt, 0);
            }
            {
                u8 *pkt;
                pkt = (u8 *)btlFormationCreateSlotPacket(1, 0xFFF);
                *pkt = 4;
                *(s64 *)(pkt + 8) = seqId;
                *(s64 *)(pkt + 0x60) = uid;
                btlPacketEnqueue(pkt, 0);
            }
            if ((*(u16 *)((u32)off + (u32)iGpffffb3bc + 2) & 0x40) == 0) {
                {
                    u8 *pkt;
                    pkt = (u8 *)btlEffectCreateReleasePacket(5);
                    *pkt = 4;
                    *(s64 *)(pkt + 8) = seqId;
                    *(s64 *)(pkt + 0x60) = uid;
                    btlPacketEnqueue(pkt, 0);
                }
                {
                    u8 *pkt;
                    pkt = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x2D);
                    *pkt = 4;
                    *(s64 *)(pkt + 8) = seqId;
                    *(s64 *)(pkt + 0x60) = uid;
                    btlPacketEnqueue(pkt, 0);
                }
            }
            firstDone = 1;
        }
        {
            u8 *q1;
            u8 *q2;
            u8 *q3;
            q1 = btlUnitCreateModelLoadPacket((u8 *)unit, curId, 0x7E);
            *q1 = 4;
            *(s64 *)(q1 + 8) = seqId;
            *(s64 *)(q1 + 0x60) = uid;
            btlPacketEnqueue(q1, 1);
            q2 = (u8 *)btlUnitCreateResourceLoadPacket((BtlUnit *)unit, curId, 0x10);
            *q2 = 4;
            *(s64 *)(q2 + 8) = *(s64 *)(q1 + 0x58);
            btlPacketEnqueue(q2, 1);
            q3 = (u8 *)btlFormationCreatePacket(handle, action->unitRef.address, ((UnitReference *)(loopPkt + 0x30))->address, 1, 0x100);
            *q3 = 4;
            *(s64 *)(q3 + 8) = *(s64 *)(q2 + 0x58);
            *(q3 + 0x10) = 4;
            *(s64 *)(q3 + 0x18) = *(s64 *)(holdPkt + 0x58);
            *(s64 *)(q3 + 0x60) = uid;
            btlPacketEnqueue(q3, 2);
            tailPkt = q3;
            {
                u8 *q4;
                q4 = (u8 *)btlSoundCreateCueQueuePacket(1);
                *q4 = 5;
                *(s64 *)(q4 + 8) = *(s64 *)(q3 + 0x58);
                btlPacketEnqueue(q4, 1);
            }
            if (((u16)idx == 0) && (action->ids[1] == 0)) {
                u8 *q5;
                q5 = (u8 *)btlPacketCreateEffectCounter(((UnitReference *)(loopPkt + 0x30))->signedAddress, 0x9F);
                *q5 = 5;
                *(s64 *)(q5 + 8) = *(s64 *)(q3 + 0x58);
                *(s16 *)(q5 + 0x48) = 0x1C;
                btlPacketEnqueue(q5, 3);
            }
            {
                u8 *q6;
                q6 = func_0019bbe0((u8 *)unit, -1, 0xC, 0, 3, 1);
                *q6 = 4;
                *(s64 *)(q6 + 8) = *(s64 *)(q2 + 0x58);
                *(q6 + 0x10) = 0xB;
                *(s64 *)(q6 + 0x18) = *(s64 *)(q3 + 0x58);
                *(s16 *)(q6 + 0x48) = 1;
                *(s64 *)(q6 + 0x60) = uid;
                btlPacketEnqueue(q6, 1);
            }
            seqId = *(s64 *)(q2 + 0x58);
        }
    }
    {
        u8 *pkt;
        pkt = (u8 *)actionTargetPacketBytes((u8 *)action, 9, 0, 0, 0);
        *pkt = 0xB;
        *(s64 *)(pkt + 8) = *(s64 *)(tailPkt + 0x58);
        btlPacketEnqueue(pkt, 1);
    }
    {
        u8 *pkt;
        pkt = (u8 *)btlCreateTimingPacket(0x10);
        *pkt = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(tailPkt + 0x58);
        *(pkt + 0x47) &= ~0x20;
        *(s64 *)(pkt + 0x60) = uid;
        btlPacketEnqueue(pkt, 1);
    }
    {
        u8 *pkt;
        pkt = (u8 *)btlMainCreateFadePacket(0x10, 0);
        *pkt = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(tailPkt + 0x58);
        *(pkt + 0x47) &= ~0x20;
        *(s64 *)(pkt + 0x60) = uid;
        btlPacketEnqueue(pkt, 1);
    }
    {
        u8 *pkt;
        pkt = (u8 *)btlMainCreateColorFadePacket(0x10);
        *pkt = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(tailPkt + 0x58);
        *(pkt + 0x47) &= ~0x20;
        *(s64 *)(pkt + 0x60) = uid;
        btlPacketEnqueue(pkt, 1);
    }
    {
        u8 *pkt;
        pkt = (u8 *)btlMainCreateColorSetPacket(8);
        *pkt = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(tailPkt + 0x58);
        *(pkt + 0x47) &= ~0x20;
        *(s64 *)(pkt + 0x60) = uid;
        btlPacketEnqueue(pkt, 0);
    }
    btlFormationSetPlacement(handle);
    if (func_001f68e0((u8 *)action) != 0) {
        btlActionSetState((BtlAction *)action, 0x1B);
    } else {
        u16 nextState;
        switch (action->mode) {
        case 1:
        case 3:
        case 2:
            nextState = 0x20;
            break;
        default:
            nextState = 0x20;
            break;
        }
        btlActionSetState((BtlAction *)action, nextState);
    }
}

#pragma pop
// FUN_001AC500
void btlActionAssistInit(BtlAction *action) {
    u8 *resetPacket;
    u8 *cameraPacket;

    btlActionFinishPresentation(action);
    func_001eb3b0((u8 *)action + 0x38);
    btlAICommandPickAiTarget(action, 0);
    btlActionFinishPresentation(action);
    resetPacket = (u8 *)btlFormationCreateSlotPacket(3, 0xFFF);
    *(s64 *)(resetPacket + 0x60) = *(s64 *)action;
    btlPacketEnqueue(resetPacket, 0);
    cameraPacket = (u8 *)btlCameraCreateSetStatePacket(action, 0x2C);
    *(s64 *)(cameraPacket + 0x60) = *(s64 *)action;
    btlPacketEnqueue(cameraPacket, 0);
    *(u16 *)((u8 *)action + 0x18) |= 2;
}

// FUN_001AC5B0
void btlActionAssistUpdate(BtlAction *action) {
    if ((btlCountUnitRecordsById(0x506) == 0) && (btlCountUnitRecordsById(0x800) == 0)) {
        *(u16 *)((u8 *)action + 0x18) = (u16) (*(u16 *)((u8 *)action + 0x18) | 0x100);
        btlActionSetState(action, 0xFU);
    }
}

// FUN_001AC620
void btlActionEventInit(void) {
    u8 *p = *(u8 **)(D_0076449C + 0x174);
    u8 *o;

    while (p != NULL) {
        if (func_001a05f0((BtlAction *)p) != 0) {
            o = (u8 *)btlUnitCreateModelReleasePacket(*(BtlUnit **)(*(u8 **)(p + 0x30) + 0xA0C));
            *(s64 *)(o + 0x60) = *(s64 *)p;
            btlPacketEnqueue(o, 1);
        }
        p = *(u8 **)(p + 0x450);
    }
}

// FUN_001AC6A0
void btlActionEventUpdate(BtlAction *action) {
    if ((*(s32 (**)(void))((u8 *)action + 0x440))() == 0) {
        btlActionSetState(action, *(u16 *)((u8 *)action + 0x43C));
    }
}

// FUN_001AC6F0
void btlActionErrorInit(void)
{
}

// FUN_001AC700
void btlActionErrorUpdate(u8 *action) {
    s64 packetIdentity;
    s32 alternateAction;
    s32 animationChoice;
    f32 speed;
    u16 actionKind;
    u8 *animationPacket;

    BtlPacket *btlEffectCreateSpriteFramePacket(u32 action, u16 arg1);
    BtlPacket *btlPacketCreateSpriteStep(u32 action, u16 arg1);
    BtlPacket *btlMainCreateFadePacket(s32 action, s16 mode);
    BtlPacket *btlCreateTimingPacket(u32 value);
    BtlPacket *btlMainCreateColorFadePacket(s32 action);


    struct {
        u16 resource;
        u16 animation;
        u16 frames;
        u16 cameraState;
    } selection;

    btlActionFinishPresentation((BtlAction *)action);
    alternateAction = (*(u16 *)(action + 0x6C) == 3);
    packetIdentity = *(s64 *)action;
    if (alternateAction == 0) {
        u8 *packet;
        packet = (u8 *)btlEffectCreateSpriteFramePacket(*(s32 *)(action + 0x30),
                               *(u16 *)(action + 0x6E));
        *(s64 *)(packet + 0x60) = packetIdentity;
        btlPacketEnqueue(packet, 3);
    } else {
        u8 *packet;
        packet = (u8 *)btlPacketCreateSpriteStep(*(s32 *)(action + 0x30),
                               *(u16 *)(action + 0x70));
        *(s64 *)(packet + 0x60) = packetIdentity;
        btlPacketEnqueue(packet, 3);
    }
    if ((*(u8 **)(action + 0x30))[0xA2] == 0) {
        if (alternateAction == 0) {
            selection.animation = (s64)0xD;
            selection.resource = (s64)0xB;
        } else {
            selection.animation = (s64)0x16;
            selection.resource = (s64)0x21;
        }
        selection.cameraState = 0x14;
        selection.frames = btlUnitMotionModelFrames(*(u8 **)(action + 0x30),
                               selection.animation, 1.0f);
        speed = 1.0f;
    } else {
        if (func_001f11e0(*(s16 *)(action + 0x6E)) != 0) {
            animationChoice = 4;
        } else {
            animationChoice = 8;
        }
        selection.animation = (u16)animationChoice;
        selection.resource = (s64)0xF;
        selection.cameraState = 0x15;
        if (*(u16 *)(action + 0x18) & 0x4000) {
            speed = 2.0f;
        } else {
            speed = 1.0f;
        }
        selection.frames = btlUnitMotionFrames(*(u8 **)(action + 0x30),
                               selection.animation, speed);
    }
    animationPacket = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(action + 0x30),
                                 (s16)selection.animation, 6, speed, 0);
    *(s64 *)(animationPacket + 0x60) = packetIdentity;
    *(s16 *)(animationPacket + 0x4A) = (s16)((selection.frames & 0xFFFF) + 6);
    btlPacketEnqueue(animationPacket, 0);
    {
        u8 *packet;
        packet = func_001d65d0(
            actionResourceAt((ActionResourcePrefix *)D_0076449C, (u16)selection.resource),
            *(s32 *)(action + 0x30), 0,
            *(s64 *)(animationPacket + 0x58), 0x100);
        *(s64 *)(packet + 0x60) = packetIdentity;
        btlPacketEnqueue(packet, 2);
    }
    {
        u8 *packet;
        packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, selection.cameraState);
        *(s64 *)(packet + 0x60) = packetIdentity;
        btlPacketEnqueue(packet, 0);
    }
    {
        u8 *packet;
        packet = (u8 *)actionMessagePacketBytes(*(s32 *)(action + 0x30),
                               *(s16 *)(action + 0xEC));
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
        *(s64 *)(packet + 0x60) = packetIdentity;
        btlPacketEnqueue(packet, 3);
    }
    {
        u8 *packet;
        packet = btlTargetCreateActionPacket(action, 0);
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
        *(s64 *)(packet + 0x60) = packetIdentity;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlCreateTimingPacket(0x10);
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
        *(u8 *)(packet + 0x47) &= ~0x20;
        *(s64 *)(packet + 0x60) = packetIdentity;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateFadePacket(0x10, 0);
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
        *(u8 *)(packet + 0x47) &= ~0x20;
        *(s64 *)(packet + 0x60) = packetIdentity;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateColorFadePacket(0x10);
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
        *(u8 *)(packet + 0x47) &= ~0x20;
        *(s64 *)(packet + 0x60) = packetIdentity;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateColorSetPacket(8);
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
        *(u8 *)(packet + 0x47) &= ~0x20;
        *(s64 *)(packet + 0x60) = packetIdentity;
        btlPacketEnqueue(packet, 0);
    }
    if (func_001f68e0(action) != 0) {
        btlActionSetState((BtlAction *)action, 0x1B);
        return;
    }
    actionKind = *(u16 *)(action + 0x6C);
    {
        u16 nextState;
        switch (actionKind) {
        case 1:
        case 3:
        case 2:
            nextState = 0x20;
            break;
        default:
            nextState = 0x20;
            break;
        }
        btlActionSetState((BtlAction *)action, nextState);
    }
}

// FUN_001ACB10
void btlActionEndureInit(u8 *arg0)
{
    u16 skillId;
    u8 *unitStatePtr;

    skillId = *(u16 *)(arg0 + 0x3F4);
    switch (skillId) {
    case 0x20F:
        unitStatePtr = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
        *(u16 *)unitStatePtr = *(u16 *)unitStatePtr | 0x400;
        break;
    case 0x210:
        unitStatePtr = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
        *(u16 *)unitStatePtr = *(u16 *)unitStatePtr | 0x800;
        break;
    }
    if (*(u16 *)(arg0 + 0x3F4) == 0) {
        unitStatePtr = *(u8 **)(arg0 + 0x30);
        *(s32 *)(unitStatePtr + 0x9C) = *(s32 *)(unitStatePtr + 0x9C) & ~0x10;
        btlActionSetState((BtlAction *)arg0, *(u16 *)(arg0 + 0x430));
    }
}

// FUN_001ACBB0
void btlActionEndureUpdate(u8 *arg0) {
    s32 damageResult[8];
    s32 value;
    s32 remainingCount;
    s32 prevFlags;
    s32 flagAdded;
    s64 secondPacketTag;
    s64 firstPacketTag;
    s64 messageIdVariant;
    s64 messageId;
    s64 messageIdDefault;
    u16 skillId;
    u8 *battleUnit;
    u8 *messagePacket;
    u8 *damagePacket;
    u8 *unitPacket;
    u8 *statusPacket;
    u8 *statPacket;
    u8 *removeFlagsPacket;

    s32 func_00106600(s16 id);
    u8 *btlCreateRemoveFlagsPacket(s32 arg0);
    u8 *func_00194b60(void);
    void func_001f0a10(u8 *arg0);
    extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
    extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);

    extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 kind, s16 value);
    void btlActionSetState(u8 *arg0, u16 arg1);
    u8 *btlPacketCreateHpRatio(u8 *arg0);
    u32 datCalcGetHp(u8 *arg0);
    u32 datCalcMaxHp(u8 *arg0);

    battleUnit = *(u8 **)((u8 *)arg0 + 0x30);
    *(s32 *)(battleUnit + 0x9C) &= ~0x10;
    if (btlCountUnitRecordsById(0xFF03) == 0) {
        prevFlags = *(s32 *)(D_0076449C + 0xC);
        if (!(prevFlags & 0x80000)) {
            *(s32 *)(D_0076449C + 0xC) = prevFlags | 0x80000;
            flagAdded = 1;
        } else {
            flagAdded = 0;
        }
        skillId = *(u16 *)(arg0 + 0x3F4);
        switch (skillId) {
        case 0x210:
            if (battleUnit[0xA2] == 0) {
                messageIdVariant = 0x3E;
            } else {
                messageIdVariant = 0x3F;
            }
            messageId = (s16)messageIdVariant;
            break;
        case 0x154:
            messageId = 0x9B;
            break;
        case 0x231:
            messageId = 0xB4;
            break;
        case 0x232:
            messageId = 0xB6;
            break;
        default:
            if (battleUnit[0xA2] == 0) {
                messageIdDefault = 0x3C;
            } else {
                messageIdDefault = 0x3D;
            }
            messageId = (s16)messageIdDefault;
            break;
        }
        value = (s16)messageId;
        messagePacket = actionMessagePacketBytes((s32)*(u8 **)(arg0 + 0x30),
                                 value);
        *(s16 *)(messagePacket + 0x48) = 8;
        *(s64 *)(messagePacket + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(messagePacket, 3);
        firstPacketTag = *(s64 *)(messagePacket + 0x58);
        messagePacket = func_00194b60();
        *(s16 *)(messagePacket + 0x48) = 8;
        *(s64 *)(messagePacket + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(messagePacket, 0);
        secondPacketTag = *(s64 *)(messagePacket + 0x58);
        if (*(u16 *)(arg0 + 0x3F4) == 0x154) {
            remainingCount = func_00106600(0x340) & 0xFF;
            if (remainingCount > 0) {
                func_00106620(0x340, (remainingCount - 1) & 0xFF);
            }
        }
        if (*(u16 *)(arg0 + 0x3F4) == 0x210) {
            func_001f0a10((u8 *)&damageResult);
            value = datCalcMaxHp(*(u8 **)(battleUnit + 0xA64)) & 0xFFFF;
            damageResult[0] = value - (datCalcGetHp(*(u8 **)(battleUnit + 0xA64)) & 0xFFFF);
            damagePacket = (u8 *)btlTargetCreateDataPacket((s32)arg0, (s32)arg0,
                                     &damageResult, 1, 1);
            *(s8 *)(damagePacket + 0) = 4;
            *(s64 *)(damagePacket + 8) = secondPacketTag;
            *(s64 *)(damagePacket + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(damagePacket, 1);
            unitPacket = btlPacketCreateHpRatio(battleUnit);
            *(s8 *)(unitPacket + 0) = 4;
            *(s64 *)(unitPacket + 8) = secondPacketTag;
            *(s64 *)(unitPacket + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(unitPacket, 1);
            statusPacket = btlPacketCreateHitDisplay((s32)battleUnit, (s32)battleUnit, -1, 0, 0,
                                     0, 1, (u8 *)&damageResult, 0);
            *(s8 *)(statusPacket + 0) = 4;
            *(s64 *)(statusPacket + 8) = secondPacketTag;
            *(s64 *)(statusPacket + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(statusPacket, 3);
            statPacket = btlPacketCreateUnitCounter((s32)battleUnit, 0, 0);
            *(s8 *)(statPacket + 0) = 4;
            *(s64 *)(statPacket + 8) = secondPacketTag;
            *(s64 *)(statPacket + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(statPacket, 3);
        }
        if (flagAdded != 0) {
            removeFlagsPacket = btlCreateRemoveFlagsPacket(0x80000);
            *(s8 *)(removeFlagsPacket + 0) = 4;
            *(s64 *)(removeFlagsPacket + 8) = firstPacketTag;
            *(s64 *)(removeFlagsPacket + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(removeFlagsPacket, 0);
        }
        btlActionSetState(arg0, *(u16 *)(arg0 + 0x430));
    }
}

// FUN_001ACF40
void btlActionWaitInit(void)
{
}

// FUN_001ACF50
u8 *func_00194b60(void);
s32 func_00198810(u8 *arg0);

void func_001f0a10(u8 *arg0);
extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
s32 func_001f68e0(u8 *arg0);

void btlActionWaitUpdate(u8 *arg0) {
    struct {
        s32 sp30;
        u8 pad[0x1A];
        u16 sp4E;
    } locals;
    u16 actionKind;
    u8 *packet;
    u8 *battleUnit;
    void btlActionFinishPresentation();
    u8 *recoveryPacket;

    switch (*(u16 *)(arg0 + 0x6C)) {
    case 7:
        btlActionFinishPresentation();
        packet = (u8 *)btlUnitCreateLookAtDeactivatePacket(0, 3);
        *(s64 *)(packet + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(packet, 0);
        if (*(s16 *)(arg0 + 0xEC) != 0) {
            packet = actionMessagePacketBytes(*(s32 *)(arg0 + 0x30), *(s16 *)(arg0 + 0xEC));
            *(s64 *)(packet + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(packet, 3);
        } else {
            battleUnit = *(u8 **)(arg0 + 0x30);
            if ((*(s32 *)(battleUnit + 0x9C) & 0x4000) != 0) {
                actionKind = *(u16 *)(arg0 + 0x6C);
            } else {
                actionKind = 8;
            }
            packet = btlPacketCreateSpriteTable((u32)battleUnit, actionKind & 0xFFFF);
            *(s64 *)(packet + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(packet, 3);
        }
        packet = func_001f99c0(arg0, 0x16, 0, 0, 0);
        *(s64 *)(packet + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(packet, 1);
        if ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x4000) != 0) {
            packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x32);
            *(s64 *)(packet + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(packet, 0);
            if ((s16)func_00198810(*(u8 **)(arg0 + 0x30)) != 0x11) {
                recoveryPacket = actionRecoveryPacketBytes((BtlUnit *)*(u8 **)(arg0 + 0x30));
                *(s64 *)(recoveryPacket + 0x60) = *(s64 *)arg0;
                btlPacketEnqueue(recoveryPacket, 0);
            } else {
                recoveryPacket = func_00194b60();
                *(s64 *)(recoveryPacket + 0x60) = *(s64 *)arg0;
                btlPacketEnqueue(recoveryPacket, 0);
            }
            func_001f0a10((u8 *)&locals.sp30);
            locals.sp4E |= 0x80;
            packet = (u8 *)btlTargetCreateDataPacket((s32)arg0, (s32)arg0, &locals.sp30, 1, 1);
            *(s8 *)(packet + 0) = 4;
            *(s64 *)(packet + 8) = *(s64 *)(recoveryPacket + 0x58);
            *(s64 *)(packet + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(packet, 1);
            packet = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)*(u8 **)(arg0 + 0x30), 0x18, 6, 1.0f, 1);
            *(s8 *)(packet + 0) = 4;
            *(s64 *)(packet + 8) = *(s64 *)(recoveryPacket + 0x58);
            *(s64 *)(packet + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(packet, 0);
        } else {
            packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 0xA);
            *(s64 *)(packet + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(packet, 0);
        }
        break;
    case 8:
    case 11:
        break;
    }
    btlPacketEnqueue(btlTargetCreateActionPacket(arg0, 0), 1);
    if ((func_001f68e0(arg0) != 0) && (*(u16 *)(arg0 + 0x6C) != 8)) {
        btlActionSetState((BtlAction *)arg0, 0x1B);
        return;
    }
    btlActionSetState((BtlAction *)arg0, 0x20);
}

// FUN_001AD280
void btlActionEscapeMesInit(u8 *arg0)
{
    s16 cutinParams[8];
    u8 *lookAtPacket;
    u8 *resetPacket;
    u8 *cameraPacket;
    u8 *cutinPacket;

    btlActionFinishPresentation((BtlAction *)arg0);
    lookAtPacket = actionLookAtUnit(
        *(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30),
        *(u8 **)(arg0 + 0x30),
        0);
    *(s64 *)(lookAtPacket + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(lookAtPacket, 1);
    lookAtPacket = actionLookAtUnit(
        *(u8 **)(arg0 + 0x30),
        *(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30),
        0);
    *(s64 *)(lookAtPacket + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(lookAtPacket, 1);
    *(u16 *)(arg0 + 0x18) |= 0x200;
    resetPacket = (u8 *)btlFormationCreateSlotPacket(3, 0xFFF);
    *(s64 *)(resetPacket + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(resetPacket, 0);
    cameraPacket = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 9);
    *(s64 *)(cameraPacket + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(cameraPacket, 0);
    cutinParams[0] = 5;
    cutinPacket = func_001fa720((u8 *)&cutinParams[0]);
    *(s64 *)(cutinPacket + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(cutinPacket, 1);
    if (func_001eb860() == 1) {
        *(s32 *)(D_0076449C + 0xC) &= ~0x2000;
        btlDamageSetSource(*(u8 **)(D_0076449C + 0xDD4), 0);
    }
    *(s32 *)(arg0 + 0x41C) = 0;
}

// FUN_001AD3E0
void btlActionEscapeMesUpdate(u8 *arg0)
{
    u8 *temp;

    if (*(s32 *)(arg0 + 0x41C) != 0) {
        goto common;
    }
    if (func_00193bf0(*(s64 *)arg0, 0x3FFFFFFFFFFFFFFFLL) != 0) {
        goto done;
    }
    btlMessageInstallWindow(*(s32 *)(D_0076449C + 0xDD4), arg0);
    temp = func_001fa8f0();
    *(s64 *)(temp + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(temp, 1);
    *(s32 *)(arg0 + 0x41C) = 1;
common:
    if (btlMessageIsActiveAlt2(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
        goto done;
    }
    if (func_001eb860() != 1) {
        goto after_flag;
    }
    *(s32 *)(D_0076449C + 0xC) |= 0x2000;
    btlDamageSetSource(*(u8 **)(D_0076449C + 0xDD4), 1);
after_flag:
    if (btlMessageGetResultAlt2(*(s32 *)(D_0076449C + 0xDD4)) != 0) {
        goto alternate;
    }
    btlActionSetState((BtlAction *)arg0, 0x1D);
    goto after_state;
alternate:
    btlActionSetState((BtlAction *)arg0, 0x20);
after_state:
    temp = func_001faa60();
    *(s64 *)(temp + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(temp, 1);
    btlMessageRelease(*(s32 *)(D_0076449C + 0xDD4));
done:
    return;
}

// FUN_001AD540
void btlActionEscapeInit(void)
{
}

// FUN_001AD550
/* measured: func_001ad550 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
void btlActionEscapeUpdate(s64 *arg0)
{
    typedef struct RtQuat { RwV3d imag; f32 real; } RtQuat;
    extern void btlUnitGetSphereWorldCenter(BtlUnit *arg0, RwV3d *arg1);
    extern RwV3d *RtQuatTransformVectors(RwV3d *out, const RwV3d *in, s32 count, const RtQuat *quat);
    extern BtlPacket *btlCreateSetFlagsPacket(u32 arg0);
    extern RwV3d D_0060A100;
    extern f32 fGpffff8218;
    typedef struct UnitView {
        u8 unknown00[0xA2];
        u8 kind;
        u8 unknownA3;
        u16 index;
        u8 unknownA6[0xA64 - 0xA6];
        s32 data;
    } UnitView;
    typedef struct ActionView {
        s64 uid;
        u8 unknown08[0x10];
        u16 flags18;
        u16 flags1A;
        u8 unknown1C[0x14];
        UnitView *unit;
        u8 unknown34[0x38];
        u16 mode;
        u8 unknown6E[0x450 - 0x6E];
        struct ActionView *next;
    } ActionView;
    ActionView *action;
    RwV3d outE0;
    RwV3d posD0;
    RwV3d vecC0;
    ActionView *collected[12];
    union {
        RtQuat rotation;
        f32 values[4];
    } quat80;
    u8 *first;
    u8 *stepPkt;
    ActionView *cur;
    ActionView *iter;
    s64 lastId;
    s32 listed;
    s32 spread;
    u16 count;
    u16 idx;

    action = (ActionView *)arg0;
    btlActionFinishPresentation((BtlAction *)arg0);
    first = btlPacketCreateSpriteTable((u32)action->unit, 6);
    *(s64 *)(first + 0x60) = action->uid;
    btlPacketEnqueue(first, 3);
    listed = 0;
    spread = 0;
    count = 0;
    lastId = 0;
    switch (action->unit->kind) {
    case 0:
        if (action->mode != 0xC) {
            *(u16 *)(iGpffffb3ac + 0xC5E) = *(u16 *)(iGpffffb3ac + 0xC5E) + 1;
            spread = 1;
            for (iter = *(ActionView **)(iGpffffb3ac + 0x174); iter != NULL; iter = iter->next) {
                if ((iter->flags1A & 1) != 0) {
                    if (iter->unit->kind == 0) {
                        if (datCalcIsDead(iter->unit->data, 0) == 0) {
                            if (datCalcChkBadStatus(iter->unit->data, 0x100001) == 0) {
                                collected[count] = iter;
                                count++;
                            }
                        }
                    }
                }
            }
            listed = 1;
        } else {
            collected[0] = action;
            count = 1;
            action->flags18 |= 0x20;
            action->flags1A &= 0xFFF7;
        }
        break;
    case 1:
        collected[0] = action;
        count = 1;
        action->flags18 |= 0x20;
        action->flags1A &= 0xFFF7;
        break;
    }
    if (listed == 0) {
        {
            u8 *pkt;
            pkt = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)collected[0], 0xA);
            *(s64 *)(pkt + 0x60) = action->uid;
            btlPacketEnqueue(pkt, 0);
        }
    }
    if (action->unit->kind == 0) {
        {
            u8 *pkt;
            pkt = (u8 *)btlSoundCreateCuePacket(0xF, 2, 0);
            *pkt = 5;
            *(s64 *)(pkt + 8) = *(s64 *)(first + 0x58);
            *(u16 *)(pkt + 0x48) = 0x1A;
            *(s64 *)(pkt + 0x60) = action->uid;
            btlPacketEnqueue(pkt, 1);
        }
        if (action->mode == 0xC) {
            {
                u8 *pkt;
                pkt = actionTargetPacketBytes((u8 *)action, 7, 0, 0, 0);
                *(s64 *)(pkt + 0x60) = action->uid;
                btlPacketEnqueue(pkt, 1);
            }
        } else if (spread == 1) {
            {
                u8 *pkt;
                pkt = btlPacketCreateEndSequence();
                *pkt = 5;
                *(s64 *)(pkt + 8) = *(s64 *)(first + 0x58);
                *(u16 *)(pkt + 0x48) = 0x10;
                *(s64 *)(pkt + 0x60) = action->uid;
                btlPacketEnqueue(pkt, 1);
            }
        }
    } else {
        {
            u8 *pkt;
            pkt = (u8 *)btlSoundCreateChannelCuePacket(0xC, 2, 0xF);
            *pkt = 5;
            *(s64 *)(pkt + 8) = *(s64 *)(first + 0x58);
            *(u16 *)(pkt + 0x48) = 0x16;
            *(s64 *)(pkt + 0x60) = action->uid;
            btlPacketEnqueue(pkt, 1);
        }
        {
            u8 *pkt;
            pkt = actionTargetPacketBytes((u8 *)action, 6, 0, 0, 0);
            *(u16 *)(pkt + 0x48) = 0xC;
            *(s64 *)(pkt + 0x60) = action->uid;
            btlPacketEnqueue(pkt, 1);
        }
    }
    for (idx = 0; idx < count; idx++) {
        cur = collected[idx];
        btlUnitGetSphereWorldCenter((BtlUnit *)cur->unit, &posD0);
        func_00194ff0((u8 *)cur->unit, NULL, quat80.values, NULL);
        RtQuatTransformVectors(&vecC0, &D_0060A100, 1, &quat80.rotation);
        if (action->unit->kind == 0) {
            vecC0.x = vecC0.x * 500.0f;
            vecC0.y = vecC0.y * 500.0f;
            vecC0.z = vecC0.z * 500.0f;
            outE0.x = posD0.x + vecC0.x;
            outE0.y = posD0.y + vecC0.y;
            outE0.z = posD0.z + vecC0.z;
            stepPkt = (u8 *)btlUnitCreateMovePacket((BtlUnit *)cur->unit, &outE0, 0.5f, 0);
        } else {
            if (*(s16 *)(iGpffffb3cc + (u32)cur->unit->index * 0xE8 + 0x22) != 1) {
                vecC0.x = vecC0.x * 129.6f;
                vecC0.y = vecC0.y * 129.6f;
                vecC0.z = vecC0.z * 129.6f;
                outE0.x = posD0.x + vecC0.x;
                outE0.y = posD0.y + vecC0.y;
                outE0.z = posD0.z + vecC0.z;
            } else {
                outE0 = posD0;
            }
            stepPkt = (u8 *)btlUnitCreateMovePacket((BtlUnit *)cur->unit, &outE0, fGpffff8218, 4);
        }
        *stepPkt = 5;
        *(s64 *)(stepPkt + 8) = *(s64 *)(first + 0x58);
        *(u16 *)(stepPkt + 0x48) = 0x10;
        *(s64 *)(stepPkt + 0x60) = action->uid;
        btlPacketEnqueue(stepPkt, 1);
        {
            u8 *pkt;
            pkt = func_0019bbe0((u8 *)cur->unit, 0xFFFFFF, 8, 0, 4, 0);
            *pkt = 5;
            *(s64 *)(pkt + 8) = *(s64 *)(stepPkt + 0x58);
            *(u16 *)(pkt + 0x48) = 0xC;
            *(s64 *)(pkt + 0x60) = action->uid;
            btlPacketEnqueue(pkt, 1);
            lastId = *(s64 *)(pkt + 0x58);
        }
    }
    if (spread != 0) {
        {
            u8 *pkt;
            pkt = (u8 *)btlCreateSetFlagsPacket(0x80);
            *pkt = 4;
            *(s64 *)(pkt + 8) = lastId;
            *(pkt + 0x10) = 0xA;
            *(u16 *)(pkt + 0x18) = 0x801;
            *(s64 *)(pkt + 0x60) = action->uid;
            btlPacketEnqueue(pkt, 1);
        }
        *(u16 *)(iGpffffb3ac + 0x1C) = 3;
    }
    {
        u8 *pkt;
        pkt = btlTargetCreateActionPacket((u8 *)action, 0);
        *(s64 *)(pkt + 0x60) = action->uid;
        btlPacketEnqueue(pkt, 1);
    }
    btlActionSetState((BtlAction *)action, 0x20);
}

/* Measured: 644/656 bytes, 22 resolved relocations and 12 zero tail bytes.
 * Packet submissions retain callback-visible unit, UID and global reloads. */
#pragma push
/* measured: func_001adb80 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: func_001adb80 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001ADB80
void btlActionPersonaInit(s64 *arg0)
{
    u16 person;
    u32 unit;
    s32 needsIntro;
    s32 actionFlags;
    u8 *introPacket;
    u8 *actionPacket;
    u8 *cameraPacket;
    u8 *animPacket;
    u8 *effectPacket;
    u8 *pendingRecord;
    u8 *resultPacket;
    u8 *followPacket;
    u8 *battleUnit;
    u8 *linkedUnit;

    actionFlags = *(u16 *)((u8 *)arg0 + 0x1A);
    if ((actionFlags & 1) == 0) {
        needsIntro = 0;
    } else {
        battleUnit = *(u8 **)((u8 *)arg0 + 0x30);
        linkedUnit = *(u8 **)(battleUnit + 0xA0C);
        if ((actionFlags & 0x10) == 0) {
            needsIntro = 0;
        } else if ((*(s32 *)(linkedUnit + 0x98) & 2) != 0) {
            needsIntro = 1;
        } else {
            needsIntro = 0;
        }
    }
    if (needsIntro != 0) {
        introPacket = (u8 *)btlUnitCreateModelReleasePacket(
            *(BtlUnit **)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA0C));
        *(s64 *)(introPacket + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(introPacket, 1);
    }
    btlActionFinishPresentation((BtlAction *)arg0);
    actionPacket = btlPacketCreateSpriteTable(
        *(u32 *)((u8 *)arg0 + 0x30),
        *(u16 *)((u8 *)arg0 + 0x6C));
    *(s64 *)(actionPacket + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(actionPacket, 3);
    cameraPacket = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x1F);
    *(s64 *)(cameraPacket + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(cameraPacket, 0);
    animPacket = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)*(u8 **)((u8 *)arg0 + 0x30),
                             0x19, 0, 1.0f, 0);
    *(s64 *)(animPacket + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(animPacket, 0);
    effectPacket = func_001f99c0((u8 *)arg0, 0x15, 0, 0, 0);
    *(s64 *)(effectPacket + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(effectPacket, 1);
    if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA2) == 0) {
        datPersonaSelectRosterMemberById(*(u16 *)((u8 *)arg0 + 0x74));
        person = *(u16 *)((u8 *)arg0 + 0x74);
        btlUnitInitChild(*(u8 **)((u8 *)arg0 + 0x30), person);
        datPersonaRemoveSelectedRosterMember();
        if (datGetFlag(0x3C) != 0) {
            pendingRecord = *(u8 **)((u8 *)arg0 + 0x3F0);
            if (pendingRecord != NULL) {
                *(s16 *)(pendingRecord + 6) = 0;
                *(s16 *)(*(u8 **)((u8 *)arg0 + 0x3F0) + 4) = 0;
            }
        }
    }
    unit = *(u32 *)((u8 *)arg0 + 0x30);
    resultPacket = (u8 *)btlFormationCreatePacket(
        *(s32 *)(D_0076449C + 0xD3C),
        unit, unit,
        0, 0);
    *(s16 *)(resultPacket + 0x48) = 0xF;
    *(s64 *)(resultPacket + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(resultPacket, 2);
    followPacket = (u8 *)btlSoundCreateChannelCuePacket(0xA, 2, 6);
    *(s8 *)(followPacket + 0) = 5;
    *(s64 *)(followPacket + 8) = *(s64 *)(resultPacket + 0x58);
    *(s64 *)(followPacket + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(followPacket, 1);
    *(s32 *)(D_0076449C + 0xC) |= 0x400000;
    *(u16 *)(D_0076449C + 0x18) |= 5;
}


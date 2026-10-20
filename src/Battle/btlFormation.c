#include "btl_unit_internal.h"
#include "btl_formation_attach_internal.h"
#include "datCalc_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_formation_internal.h"
#include "btl_motion_internal.h"
#include "btl_effect_internal.h"
#include "btl_action_internal.h"
#include "btl_camera_framing_internal.h"

typedef u32 (*BtlPacketUpdateFunc)(void* work);


extern BtlPacket* btlPacketAlloc(u32 packetType, u32 workSize);
extern u32 btlCameraNudgeUnitPair(int* work);
extern u32 btlFormationPlaceUnits(u32 *work);
extern void btlFormationEnterTurn(u32 *work);
extern u32 btlFormationPlaceFromRaw(u8 *raw);
extern void btlFormationLeaveTurn(u32 *work);
extern u32 btlFormationUpdatePose(u32 *work);
extern u32 btlFormationUpdateMovement(u16 *options);
extern u32 btlFormationUpdateDeadPosition(u16 *flags);
extern u32 btlFormationAdvanceSlot(u8 **actionWork);
extern u32 btlFormationApplyDefaultPose(void);
extern u32 btlEffectAllocEntry(u32 pool);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern u8 D_00609498[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 *D_0076449C;
extern void btlUnitGetAnchorPose(void *unit, void *outPosition, void *outRotation, void *outTarget);
extern void btlUnitSetPos(void *unit, void *pos);
extern void btlUnitSetRot(void *unit, void *rot);
extern s32 btlUnitIsMoving(void *unit);
extern void btlUnitClearMoveFlags(void *unit);
extern void btlUnitClearRotateFlags(void *unit);
extern void btlUnitRequestLookAt(void *unit);
extern void btlTargetRefreshRadiusNode(void *unit);
extern u8 *btlActionGetActiveOrQueueFront(void);
extern void btlCameraAssignFormationSlots(s32 applyPositions, s32 unused);
extern f32 RwV3dNormalize(f32 *context, f32 *value);

/* Packet 0xB03 stores two unit addresses followed by a pose selector. */
typedef struct BtlFormationPoseWork
{
    u32 actor;
    u32 target;
    u16 mode;
    u8 pad0A[2];
} BtlFormationPoseWork;

/* Packet 0x301 owns the effect node until both timing predicates finish. */
typedef struct BtlFormationEffectWork
{
    u32 formation;
    u32 source;
    u32 target;
    u16 side;
    u8 pad0E[2];
    u32 effect;
    u32 resource;
    u32 elapsed;
    u32 flags;
} BtlFormationEffectWork;

typedef struct BtlFormationDescriptor
{
    u8 pad00[4];
    u16 flags;
    u16 options;
    s32 unk08;
    s32 unk0C;
} BtlFormationDescriptor;

/* The opaque unit span before effectKey ends with the effect-pool key. */
typedef struct BtlFormationUnitResources
{
    u8 pad00[4];
    u32 effectKey;
} BtlFormationUnitResources;

extern void btlFormationSetState(int state);
extern void (*DAT_008873EC[])(void *);

extern u64 memcpy();

extern u64 mdlEffectDestroyWithNodes(u32 effect);

extern void btlFormationCopyRecord(int destination, u32 source);

typedef struct BtlFormationWork
{
    u32 state;
    u32 list;
    u32 argument5;
    u8 padding0c[4];
    s32 sentinel;
    u8 random;
    u8 padding15[3];
    u32 argument3;
    u32 argument4;
    u8 padding20[0x34];
    u16 count;
    u16 padding56;
    u32 items;
} BtlFormationWork;

// Counterpart of P3 global fGpffff8398.
extern float fGpffff8354;
// Matches P3FES fGpffff839c; in P4 retail this float is at 0x0076120c.
extern float fGpffff811c;
extern u32 strlen(const char *text);
extern char *strcpy(char *destination, const char *source);
extern void btlBedCopyRecord(u32 *bed);
extern u32 btlBedLoad(u32 *bed);


u32 btlFormationGetCount(void *formation);
u32 btlFormationGetEntry(void *formation, u32 index);

extern u32 btlEffectFreeEntry(int pool, u16 *entry);
extern void btlFormationSetPlacement(u32 formation);
extern void btlFormationRefresh(u32 *work);
extern u32 btlFormationIsReady(u32 *work);

extern /* measured: retail keeps the predicate's propagated value unchanged. */
u8 btlFormationHasEntry(u32 *work);
extern void btlFormationRelease(u32 *work);

extern u8* DAT_0076449c;
extern char D_00609570[];
extern u8 *btlFormationAllocEntry(u8 *table, s32 tableIndex, s32 unit, s32 target, s32 flags);
extern char D_00609588[];
extern u8 D_00763388;

s32 sprintf(char *destination, const char *format, ...);

void mdlSetFileStateTriple(u32 first, u32 second, u32 third);
u32 btlUiBeginSequence(void);


/* Create packet 0xB00 for a unit-pair separation/rotation request. */
// FUN_001D1EB0
BtlPacket *btlFormationCreateMovePacket(u32 source, u32 target, f32 distance, u16 mode)
{
    u32 *work;
    u32 packet;

    packet = (u32)btlPacketAlloc(0xb00, 0x10);
    ((BtlPacket *)packet)->updateFunc = (BtlPacketUpdateFunc)btlCameraNudgeUnitPair;
    work = (u32 *)((BtlPacket *)packet)->workData;
    work[0] = source;
    work[1] = target;
    ((BtlCameraUnitPair *)work)->separation = distance;
    ((BtlCameraUnitPair *)work)->flags = mode;
    return (BtlPacket *)packet;
}


struct BtlUnit;
struct BtlTarget;
struct RwV3d;
struct RtQuat;

/* Scale the unit sphere radius for formation placement. */
static inline f32 btlFormationGetScaledRadius(const u8 *unit)
{
    f32 scale = ((const BtlUnit *)unit)->scale;
    return ((const BtlUnit *)unit)->sphereRadius * scale;
}
/* Keep the original target/companion geometry and phase-specific vector lifetimes. */
#pragma push
/* measured: retail does not propagate copies here; scoped locals and reordered branches do not
 * reproduce it. */
#pragma opt_propagation off
/* measured: retail's vector lifetimes require lifetime-based register allocation. */
#pragma opt_lifetimes on
/* Place the actor, companion and selected groups using their world-space bounds. */
// FUN_001D1F30
/* Typed actor/action aliases and indexed target records reproduce the original load order. */
u32 btlFormationPlaceUnits(u32 *work)
{
    BtlAction *actionState;
    BtlUnit *actorUnit;
    BtlAction *targetActionState;

    extern void btlUnitSetPos(struct BtlUnit *, const struct RwV3d *);
    extern void btlUnitSetRot(struct BtlUnit *, const struct RtQuat *);
    extern void btlUnitGetAnchorPose(u8 *, u8 *, f32 *, f32 *);
    extern void btlUnitGetSphereWorldCenter(struct BtlUnit *, struct RwV3d *);
    extern void btlUnitGetSphereCenterTowardTarget(struct BtlUnit *, struct BtlUnit *, struct RwV3d *);
    extern void btlUnitGetGridSphereCenter(struct BtlUnit *, struct RwV3d *);
    extern f32 btlUnitGetGroupBounds(u32, u32, struct RwV3d *, f32 *, f32 *, u32);
    extern s32 btlUnitOpeningMotionMode(s32, u8 *, s16, s32);
    extern s32 btlTargetCanSelectEntry(u8 *context, s16 value, s32 option);
    extern void btlUnitGetSlotPose(u8 *unit, u8 *anchorUnit, u8 *targetUnit, s32 motion,
                            f32 *outPosition, f32 *outRotation, s32 slot);
    extern u16 btlTargetGetUnitIndex(struct BtlTarget *);
    extern void btlTargetBlendVectors(u8 *, u8 *, u8 *);
    extern f32 btlTargetAngleBetween(u8 *, u8 *, u8 *, u8 *);
    extern struct RwV3d *RtQuatTransformVectors(struct RwV3d *, const struct RwV3d *, s32, const struct RtQuat *);
    extern f32 RwV3dLength(f32 *vector);
    extern f32 RwV2dLength(f32 *vector);
    extern s32 btlActionHasNoTargetClass(u32 action);
    extern s32 btlTargetIsEntryActive(s16 context);
    extern s32 btlBossUnitsSameGenus(struct BtlUnit *, struct BtlUnit *);
    extern s32 btlBossTargetBlocked(u8 *);
    extern u32 btlBossFlagPairOk(s32, s32);
    extern u8 *iGpffffb3ac;
    extern f32 fGpffff809c;
    typedef struct { f32 v[3]; } Vec3;
    u8 *action;
    u8 *targetAction;
    u8 *actor;
    u8 *targetUnit;
    u8 *nearestNode;
    u8 *spacingNode;
    u8 *groupNode;
    u8 *actionTarget;
    u8 *groupTarget;
    s32 movedAny;
    u8 *groupUnit;
    u8 *companion;
    u16 skill;
    u8 genus;
    s32 motionKind;
    s32 motionCategory;
    s32 isClose;
    s32 companionNeedsMove;
    s32 firstCandidate;
    u32 targetCount;
    u16 targetIndex;
    f32 actorCenter[3];
    Vec3 targetCenter;
    Vec3 farthestCenter;
    f32 direction[3];
    f32 position[3];
    f32 companionDelta[3];
    Vec3 candidateCenter;
    Vec3 nearestCenter;
    f32 companionVector[3];
    f32 actorXZ[2];
    f32 targetXZ[2];
    f32 groupXZ[2];
    f32 nearestXZ[2];
    f32 rotation[4];
    f32 distance;
    f32 actorRadius;
    f32 extraDistance;
    f32 separation;
    f32 companionRadius;
    f32 companionScale;
    f32 nearestDistance;
    f32 scale;
    f32 centerX;
    f32 extent;
    f32 lineDistance;
    f32 minimumSpacing;
    f32 projectedY;
    f32 projectedZ;
    f32 otherRadius;
    f32 offsetDistance;
    f32 targetScale;
    f32 groupRadius;
    f32 farthestDistance;
    f32 groupDistance;

    action = *(u8 **)work;
    actionState = (BtlAction *)action;
    skill = ((BtlAction *)action)->unk_6e;
    genus = ((BtlAction *)action)->unit->genus;
    switch (genus) {
    case 0:
        btlTargetIsEntryActive((s16)skill);
        if (btlActionHasNoTargetClass((u32)action) == 1) {
            targetAction = (u8 *)((BtlAction **)((BtlAction *)action)->unk_38)[0];
            if (action == targetAction) {
                return 1;
            }
            if ((((BtlBattleState *)iGpffffb3ac)->battleFlags & 0x1000000) != 0) {
                return 1;
            }
            if (btlBossTargetBlocked(action) == 0) {
                return 1;
            }
            actor = (u8 *)actionState->unit;
            actorUnit = (BtlUnit *)actor;
            targetUnit = (u8 *)((BtlAction *)targetAction)->unit;
            companion = (u8 *)((BtlUnit *)actor)->childUnit;
            if (btlBossUnitsSameGenus((struct BtlUnit *)(actor), (struct BtlUnit *)(targetUnit)) != 0) {
                ((BtlBattleState *)iGpffffb3ac)->flags |= 0x400000;
                ((BtlBattleState *)iGpffffb3ac)->actionEndFlags |= 0xE;
            }
            btlUnitGetSphereWorldCenter((struct BtlUnit *)(actor), (struct RwV3d *)(actorCenter));
            btlUnitGetSphereCenterTowardTarget((struct BtlUnit *)(targetUnit), (struct BtlUnit *)(actor), (struct RwV3d *)((f32 *)&targetCenter));
            targetCenter.v[1] = ((BtlUnit *)actor)->pos.y;
            actorCenter[1] = targetCenter.v[1];
            if (work[2] == 1 && targetUnit != actor && btlBossFlagPairOk((s32)(actor), (s32)(targetUnit)) != 0) {
                if ((((BtlBattleState *)iGpffffb3ac)->flags & 0x200000) == 0) {
                    btlUnitGetSphereWorldCenter((struct BtlUnit *)(targetUnit), (struct RwV3d *)((f32 *)&candidateCenter));
                    btlTargetBlendVectors((u8 *)(rotation), (u8 *)((f32 *)&candidateCenter), (u8 *)(actorCenter));
                    centerX = ((BtlUnit *)targetUnit)->sphereCenter.x;
                    scale = ((BtlUnit *)targetUnit)->scale;
                    position[0] = centerX * scale;
                    position[1] = ((BtlUnit *)targetUnit)->sphereCenter.y * scale;
                    position[2] = ((BtlUnit *)targetUnit)->sphereCenter.z * scale;
                    RtQuatTransformVectors((struct RwV3d *)(direction), (const struct RwV3d *)(position), 1, (const struct RtQuat *)(rotation));
                    position[0] = candidateCenter.v[0] - direction[0];
                    position[1] = candidateCenter.v[1] - direction[1];
                    position[2] = candidateCenter.v[2] - direction[2];
                    candidateCenter.v[1] = ((BtlUnit *)targetUnit)->pos.y;
                    position[1] = candidateCenter.v[1];
                    btlUnitSetPos((struct BtlUnit *)(targetUnit), (const struct RwV3d *)(position));
                    btlTargetBlendVectors((u8 *)(rotation), (u8 *)(position), (u8 *)(actor + 4));
                    btlUnitSetRot((struct BtlUnit *)(targetUnit), (const struct RtQuat *)(rotation));
                    targetCenter = candidateCenter;
                } else {
                    btlTargetBlendVectors((u8 *)(rotation), (u8 *)((f32 *)&targetCenter), (u8 *)(actorCenter));
                    btlUnitSetRot((struct BtlUnit *)(targetUnit), (const struct RtQuat *)(rotation));
                }
                btlUnitClearRotateFlags(targetUnit);
                btlUnitRequestLookAt(targetUnit);
            }
            if (work[1] == 1) {
                direction[0] = actorCenter[0] - targetCenter.v[0];
                direction[1] = actorCenter[1] - targetCenter.v[1];
                direction[2] = actorCenter[2] - targetCenter.v[2];
                direction[1] = 0.0f;
                distance = RwV3dNormalize(direction, direction);
                actorRadius = actorUnit->sphereRadius * actorUnit->scale;
                extraDistance = 0.0f;
                /* The null-companion path supplies no isClose value in
                 * retail; only the later distance clamp may set it. */
                if (companion != NULL) {
                    isClose = btlTargetCanSelectEntry(companion, (s16)skill, 1);
                    motionCategory = (s16)btlUnitOpeningMotionMode((s32)((s32)companion), actor, (s16)skill, 1);
                    distance = (0.0f + distance) - actorUnit->sphereRadius * actorUnit->scale;
                    if (isClose == 0) {
                        motionKind = (s16)btlUnitOpeningMotionMode((s32)((s32)companion), actor, (s16)skill, 1);
                        switch (motionKind) {
                        case 0:
                        case 2:
                            btlUnitGetSlotPose(companion, actor, targetUnit, motionCategory, position, NULL, 0);
                            break;
                        case 1:
                        case 3:
                            btlUnitGetSlotPose(companion, actor, targetUnit, motionCategory, position, NULL, 1);
                            break;
                        }
                    } else {
                        btlUnitGetSlotPose(companion, actor, targetUnit, motionCategory, position, NULL, 2);
                    }
                    direction[0] = targetCenter.v[0] - actorCenter[0];
                    direction[1] = targetCenter.v[1] - actorCenter[1];
                    direction[2] = targetCenter.v[2] - actorCenter[2];
                    direction[1] = 0.0f;
                    RwV3dNormalize(direction, direction);
                    direction[0] *= 1000.0f;
                    direction[1] *= 1000.0f;
                    direction[2] *= 1000.0f;
                    companionVector[0] = targetCenter.v[0] + direction[0];
                    companionVector[1] = targetCenter.v[1] + direction[1];
                    companionVector[2] = targetCenter.v[2] + direction[2];
                    direction[0] = position[0] - companionVector[0];
                    direction[1] = position[1] - companionVector[1];
                    direction[2] = position[2] - companionVector[2];
                    direction[1] = 0.0f;
                    RwV3dNormalize(direction, direction);
                    companionVector[0] = position[0] - targetCenter.v[0];
                    companionVector[1] = position[1] - targetCenter.v[1];
                    companionVector[2] = position[2] - targetCenter.v[2];
                    companionVector[1] = 0.0f;
                    extent = RwV3dLength(companionVector);
                    companionScale = ((BtlUnit *)companion)->scale;
                    companionRadius = ((BtlUnit *)companion)->sphereRadius * companionScale;
                    separation = extent - companionRadius;
                    companionNeedsMove = isClose;
                    if (companionNeedsMove == 0) {
                        if ((0.0f + distance) + ((BtlUnit *)actor)->sphereRadius * ((BtlUnit *)actor)->scale < separation + companionRadius) {
                            isClose = companionNeedsMove;
                        } else {
                            distance = separation;
                            actorRadius = companionRadius;
                            companionDelta[0] = actorCenter[0] - position[0];
                            companionDelta[1] = actorCenter[1] - position[1];
                            companionDelta[2] = actorCenter[2] - position[2];
                            companionDelta[1] = 0.0f;
                            extraDistance = RwV3dNormalize(companionDelta, companionDelta);
                        }
                    } else {
                        actorRadius = companionRadius;
                        btlUnitGetSlotPose(companion, actor, NULL, -1, position, NULL, 0);
                        position[0] = actorCenter[0];
                        position[1] = actorCenter[1];
                        companionDelta[0] = position[0] - actorCenter[0];
                        companionDelta[1] = position[1] - actorCenter[1];
                        companionDelta[2] = position[2] - actorCenter[2];
                        extraDistance = RwV3dLength(companionDelta);
                        if (extraDistance + (separation + companionRadius) <= distance) {
                            extraDistance = 0.0f;
                        } else {
                            distance = separation;
                        }
                    }
                }
                otherRadius = btlFormationGetScaledRadius(targetUnit);
                distance -= otherRadius;
                if (distance < 300.0f) {
                    distance = 300.0f;
                    isClose = 1;
                }
                if (isClose != 0) {
                    offsetDistance = distance + actorRadius;
                    targetScale = ((BtlUnit *)targetUnit)->scale;
                    offsetDistance += otherRadius;
                    offsetDistance += extraDistance;
                    scale = (0.0f + offsetDistance) +
                            ((BtlUnit *)targetUnit)->sphereCenter.z * targetScale;
                    direction[0] *= scale;
                    direction[1] *= scale;
                    direction[2] *= scale;
                    position[0] = targetCenter.v[0] + direction[0];
                    position[1] = targetCenter.v[1] + direction[1];
                    position[2] = targetCenter.v[2] + direction[2];
                    btlUnitSetPos((struct BtlUnit *)(actor), (const struct RwV3d *)(position));
                }
            }
        } else {
            if ((((BtlBattleState *)iGpffffb3ac)->flags & 0x200000) == 0) {
                actor = (u8 *)actionState->unit;
                actorUnit = (BtlUnit *)actor;
                if (work[2] == 1) {
                    for (targetIndex = 0; targetIndex < ((BtlAction *)action)->unk_6a; targetIndex++) {
                        actionTarget = ((BtlAction *)action)->targets[targetIndex];
                        targetActionState = (BtlAction *)actionTarget;
                        if ((((BtlAction *)actionTarget)->unk_1a & 1) != 0 && actionTarget != action) {
                            btlTargetBlendVectors((u8 *)(rotation), (u8 *)((u8 *)((BtlAction *)actionTarget)->unit + 4), (u8 *)(actor + 4));
                            btlUnitSetRot((struct BtlUnit *)((u8 *)targetActionState->unit), (const struct RtQuat *)(rotation));
                            btlUnitClearRotateFlags((u8 *)targetActionState->unit);
                            btlUnitRequestLookAt((u8 *)targetActionState->unit);
                        }
                    }
                }
                btlUnitGetSphereWorldCenter((struct BtlUnit *)(actor), (struct RwV3d *)(actorCenter));
                /* An empty filtered group leaves X/Z unwritten, as in
                 * retail. Only Y is replaced before using the center. */
                btlUnitGetGroupBounds(2, 0, (struct RwV3d *)((f32 *)&targetCenter), NULL, NULL, 1);
                targetCenter.v[1] = ((BtlUnit *)actor)->pos.y;
                actorCenter[1] = targetCenter.v[1];
                nearestCenter = targetCenter;
                nearestDistance = 0.0f;
                firstCandidate = 1;
                actorXZ[0] = actorCenter[0];
                actorXZ[1] = actorCenter[2];
                groupXZ[0] = targetCenter.v[0];
                groupXZ[1] = targetCenter.v[2];
                for (nearestNode = ((BtlBattleState *)iGpffffb3ac)->unitLists[3]; nearestNode != NULL; nearestNode = (u8 *)((BtlUnit *)nearestNode)->prevUnit) {
                    if ((((BtlUnit *)nearestNode)->flags3 & 8) != 0) {
                        btlUnitGetSphereCenterTowardTarget((struct BtlUnit *)(nearestNode), (struct BtlUnit *)(actor), (struct RwV3d *)((f32 *)&candidateCenter));
                        targetXZ[0] = candidateCenter.v[0];
                        targetXZ[1] = candidateCenter.v[2];
                        btlTargetAngleBetween((u8 *)(actorXZ), (u8 *)(groupXZ), (u8 *)(targetXZ), (u8 *)(nearestXZ));
                        targetXZ[0] = actorXZ[0] - nearestXZ[0];
                        targetXZ[1] = actorXZ[1] - nearestXZ[1];
                        lineDistance = RwV2dLength(targetXZ);
                        if (lineDistance < nearestDistance || firstCandidate == 1) {
                            nearestCenter.v[0] = nearestXZ[0];
                            nearestCenter.v[1] = actorCenter[1];
                            nearestCenter.v[2] = nearestXZ[1];
                            nearestDistance = lineDistance;
                            firstCandidate = 0;
                        }
                    }
                }
                separation = (0.0f + nearestDistance) - actorUnit->sphereRadius * actorUnit->scale;
                minimumSpacing = 450.0f;
                if (separation < minimumSpacing) {
                    direction[0] = actorCenter[0] - nearestCenter.v[0];
                    projectedY = nearestCenter.v[1];
                    direction[1] = actorCenter[1] - projectedY;
                    projectedZ = nearestCenter.v[2];
                    direction[2] = actorCenter[2] - projectedZ;
                    direction[1] = 0.0f;
                    RwV3dNormalize(direction, direction);
                    separation = (0.0f + minimumSpacing) + ((BtlUnit *)actor)->sphereRadius * ((BtlUnit *)actor)->scale;
                    direction[0] *= separation;
                    direction[1] *= separation;
                    direction[2] *= separation;
                    position[0] = nearestCenter.v[0] + direction[0];
                    position[1] = projectedY + direction[1];
                    position[2] = projectedZ + direction[2];
                    btlUnitSetPos((struct BtlUnit *)(actor), (const struct RwV3d *)(position));
                }
            } else if ((((BtlBattleState *)iGpffffb3ac)->battleFlags & 0x80) != 0) {
                btlUnitGetGroupBounds(2, 0, (struct RwV3d *)((f32 *)&targetCenter), NULL, NULL, 1);
                for (spacingNode = ((BtlBattleState *)iGpffffb3ac)->unitLists[1]; spacingNode != NULL; spacingNode = (u8 *)((BtlUnit *)spacingNode)->prevUnit) {
                    if ((((BtlUnit *)spacingNode)->flags3 & 8) != 0) {
                        btlUnitGetSphereWorldCenter((struct BtlUnit *)(spacingNode), (struct RwV3d *)(actorCenter));
                        direction[0] = actorCenter[0] - targetCenter.v[0];
                        direction[1] = actorCenter[1] - targetCenter.v[1];
                        direction[2] = actorCenter[2] - targetCenter.v[2];
                        direction[1] = 0.0f;
                        RwV3dNormalize(direction, direction);
                        direction[0] *= 200.0f;
                        direction[1] *= 200.0f;
                        direction[2] *= 200.0f;
                        btlUnitGetAnchorPose((u8 *)(spacingNode), (u8 *)(position), (f32 *)(NULL), (f32 *)(NULL));
                        position[0] += direction[0];
                        position[1] += direction[1];
                        position[2] += direction[2];
                        btlUnitSetPos((struct BtlUnit *)(spacingNode), (const struct RwV3d *)(position));
                    }
                }
                ((BtlBattleState *)iGpffffb3ac)->flags |= 0x400000;
                ((BtlBattleState *)iGpffffb3ac)->actionEndFlags |= 6;
            }
        }
        break;
    case 1:
        if (((BtlAction *)action)->unk_6a == 1) {
            break;
        }
        if ((((BtlBattleState *)iGpffffb3ac)->flags & 0x200000) != 0) {
            break;
        }
        targetCount = btlTargetGetUnitIndex((struct BtlTarget *)(action + 0x38)) & 0xFFFF;
        if (targetCount != 1) {
            break;
        }
        movedAny = 0;
        groupUnit = (u8 *)actionState->unit;
        btlUnitGetSphereWorldCenter((struct BtlUnit *)(groupUnit), (struct RwV3d *)(actorCenter));
        groupRadius = ((BtlUnit *)groupUnit)->sphereRadius * ((BtlUnit *)groupUnit)->scale;
        if (work[2] == 1) {
            btlUnitGetGroupBounds(targetCount, 1, (struct RwV3d *)((f32 *)&targetCenter), NULL, NULL, 1);
            /* farthestCenter is written only for a qualifying farther target.
             * Retail still consumes its stack slot after an empty scan. */
            farthestDistance = 0.0f;
            for (targetIndex = 0; targetIndex < actionState->unk_6a; targetIndex++) {
                groupTarget = ((BtlAction *)action)->targets[targetIndex];
                if ((((BtlAction *)groupTarget)->unk_1a & 1) != 0) {
                    btlUnitGetGridSphereCenter((struct BtlUnit *)((u8 *)((BtlAction *)groupTarget)->unit), (struct RwV3d *)((f32 *)&candidateCenter));
                    direction[0] = targetCenter.v[0] - candidateCenter.v[0];
                    direction[1] = targetCenter.v[1] - candidateCenter.v[1];
                    direction[2] = targetCenter.v[2] - candidateCenter.v[2];
                    extent = RwV3dLength(direction);
                    if (!(extent <= farthestDistance)) {
                        farthestCenter = candidateCenter;
                        farthestDistance = extent;
                    }
                }
            }
            btlTargetBlendVectors((u8 *)(rotation), (u8 *)(actorCenter), (u8 *)((f32 *)&farthestCenter));
            btlUnitSetRot((struct BtlUnit *)(groupUnit), (const struct RtQuat *)(rotation));
            btlUnitClearRotateFlags(groupUnit);
            btlUnitRequestLookAt(groupUnit);
        }
        for (groupNode = ((BtlBattleState *)iGpffffb3ac)->unitLists[1]; groupNode != NULL; groupNode = (u8 *)((BtlUnit *)groupNode)->prevUnit) {
            if ((((BtlUnit *)groupNode)->flags3 & 8) != 0) {
                btlUnitGetSphereCenterTowardTarget((struct BtlUnit *)(groupNode), (struct BtlUnit *)(groupUnit), (struct RwV3d *)((f32 *)&targetCenter));
                direction[0] = targetCenter.v[0] - actorCenter[0];
                direction[1] = targetCenter.v[1] - actorCenter[1];
                direction[2] = targetCenter.v[2] - actorCenter[2];
                direction[1] = 0.0f;
                groupDistance = RwV3dNormalize(direction, direction);
                scale = (0.0f + groupRadius) + fGpffff809c * (groupDistance - groupRadius);
                if (scale < groupDistance && !(scale <= 300.0f)) {
                    direction[0] *= scale;
                    direction[1] *= scale;
                    direction[2] *= scale;
                    position[0] = actorCenter[0] + direction[0];
                    position[1] = actorCenter[1] + direction[1];
                    position[2] = actorCenter[2] + direction[2];
                    position[1] = 0.0f;
                    btlUnitSetPos((struct BtlUnit *)(groupNode), (const struct RwV3d *)(position));
                    movedAny = 1;
                }
            }
        }
        if (movedAny != 0) {
            ((BtlBattleState *)iGpffffb3ac)->flags |= 0x400000;
            ((BtlBattleState *)iGpffffb3ac)->actionEndFlags |= 0x1E;
        }
        break;
    }
    return 1;
}

#pragma pop
/* Create packet 0xB01 with independent actor-placement and target-rotation switches. */
// FUN_001D2D90
BtlPacket* btlFormationCreateStepPacket(u32 action, u32 moveActor, u32 rotateTargets)
{
    u32 *work;
    u32 packet;

    packet = (u32)btlPacketAlloc(0xb01, 0xc);
    ((BtlPacket *)packet)->updateFunc = (BtlPacketUpdateFunc)btlFormationPlaceUnits;
    work = (u32 *)((BtlPacket *)packet)->workData;
    work[0] = action;
    work[1] = moveActor;
    work[2] = rotateTargets;
    return (BtlPacket*)packet;
}


/* Hold the actor while the placement packet owns its pending-packet reference. */
// FUN_001D2E00
void btlFormationEnterTurn(u32 *work)
{
    ((BtlUnit *)work[0])->pendingPacketCount = ((BtlUnit *)work[0])->pendingPacketCount + 1;
}
/* Packet storage stays unsigned; the action helpers receive its signed interpretation. */
#pragma push
/* measured: retail does not propagate copies in this callback; local restructuring does not
 * reproduce it. */
#pragma opt_propagation off
extern s32 btlUnitOpeningMotionMode(s32, u8 *, s16, s32);
extern s32 btlTargetCanSelectEntry(u8 *, s16, s32);
extern void btlUnitGetSlotPose(u8 *, u8 *, u8 *, s32, f32 *, f32 *, s32);

typedef struct BtlFormationPlacementWork
{
    u8 *actor;
    u8 *targetAction;
    u8 *partnerAction;
    u16 action;
} BtlFormationPlacementWork;

/* Choose the opening pose mode and place the unit relative to its partner. */
static inline u32 btlFormationPlaceUnit(BtlFormationPlacementWork *work, u8 *node, u8 *unit)
{
    /* Complete quaternion and position outputs of the placement helper. */
    struct { f32 rotation[4]; f32 position[3]; } frame;
    s32 category;
    s32 kind;
    u16 actionBits;
    s32 paired;
    s16 mode;

    /* Capture the stored halfword before querying the partner, then
     * interpret those same bits as the signed action identifier. */
    actionBits = work->action;
    paired = work->partnerAction != NULL;
    mode = (s16)actionBits;
    category = (s16)btlUnitOpeningMotionMode((s32)node, unit, mode, paired);
    if (btlTargetCanSelectEntry(node, mode, paired) == 0) {
        kind = (s16)btlUnitOpeningMotionMode((s32)node, unit, mode, paired);
        switch (kind) {
        case 0:
        case 2:
            btlUnitGetSlotPose(node, unit, NULL, category, frame.position, frame.rotation, 0);
            break;
        case 1:
        case 3:
            btlUnitGetSlotPose(node, unit, NULL, category, frame.position, frame.rotation, 1);
            break;
        }
        btlUnitSetRot(node, frame.rotation);
        btlUnitSetPos(node, frame.position);
    } else {
        btlUnitGetSlotPose(node, unit, (u8 *)((BtlAction *)work->partnerAction)->unit,
                      category, frame.position, frame.rotation, 2);
        btlUnitSetRot(node, frame.rotation);
        btlUnitSetPos(node, frame.position);
    }
    return 1;
}

/* Place the actor relative to its target action and optional partner action. */
// FUN_001D2E20
u32 btlFormationPlaceFromRaw(u8 *raw)
{
    BtlFormationPlacementWork *work;
    u8 *node;
    u8 *unit;

    work = (BtlFormationPlacementWork *)raw;
    node = work->actor;
    unit = (u8 *)((BtlAction *)work->targetAction)->unit;
    return btlFormationPlaceUnit(work, node, unit);
}
#pragma pop

/* Release the placement packet's pending reference on its actor. */
// FUN_001D2FE0
void btlFormationLeaveTurn(u32 *work)
{
    ((BtlUnit *)work[0])->pendingPacketCount = ((BtlUnit *)work[0])->pendingPacketCount - 1;
}
/* Create packet 0xB02, retaining the actor for the target/partner placement callback. */
// FUN_001D3000
BtlPacket* btlFormationCreateTurnPacket(u32 actor, u32 targetAction, u32 partnerAction, u16 skill)
{
    u32 *work;
    u32 packet;

    packet = (u32)btlPacketAlloc(0xb02, 0x10);
    ((BtlPacket *)packet)->initFunc = (BtlPacketFunc)btlFormationEnterTurn;
    ((BtlPacket *)packet)->updateFunc = (BtlPacketUpdateFunc)btlFormationPlaceFromRaw;
    ((BtlPacket *)packet)->destroyFunc = (BtlPacketUpdateFunc)btlFormationLeaveTurn;
    work = (u32 *)((BtlPacket *)packet)->workData;
    work[0] = actor;
    work[1] = targetAction;
    work[2] = partnerAction;
    ((BtlFormationPlacementWork *)work)->action = skill;
    return (BtlPacket*)packet;
}


/* Apply one of five relative-pose modes to the stored unit pair. */
// FUN_001D3090
u32 btlFormationUpdatePose(u32 *work)
{
    #include "rw_types_internal.h"

    extern void btlUnitFaceTarget(void *unit, void *target);
    extern void func_003dc740(void *dst, void *src, s32 c, f32 d);
    extern void RtQuatTransformVectors(void *out, const void *in, s32 count, const void *rot);
    extern f32 D_0060A0E0[3];
    extern f32 D_0060A0F0[3];

    u16 sel;
    RtQuat rotation;
    f32 diff[3];
    f32 dest[3];
    f32 scale;

    sel = ((BtlFormationPoseWork *)work)->mode;
    switch (sel) {
    case 0:
        btlUnitClearMoveFlags((void *)work[0]);
        btlUnitClearRotateFlags((void *)work[0]);
        btlUnitFaceTarget((void *)work[0], (u8 *)work[1] + 4);
        btlUnitFaceTarget((void *)work[1], (u8 *)work[0] + 4);
        diff[0] = ((BtlUnit *)work[0])->pos.x - ((BtlUnit *)work[1])->pos.x;
        diff[1] = ((BtlUnit *)work[0])->pos.y - ((BtlUnit *)work[1])->pos.y;
        diff[2] = ((BtlUnit *)work[0])->pos.z - ((BtlUnit *)work[1])->pos.z;
        diff[1] = 0.0f;
        RwV3dNormalize(diff, diff);
        diff[0] *= 100.0f;
        diff[1] *= 100.0f;
        diff[2] *= 100.0f;
        dest[0] = ((BtlUnit *)work[1])->pos.x + diff[0];
        dest[1] = ((BtlUnit *)work[1])->pos.y + diff[1];
        dest[2] = ((BtlUnit *)work[1])->pos.z + diff[2];
        btlUnitSetPos((void *)work[0], dest);
        break;
    case 1:
        btlUnitClearMoveFlags((void *)work[0]);
        btlUnitClearRotateFlags((void *)work[0]);
        btlUnitFaceTarget((void *)work[0], (u8 *)work[1] + 4);
        btlUnitFaceTarget((void *)work[1], (u8 *)work[0] + 4);
        diff[0] = ((BtlUnit *)work[0])->pos.x - ((BtlUnit *)work[1])->pos.x;
        diff[1] = ((BtlUnit *)work[0])->pos.y - ((BtlUnit *)work[1])->pos.y;
        diff[2] = ((BtlUnit *)work[0])->pos.z - ((BtlUnit *)work[1])->pos.z;
        diff[1] = 0.0f;
        RwV3dNormalize(diff, diff);
        diff[0] *= 150.0f;
        diff[1] *= 150.0f;
        diff[2] *= 150.0f;
        dest[0] = ((BtlUnit *)work[1])->pos.x + diff[0];
        dest[1] = ((BtlUnit *)work[1])->pos.y + diff[1];
        dest[2] = ((BtlUnit *)work[1])->pos.z + diff[2];
        btlUnitSetPos((void *)work[0], dest);
        break;
    case 2:
        btlUnitSetPos((void *)work[0], (u8 *)work[1] + 4);
        btlUnitSetRot((void *)work[0], (u8 *)work[1] + 0x1c);
        break;
    case 3:
        rotation = ((BtlUnit *)work[1])->rot;
        if ((((BtlBattleState *)D_0076449C)->flags & 0x200000) == 0) {
            func_003dc740(&rotation, D_0060A0E0, 2, 90.0f);
        } else {
            func_003dc740(&rotation, D_0060A0E0, 2, 130.0f);
        }
        RtQuatTransformVectors(diff, D_0060A0F0, 1, &rotation);
        diff[0] *= 250.0f;
        diff[1] *= 250.0f;
        diff[2] *= 250.0f;
        dest[0] = ((BtlUnit *)work[0])->pos.x + diff[0];
        dest[1] = ((BtlUnit *)work[0])->pos.y + diff[1];
        dest[2] = ((BtlUnit *)work[0])->pos.z + diff[2];
        btlUnitSetPos((void *)work[1], dest);
        break;
    case 4:
        btlUnitClearMoveFlags((void *)work[0]);
        btlUnitClearRotateFlags((void *)work[0]);
        btlUnitFaceTarget((void *)work[0], (u8 *)work[1] + 4);
        btlUnitFaceTarget((void *)work[1], (u8 *)work[0] + 4);
        scale = btlUnitGetMotionDistance((u8 *)work[0], (u8 *)work[1], 7);
        diff[0] = ((BtlUnit *)work[0])->pos.x - ((BtlUnit *)work[1])->pos.x;
        diff[1] = ((BtlUnit *)work[0])->pos.y - ((BtlUnit *)work[1])->pos.y;
        diff[2] = ((BtlUnit *)work[0])->pos.z - ((BtlUnit *)work[1])->pos.z;
        diff[1] = 0.0f;
        RwV3dNormalize(diff, diff);
        diff[0] *= scale;
        diff[1] *= scale;
        diff[2] *= scale;
        dest[0] = ((BtlUnit *)work[1])->pos.x + diff[0];
        dest[1] = ((BtlUnit *)work[1])->pos.y + diff[1];
        dest[2] = ((BtlUnit *)work[1])->pos.z + diff[2];
        btlUnitSetPos((void *)work[0], dest);
        break;
    }
    return 1;
}
/* Create packet 0xB03 to apply a relative-pose mode to two units. */
// FUN_001D3530
BtlPacket* btlFormationCreateWaitPacket(u32 actor, u32 target, u16 mode)
{
    u32 *work;
    u32 packet;

    packet = (u32)btlPacketAlloc(0xb03, 0xc);
    ((BtlPacket *)packet)->updateFunc = (BtlPacketUpdateFunc)btlFormationUpdatePose;
    work = (u32 *)((BtlPacket *)packet)->workData;
    work[0] = actor;
    work[1] = target;
    ((BtlFormationPoseWork *)work)->mode = mode;
    return (BtlPacket*)packet;
}
/* Restore anchor position/rotation for selected groups; bit 0x8000 skips moving units. */
// FUN_001D35A0
u32 btlFormationUpdateMovement(u16 *options)
{
    u8 position[0x10];
    u8 rotation[0x10];
    s32 resetPosition;
    s32 skipMoving;
    s32 resetRotation;
    u32 groupMask;
    u16 flags;
    u8 *unit;
    u32 group;

    groupMask = options[0];
    flags = options[1];
    group = 0;
    skipMoving = flags & 0x8000;
    resetPosition = flags & 1;
    resetRotation = flags & 2;
    while (group < 4) {
        if ((groupMask & (1 << group)) != 0) {
            unit = ((BtlBattleState *)D_0076449C)->unitLists[group * 2];
            while (unit != NULL) {
                if (((((BtlUnit *)unit)->flags3 & 4) != 0) &&
                    ((skipMoving == 0) || (btlUnitIsMoving(unit) == 0))) {
                    btlUnitGetAnchorPose(unit, position, rotation, NULL);
                    if (resetPosition != 0) {
                        btlUnitSetPos(unit, position);
                        btlUnitClearMoveFlags(unit);
                        btlTargetRefreshRadiusNode(unit);
                    }
                    if (resetRotation != 0) {
                        btlUnitSetRot(unit, rotation);
                        btlUnitClearRotateFlags(unit);
                        btlUnitRequestLookAt(unit);
                    }
                }
                unit = (u8 *)((BtlUnit *)unit)->nextUnit;
            }
        }
        group++;
    }
    return 1;
}
/* Create packet 0xB04 with group mask and anchor-reset option bits. */
// FUN_001D3700
BtlPacket *btlFormationCreateSlotPacket(u16 groupMask, u16 flags)
{
    u16 *work;
    BtlPacket *packet;

    packet = btlPacketAlloc(0xb04, 4);
    packet->updateFunc = (BtlPacketUpdateFunc)btlFormationUpdateMovement;
    work = (u16 *)packet->workData;
    work[0] = groupMask;
    work[1] = flags;
    return packet;
}
/* Reset camera slots and offset eligible living party units from their anchor poses. */
// FUN_001D3760
u32 btlFormationUpdateDeadPosition(u16 *flags)
{
    f32 position[4];
    f32 anchor[4];
    f32 direction[4];
    f32 offsetZ;
    f32 offsetY;
    f32 offsetX;
    f32 distance;
    u8 *action;
    BtlUnit *unit;

    action = btlActionGetActiveOrQueueFront();
    btlCameraAssignFormationSlots(!(*flags & 2), 0);
    if ((*flags & 1) != 0) {
        unit = (BtlUnit *)((BtlBattleState *)D_0076449C)->unitLists[0];
        while (unit != NULL) {
            if ((datCalcChkBadStatus(unit->datUnit, 0x180017) == 0) &&
                (datCalcIsDead(unit->datUnit, 0) == 0)) {
                if (((BtlAction *)action)->unit == unit) {
                    distance = 250.0f;
                } else {
                    distance = 350.0f;
                }
                btlUnitGetAnchorPose(unit, position, NULL, anchor);
                anchor[1] = position[1];
                direction[0] = position[0] - anchor[0];
                direction[1] = position[1] - position[1];
                direction[2] = position[2] - anchor[2];
                RwV3dNormalize(&direction[0], &direction[0]);
                offsetX = direction[0] * distance;
                direction[0] = offsetX;
                offsetY = direction[1] * distance;
                direction[1] = offsetY;
                offsetZ = direction[2] * distance;
                direction[2] = offsetZ;
                position[0] += offsetX;
                position[1] += offsetY;
                position[2] += offsetZ;
                btlUnitSetPos(unit, position);
            }
            unit = unit->nextUnit;
        }
    }
    return 1;
}
/* Create packet 0xB05 for the camera/party anchor-position reset. */
// FUN_001D3900
BtlPacket *btlFormationCreateReturnPacket(u16 flags)
{
    u32 *work;
    u32 packet;

    packet = (u32)btlPacketAlloc(0xb05, 2);
    ((BtlPacket *)packet)->updateFunc = (BtlPacketUpdateFunc)btlFormationUpdateDeadPosition;
    work = (u32 *)((BtlPacket *)packet)->workData;
    *(u16 *)work = flags;
    return (BtlPacket *)packet;
}
/* measured: retail does not propagate copies in this function. */
#pragma push
#pragma opt_propagation off
/* Put living party units on the 25-unit grid, reserving the active actor's default slot. */
// FUN_001D3950
u32 btlFormationAdvanceSlot(u8 **actionWork)
{
    typedef union FormationPair {
        u64 whole;
        f32 values[2];
    } FormationPair;
    typedef struct FormationScratch {
        f32 delta[3];
        u32 gap0;
        FormationPair position;
        f32 positionZ;
        u32 gap1;
    } FormationScratch;
    typedef struct FormationDefault
    {
        u64 whole;
        u32 z : 32;
    } __attribute__((packed)) FormationDefault;
    typedef struct FormationPosition {
        f32 x;
        f32 y;
        f32 z;
    } FormationPosition;
    extern void btlTargetPositionToCell(s16 *outX, s16 *outZ, f32 *position);
    extern u8 D_00609430[];
    extern f32 D_00609458[];
    extern f32 D_0060A110[];
    extern FormationDefault D_00881430;
    extern FormationPosition D_00881438;
    FormationScratch scratch;
    BtlUnit *current;
    u16 index;
    index = 0;
    current = (BtlUnit *)((BtlBattleState *)D_0076449C)->unitLists[1];
    while (current != NULL) {
        if (((current->flags3 & 8) != 0) &&
            (datCalcIsDead(current->datUnit, 0) == 0)) {
            if (((BtlAction *)*actionWork)->unit == current) {
                {
                    u64 defaultPair = D_00881430.whole;
                    f32 defaultZ = D_00881438.x;
                    scratch.position.whole = defaultPair;
                    scratch.positionZ = defaultZ;
                }
            } else {
                *(FormationPosition *)&scratch.position =
                    ((FormationPosition *)D_00609430)[index & 0xffff];
            }
            btlTargetPositionToCell(&current->unk_94,
                          &current->unk_96,
                          scratch.position.values);
            scratch.position.values[0] =
                (f32)((s32)current->unk_94 * 25 - 1750);
            scratch.positionZ =
                (f32)((s32)current->unk_96 * 25 - 1750);
            if (((BtlAction *)*actionWork)->unit != current) {
                RwV3dNormalize(scratch.delta, scratch.position.values);
                {
                    f32 scale;
                    scale = D_00609458[index & 0xffff];
                    scratch.delta[0] *= scale;
                    scratch.delta[1] *= scale;
                    scratch.delta[2] *= scale;
                    scratch.position.values[0] += scratch.delta[0];
                    scratch.position.values[1] += scratch.delta[1];
                    scratch.positionZ += scratch.delta[2];
                }
                index++;
            }
            btlUnitSetPos(current, scratch.position.values);
            btlUnitSetRot(current, D_0060A110);
        }
        current = current->prevUnit;
    }
    return 1;
}
#pragma pop
/* Create packet 0xB06 to assign grid slots around the supplied action. */
// FUN_001D3B50
u8 *btlFormationCreateActionPacket(u8 *action)
{
    u8 **work;
    u8 *packet;

    packet = (u8 *)btlPacketAlloc(0xb06, 4);
    ((BtlPacket *)packet)->updateFunc = (BtlPacketUpdateFunc)btlFormationAdvanceSlot;
    work = (u8 **)((BtlPacket *)packet)->workData;
    work[0] = action;
    return packet;
}
/* Restore the active actor anchor and distribute its party actions through rotated offsets. */
// FUN_001D3BA0
u32 btlFormationApplyDefaultPose(void)
{
    typedef struct FormationVectors {
        f32 offsets[3];
        u32 gap0;
        f32 transformed[3];
        u32 gap1;
        u8 padding[32];
        f32 base[3];
        u32 gap2;
        f32 result[3];
        u32 gap3;
    } FormationVectors;
    FormationVectors vectors;
    u16 index;
    u8 *node;
    f32 *offset;
    extern u8 D_00609470[];
    extern void RtQuatTransformVectors(void *out, const void *in, s32 count, const void *rot);

    node = (u8 *)((BtlAction *)((BtlBattleState *)D_0076449C)->selectedAction)->unit;
    btlUnitGetAnchorPose(node, vectors.base, vectors.offsets, NULL);
    btlUnitClearMoveFlags(node);
    btlUnitClearRotateFlags(node);
    btlUnitSetPos(node, vectors.base);
    btlUnitSetRot(node, vectors.offsets);
    RtQuatTransformVectors(vectors.transformed, D_00609470, 3, vectors.offsets);
    index = 0;
    while (index < ((BtlBattleState *)D_0076449C)->partyActionCount) {
        {
            u32 current;

            current = index;
            node = (u8 *)((BtlAction *)((BtlBattleState *)D_0076449C)->partyActions[current])->unit;
            offset = &vectors.transformed[current * 3];
        }
        vectors.result[0] = vectors.base[0] + offset[0];
        vectors.result[1] = vectors.base[1] + offset[1];
        vectors.result[2] = vectors.base[2] + offset[2];
        btlUnitClearMoveFlags(node);
        btlUnitClearRotateFlags(node);
        btlUnitSetPos(node, vectors.result);
        btlUnitSetRot(node, vectors.offsets);
        index++;
    }
    return 1;
}
/* Create packet 0xB07 for the active-action party pose restoration. */
// FUN_001D3D00
BtlPacket *btlFormationCreateEventPacket(u32 value)
{
    u32 *work;
    u32 packet;

    packet = (u32)btlPacketAlloc(0xb07, 4);
    ((BtlPacket *)packet)->updateFunc = (BtlPacketUpdateFunc)btlFormationApplyDefaultPose;
    work = (u32 *)((BtlPacket *)packet)->workData;
    work[0] = value;
    return (BtlPacket *)packet;
}
/* Allocate the 0x638-byte resource state with one reference; mode 2 enables deferred loading. */
// FUN_001D3D50
s32 btlFormationAllocWork(u32 mode)
{
    BtlFormationState *state;

    chkmemAllocSiteTag(&D_00609498, 0x3A);
    state = (BtlFormationState *)jtbl_008873E8[0](0x638, 0x40000);
    switch (mode & 0xffff) {
    case 0:
        state->flags = 0;
        break;
    case 1:
        state->flags = 0;
        break;
    case 2:
        state->flags = 8;
        break;
    }
    state->counter = 1;
    state->value = 0;
    return (s32)state;
}
/* Release a resource reference, unloading deferred effects at the reference-count boundary. */
// FUN_001D3E00
void btlFormationSetPlacement(u32 formation)
{
    BtlFormationState *state;

    state = (BtlFormationState *)formation;
    state->counter--;
    if (((state->flags & 8) != 0) && (state->counter == 1)) {
        btlFormationSetState((int)state);
    }
    if (state->counter == 0) {
        if ((state->flags & 2) != 0) {
            btlFormationSetState((int)state);
        }
        (*DAT_008873EC)(state);
    }
}


/* Copy two resource blocks and replace file offsets/references with live cloned or built effects. */
// FUN_001D3EA0
/* Declaring the resourceEntry alias after the original declarations keeps retail's store sequence. */
void btlFormationCopyRecord(int destination, u32 source)
{

    u16 outer;
    u16 index;
    s32 count;
    u8* entry;
    int block;
    u8* referencedEntry;
    u32 packed;
    u32 resource;
    u32 continueLoop;

    BtlFormationResourceEntry *resourceEntry;

    memcpy(destination, source, 0x630);
    outer = 0;
    while ((s32)(continueLoop = outer) < 2) {
        block = destination + (outer & 0xffff) * 0x314;
        count = ((BtlFormationResourceBlock *)block)->entryCount;
        entry = (u8 *)(block + 0x1c);
        resourceEntry = (BtlFormationResourceEntry *)entry;
        for (index = 0; index < count; index++) {
            if (entry[0] != 0xfe) {
                if (entry[0] == 0xff) {
                    packed = ((BtlFormationResourceEntry *)entry)->resource;
                    referencedEntry = (u8 *)(destination + (packed >> 5) * 0x314 +
                                             (packed & 0x1f) * 0x18 + 0x1c);
                    resource = (u32)mdlEffectCloneWithNodes((u8 *)((BtlFormationResourceEntry *)referencedEntry)->resource);
                    entry[0] = referencedEntry[0];
                } else {
                    resource = (u32)mdlEffectBuildFromResource((u8 *)(source + ((BtlFormationResourceEntry *)entry)->resource));
                }
                resourceEntry->resource = resource;
            }
            entry += 0x18;
            resourceEntry = (BtlFormationResourceEntry *)entry;
        }
        outer++;
    }
    ((BtlFormationState *)destination)->flags |= 2;
}


/* Destroy owning entries in both resource blocks and clear the loaded flag. */
// FUN_001D3FF0
void btlFormationSetState(int state)
{
    u16 outer;
    u16 index;
    int count;
    u8 *entry;
    int block;
    u32 continueLoop;

    outer = 0;
    while ((s32)(continueLoop = outer) < 2) {
        block = state + (outer & 0xffff) * 0x314;
        count = ((BtlFormationResourceBlock *)block)->entryCount;
        entry = (u8 *)(block + 0x1c);
        index = 0;
        while (index < count) {
            if (*entry != 0xfe && *entry != 0xfd) {
                mdlEffectDestroyWithNodes(((BtlFormationResourceEntry *)entry)->resource);
            }
            entry += 0x18;
            index++;
        }
        outer++;
    }
    ((BtlFormationState *)state)->flags &= 0xfffd;
}


/* Acquire a resource reference, instantiating deferred effects on the first additional reference. */
// FUN_001D40D0
void btlFormationCopyDefault(int formation)
{
    BtlFormationState *state;

    state = (BtlFormationState *)formation;
    state->counter++;
    if (((state->flags & 8) != 0) && (state->counter == 2)) {
        btlFormationCopyRecord(formation, state->value);
    }
}


/* Return whether the resource state has instantiated effects (flag 2), not an entry count. */
// FUN_001D4120
u32 btlFormationGetCount(void* formation)
{
    return (((BtlFormationState *)formation)->flags & 2) != 0;
}

/* Read the side-specific timing value; unsupported sides return zero. */
// FUN_001D4140
u32 btlFormationGetIndex(int formation, u16 side)
{
    u32 result;

    switch (side) {
    case 0:
        result = ((BtlFormationState *)formation)->blocks[0].unk08;
        break;
    case 1:
        result = ((BtlFormationState *)formation)->blocks[1].unk14;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}


/* Read the selected 0x314-byte resource block's duration word. */
// FUN_001D4190
u32 btlFormationGetEntry(void* formation, u32 index)
{
    u32 offset;

    offset = (index & 0xFFFF) * 0x314;
    return ((BtlFormationResourceBlock *)(offset + (u32)formation))->duration;
}

/* Destroy an allocated formation entry's effect instances, then release its work. */
// FUN_001D42E0
void btlFormationResetState(BtlFormationWork *work)
{
    s32 count;
    u16 index;
    u32 *items;

    count = work->count;
    items = (u32 *)(uintptr_t)work->items;
    index = 0;
    while (index < count) {
        if (*items != 0) {
            mdlEffectDestroyWithNodes(*items);
        }
        items++;
        index++;
    }
    (*DAT_008873EC)(work);
}


/* Derive and clamp an effect scale from the unit's scaled sphere dimensions. */
// FUN_001D4380
f32 btlFormationGetScale(int unit)
{
    f32 scale = 0;

    scale = fGpffff8354 * ((((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale +
            ((BtlUnit *)unit)->unk_8c * ((BtlUnit *)unit)->scale * 0.5f) * 0.5f);
    if (scale > 2.5f) {
        scale = 2.5f;
    }
    else if (scale < fGpffff811c) {
        scale = fGpffff811c;
    }
    return scale;
}


/* Translate descriptor presence words and flag halfwords into the runtime effect mask. */
// FUN_001D43F0
u32 btlFormationGetFlags(s32 record)
{
    u16 flags = 0;
    u32 result = 0;

    if (((BtlFormationDescriptor *)record)->unk08 != 0)
    {
        result |= 0x80;
    }
    if (((BtlFormationDescriptor *)record)->unk0C != 0)
    {
        result |= 1;
    }
    flags = ((BtlFormationDescriptor *)record)->flags;
    if ((flags & 0x400) != 0)
    {
        result |= 2;
    }
    if ((flags & 0x100) != 0)
    {
        result |= 4;
    }
    if ((flags & 4) != 0)
    {
        result |= 0x10;
    }
    if ((flags & 2) != 0)
    {
        result |= 8;
    }
    if ((((BtlFormationDescriptor *)record)->options & 2) != 0)
    {
        result |= 0x20;
    }
    if ((((BtlFormationDescriptor *)record)->options & 4) != 0)
    {
        result |= 0x40;
    }
    return result;
}

/* Record the source resource address for deferred instantiation. */
// FUN_001D4490
void btlFormationSetSlot(s32 formation, u32 resource)
{
    ((BtlFormationState *)formation)->value = resource;
}

/* Clear the four-component attachment-vector output; the context arguments are unused. */
// FUN_001D4E90
void btlFormationClearAttachVector(u8 *unusedOwner, u8 *unusedEntry, u8 *unusedUnit, f32 *vector) {
    vector[0] = 0.0f;
    vector[1] = 0.0f;
    vector[2] = 0.0f;
    vector[3] = 0.0f;
}

/* Create packet 0x400 with an inline resource-path copy for the BED loader. */
// FUN_001D5EB0
BtlPacket *btlFormationCreateNamedPacket(u32 resource, const char *path, u16 mode)
{
    typedef struct FormationStringWork {
        u32 value;
        u32 unused;
        char *text;
        u16 field;
        u16 padding;
    } FormationStringWork;
    BtlPacket *packet;
    FormationStringWork *work;

    packet = btlPacketAlloc(0x400, strlen(path) + sizeof(FormationStringWork));
    packet->flags &= 0xfe;
    packet->initFunc = (BtlPacketFunc)btlBedCopyRecord;
    packet->updateFunc = (BtlPacketUpdateFunc)btlBedLoad;
    work = packet->workData;
    work->value = resource;
    work->text = (char *)(work + 1);
    work->field = mode;
    strcpy(work->text, path);
    return packet;
}


/* Acquire the formation and both units, then allocate the selected unit's effect-pool node. */
// FUN_001D5F60
void btlFormationRefresh(u32 *work)
{
    s16 mode;

    work[6] = 0;
    btlFormationCopyDefault(work[0]);
    ((BtlUnit *)work[1])->pendingPacketCount = ((BtlUnit *)work[1])->pendingPacketCount + 1;
    ((BtlUnit *)work[2])->pendingPacketCount = ((BtlUnit *)work[2])->pendingPacketCount + 1;
    mode = (s16)((BtlFormationEffectWork *)work)->side;
    switch (mode) {
    case 0:
        work[5] = ((BtlFormationUnitResources *)((BtlUnit *)work[1])->unk_a04)->effectKey;
        break;
    case 1:
        work[5] = ((BtlFormationUnitResources *)((BtlUnit *)work[2])->unk_a04)->effectKey;
        break;
    }
    work[4] = btlEffectAllocEntry(work[5]);
}
/* Advance effect timing by two and create the runtime formation entry before fading it out. */
// FUN_001D6010
/* measured: propagation off keeps retail's order of loading the index argument before the value
 * argument. */
#pragma opt_propagation off
/* Separate typed aliases and signed member reads reproduce retail where direct field access does
 * not. */
u32 btlFormationIsReady(u32 *work)
{
    BtlFormationEffectWork *effectWork = (BtlFormationEffectWork *)work;

    s16 side;
    u16 *effect;
    int duration;
    u16 functionIndex;
    u32 sourceUnit;
    u32 targetUnit;

    if (!btlFormationGetCount(*(u8 **)work)) {
        return 0;
    }
    effect = (u16 *)work[4];
    if ((((BtlEffectNode *)effect)->color & 0xff000000) == 0) {
        return 1;
    }
    functionIndex = effectWork->side;
    duration = btlFormationGetIndex(work[functionIndex & 0], functionIndex);
    if ((*effect & 0x40) == 0) {
        if ((int)work[6] >= duration * 2 - 0xd) {
            *effect = *effect | 0x100;
            return 0;
        }
        if (work[6] == 0) {
            u32 flags = work[7];

            if ((flags & 0xc00) != 0xc00) {
                side = (s16)((BtlFormationEffectWork *)work)->side;
                switch (side) {
                case 0:
                    sourceUnit = work[1];
                    targetUnit = work[2];
                    break;
                case 1:
                    sourceUnit = work[2];
                    targetUnit = work[1];
                    break;
                }
                *(u32 *)&((BtlEffectNode *)effect)->formation =
                    (u32)btlFormationAllocEntry((u8 *)work[0], side & 0xffff,
                                       sourceUnit, targetUnit, flags);
                *effect = *effect | 0x30;
            }
        }
        work[6] = work[6] + 2;
    }
    return 0;
}
#pragma opt_propagation on
// measured: opt_propagation off keeps retail's index-before-value argument-load order; plain C
// loads them in the opposite order.
// FUN_001D6170
/* Report when the elapsed two-frame count reaches the selected resource duration. */
/* The index & 0 address term preserves the existing index-before-value evaluation shape under
 * opt_propagation off; do not simplify it. */
u8 btlFormationHasEntry(u32 *work)
{
    int duration;
    u16 index;
    u8 *value;

    if (!btlFormationGetCount(*(u8 **)work)) {
        return 0;
    }
    duration = (index = ((BtlFormationEffectWork *)work)->side,
             value = (u8 *)((BtlFormationEffectWork *)((u8 *)work + ((u32)index & 0)))->formation,
             btlFormationGetEntry(value, index));
    duration <<= 1;
    if (duration < 1) {
        duration = 2;
    }
    return duration <= (int)work[6];
}


/* Release the effect-pool node, formation reference and both unit packet references. */
// FUN_001D61E0
void btlFormationRelease(u32 *work)
{
    btlEffectFreeEntry(work[5], (u16 *)work[4]);
    btlFormationSetPlacement(*(int *)work);
    ((BtlUnit *)work[1])->pendingPacketCount = ((BtlUnit *)work[1])->pendingPacketCount + -1;
    ((BtlUnit *)work[2])->pendingPacketCount = ((BtlUnit *)work[2])->pendingPacketCount + -1;
}


/* Create packet 0x301 with formation lifecycle callbacks and its two unit addresses. */
// FUN_001D6240
BtlPacket* btlFormationCreatePacket(u32 formation, u32 sourceUnit, u32 targetUnit, u16 side, u32 flags)
{
    u32 *work;
    u32 packet;

    packet = (u32)btlPacketAlloc(0x301, 0x20);
    ((BtlPacket *)packet)->flags = ((BtlPacket *)packet)->flags & 0xef;
    ((BtlPacket *)packet)->initFunc = (BtlPacketFunc)btlFormationRefresh;
    ((BtlPacket *)packet)->updateFunc = (BtlPacketFunc)btlFormationIsReady;
    /* The optional condition callback is the packet completion predicate. */
    ((BtlPacket *)packet)->conditionFunc = (s32 (*)(u8 *))btlFormationHasEntry;
    ((BtlPacket *)packet)->destroyFunc = (BtlPacketFunc)btlFormationRelease;
    work = (u32 *)((BtlPacket *)packet)->workData;
    work[0] = formation;
    work[1] = sourceUnit;
    work[2] = targetUnit;
    ((BtlFormationEffectWork *)work)->side = side;
    work[7] = flags;
    return (BtlPacket*)packet;
}


/* Format the resource path selected by the battle resource-mode flag. */
// FUN_001D69F0
void btlFormationFormatName(u32 value, char *destination)
{
    if ((((BtlBattleState *)DAT_0076449c)->resourceFlags & 1) != 0)
    {
        sprintf(destination, D_00609570);
    }
    else
    {
        sprintf(destination, D_00609588, &D_00763388, (u16)value);
    }
}


/* Forward three stored arguments to the formation helper, then complete the packet. */
// FUN_001D7BB0
u32 btlFormationDispatchArgs(u32* args)
{
    mdlSetFileStateTriple(args[0], args[1], args[2]);
    return 1;
}


/* Create the zero-work 0x50D packet that starts the battle UI sequence. */
// FUN_002027E0
u8 *btlFormationCreateDefaultPacket(void)
{
    u8 *task;

    task = (u8 *)btlPacketAlloc(0x50d, 0);
    ((BtlPacket *)task)->updateFunc = (BtlPacketFunc)btlUiBeginSequence;
    return task;
}

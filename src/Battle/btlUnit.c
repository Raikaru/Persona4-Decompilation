#include "member_access.h"
#include "btl_unit_packet_internal.h"
#include "btl_unit_record_internal.h"
#include "mdl_file_internal.h"
#include "btl_target_internal.h"
#include "btl_effect_internal.h"
#include "btl_action_internal.h"
#include "btl_motion_internal.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "btl_unit_internal.h"

/* Two filter words occupy separate sixteen-byte scratch slots in the
 * group-bounds frame; keep the original 0x20-byte extent. */
typedef struct BtlUnitBoundsFilters {
    s32 useGrid;
    u8 pad04[12];
    s32 excludeDead;
    u8 pad14[12];
} BtlUnitBoundsFilters;

extern u16 btlFindFreeCharResId(void);

extern void mdlDestroyModelObject(); /* old-style: retail jals with $a1 still holding the compared coordinate */
extern void *mdlFindModelObject(u32 type, u16 id, u32 flags);
extern void *mdlCreateModelObjectFromResource(u32 type, u16 id, void *resourceOrModel, u32 flags);
extern u32 *mdlCloneModelObject(u8 *source);
extern s32 mdlBuildModelPath(u32 type, u16 id, char *output);
extern void func_00440b68(void *, u8 *, s32);
extern s32 H_Cdvd_AcquireDirectory(void *path, s32 flags);
extern s32 mdlComputeIndexedAttachMatrix(void *model, s32 index, void *destination);
extern f32 fGpffff82d4;
extern u8 D_005F6D00[];
extern u8 iGpffffa0b0;
extern void btlUnitGetAnchorPose(void *unit, void *outPosition, s32 outRotation, void *outTarget);
extern void func_003dc740(void *dst, void *src, f32 angle, s32 mode);
#define func_003dc740(dst, src, mode, angle) \
    func_003dc740(dst, src, angle, mode)
extern f32 func_0044b950(f32 left, f32 right);
extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern void btlUnitRequestLookAt(void *unit);
extern f32 func_003e41e0(f32 *out, f32 *in);
extern void btlUnitShowModel(u8 *unit);
extern void btlUnitHideModel(u8 *unit);
extern f32 RwV2dLength(f32 *value);
extern s32 fptodp(f32 value);
extern s32 func_0044b310(s32 value);
extern f32 dptofp(s32 value);
extern f32 D_007614c0;
#include "include_asm.h"
#define BTLUNIT_FLAG2_DIRTY (1 << 2)
#define BTLUNIT_FLAG3_NOROT (1 << 13)
#define BTLUNIT_FLAG3_MODEL_HIDDEN (1 << 12)
/* Unit kind stored at +0xA2 and passed to btlUnitCreate: 0 party, 1 enemy,
 * 2 child unit created by btlUnitInitChild. */
#define BTLUNIT_KIND_CHILD 2

extern RwV3d D_0060A0F0;


typedef struct BtlUnitPacketMove BtlUnitPacketMove;
struct BtlUnitPacketMove
{
    BtlUnit* unit;
    RwV3d targetPos;
    u32 flags;
    u16 state;
    u8 _pad16[2];
    u32 timer;
    f32 unk_1c;
    f32 speed;
};

typedef struct BtlUnitPacketPosRotCol BtlUnitPacketPosRotCol;
struct BtlUnitPacketPosRotCol
{
    BtlUnit* unit;
    RwV3d pos;
    RtQuat rot;
    RwRGBA col;
    u16 flags;
};

typedef struct BtlUnitPacketCountRef BtlUnitPacketCountRef;
struct BtlUnitPacketCountRef
{
    u8 _pad00[0x24];
    BtlUnit* unit;
};

typedef struct BtlUnitPacketPair BtlUnitPacketPair;
struct BtlUnitPacketPair
{
    BtlUnit* first;
    BtlUnit* second;
    u32 flags;
    s32 timer;
};

typedef struct BtlUnitPacketUnitAtC BtlUnitPacketUnitAtC;
struct BtlUnitPacketUnitAtC
{
    u8 _pad00[0xc];
    BtlUnit* unit;
};

typedef struct BtlUnitPacketTwoUnits BtlUnitPacketTwoUnits;
struct BtlUnitPacketTwoUnits
{
    BtlUnit* first;
    BtlUnit* second;
    u16 flags;
    u8 _pad06[2];
};

typedef struct BtlUnitStateWork BtlUnitStateWork;
struct BtlUnitStateWork
{
    u8 _pad00[0xa2];
    u8 state;
    u8 _padA3[9];
    u8 value;
};


typedef struct BtlUnitPacketMoveToUnit BtlUnitPacketMoveToUnit;
struct BtlUnitPacketMoveToUnit
{
    BtlUnit* unit;
    RwV3d targetPos;
    u32 flags;
    u8 _pad14[4];
    u32 timer;
    f32 unk_1c;
    f32 speed;
    BtlUnit* targetUnit;
};
typedef struct BtlUnitAnimBounds BtlUnitAnimBounds;
struct BtlUnitAnimBounds
{
    s16 centerX;
    s16 centerY;
    s16 centerZ;
    u16 unk_6;
    u16 radius;
};
u8* btlUnitGetRecordPtr(u8* unit, s32 motion);


BtlPacket* btlPacketAlloc(u32 packetType, s32 workSize);
RwV3d* RtQuatTransformVectors(RwV3d* vectorsOut, const RwV3d* vectorsIn,
                     s32 numPoints, const void* quat);
void btlTargetBlendVectors(RwV3d* rotation, const RwV3d* first, const RwV3d* second);
extern s32 datCalcIsDead(void *unit, s32 hpDelta);
extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
extern f32 RwV3dLength(RwV3d *value);
extern u8 *iGpffffb3ac;
extern RwV3d D_00881430;
void btlUnitHoldPendingMove(BtlUnitPacketMove* packetWork);
u32 btlUnitMovePacketUpdate(void* workData);
void btlUnitReleasePendingMove(BtlUnitPacketMove* packetWork);
void btlUnitHoldPendingPacket(BtlUnitPacketCountRef* packet);
u32 btlUnitMoveToUnitPacketUpdate(BtlUnitPacketMoveToUnit* packet);
void btlUnitReleasePendingPacket(BtlUnitPacketCountRef* packet);

/* Transform animation bounds toward another unit and translate the center to world coordinates. */
// FUN_00195B60
void btlUnitGetAnimBoundsWorldCenterTowardUnit(u8 *context, s32 value, u8 *option)
{
    struct Btl95Work {
        RwV3d rotation;
        f32 pad3c;
        RwV3d transformed;
        f32 pad4c;
        RwV3d scaled;
    } work;
    BtlUnitAnimBounds *bounds;
    f32 centerY;
    f32 centerZ;
    f32 centerX;
    RwV3d *out;

    btlTargetBlendVectors(&work.rotation, (RwV3d *)(context + 4), (RwV3d *)((u8 *)value + 4));
    bounds = (BtlUnitAnimBounds *)btlUnitGetRecordPtr(context, 0xA);
    centerY = (f32)bounds->centerY;
    centerZ = (f32)bounds->centerZ;
    centerX = (f32)bounds->centerX;
    work.scaled.x = centerX * ((BtlUnit *)context)->scale;
    work.scaled.y = centerY * ((BtlUnit *)context)->scale;
    work.scaled.z = centerZ * ((BtlUnit *)context)->scale;
    RtQuatTransformVectors(&work.transformed, &work.scaled, 1, &work.rotation);
    out = (RwV3d *)option;
    out->x = work.transformed.x + ((BtlUnit *)context)->pos.x;
    out->y = work.transformed.y + ((BtlUnit *)context)->pos.y;
    out->z = work.transformed.z + ((BtlUnit *)context)->pos.z;
}
/* measured: plain-C aggregate reconstruction reproduces every retail
   instruction; the object is 324B against the 336B window, with three retail
   trailing nop words left as window padding. */
/* Use the attached model center when available, otherwise transform the unit sphere center. */
// FUN_00195D50
void btlUnitGetAttachedSphereCenter(u8 *context, u8 *value)
{
    struct Btl95DWork {
        RwV3d secondOut;
        f32 pad0;
        RwV3d secondScaled;
        f32 pad1;
        RwV3d firstOut;
        f32 pad2;
        RwV3d firstScaled;
        f32 pad3;
    } work;
    RwV3d *out;

    out = (RwV3d *)value;
    if ((((BtlUnit *)context)->flags2 & 2) == 0)
    {
        work.firstScaled.x = ((BtlUnit *)context)->sphereCenter.x * ((BtlUnit *)context)->scale;
        work.firstScaled.y = ((BtlUnit *)context)->sphereCenter.y * ((BtlUnit *)context)->scale;
        work.firstScaled.z = ((BtlUnit *)context)->sphereCenter.z * ((BtlUnit *)context)->scale;
        RtQuatTransformVectors(&work.firstOut, &work.firstScaled, 1,
                      (RwV3d *)(context + 0x1C));
        out->x = work.firstOut.x + ((BtlUnit *)context)->pos.x;
        out->y = work.firstOut.y + ((BtlUnit *)context)->pos.y;
        out->z = work.firstOut.z + ((BtlUnit *)context)->pos.z;
        return;
    }
    if (mdlComputeIndexedAttachMatrix((void *)((BtlUnit *)context)->layerHandle, 0, value) == 0)
    {
        work.secondScaled.x = ((BtlUnit *)context)->sphereCenter.x * ((BtlUnit *)context)->scale;
        work.secondScaled.y = ((BtlUnit *)context)->sphereCenter.y * ((BtlUnit *)context)->scale;
        work.secondScaled.z = ((BtlUnit *)context)->sphereCenter.z * ((BtlUnit *)context)->scale;
        RtQuatTransformVectors(&work.secondOut, &work.secondScaled, 1,
                      (RwV3d *)(context + 0x1C));
        out->x = work.secondOut.x + ((BtlUnit *)context)->pos.x;
        out->y = work.secondOut.y + ((BtlUnit *)context)->pos.y;
        out->z = work.secondOut.z + ((BtlUnit *)context)->pos.z;
    }
}

/* Compute a filtered group center, vertical extents, and enclosing horizontal radius. */
/* measured: three filter/data-unit accesses changed MATCH as fields, typed aliases, and indexed fields; MEMBER preserves those reloads. */
// FUN_00196040
f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter,
                  f32 *outTop, f32 *outBottom, u32 options)
{
    BtlUnit *firstUnitFields;
    RwV3d center;
    RwV3d sum;
    RwV3d delta;
    RwV3d firstScaled;
    RwV3d firstRotated;
    RwV3d secondScaled;
    RwV3d secondRotated;
    u8 filters[32];
    f32 radius;
    f32 top;
    f32 bottom;
    u8 *firstUnit;
    u8 *singleUnit;
    u32 group;
    u32 count;
    u32 mask;
    u32 optionFlags;

    top = 0.0f;
    bottom = (f32)100000000;
    singleUnit = 0;
    count = 0;
    sum = D_00881430;
    group = 0;
    mask = groupFlags & 0xFFFF;
    optionFlags = options & 0xFFFF;
    ((BtlUnitBoundsFilters *)filters)->excludeDead = optionFlags & 2;
    ((BtlUnitBoundsFilters *)filters)->useGrid = optionFlags & 1;
    while (group < 4)
    {
        if (mask & (1 << group))
        {
            firstUnit =
                ((BtlBattleState *)iGpffffb3ac)->unitLists[group * 2];
            firstUnitFields = (BtlUnit *)firstUnit;
            while (firstUnit != 0)
            {
                u32 flags = ((BtlUnit *)firstUnit)->flags3;

                if ((flags & 8) &&
                    !(flags & excludedFlags) &&
                    (!MEMBER(s32, filters, BtlUnitBoundsFilters, excludeDead) ||
                     group != 0 ||
                     (datCalcIsDead((void *)((BtlUnit *)firstUnit)->datUnit, 0) == 0 &&
                      datCalcChkBadStatus((s32)firstUnitFields->datUnit, 0x100117) == 0)))
                {
                    f32 x;
                    f32 y;
                    f32 z;
                    f32 extent;
                    if (!((BtlUnitBoundsFilters *)filters)->useGrid)
                    {
                        firstScaled.x =
                            ((BtlUnit *)firstUnit)->sphereCenter.x *
                                ((BtlUnit *)firstUnit)->scale;
                        firstScaled.y =
                            ((BtlUnit *)firstUnit)->sphereCenter.y *
                                ((BtlUnit *)firstUnit)->scale;
                        firstScaled.z =
                            ((BtlUnit *)firstUnit)->sphereCenter.z *
                                ((BtlUnit *)firstUnit)->scale;
                        RtQuatTransformVectors(&firstRotated, &firstScaled, 1,
                                      (RwV3d *)(firstUnit + 0x1C));
                        x = firstRotated.x + ((BtlUnit *)firstUnit)->pos.x;
                        y = firstRotated.y + ((BtlUnit *)firstUnit)->pos.y;
                        z = firstRotated.z + ((BtlUnit *)firstUnit)->pos.z;
                    }
                    else
                    {
                        x = (f32)(25 * ((BtlUnit *)firstUnit)->unk_94 - 1750);
                        y = ((BtlUnit *)firstUnit)->pos.y +
                            ((BtlUnit *)firstUnit)->sphereCenter.y *
                                ((BtlUnit *)firstUnit)->scale;
                        z = (f32)(25 * ((BtlUnit *)firstUnit)->unk_96 - 1750);
                    }
                    sum.x += x;
                    sum.y += y;
                    sum.z += z;
                    extent = y +
                             0.5f *
                                 (((BtlUnit *)firstUnit)->unk_8c *
                                  firstUnitFields->scale);
                    if (top < extent)
                        top = extent;
                    if (bottom > extent)
                        bottom = extent;
                    singleUnit = firstUnit;
                    count += 1;
                }
                firstUnit = (u8 *)((BtlUnit *)firstUnit)->nextUnit;
                firstUnitFields = (BtlUnit *)firstUnit;
            }
        }
        group += 1;
    }
    if (count == 0)
        return 0.0f;

    if (count == 1)
    {
        f32 extent;
        center = sum;
        radius = ((BtlUnit *)singleUnit)->sphereRadius *
                 ((BtlUnit *)singleUnit)->scale;
        extent = 0.5f *
                 (((BtlUnit *)singleUnit)->unk_8c *
                  ((BtlUnit *)singleUnit)->scale);
        if (extent > radius)
            radius = extent;
    }
    else
    {
        f32 inverse;
        f32 centerY;
        f32 centerZ;
        u32 secondGroup;

        inverse = 1.0f / (f32)count;

        center.x = sum.x * inverse;
        centerY = sum.y * inverse;
        center.y = centerY;
        centerZ = sum.z * inverse;
        center.z = centerZ;
        radius = 0.0f;
        secondGroup = 0;
        while (secondGroup < 4)
        {
            if (mask & (1 << secondGroup))
            {
                u8 *unit;
                unit = ((BtlBattleState *)iGpffffb3ac)->unitLists[secondGroup * 2];
                while (unit != 0)
                {
                    u32 flags = ((BtlUnit *)unit)->flags3;

                    if ((flags & 8) &&
                        !(flags & excludedFlags) &&
                        (!MEMBER(s32, filters, BtlUnitBoundsFilters, excludeDead) ||
                         secondGroup != 0 ||
                         (datCalcIsDead((void *)((BtlUnit *)unit)->datUnit, 0) == 0 &&
                          datCalcChkBadStatus(MEMBER(s32, unit, BtlUnit, datUnit), 0x100117) == 0)))
                    {
                        f32 x;
                        f32 z;
                        f32 extent;
                        if (!((BtlUnitBoundsFilters *)filters)->useGrid)
                        {
                            secondScaled.x =
                                ((BtlUnit *)unit)->sphereCenter.x * ((BtlUnit *)unit)->scale;
                            secondScaled.y =
                                ((BtlUnit *)unit)->sphereCenter.y * ((BtlUnit *)unit)->scale;
                            secondScaled.z =
                                ((BtlUnit *)unit)->sphereCenter.z * ((BtlUnit *)unit)->scale;
                            RtQuatTransformVectors(&secondRotated, &secondScaled, 1,
                                          (RwV3d *)(unit + 0x1C));
                            x = secondRotated.x + ((BtlUnit *)unit)->pos.x;
                            z = secondRotated.z + ((BtlUnit *)unit)->pos.z;
                        }
                        else
                        {
                            x = (f32)(25 * ((BtlUnit *)unit)->unk_94 - 1750);
                            z = (f32)(25 * ((BtlUnit *)unit)->unk_96 - 1750);
                        }
                        delta.x = x - center.x;
                        delta.y = centerY - centerY;
                        delta.z = z - centerZ;
                        extent = RwV3dLength(&delta);
                        extent += ((BtlUnit *)unit)->sphereRadius *
                                  ((BtlUnit *)unit)->scale;
                        if (extent > radius)
                            radius = extent;
                        count += 1;
                    }
                    unit = (u8 *)((BtlUnit *)unit)->nextUnit;
                }
            }
            secondGroup += 1;
        }
    }
    if (outCenter != 0)
        *outCenter = center;
    if (outTop != 0)
        *outTop = top;
    if (outBottom != 0)
        *outBottom = bottom;
    return radius;
}
/* Advance the XZ route and rotate toward the next point, respecting stopping distance and rotation locks. */
/* measured: access-site fields moved some movement-state instructions; separate typed aliases retain the byte-identical route and facing update. */
// FUN_00196610
u32 btlUnitUpdateFollowPath(u8 *context)
{
    BtlUnit *contextFields = (BtlUnit *)context;
    struct Btl966XZ
    {
        f32 x;
        f32 z;
    };
    struct Btl966Work
    {
        RtQuat rotation;
        f32 pad10;
        f32 pad14;
        f32 currentX;
        f32 currentZ;
        f32 deltaX;
        f32 deltaZ;
        f32 nextDeltaX;
        f32 nextDeltaZ;
    } frame;
    RwV3d finalPos;
    RwV3d targetPos;
    u8 *entry;
    u8 *point;
    s32 index;
    s32 count;
    s32 pointOffset;
    f32 pathLength;
    f32 lastDistance;
    f32 nextX;
    f32 nextZ;
    f32 currentZ;
    f32 turn;
    f32 angle;

    if ((((BtlUnit *)context)->movementFlags & 1) &&
        (((BtlUnit *)context)->movementFlags & 0x10))
    {
        entry = context + 0xEC;
        index = ((BtlTargetRoute *)(context + 0xEC))->cursor;
        count = ((BtlTargetRoute *)(context + 0xEC))->count;
        lastDistance = 0.0f;
        pathLength = ((BtlUnit *)context)->moveSpeed;
        frame.currentX = ((BtlUnit *)context)->pos.x;
        frame.currentZ = ((BtlUnit *)context)->pos.z;
        while (index < count - 1)
        {
            pathLength -= lastDistance;
            point = entry + (index * 8) + 8;
            frame.deltaX = ((BtlTargetPoint *)point)[0].x - frame.currentX;
            frame.deltaZ = ((BtlTargetPoint *)point)[0].z - frame.currentZ;
            lastDistance = func_003e41e0(&frame.deltaX, &frame.deltaX);
            if (lastDistance < pathLength)
            {
                *(struct Btl966XZ *)&frame.currentX =
                    *(struct Btl966XZ *)point;
                index += 1;
            }
            else
            {
                break;
            }
        }
        if (((BtlUnit *)context)->stateFlags & 1)
            index = count - 1;
        if (index < count - 1)
        {
            frame.nextDeltaX = frame.deltaX * pathLength;
            frame.nextDeltaZ = frame.deltaZ * pathLength;
            nextX = frame.currentX + frame.nextDeltaX;
            currentZ = frame.currentZ;
            nextZ = currentZ + frame.nextDeltaZ;
            pointOffset = count * 8;
            point = (u8 *)(pointOffset + (u32)entry);
            frame.nextDeltaX = frame.currentX - ((BtlTargetPoint *)point)[-1].x;
            frame.nextDeltaZ = currentZ - ((BtlTargetPoint *)point)[-1].z;
            lastDistance = RwV2dLength(&frame.nextDeltaX);
            if (lastDistance < ((BtlUnit *)context)->stoppingDistance)
            {
                lastDistance = (lastDistance + pathLength) -
                               ((BtlUnit *)context)->stoppingDistance;
                frame.nextDeltaX = frame.deltaX * lastDistance;
                frame.nextDeltaZ = frame.deltaZ * lastDistance;
                nextX = frame.currentX + frame.nextDeltaX;
                nextZ = currentZ + frame.nextDeltaZ;
                contextFields->stateFlags &= ~1;
                contextFields->movementFlags &= 0xFFFE;
                contextFields->movementFlags &= 0xFFEF;
            }
            finalPos.x = nextX;
            finalPos.y = ((BtlUnit *)context)->pos.y;
            finalPos.z = nextZ;
            frame.currentX = nextX + frame.deltaX;
            frame.currentZ = nextZ + frame.deltaZ;
            targetPos.x = frame.currentX;
            targetPos.y = finalPos.y;
            targetPos.z = frame.currentZ;
        }
        else
        {
            point = entry + (index * 8);
            finalPos.x = ((BtlTargetPoint *)point)[0].x;
            finalPos.y = ((BtlUnit *)context)->pos.y;
            finalPos.z = ((BtlTargetPoint *)point)[0].z;
            targetPos = finalPos;
            contextFields->stateFlags &= ~1;
            ((BtlUnit *)context)->movementFlags &= 0xFFFE;
            ((BtlUnit *)context)->movementFlags &= 0xFFEF;
        }
        contextFields->pos = finalPos;
        ((BtlUnit *)context)->flags2 |= 4;
        ((BtlTargetRoute *)entry)->cursor = index;
        if (!(contextFields->stateFlags & 0x100))
        {
            ((BtlUnit *)context)->rotationTarget = targetPos;
        }
        else
        {
            ((BtlUnit *)context)->rotationTarget = ((BtlUnit *)context)->fixedFacingTarget;
        }
        contextFields->movementFlags |= 2;
    }
    if (contextFields->movementFlags & 2)
    {
        targetPos.x = ((BtlUnit *)context)->rotationTarget.x - ((BtlUnit *)context)->pos.x;
        targetPos.z = ((BtlUnit *)context)->rotationTarget.z - ((BtlUnit *)context)->pos.z;
        if (((targetPos.x != 0.0f) ||
             (targetPos.z != 0.0f)) &&
            !(((BtlUnit *)context)->flags3 & 0x2000))
        {
            turn = fGpffff8048 *
                   func_0044b950(targetPos.x, targetPos.z);
            RtQuatTransformVectors(&targetPos, &D_0060A0F0, 1,
                          (RwV3d *)(context + 0x1C));
            angle = fGpffff8048 *
                    func_0044b950(targetPos.x, targetPos.z);
            nextZ = turn - angle;
            lastDistance =
                dptofp(func_0044b310(fptodp(nextZ)));
            if ((lastDistance > D_007614c0) &&
                !(((BtlUnit *)context)->stateFlags & 2))
            {
                if (lastDistance > 180.0f)
                {
                    if (nextZ > 0.0f)
                        nextZ -= 360.0f;
                    else
                    {
                        angle = 360.0f + nextZ;
                        nextZ = angle;
                    }
                }
                nextZ /= ((BtlUnit *)context)->turnDivisor;
                frame.rotation = ((BtlUnit *)context)->rot;
                func_003dc740(&frame.rotation, D_0060A0E0, 2, nextZ);
            }
            else
            {
                angle = turn;
                func_003dc740(&frame.rotation, D_0060A0E0, 0, angle);
                ((BtlUnit *)context)->stateFlags &= ~2;
                contextFields->movementFlags &= 0xFFFD;
            }
            if (!(contextFields->flags3 & 0x2000))
            {
                ((BtlUnit *)context)->rot = frame.rotation;
                ((BtlUnit *)context)->flags2 |= 4;
            }
        }
        else
        {
            ((BtlUnit *)context)->stateFlags &= ~2;
            contextFields->movementFlags &= 0xFFFD;
        }
    }
    return 0;
}
/* Initialize a move destination relative to another unit, then run the normal move-packet update. */
// FUN_001974F0
u32 btlUnitMoveToUnitPacketUpdate(BtlUnitPacketMoveToUnit* packet)
{
    struct Btl974Work
    {
        RwV3d rotateB;
        f32 pad3c;
        RwV3d rotateA;
        f32 pad4c;
        RwV3d rotate;
        f32 pad5c;
        RwV3d transformedF;
        f32 pad6c;
        RwV3d scaleF;
        f32 pad7c;
        RwV3d transformedE;
        f32 pad8c;
        RwV3d scaleE;
        f32 pad9c;
        RwV3d transformedD;
        f32 padAc;
        RwV3d scaleD;
        f32 padBc;
        RwV3d transformedC;
        f32 padCc;
        RwV3d scaleC;
        f32 padDc;
        RwV3d transformedB;
        f32 padEc;
        RwV3d scaleB;
        f32 padFc;
        RwV3d transformedA;
        f32 pad10c;
        RwV3d scaleA;
        f32 pad11c;
        RwV3d positionB;
        f32 pad12c;
        RwV3d finalRotation;
        f32 pad13c;
        RwV3d positionA;
    } frame;
    BtlUnit* target;
    const BtlUnitAnimBounds* bounds;
    f32 centerY;
    f32 centerZ;
    f32 centerX;

    if (packet->timer == 0)
    {
        target = packet->targetUnit;
        if ((target->flags3 & 0x2000) == 0)
        {
            if ((packet->flags & 0x40) == 0)
            {
                btlTargetBlendVectors(&frame.rotateA, &target->pos, &packet->unit->pos);
                frame.scaleA.x = target->sphereCenter.x * target->scale;
                frame.scaleA.y = target->sphereCenter.y * target->scale;
                frame.scaleA.z = target->sphereCenter.z * target->scale;
                RtQuatTransformVectors(&frame.transformedA, &frame.scaleA, 1,
                              &frame.rotateA);
                frame.positionA.x = frame.transformedA.x + target->pos.x;
                frame.positionA.y = frame.transformedA.y + target->pos.y;
                frame.positionA.z = frame.transformedA.z + target->pos.z;
            }
            else
            {
                btlTargetBlendVectors(&frame.rotateB, &target->pos, &packet->unit->pos);
                bounds = (const BtlUnitAnimBounds *)btlUnitGetRecordPtr((u8 *)target, 0);
                centerY = (f32)bounds->centerY;
                centerZ = (f32)bounds->centerZ;
                centerX = (f32)bounds->centerX;
                frame.scaleB.x = centerX * target->scale;
                frame.scaleB.y = centerY * target->scale;
                frame.scaleB.z = centerZ * target->scale;
                RtQuatTransformVectors(&frame.transformedB, &frame.scaleB, 1,
                              &frame.rotateB);
                frame.positionA.x = frame.transformedB.x + target->pos.x;
                frame.positionA.y = frame.transformedB.y + target->pos.y;
                frame.positionA.z = frame.transformedB.z + target->pos.z;
            }
            packet->targetPos = frame.positionA;
            goto finish;
        }

        if ((packet->flags & 0x40) == 0)
        {
            frame.scaleC.x = target->sphereCenter.x * target->scale;
            frame.scaleC.y = target->sphereCenter.y * target->scale;
            frame.scaleC.z = target->sphereCenter.z * target->scale;
            RtQuatTransformVectors(&frame.transformedC, &frame.scaleC, 1,
                          (RwV3d *)((u8 *)target + 0x1c));
            frame.positionA.x = frame.transformedC.x + target->pos.x;
            frame.positionA.y = frame.transformedC.y + target->pos.y;
            frame.positionA.z = frame.transformedC.z + target->pos.z;
        }
        else
        {
            bounds = (const BtlUnitAnimBounds *)btlUnitGetRecordPtr((u8 *)target, 0);
            centerY = (f32)bounds->centerY;
            centerZ = (f32)bounds->centerZ;
            centerX = (f32)bounds->centerX;
            frame.scaleD.x = centerX * target->scale;
            frame.scaleD.y = centerY * target->scale;
            frame.scaleD.z = centerZ * target->scale;
            RtQuatTransformVectors(&frame.transformedD, &frame.scaleD, 1,
                          (RwV3d *)((u8 *)target + 0x1c));
            frame.positionA.x = frame.transformedD.x + target->pos.x;
            frame.positionA.y = frame.transformedD.y + target->pos.y;
            frame.positionA.z = frame.transformedD.z + target->pos.z;
        }

        if ((packet->flags & 0x40) == 0)
        {
            target = packet->unit;
            frame.scaleE.x = target->sphereCenter.x * target->scale;
            frame.scaleE.y = target->sphereCenter.y * target->scale;
            frame.scaleE.z = target->sphereCenter.z * target->scale;
            RtQuatTransformVectors(&frame.transformedE, &frame.scaleE, 1,
                          (RwV3d *)((u8 *)target + 0x1c));
            frame.positionB.x = frame.transformedE.x + target->pos.x;
            frame.positionB.y = frame.transformedE.y + target->pos.y;
            frame.positionB.z = frame.transformedE.z + target->pos.z;
        }
        else
        {
            target = packet->unit;
            bounds = (const BtlUnitAnimBounds *)btlUnitGetRecordPtr((u8 *)target, 0);
            centerY = (f32)bounds->centerY;
            centerZ = (f32)bounds->centerZ;
            centerX = (f32)bounds->centerX;
            frame.scaleF.x = centerX * target->scale;
            frame.scaleF.y = centerY * target->scale;
            frame.scaleF.z = centerZ * target->scale;
            RtQuatTransformVectors(&frame.transformedF, &frame.scaleF, 1,
                          (RwV3d *)((u8 *)target + 0x1c));
            frame.positionB.x = frame.transformedF.x + target->pos.x;
            frame.positionB.y = frame.transformedF.y + target->pos.y;
            frame.positionB.z = frame.transformedF.z + target->pos.z;
        }

        btlTargetBlendVectors(&frame.rotate, &frame.positionA, &frame.positionB);
        RtQuatTransformVectors(&frame.finalRotation, &D_0060A0F0, 1, &frame.rotate);
        frame.finalRotation.x *= packet->unk_1c;
        frame.finalRotation.y *= packet->unk_1c;
        frame.finalRotation.z *= packet->unk_1c;
        frame.positionA.x += frame.finalRotation.x;
        frame.positionA.y += frame.finalRotation.y;
        frame.positionA.z += frame.finalRotation.z;
        packet->targetPos = frame.positionA;
        packet->unk_1c = 0.0f;
    }
finish:
    btlUnitMovePacketUpdate(packet);
}
/* Create movement relative to a target unit using the supplied separation and speed. */
// FUN_001979E0
BtlPacket* btlUnitCreateMoveToUnitPacket(BtlUnit* unit, BtlUnit* targetUnit, f32 param, f32 speed, u32 flags)
{
    BtlPacket* packet;
    BtlUnitPacketMoveToUnit* work;

    packet = btlPacketAlloc(0x10B, sizeof(BtlUnitPacketMoveToUnit));

    packet->initFunc = (BtlPacketFunc)btlUnitHoldPendingPacket;
    packet->updateFunc = (BtlPacketFunc)btlUnitMoveToUnitPacketUpdate;
    packet->destroyFunc = (BtlPacketFunc)btlUnitReleasePendingPacket;

    work = (BtlUnitPacketMoveToUnit*)packet->workData;

    work->unit = unit;
    work->unk_1c = param;
    work->speed = speed;
    work->flags = flags;
    work->targetUnit = targetUnit;

    return packet;
}

typedef struct BtlUnitPacketRotate BtlUnitPacketRotate;
struct BtlUnitPacketRotate
{
    BtlUnit* unit;
    RwV3d rot;
    u32 flags;
    u32 timer;
};

void btlUnitHoldPendingRotate(BtlUnitPacketCountRef* packetWork);
u32 btlUnitRotatePacketUpdate(void* packetWork);
void btlUnitReleasePendingRotate(BtlUnitPacketCountRef* packetWork);
extern RwV3d D_00881430;

/* Create a rotation packet with a world target, defaulting a missing target to the zero vector. */
// FUN_00197F50
BtlPacket* btlUnitCreateRotatePacket(BtlUnit* unit, const RwV3d* rot, u32 flags)
{
    BtlPacket* packet;
    BtlUnitPacketRotate* work;

    packet = btlPacketAlloc(0x10D, sizeof(BtlUnitPacketRotate));

    packet->initFunc = (BtlPacketFunc)btlUnitHoldPendingRotate;
    packet->updateFunc = btlUnitRotatePacketUpdate;
    packet->destroyFunc = (BtlPacketFunc)btlUnitReleasePendingRotate;

    work = (BtlUnitPacketRotate*)packet->workData;

    work->unit = unit;
    work->flags = flags;

    if (rot != NULL)
    {
        work->rot = *rot;
    }
    else
        work->rot = D_00881430;

    return packet;
}

typedef struct BtlUnitPacketAnim BtlUnitPacketAnim;
struct BtlUnitPacketAnim
{
    BtlUnit* unit;
    s16 id;
    u16 blendFrameCount;
    f32 speed;
    u16 mode;
};

/* measured: plain-C reconstruction matches the 640B retail window with
   normalized_diff 0; a named u8 boolean plus zero-guard reproduces retail's
   sltu/bnez tail layout. */
/* Face or follow another unit, optionally using its grid-space sphere center. */
/* measured: separate typed aliases preserve the packet/unit reloads that moved instructions with access-site fields. */
// FUN_00198050
s32 btlUnitRotateTowardUnitPacketUpdate(u8 *packetData)
{
    BtlUnitPacketPair *packetDataFields = (BtlUnitPacketPair *)packetData;
    BtlUnit *unitFields;
    struct Btl980Rot {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };
    struct Btl980Work {
        struct Btl980Rot rotation;
        RwV3d transformed;
        f32 transformedPad;
        RwV3d scaled;
    } work;
    u8 *unit;
    u8 *gridTarget;
    u8 *positionTarget;
    u8 *followTarget;
    s32 flags;
    u8 turnPending;
    f32 deltaX;
    f32 deltaZ;

    unit = (u8 *)((BtlUnitPacketPair *)packetData)->first;
    unitFields = (BtlUnit *)unit;
    if (((BtlUnitPacketPair *)packetData)->timer == 0)
    {
        flags = ((BtlUnitPacketPair *)packetData)->flags;
        if ((flags & 2) != 0)
        {
            if ((flags & 0x20) != 0)
            {
                gridTarget = (u8 *)((BtlUnitPacketPair *)packetData)->second;
                work.scaled.x = ((BtlUnit *)gridTarget)->sphereCenter.x * ((BtlUnit *)gridTarget)->scale;
                work.scaled.y = ((BtlUnit *)gridTarget)->sphereCenter.y * ((BtlUnit *)gridTarget)->scale;
                work.scaled.z = ((BtlUnit *)gridTarget)->sphereCenter.z * ((BtlUnit *)gridTarget)->scale;
                RtQuatTransformVectors(&work.transformed, &work.scaled, 1,
                              (void *)(gridTarget + 0x1C));
                deltaX = work.transformed.x
                    + (f32)((((BtlUnit *)gridTarget)->unk_94 * 0x19) - 0x6D6)
                    - ((BtlUnit *)unit)->pos.x;
                deltaZ = work.transformed.z
                    + (f32)((((BtlUnit *)gridTarget)->unk_96 * 0x19) - 0x6D6)
                    - ((BtlUnit *)unit)->pos.z;
            }
            else
            {
                positionTarget = (u8 *)((BtlUnitPacketPair *)packetData)->second;
                deltaX = ((BtlUnit *)positionTarget)->pos.x - ((BtlUnit *)unit)->pos.x;
                deltaZ = ((BtlUnit *)positionTarget)->pos.z - ((BtlUnit *)unit)->pos.z;
            }
            if ((deltaX != 0.0f) || (deltaZ != 0.0f))
            {
                func_003dc740(&work.rotation, D_0060A0E0, 0,
                              fGpffff8048 * func_0044b950(deltaX, deltaZ));
                if ((((BtlUnit *)unit)->flags3 & 0x2000) == 0)
                {
                    *(struct Btl980Rot *)&((BtlUnit *)unit)->rot = work.rotation;
                    ((BtlUnit *)unit)->flags2 |= 4;
                }
            }
            ((BtlUnit *)unit)->stateFlags &= ~2;
            ((BtlUnit *)unit)->movementFlags &= 0xFFFD;
            btlUnitRequestLookAt(unit);
        }
        else
        {
            if ((flags & 0x20) != 0)
            {
                btlUnitGetAnchorPose((u8 *)((BtlUnitPacketPair *)packetData)->second, unit + 0xD0, 0, NULL);
            }
            else
            {
                followTarget = (u8 *)((BtlUnitPacketPair *)packetData)->second;
                ((BtlUnit *)unit)->rotationTarget = ((BtlUnit *)followTarget)->pos;
            }
            unitFields->stateFlags |= packetDataFields->flags;
            ((BtlUnit *)unit)->movementFlags |= 2;
        }
    }
    turnPending = ((((BtlUnit *)unit)->movementFlags & 2) != 0) ? 1 : 0;
    if (turnPending == 0)
    {
        return 1;
    }
    packetDataFields->timer += 1;
    return 0;
}
BtlPacket* btlUnitCreateResNullifiedAnimPacket(BtlUnit* unit, f32 value);
BtlPacket* btlUnitCreateArcOffsetPacket(BtlUnit* unit, s32 value);
BtlPacket* btlUnitCreateEnmDodgeAnimPacket(BtlUnit* unit, s32 param);
void btlUnitHoldPendingAnim(BtlUnitPacketCountRef* packetWork);
void btlUnitReleasePendingAnim(BtlUnitPacketCountRef* packetWork);

/* Create motion playback work; negative ids select reaction packets or remap -5 to the default motion. */
// FUN_00199EE0
BtlPacket* btlUnitCreateAnimPacket(BtlUnit* unit, s16 id, u16 blendFrameCount, f32 speed, u16 mode)
{
    BtlPacket* packet;
    BtlUnitPacketAnim* work;
    s16 _id;

    _id = id;
    switch (_id)
    {
        case -2: return btlUnitCreateResNullifiedAnimPacket(unit, 32.0f);
        case -3: return btlUnitCreateArcOffsetPacket(unit, 6);
        case -4: return btlUnitCreateEnmDodgeAnimPacket(unit, 6);
    }

    packet = btlPacketAlloc(0x100, sizeof(BtlUnitPacketAnim));

    packet->initFunc = (BtlPacketFunc)btlUnitHoldPendingAnim;
    packet->updateFunc = btlUnitPlayMotionPacketUpdate;
    packet->destroyFunc = (BtlPacketFunc)btlUnitReleasePendingAnim;

    work = (BtlUnitPacketAnim*)packet->workData;
    work->unit = unit;

    switch (_id)
    {
        case -5:
            _id = -1;
    }

    work->id = _id;
    work->blendFrameCount = blendFrameCount;
    work->speed = speed;
    work->mode = mode;

    return packet;
}

typedef struct BtlUnitPacketLookAt BtlUnitPacketLookAt;
struct BtlUnitPacketLookAt
{
    BtlUnit* unit;
    RwV3d targetPos;
    u16 flags;
};

void btlUnitHoldPendingLookAtRef(BtlUnitPacketCountRef* context);
u32 btlUnitSetLookAtRanges(void* work);
void btlUnitReleasePendingLookAtRef(BtlUnitPacketCountRef* context);

/* Retain the unit and reuse or start loading the requested model resource. */
/* measured: separate typed packet/unit aliases preserve the reloads that moved instructions with access-site fields. */
// FUN_0019ACD0
void btlUnitModelLoadPacketInit(u8 *packetData)
{
    BtlUnitModelLoadPacket *packetDataFields = (BtlUnitModelLoadPacket *)packetData;
    BtlUnit *pFields;
    u8 modelPath[0x80];
    u8 *p;
    u8 *obj;
    s32 flags;
    u16 coord;
    u8 *made;

    p = *(u8 **)packetData;
    pFields = (BtlUnit *)p;
    ((BtlUnit *)p)->pendingPacketCount = ((BtlUnit *)p)->pendingPacketCount + 1;
    if (!((u16)((BtlUnitModelLoadPacket *)packetData)->motion & 0x200)) {
        obj = ((BtlUnit *)p)->layerHandle;
        if (obj != NULL) {
            coord = (u16)((BtlUnitModelLoadPacket *)packetData)->genus;
            if (coord == ((MdlFileModel *)obj)->type) {
                coord = (u16)((BtlUnitModelLoadPacket *)packetData)->modelId;
                if (coord == ((MdlFileModel *)obj)->id) {
                    return;
                }
            }
            mdlDestroyModelObject(obj);
            pFields->layerHandle = NULL;
        }
        made = mdlFindModelObject((u16)((BtlUnitModelLoadPacket *)packetData)->genus, (u16)((BtlUnitModelLoadPacket *)packetData)->modelId, 0);
        if (made != 0) {
            pFields->layerHandle = (u8 *)mdlCloneModelObject(made);
            flags = ((BtlUnit *)p)->flags2 | 2;
            ((BtlUnit *)p)->flags2 = flags;
            ((BtlUnit *)p)->flags2 = flags | 1;
            return;
        }
    }
    if (!(packetDataFields->flags & 0x10)) {
        mdlBuildModelPath((u16)((BtlUnitModelLoadPacket *)packetData)->genus, (u16)((BtlUnitModelLoadPacket *)packetData)->modelId, (char *)&modelPath[0]);
        func_00440b68(&iGpffffa0b0, D_005F6D00, 0xD98);
        ((BtlUnitModelLoadPacket *)packetData)->resource = H_Cdvd_AcquireDirectory(&modelPath[0], 0);
        ((BtlUnit *)p)->flags2 = ((BtlUnit *)p)->flags2 | 1;
    }
    if (!(packetDataFields->flags & 0x200)) {
        ((BtlUnit *)p)->flags2 = ((BtlUnit *)p)->flags2 & ~2;
    }
}
static inline u8 *btlUnitOffsetAdd(u32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
/* 1796/1808 bytes (three words of padding). The unit's model is loaded or
   adopted, its resource ids and material flags are applied, then its motion
   frame, scale and quaternion rotation are pushed to the model. Levers: the
   rotation is RtQuatUnitConvertToMatrix written out (all nine products
   first); the frame argument is `(u16)(cond ? frame : 0)` so the mask sits
   at the merge; the percentage scale goes through a `speed` local set to
   1.0f, which keeps retail's `mul.s` by one; the character table offset goes
   through the offset-first add helper; both tail switches are switches. */
/* Finish model loading, apply resource/material state, initialize motion, and publish the unit transform. */
/* measured: packet aliases and the named model/resource layouts preserve the reloads that moved instructions with access-site fields. */
/* The constructor names +0x08 motion; these callbacks interpret that halfword as model flags. */
// FUN_0019AE20
s32 btlUnitModelMotionPacketUpdate(u8 *packetData) {
    BtlUnitModelLoadPacket *packetDataFields = (BtlUnitModelLoadPacket *)packetData;
    extern f32 mdlGetLayerKeyTime(void *model, s32 layer, s64 animationIndex);
    extern u8 *iGpffffb3cc;
    extern void mdlSetLayerTime(void *model, s32 layer, f32 frameValue);
    extern u32 datCalcRandomBelow(u32 limit);
    u8 *unitData;
    BtlUnit *unit;
    u8 *model;
    u8 *made;
    s32 modelFlags;
    u16 motion;
    f32 speed;
    s16 frameCount;
    s16 motionId;
    f32 keyTime;
    s16 randomFrame;
    u16 resourceFlags;
    s32 childFlags;
    s32 hasMotion;
    u8 genus;
    u8 modelPath[128];
    struct { RwV3d right; u32 flags; RwV3d up; u32 pad1; RwV3d at; u32 pad2; RwV3d pos; u32 pad3; } mat;
    f32 transformVector[3];

    unitData = *(u8 **)packetData;
    unit = (BtlUnit *)unitData;
    if ((unit->flags2 & 1) == 0) {
        made = mdlFindModelObject((u16)((BtlUnitModelLoadPacket *)packetData)->genus, (u16)((BtlUnitModelLoadPacket *)packetData)->modelId, 0);
        if (made != 0) {
            unit->layerHandle = (u8 *)mdlCloneModelObject(made);
        } else {
            mdlBuildModelPath((u16)packetDataFields->genus, (u16)packetDataFields->modelId, (char *)modelPath);
            func_00440b68(&iGpffffa0b0, D_005F6D00, 0xDC9);
            ((BtlUnitModelLoadPacket *)packetData)->resource = H_Cdvd_AcquireDirectory(modelPath, 0);
            unit->flags2 |= 1;
        }
    }
    model = unit->layerHandle;
    if (model == NULL) {
        if (H_Cdvd_IsFileLoaded(((BtlUnitModelLoadPacket *)packetData)->resource) != 0) {
            model = mdlCreateModelObjectFromResource((u16)((BtlUnitModelLoadPacket *)packetData)->genus, (u16)((BtlUnitModelLoadPacket *)packetData)->modelId, packetDataFields->resourcePtr, 0);
            unit->layerHandle = model;
            mdlAppBindSecondaryText((void *)model);
            if ((u16)packetDataFields->genus == 1) {
                mdlRunSetupCallback(unit->layerHandle);
            }
        }
    } else if (mdlPrepareModel(model) != 0) {
        if ((u16)((BtlUnitModelLoadPacket *)packetData)->motion & 4) {
            genus = unit->genus;
            switch (genus) {
            case 0: {
                unit->sceneDrawId = MT_Scene_CreateModelCharRes(unit->charId, unit->layerHandle);
                SceneDraw_SetDirectionalOnly(unit->sceneDrawId, 1);
                ((MdlFileModel *)unit->layerHandle)->flags |= 0x400;
                mdlClumpSetEnvMapState(mdlGetClump(unit->layerHandle));
            } break;
            case 1: {
                unit->sceneDrawId = MT_Scene_CreateModelCharRes(btlFindFreeCharResId(), unit->layerHandle);
                SceneDraw_SetDirectionalOnly(unit->sceneDrawId, 1);
                resourceFlags = (u16)((BtlUnitEnemyRecord *)btlUnitOffsetAdd(unit->charId * 0xE8, iGpffffb3cc))->flags;
                if (resourceFlags & 2) {
                    ((MdlFileModel *)unit->layerHandle)->flags |= 0x200;
                }
                if (resourceFlags & 8) {
                    ((MdlFileModel *)unit->layerHandle)->flags |= 0x400;
                }
                if (resourceFlags & 0x10) {
                    ((MdlFileModel *)unit->layerHandle)->flags |= 0x800;
                }
            } break;
            case 2: {
                ((MdlFileModel *)unit->layerHandle)->flags &= ~0x100;
                childFlags = datGetPersonaFlagClass(unit->charId) & 0xFFFF;
                if (childFlags & 2) {
                    ((MdlFileModel *)unit->layerHandle)->flags |= 0x200;
                } else if (childFlags & 4) {
                    btlUnitClearModelState(unitData, 2);
                    packetDataFields->flags &= ~1;
                }
                if (childFlags & 8) {
                    ((MdlFileModel *)unit->layerHandle)->flags |= 0x400;
                }
                unit->sceneDrawId = MT_Scene_CreateModelUnkRes(unit->charId, unit->layerHandle);
            } break;
            }
        }
        modelFlags = unit->flags2 & ~1;
        unit->flags2 = modelFlags;
        unit->flags2 = modelFlags | 2;
        btlUnitApplyModelState(unitData, 4);
        if (packetDataFields->flags & 8) {
            unit->cols[0].alpha = 0;
        }
        if (packetDataFields->flags & 1) {
            btlUnitApplyModelState(unitData, 2);
        }
        if (packetDataFields->flags & 2) {
            btlUnitApplyModelState(unitData, 1);
        }
        if (packetDataFields->flags & 0x100) {
            ((MdlFileModel *)unit->layerHandle)->colorRed = 0;
            ((MdlFileModel *)unit->layerHandle)->colorGreen = 0;
            ((MdlFileModel *)unit->layerHandle)->colorBlue = 0;
        }
        if (packetDataFields->flags & 0x40) {
            btlTargetAddRadiusNode(unitData, 0);
        }
        if (packetDataFields->flags & 0x20) {
            btlUnitUpdateStatusMotion(unitData, 0);
            btlUnitSetMotion(unitData, unit->restMotion, 0, unit->restRate, unit->restOption);
            hasMotion = unit->flags2 & 2;
            motion = (u16)((hasMotion != 0) ? unit->currentMotion : 0);
            if (hasMotion == 0) {
                frameCount = 0;
            } else {
                speed = 1.0f;
                motionId = btlUnitGetMotionId(unitData, motion);
                keyTime = mdlGetLayerKeyTime(unit->layerHandle, 0, motionId);
                if (motionId < unit->motionCount) {
                    frameCount = (s16)(s32)(keyTime / (speed * ((f32)(unit->motionRates)[motionId].rate / 100.0f)));
                } else {
                    frameCount = (s16)(s32)keyTime;
                }
            }
            randomFrame = datCalcRandomBelow((u32)frameCount);
            if (unit->flags2 & 2) {
                mdlSetLayerTime(unit->layerHandle, 0, (f32)randomFrame);
            }
        }
        if (((BtlUnitModelLoadPacket *)packetData)->resource != 0) {
            H_Cdvd_Destroy(((BtlUnitModelLoadPacket *)packetData)->resource);
        }
        genus = unit->genus;
        switch (genus) {
        case 0:
        case 1: {
            f32 x = unit->rot.imag.x;
            f32 y = unit->rot.imag.y;
            f32 z = unit->rot.imag.z;
            f32 w = unit->rot.real;
            RwV3d square;
            RwV3d cross;
            RwV3d wimag;

            square.x = x * x;
            square.y = y * y;
            square.z = z * z;
            cross.x = y * z;
            cross.y = z * x;
            cross.z = x * y;
            wimag.x = w * x;
            wimag.y = w * y;
            wimag.z = w * z;
            mat.right.x = 1 - 2 * (square.y + square.z);
            mat.right.y = 2 * (cross.z + wimag.z);
            mat.right.z = 2 * (cross.y - wimag.y);
            mat.up.x = 2 * (cross.z - wimag.z);
            mat.up.y = 1 - 2 * (square.x + square.z);
            mat.up.z = 2 * (cross.x + wimag.x);
            mat.at.x = 2 * (cross.y + wimag.y);
            mat.at.y = 2 * (cross.x - wimag.x);
            mat.at.z = 1 - 2 * (square.x + square.y);
            mat.pos.x = 0;
            mat.pos.y = 0;
            mat.pos.z = 0;
            mat.flags = 3;
            mdlApplyModelMatrix(unit->layerHandle, &mat, 0);
            transformVector[0] = transformVector[1] = transformVector[2] = unit->scale;
            mdlScale(unit->layerHandle, transformVector, 2);
            transformVector[0] = unit->pos.x + unit->posOffset.x;
            transformVector[1] = unit->pos.y + unit->posOffset.y;
            transformVector[2] = unit->pos.z + unit->posOffset.z;
            mdlTranslateMatrix(unit->layerHandle, transformVector, 2);
            mdlUpdateModelMatrix(unit->layerHandle);
            mdlPrepareItemSlots(unit->layerHandle);
        } break;
        }
        return 1;
    }
    return 0;
}
// FUN_0019BCB0
s32 btlUnitShowPacketUpdate(u8 *context) {
    btlUnitShowModel(*(u8 **)context);
    return 1;
}
// FUN_0019BD80
s32 btlUnitHidePacketUpdate(u8 *context) {
    btlUnitHideModel(*(u8 **)context);
    return 1;
}
/* Release the optional unit reference retained by a world-position look-at packet. */
// FUN_0019E130
void btlUnitReleasePendingLookAtRef(BtlUnitPacketCountRef* context) {
    u8 *temp;

    temp = *(u8 **)context;
    if (temp != NULL) {
        ((BtlUnit *)temp)->pendingPacketCount = ((BtlUnit *)temp)->pendingPacketCount - 1;
    }
}
/* Create a look-at request using a copied world position and the supplied selection flags. */
// FUN_0019E150
BtlPacket* btlUnitCreateLookAtPacket(BtlUnit* unit, const RwV3d* targetPos, u16 flags)
{
    BtlPacket* packet;
    BtlUnitPacketLookAt* work;

    packet = btlPacketAlloc(0x117, sizeof(BtlUnitPacketLookAt));

    packet->initFunc = (BtlPacketFunc)btlUnitHoldPendingLookAtRef;
    packet->updateFunc = btlUnitSetLookAtRanges;
    packet->destroyFunc = (BtlPacketFunc)btlUnitReleasePendingLookAtRef;

    work = (BtlUnitPacketLookAt*)packet->workData;

    work->unit = unit;
    work->flags = flags;
    work->targetPos = *targetPos;

    return packet;
}

/* Publish a new position and request a model-transform refresh. */
// FUN_00194EE0
void btlUnitSetPos(BtlUnit* unit, const RwV3d* pos)
{
    unit->pos = *pos;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}

/* Publish rotation only when rotation is unlocked, then request a model refresh. */
// FUN_00194F10
void btlUnitSetRot(BtlUnit* unit, const RtQuat* rot)
{
    if (!(unit->flags3 & BTLUNIT_FLAG3_NOROT))
    {
        unit->rot = *rot;
        unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    }
}

/* Set the primary unit color and request a model-state refresh. */
// FUN_00194F60
void btlUnitSetColor(BtlUnit* unit, RwRGBA col)
{
    unit->cols[0] = col;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}

/* Enable unit flags and request their model-state refresh. */
// FUN_00194FA0
void btlUnitSetFlags(BtlUnit* unit, u16 flags)
{
    unit->flags |= flags;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}

/* Disable unit flags and request their model-state refresh. */
// FUN_00194FC0
void btlUnitClearFlags(BtlUnit* unit, u16 flags)
{
    unit->flags &= ~flags;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}
/* Apply the requested position, rotation, and color overrides and mark the unit dirty. */
// FUN_00195630
u32 btlUnitOverridePacketUpdate(BtlUnitPacketPosRotCol* packet)
{
    BtlUnit* unit;

    if (packet->flags & 0x1)
    {
        unit = packet->unit;
        unit->pos = packet->pos;
        unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    }

    if ((packet->flags & 0x2) &&
        !(packet->unit->flags3 & BTLUNIT_FLAG3_NOROT))
    {
        unit = packet->unit;
        unit->rot = packet->rot;
        unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    }

    if (packet->flags & 0x4)
    {
        unit = packet->unit;
        unit->cols[0] = packet->col;
        unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    }

    return 1;
}

/* Scale and rotate the local sphere center into world space. */
// FUN_00195850
void btlUnitGetSphereWorldCenter(BtlUnit* unit, RwV3d* dst)
{
    RwV3d scaledCenter;
    RwV3d rotatedCenter;

    scaledCenter.x = unit->sphereCenter.x * unit->scale;
    scaledCenter.y = unit->sphereCenter.y * unit->scale;
    scaledCenter.z = unit->sphereCenter.z * unit->scale;

    RtQuatTransformVectors(&rotatedCenter, &scaledCenter, 1, &unit->rot);

    dst->x = rotatedCenter.x + unit->pos.x;
    dst->y = rotatedCenter.y + unit->pos.y;
    dst->z = rotatedCenter.z + unit->pos.z;
}

/* Same rotation and scale as btlUnitGetSphereWorldCenter, but the x/z
 * position comes from the grid cell fields (unk_94/unk_96, 25 units per
 * cell, -0x6d6 origin) instead of pos.x/pos.z. The two formulas are
 * near-duplicates; the battle target/group and camera callers want the grid
 * position. */
/* Transform the sphere center using grid coordinates instead of the world XZ position. */
// FUN_001958F0
void btlUnitGetGridSphereCenter(BtlUnit* unit, RwV3d* dst)
{
    RwV3d scaledCenter;
    RwV3d rotatedCenter;

    scaledCenter.x = unit->sphereCenter.x * unit->scale;
    scaledCenter.y = unit->sphereCenter.y * unit->scale;
    scaledCenter.z = unit->sphereCenter.z * unit->scale;

    RtQuatTransformVectors(&rotatedCenter, &scaledCenter, 1, &unit->rot);

    dst->x = rotatedCenter.x + (unit->unk_94 * 25 - 0x6d6);
    dst->y = rotatedCenter.y + unit->pos.y;
    dst->z = rotatedCenter.z + (unit->unk_96 * 25 - 0x6d6);
}

/* Compute the grid sphere center with a rotation facing another unit. */
// FUN_00195C50
void btlUnitGetGridSphereCenterTowardTarget(BtlUnit* unit, BtlUnit* target, RwV3d* outPosition)
{
    RtQuat rotation;
    RwV3d scaled;
    RwV3d transformed;

    btlTargetBlendVectors((RwV3d*)&rotation, &unit->pos, &target->pos);
    scaled.x = unit->sphereCenter.x * unit->scale;
    scaled.y = unit->sphereCenter.y * unit->scale;
    scaled.z = unit->sphereCenter.z * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &rotation);
    outPosition->x = transformed.x + (unit->unk_94 * 25 - 0x6d6);
    outPosition->y = transformed.y + unit->pos.y;
    outPosition->z = transformed.z + (unit->unk_96 * 25 - 0x6d6);
}

// FUN_00196B50
u32 btlUnitIsMoving(BtlUnit* unit)
{
    return (unit->movementFlags & 0x1) != 0;
}

/* Allocate the move packet work and install its lifecycle callbacks. */
// FUN_001973F0
BtlPacket* btlUnitCreateMovePacket(BtlUnit* unit, const RwV3d* targetPos, f32 speed, u32 flags)
{
    BtlPacket* packet;
    BtlUnitPacketMove* work;

    packet = btlPacketAlloc(0x10A, sizeof(BtlUnitPacketMove));

    packet->initFunc = (BtlPacketFunc)btlUnitHoldPendingMove;
    packet->updateFunc = btlUnitMovePacketUpdate;
    packet->destroyFunc = (BtlPacketFunc)btlUnitReleasePendingMove;

    work = (BtlUnitPacketMove*)packet->workData;

    work->unit = unit;
    work->speed = speed;
    work->flags = flags;

    if (targetPos != NULL)
    {
        work->targetPos = *targetPos;
    }
    else
    {
        work->targetPos = D_00881430;
    }

    return packet;
}

/* Retain the referenced unit or units for the lifetime of this packet. */
// FUN_001974D0
void btlUnitHoldPendingPacket(BtlUnitPacketCountRef* packet)
{
    packet->unit->pendingPacketCount++;
}

/* Release the unit references held by this packet. */
// FUN_001979C0
void btlUnitReleasePendingPacket(BtlUnitPacketCountRef* packet)
{
    packet->unit->pendingPacketCount--;
}

/* Retain the referenced unit or units for the lifetime of this packet. */
// FUN_00198020
void btlUnitHoldPendingPair(BtlUnitPacketPair* packet)
{
    packet->first->pendingPacketCount++;
    packet->second->pendingPacketCount++;
}

/* Release the unit references held by this packet. */
// FUN_001982D0
void btlUnitReleasePendingPair(BtlUnitPacketPair* packet)
{
    packet->first->pendingPacketCount--;
    packet->second->pendingPacketCount--;
}

/* Retain the referenced unit or units for the lifetime of this packet. */
// FUN_0019A350
void btlUnitHoldPendingUnit(BtlUnitPacketUnitAtC* packet)
{
    packet->unit->pendingPacketCount++;
}

/* Release the unit references held by this packet. */
// FUN_0019A5C0
void btlUnitReleasePendingUnit(BtlUnitPacketUnitAtC* packet)
{
    packet->unit->pendingPacketCount--;
}

// FUN_0019D130
u32 btlUnitIsModelVisible(BtlUnit* unit)
{
    return !((unit->flags3 & BTLUNIT_FLAG3_MODEL_HIDDEN) != 0);
}

/* Store the low byte of the supplied value only for a nonnull child-unit work record. */
// FUN_0019DE70
void btlUnitSetChildValue(BtlUnitStateWork* work, u16 value)
{
    if (work != NULL && work->state == BTLUNIT_KIND_CHILD)
    {
        work->value = (u8)value;
    }
}

/* Retain the referenced unit or units for the lifetime of this packet. */
// FUN_0019DF00
void btlUnitHoldPendingLookAtRef(BtlUnitPacketCountRef* context) {
    u8 *temp;

    temp = *(u8 **)context;
    if (temp != NULL) {
        ((BtlUnit *)temp)->pendingPacketCount = ((BtlUnit *)temp)->pendingPacketCount + 1;
    }
}

/* Retain the referenced unit or units for the lifetime of this packet. */
// FUN_0019E1F0
void btlUnitHoldPendingLookAtUnits(BtlUnitPacketTwoUnits* packet)
{
    if (packet->first != NULL)
    {
        packet->first->pendingPacketCount++;
    }
    packet->second->pendingPacketCount++;
}

/* Configure look-at ranges and target ids for one unit or the requested party/enemy lists. */
/* measured: typed aliases retain the packet/model-state reloads across callbacks that moved instructions with access-site fields. */
// FUN_0019E220
u32 btlUnitLookAtUnitPacketUpdate(u8* packet)
{
    BtlUnit *singleCurrentFields;
    BtlUnit *secondCurrentFields;
    BtlUnitPacketTwoUnits *packetFields = (BtlUnitPacketTwoUnits *)packet;
    BtlUnit *firstCurrentFields;
    extern u8* iGpffffb3ac;
    extern void mdlLookAtSetupSetRange(void* model, f32 pitchLimit, f32 yawLimit);
    extern void mdlSetBlendWeight(void* model, f32 value);
    extern void btlUnitApplyModelState(void* unit, s32 mode);
    f32 firstHigh;
    f32 firstLow;
    f32 secondHigh;
    f32 secondLow;
    f32 singleHigh;
    f32 singleLow;
    u8* firstCurrent;
    u8* secondCurrent;
    u8* singleCurrent;
    u8* firstTarget;
    u8* secondTarget;
    u8* singleTarget;

    if ((((BtlUnitPacketTwoUnits *)packet)->flags & 3) != 0)
    {
        if ((((BtlUnitPacketTwoUnits *)packet)->flags & 1) != 0)
        {
            firstCurrent = ((BtlBattleState *)iGpffffb3ac)->unitLists[1];
            firstCurrentFields = (BtlUnit *)firstCurrent;
            while (firstCurrent != NULL)
            {
                if ((((BtlUnit *)firstCurrent)->flags3 & 8) != 0)
                {
                    firstTarget = (u8 *)((BtlUnitPacketTwoUnits *)packet)->second;
                    if (&firstHigh != NULL)
                    {
                        firstHigh = 70.0f;
                    }
                    if (&firstLow != NULL)
                    {
                        firstLow =
                            ((u8 *)((BtlAction *)((BtlBattleState *)iGpffffb3ac)->selectedAction)->unit ==
                             firstCurrent) ? 70.0f : 60.0f;
                    }
                    {
                        f32 highArg;
                        f32 lowArg;
                        lowArg = firstLow;
                        highArg = firstHigh;
                        if ((((BtlUnit *)firstCurrent)->flags2 & 2) != 0)
                        {
                            mdlLookAtSetupSetRange((void *)((BtlUnit *)firstCurrent)->layerHandle, highArg, lowArg);
                        }
                    }
                    if ((firstCurrentFields->flags2 & 2) != 0)
                    {
                        mdlSetBlendWeight((void *)((BtlUnit *)firstCurrent)->layerHandle, 0.25f);
                    }
                    ((BtlUnit *)firstCurrent)->lookAtMode = 2;
                    ((BtlUnit *)firstCurrent)->lookAtTargetId =
                        ((BtlUnit *)firstTarget)->id;
                    btlUnitApplyModelState(firstCurrent, 3);
            }
                firstCurrent = (u8 *)((BtlUnit *)firstCurrent)->prevUnit;
                firstCurrentFields = (BtlUnit *)firstCurrent;
        }
        }
        if ((packetFields->flags & 2) != 0)
        {
            secondCurrent = ((BtlBattleState *)iGpffffb3ac)->unitLists[3];
            secondCurrentFields = (BtlUnit *)secondCurrent;
            while (secondCurrent != NULL)
            {
                if ((((BtlUnit *)secondCurrent)->flags3 & 8) != 0)
                {
                    secondTarget = (u8 *)((BtlUnitPacketTwoUnits *)packet)->second;
                    if (&secondHigh != NULL)
                    {
                        secondHigh = 70.0f;
                    }
                    if (&secondLow != NULL)
                    {
                        secondLow =
                            ((u8 *)((BtlAction *)((BtlBattleState *)iGpffffb3ac)->selectedAction)->unit ==
                             secondCurrent) ? 70.0f : 60.0f;
                    }
                    {
                        f32 highArg;
                        f32 lowArg;
                        lowArg = secondLow;
                        highArg = secondHigh;
                        if ((((BtlUnit *)secondCurrent)->flags2 & 2) != 0)
                        {
                            mdlLookAtSetupSetRange((void *)((BtlUnit *)secondCurrent)->layerHandle, highArg, lowArg);
                        }
                    }
                    if ((secondCurrentFields->flags2 & 2) != 0)
                    {
                        mdlSetBlendWeight((void *)((BtlUnit *)secondCurrent)->layerHandle, 0.25f);
                    }
                    ((BtlUnit *)secondCurrent)->lookAtMode = 2;
                    ((BtlUnit *)secondCurrent)->lookAtTargetId =
                        ((BtlUnit *)secondTarget)->id;
                    btlUnitApplyModelState(secondCurrent, 3);
                }
                secondCurrent = (u8 *)((BtlUnit *)secondCurrent)->prevUnit;
                secondCurrentFields = (BtlUnit *)secondCurrent;
            }
        }
    }
    else
    {
        singleTarget = (u8 *)((BtlUnitPacketTwoUnits *)packet)->second;
        singleCurrent = (u8 *)((BtlUnitPacketTwoUnits *)packet)->first;
        singleCurrentFields = (BtlUnit *)singleCurrent;
        if (&singleHigh != NULL)
        {
            singleHigh = 70.0f;
        }
        if (&singleLow != NULL)
        {
            singleLow =
                ((u8 *)((BtlAction *)((BtlBattleState *)iGpffffb3ac)->selectedAction)->unit ==
                 singleCurrent) ? 70.0f : 60.0f;
        }
        {
            f32 highArg;
            f32 lowArg;
            lowArg = singleLow;
            highArg = singleHigh;
            if ((((BtlUnit *)singleCurrent)->flags2 & 2) != 0)
            {
                mdlLookAtSetupSetRange((void *)((BtlUnit *)singleCurrent)->layerHandle, highArg, lowArg);
            }
        }
        if ((singleCurrentFields->flags2 & 2) != 0)
        {
            mdlSetBlendWeight((void *)((BtlUnit *)singleCurrent)->layerHandle, 0.25f);
        }
        ((BtlUnit *)singleCurrent)->lookAtMode = 2;
        ((BtlUnit *)singleCurrent)->lookAtTargetId =
            ((BtlUnit *)singleTarget)->id;
        btlUnitApplyModelState(singleCurrent, 3);
    }
    return 1;
}
/* Release the unit references held by this packet. */
// FUN_0019E520
void btlUnitReleasePendingLookAtUnits(BtlUnitPacketTwoUnits* packet)
{
    if (packet->first != NULL)
    {
        packet->first->pendingPacketCount--;
    }
    packet->second->pendingPacketCount--;
}

#define BTLUNIT_FLAG3_UNK400 (1 << 10)


typedef struct BtlUnitPacket00284900 BtlUnitPacket00284900;
struct BtlUnitPacket00284900
{
    RwV3d pos;
    BtlUnit* unit;
    u16 unk_10;
    u16 unk_12;
    f32 phase;
};

s16 btlUnitGetMotionState(BtlUnit* unit);
u16 datCalcRandomBelow(u32 limit);
void btlUnitSetModelAnimFrame(BtlUnit* unit, s32 frame);
extern RwV3d D_0060a0d0;
extern f32 DAT_007613f8;

/* Retain the referenced unit or units for the lifetime of this packet. */
// FUN_0019E830
void btlUnitHoldPendingLookAt(u8 *context) {
    u8 *temp;

    temp = *(u8 **)context;
    if (temp != NULL) {
        ((BtlUnit *)temp)->pendingPacketCount = ((BtlUnit *)temp)->pendingPacketCount + 1;
    }
}
/* Release the unit references held by this packet. */
// FUN_0019E9D0
void btlUnitReleasePendingLookAt(u8 *context) {
    u8 *temp;

    temp = *(u8 **)context;
    if (temp != NULL) {
        ((BtlUnit *)temp)->pendingPacketCount = ((BtlUnit *)temp)->pendingPacketCount - 1;
    }
}
/* Face a world-space target unless rotation is locked, then refresh look-at state. */
// FUN_00195590
void btlUnitFaceTarget(BtlUnit* unit, const RwV3d* target)
{
    RtQuat rotation;

    btlTargetBlendVectors((RwV3d*)&rotation, &unit->pos, target);
    if ((unit->flags3 & BTLUNIT_FLAG3_NOROT) == 0)
    {
        unit->rot = rotation;
        unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    }
    btlUnitRequestLookAt(unit);
}

/* Transform the animation-table bounds center into world space. */
// FUN_001959D0
void btlUnitGetAnimBoundsWorldCenter(BtlUnit* unit, RwV3d* outPosition)
{
    const BtlUnitAnimBounds* bounds;
    RwV3d scaled;
    RwV3d transformed;
    f32 centerY;
    f32 centerZ;
    f32 centerX;

    bounds = (const BtlUnitAnimBounds *)btlUnitGetRecordPtr((u8 *)unit, 0);
    centerY = bounds->centerY;
    centerZ = bounds->centerZ;
    centerX = bounds->centerX;
    scaled.x = centerX * unit->scale;
    scaled.y = centerY * unit->scale;
    scaled.z = centerZ * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &unit->rot);
    outPosition->x = transformed.x + unit->pos.x;
    outPosition->y = transformed.y + unit->pos.y;
    outPosition->z = transformed.z + unit->pos.z;
}

/* Transform the sphere center using a rotation facing the target unit. */
// FUN_00195AA0
void btlUnitGetSphereCenterTowardTarget(BtlUnit* unit, BtlUnit* target, RwV3d* outPosition)
{
    RtQuat rotation;
    RwV3d scaled;
    RwV3d transformed;

    btlTargetBlendVectors((RwV3d*)&rotation, &unit->pos, &target->pos);
    scaled.x = unit->sphereCenter.x * unit->scale;
    scaled.y = unit->sphereCenter.y * unit->scale;
    scaled.z = unit->sphereCenter.z * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &rotation);
    outPosition->x = transformed.x + unit->pos.x;
    outPosition->y = transformed.y + unit->pos.y;
    outPosition->z = transformed.z + unit->pos.z;
}

/* Return the world sphere center with the HUD vertical offset. */
// FUN_00195EA0
void btlUnitGetHudAnchor(BtlUnit* unit, RwV3d* outPosition)
{
    RwV3d scaled;
    RwV3d transformed;

    scaled.x = unit->sphereCenter.x * unit->scale;
    scaled.y = unit->sphereCenter.y * unit->scale;
    scaled.z = unit->sphereCenter.z * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &unit->rot);
    outPosition->x = transformed.x + unit->pos.x;
    outPosition->y = transformed.y + unit->pos.y;
    outPosition->z = transformed.z + unit->pos.z;
    outPosition->y += unit->unk_8c * unit->scale * DAT_007613f8;
}

/* Return the world sphere center with a quarter-height status-marker offset. */
// FUN_00195F70
void btlUnitGetStatusMarkerPoint(BtlUnit* unit, RwV3d* outPosition)
{
    RwV3d scaled;
    RwV3d transformed;

    scaled.x = unit->sphereCenter.x * unit->scale;
    scaled.y = unit->sphereCenter.y * unit->scale;
    scaled.z = unit->sphereCenter.z * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &unit->rot);
    outPosition->x = transformed.x + unit->pos.x;
    outPosition->y = transformed.y + unit->pos.y;
    outPosition->z = transformed.z + unit->pos.z;
    outPosition->y += unit->unk_8c * unit->scale * 0.25f;
}

/* Set the model to a random frame within the current motion. */
// FUN_001987A0
void btlUnitSetRandomAnimFrame(BtlUnit* unit)
{
    s16 animation;

    animation = (s16)btlUnitMotionModelFrames(
        (u8 *)unit, (u16)(s32)btlUnitGetMotionState(unit), 1.0f);
    animation = (s16)datCalcRandomBelow(animation);
    btlUnitSetModelAnimFrame(unit, animation);
}

/* Advance the temporary arc displacement and restore/offset the saved position unless movement is locked. */
// FUN_0019A370
u32 btlUnitPacketArcOffsetUpdate(void* work)
{
    BtlUnitPacket00284900* packet;
    BtlUnit* unit;
    RwV3d position;
    RwV3d direction;
    f32 phase;
    f32 magnitude;
    f32 arcScale;
    u32 result;

    packet = (BtlUnitPacket00284900*)work;
    unit = packet->unit;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;

    if (packet->unk_12 == 0)
    {
        packet->phase = 0.5f;
        packet->pos = unit->pos;
    }

    phase = packet->phase + 1.0f / (2.0f * (f32)packet->unk_10);
    packet->phase = phase;
    arcScale = 2.0f * (((-1.0f + (-2.0f * phase * phase)) + (4.0f * phase)) - 0.5f);

    RtQuatTransformVectors(&direction, &D_0060a0d0, 1, &unit->rot);
    magnitude = unit->sphereRadius * unit->scale * 1.25f;
    if (magnitude < 75.0f)
    {
        magnitude = 75.0f;
    }

    if (arcScale < fGpffff82d4)
    {
        magnitude *= arcScale;
        direction.x *= magnitude;
        direction.y *= magnitude;
        direction.z *= magnitude;
        result = 0;
        goto update;
    }

    direction.x *= magnitude;
    direction.y *= magnitude;
    direction.z *= magnitude;

    result = 1;
update:
    if (!(unit->flags3 & BTLUNIT_FLAG3_UNK400))
    {
        position.x = packet->pos.x + direction.x;
        position.y = packet->pos.y + direction.y;
        position.z = packet->pos.z + direction.z;
        unit->pos = position;
        unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    }

    packet->unk_12++;
    return result;
}

#include "btl_motion_internal.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "btl_unit_internal.h"

extern u16 btlFindFreeCharResId(void);

extern void mdlDestroyModelObject(); /* old-style: retail jals with $a1 still holding the compared coordinate */
extern void *mdlFindModelObject(u32 arg0, u16 arg1, u32 arg2);
extern void *mdlCreateModelObjectFromResource(u32 arg0, u16 arg1, void *arg2, u32 arg3);
extern u32 *mdlCloneModelObject(u8 *arg0);
extern s32 mdlBuildModelPath(u32 arg0, u16 arg1, char *arg2);
extern void func_00440b68(void *arg0, u8 *arg1, s32 arg2);
extern s32 func_00454a60(void *arg0, s32 arg1);
extern s32 mdlComputeIndexedAttachMatrix(void *arg0, s32 arg1, void *arg2);
extern f32 fGpffff82d4;
extern u8 D_005F6D00[];
extern u8 iGpffffa0b0;
extern void func_00194ff0(void *arg0, void *arg1, s32 arg2, void *arg3);
extern void func_003dc740(void *dst, void *src, f32 angle, s32 mode);
#define func_003dc740(dst, src, mode, angle) \
    func_003dc740(dst, src, angle, mode)
extern f32 func_0044b950(f32 x, f32 y);
extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern void btlUnitRequestLookAt(void *unit);
extern f32 func_003e41e0(f32 *out, f32 *in);
extern void btlUnitShowModel(u8 *arg0);
extern void btlUnitHideModel(u8 *arg0);
extern f32 RwV2dLength(f32 *value);
extern s32 func_0044dcd8(f32 value);
extern s32 func_0044b310(s32 value);
extern f32 func_0044e7d8(s32 value);
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
    u8 _pad08[8];
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
typedef u32 (*BtlPacketFunc)(void* work);

typedef struct BtlPacket BtlPacket;
struct BtlPacket
{
    u8 _pad00[0x68];
    BtlPacketFunc initFunc;
    BtlPacketFunc updateFunc;
    BtlPacketFunc destroyFunc;
    u8 _pad74[4];
    void* workData;
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
u8* btlUnitGetRecordPtr(u8* unit, s32 id);


BtlPacket* btlPacketAlloc(u32 id, s32 workDataSize);
RwV3d* RtQuatTransformVectors(RwV3d* vectorsOut, const RwV3d* vectorsIn,
                     s32 numPoints, const void* quat);
void btlTargetBlendVectors(RwV3d* dst, const RwV3d* from, const RwV3d* to);
extern s32 datCalcIsDead(void *arg0, s32 arg1);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern f32 RwV3dLength(RwV3d *value);
extern u8 *iGpffffb3ac;
extern RwV3d D_00881430;
void func_00196ce0(BtlUnitPacketMove* work);
u32 func_00196d00(void* work);
void func_001973d0(BtlUnitPacketMove* work);
void btlUnitHoldPendingPacket(BtlUnitPacketCountRef* work);
u32 btlUnitMoveToUnitPacketUpdate(BtlUnitPacketMoveToUnit* work);
void btlUnitReleasePendingPacket(BtlUnitPacketCountRef* work);

// FUN_00195B60
void btlUnitGetAnimBoundsWorldCenterTowardUnit(u8 *arg0, s32 arg1, u8 *arg2)
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

    btlTargetBlendVectors(&work.rotation, (RwV3d *)(arg0 + 4), (RwV3d *)((u8 *)arg1 + 4));
    bounds = (BtlUnitAnimBounds *)btlUnitGetRecordPtr(arg0, 0xA);
    centerY = (f32)bounds->centerY;
    centerZ = (f32)bounds->centerZ;
    centerX = (f32)bounds->centerX;
    work.scaled.x = centerX * *(f32 *)(arg0 + 0x2C);
    work.scaled.y = centerY * *(f32 *)(arg0 + 0x2C);
    work.scaled.z = centerZ * *(f32 *)(arg0 + 0x2C);
    RtQuatTransformVectors(&work.transformed, &work.scaled, 1, &work.rotation);
    out = (RwV3d *)arg2;
    out->x = work.transformed.x + *(f32 *)(arg0 + 4);
    out->y = work.transformed.y + *(f32 *)(arg0 + 8);
    out->z = work.transformed.z + *(f32 *)(arg0 + 0xC);
}
/* measured: plain-C aggregate reconstruction reproduces every retail
   instruction; the object is 324B against the 336B window, with three retail
   trailing nop words left as window padding. */
// FUN_00195D50
void btlUnitGetAttachedSphereCenter(u8 *arg0, u8 *arg1)
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

    out = (RwV3d *)arg1;
    if ((*(s32 *)(arg0 + 0x98) & 2) == 0)
    {
        work.firstScaled.x = *(f32 *)(arg0 + 0x80) * *(f32 *)(arg0 + 0x2C);
        work.firstScaled.y = *(f32 *)(arg0 + 0x84) * *(f32 *)(arg0 + 0x2C);
        work.firstScaled.z = *(f32 *)(arg0 + 0x88) * *(f32 *)(arg0 + 0x2C);
        RtQuatTransformVectors(&work.firstOut, &work.firstScaled, 1,
                      (RwV3d *)(arg0 + 0x1C));
        out->x = work.firstOut.x + *(f32 *)(arg0 + 4);
        out->y = work.firstOut.y + *(f32 *)(arg0 + 8);
        out->z = work.firstOut.z + *(f32 *)(arg0 + 0xC);
        return;
    }
    if (mdlComputeIndexedAttachMatrix(*(void **)(arg0 + 0xA00), 0, arg1) == 0)
    {
        work.secondScaled.x = *(f32 *)(arg0 + 0x80) * *(f32 *)(arg0 + 0x2C);
        work.secondScaled.y = *(f32 *)(arg0 + 0x84) * *(f32 *)(arg0 + 0x2C);
        work.secondScaled.z = *(f32 *)(arg0 + 0x88) * *(f32 *)(arg0 + 0x2C);
        RtQuatTransformVectors(&work.secondOut, &work.secondScaled, 1,
                      (RwV3d *)(arg0 + 0x1C));
        out->x = work.secondOut.x + *(f32 *)(arg0 + 4);
        out->y = work.secondOut.y + *(f32 *)(arg0 + 8);
        out->z = work.secondOut.z + *(f32 *)(arg0 + 0xC);
    }
}

// FUN_00196040
f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter,
                  f32 *outTop, f32 *outBottom, u32 options)
{
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
    *(s32 *)(filters + 0x10) = optionFlags & 2;
    *(s32 *)(filters + 0x00) = optionFlags & 1;
    while (group < 4)
    {
        if (mask & (1 << group))
        {
            firstUnit =
                *(u8 **)(iGpffffb3ac + (group * 8) + 0x178);
            while (firstUnit != 0)
            {
                u32 flags = *(u32 *)(firstUnit + 0x9C);

                if ((flags & 8) &&
                    !(flags & excludedFlags) &&
                    (!*(s32 *)(filters + 0x10) ||
                     group != 0 ||
                     (datCalcIsDead(*(void **)(firstUnit + 0xA64), 0) == 0 &&
                      datCalcChkBadStatus(*(s32 *)(firstUnit + 0xA64), 0x100117) == 0)))
                {
                    f32 x;
                    f32 y;
                    f32 z;
                    f32 extent;
                    if (!*(s32 *)(filters + 0x00))
                    {
                        firstScaled.x =
                            *(f32 *)(firstUnit + 0x80) *
                                *(f32 *)(firstUnit + 0x2C);
                        firstScaled.y =
                            *(f32 *)(firstUnit + 0x84) *
                                *(f32 *)(firstUnit + 0x2C);
                        firstScaled.z =
                            *(f32 *)(firstUnit + 0x88) *
                                *(f32 *)(firstUnit + 0x2C);
                        RtQuatTransformVectors(&firstRotated, &firstScaled, 1,
                                      (RwV3d *)(firstUnit + 0x1C));
                        x = firstRotated.x + *(f32 *)(firstUnit + 4);
                        y = firstRotated.y + *(f32 *)(firstUnit + 8);
                        z = firstRotated.z + *(f32 *)(firstUnit + 0xC);
                    }
                    else
                    {
                        x = (f32)(25 * *(s16 *)(firstUnit + 0x94) - 1750);
                        y = *(f32 *)(firstUnit + 8) +
                            *(f32 *)(firstUnit + 0x84) *
                                *(f32 *)(firstUnit + 0x2C);
                        z = (f32)(25 * *(s16 *)(firstUnit + 0x96) - 1750);
                    }
                    sum.x += x;
                    sum.y += y;
                    sum.z += z;
                    extent = y +
                             0.5f *
                                 (*(f32 *)(firstUnit + 0x8C) *
                                  *(f32 *)(firstUnit + 0x2C));
                    if (top < extent)
                        top = extent;
                    if (bottom > extent)
                        bottom = extent;
                    singleUnit = firstUnit;
                    count += 1;
                }
                firstUnit = *(u8 **)(firstUnit + 0xA6C);
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
        radius = *(f32 *)(singleUnit + 0x90) *
                 *(f32 *)(singleUnit + 0x2C);
        extent = 0.5f *
                 (*(f32 *)(singleUnit + 0x8C) *
                  *(f32 *)(singleUnit + 0x2C));
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
                unit = *(u8 **)(iGpffffb3ac + (secondGroup * 8) + 0x178);
                while (unit != 0)
                {
                    u32 flags = *(u32 *)(unit + 0x9C);

                    if ((flags & 8) &&
                        !(flags & excludedFlags) &&
                        (!*(s32 *)(filters + 0x10) ||
                         secondGroup != 0 ||
                         (datCalcIsDead(*(void **)(unit + 0xA64), 0) == 0 &&
                          datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x100117) == 0)))
                    {
                        f32 x;
                        f32 z;
                        f32 extent;
                        if (!*(s32 *)(filters + 0x00))
                        {
                            secondScaled.x =
                                *(f32 *)(unit + 0x80) * *(f32 *)(unit + 0x2C);
                            secondScaled.y =
                                *(f32 *)(unit + 0x84) * *(f32 *)(unit + 0x2C);
                            secondScaled.z =
                                *(f32 *)(unit + 0x88) * *(f32 *)(unit + 0x2C);
                            RtQuatTransformVectors(&secondRotated, &secondScaled, 1,
                                          (RwV3d *)(unit + 0x1C));
                            x = secondRotated.x + *(f32 *)(unit + 4);
                            z = secondRotated.z + *(f32 *)(unit + 0xC);
                        }
                        else
                        {
                            x = (f32)(25 * *(s16 *)(unit + 0x94) - 1750);
                            z = (f32)(25 * *(s16 *)(unit + 0x96) - 1750);
                        }
                        delta.x = x - center.x;
                        delta.y = centerY - centerY;
                        delta.z = z - centerZ;
                        extent = RwV3dLength(&delta);
                        extent += *(f32 *)(unit + 0x90) *
                                  *(f32 *)(unit + 0x2C);
                        if (extent > radius)
                            radius = extent;
                        count += 1;
                    }
                    unit = *(u8 **)(unit + 0xA6C);
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
// FUN_00196610
u32 btlUnitUpdateFollowPath(u8 *arg0)
{
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

    if ((*(u16 *)(arg0 + 0xC8) & 1) &&
        (*(u16 *)(arg0 + 0xC8) & 0x10))
    {
        entry = arg0 + 0xEC;
        index = *(u16 *)(arg0 + 0x4EE);
        count = *(u16 *)(arg0 + 0x4EC);
        lastDistance = 0.0f;
        pathLength = *(f32 *)(arg0 + 0xCC);
        frame.currentX = *(f32 *)(arg0 + 4);
        frame.currentZ = *(f32 *)(arg0 + 0xC);
        while (index < count - 1)
        {
            pathLength -= lastDistance;
            point = entry + (index * 8) + 8;
            frame.deltaX = *(f32 *)(point + 0) - frame.currentX;
            frame.deltaZ = *(f32 *)(point + 4) - frame.currentZ;
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
        if (*(u32 *)(arg0 + 0xC4) & 1)
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
            frame.nextDeltaX = frame.currentX - *(f32 *)(point - 8);
            frame.nextDeltaZ = currentZ - *(f32 *)(point - 4);
            lastDistance = RwV2dLength(&frame.nextDeltaX);
            if (lastDistance < *(f32 *)(arg0 + 0xE8))
            {
                lastDistance = (lastDistance + pathLength) -
                               *(f32 *)(arg0 + 0xE8);
                frame.nextDeltaX = frame.deltaX * lastDistance;
                frame.nextDeltaZ = frame.deltaZ * lastDistance;
                nextX = frame.currentX + frame.nextDeltaX;
                nextZ = currentZ + frame.nextDeltaZ;
                *(u32 *)(arg0 + 0xC4) &= ~1;
                *(u16 *)(arg0 + 0xC8) &= 0xFFFE;
                *(u16 *)(arg0 + 0xC8) &= 0xFFEF;
            }
            finalPos.x = nextX;
            finalPos.y = *(f32 *)(arg0 + 8);
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
            finalPos.x = *(f32 *)(point + 0);
            finalPos.y = *(f32 *)(arg0 + 8);
            finalPos.z = *(f32 *)(point + 4);
            targetPos = finalPos;
            *(u32 *)(arg0 + 0xC4) &= ~1;
            *(u16 *)(arg0 + 0xC8) &= 0xFFFE;
            *(u16 *)(arg0 + 0xC8) &= 0xFFEF;
        }
        *(RwV3d *)(arg0 + 4) = finalPos;
        *(u32 *)(arg0 + 0x98) |= 4;
        *(u16 *)(entry + 0x402) = index;
        if (!(*(u32 *)(arg0 + 0xC4) & 0x100))
        {
            *(RwV3d *)(arg0 + 0xD0) = targetPos;
        }
        else
        {
            *(RwV3d *)(arg0 + 0xD0) = *(RwV3d *)(arg0 + 0x4F8);
        }
        *(u16 *)(arg0 + 0xC8) |= 2;
    }
    if (*(u16 *)(arg0 + 0xC8) & 2)
    {
        targetPos.x = *(f32 *)(arg0 + 0xD0) - *(f32 *)(arg0 + 4);
        targetPos.z = *(f32 *)(arg0 + 0xD8) - *(f32 *)(arg0 + 0xC);
        if (((targetPos.x != 0.0f) ||
             (targetPos.z != 0.0f)) &&
            !(*(u32 *)(arg0 + 0x9C) & 0x2000))
        {
            turn = fGpffff8048 *
                   func_0044b950(targetPos.x, targetPos.z);
            RtQuatTransformVectors(&targetPos, &D_0060A0F0, 1,
                          (RwV3d *)(arg0 + 0x1C));
            angle = fGpffff8048 *
                    func_0044b950(targetPos.x, targetPos.z);
            nextZ = turn - angle;
            lastDistance =
                func_0044e7d8(func_0044b310(func_0044dcd8(nextZ)));
            if ((lastDistance > D_007614c0) &&
                !(*(u32 *)(arg0 + 0xC4) & 2))
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
                nextZ /= *(f32 *)(arg0 + 0x4F4);
                frame.rotation = *(RtQuat *)(arg0 + 0x1C);
                func_003dc740(&frame.rotation, D_0060A0E0, 2, nextZ);
            }
            else
            {
                angle = turn;
                func_003dc740(&frame.rotation, D_0060A0E0, 0, angle);
                *(u32 *)(arg0 + 0xC4) &= ~2;
                *(u16 *)(arg0 + 0xC8) &= 0xFFFD;
            }
            if (!(*(u32 *)(arg0 + 0x9C) & 0x2000))
            {
                *(RtQuat *)(arg0 + 0x1C) = frame.rotation;
                *(u32 *)(arg0 + 0x98) |= 4;
            }
        }
        else
        {
            *(u32 *)(arg0 + 0xC4) &= ~2;
            *(u16 *)(arg0 + 0xC8) &= 0xFFFD;
        }
    }
    return 0;
}
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
    func_00196d00(packet);
}
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

void btlUnitHoldPendingRotate(BtlUnitPacketCountRef* work);
u32 btlUnitRotatePacketUpdate(void* work);
void btlUnitReleasePendingRotate(BtlUnitPacketCountRef* work);
extern RwV3d D_00881430;

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
// FUN_00198050
s32 btlUnitRotateTowardUnitPacketUpdate(u8 *arg0)
{
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
    u8 *temp_17;
    u8 *temp_16;
    u8 *temp_2;
    u8 *temp_2_2;
    s32 temp_3;
    u8 temp_4;
    f32 var_f12;
    f32 var_f13;

    temp_17 = *(u8 **)(arg0 + 0);
    if (*(s32 *)(arg0 + 0xC) == 0)
    {
        temp_3 = *(s32 *)(arg0 + 8);
        if ((temp_3 & 2) != 0)
        {
            if ((temp_3 & 0x20) != 0)
            {
                temp_16 = *(u8 **)(arg0 + 4);
                work.scaled.x = *(f32 *)(temp_16 + 0x80) * *(f32 *)(temp_16 + 0x2C);
                work.scaled.y = *(f32 *)(temp_16 + 0x84) * *(f32 *)(temp_16 + 0x2C);
                work.scaled.z = *(f32 *)(temp_16 + 0x88) * *(f32 *)(temp_16 + 0x2C);
                RtQuatTransformVectors(&work.transformed, &work.scaled, 1,
                              (void *)(temp_16 + 0x1C));
                var_f12 = work.transformed.x
                    + (f32)((*(s16 *)(temp_16 + 0x94) * 0x19) - 0x6D6)
                    - *(f32 *)(temp_17 + 4);
                var_f13 = work.transformed.z
                    + (f32)((*(s16 *)(temp_16 + 0x96) * 0x19) - 0x6D6)
                    - *(f32 *)(temp_17 + 0xC);
            }
            else
            {
                temp_2 = *(u8 **)(arg0 + 4);
                var_f12 = *(f32 *)(temp_2 + 4) - *(f32 *)(temp_17 + 4);
                var_f13 = *(f32 *)(temp_2 + 0xC) - *(f32 *)(temp_17 + 0xC);
            }
            if ((var_f12 != 0.0f) || (var_f13 != 0.0f))
            {
                func_003dc740(&work.rotation, D_0060A0E0, 0,
                              fGpffff8048 * func_0044b950(var_f12, var_f13));
                if ((*(s32 *)(temp_17 + 0x9C) & 0x2000) == 0)
                {
                    *(struct Btl980Rot *)(temp_17 + 0x1C) = work.rotation;
                    *(s32 *)(temp_17 + 0x98) |= 4;
                }
            }
            *(s32 *)(temp_17 + 0xC4) &= ~2;
            *(u16 *)(temp_17 + 0xC8) &= 0xFFFD;
            btlUnitRequestLookAt(temp_17);
        }
        else
        {
            if ((temp_3 & 0x20) != 0)
            {
                func_00194ff0(*(u8 **)(arg0 + 4), temp_17 + 0xD0, 0, NULL);
            }
            else
            {
                temp_2_2 = *(u8 **)(arg0 + 4);
                *(RwV3d *)(temp_17 + 0xD0) = *(RwV3d *)(temp_2_2 + 4);
            }
            *(s32 *)(temp_17 + 0xC4) |= *(s32 *)(arg0 + 8);
            *(u16 *)(temp_17 + 0xC8) |= 2;
        }
    }
    temp_4 = ((*(u16 *)(temp_17 + 0xC8) & 2) != 0) ? 1 : 0;
    if (temp_4 == 0)
    {
        return 1;
    }
    *(s32 *)(arg0 + 0xC) += 1;
    return 0;
}
BtlPacket* btlUnitCreateResNullifiedAnimPacket(BtlUnit* unit, f32 param);
BtlPacket* btlUnitCreateArcOffsetPacket(BtlUnit* unit, s32 param);
BtlPacket* btlUnitCreateEnmDodgeAnimPacket(BtlUnit* unit, s32 param);
void btlUnitHoldPendingAnim(BtlUnitPacketCountRef* work);
void btlUnitReleasePendingAnim(BtlUnitPacketCountRef* work);

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

void btlUnitHoldPendingLookAtRef(BtlUnitPacketCountRef* work);
u32 btlUnitSetLookAtRanges(void* work);
void btlUnitReleasePendingLookAtRef(BtlUnitPacketCountRef* work);

// FUN_0019ACD0
void btlUnitModelLoadPacketInit(u8 *arg0)
{
    u8 sp30[0x80];
    u8 *p;
    u8 *obj;
    s32 flags;
    u16 coord;
    u8 *made;

    p = *(u8 **)arg0;
    *(u16 *)(p + 0xA0) = *(u16 *)(p + 0xA0) + 1;
    if (!(*(u16 *)(arg0 + 8) & 0x200)) {
        obj = *(u8 **)(p + 0xA00);
        if (obj != NULL) {
            coord = *(u16 *)(arg0 + 4);
            if (coord == *(u16 *)(obj + 0xD4)) {
                coord = *(u16 *)(arg0 + 6);
                if (coord == *(u16 *)(obj + 0xD6)) {
                    return;
                }
            }
            mdlDestroyModelObject(obj);
            *(u8 **)(p + 0xA00) = NULL;
        }
        made = mdlFindModelObject(*(u16 *)(arg0 + 4), *(u16 *)(arg0 + 6), 0);
        if (made != 0) {
            *(u8 **)(p + 0xA00) = (u8 *)mdlCloneModelObject(made);
            flags = *(s32 *)(p + 0x98) | 2;
            *(s32 *)(p + 0x98) = flags;
            *(s32 *)(p + 0x98) = flags | 1;
            return;
        }
    }
    if (!(*(u16 *)(arg0 + 8) & 0x10)) {
        mdlBuildModelPath(*(u16 *)(arg0 + 4), *(u16 *)(arg0 + 6), (char *)&sp30[0]);
        func_00440b68(&iGpffffa0b0, D_005F6D00, 0xD98);
        *(s32 *)(arg0 + 0xC) = func_00454a60(&sp30[0], 0);
        *(s32 *)(p + 0x98) = *(s32 *)(p + 0x98) | 1;
    }
    if (!(*(u16 *)(arg0 + 8) & 0x200)) {
        *(s32 *)(p + 0x98) = *(s32 *)(p + 0x98) & ~2;
    }
}
static inline u8 *btlUnitOffsetAdd(u32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
/* Ten-byte motion table entries; the second halfword is a percentage. */
typedef struct { s16 unk0; s16 rate; s16 unk4; s16 unk6; s16 unk8; } BtlMotionRate;
/* 1796/1808 bytes (three words of padding). The unit's model is loaded or
   adopted, its resource ids and material flags are applied, then its motion
   frame, scale and quaternion rotation are pushed to the model. Levers: the
   rotation is RtQuatUnitConvertToMatrix written out (all nine products
   first); the frame argument is `(u16)(cond ? frame : 0)` so the mask sits
   at the merge; the percentage scale goes through a `speed` local set to
   1.0f, which keeps retail's `mul.s` by one; the character table offset goes
   through the offset-first add helper; both tail switches are switches. */
// FUN_0019AE20
s32 btlUnitModelMotionPacketUpdate(u8 *arg0) {
    extern f32 mdlGetLayerKeyTime(void *a, s32 b, s64 c);
    extern u8 *iGpffffb3cc;
    extern void mdlSetLayerTime(void *a, s32 b, f32 c);
    extern u32 datCalcRandomBelow(u32 a);
    u8 *t17;
    u8 *t4;
    u8 *made;
    s32 t2;
    u16 v2;
    f32 speed;
    s16 v2_2;
    s16 s5;
    f32 f0;
    s16 t16;
    u16 t16_flags;
    s32 t16_sts;
    s32 t3_8;
    u8 t3;
    u8 sp80[128];
    struct { RwV3d right; u32 flags; RwV3d up; u32 pad1; RwV3d at; u32 pad2; RwV3d pos; u32 pad3; } mat;
    f32 sp100[3];

    t17 = *(u8 **)arg0;
    if ((*(s32 *)(t17 + 0x98) & 1) == 0) {
        made = mdlFindModelObject(*(u16 *)(arg0 + 4), *(u16 *)(arg0 + 6), 0);
        if (made != 0) {
            *(u8 **)(t17 + 0xA00) = (u8 *)mdlCloneModelObject(made);
        } else {
            mdlBuildModelPath(*(u16 *)(arg0 + 4), *(u16 *)(arg0 + 6), (char *)sp80);
            func_00440b68(&iGpffffa0b0, D_005F6D00, 0xDC9);
            *(s32 *)(arg0 + 0xC) = func_00454a60(sp80, 0);
            *(s32 *)(t17 + 0x98) |= 1;
        }
    }
    t4 = *(u8 **)(t17 + 0xA00);
    if (t4 == NULL) {
        if (H_Cdvd_IsFileLoaded(*(s32 *)(arg0 + 0xC)) != 0) {
            t4 = mdlCreateModelObjectFromResource(*(u16 *)(arg0 + 4), *(u16 *)(arg0 + 6), *(void **)(arg0 + 0xC), 0);
            *(u8 **)(t17 + 0xA00) = t4;
            func_002311a0((void *)t4);
            if (*(u16 *)(arg0 + 4) == 1) {
                mdlRunSetupCallback(*(u8 **)(t17 + 0xA00));
            }
        }
    } else if (mdlPrepareModel(t4) != 0) {
        if (*(u16 *)(arg0 + 8) & 4) {
            t3 = *(u8 *)(t17 + 0xA2);
            switch (t3) {
            case 0: {
                *(u16 *)(t17 + 0x9FE) = MT_Scene_CreateModelCharRes(*(u16 *)(t17 + 0xA4), *(u8 **)(t17 + 0xA00));
                func_0014a460(*(u16 *)(t17 + 0x9FE), 1);
                *(u32 *)(*(u8 **)(t17 + 0xA00) + 0xD8) |= 0x400;
                mdlClumpSetEnvMapState(mdlGetClump(*(u8 **)(t17 + 0xA00)));
            } break;
            case 1: {
                *(u16 *)(t17 + 0x9FE) = MT_Scene_CreateModelCharRes(btlFindFreeCharResId(), *(u8 **)(t17 + 0xA00));
                func_0014a460(*(u16 *)(t17 + 0x9FE), 1);
                t16_flags = *(u16 *)(btlUnitOffsetAdd(*(u16 *)(t17 + 0xA4) * 0xE8, iGpffffb3cc) + 0x18);
                if (t16_flags & 2) {
                    *(u32 *)(*(u8 **)(t17 + 0xA00) + 0xD8) |= 0x200;
                }
                if (t16_flags & 8) {
                    *(u32 *)(*(u8 **)(t17 + 0xA00) + 0xD8) |= 0x400;
                }
                if (t16_flags & 0x10) {
                    *(u32 *)(*(u8 **)(t17 + 0xA00) + 0xD8) |= 0x800;
                }
            } break;
            case 2: {
                *(u32 *)(*(u8 **)(t17 + 0xA00) + 0xD8) &= ~0x100;
                t16_sts = func_0010fbd0(*(u16 *)(t17 + 0xA4)) & 0xFFFF;
                if (t16_sts & 2) {
                    *(u32 *)(*(u8 **)(t17 + 0xA00) + 0xD8) |= 0x200;
                } else if (t16_sts & 4) {
                    btlUnitClearModelState(t17, 2);
                    *(u16 *)(arg0 + 8) &= ~1;
                }
                if (t16_sts & 8) {
                    *(u32 *)(*(u8 **)(t17 + 0xA00) + 0xD8) |= 0x400;
                }
                *(u16 *)(t17 + 0x9FE) = MT_Scene_CreateModelUnkRes(*(u16 *)(t17 + 0xA4), *(u8 **)(t17 + 0xA00));
            } break;
            }
        }
        t2 = *(s32 *)(t17 + 0x98) & ~1;
        *(s32 *)(t17 + 0x98) = t2;
        *(s32 *)(t17 + 0x98) = t2 | 2;
        btlUnitApplyModelState(t17, 4);
        if (*(u16 *)(arg0 + 8) & 8) {
            *(u8 *)(t17 + 0x33) = 0;
        }
        if (*(u16 *)(arg0 + 8) & 1) {
            btlUnitApplyModelState(t17, 2);
        }
        if (*(u16 *)(arg0 + 8) & 2) {
            btlUnitApplyModelState(t17, 1);
        }
        if (*(u16 *)(arg0 + 8) & 0x100) {
            *(u8 *)(*(u8 **)(t17 + 0xA00) + 0x280) = 0;
            *(u8 *)(*(u8 **)(t17 + 0xA00) + 0x281) = 0;
            *(u8 *)(*(u8 **)(t17 + 0xA00) + 0x282) = 0;
        }
        if (*(u16 *)(arg0 + 8) & 0x40) {
            func_001ee250(t17, 0);
        }
        if (*(u16 *)(arg0 + 8) & 0x20) {
            btlUnitUpdateStatusMotion(t17, 0);
            func_00198920(t17, *(s16 *)(t17 + 0x9EC), 0, *(f32 *)(t17 + 0x9F0), *(s8 *)(t17 + 0x9F4));
            t3_8 = *(s32 *)(t17 + 0x98) & 2;
            v2 = (u16)((t3_8 != 0) ? *(s16 *)(t17 + 0x9DA) : 0);
            if (t3_8 == 0) {
                v2_2 = 0;
            } else {
                speed = 1.0f;
                s5 = btlUnitGetMotionId(t17, v2);
                f0 = mdlGetLayerKeyTime(*(u8 **)(t17 + 0xA00), 0, s5);
                if (s5 < *(u16 *)(t17 + 0x9E4)) {
                    v2_2 = (s16)(s32)(f0 / (speed * ((f32)(*(BtlMotionRate **)(t17 + 0x9F8))[s5].rate / 100.0f)));
                } else {
                    v2_2 = (s16)(s32)f0;
                }
            }
            t16 = datCalcRandomBelow((u32)v2_2);
            if (*(s32 *)(t17 + 0x98) & 2) {
                mdlSetLayerTime(*(u8 **)(t17 + 0xA00), 0, (f32)t16);
            }
        }
        if (*(s32 *)(arg0 + 0xC) != 0) {
            H_Cdvd_Destroy(*(s32 *)(arg0 + 0xC));
        }
        t3 = *(u8 *)(t17 + 0xA2);
        switch (t3) {
        case 0:
        case 1: {
            f32 x = *(f32 *)(t17 + 0x1C);
            f32 y = *(f32 *)(t17 + 0x20);
            f32 z = *(f32 *)(t17 + 0x24);
            f32 w = *(f32 *)(t17 + 0x28);
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
            mdlApplyModelMatrix(*(u8 **)(t17 + 0xA00), &mat, 0);
            sp100[0] = sp100[1] = sp100[2] = *(f32 *)(t17 + 0x2C);
            mdlScale(*(u8 **)(t17 + 0xA00), sp100, 2);
            sp100[0] = *(f32 *)(t17 + 4) + *(f32 *)(t17 + 0x10);
            sp100[1] = *(f32 *)(t17 + 8) + *(f32 *)(t17 + 0x14);
            sp100[2] = *(f32 *)(t17 + 0xC) + *(f32 *)(t17 + 0x18);
            mdlTranslateMatrix(*(u8 **)(t17 + 0xA00), sp100, 2);
            mdlUpdateModelMatrix(*(u8 **)(t17 + 0xA00));
            func_0047a320(*(u8 **)(t17 + 0xA00));
        } break;
        }
        return 1;
    }
    return 0;
}
// FUN_0019BCB0
s32 btlUnitShowPacketUpdate(u8 *arg0) {
    btlUnitShowModel(*(u8 **)arg0);
    return 1;
}
// FUN_0019BD80
s32 btlUnitHidePacketUpdate(u8 *arg0) {
    btlUnitHideModel(*(u8 **)arg0);
    return 1;
}
// FUN_0019E130
void btlUnitReleasePendingLookAtRef(BtlUnitPacketCountRef* arg0) {
    u8 *temp;

    temp = *(u8 **)arg0;
    if (temp != NULL) {
        *(u16 *)(temp + 0xA0) = *(u16 *)(temp + 0xA0) - 1;
    }
}
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

// FUN_00194EE0
void btlUnitSetPos(BtlUnit* unit, const RwV3d* pos)
{
    unit->pos = *pos;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}

// FUN_00194F10
void btlUnitSetRot(BtlUnit* unit, const RtQuat* rot)
{
    if (!(unit->flags3 & BTLUNIT_FLAG3_NOROT))
    {
        unit->rot = *rot;
        unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    }
}

// FUN_00194F60
void btlUnitSetColor(BtlUnit* unit, RwRGBA col)
{
    unit->cols[0] = col;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}

// FUN_00194FA0
void btlUnitSetFlags(BtlUnit* unit, u16 flags)
{
    unit->flags |= flags;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}

// FUN_00194FC0
void btlUnitClearFlags(BtlUnit* unit, u16 flags)
{
    unit->flags &= ~flags;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}
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

// FUN_00195C50
void btlUnitGetGridSphereCenterTowardTarget(BtlUnit* unit, BtlUnit* target, RwV3d* param_3)
{
    RtQuat rotation;
    RwV3d scaled;
    RwV3d transformed;

    btlTargetBlendVectors((RwV3d*)&rotation, &unit->pos, &target->pos);
    scaled.x = unit->sphereCenter.x * unit->scale;
    scaled.y = unit->sphereCenter.y * unit->scale;
    scaled.z = unit->sphereCenter.z * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &rotation);
    param_3->x = transformed.x + (unit->unk_94 * 25 - 0x6d6);
    param_3->y = transformed.y + unit->pos.y;
    param_3->z = transformed.z + (unit->unk_96 * 25 - 0x6d6);
}

// FUN_00196B50
u32 btlUnitIsMoving(BtlUnit* unit)
{
    return (unit->movementFlags & 0x1) != 0;
}

// FUN_001973F0
BtlPacket* btlUnitCreateMovePacket(BtlUnit* unit, const RwV3d* targetPos, f32 speed, u32 flags)
{
    BtlPacket* packet;
    BtlUnitPacketMove* work;

    packet = btlPacketAlloc(0x10A, sizeof(BtlUnitPacketMove));

    packet->initFunc = (BtlPacketFunc)func_00196ce0;
    packet->updateFunc = func_00196d00;
    packet->destroyFunc = (BtlPacketFunc)func_001973d0;

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

// FUN_001974D0
void btlUnitHoldPendingPacket(BtlUnitPacketCountRef* packet)
{
    packet->unit->pendingPacketCount++;
}

// FUN_001979C0
void btlUnitReleasePendingPacket(BtlUnitPacketCountRef* packet)
{
    packet->unit->pendingPacketCount--;
}

// FUN_00198020
void btlUnitHoldPendingPair(BtlUnitPacketPair* packet)
{
    packet->first->pendingPacketCount++;
    packet->second->pendingPacketCount++;
}

// FUN_001982D0
void btlUnitReleasePendingPair(BtlUnitPacketPair* packet)
{
    packet->first->pendingPacketCount--;
    packet->second->pendingPacketCount--;
}

// FUN_0019A350
void btlUnitHoldPendingUnit(BtlUnitPacketUnitAtC* packet)
{
    packet->unit->pendingPacketCount++;
}

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

// FUN_0019DE70
void btlUnitSetChildValue(BtlUnitStateWork* work, u16 value)
{
    if (work != NULL && work->state == BTLUNIT_KIND_CHILD)
    {
        work->value = (u8)value;
    }
}

// FUN_0019DF00
void btlUnitHoldPendingLookAtRef(BtlUnitPacketCountRef* arg0) {
    u8 *temp;

    temp = *(u8 **)arg0;
    if (temp != NULL) {
        *(u16 *)(temp + 0xA0) = *(u16 *)(temp + 0xA0) + 1;
    }
}

// FUN_0019E1F0
void btlUnitHoldPendingLookAtUnits(BtlUnitPacketTwoUnits* packet)
{
    if (packet->first != NULL)
    {
        packet->first->pendingPacketCount++;
    }
    packet->second->pendingPacketCount++;
}

// FUN_0019E220
u32 btlUnitLookAtUnitPacketUpdate(u8* packet)
{
    extern u8* iGpffffb3ac;
    extern void mdlLookAtSetupSetRange(void* model, f32 x, f32 y);
    extern void mdlSetBlendWeight(void* model, f32 value);
    extern void btlUnitApplyModelState(void* unit, s32 state);
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

    if ((*(u16 *)(packet + 8) & 3) != 0)
    {
        if ((*(u16 *)(packet + 8) & 1) != 0)
        {
            firstCurrent = (u8 *)*(BtlUnit **)(iGpffffb3ac + 0x17c);
            while (firstCurrent != NULL)
            {
                if ((*(u32 *)(firstCurrent + 0x9c) & 8) != 0)
                {
                    firstTarget = *(u8 **)(packet + 4);
                    if (&firstHigh != NULL)
                    {
                        firstHigh = 70.0f;
                    }
                    if (&firstLow != NULL)
                    {
                        firstLow =
                            (*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30) ==
                             firstCurrent) ? 70.0f : 60.0f;
                    }
                    {
                        f32 highArg;
                        f32 lowArg;
                        lowArg = firstLow;
                        highArg = firstHigh;
                        if ((*(u32 *)(firstCurrent + 0x98) & 2) != 0)
                        {
                            mdlLookAtSetupSetRange(*(void **)(firstCurrent + 0xa00), highArg, lowArg);
                        }
                    }
                    if ((*(u32 *)(firstCurrent + 0x98) & 2) != 0)
                    {
                        mdlSetBlendWeight(*(void **)(firstCurrent + 0xa00), 0.25f);
                    }
                    *(u16 *)(firstCurrent + 0xb0) = 2;
                    *(u32 *)(firstCurrent + 0xb4) =
                        *(u32 *)(firstTarget + 0xa8);
                    btlUnitApplyModelState(firstCurrent, 3);
            }
                firstCurrent = (u8 *)*(BtlUnit **)(firstCurrent + 0xa68);
        }
        }
        if ((*(u16 *)(packet + 8) & 2) != 0)
        {
            secondCurrent = (u8 *)*(BtlUnit **)(iGpffffb3ac + 0x184);
            while (secondCurrent != NULL)
            {
                if ((*(u32 *)(secondCurrent + 0x9c) & 8) != 0)
                {
                    secondTarget = *(u8 **)(packet + 4);
                    if (&secondHigh != NULL)
                    {
                        secondHigh = 70.0f;
                    }
                    if (&secondLow != NULL)
                    {
                        secondLow =
                            (*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30) ==
                             secondCurrent) ? 70.0f : 60.0f;
                    }
                    {
                        f32 highArg;
                        f32 lowArg;
                        lowArg = secondLow;
                        highArg = secondHigh;
                        if ((*(u32 *)(secondCurrent + 0x98) & 2) != 0)
                        {
                            mdlLookAtSetupSetRange(*(void **)(secondCurrent + 0xa00), highArg, lowArg);
                        }
                    }
                    if ((*(u32 *)(secondCurrent + 0x98) & 2) != 0)
                    {
                        mdlSetBlendWeight(*(void **)(secondCurrent + 0xa00), 0.25f);
                    }
                    *(u16 *)(secondCurrent + 0xb0) = 2;
                    *(u32 *)(secondCurrent + 0xb4) =
                        *(u32 *)(secondTarget + 0xa8);
                    btlUnitApplyModelState(secondCurrent, 3);
                }
                secondCurrent = (u8 *)*(BtlUnit **)(secondCurrent + 0xa68);
            }
        }
    }
    else
    {
        singleTarget = *(u8 **)(packet + 4);
        singleCurrent = *(u8 **)(packet + 0);
        if (&singleHigh != NULL)
        {
            singleHigh = 70.0f;
        }
        if (&singleLow != NULL)
        {
            singleLow =
                (*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30) ==
                 singleCurrent) ? 70.0f : 60.0f;
        }
        {
            f32 highArg;
            f32 lowArg;
            lowArg = singleLow;
            highArg = singleHigh;
            if ((*(u32 *)(singleCurrent + 0x98) & 2) != 0)
            {
                mdlLookAtSetupSetRange(*(void **)(singleCurrent + 0xa00), highArg, lowArg);
            }
        }
        if ((*(u32 *)(singleCurrent + 0x98) & 2) != 0)
        {
            mdlSetBlendWeight(*(void **)(singleCurrent + 0xa00), 0.25f);
        }
        *(u16 *)(singleCurrent + 0xb0) = 2;
        *(u32 *)(singleCurrent + 0xb4) =
            *(u32 *)(singleTarget + 0xa8);
        btlUnitApplyModelState(singleCurrent, 3);
    }
    return 1;
}
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
u16 datCalcRandomBelow(u32 max);
void btlUnitSetModelAnimFrame(BtlUnit* unit, s32 param_2);
extern RwV3d D_0060a0d0;
extern f32 DAT_007613f8;

// FUN_0019E830
void btlUnitHoldPendingLookAt(u8 *arg0) {
    u8 *temp;

    temp = *(u8 **)arg0;
    if (temp != NULL) {
        *(u16 *)(temp + 0xA0) = *(u16 *)(temp + 0xA0) + 1;
    }
}
// FUN_0019E9D0
void btlUnitReleasePendingLookAt(u8 *arg0) {
    u8 *temp;

    temp = *(u8 **)arg0;
    if (temp != NULL) {
        *(u16 *)(temp + 0xA0) = *(u16 *)(temp + 0xA0) - 1;
    }
}
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

// FUN_001959D0
void btlUnitGetAnimBoundsWorldCenter(BtlUnit* unit, RwV3d* param_2)
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
    param_2->x = transformed.x + unit->pos.x;
    param_2->y = transformed.y + unit->pos.y;
    param_2->z = transformed.z + unit->pos.z;
}

// FUN_00195AA0
void btlUnitGetSphereCenterTowardTarget(BtlUnit* unit, BtlUnit* target, RwV3d* param_3)
{
    RtQuat rotation;
    RwV3d scaled;
    RwV3d transformed;

    btlTargetBlendVectors((RwV3d*)&rotation, &unit->pos, &target->pos);
    scaled.x = unit->sphereCenter.x * unit->scale;
    scaled.y = unit->sphereCenter.y * unit->scale;
    scaled.z = unit->sphereCenter.z * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &rotation);
    param_3->x = transformed.x + unit->pos.x;
    param_3->y = transformed.y + unit->pos.y;
    param_3->z = transformed.z + unit->pos.z;
}

// FUN_00195EA0
void btlUnitGetHudAnchor(BtlUnit* unit, RwV3d* param_2)
{
    RwV3d scaled;
    RwV3d transformed;

    scaled.x = unit->sphereCenter.x * unit->scale;
    scaled.y = unit->sphereCenter.y * unit->scale;
    scaled.z = unit->sphereCenter.z * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &unit->rot);
    param_2->x = transformed.x + unit->pos.x;
    param_2->y = transformed.y + unit->pos.y;
    param_2->z = transformed.z + unit->pos.z;
    param_2->y += unit->unk_8c * unit->scale * DAT_007613f8;
}

// FUN_00195F70
void btlUnitGetStatusMarkerPoint(BtlUnit* unit, RwV3d* param_2)
{
    RwV3d scaled;
    RwV3d transformed;

    scaled.x = unit->sphereCenter.x * unit->scale;
    scaled.y = unit->sphereCenter.y * unit->scale;
    scaled.z = unit->sphereCenter.z * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &unit->rot);
    param_2->x = transformed.x + unit->pos.x;
    param_2->y = transformed.y + unit->pos.y;
    param_2->z = transformed.z + unit->pos.z;
    param_2->y += unit->unk_8c * unit->scale * 0.25f;
}

// FUN_001987A0
void btlUnitSetRandomAnimFrame(BtlUnit* unit)
{
    s16 animation;

    animation = (s16)btlUnitMotionModelFrames(
        (u8 *)unit, (u16)(s32)btlUnitGetMotionState(unit), 1.0f);
    animation = (s16)datCalcRandomBelow(animation);
    btlUnitSetModelAnimFrame(unit, animation);
}

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

#include "include_asm.h"
#include "type.h"
#include "Kosaka/k_fldFrame_internal.h"


typedef struct RwMatrix
{
    RwV3d right;    // 0x00
    u32 flags;      // 0x0c
    RwV3d up;       // 0x10
    u32 pad1;       // 0x1c
    RwV3d at;       // 0x20
    u32 pad2;       // 0x2c
    RwV3d pos;      // 0x30
    u32 pad3;       // 0x3c
} RwMatrix;

// fGpffff8300 is the P3 sDegreesPerRadian counterpart, a small-data global at gp -0x7D00.
extern f32 fGpffff8300;
extern f32 RwV3dNormalize(RwV3d* out, const RwV3d* in);
extern f32 func_0044b920(f32 value);

extern u32 K_FldEvent_IsPosWithinFov(const RwMatrix* viewerMat, const RwV3d* targetPos, f32 fov);
extern f32 RwV3dLength(const RwV3d* vector);


#pragma push

/* Test the target direction against the viewer's inclusive angular bounds,
 * wrapping the degree interval across zero when necessary. */
// FUN_0014BFF0
u32 K_FldEvent_IsPosWithinFov(const RwMatrix* viewerMat, const RwV3d* targetPos, f32 fov)
{
    u32 isWithinFov;
    RwV3d viewDir;
    RwV3d targetDir;
    RwV3d forward = {0.0f, 0.0f, 1.0f};
    f32 viewAngle;
    f32 halfFov;
    f32 targetAngle;

    isWithinFov = 0;
    halfFov = fov / 2.0f;

    RwV3dNormalize(&viewDir, &viewerMat->at);

    targetDir.x = targetPos->x - viewerMat->pos.x;
    targetDir.y = targetPos->y - viewerMat->pos.y;
    targetDir.z = targetPos->z - viewerMat->pos.z;
    RwV3dNormalize(&targetDir, &targetDir);

    viewAngle = fGpffff8300 * func_0044b920((viewDir.x * forward.x) +
                                            (viewDir.y * forward.y) +
                                            (viewDir.z * forward.z));
    if (viewDir.x < 0.0f)
    {
        viewAngle *= -1.0f;
    }
    viewAngle += 180.0f;

    targetAngle = fGpffff8300 * func_0044b920((targetDir.x * forward.x) +
                                              (targetDir.y * forward.y) +
                                              (targetDir.z * forward.z));
    if (targetDir.x < 0.0f)
    {
        targetAngle *= -1.0f;
    }
    targetAngle += 180.0f;

    if (!(viewAngle + halfFov <= 360.0f))
    {
        if ((viewAngle - halfFov <= targetAngle) || !((viewAngle + halfFov) - 360.0f < targetAngle))
        {
            isWithinFov = 1;
        }
    }
    else
    {
        if (viewAngle - halfFov < 0.0f)
        {
            if (!(viewAngle + halfFov < targetAngle) || ((viewAngle - halfFov) + 360.0f <= targetAngle))
            {
                isWithinFov = 1;
            }
        }
        else if (!(viewAngle + halfFov < targetAngle) && (viewAngle - halfFov <= targetAngle))
        {
            isWithinFov = 1;
        }
    }

    return isWithinFov;
}
#pragma pop


#pragma push

// FUN_0014C240
u32 FldEvent_HasLineOfSight(const RwMatrix* viewerMat,
                  const RwV3d* targetPos,
                  f32 fov,
                  f32 maxDist)
{
    RwV3d delta;
    RwV3d line[2];
    RwV3d hitPoint;
    s32 result;
    u32 rayResult;

    result = 0;
    if (K_FldEvent_IsPosWithinFov(viewerMat, targetPos, fov) != 1)
    {
        goto done;
    }
    delta.x = targetPos->x - viewerMat->pos.x;
    delta.y = targetPos->y - viewerMat->pos.y;
    delta.z = targetPos->z - viewerMat->pos.z;
    if (RwV3dLength(&delta) >= maxDist)
    {
        goto done;
    }

    line[0] = viewerMat->pos;
    line[1] = *targetPos;
    // P4 retail lifts both raycast endpoints by 90.0f; P3 used 100.0f.
    line[0].y += 90.0f;
    line[1].y += 90.0f;
    if (FldFrame_RaycastSelectedWorld(line, &hitPoint) == 1)
    {
        return 0;
    }

    hitPoint = line[0];
    line[0] = line[1];
    line[1] = hitPoint;
    rayResult = FldFrame_RaycastSelectedWorld(line, &hitPoint);
    result = 1;
    if (rayResult == 1)
    {
        return 0;
    }
done:
    return result;
}
#pragma pop


#pragma push

/* Return the target distance inside the FOV-specific range or the unrestricted
 * near range; return -1 when neither strict distance bound accepts it. */
// FUN_0014C3D0
f32 FldEvent_GetVisibleDistance(const RwMatrix* viewerMat, const RwV3d* targetPos,
                  f32 fov, f32 fovMaxDist, f32 maxDist)
{
    RwV3d delta;
    f32 distance;
    f32 result;

    result = -1.0f;
    delta.x = targetPos->x - viewerMat->pos.x;
    delta.y = targetPos->y - viewerMat->pos.y;
    delta.z = targetPos->z - viewerMat->pos.z;
    distance = RwV3dLength(&delta);
    if ((K_FldEvent_IsPosWithinFov(viewerMat, targetPos, fov) == 1) &&
        (distance < fovMaxDist))
    {
        result = distance;
    }
    if (distance < maxDist)
    {
        result = distance;
    }
    return result;
}
/* Test full three-dimensional separation against an exclusive distance limit. */
// FUN_0014C4C0
u32 K_FldEvent_ArePosWithinDist(const RwV3d* posA, const RwV3d* posB, f32 maxDist)
{
    RwV3d diff;
    u32 withinDist;

    withinDist = 0;

    diff.x = posA->x - posB->x;
    diff.y = posA->y - posB->y;
    diff.z = posA->z - posB->z;

    if (RwV3dLength(&diff) < maxDist)
    {
        withinDist = 1;
    }

    return withinDist;
}
#pragma pop

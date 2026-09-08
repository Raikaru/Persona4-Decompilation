/* MATCH: object_size=1420; window=1424; normalized_diff=0;
 * code_relocations=21; uncovered_tail=4 zero alignment bytes.
 * Verified in the integrated src/promoted/code1_0022.c owner context.
 * opt_scalarize off preserves the two-component horizontal vectors.
 * Staged radius scaling, X-before-Y dot-product operands, scalar declaration
 * lifetimes and the scoped u16[2] skill records reproduce retail exactly.
 * Both center providers write XYZ, normalization/projection write only
 * their documented two or three floats, and both output poses contain
 * exactly seven initialized floats. No inline COP1 or invented inputs.
 */
#pragma opt_scalarize off
void func_002266b0(u8 *camera, f32 heightScale, f32 scale, f32 distanceOffset, f32 duration)
{
    RwV3d actorPosition;
    RwV3d targetPosition;
    RwV3d targetSnapshot;
    RwV3d center;
    RwV3d direction;
    RwV3d eye;
    RwV3d originalDirection;
    f32 targetXZ[2];
    f32 projected[2];
    f32 eyeXZ[2];
    f32 centerXZ[2];
    f32 previousView[2];
    f32 perpendicular[2];
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } poses;
    u8 *actor;
    u8 *target;
    u16 skill;
    f32 actorHeight;
    f32 separation;
    f32 centerOffset;
    f32 targetRadius;
    f32 lateralRadius;
    f32 side;
    f32 targetZ;
    f32 targetY;
    f32 fitRadius;
    f32 distance;
    f32 stepX;
    f32 stepY;
    f32 stepZ;
    f32 endDistance;

    actor = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
    target = *(u8 **)(*(u8 **)(*(u8 **)(camera + 0xE0) + 0x38) + 0x30);
    btlUnitGetSphereWorldCenter((BtlUnit *)actor, &actorPosition);
    btlUnitGetSphereWorldCenter((BtlUnit *)target, &targetPosition);
    actorHeight = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
    actorPosition.y = (0.0f + actorPosition.y) + heightScale * actorHeight;
    if (!((0.0f + actorPosition.y) + 0.5f * actorHeight < 450.0f)) {
        actorPosition.y = (0.0f + actorPosition.y) - fGpffff8030 * actorHeight;
    }
    direction.x = actorPosition.x - targetPosition.x;
    direction.y = actorPosition.y - targetPosition.y;
    direction.z = actorPosition.z - targetPosition.z;
    separation = RwV3dNormalize(&direction, &direction);
    previousView[0] = *(f32 *)(camera + 0x9C) - actorPosition.x;
    previousView[1] = *(f32 *)(camera + 0xA4) - actorPosition.z;
    func_003e41e0(previousView, previousView);
    centerOffset = fGpffff8128 * separation;
    center.x = direction.x * centerOffset;
    center.y = direction.y * centerOffset;
    center.z = direction.z * centerOffset;
    center.x = center.x + targetPosition.x;
    center.y = center.y + targetPosition.y;
    center.z = center.z + targetPosition.z;
    perpendicular[0] = direction.x;
    perpendicular[1] = direction.z;
    targetSnapshot = targetPosition;
    targetRadius = *(f32 *)(target + 0x90);
    targetRadius = targetRadius * *(f32 *)(target + 0x2C);
    lateralRadius = 1.5f * targetRadius;
    {
        f32 x = perpendicular[0];
        perpendicular[0] = perpendicular[1];
        perpendicular[1] = -x;
    }
    side = perpendicular[0] * previousView[0] + perpendicular[1] * previousView[1];
    targetY = targetSnapshot.y;
    eye.y = (0.0f + targetY) + 0.25f * (*(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C));
    if (!(side < 0.0f)) {
        eye.x = (0.0f + targetSnapshot.x) + direction.z * lateralRadius;
        targetZ = targetSnapshot.z;
        eye.z = (0.0f + targetZ) - direction.x * lateralRadius;
    } else {
        eye.x = (0.0f + targetSnapshot.x) - direction.z * lateralRadius;
        targetZ = targetSnapshot.z;
        eye.z = (0.0f + targetZ) + direction.x * lateralRadius;
    }
    originalDirection = direction;
    func_001bd780(&poses.firstRotation, &eye, &center, D_0060A0E0);
    RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1, &poses.firstRotation);
    centerXZ[0] = center.x;
    centerXZ[1] = center.z;
    eyeXZ[0] = eye.x;
    eyeXZ[1] = eye.z;
    targetXZ[0] = targetSnapshot.x;
    targetXZ[1] = targetZ;
    fitRadius = func_001ec3d0((u8 *)centerXZ, (u8 *)eyeXZ, (u8 *)targetXZ, (u8 *)projected);
    fitRadius = (0.0f + fitRadius) + scale * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
    eye.x = projected[0];
    eye.y = targetY;
    eye.z = projected[1];
    distance = fitRadius / tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    if (distance < 200.0f) {
        distance = 200.0f;
    }
    skill = *(u16 *)(*(u8 **)(camera + 0xE0) + 0x6E);
    if (skill < 0x1B8) {
        u16 (*table)[2] = (u16 (*)[2])iGpffffb3bc;
        if ((table[skill][1] & 0x400) != 0) {
            distance = distance + 150.0f;
        }
    }
    stepX = direction.x * (distance - 15.0f);
    stepY = direction.y * (distance - 15.0f);
    stepZ = direction.z * (distance - 15.0f);
    if (!(side < 0.0f)) {
        f32 radius = *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
        eye.x = (0.0f + eye.x) - originalDirection.z * radius;
        eye.z = (0.0f + eye.z) + originalDirection.x * radius;
    }
    eye.y = (0.0f + targetY) + 0.25f * (*(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C));
    poses.first.x = eye.x + stepX;
    poses.first.y = eye.y + stepY;
    poses.first.z = eye.z + stepZ;
    poses.secondRotation = poses.firstRotation;
    endDistance = 100.0f + (distance + distanceOffset);
    poses.second.x = (0.0f + eye.x) + direction.x * endDistance;
    poses.second.y = (0.0f + eye.y) + direction.y * endDistance;
    poses.second.z = (0.0f + eye.z) + direction.z * endDistance;
    if (poses.first.y < 25.0f) {
        poses.first.y = 25.0f;
    }
    if (poses.second.y < 25.0f) {
        poses.second.y = 25.0f;
    }
    func_001bc3a0((f32 *)&poses.first, (f32 *)&poses.first);
    func_001bc3a0((f32 *)&poses.second, (f32 *)&poses.second);
    func_001bcd40(*(u8 **)(camera + 0xE0), actor + 4, (f32 *)(target + 4), 3, 50.0f);
    func_001bac20((u16 *)camera, (f32 *)&poses.first, (f32 *)&poses.second, 1);
    func_001bbef0(camera, duration);
}
#pragma opt_scalarize on

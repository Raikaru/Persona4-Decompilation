/* EXACT_ORDINARY_C: object_size=1688; window=1696;
 * normalized_diff=0; fully_resolved_differing_bytes=0;
 * code_relocations=36; zero_alignment_tail=8. Integrated in code1_0022.c.
 *
 * Supersedes the 19-byte source-shape floor. The geometry workspace has
 * four real two-float vectors followed by the complete yaw quaternion.
 * Every member is consumed; no padding or uninitialized output is used.
 * opt_scalarize off preserves the actual vector stores and layout.
 * CameraPosePair is two positions and two quaternions, 56 bytes total.
 * func_001bd560 produces the entire first seven-float pose; the second
 * position and quaternion are produced before their consumers run.
 * func_001ec2b0 receives actual quaternion objects through its void* API.
 *
 * The transition provider masks the incoming flag argument to 16 bits.
 * All six active owner declarations now use u16 for that argument, in
 * each owner's existing float/GP order. The selectors in func_001bdd80
 * and func_001bdeb0 also use u16; leaving them word-sized introduces
 * truncation instructions. The six owners verify: 406 MATCH / 81 ASM,
 * no mismatches. This is compiler/relocation proof, not game execution.
 */
extern void func_001ec1c0(void *out, void *first, void *second);
extern void func_001bd5e0(f32 *out, f32 *in);
extern f32 fGpffff80fc;
extern f32 fGpffff80dc;

#pragma opt_scalarize off
void func_002250a0(u8 *camera, f32 distanceOffset, f32 duration)
{
    RwV3d actorPosition;
    RwV3d targetPosition;
    RwV3d basePosition;
    RwV3d focus;
    RwV3d offset;
    RwV3d direction;
    RwV3d eye;
    f32 baseXZ[2];
    f32 projectionXZ[2];
    struct {
        f32 perpendicular[2];
        f32 horizontal[2];
        f32 focusXZ[2];
        f32 eyeXZ[2];
        RtQuat yaw;
    } geometry;
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } poses;
    u8 *action;
    u8 *actor;
    u8 *target;
    u8 *farUnit;
    u8 *nearUnit;
    f32 framingScale;
    f32 actorRadius;
    f32 targetRadius;
    f32 length;
    f32 sideOffset;
    f32 along;
    f32 baseZ;
    f32 baseHeight;
    f32 side;
    f32 extent;
    f32 halfAngle;
    f32 distance;
    u16 flags;

    action = *(u8 **)(camera + 0xE0);
    actor = *(u8 **)(action + 0x30);
    target = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    framingScale = func_002249a0(actor, target, &actorPosition, &targetPosition);
    actorRadius = *(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C);
    targetRadius = *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
    geometry.horizontal[0] = *(f32 *)(camera + 0x9C) - actorPosition.x;
    geometry.horizontal[1] = *(f32 *)(camera + 0xA4) - actorPosition.z;
    func_003e41e0(geometry.horizontal, geometry.horizontal);

    if (*(u8 *)(actor + 0xA2) == 0) {
        func_001ec1c0((u8 *)&geometry.yaw, (u8 *)&actorPosition, (u8 *)&targetPosition);
        RtQuatTransformVectors(&offset, (const RwV3d *)D_0060A100, 1, &geometry.yaw);
        offset.x = offset.x * targetRadius;
        offset.y = offset.y * targetRadius;
        offset.z = offset.z * targetRadius;
        targetPosition.x = targetPosition.x + offset.x;
        targetPosition.y = targetPosition.y + offset.y;
        targetPosition.z = targetPosition.z + offset.z;
        direction.x = actorPosition.x - targetPosition.x;
        direction.y = actorPosition.y - targetPosition.y;
        direction.z = actorPosition.z - targetPosition.z;
        length = RwV3dNormalize(&direction, &direction);
        nearUnit = actor;
        farUnit = target;
        basePosition = actorPosition;
        sideOffset = 1.25f * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
        along = fGpffff8128 * length;
        focus.x = direction.x * along;
        focus.y = direction.y * along;
        focus.z = direction.z * along;
        baseHeight = basePosition.y;
        eye.y = baseHeight;
    } else {
        func_001ec1c0((u8 *)&geometry.yaw, (u8 *)&targetPosition, (u8 *)&actorPosition);
        RtQuatTransformVectors(&offset, (const RwV3d *)D_0060A100, 1, &geometry.yaw);
        offset.x = offset.x * actorRadius;
        offset.y = offset.y * actorRadius;
        offset.z = offset.z * actorRadius;
        actorPosition.x = actorPosition.x + offset.x;
        actorPosition.y = actorPosition.y + offset.y;
        actorPosition.z = actorPosition.z + offset.z;
        direction.x = actorPosition.x - targetPosition.x;
        direction.y = actorPosition.y - targetPosition.y;
        direction.z = actorPosition.z - targetPosition.z;
        length = RwV3dNormalize(&direction, &direction);
        nearUnit = target;
        farUnit = actor;
        basePosition = targetPosition;
        sideOffset = 0.5f * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
        along = fGpffff80fc * length;
        focus.x = direction.x * along;
        focus.y = direction.y * along;
        focus.z = direction.z * along;
        baseHeight = basePosition.y;
        eye.y = baseHeight;
    }
    focus.x = focus.x + targetPosition.x;
    focus.y = focus.y + targetPosition.y;
    focus.z = focus.z + targetPosition.z;
    geometry.perpendicular[0] = direction.z;
    geometry.perpendicular[1] = -direction.x;
    side = geometry.perpendicular[0] * geometry.horizontal[0] + geometry.perpendicular[1] * geometry.horizontal[1];
    if (!(side < 0.0f)) {
        eye.x = (0.0f + basePosition.x) + direction.z * sideOffset;
        baseZ = basePosition.z;
        eye.z = (0.0f + baseZ) - direction.x * sideOffset;
    } else {
        eye.x = (0.0f + basePosition.x) - direction.z * sideOffset;
        baseZ = basePosition.z;
        eye.z = (0.0f + baseZ) + direction.x * sideOffset;
    }
    func_001bd780(&poses.secondRotation, &eye, &focus, D_0060A0E0);
    RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1,
                           &poses.secondRotation);
    geometry.focusXZ[0] = focus.x;
    geometry.focusXZ[1] = focus.z;
    geometry.eyeXZ[0] = eye.x;
    geometry.eyeXZ[1] = eye.z;
    baseXZ[0] = basePosition.x;
    baseXZ[1] = baseZ;
    extent = func_001ec3d0((u8 *)geometry.focusXZ, (u8 *)geometry.eyeXZ,
                          (u8 *)baseXZ, (u8 *)projectionXZ);
    extent = (0.0f + extent) + framingScale *
        (*(f32 *)(nearUnit + 0x90) * *(f32 *)(nearUnit + 0x2C));
    eye.x = projectionXZ[0];
    eye.y = baseHeight;
    eye.z = projectionXZ[1];
    halfAngle = 0.5f * *(f32 *)(camera + 0xB8);
    distance = extent / tanf(fGpffff8110 * halfAngle);
    distance = distance + distanceOffset;
    if (distance < 100.0f) {
        distance = 100.0f;
    }
    direction.x = direction.x * distance;
    direction.y = direction.y * distance;
    direction.z = direction.z * distance;
    poses.second.x = eye.x + direction.x;
    poses.second.y = eye.y + direction.y;
    poses.second.z = eye.z + direction.z;
    if (poses.second.y < 22.5f) {
        poses.second.y = 22.5f;
    }
    func_001bd560((f32 *)&poses.first, (f32 *)(camera + 0x9C));
    if (!(func_001ec2b0(&poses.firstRotation,
                        &poses.secondRotation) <= fGpffff80dc)) {
        func_001bd5e0((f32 *)&poses.first, (f32 *)&poses.second);
        flags = 3;
    } else {
        flags = 0xC3;
    }
    func_001bcd40(*(u8 **)(camera + 0xE0), farUnit + 4,
                  (f32 *)&poses.second, flags, 50.0f);
    if (duration == 0.0f) {
        func_001bd5e0((f32 *)&poses.first, (f32 *)&poses.second);
        RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1,
                               &poses.firstRotation);
        direction.x = direction.x * 150.0f;
        direction.y = direction.y * 150.0f;
        direction.z = direction.z * 150.0f;
        poses.second.x = poses.first.x + direction.x;
        poses.second.y = poses.first.y + direction.y;
        poses.second.z = poses.first.z + direction.z;
        if (poses.second.y < 22.5f) {
            poses.second.y = 22.5f;
        }
        func_001bac20((u16 *)camera, (f32 *)&poses.first,
                      (f32 *)&poses.second, 1);
        func_001bbef0(camera, 2.0f);
    } else {
        func_001bac20((u16 *)camera, (f32 *)&poses.first,
                      (f32 *)&poses.second, 1);
        func_001bbef0(camera, duration);
    }
}

#pragma opt_scalarize on

/* ORDINARY_C_SOURCE_SHAPE_FLOOR: object_size=1688; window=1696;
 * normalized_diff=19; fully_resolved_differing_bytes=19;
 * fully_resolved_differing_words=19; code_relocations=36;
 * uncovered_tail=8 zero alignment bytes. Production ASM retained.
 *
 * Ordinary C reproduces the arithmetic, branches, calls and call targets.
 * opt_scalarize off retains the two-component perpendicular vector.
 * X-before-Y dot-product operands and the near/far and height/Z declaration
 * orders reduce the original 670 normalized differences to 19.
 * Seventeen remaining bytes are local stack offsets: the temporary yaw
 * quaternion is allocated after the four horizontal vectors instead of
 * before them. Two bytes select addiu instead of retail daddiu for flags.
 * Both seven-float poses are initialized; no undefined input is required.
 *
 * Tested without closing this floor: quaternion/Vec2 representations,
 * declaration order and scopes, explicit alignment, scalar widths and
 * mode expressions, pointer views, canonical float-first provider calls,
 * and supported propagation/decomposition/lifetime controls. b119 gives
 * 1884/1696 bytes and 1511 normalized differences. The following is the
 * best measured source, not a proof that an exact source is impossible.
 *
 * 0022512C: swc1 $f0, 0xd8($sp) | retail swc1 $f0, 0xc8($sp)
 * 0022513C: swc1 $f0, 0xdc($sp) | retail swc1 $f0, 0xcc($sp)
 * 00225140: addiu $a0, $sp, 0xd8 | retail addiu $a0, $sp, 0xc8
 * 0022515C: addiu $a0, $sp, 0xc0 | retail addiu $a0, $sp, 0xe0
 * 00225180: addiu $a3, $sp, 0xc0 | retail addiu $a3, $sp, 0xe0
 * 00225278: addiu $a0, $sp, 0xc0 | retail addiu $a0, $sp, 0xe0
 * 0022529C: addiu $a3, $sp, 0xc0 | retail addiu $a3, $sp, 0xe0
 * 002253BC: swc1 $f5, 0xd0($sp) | retail swc1 $f5, 0xc0($sp)
 * 002253C4: swc1 $f3, 0xd4($sp) | retail swc1 $f3, 0xc4($sp)
 * 002253C8: lwc1 $f4, 0xd8($sp) | retail lwc1 $f4, 0xc8($sp)
 * 002253CC: lwc1 $f2, 0xdc($sp) | retail lwc1 $f2, 0xcc($sp)
 * 0022546C: swc1 $f0, 0xe0($sp) | retail swc1 $f0, 0xd0($sp)
 * 00225474: swc1 $f0, 0xe4($sp) | retail swc1 $f0, 0xd4($sp)
 * 0022547C: swc1 $f0, 0xe8($sp) | retail swc1 $f0, 0xd8($sp)
 * 00225484: swc1 $f0, 0xec($sp) | retail swc1 $f0, 0xdc($sp)
 * 00225494: addiu $a0, $sp, 0xe0 | retail addiu $a0, $sp, 0xd0
 * 00225498: addiu $a1, $sp, 0xe8 | retail addiu $a1, $sp, 0xd8
 * 002255CC: addiu $a3, $zero, 3 | retail daddiu $a3, $zero, 3
 * 002255D8: addiu $a3, $zero, 0xc3 | retail daddiu $a3, $zero, 0xc3
 */
/* Missing declarations for src/promoted/code1_0022.c; retain its existing
 * RwV3d, RtQuat, pose-copy, look-quaternion and battle-camera declarations. */
typedef struct P4Vec4Holder_001EC2B0 P4Vec4Holder_001EC2B0;
extern f32 func_002249a0(u8 *actor, u8 *target, RwV3d *actorPosition, RwV3d *targetPosition);
extern void func_001ec1c0(u8 *out, u8 *first, u8 *second);
extern RwV3d *RtQuatTransformVectors(RwV3d *out, const RwV3d *in, s32 count, const RtQuat *quat);
extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
extern f32 func_003e41e0(f32 *out, f32 *in);
extern f32 func_001ec3d0(u8 *first, u8 *second, u8 *point, u8 *projection);
extern f32 func_001ec2b0(P4Vec4Holder_001EC2B0 *right, P4Vec4Holder_001EC2B0 *left);
extern void func_001bd5e0(f32 *out, f32 *in);
extern f32 tanf(f32 angle);
extern u8 D_0060A100[];
extern f32 fGpffff8128;
extern f32 fGpffff80fc;
extern f32 fGpffff8110;
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
    RtQuat yaw;
    f32 eyeXZ[2];
    f32 focusXZ[2];
    f32 horizontal[2];
    f32 perpendicular[2];
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
    u32 flags;

    action = *(u8 **)(camera + 0xE0);
    actor = *(u8 **)(action + 0x30);
    target = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    framingScale = func_002249a0(actor, target, &actorPosition, &targetPosition);
    actorRadius = *(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C);
    targetRadius = *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
    horizontal[0] = *(f32 *)(camera + 0x9C) - actorPosition.x;
    horizontal[1] = *(f32 *)(camera + 0xA4) - actorPosition.z;
    func_003e41e0(horizontal, horizontal);

    if (*(u8 *)(actor + 0xA2) == 0) {
        func_001ec1c0((u8 *)&yaw, (u8 *)&actorPosition, (u8 *)&targetPosition);
        RtQuatTransformVectors(&offset, (const RwV3d *)D_0060A100, 1, &yaw);
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
        func_001ec1c0((u8 *)&yaw, (u8 *)&targetPosition, (u8 *)&actorPosition);
        RtQuatTransformVectors(&offset, (const RwV3d *)D_0060A100, 1, &yaw);
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
    perpendicular[0] = direction.z;
    perpendicular[1] = -direction.x;
    side = perpendicular[0] * horizontal[0] + perpendicular[1] * horizontal[1];
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
    focusXZ[0] = focus.x;
    focusXZ[1] = focus.z;
    eyeXZ[0] = eye.x;
    eyeXZ[1] = eye.z;
    baseXZ[0] = basePosition.x;
    baseXZ[1] = baseZ;
    extent = func_001ec3d0((u8 *)focusXZ, (u8 *)eyeXZ,
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
    if (!(func_001ec2b0((P4Vec4Holder_001EC2B0 *)&poses.firstRotation,
                        (P4Vec4Holder_001EC2B0 *)&poses.secondRotation) <= fGpffff80dc)) {
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

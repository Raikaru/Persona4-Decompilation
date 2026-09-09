/* Exact camera pose updater recovery, func_001cc0a0.
 * Owner: src/Battle/btlCamera.c. Main independently resolved all23 relocations:
 * 1300 executable bytes equal retail, followed by12 zero alignment bytes.
 * All45 other owner functions preserve instruction bytes and relocation lists.
 * 
 * The initial complete candidate measured1272/1312 bytes,767 differing bytes.
 * Separate vector phases, existing RwV3d copies, declaration order, branch
 * polarity and clamp expressions reduced this to36 differences. Independent
 * measured agent ownership closed the remaining height-product load order and
 * stack layout with two real-value aggregates: four XZ pairs, and position plus
 * RtQuat. Every member is used and initialized before consumption. No padding
 * field, enlarged quaternion, or invented input explains the alignment gaps.
 * 
 * Both batch references were consulted: IDA src/Battle/btlCamera.c:183-339 and
 * Ghidra counterpart:195-331. Ghidra preserves entry actor2 size in f21 and the
 * tangent argument that IDA loses. The apparent20-byte quaternion scratch is not
 * a supported output extent; actual001BD780 writes a16-byte RtQuat. IDA's copy
 * shape and Ghidra's arithmetic remain aids, not replacements for retail evidence.
 * 
 * Actual integrated source passed12288 guarded Wasm32 cases with UB,
 * float-cast-overflow and float-divide-by-zero sanitizer traps. The fixture uses
 * actual001BD620/001BD780 matrix-builder and001EC3D0/003E4180 distance/length bodies.
 * Scene access, normalization, quaternion conversion/rotation and tangent are
 * explicit deterministic math/provider boundaries. An independent geometry
 * oracle checks target and final camera position over finite input heights,
 * scales, orientations and FOVs, with a0.002+0.00003*abs(expected) FP tolerance.
 * Whole-scene canaries and exact callback observations defend the entry size
 * snapshot and the late camera-work reload when providers mutate them.
 * No RenderWare rendering, PS2 FP exception, IEEE NaN, or hardware claim is made.
 *
 */

extern f32 fGpffff8118;
extern f32 func_001ec3d0(u8 *first, u8 *second, u8 *third, u8 *out);
extern f32 func_003e4180(f32 *vec);
extern RwV3d D_0060A0D0;

void func_001cc0a0(u8 *camera)
{
    RwV3d pos2;
    RwV3d pos1;
    RwV3d eye;
    RwV3d target;
    RwV3d dir;
    f32 actor2XZ[2];
    struct {
        f32 targetXZ[2];
        f32 eyeXZ[2];
        f32 dir2XZ[2];
        f32 dir1XZ[2];
    } xz;
    struct {
        RwV3d pos;
        RtQuat quat;
    } work;

    u8 *cameraWork;
    u8 *actor1;
    u8 *actor2;
    u16 flag;
    f32 scale2;
    f32 dot;
    f32 dist;
    f32 len;
    f32 tanVal;
    f32 factor;

    cameraWork = *(u8 **)(camera + 0xE0);
    actor1 = *(u8 **)(cameraWork + 0x30);
    flag = *(u8 *)(actor1 + 0xA2);
    actor2 = *(u8 **)(*(u8 **)(cameraWork + 0x38) + 0x30);

    scale2 = *(f32 *)(actor2 + 0x90) * *(f32 *)(actor2 + 0x2C);

    func_00195850(actor2, (f32 *)&pos2);
    func_00195850(actor1, (f32 *)&pos1);

    if (pos2.y > pos1.y) {
        pos2.y = (0.0f + pos2.y) - (*(f32 *)(actor2 + 0x8C) * *(f32 *)(actor2 + 0x2C)) * fGpffff8118;
        pos1.y = (0.0f + pos1.y) + (*(f32 *)(actor1 + 0x8C) * *(f32 *)(actor1 + 0x2C)) * DAT_00761278;
    } else {
        factor = *(f32 *)(actor2 + 0x8C) * *(f32 *)(actor2 + 0x2C);
        pos2.y = (0.0f + pos2.y) + fGpffff8118 * factor;
        pos1.y = (0.0f + pos1.y) - fGpffff8118 * (*(f32 *)(actor1 + 0x8C) * *(f32 *)(actor1 + 0x2C));
    }

    if (pos2.y < 65.0f) {
        pos2.y = 65.0f;
    }

    dir.x = pos1.x - pos2.x;
    dir.y = pos1.y - pos2.y;
    dir.z = pos1.z - pos2.z;
    dir.x *= D_0076122C;
    dir.y *= D_0076122C;
    dir.z *= D_0076122C;

    target.x = pos2.x + dir.x;
    target.y = pos2.y + dir.y;
    target.z = pos2.z + dir.z;

    dir.x = pos2.x - *(f32 *)(camera + 0x9C);
    dir.y = pos2.y - *(f32 *)(camera + 0xA0);
    dir.z = pos2.z - *(f32 *)(camera + 0xA4);

    xz.dir1XZ[0] = dir.x;
    xz.dir1XZ[1] = dir.z;
    func_003e41e0(xz.dir1XZ, xz.dir1XZ);

    func_003dcb40(&dir, &D_0060A0D0, 1, actor2 + 0x1C);

    xz.dir2XZ[0] = dir.x;
    xz.dir2XZ[1] = dir.z;
    func_003e41e0(xz.dir2XZ, xz.dir2XZ);

    dot = xz.dir2XZ[0] * xz.dir1XZ[0] + xz.dir2XZ[1] * xz.dir1XZ[1];

    if ((flag & 0xFFFF) == 0) {
        eye = pos2;
    } else {
        factor = 1.5f * scale2;

        dir.x *= factor;
        dir.y *= factor;
        dir.z *= factor;

        if (dot < 0.0f) {
            eye.x = pos2.x + dir.x;
            eye.y = pos2.y + dir.y;
            eye.z = pos2.z + dir.z;
        } else {
            eye.x = pos2.x - dir.x;
            eye.y = pos2.y - dir.y;
            eye.z = pos2.z - dir.z;
        }
    }

    func_001bd780(&work.quat, &eye, &target, &D_0060A0E0);

    xz.targetXZ[0] = target.x;
    xz.targetXZ[1] = target.z;
    xz.eyeXZ[0] = eye.x;
    xz.eyeXZ[1] = eye.z;
    actor2XZ[0] = pos2.x;
    actor2XZ[1] = pos2.z;

    dist = func_001ec3d0((u8 *)xz.targetXZ, (u8 *)xz.eyeXZ, (u8 *)actor2XZ, NULL);

    if ((flag & 0xFFFF) == 0) {
        scale2 = scale2 > 100.0f ? scale2 : 100.0f;
        dist += scale2;
    } else {
        scale2 = scale2 > 125.0f ? scale2 : 125.0f;
        dist += scale2;
    }

    if (dist < 160.0f) {
        dist = 160.0f;
    }

    dir.x = target.x - eye.x;
    dir.y = target.y - eye.y;
    dir.z = target.z - eye.z;

    len = func_003e4180((f32 *)&dir);

    tanVal = func_0044b868(DAT_00761200 * (0.5f * *(f32 *)(camera + 0xB8)));
    dist = len + (dist / tanVal);

    dist = dist > 0.0f ? dist : 0.0f;

    func_003dcb40(&dir, &D_0060A100, 1, &work.quat);

    dir.x *= dist;
    dir.y *= dist;
    dir.z *= dist;

    work.pos.x = target.x + dir.x;
    work.pos.y = target.y + dir.y;
    work.pos.z = target.z + dir.z;

    if (work.pos.y < 25.0f) {
        work.pos.y = 25.0f;
    }

    func_001bcd40(400.0f, *(u8 **)(camera + 0xE0), (u8 *)&work.pos, (u8 *)&target, 3);
    func_001bab00(camera, &work.pos);
}
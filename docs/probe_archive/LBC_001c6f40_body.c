/* Closest candidate archived on 2026-08-23; did not compile because an earlier generated declaration had an incompatible prototype. */
// FUN_001C6F40
s32 func_001c6f40(u8 *camera, s32 resultCode, s32 useAlternate,
                  s32 *firstOut, f32 *secondOut)
{
    struct C6Scratch
    {
        f32 position[4];
        f32 first[7];
        f32 final[7];
        u8 pad[8];
        f32 target[4];
        f32 unit[4];
        f32 candidate[4];
        f32 diff[4];
        f32 direction[4];
    } work;
    BtlUnit *unit;
    f32 radius;
    f32 normal;
    f32 height;
    f32 minDistance;
    f32 minRequired;
    f32 factor;
    s32 i;
    s32 *src;
    s32 *dst;

    func_001bd560(work.first, camera + 0x9C);
    radius = func_00196040(2, 0, work.target, &work.direction[3],
                           NULL, 1);
    if (work.direction[3] < 350.0f) {
        work.target[1] = 0.25f * work.direction[3];
    }
    else {
        work.target[1] = D_0076122C * work.direction[3];
    }
    unit = *(BtlUnit **)(*(u8 **)(camera + 0xE0) + 0x30);
    if (useAlternate != 0) {
        func_001958f0((u8 *)unit, work.unit);
    }
    else {
        func_00195850((u8 *)unit, work.unit);
    }
    radius = unit->sphereRadius * unit->scale;
    radius = radius * 2.5f;
    func_001ec1c0(work.position, work.unit, work.target);
    work.unit[1] = D_0076122C * (unit->unk_8C * unit->scale) +
                   work.unit[1] + 0.0f;
    func_003dcb40(work.direction, &D_0060A0D0, 1, work.position);
    work.direction[0] = work.direction[0] * radius;
    work.direction[1] = work.direction[1] * radius;
    work.direction[2] = work.direction[2] * radius;
    work.unit[0] = work.unit[0] + work.direction[0];
    work.unit[1] = work.unit[1] + work.direction[1];
    work.unit[2] = work.unit[2] + work.direction[2];
    work.diff[0] = work.unit[0] - work.target[0];
    work.diff[1] = work.unit[1] - work.target[1];
    work.diff[2] = work.unit[2] - work.target[2];
    normal = func_003e40b0(work.diff, work.diff);
    height = fGpffff811c * normal;
    work.candidate[0] = work.diff[0] * height + work.target[0];
    work.candidate[1] = work.diff[1] * height + work.target[1];
    work.candidate[2] = work.diff[2] * height + work.target[2];
    func_001bd780(work.final + 3, work.direction, work.candidate,
                  &D_0060A0E0);
    if (func_001ec2b0(work.first + 3, work.final + 3) > D_00761184) {
        resultCode = 1;
    }
    height = fGpffff811c * (unit->unk_8C * unit->scale);
    minDistance = height /
                  func_0044b868(DAT_00761200 *
                                 (0.5f * *(f32 *)(camera + 0xB8))) +
                  normal;
    minRequired = fGpffff811c * radius /
                  func_0044b868(DAT_00761200 *
                                 (0.5f * *(f32 *)(camera + 0xB8)));
    if (minDistance <= minRequired) {
        minDistance = minRequired;
    }
    func_003dcb40(work.direction, &D_0060A100, 1, work.final + 3);
    factor = minDistance *
             func_0044b868(DAT_00761200 *
                           (0.5f * *(f32 *)(camera + 0xB8)));
    factor = factor * 0.109375f;
    factor = factor * 1.25f;
    work.target[0] = work.direction[2] * factor +
                     work.target[0] + 0.0f;
    work.target[2] = (work.target[2] + 0.0f) -
                     work.direction[0] * factor;
    work.direction[0] = work.direction[0] * minDistance;
    work.direction[1] = work.direction[1] * minDistance;
    work.direction[2] = work.direction[2] * minDistance;
    work.final[0] = work.target[0] + work.direction[0];
    work.final[1] = work.target[1] + work.direction[1];
    work.final[2] = work.target[2] + work.direction[2];
    if (firstOut != NULL) {
        src = (s32 *)work.first;
        dst = firstOut;
        i = 7;
        do {
            *dst = *src;
            src++;
            dst++;
            i--;
        } while (i > 0);
    }
    if (secondOut != NULL) {
        src = (s32 *)work.final;
        dst = (s32 *)secondOut;
        i = 7;
        do {
            *dst = *src;
            src++;
            dst++;
            i--;
        } while (i > 0);
    }
    return resultCode;
}

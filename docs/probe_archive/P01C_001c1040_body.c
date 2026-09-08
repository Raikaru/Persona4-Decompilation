/* Complete first C reconstruction; production remains ASM.
 * 1876B symbol / 1888B retail window (1884B executable plus 4B zero tail).
 * All 48 code relocations resolved; 899 overlap bytes and 312 executable
 * word positions differ, including two uncovered retail words. No tables.
 * Ordinary C emits adda.s/madd.s and adda.s/msub.s: the prior ASM-only
 * inventory's blanket compiler-floor claim was false. Actual retail offsets
 * are +0x564/+0x568/+0x578/+0x57C.
 * Required owner contracts include the six-argument float bounds provider
 * func_00196040(u32,u32,void*,f32*,f32*,u32), the byte-state setter
 * func_0019de70(u8*,u8), full 28-byte pose copies, f32 normalization returns,
 * and u32 func_004bd050(void*). Caller requires valid camera/context/unit
 * objects and at least one eligible unit; no fabricated output initialization.
 * The single aggregate-layout refinement was worse (1908B). This preserves
 * the closer complete initial body, not a standalone translation unit.
 */
void func_001c1040(u8 *arg0, s32 arg1)
{
    union MotionVector {
        f32 c[3];
        struct { s64 xy; f32 z; } bits;
    } unitCenter, center, target, direction, delta, focus, flat1, flat2;
    f32 top;
    f32 horizontal[2];
    f32 matrix[16];
    f32 second[7];
    f32 first[7];
    f32 radius;
    f32 distance;
    f32 half;
    f32 angleScale;
    f32 side;
    f32 scale;
    f32 x;
    f32 y;
    f32 z;
    u8 *unit;
    u8 *resource;

    func_001bd560(first, arg0 + 0x9C);
    unit = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    func_00195850(unit, unitCenter.c);
    radius = func_00196040(3, 1, center.c, &top, 0, 0);
    if (func_001bc240(arg0) != 0 || func_001bc1b0(arg0) != 0) {
        resource = *(u8 **)(unit + 0xA0C);
        if (resource != 0) {
            func_0019de70(resource, 0);
            *(u8 **)(arg0 + 0x12C) = *(u8 **)(unit + 0xA0C);
            *(s16 *)(arg0 + 0x130) = 1;
        }
        center.c[1] = 0.75f * top;
        unitCenter.c[1] = center.c[1];
        half = 0.5f;
        angleScale = fGpffff8110;
        distance = radius / func_0044b868(angleScale * (half * *(f32 *)(arg0 + 0xB8)));
        if (distance < 1000.0f) distance = 1000.0f;
        if (center.c[0] == unitCenter.c[0] && center.c[2] == unitCenter.c[2]) {
            func_001c_copy_pair(&direction.bits.xy, &direction.bits.z,
                               (s64 *)D_0060A0F0, (f32 *)(D_0060A0F0 + 8));
        } else {
            direction.c[0] = center.c[0] - unitCenter.c[0];
            direction.c[1] = center.c[1] - unitCenter.c[1];
            direction.c[2] = center.c[2] - unitCenter.c[2];
            func_003e40b0(direction.c, direction.c);
        }
        x = direction.c[0] * radius;
        direction.c[0] = x;
        y = direction.c[1] * radius;
        direction.c[1] = y;
        z = direction.c[2] * radius;
        direction.c[2] = z;
        target.c[0] = center.c[0] + x;
        target.c[1] = center.c[1] + y;
        target.c[2] = center.c[2] + z;
        target.c[1] = 1.25f * top;
    } else {
        resource = *(u8 **)(unit + 0xA0C);
        if (resource != 0) {
            func_0019de70(resource, 0);
            *(u8 **)(arg0 + 0x12C) = *(u8 **)(unit + 0xA0C);
            *(s16 *)(arg0 + 0x130) = 1;
        }
        center.c[1] = 0.75f * top;
        unitCenter.c[1] = center.c[1];
        half = 0.5f;
        angleScale = fGpffff8110;
        distance = radius / func_0044b868(angleScale * (half * *(f32 *)(arg0 + 0xB8)));
        if (distance < 1200.0f) distance = 1200.0f;
        if (center.c[0] == unitCenter.c[0] && center.c[2] == unitCenter.c[2]) {
            func_001c_copy_pair(&direction.bits.xy, &direction.bits.z,
                               (s64 *)D_0060A0F0, (f32 *)(D_0060A0F0 + 8));
        } else {
            direction.c[0] = center.c[0] - unitCenter.c[0];
            direction.c[1] = center.c[1] - unitCenter.c[1];
            direction.c[2] = center.c[2] - unitCenter.c[2];
            func_003e40b0(direction.c, direction.c);
        }
        x = direction.c[0] * radius;
        direction.c[0] = x;
        y = direction.c[1] * radius;
        direction.c[1] = y;
        z = direction.c[2] * radius;
        direction.c[2] = z;
        target.c[0] = center.c[0] + x;
        target.c[1] = center.c[1] + y;
        target.c[2] = center.c[2] + z;
        target.c[1] = fGpffff807c * top;
        if (!(target.c[1] <= 200.0f)) target.c[1] = 200.0f;
        func_001c_copy_pair(&flat1.bits.xy, &flat1.bits.z,
                           &target.bits.xy, &target.bits.z);
        flat1.c[1] = center.c[1];
        delta.c[0] = flat1.c[0] - center.c[0];
        delta.c[1] = flat1.c[1] - center.c[1];
        delta.c[2] = flat1.c[2] - center.c[2];
        scale = fGpffff8128 * func_003e40b0(delta.c, delta.c);
        x = delta.c[0] * scale;
        focus.c[0] = x;
        y = delta.c[1] * scale;
        focus.c[1] = y;
        z = delta.c[2] * scale;
        focus.c[2] = z;
        focus.c[0] = x + center.c[0];
        focus.c[1] = y + center.c[1];
        focus.c[2] = z + center.c[2];
    }
    func_001c_copy_pair(&flat2.bits.xy, &flat2.bits.z,
                       &target.bits.xy, &target.bits.z);
    flat2.c[1] = center.c[1];
    delta.c[0] = flat2.c[0] - center.c[0];
    delta.c[1] = flat2.c[1] - center.c[1];
    delta.c[2] = flat2.c[2] - center.c[2];
    scale = fGpffff8128 * func_003e40b0(delta.c, delta.c);
    x = delta.c[0] * scale;
    focus.c[0] = x;
    y = delta.c[1] * scale;
    focus.c[1] = y;
    z = delta.c[2] * scale;
    focus.c[2] = z;
    focus.c[0] = x + center.c[0];
    focus.c[1] = y + center.c[1];
    focus.c[2] = z + center.c[2];
    func_001bd780(second + 3, target.c, focus.c, D_0060A0E0);
    direction.c[0] = target.c[0] - focus.c[0];
    direction.c[1] = target.c[1] - focus.c[1];
    direction.c[2] = target.c[2] - focus.c[2];
    func_003e40b0(direction.c, direction.c);
    side = (distance * func_0044b868(angleScale * (half * *(f32 *)(arg0 + 0xB8)))) * 0.21875f;
    horizontal[0] = direction.c[0];
    horizontal[1] = direction.c[2];
    func_003e41e0(horizontal, horizontal);
    focus.c[0] = (0.0f + focus.c[0]) + horizontal[1] * side;
    focus.c[2] = (0.0f + focus.c[2]) - horizontal[0] * side;
    x = direction.c[0] * distance;
    delta.c[0] = x;
    y = direction.c[1] * distance;
    delta.c[1] = y;
    z = direction.c[2] * distance;
    delta.c[2] = z;
    second[0] = focus.c[0] + x;
    second[1] = focus.c[1] + y;
    second[2] = focus.c[2] + z;
    if (func_004bd050(0) & 1) {
        func_003e0870(matrix, D_0060A0E0, -30.0f, 0);
    } else {
        func_003e0870(matrix, D_0060A0E0, 30.0f, 0);
    }
    func_003e4320(delta.c, direction.c, matrix);
    x = delta.c[0] * distance;
    delta.c[0] = x;
    y = delta.c[1] * distance;
    delta.c[1] = y;
    z = delta.c[2] * distance;
    delta.c[2] = z;
    first[0] = focus.c[0] + x;
    first[1] = focus.c[1] + y;
    first[2] = focus.c[2] + z;
    func_001bd780(first + 3, first, focus.c, D_0060A0E0);
    func_004b3110(8);
    func_001bc3a0(first, first);
    func_001bc3a0(second, second);
    if (first[1] < 25.0f) first[1] = 25.0f;
    if (second[1] < 25.0f) second[1] = 25.0f;
    func_001bac20(arg0, first, second, 1);
    func_001bbef0(arg0, 10.0f);
}

/*
 * Candidate archived: normalized diff remained nonzero (FPU register/scheduling
 * residual around the COP1 accumulator smoothstep sequence). The control flow,
 * scalar/vector loads, stack layout, and direct-path tail were matched, but the
 * emitted arithmetic did not close byte-exactly; keep the source placeholder.
 */
s32 func_00197a80(u8 *arg0)
{
    u8 *unit;
    P4_95730_Vec3 transformed;
    P4_95730_Vec3 delta;
    volatile P4_95730_Vec3 position;
    f32 temp_f2;
    f32 temp_f4;
    f32 progress;
    s32 use_scaled;

    unit = *(u8 **)arg0;
    if (func_0023df70(*(u16 *)(arg0 + 4)) != 0) {
        if (*(u16 *)(arg0 + 6) == 0) {
            *(f32 *)(arg0 + 0x24) = 0.5f;
            *(P4_95730_Vec3 *)(arg0 + 0xC) =
                *(P4_95730_Vec3 *)(unit + 4);
            func_003dcb40(&transformed, D_0060A100, 1, unit + 0x1C);
            *(f32 *)(arg0 + 0x18) = 400.0f * transformed.x;
            *(f32 *)(arg0 + 0x1C) = 400.0f * transformed.y;
            *(f32 *)(arg0 + 0x20) = 400.0f * transformed.z;
        }
        temp_f4 = *(f32 *)(arg0 + 0x24) + 0.03125f;
        *(f32 *)(arg0 + 0x24) = temp_f4;
        temp_f2 = 0.0f + (-1.0f) +
                  ((-2.0f * temp_f4) * temp_f4) +
                  (4.0f * temp_f4);
        progress = 2.0f;
        progress *= temp_f2 - 0.5f;
        if (progress < fGpffff82d4) {
            delta.x = *(f32 *)(arg0 + 0x18) * progress;
            delta.y = *(f32 *)(arg0 + 0x1C) * progress;
            delta.z = *(f32 *)(arg0 + 0x20) * progress;
            use_scaled = 0;
        } else {
            delta = *(P4_95730_Vec3 *)(arg0 + 0x18);
            use_scaled = 1;
        }
        position.x = *(f32 *)(arg0 + 0xC) + delta.x;
        position.y = *(f32 *)(arg0 + 0x10) + delta.y;
        position.z = *(f32 *)(arg0 + 0x14) + delta.z;
        *(volatile P4_95730_Vec3 *)(unit + 4) = position;
        *(s32 *)(unit + 0x98) |= 4;
        *(u16 *)(arg0 + 6) = *(u16 *)(arg0 + 6) + 1;
        return use_scaled;
    }
    *(s32 *)(unit + 0x10) = 0;
    *(f32 *)(unit + 0x14) =
        *(f32 *)(arg0 + 8) * D_005F6C10[*(u16 *)(arg0 + 6)];
    *(s32 *)(unit + 0x18) = 0;
    *(s32 *)(unit + 0x98) |= 4;
    {
        return (u16)((*(u16 *)(arg0 + 6) += 1) & 0xFFFF) >= 0x23U;
    }
}

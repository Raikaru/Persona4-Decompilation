/*
 * Probe archive for func_00197a80 (0x00197A80).
 *
 * Final candidate: object 564B, retail window 576B, normalized_diff 0
 * (scoped lverify LnE_00197a80).  The last ordinary residual before closure
 * was object 564B/window 576B, normalized_diff 9; differing word offsets
 * were 520, 524, and 528 (byte offsets 522, 524-531).  A local u16 count
 * emitted addiu/andi/store in the wrong order.  Preincrementing the pointed
 * u16 directly produced the retail addiu v0, store v0, and andi v0 sequence.
 *
 * COP1 chain reproduced: yes.  Natural C emitted the complete adda.s,
 * madda.s, and madd.s chain when opt_propagation was disabled for this
 * function; no chain instruction remained in the final residual.  The
 * function-scoped pragma is measured in the source and balanced afterward.
 *
 * Ruled out: volatile aggregate temporaries (banned and caused extra stores),
 * inline/whole-function asm (not used), direct inline smoothstep (selected
 * madd.s f1 instead of retail f2), separate 2.0f initialization (wrong
 * register/liveness), aggregate-field temporary (extra stack store), and
 * direct local-count assignment (wrong v1/andi/store order).
 *
 * Data references are real and placeable: D_0060A100 is the typed vector
 * object used by func_003dcb40, and D_005F6C10 is the retail float table.
 */
#pragma opt_propagation off
s32 func_00197a80(u8 *arg0)
{
    u8 *unit;
    P4_95730_Vec3 transformed;
    P4_95730_Vec3 delta;
    P4_95730_Vec3 position;
    f32 temp_f2;
    f32 progress;
    s32 use_scaled;
    unit = *(u8 **)arg0;
    if (func_0023df70(*(u16 *)(arg0 + 4)) != 0) {
        if (*(u16 *)(arg0 + 6) == 0) {
            *(f32 *)(arg0 + 0x24) = 0.5f;
            *(P4_95730_Vec3 *)(arg0 + 0xC) =
                *(P4_95730_Vec3 *)(unit + 4);
            func_003dcb40(&transformed, &D_0060A100, 1, unit + 0x1C);
            *(f32 *)(arg0 + 0x18) = 400.0f * transformed.x;
            *(f32 *)(arg0 + 0x1C) = 400.0f * transformed.y;
            *(f32 *)(arg0 + 0x20) = 400.0f * transformed.z;
        }
        progress = *(f32 *)(arg0 + 0x24);
        progress += 0.03125f;
        *(f32 *)(arg0 + 0x24) = progress;
        temp_f2 = 0.0f + (-1.0f) +
                  ((-2.0f * progress) * progress) +
                  (4.0f * progress);
        progress = 2.0f * (temp_f2 - 0.5f);
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
        *(P4_95730_Vec3 *)(unit + 4) = position;
        *(s32 *)(unit + 0x98) |= 4;
        *(u16 *)(arg0 + 6) = *(u16 *)(arg0 + 6) + 1;
        return use_scaled;
    }
    *(s32 *)(unit + 0x10) = 0;
    *(f32 *)(unit + 0x14) =
        *(f32 *)(arg0 + 8) * D_005F6C10[*(u16 *)(arg0 + 6)];
    *(s32 *)(unit + 0x18) = 0;
    *(s32 *)(unit + 0x98) |= 4;
    return ++*(u16 *)(arg0 + 6) >= 0x23U;
}
#pragma opt_propagation on

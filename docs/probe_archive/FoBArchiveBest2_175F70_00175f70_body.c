// Best attempted reconstruction for func_00175f70 (608B), archived after wrap-up.
// Fresh lane FoBArchiveBest2_175F70: object 608B/window 608B, residual 27 normalized words, MISMATCH.
// Retail GPRs: v1 (work pointer), a0 (state/flag and final integer conversion), v0 (constant/quotient),
//               a1 (source pointer), a2 (loop counter), a3 (destination pointer).
// Retail FPRs: f0, f1, f2, f3, f12, f13. No saved registers.
// Rules/probes: fixed loop source stride (+2 s32 elements), canonical f32 GP globals with
// pointer-cast reloads for repeated accesses, explicit state local, reversed f2/f3 declaration order,
// angle normalization and signed shortest-difference shape, integer fabs/30 conversion.
// Remaining differences are register allocation: work pointer a0 vs retail v1, state/flag v1 vs a0.
// Tried and rejected: direct canonical globals (CSE, 592B); opt_common_subs off (644B); aliases
// at the same GP addresses (608B/33 words, rejected); typed s32 work pointer (compile error);
// base-pointer liveness (612B/58 words); pragma opt_propagation off (556B).

s32 func_00175f70(const u8 *arg0, s32 *arg1, f32 arg2, f32 arg3)
{
    s32 state;
    u8 *temp_3;
    u8 *var_7;
    s32 temp_2;
    s32 temp_4;
    s32 var_2;
    s32 var_4;
    s32 var_6;
    f32 var_f12;
    f32 var_f13;
    f32 var_f3;
    f32 var_f2;
    temp_3 = *(u8 **)((u8 *)arg0 + 0x38);
    state = *(s32 *)(temp_3 + 0x40);
    if (state == 1)
        return 0;
    var_f12 = arg2;
    var_f13 = arg3;
    var_6 = 8;
    var_7 = temp_3;
    do {
        temp_4 = *(s32 *)(arg1 + 0);
        temp_2 = *(s32 *)(arg1 + 1);
        arg1 += 2;
        var_6 -= 1;
        *(s32 *)(var_7 + 0) = temp_4;
        *(s32 *)(var_7 + 4) = temp_2;
        var_7 += 8;
    } while (var_6 > 0);
    if (!(var_f12 <= 360.0f))
        var_f12 -= 360.0f;
    *(f32 *)(temp_3 + 0x4C) = var_f12;
    if (!(var_f13 <= 360.0f))
        var_f13 -= 360.0f;
    *(f32 *)(temp_3 + 0x50) = var_f13;
    if (var_f12 < var_f13) {
        if (!(var_f12 <= fGpffff8558))
            var_f12 = 0.0f;
        if (!(var_f13 <= *(f32 *)(void *)&fGpffff8558))
            var_f13 = 360.0f;
        if (var_f12 < iGpffff8214)
            var_f12 = 0.0f;
        if (var_f13 < *(f32 *)(void *)&iGpffff8214)
            var_f13 = 360.0f;
        var_f3 = var_f13 - var_f12;
        var_f2 = var_f12 + (360.0f - var_f13);
        var_4 = 0;
    } else {
        if (!(var_f12 <= fGpffff8558))
            var_f12 = 360.0f;
        if (!(var_f13 <= *(f32 *)(void *)&fGpffff8558))
            var_f13 = 0.0f;
        if (var_f12 < iGpffff8214)
            var_f12 = 360.0f;
        if (var_f13 < *(f32 *)(void *)&iGpffff8214)
            var_f13 = 0.0f;
        var_f3 = var_f12 - var_f13;
        var_f2 = var_f13 + (360.0f - var_f12);
        var_4 = 1;
    }
    if (fabsf(var_f3) < fabsf(var_f2)) {
        *(f32 *)(temp_3 + 0x54) = var_f3;
        if (var_4 == 1)
            *(f32 *)(temp_3 + 0x54) = *(f32 *)(temp_3 + 0x54) * -1.0f;
    } else {
        *(f32 *)(temp_3 + 0x54) = var_f2;
        if (var_4 == 0)
            *(f32 *)(temp_3 + 0x54) = *(f32 *)(temp_3 + 0x54) * -1.0f;
    }
    if (!(fabsf(*(f32 *)(temp_3 + 0x54)) <= 45.0f)) {
        var_2 = (s32)fabsf(*(f32 *)(temp_3 + 0x54)) / 30;
        if (var_2 <= 0)
            var_2 = 1;
        *(s32 *)(temp_3 + 0x5C) = var_2;
        *(s32 *)(temp_3 + 0x58) = 0;
        *(f32 *)(temp_3 + 0x54) =
            *(f32 *)(temp_3 + 0x54) / (f32) *(s32 *)(temp_3 + 0x5C);
        *(s32 *)(temp_3 + 0x40) = 1;
        return 1;
    }
    return 0;
}

s32 func_00371c70(u8 *arg0) {
    f32 var_f12;
    f32 var_f1;
    f32 inv;
    f32 f3;
    f32 f4;
    f32 f5;
    f32 f6;
    u32 temp_2;
    u32 temp_2_2;

    temp_2 = *(u16 *)(arg0 + 0);
    if ((s32)temp_2 >= 0) {
        var_f1 = (f32)temp_2;
    } else {
        var_f1 = (f32)((temp_2 >> 1) | (temp_2 & 1));
        var_f1 += var_f1;
    }
    if (var_f1 < *(f32 *)(arg0 + 4)) {
        temp_2_2 = *(u16 *)(arg0 + 0) + 1;
        *(u16 *)(arg0 + 0) = (u16)temp_2_2;
        temp_2_2 = *(u16 *)(arg0 + 0);
        if ((s32)temp_2_2 >= 0) {
            var_f12 = (f32)temp_2_2;
        } else {
            var_f12 = (f32)((temp_2_2 >> 1) | (temp_2_2 & 1));
            var_f12 += var_f12;
        }
        var_f12 = func_00373cb0(0, var_f12, *(f32 *)(arg0 + 8), *(f32 *)(arg0 + 4));
        inv = 1.0f - var_f12;

        f6 = *(f32 *)(arg0 + 0x3C) * var_f12;
        f6 = var_f12 * f6;
        f5 = 3.0f * *(f32 *)(arg0 + 0x30);
        f5 = f5 * inv;
        f5 = var_f12 * f5;
        f4 = *(f32 *)(arg0 + 0x18) * inv;
        f4 = inv * f4;
        f3 = 3.0f * *(f32 *)(arg0 + 0x24);
        f3 = f3 * inv;
        f3 = inv * f3;
        *(f32 *)(arg0 + 0xC) = var_f12 * f3 + inv * f4 + var_f12 * f5 + var_f12 * f6;

        f6 = *(f32 *)(arg0 + 0x40) * var_f12;
        f6 = var_f12 * f6;
        f5 = 3.0f * *(f32 *)(arg0 + 0x34);
        f5 = f5 * inv;
        f5 = var_f12 * f5;
        f4 = *(f32 *)(arg0 + 0x1C) * inv;
        f4 = inv * f4;
        f3 = 3.0f * *(f32 *)(arg0 + 0x28);
        f3 = f3 * inv;
        f3 = inv * f3;
        *(f32 *)(arg0 + 0x10) = var_f12 * f3 + inv * f4 + var_f12 * f5 + var_f12 * f6;

        f6 = *(f32 *)(arg0 + 0x44) * var_f12;
        f6 = var_f12 * f6;
        f5 = 3.0f * *(f32 *)(arg0 + 0x38);
        f5 = f5 * inv;
        f5 = var_f12 * f5;
        f4 = *(f32 *)(arg0 + 0x20) * inv;
        f4 = inv * f4;
        f3 = *(f32 *)(arg0 + 0x2C) * 3.0f;
        f3 = f3 * inv;
        f3 = inv * f3;
        *(f32 *)(arg0 + 0x14) = var_f12 * f3 + inv * f4 + var_f12 * f5 + var_f12 * f6;
        return 0;
    }
    return 1;
}

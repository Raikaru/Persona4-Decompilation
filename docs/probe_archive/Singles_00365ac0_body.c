/* Closest candidate: object 1328B/window 1088B, normalized_diff 988.
   The 1088-byte retail body remains compiler-floor due prologue ordering,
   color-byte extraction, and loop scheduling; source was reverted. */
void func_00365ac0(s64 arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1,
                   f32 fparg2, f32 fparg3)
{
    struct {
        u8 pad[8];
        s64 packed;
        f32 output[160];
    } sp90;
    f32 temp_f27;
    f32 temp_f26;
    f32 temp_f25;
    f32 temp_f24;
    f32 temp_f23;
    f32 temp_f22;
    f32 temp_f0;
    f32 pos_x;
    f32 pos_y;
    f32 temp_f11;
    f32 temp_f10;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f1_4;
    u8 *camera;
    u8 *out;
    s32 temp_10;
    s32 temp_10_2;
    s32 temp_10_3;
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    s32 temp_5;
    s32 temp_6;
    s32 temp_7;
    s32 temp_8;
    s32 temp_9;
    s32 var_11;
    s32 var_11_2;
    s32 var_13;
    s32 var_4;
    s32 var_5;
    temp_f27 = fparg1;
    temp_f26 = fparg2;
    temp_f25 = fparg3;
    sp90.packed = arg0;
    pos_x = *(f32 *)((u8 *)&sp90.packed);
    pos_y = *(f32 *)((u8 *)&sp90.packed + 4);
    temp_f26 = temp_f26 * iGpffff83d4;
    temp_f24 = D_008872F8[0] - fparg0;
    camera = func_00457120();
    temp_f23 = 1.0f / *(f32 *)(camera + 0x80);
    temp_19 = (((u32)arg1 & 0xFF000000) >> 24) & 0xFF;
    temp_18 = (((u32)arg1 & 0x00FF0000) >> 16) & 0xFF;
    temp_17 = (((u32)arg1 & 0x0000FF00) >> 8) & 0xFF;
    temp_16 = (u32)arg1 & 0xFF;
    temp_f22 = func_0044b7b0(temp_f27);
    temp_f0 = func_0044b610(temp_f27);
    temp_9 = temp_19 & 1;
    temp_8 = temp_18 & 1;
    temp_7 = temp_17 & 1;
    temp_6 = temp_16 & 1;
    var_5 = 0;
    for (var_5 = 0; var_5 < 10; var_5++) {
        var_13 = var_5 & 7;
        if (var_5 < 0 && var_13 != 0) {
            var_13 -= 8;
        }
        temp_10 = var_5 + 6;
        var_4 = temp_10 & 7;
        if (temp_10 < 0 && var_4 != 0) {
            var_4 -= 8;
        }
        temp_10_2 = var_13 & 3;
        if (var_13 < 0 && temp_10_2 != 0) {
            temp_10_2 -= 4;
        }
        temp_10_2 = temp_10_2 ^ 1;
        temp_5 = temp_10_2 < 1;
        temp_10_3 = var_13 + 1;
        var_11 = temp_10_3 & 3;
        if (temp_10_3 < 0 && var_11 != 0) {
            var_11 -= 4;
        }
        if (var_11 < 0) {
            var_11 += 1;
        }
        temp_f11 = (f32)((var_13 < 4) ? 1 : -1) *
                   (temp_f26 * (f32)(var_11 / 2) +
                    temp_f25 * (f32)temp_5);
        temp_10_2 = var_4 & 3;
        if (var_4 < 0 && temp_10_2 != 0) {
            temp_10_2 -= 4;
        }
        temp_10_2 = temp_10_2 ^ 1;
        temp_5 = temp_10_2 < 1;
        temp_10_3 = var_4 + 1;
        var_11_2 = temp_10_3 & 3;
        if (temp_10_3 < 0 && var_11_2 != 0) {
            var_11_2 -= 4;
        }
        if (var_11_2 < 0) {
            var_11_2 += 1;
        }
        temp_f10 = (f32)((var_4 < 4) ? 1 : -1) *
                   (temp_f26 * (f32)(var_11_2 / 2) +
                    temp_f25 * (f32)temp_5);
        out = (u8 *)sp90.output + (var_5 << 6);
        *(f32 *)(out + 0) =
            temp_f11 * temp_f0 + pos_x + 0.0f - temp_f10 * temp_f22;
        *(f32 *)(out + 4) =
            temp_f11 * temp_f22 + temp_f10 * temp_f0 + pos_y + 0.0f;
        *(f32 *)(out + 8) = temp_f24;
        *(f32 *)(out + 0x18) = temp_f23;
        if (temp_19 >= 0) {
            var_f1 = (f32)temp_19;
        } else {
            var_f1 = 2.0f * (f32)(((u32)temp_19 >> 1) | temp_9);
        }
        *(f32 *)(out + 0x20) = var_f1;
        if (temp_18 >= 0) {
            var_f1_2 = (f32)temp_18;
        } else {
            var_f1_2 = 2.0f * (f32)(((u32)temp_18 >> 1) | temp_8);
        }
        *(f32 *)(out + 0x24) = var_f1_2;
        if (temp_17 >= 0) {
            var_f1_3 = (f32)temp_17;
        } else {
            var_f1_3 = 2.0f * (f32)(((u32)temp_17 >> 1) | temp_7);
        }
        *(f32 *)(out + 0x28) = var_f1_3;
        if (temp_16 >= 0) {
            var_f1_4 = (f32)temp_16;
        } else {
            var_f1_4 = 2.0f * (f32)(((u32)temp_16 >> 1) | temp_6);
        }
        *(f32 *)(out + 0x2C) = var_f1_4;
    }
    D_00887300[0](1, 0);
    if (arg2 != 0 && temp_16 == 0xFF) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](4, sp90.output, 10);
    if (arg2 != 0 && temp_16 == 0xFF) {
        iGpffffabe8 &= ~0x80;
    }
}

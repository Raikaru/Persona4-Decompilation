/* Closest candidate for func_0020ef10; retained for future register-allocation work.
 * Lane0020_ef10_17: object 1460B/window 1472B, 32 differing words.
 */
void func_0020ef10(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3)
{
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f3;
    f32 temp_f2;
    f32 var_f2;
    f32 var_f2_2;
    u8 *temp_16;
    s32 temp_20;
    s32 var_2;
    s32 var_3;
    s32 var_3_2;
    s32 var_4;
    u8 temp_21;
    u8 temp_21_2;

    extern void func_0021b310(u8 *arg0, s32 arg1);

    temp_16 = (u8 *)func_00452560(*(s32 *)(arg0 + 4));
    temp_20 = *(s32 *)(arg1 + 0x10);
    if (temp_20 < 0) {
        temp_f3 = 0.0f;
    } else if (temp_20 < 4) {
        temp_f3 = (f32)temp_20 / 4.0f;
    } else {
        temp_f3 = 1.0f;
    }
    if (temp_20 < 4) {
        temp_f2 = 0.0f;
    } else if (temp_20 < 8) {
        temp_f2 = (f32)(temp_20 - 4) / 4.0f;
    } else {
        temp_f2 = 1.0f;
    }
    temp_f2 = temp_f3 * 3.0f - temp_f2 * 2.0f;
    if (!(temp_f2 <= 0.0f)) {
        if (!(temp_f2 <= 1.0f)) {
            var_2 = 0xFF;
        } else {
            temp_f1 = temp_f2 * 255.0f;
            if (2.1474836e9f <= temp_f1) {
                goto ef10_alpha_big1;
            }
            var_3 = (s32)temp_f1;
            var_3 &= 0xFF;
            goto ef10_alpha_done1;
        ef10_alpha_big1:
            var_3 = (s32)(temp_f1 - 2.1474836e9f);
            var_3 |= 0x80000000;
            var_3 &= 0xFF;
        ef10_alpha_done1:
            var_2 = var_3 & 0xFF;
        }
        temp_21 = var_2 & 0xFF;
        func_00201650(temp_16, 10, 0x12, 61.0f,
                      46.0f - 20.0f * temp_f20 - 16.0f,
                      0xF4, 0xFF, 0xE, temp_21);
        temp_f21 = 10.0f * temp_f20;
        temp_f20 = (87.0f + temp_f21) - 16.0f;
        func_00201650(temp_16, 10, 0x13, 37.0f - temp_f21,
                      temp_f20, 0xF4, 0xFF, 0xE, temp_21);
        func_00201650(temp_16, 10, 0x14, 84.0f + temp_f21,
                      temp_f20, 0xF4, 0xFF, 0xE, temp_21);
    }
    if (temp_20 < 2) {
        var_f2 = 0.0f;
    } else if (temp_20 < 5) {
        var_f2 = (f32)(temp_20 - 2) / 3.0f;
    } else {
        var_f2 = 1.0f;
    }
    if (!(var_f2 <= 0.0f)) {
        temp_f1_2 = 255.0f * var_f2;
        if (2.1474836e9f <= temp_f1_2) {
            goto ef10_alpha_big2;
        }
        var_3_2 = (s32)temp_f1_2;
        var_3_2 &= 0xFF;
        goto ef10_alpha_done2;
    ef10_alpha_big2:
        var_3_2 = (s32)(temp_f1_2 - 2.1474836e9f);
        var_3_2 |= 0x80000000;
        var_3_2 &= 0xFF;
    ef10_alpha_done2:
        temp_21_2 = var_3_2 & 0xFF;
        temp_f20_2 = (73.0f + (20.0f * (1.0f - var_f2))) - 16.0f;
        func_00201650(temp_16, 10, 0xC, 47.0f, temp_f20_2,
                      0xF4, 0xFF, 0xE, temp_21_2);
        func_00201650(temp_16, 10, 0xB, 47.0f, temp_f20_2,
                      0x36, 0x2E, 0, temp_21_2);
    }
    if (temp_20 < 2) {
        var_f2_2 = 0.0f;
    } else if (temp_20 < 5) {
        var_f2_2 = (f32)(temp_20 - 2) / 3.0f;
    } else {
        var_f2_2 = 1.0f;
    }
    temp_f1_3 = 255.0f * var_f2_2;
    if (2.1474836e9f <= temp_f1_3) {
        goto ef10_alpha_big3;
    }
    var_4 = (s32)temp_f1_3;
    var_4 &= 0xFF;
    goto ef10_alpha_done3;
ef10_alpha_big3:
    var_4 = (s32)(temp_f1_3 - 2.1474836e9f);
    var_4 |= 0x80000000;
    var_4 &= 0xFF;
ef10_alpha_done3:
    *(u8 *)(arg3 + 4) = (u8)var_4;
    *(f32 *)(arg3 + 0) = 20.0f * (1.0f - var_f2_2);
    if ((*(u16 *)(arg1 + 0x14) & 4) != 0) {
        *(f32 *)(arg3 + 0xC) = 54.0f;
        *(f32 *)(arg3 + 0x10) = 89.0f;
        *(s32 *)(arg3 + 8) = 1;
    } else if (temp_20 == 6) {
        func_0021b310(arg2, 1);
    } else if (temp_20 >= 7) {
        *(f32 *)(arg3 + 0xC) = 54.0f;
        *(f32 *)(arg3 + 0x10) = 89.0f;
        *(s32 *)(arg3 + 8) = 1;
    }
}

/* Lane L29 near-match archive; current candidate was reverted because it remained MISMATCH. */
void func_0029f790(u8 *arg0)
{
    f32 temp_f0;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f6;
    f32 var_f14;
    s32 temp_2;
    s32 temp_5;
    s32 temp_5_2;
    s32 temp_6;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 var_3;
    s32 var_3_2;
    s32 var_5;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 0x14) != 1) {
        if (func_002a2ca0(temp_16 + 0xE0) == 0) {
            func_002a2780((s32)(temp_16 + 0xE0));
        }
        return;
    }
    if (*(s32 *)(temp_16 + 0x24) == *(s32 *)(temp_16 + 0x30)) {
        temp_2 = *(s32 *)(temp_16 + 0x1C30) + 1;
        *(s32 *)(temp_16 + 0x1C30) = temp_2;
        if (temp_2 >= 0x5A) {
            *(s32 *)(temp_16 + 0x1C30) = 0;
            temp_6 = *(s32 *)(temp_16 + 0x20);
            temp_5 = *(s32 *)(temp_16 + 0x1C);
            temp_f21 = (f32)((temp_5 % 5) * 0x1B);
            temp_lo = temp_5 / 5;
            switch (temp_lo) {
            case 0:
                temp_f21 += 30.0f;
                break;
            case 1:
                temp_f21 += 178.0f;
                break;
            case 2:
                temp_f21 += 326.0f;
                break;
            case 3:
                temp_f21 += 474.0f;
                break;
            default:
                break;
            }
            temp_f20 = (f32)(temp_6 * 0x19 + 0xE5);
            func_002a2780((s32)(temp_16 + 0xE0));
            func_002a27c0((s32)((u8 *)((u32)temp_16 + 0xE0)),
                          (s32)temp_f21, (s32)temp_f20,
                          (s32)temp_f21, (s32)temp_f20,
                          fGpffff8204, 0, 0, 0x3C);
        }
    } else {
        *(s32 *)(temp_16 + 0x1C30) = 0;
    }
    if (func_002a2ca0(temp_16 + 0xE0) == 0 &&
        func_002a2c70(temp_16 + 0xE0) != 0) {
        func_002a2980(temp_16 + 0xE0);
        temp_6 = *(s32 *)(temp_16 + 0x20);
        temp_5_2 = *(s32 *)(temp_16 + 0x1C);
        temp_f2 = (f32)((temp_5_2 % 5) * 0x1B);
        temp_lo_2 = temp_5_2 / 5;
        switch (temp_lo_2) {
        case 0:
            temp_f2 += 30.0f;
            break;
        case 1:
            temp_f2 += 178.0f;
            break;
        case 2:
            temp_f2 += 326.0f;
            break;
        case 3:
            temp_f2 += 474.0f;
            break;
        default:
            break;
        }
        temp_f1 = (f32)(temp_6 * 0x19 + 0xE5);
        temp_f21 = temp_f2;
        temp_f21 += -12.0f;
        temp_f20 = temp_f1;
        temp_f20 += -12.0f;
        temp_f6 = (f32)func_002a2cd0(temp_16 + 0xE0);
        if (temp_f6 < 0.5f) {
            temp_f2 = temp_f6 * 255.0f;
            if (2.1474836e9f <= temp_f2) {
                goto color_wrap_1;
            }
            var_3 = (s32)temp_f2;
            goto color_done_1;
color_wrap_1:
            var_3 = (s32)(temp_f2 - 2.1474836e9f) | 0x80000000;
color_done_1:
            var_f14 = 1.0f + temp_f6;
        } else {
            temp_f2 = 1.0f - temp_f6;
            temp_f1 = 255.0f * temp_f2;
            if (2.1474836e9f <= temp_f1) {
                goto color_wrap_2;
            }
            var_3 = (s32)temp_f1;
            goto color_done_2;
color_wrap_2:
            var_3 = (s32)(temp_f1 - 2.1474836e9f) | 0x80000000;
color_done_2:
            var_f14 = 1.0f + temp_f2;
        }
        func_0029e9e0(0xF, temp_f21, temp_f20, var_f14, var_f14,
                      (u8)var_3, 1);
    }
}

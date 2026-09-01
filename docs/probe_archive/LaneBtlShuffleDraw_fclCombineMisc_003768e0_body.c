/* Closest candidate for func_003768e0; rejected after scoped mismatch (normalized diff remains). */
// FUN_003768E0 M2C_CANDIDATE
typedef struct ShuffleStackProbe {
    s32 spB0[3];
    s32 spBC;
    s32 spC0;
    s32 spC4;
    s32 spC8;
    u8 _pad_0BC[0x4];
    s32 spD0;
    s32 spD4;
    s32 spD8;
    u8 _pad_0CC[0x4];
    s32 spE0;
    s32 spE4;
    s32 spE8;
    u8 _pad_0DC[0x4];
    f32 spF0[0x40];
    u8 sp1F0[0x5F0];
    u8 sp7E0[0x5F0];
    f32 spDD0;
    f32 spDD4;
    f32 spDD8;
    u8 _pad_DCC[0x4];
    f32 spDE0;
    f32 spDE4;
    f32 spDE8;
    u8 _pad_DDC[0x4];
    f32 spDF0;
    f32 spDF4;
    f32 spDF8;
    u8 _pad_DEC[0x4];
    f32 spE00;
    f32 spE04;
    f32 spE08;
    u8 _pad_DFC[0x4];
    f32 spE10;
    f32 spE14;
    f32 spE18;
    u8 _pad_E0C[0x4];
    f32 spE20;
    f32 spE24;
    f32 spE28;
    u8 _pad_E1C[0x4];
    f32 spE30;
    f32 spE34;
    f32 spE38;
    u8 _pad_E2C[0x4];
    f32 spE40;
    f32 spE44;
    f32 spE48;
    u8 _pad_E3C[0x4];
    f32 spE50;
    f32 spE54;
    f32 spE58;
    u8 _pad_E4C[0x4];
    f32 spE60;
    f32 spE64;
    f32 spE68;
    u8 _pad_E5C[0x4];
    f32 spE70;
    f32 spE74;
    f32 spE78;
    u8 _pad_E6C[0x4];
    f32 spE80;
    f32 spE84;
    f32 spE88;
    u8 _pad_E7C[0x4];
    f32 spE90;
    f32 spE94;
    f32 spE98;
    u8 _pad_E8C[0x4];
    f32 spEA0;
    f32 spEA4;
    f32 spEA8;
    u8 _pad_E9C[0x4];
    f32 spEB0;
    f32 spEB4;
    f32 spEB8;
    u8 _pad_EAC[0x4];
    f32 spEC0;
    f32 spEC4;
    f32 spEC8;
    u8 _pad_EBC[0x4];
    f32 spED0;
    f32 spED4;
    f32 spED8;
    u8 _pad_ECC[0x4];
    f32 spEE0;
    f32 spEE4;
    f32 spEE8;
    u8 _pad_EDC[0x4];
    f32 spEF0;
    f32 spEF4;
    f32 spEF8;
    u8 _pad_EEC[0x4];
    f32 spF00;
    f32 spF04;
    f32 spF08;
    u8 _pad_EFC[0x4];
    f32 spF10;
    f32 spF14;
    f32 spF18;
    u8 _pad_F0C[0x4];
    f32 spF20;
    f32 spF24;
    f32 spF28;
    u8 _pad_F1C[0x4];
    f32 spF30;
    f32 spF34;
    f32 spF38;
    u8 _pad_F2C[0x4];
    f32 spF40;
    f32 spF44;
    f32 spF48;
    u8 _tail[0x4];
} ShuffleStackProbe;
// FUN_003768E0
void func_003768e0(u8 *arg0, s32 arg1, s64 arg2, u8 *arg3, f32 fparg0) {
    ShuffleStackProbe stack;
    u32 *render_table;
    u8 *var_19;
    u8 *var_19_2;
    u8 *var_19_3;
    u8 *var_20;
    u8 *var_20_2;
    u8 *var_20_3;
    u8 *var_2;
    u8 *var_3_5;
    u8 *var_4;
    u8 *var_4_2;
    u8 *var_5_5;
    u8 *var_5_6;
    f32 temp_f10;
    f32 temp_f10_2;
    f32 temp_f11;
    f32 temp_f11_2;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f13;
    f32 temp_f13_2;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f15;
    f32 temp_f15_2;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f22_3;
    f32 temp_f22_4;
    f32 temp_f23;
    f32 temp_f23_2;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 temp_f25;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f3_4;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f4_4;
    f32 temp_f5;
    f32 temp_f5_2;
    f32 temp_f5_3;
    f32 temp_f5_4;
    f32 temp_f6;
    f32 temp_f6_2;
    f32 temp_f9;
    f32 temp_f9_2;
    f32 var_f1;
    f32 var_f20;
    f32 var_f21;
    f32 var_f21_2;
    f32 var_f24;
    f32 var_f24_2;
    f32 var_f24_3;
    f32 var_f2;
    f32 var_f4;
    f32 var_f4_2;
    u8 *temp_21;
    s32 temp_4;
    s32 var_16;
    s32 var_16_2;
    s32 var_16_3;
    s32 var_18;
    s32 var_18_2;
    s32 var_18_3;
    s32 var_3_6;
    s32 var_3_7;
    s32 var_3_8;
    s32 var_3_9;
    s32 var_5;
    s32 var_5_2;
    s32 var_5_3;
    s32 var_5_4;
    s64 temp_18;
    s8 temp_23;
    s8 temp_23_2;
    s8 var_3;
    s8 var_3_2;
    s8 var_3_3;
    s8 var_3_4;
    u32 temp_2;
    u32 temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_4_2;
    u8 *temp_4_3;
    u8 *temp_4_4;
    u8 *temp_4_5;
    u8 *temp_4_6;
    u8 *temp_4_7;
    u8 *temp_4_8;
    u8 *temp_4_9;
    u8 *temp_5;

    temp_18 = (s64) (arg2 << 0x38) >> 0x38;
    if (temp_18 >= 3) {
        func_0046d730(&D_0064EA20, 0x5DE);
    }
    stack.spD8 = 0x3F800000;
    stack.spC4 = 0x3F800000;
    stack.spB0[0] = 0x3F800000;
    stack.spC0 = 0;
    stack.spB0[2] = 0;
    stack.spB0[1] = 0;
    stack.spD4 = 0;
    stack.spD0 = 0;
    stack.spC8 = 0;
    stack.spE8 = 0;
    stack.spE4 = 0;
    stack.spE0 = 0;
    stack.spBC |= 0x20003;
    func_003f6440(2, 0x48);
    func_003f6440(3, 0x71801);
    render_table = (u32 *)D_00887300;
    ((void (*)(u32, u32))render_table[0])(0x14, 1);
    ((void (*)(u32, u32))render_table[0])(6, 1);
    ((void (*)(u32, u32))render_table[0])(8, 0);
    temp_5 = (u8 *)(arg0 + (arg1 * 0xE8) + 0x1D6A0);
    temp_21 = arg0 + (arg1 * 0xFB0);
    temp_4 = (s32)(M2C_FIELD(temp_5, s32 *, 4));
    if (temp_4 == 6) {
        temp_2 = M2C_FIELD(arg3, u8 *, 3);
        if (temp_2 >= 0) {
            var_f2 = (f32) temp_2;
        } else {
            var_f2 = 2.0f * (f32) ((temp_2 >> 1) | (temp_2 & 1));
        }
        temp_2_2 = M2C_FIELD(temp_5, u8 *, 0xD8);
        if (temp_2_2 >= 0) {
            var_f1 = (f32) temp_2_2;
        } else {
            var_f1 = 2.0f * (f32) ((temp_2_2 >> 1) | (temp_2_2 & 1));
        }
        temp_f22 = var_f2 * (var_f1 / 255.0f);
        switch (temp_18) {                          /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            var_20 = (u8 *)(&stack.sp7E0);
            var_19 = (u8 *)(&stack.sp1F0);
            temp_f20 = iGpffff8400 * temp_f22;
            var_f21_2 = 1.0f;
            var_f24 = 0.0f;
            var_18 = 0;
loop_27:
            if (var_18 < 0x15) {
                func_003764b0(arg0, arg1, var_f24, ((u8 *)stack.spF0 + (var_18 * 0xC)));
                var_f24 -= fparg0 / 21.0f;
                M2C_FIELD(var_20, u8 *, 0xC) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_20, u8 *, 0xD) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_20, u8 *, 0xE) = (u8) M2C_FIELD(arg3, u8 *, 2);
                temp_f1 = temp_f22 * var_f21_2;
                if (!(temp_f1 >= 2.1474836e9f)) {
                    var_3 = 0x4F000000 & 0xFF;
                } else {
                    var_3 = (M2C_BITWISE(s32, (temp_f1 - 2.1474836e9f)) | 0x80000000) & 0xFF;
                }
                M2C_FIELD((var_20 + 0xC), s8 *, 3) = var_3;
                M2C_FIELD(var_20, u8 *, 0x30) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_20, u8 *, 0x31) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_20, u8 *, 0x32) = (u8) M2C_FIELD(arg3, u8 *, 2);
                temp_f2 = temp_f20 * var_f21_2;
                if (!(temp_f2 >= 2.1474836e9f)) {
                    var_3_2 = 0x4F000000 & 0xFF;
                } else {
                    var_3_2 = (M2C_BITWISE(s32, (temp_f2 - 2.1474836e9f)) | 0x80000000) & 0xFF;
                }
                M2C_FIELD((var_20 + 0x30), s8 *, 3) = var_3_2;
                M2C_FIELD(var_19, u8 *, 0xC) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_19, u8 *, 0xD) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_19, u8 *, 0xE) = (u8) M2C_FIELD(arg3, u8 *, 2);
                if (!(temp_f2 >= 2.1474836e9f)) {
                    var_3_3 = 0x4F000000 & 0xFF;
                } else {
                    var_3_3 = (M2C_BITWISE(s32, (temp_f2 - 2.1474836e9f)) | 0x80000000) & 0xFF;
                }
                M2C_FIELD((var_19 + 0xC), s8 *, 3) = var_3_3;
                M2C_FIELD(var_19, u8 *, 0x30) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_19, u8 *, 0x31) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_19, u8 *, 0x32) = (u8) M2C_FIELD(arg3, u8 *, 2);
                if (!(temp_f1 >= 2.1474836e9f)) {
                    var_3_4 = 0x4F000000 & 0xFF;
                } else {
                    var_3_4 = (M2C_BITWISE(s32, (temp_f1 - 2.1474836e9f)) | 0x80000000) & 0xFF;
                }
                M2C_FIELD((var_19 + 0x30), s8 *, 3) = var_3_4;
                var_f21_2 += (f32)(s32)(iGpffff8404);
                var_18 += 1;
                var_20 += 0x48;
                var_19 += 0x48;
                goto loop_27;
            }
            temp_f21 = 0.5f * func_0036de70(temp_21);
            temp_f20_2 = 0.5f * func_0036deb0(temp_21);
            var_16 = 0;
loop_50:
            if (var_16 < 4) {
                var_3_5 = (u8 *)(&stack.sp7E0);
                var_2 = (u8 *)(&stack.sp1F0);
                switch (var_16) {                   /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    var_5 = 0;
loop_36:
                    if (var_5 < 0x15) {
                        temp_4_2 = (u8 *)((u8 *)stack.spF0 + (var_5 * 0xC));
                        temp_4_3 = (u8 *)(temp_4_2 + 0xF0);
                        temp_f5 = temp_f21 + M2C_FIELD(temp_4_2, f32 *, 0xF0);
                        stack.spF40 = temp_f5;
                        temp_f4 = M2C_FIELD(temp_4_3, f32 *, 4);
                        stack.spF44 = temp_f4 - temp_f20_2;
                        temp_f3 = M2C_FIELD(temp_4_3, f32 *, 8);
                        stack.spF48 = temp_f3;
                        M2C_FIELD(var_3_5, f32 *, 0) = stack.spF40;
                        M2C_FIELD(var_3_5, f32 *, 4) = stack.spF44;
                        M2C_FIELD(var_3_5, f32 *, 8) = stack.spF48;
                        stack.spF30 = temp_f5;
                        stack.spF34 = temp_f4;
                        stack.spF38 = temp_f3;
                        M2C_FIELD(var_3_5, f32 *, 0x24) = stack.spF30;
                        M2C_FIELD(var_3_5, f32 *, 0x28) = stack.spF34;
                        M2C_FIELD(var_3_5, f32 *, 0x2C) = stack.spF38;
                        stack.spF20 = temp_f5;
                        stack.spF24 = temp_f4;
                        stack.spF28 = temp_f3;
                        M2C_FIELD(var_2, f32 *, 0) = stack.spF20;
                        M2C_FIELD(var_2, f32 *, 4) = stack.spF24;
                        M2C_FIELD(var_2, f32 *, 8) = stack.spF28;
                        stack.spF10 = temp_f5;
                        stack.spF14 = temp_f20_2 + temp_f4;
                        stack.spF18 = temp_f3;
                        M2C_FIELD(var_2, f32 *, 0x24) = stack.spF10;
                        M2C_FIELD(var_2, f32 *, 0x28) = stack.spF14;
                        M2C_FIELD(var_2, f32 *, 0x2C) = stack.spF18;
                        var_5 += 1;
                        var_3_5 += 0x48;
                        var_2 += 0x48;
                        goto loop_36;
                    }
                    break;
                case 1:                             /* switch 2 */
                    var_5_2 = 0;
loop_40:
                    if (var_5_2 < 0x15) {
                        temp_4_4 = (u8 *)((u8 *)stack.spF0 + (var_5_2 * 0xC));
                        temp_4_5 = (u8 *)(temp_4_4 + 0xF0);
                        temp_f5_2 = M2C_FIELD(temp_4_4, f32 *, 0xF0) - temp_f21;
                        stack.spF00 = temp_f5_2;
                        temp_f4_2 = M2C_FIELD(temp_4_5, f32 *, 4);
                        stack.spF04 = temp_f4_2 - temp_f20_2;
                        temp_f3_2 = M2C_FIELD(temp_4_5, f32 *, 8);
                        stack.spF08 = temp_f3_2;
                        M2C_FIELD(var_3_5, f32 *, 0) = stack.spF00;
                        M2C_FIELD(var_3_5, f32 *, 4) = stack.spF04;
                        M2C_FIELD(var_3_5, f32 *, 8) = stack.spF08;
                        stack.spEF0 = temp_f5_2;
                        stack.spEF4 = temp_f4_2;
                        stack.spEF8 = temp_f3_2;
                        M2C_FIELD(var_3_5, f32 *, 0x24) = stack.spEF0;
                        M2C_FIELD(var_3_5, f32 *, 0x28) = stack.spEF4;
                        M2C_FIELD(var_3_5, f32 *, 0x2C) = stack.spEF8;
                        stack.spEE0 = temp_f5_2;
                        stack.spEE4 = temp_f4_2;
                        stack.spEE8 = temp_f3_2;
                        M2C_FIELD(var_2, f32 *, 0) = stack.spEE0;
                        M2C_FIELD(var_2, f32 *, 4) = stack.spEE4;
                        M2C_FIELD(var_2, f32 *, 8) = stack.spEE8;
                        stack.spED0 = temp_f5_2;
                        stack.spED4 = temp_f20_2 + temp_f4_2;
                        stack.spED8 = temp_f3_2;
                        M2C_FIELD(var_2, f32 *, 0x24) = stack.spED0;
                        M2C_FIELD(var_2, f32 *, 0x28) = stack.spED4;
                        M2C_FIELD(var_2, f32 *, 0x2C) = stack.spED8;
                        var_5_2 += 1;
                        var_3_5 += 0x48;
                        var_2 += 0x48;
                        goto loop_40;
                    }
                    break;
                case 2:                             /* switch 2 */
                    var_5_3 = 0;
loop_44:
                    if (var_5_3 < 0x15) {
                        temp_4_6 = (u8 *)((u8 *)stack.spF0 + (var_5_3 * 0xC));
                        temp_4_7 = (u8 *)(temp_4_6 + 0xF0);
                        temp_f5_3 = M2C_FIELD(temp_4_6, f32 *, 0xF0);
                        stack.spEC0 = temp_f21 + temp_f5_3;
                        temp_f4_3 = temp_f20_2 + M2C_FIELD(temp_4_7, f32 *, 4);
                        stack.spEC4 = temp_f4_3;
                        temp_f3_3 = M2C_FIELD(temp_4_7, f32 *, 8);
                        stack.spEC8 = temp_f3_3;
                        M2C_FIELD(var_3_5, f32 *, 0) = stack.spEC0;
                        M2C_FIELD(var_3_5, f32 *, 4) = stack.spEC4;
                        M2C_FIELD(var_3_5, f32 *, 8) = stack.spEC8;
                        stack.spEB0 = temp_f5_3;
                        stack.spEB4 = temp_f4_3;
                        stack.spEB8 = temp_f3_3;
                        M2C_FIELD(var_3_5, f32 *, 0x24) = stack.spEB0;
                        M2C_FIELD(var_3_5, f32 *, 0x28) = stack.spEB4;
                        M2C_FIELD(var_3_5, f32 *, 0x2C) = stack.spEB8;
                        stack.spEA0 = temp_f5_3;
                        stack.spEA4 = temp_f4_3;
                        stack.spEA8 = temp_f3_3;
                        M2C_FIELD(var_2, f32 *, 0) = stack.spEA0;
                        M2C_FIELD(var_2, f32 *, 4) = stack.spEA4;
                        M2C_FIELD(var_2, f32 *, 8) = stack.spEA8;
                        stack.spE90 = temp_f5_3 - temp_f21;
                        stack.spE94 = temp_f4_3;
                        stack.spE98 = temp_f3_3;
                        M2C_FIELD(var_2, f32 *, 0x24) = stack.spE90;
                        M2C_FIELD(var_2, f32 *, 0x28) = stack.spE94;
                        M2C_FIELD(var_2, f32 *, 0x2C) = stack.spE98;
                        var_5_3 += 1;
                        var_3_5 += 0x48;
                        var_2 += 0x48;
                        goto loop_44;
                    }
                    break;
                case 3:                             /* switch 2 */
                    var_5_4 = 0;
loop_48:
                    if (var_5_4 < 0x15) {
                        temp_4_8 = (u8 *)((u8 *)stack.spF0 + (var_5_4 * 0xC));
                        temp_4_9 = (u8 *)(temp_4_8 + 0xF0);
                        temp_f5_4 = M2C_FIELD(temp_4_8, f32 *, 0xF0);
                        stack.spE80 = temp_f21 + temp_f5_4;
                        temp_f4_4 = M2C_FIELD(temp_4_9, f32 *, 4) - temp_f20_2;
                        stack.spE84 = temp_f4_4;
                        temp_f3_4 = M2C_FIELD(temp_4_9, f32 *, 8);
                        stack.spE88 = temp_f3_4;
                        M2C_FIELD(var_3_5, f32 *, 0) = stack.spE80;
                        M2C_FIELD(var_3_5, f32 *, 4) = stack.spE84;
                        M2C_FIELD(var_3_5, f32 *, 8) = stack.spE88;
                        stack.spE70 = temp_f5_4;
                        stack.spE74 = temp_f4_4;
                        stack.spE78 = temp_f3_4;
                        M2C_FIELD(var_3_5, f32 *, 0x24) = stack.spE70;
                        M2C_FIELD(var_3_5, f32 *, 0x28) = stack.spE74;
                        M2C_FIELD(var_3_5, f32 *, 0x2C) = stack.spE78;
                        stack.spE60 = temp_f5_4;
                        stack.spE64 = temp_f4_4;
                        stack.spE68 = temp_f3_4;
                        M2C_FIELD(var_2, f32 *, 0) = stack.spE60;
                        M2C_FIELD(var_2, f32 *, 4) = stack.spE64;
                        M2C_FIELD(var_2, f32 *, 8) = stack.spE68;
                        stack.spE50 = temp_f5_4 - temp_f21;
                        stack.spE54 = temp_f4_4;
                        stack.spE58 = temp_f3_4;
                        M2C_FIELD(var_2, f32 *, 0x24) = stack.spE50;
                        M2C_FIELD(var_2, f32 *, 0x28) = stack.spE54;
                        M2C_FIELD(var_2, f32 *, 0x2C) = stack.spE58;
                        var_5_4 += 1;
                        var_3_5 += 0x48;
                        var_2 += 0x48;
                        goto loop_48;
                    }
                    break;
                }
                func_00410420(&stack.sp7E0, 0x2A, &stack.spB0[0], 2);
                func_004106a0(4);
                func_00410420(&stack.sp1F0, 0x2A, &stack.spB0[0], 2);
                func_004106a0(4);
                var_16 += 1;
                goto loop_50;
            }
            break;
        case 1:                                     /* switch 1 */
            var_20_2 = (u8 *)(&stack.sp7E0);
            var_19_2 = (u8 *)(&stack.sp1F0);
            if (!(temp_f22 >= 2.1474836e9f)) {
                var_3_6 = 0x4F000000 & 0xFF;
            } else {
                var_3_6 = (M2C_BITWISE(s32, (temp_f22 - 2.1474836e9f)) | 0x80000000) & 0xFF;
            }
            temp_23 = var_3_6 & 0xFF;
            var_f24_2 = 0.0f;
            var_18_2 = 0;
loop_57:
            if (var_18_2 < 0x15) {
                func_003764b0(arg0, arg1, var_f24_2, ((u8 *)stack.spF0 + (var_18_2 * 0xC)));
                var_f24_2 -= fparg0 / 21.0f;
                M2C_FIELD(var_20_2, u8 *, 0xC) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_20_2, u8 *, 0xD) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_20_2, u8 *, 0xE) = (u8) M2C_FIELD(arg3, u8 *, 2);
                M2C_FIELD(var_20_2, s8 *, 0xF) = 0;
                M2C_FIELD(var_20_2, u8 *, 0x30) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_20_2, u8 *, 0x31) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_20_2, u8 *, 0x32) = (u8) M2C_FIELD(arg3, u8 *, 2);
                M2C_FIELD(var_20_2, s8 *, 0x33) = temp_23;
                M2C_FIELD(var_19_2, u8 *, 0xC) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_19_2, u8 *, 0xD) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_19_2, u8 *, 0xE) = (u8) M2C_FIELD(arg3, u8 *, 2);
                M2C_FIELD(var_19_2, s8 *, 0xF) = temp_23;
                M2C_FIELD(var_19_2, u8 *, 0x30) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_19_2, u8 *, 0x31) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_19_2, u8 *, 0x32) = (u8) M2C_FIELD(arg3, u8 *, 2);
                M2C_FIELD(var_19_2, s8 *, 0x33) = 0;
                var_18_2 += 1;
                var_20_2 += 0x48;
                var_19_2 += 0x48;
                goto loop_57;
            }
            temp_f25 = 0.5f * func_0036de70(temp_21);
            temp_f24 = 0.5f * func_0036deb0(temp_21);
            var_16_2 = 0;
            temp_f23 = -temp_f25;
            temp_f22_2 = -temp_f24;
loop_72:
            switch (var_16_2) {                     /* switch 3; irregular */
            case 0:                                 /* switch 3 */
                var_f21 = temp_f25;
                var_f20 = temp_f24;
            default:                                /* switch 3 */
block_68:
                var_5_5 = (u8 *)(&stack.sp7E0);
                var_4 = (u8 *)(&stack.sp1F0);
                var_f4 = 1.0f;
                var_3_7 = 0;
loop_70:
                if (var_3_7 < 0x15) {
                    temp_f6 = 3.0f * var_f4;
                    temp_f11 = D_0060A0E0 * temp_f6;
                    temp_f16 = D_0060A0E4 * temp_f6;
                    temp_f15 = D_0060A0E8 * temp_f6;
                    temp_2_3 = (u8 *)((u8 *)stack.spF0 + (var_3_7 * 0xC));
                    temp_2_4 = (u8 *)(temp_2_3 + 0xF0);
                    temp_f10 = M2C_FIELD(temp_2_3, f32 *, 0xF0);
                    temp_f9 = M2C_FIELD(temp_2_4, f32 *, 4);
                    temp_f14 = M2C_FIELD(temp_2_4, f32 *, 8);
                    stack.spE40 = temp_f11 + temp_f10 + var_f21;
                    stack.spE44 = temp_f16 + temp_f9 + var_f20;
                    stack.spE48 = temp_f15 + temp_f14;
                    M2C_FIELD(var_5_5, f32 *, 0) = stack.spE40;
                    M2C_FIELD(var_5_5, f32 *, 4) = stack.spE44;
                    M2C_FIELD(var_5_5, f32 *, 8) = stack.spE48;
                    temp_f13 = var_f21 + temp_f10;
                    stack.spE30 = temp_f13;
                    temp_f12 = var_f20 + temp_f9;
                    stack.spE34 = temp_f12;
                    stack.spE38 = temp_f14;
                    M2C_FIELD(var_5_5, f32 *, 0x24) = stack.spE30;
                    M2C_FIELD(var_5_5, f32 *, 0x28) = stack.spE34;
                    M2C_FIELD(var_5_5, f32 *, 0x2C) = stack.spE38;
                    stack.spE20 = temp_f13;
                    stack.spE24 = temp_f12;
                    stack.spE28 = temp_f14;
                    M2C_FIELD(var_4, f32 *, 0) = stack.spE20;
                    M2C_FIELD(var_4, f32 *, 4) = stack.spE24;
                    M2C_FIELD(var_4, f32 *, 8) = stack.spE28;
                    stack.spE10 = (temp_f10 - temp_f11) + var_f21;
                    stack.spE14 = (temp_f9 - temp_f16) + var_f20;
                    stack.spE18 = temp_f14 - temp_f15;
                    M2C_FIELD(var_4, f32 *, 0x24) = stack.spE10;
                    M2C_FIELD(var_4, f32 *, 0x28) = stack.spE14;
                    M2C_FIELD(var_4, f32 *, 0x2C) = stack.spE18;
                    var_f4 += (f32)(s32)(iGpffff8404);
                    var_3_7 += 1;
                    var_5_5 += 0x48;
                    var_4 += 0x48;
                    goto loop_70;
                }
                func_00410420(&stack.sp7E0, 0x2A, &stack.spB0[0], 2);
                func_004106a0(4);
                func_00410420(&stack.sp1F0, 0x2A, &stack.spB0[0], 2);
                func_004106a0(4);
                var_16_2 += 1;
                goto loop_72;
            case 1:                                 /* switch 3 */
                var_f21 = temp_f23;
                var_f20 = temp_f24;
                goto block_68;
            case 2:                                 /* switch 3 */
                var_f21 = temp_f25;
                var_f20 = temp_f22_2;
                goto block_68;
            case 3:                                 /* switch 3 */
                var_f21 = temp_f23;
                var_f20 = temp_f22_2;
                goto block_68;
            }
            break;
        case 2:                                     /* switch 1 */
            func_003e9700(*(s32 *)((u8 *)func_00457120() + 4));
            var_20_3 = (u8 *)(&stack.sp7E0);
            var_19_3 = (u8 *)(&stack.sp1F0);
            if (!(temp_f22 >= 2.1474836e9f)) {
                var_3_8 = 0x4F000000 & 0xFF;
            } else {
                var_3_8 = (M2C_BITWISE(s32, (temp_f22 - 2.1474836e9f)) | 0x80000000) & 0xFF;
            }
            temp_23_2 = var_3_8 & 0xFF;
            var_f24_3 = 0.0f;
            var_18_3 = 0;
loop_79:
            if (var_18_3 < 0x15) {
                func_003764b0(arg0, arg1, var_f24_3, ((u8 *)stack.spF0 + (var_18_3 * 0xC)));
                var_f24_3 -= fparg0 / 21.0f;
                M2C_FIELD(var_20_3, u8 *, 0xC) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_20_3, u8 *, 0xD) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_20_3, u8 *, 0xE) = (u8) M2C_FIELD(arg3, u8 *, 2);
                M2C_FIELD(var_20_3, s8 *, 0xF) = 0;
                M2C_FIELD(var_20_3, u8 *, 0x30) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_20_3, u8 *, 0x31) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_20_3, u8 *, 0x32) = (u8) M2C_FIELD(arg3, u8 *, 2);
                M2C_FIELD(var_20_3, s8 *, 0x33) = temp_23_2;
                M2C_FIELD(var_19_3, u8 *, 0xC) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_19_3, u8 *, 0xD) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_19_3, u8 *, 0xE) = (u8) M2C_FIELD(arg3, u8 *, 2);
                M2C_FIELD(var_19_3, s8 *, 0xF) = temp_23_2;
                M2C_FIELD(var_19_3, u8 *, 0x30) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_19_3, u8 *, 0x31) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_19_3, u8 *, 0x32) = (u8) M2C_FIELD(arg3, u8 *, 2);
                M2C_FIELD(var_19_3, s8 *, 0x33) = 0;
                var_18_3 += 1;
                var_20_3 += 0x48;
                var_19_3 += 0x48;
                goto loop_79;
            }
            temp_f22_3 = 0.5f * func_0036de70(temp_21);
            var_16_3 = 0;
            temp_f1_2 = (f32)(s32)(iGpffff8218);
            temp_f24_2 = temp_f1_2 * temp_f22_3;
            temp_f23_2 = (f32)(s32)(iGpffff8308 * (0.5f * func_0036deb0(temp_21)));
            temp_f22_4 = temp_f1_2 * -temp_f22_3;
loop_90:
            switch (var_16_3) {                     /* switch 4; irregular */
            case 0:                                 /* switch 4 */
                var_f21 = temp_f24_2;
                var_f20 = temp_f23_2;
            default:                                /* switch 4 */
block_86:
                var_5_6 = (u8 *)(&stack.sp7E0);
                var_4_2 = (u8 *)(&stack.sp1F0);
                var_f4_2 = 1.0f;
                var_3_9 = 0;
loop_88:
                if (var_3_9 < 0x15) {
                    temp_f6_2 = iGpffff8408 * var_f4_2;
                    temp_f11_2 = D_0060A0E0 * temp_f6_2;
                    temp_f16_2 = D_0060A0E4 * temp_f6_2;
                    temp_f15_2 = D_0060A0E8 * temp_f6_2;
                    temp_2_5 = (u8 *)((u8 *)stack.spF0 + (var_3_9 * 0xC));
                    temp_2_6 = (u8 *)(temp_2_5 + 0xF0);
                    temp_f10_2 = M2C_FIELD(temp_2_5, f32 *, 0xF0);
                    temp_f9_2 = M2C_FIELD(temp_2_6, f32 *, 4);
                    temp_f14_2 = M2C_FIELD(temp_2_6, f32 *, 8);
                    stack.spE00 = temp_f11_2 + temp_f10_2 + var_f21;
                    stack.spE04 = temp_f16_2 + temp_f9_2 + var_f20;
                    stack.spE08 = temp_f15_2 + temp_f14_2;
                    M2C_FIELD(var_5_6, f32 *, 0) = stack.spE00;
                    M2C_FIELD(var_5_6, f32 *, 4) = stack.spE04;
                    M2C_FIELD(var_5_6, f32 *, 8) = stack.spE08;
                    temp_f13_2 = var_f21 + temp_f10_2;
                    stack.spDF0 = temp_f13_2;
                    temp_f12_2 = var_f20 + temp_f9_2;
                    stack.spDF4 = temp_f12_2;
                    stack.spDF8 = temp_f14_2;
                    M2C_FIELD(var_5_6, f32 *, 0x24) = stack.spDF0;
                    M2C_FIELD(var_5_6, f32 *, 0x28) = stack.spDF4;
                    M2C_FIELD(var_5_6, f32 *, 0x2C) = stack.spDF8;
                    stack.spDE0 = temp_f13_2;
                    stack.spDE4 = temp_f12_2;
                    stack.spDE8 = temp_f14_2;
                    M2C_FIELD(var_4_2, f32 *, 0) = stack.spDE0;
                    M2C_FIELD(var_4_2, f32 *, 4) = stack.spDE4;
                    M2C_FIELD(var_4_2, f32 *, 8) = stack.spDE8;
                    stack.spDD0 = (temp_f10_2 - temp_f11_2) + var_f21;
                    stack.spDD4 = (temp_f9_2 - temp_f16_2) + var_f20;
                    stack.spDD8 = temp_f14_2 - temp_f15_2;
                    M2C_FIELD(var_4_2, f32 *, 0x24) = stack.spDD0;
                    M2C_FIELD(var_4_2, f32 *, 0x28) = stack.spDD4;
                    M2C_FIELD(var_4_2, f32 *, 0x2C) = stack.spDD8;
                    var_f4_2 += (f32)(s32)(iGpffff8404);
                    var_3_9 += 1;
                    var_5_6 += 0x48;
                    var_4_2 += 0x48;
                    goto loop_88;
                }
                func_00410420(&stack.sp7E0, 0x2A, &stack.spB0[0], 2);
                func_004106a0(4);
                func_00410420(&stack.sp1F0, 0x2A, &stack.spB0[0], 2);
                func_004106a0(4);
                var_16_3 += 1;
                goto loop_90;
            case 1:                                 /* switch 4 */
                var_f21 = temp_f22_4;
                var_f20 = temp_f23_2;
                goto block_86;
            }
            break;
        }
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
    }
}

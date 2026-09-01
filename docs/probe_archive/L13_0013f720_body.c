/* Closest tested candidate before reverting to INCLUDE_ASM: object 1172B, retail window 1072B, normalized_diff 232 words. */
s32 func_0013f720(s32 arg0, s64 arg1, s32 arg2, u8 *arg3) {
    u8 *spC0;
    u8 *spB0;
    u8 *spA0;
    s64 var_19;
    s64 var_18;
    s64 temp_17;
    s64 temp_22;
    s64 temp_23;
    s64 temp_30;
    s64 var_22;
    s64 var_16;
    s64 var_17;
    s64 temp_16;
    s64 temp_17_2;
    s64 temp_17_3;
    s64 temp_3_3;
    s64 var_16_2;
    s64 temp_22_2;
    s64 temp_23_2;
    u8 *temp_3;
    u8 *temp_3_2;

    var_19 = 1;
    var_18 = -1;
    temp_3 = arg3 + arg2 * 0xC;
    spC0 = temp_3 + 0x102;
    temp_17 = *(u16 *)(temp_3 + 0x102);
    spB0 = temp_3 + 0x100;
    temp_22 = *(s16 *)(temp_3 + 0x100);
    temp_23 = *(s32 *)(temp_3 + 0x104);
    temp_30 = *(s32 *)(temp_3 + 0x108);
    if (temp_22 != -1) {
        var_18 = (s64)((func_0010b510() << 0x30) >> 0x30);
        func_0010b3b0(temp_22);
    }
    if ((temp_17 & 0xFFFF) == 0xF6) {
        if (func_00354010() != 0) {
            var_19 = 3;
        } else {
            var_19 = 0;
        }
    } else if (((s64)(arg1 << 0x30) >> 0x30) == -1) {
        var_22 = 0;
        var_16 = 0;
loop_11:
        if (var_16 < *(s16 *)(arg3 + 0xFC)) {
            temp_3_2 = arg3 + var_16 * 2;
            spA0 = temp_3_2 + 0xF4;
            if (func_0010f930(arg0, *(s16 *)(temp_3_2 + 0xF4), temp_17, 0) == 0) {
                func_0010f770(arg0, *(s16 *)spA0, temp_17, 0);
                var_22 += 1;
            }
            var_16 += 1;
            goto loop_11;
        }
        if (var_22 == 0) {
            var_19 = 0;
        }
    } else if (func_0010f930(arg0, (s16)arg1, temp_17, 0) == 0) {
        func_0010f770(arg0, (s16)arg1, temp_17, 0);
    } else {
        var_19 = 0;
    }
    temp_16 = (s64)(((s64)var_19 << 0x38) >> 0x38);
    if (temp_16 > 0) {
        if (temp_23 > 0) {
            temp_17_2 = (func_00104ce0(arg0) & 0xFFFF) - temp_23;
            if (temp_17_2 <= 0) {
                func_0046d730(D_005ED9F0, 0x25B);
            }
            func_001056e0(arg0, (s16)((temp_17_2 << 0x30) >> 0x30));
        }
        if (temp_30 > 0) {
            temp_17_3 = (func_00104d50(arg0) & 0xFFFF) - temp_30;
            if (temp_17_3 < 0) {
                func_0046d730(D_005ED9F0, 0x261);
            }
            func_00105730(arg0, (s16)((temp_17_3 << 0x30) >> 0x30));
        }
        if (temp_16 == 3) {
            func_00106390(0x1401, 1);
        } else {
            var_17 = 1;
            var_16_2 = -1;
            temp_23_2 = *(u16 *)spC0;
            temp_22_2 = *(s16 *)spB0;
            if (func_0010f540(temp_23_2) == 0) {
                var_17 = 0;
            } else {
                if (((s64)((s64)temp_22_2 << 0x30) >> 0x30) != -1) {
                    var_16_2 = (s64)((func_0010b510() << 0x30) >> 0x30);
                    func_0010b3b0(temp_22_2);
                }
                if (func_0010f6a0(arg0, temp_23_2) != 0) {
                    var_17 = 0;
                }
                if (((s64)(var_16_2 << 0x30) >> 0x30) != -1) {
                    func_0010b3b0((s16)var_16_2);
                }
            }
            if (var_17 == 0) {
                var_19 = 2;
            } else {
                func_0013aa90(arg3);
            }
        }
    }
    if (((s64)(var_18 << 0x30) >> 0x30) != -1) {
        func_0010b3b0((s16)var_18);
    }
    temp_3_3 = (s64)(((s64)var_19 << 0x38) >> 0x38);
    switch (temp_3_3) {
    case 3:
        break;
    case 0:
        func_0045af60(0, 0, 0, 8);
        break;
    case 2:
    case 1:
        func_0045af60(1, 3, 2, 0x16);
        break;
    default:
        func_0046d730(D_005ED9F0, 0x28C);
        break;
    }
    return var_19;
}

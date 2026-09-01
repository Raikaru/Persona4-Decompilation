/* Closest tested candidate before reverting to INCLUDE_ASM: object 2500B, retail window 2512B, normalized_diff 77 words. */
s32 func_0013caa0(u32 *arg0, s32 *arg1, u8 *arg2) {
    struct {
        u8 bytes[0x24];
        s32 value64;
        s32 value68;
    } stack;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_4;
    s32 temp_4_2;
    f32 temp_f1;
    s32 converted;
    s32 done;

    *arg1 = 1;
    switch (*arg0) {
    case 0:
        *arg1 = 0;
        func_001312b0(arg2);
        *arg0 = 1;
        goto block_75;
    case 1:
        temp_2 = func_001318c0(arg2);
        if ((temp_2 & func_0034c210()) != 0) {
            *arg0 = 4;
            func_0034bb20(3);
        } else {
            *arg1 = 0;
        }
        goto block_75;
    case 2:
        temp_4 = *(s32 *)(arg2 + 0x1594);
        if (temp_4 != 0 && func_00452490(temp_4) != 0) {
            goto block_75;
        }
        *arg0 = 3;
        func_00134560(arg2, 1);
        func_00353fb0();
        func_0034bb20(7);
    case 3:
        if (func_00134b60(arg2) == 0) {
            goto block_75;
        }
        func_00134ab0(arg2);
        return 1;
    case 4:
        if (func_00134b60(arg2) != 0) {
            func_00353fe0();
            func_00134560(arg2, 2);
            *arg0 = 5;
        }
        goto block_75;
    case 5:
        if (func_00134b60(arg2) == 0) {
            goto block_75;
        }
        if (D_008C024E[0] & 0x20) {
            *arg0 = 2;
            func_00134be0(arg2);
            func_0045af60(0, 2, 0, 4);
            goto block_75;
        }
        if (D_008C024E[0] & 0x40) {
            func_00134560(arg2, 3);
            *arg0 = 7;
            func_0034bb20(4);
            func_0045af60(0, 0, 0, 1);
            goto block_75;
        }
        if (D_008C024E[0] & 0x10) {
            func_00134be0(arg2);
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 0xD;
            goto block_75;
        }
        func_00453670(stack.bytes, 8, *(s16 *)(arg2 + 0x48),
                      *(s16 *)(arg2 + 0x28), 0);
        func_004538e0(stack.bytes, 0x4000, 0x1000, 0, 0);
        if (func_00453960(stack.bytes) != 0) {
            func_001344b0(arg2, 0, stack.value64);
            func_0045af60(0, 1, 0, 0);
        }
        goto block_75;
    case 6:
        if (func_00134b60(arg2) != 0) {
            func_00134560(arg2, 4);
            *arg0 = 7;
        }
        goto block_75;
    case 7:
        if (D_008C024E[0] & 0x20) {
            func_001344b0(arg2, 1, 0);
            func_00134560(arg2, 2);
            *arg0 = 5;
            func_0034bd60(3);
            func_0045af60(0, 0, 0, 2);
            goto block_75;
        }
        if (D_008C024E[0] & 0x40) {
            func_00134560(arg2, 5);
            *arg0 = 8;
            func_0034bb20(5);
            func_0045af60(0, 0, 0, 1);
            goto block_75;
        }
        if (D_008C024E[0] & 0x10) {
            func_00134be0(arg2);
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 0xD;
            goto block_75;
        }
        func_00453670(stack.bytes, 3, 3, *(s16 *)(arg2 + 0x2A), 0);
        func_004538e0(stack.bytes, 0x4000, 0x1000, 0, 0);
        if (func_00453960(stack.bytes) != 0) {
            func_001344b0(arg2, 1, stack.value64);
            func_0045af60(0, 1, 0, 0);
        }
        goto block_75;
    case 8:
        if (func_00134b60(arg2) != 0) {
            func_00134560(arg2, 6);
            *arg0 = 9;
            func_0034bb20(6);
        }
        goto block_75;
    case 9:
        if (func_00134b60(arg2) != 0) {
            func_00134560(arg2, 7);
            *arg0 = 10;
        }
        goto block_75;
    case 10:
        if (func_00134b60(arg2) == 0) {
            goto block_75;
        }
        if (D_008C024E[0] & 0x40) {
            if (*(s16 *)(arg2 + 0xC46) != 0) {
                func_0013d5d0(arg2);
            }
            goto block_75;
        }
        if (D_008C024E[0] & 0x20) {
            func_001344b0(arg2, 2, 0);
            func_001344b0(arg2, 3, 0);
            func_00134560(arg2, 4);
            *arg0 = 6;
            func_0034bd60(4);
            func_0045af60(0, 0, 0, 2);
            goto block_75;
        }
        if (D_008C024E[0] & 0x10) {
            func_00134be0(arg2);
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 0xD;
            goto block_75;
        }
        if (D_008C024E[0] & 0x80) {
            if (*(s16 *)(arg2 + 0xC46) != 0) {
                func_00134560(arg2, 8);
                *arg0 = 0xB;
                func_0045af60(0, 2, 0, 3);
            }
            goto block_75;
        }
        if (func_0013d470(arg2, (s32 *)arg0) != 0) {
            goto block_75;
        }
        func_00453670(stack.bytes, 5, *(s16 *)(arg2 + 0xC46),
                      *(s16 *)(arg2 + 0x2E), *(s16 *)(arg2 + 0x2C));
        func_004538e0(stack.bytes, 0x4000, 0x1000, 0x2000, 0x8000);
        temp_2_2 = func_00453960(stack.bytes);
        if (temp_2_2 > 0) {
            func_001344b0(arg2, 2, stack.value68);
            func_001344b0(arg2, 3, stack.value64);
            if (*(s16 *)(arg2 + 0x2C) != *(s16 *)(arg2 + 0x34)) {
                func_00134890(arg2);
            }
            func_00354080(temp_2_2);
        }
        goto block_75;
    case 11:
        if (func_00134b60(arg2) != 0) {
            func_00134560(arg2, 9);
            *arg0 = 12;
        }
        goto block_75;
    case 12:
        if (D_008C024E[0] & 0x40) {
            if (func_0013d5d0(arg2) != 0) {
                *arg0 = 9;
            }
        } else if ((D_008C024E[0] & 0x20) ||
                   (D_008C024E[0] & 0x80)) {
            func_00134560(arg2, 7);
            *arg0 = 9;
            func_0045af60(0, 2, 0, 4);
        } else if (D_008C024E[0] & 0x10) {
            func_00134be0(arg2);
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 13;
        } else if (func_0013d470(arg2, (s32 *)arg0) == 0) {
            func_00453670(stack.bytes, 5, *(s16 *)(arg2 + 0xC46),
                          *(s16 *)(arg2 + 0x2E), *(s16 *)(arg2 + 0x2C));
            func_004538e0(stack.bytes, 0x4000, 0x1000, 0x2000, 0x8000);
            temp_2_3 = func_00453960(stack.bytes);
            if (temp_2_3 > 0) {
                func_001344b0(arg2, 2, stack.value68);
                func_001344b0(arg2, 3, stack.value64);
                if (*(s16 *)(arg2 + 0x2C) != *(s16 *)(arg2 + 0x34)) {
                    func_00134890(arg2);
                }
                func_00354080(temp_2_3);
            }
        }
        goto block_75;
    case 13:
        temp_4_2 = *(s32 *)(arg2 + 0x1594);
        if (temp_4_2 != 0 && func_00452490(temp_4_2) != 0) {
            goto block_75;
        }
        temp_2 = (u16)(*(u16 *)(arg2 + 0xC) + 1);
        *(u16 *)(arg2 + 0xC) = temp_2;
        if (temp_2 < 3) {
            goto alpha_path;
        }
        done = 1;
        goto alpha_done;
    alpha_path:
        temp_f1 = 255.0f *
                  (1.0f - ((f32)*(u16 *)(arg2 + 0xC) / 3.0f));
        if (2147483600.0f <= temp_f1) {
            goto high_value;
        }
        converted = (s32)temp_f1;
        goto value_ready;
    high_value:
        converted = (s32)(temp_f1 - 2147483600.0f) |
                    (s32)0x80000000;
    value_ready:
        converted &= 0xFF;
        *(u8 *)arg2 = (u8)converted;
        done = 0;
    alpha_done:
        if (done == 0) {
            goto block_75;
        }
        return 2;
    default:
        goto block_75;
    }
block_75:
    return 0;
}

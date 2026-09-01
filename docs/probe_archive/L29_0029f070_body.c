/* Lane L29 near-match archive; candidate was reverted because it remained MISMATCH. */
void func_0029f070(u8 *arg0)
{
    u8 sp7C[4];
    s32 temp_19;
    s32 temp_20;
    s32 temp_2;
    s32 temp_3_3;
    s32 temp_3_4;
    s32 var_16;
    s32 var_16_2;
    s32 var_19;
    s32 var_19_2;
    s32 var_19_3;
    s32 var_19_4;
    s32 var_20;
    s32 var_20_2;
    s32 var_20_3;
    s32 var_20_4;
    s32 var_3;
    s32 var_4;
    s32 var_4_2;
    s32 var_4_3;
    s32 var_5;
    s32 var_5_2;
    u8 *temp_18;
    u8 *temp_3;
    u8 *temp_3_2;

    temp_18 = *(u8 **)(arg0 + 0x38);
    var_3 = 0;
loop_2:
    if (var_3 < 6) {
        *(s32 *)(temp_18 + (var_3 * 4) + 0x1C50) = 0;
        var_3 += 1;
        goto loop_2;
    }
    temp_3 = temp_18 + 0x1C4C;
    *(s16 *)temp_3 = 0;
    var_16 = 0;
    if (D_0076462C == 0) {
        var_19 = 0;
        var_20 = 0;
loop_8:
        if (var_20 < 8) {
            if (func_00442c30(&iGpffffa7e8,
                              D_00882EF0 + (var_20 * 2), 2) == 0) {
                var_19 += 1;
            }
            var_20 += 1;
            goto loop_8;
        }
        if (var_19 < 8) {
            var_19_2 = 0;
            var_20_2 = 0;
loop_14:
            if (var_20_2 < 8) {
            if (func_00442c30(&iGpffffa7e8,
                              D_00882ED0 + (var_20_2 * 2), 2) == 0) {
                    var_19_2 += 1;
                }
                var_20_2 += 1;
                goto loop_14;
            }
            if (var_19_2 < 8) {
                var_16 = 1;
                *(s16 *)temp_3 = 1;
            }
        }
    }
    if ((D_008C024E[0] & 0x800) && (var_16 > 0)) {
        *(s32 *)(temp_18 + 0x14) = 3;
        *(s32 *)(temp_18 + 0x1C64) = 1;
        func_0045af60(0, 0, 0, 1);
        return;
    }
    temp_3 = temp_18 + 0x1C38;
    *(s16 *)temp_3 = 0;
    var_16_2 = 0;
    if (D_0076462C > 0) {
        var_16_2 = 0xA;
    } else if (iGpffffb538 < 8) {
        if ((func_00442948(D_00882EF0) >> 1) != 0) {
            temp_20 = iGpffffb538;
            if (func_00442c30(&iGpffffa7e8,
                              D_00882EF0 + (temp_20 * 2), 2) == 0) {
                var_19_3 = 0;
                var_20_3 = temp_20 + 1;
loop_29:
                if (var_20_3 < 8) {
                if (func_00442c30(&iGpffffa7e8,
                                  D_00882EF0 + (var_20_3 * 2), 2) != 0) {
                        var_19_3 = 1;
                    } else {
                        var_20_3 += 1;
                        goto loop_29;
                    }
                }
                if (var_19_3 != 0) {
                    var_16_2 = 0x14;
                }
            } else {
                var_16_2 = 0x15;
            }
        }
    } else if ((func_00442948(D_00882ED0) >> 1) != 0) {
        temp_19 = iGpffffb538 - 8;
        if (func_00442c30(&iGpffffa7e8,
                          D_00882ED0 + (temp_19 * 2), 2) == 0) {
            var_20_4 = 0;
            var_19_4 = temp_19 + 1;
loop_39:
            if (var_19_4 < 8) {
                if (func_00442c30(&iGpffffa7e8,
                                  D_00882ED0 + (var_19_4 * 2), 2) != 0) {
                    var_20_4 = 1;
                } else {
                    var_19_4 += 1;
                    goto loop_39;
                }
            }
            if (var_20_4 != 0) {
                var_16_2 = 0x1E;
            }
        } else {
            var_16_2 = 0x1F;
        }
    }
    if (var_16_2 > 0) {
        *(s16 *)temp_3 = 1;
    }
    if (D_008C024E[0] & 0x20) {
        switch (var_16_2) {
        case 10:
            temp_2 = iGpffffb538;
            if (temp_2 < 8) {
                func_00442de8(D_00882EF0 + (temp_2 * 2),
                              &iGpffffa7e8, 2);
            } else {
                func_00442de8(D_00882ED0 + ((temp_2 - 8) * 2),
                              &iGpffffa7e8, 2);
            }
            break;
        case 20:
            var_5 = iGpffffb538 + 1;
loop_57:
            if (var_5 < 8) {
                temp_3 = D_00882EF0 + (var_5 * 2);
                *(s8 *)(temp_3 - 2) = *(s8 *)temp_3;
                *(s8 *)(temp_3 - 1) = *(s8 *)(temp_3 + 1);
                var_5 += 1;
                goto loop_57;
            }
            func_00442de8(D_00882EFE, &iGpffffa7e8, 2);
            break;
        case 21:
            func_00442de8(D_00882EF0 + (iGpffffb538 * 2),
                          &iGpffffa7e8, 2);
            break;
        case 30:
            var_5_2 = iGpffffb538 - 8 + 1;
loop_62:
            if (var_5_2 < 8) {
                temp_3_2 = D_00882ED0 + (var_5_2 * 2);
                *(s8 *)(temp_3_2 - 2) = *(s8 *)temp_3_2;
                *(s8 *)(temp_3_2 - 1) = *(s8 *)(temp_3_2 + 1);
                var_5_2 += 1;
                goto loop_62;
            }
            func_00442de8(D_00882EDE, &iGpffffa7e8, 2);
            break;
        case 31:
            func_00442de8(D_00882ED0 + ((iGpffffb538 - 8) * 2),
                          &iGpffffa7e8, 2);
            break;
        default:
            var_16_2 = 0;
            break;
        }
        if (var_16_2 > 0) {
            *(s32 *)(temp_18 + 0x1C50) = 1;
            func_0045af60(0, 0, 0, 2);
            return;
        }
    }
    temp_3 = temp_18 + 0x1C3C;
    *(s16 *)temp_3 = 0;
    var_4 = 0;
    if (D_0076462C < 0x10) {
        var_4 = 1;
        *(s16 *)temp_3 = 1;
    }
    if ((D_008C024E[0] & 0x40) && (var_4 > 0)) {
        temp_3 = *(u8 **)(D_0063E810 +
                          (*(s32 *)(temp_18 + 0x20) * 4));
        func_0043f810(sp7C,
                      temp_3 + (*(s32 *)(temp_18 + 0x1C) * 2), 2);
        func_0029ef90(arg0, sp7C);
        *(s32 *)(temp_18 + 0x1C54) = 1;
        func_0045af60(0, 0, 0, 1);
        return;
    }
    temp_3 = temp_18 + 0x1C40;
    *(s16 *)temp_3 = 0;
    var_4_2 = 0;
    if (iGpffffb538 > 0) {
        var_4_2 = 1;
        *(s16 *)temp_3 = 1;
    }
    if ((D_008C024E[0] & 4) && (var_4_2 > 0)) {
        temp_3_3 = iGpffffb538 - 1;
        iGpffffb538 = temp_3_3;
        if (temp_3_3 == 7) {
            *(s32 *)(temp_18 + 0x1C34) = 2;
            func_0029ebf0(arg0, 2);
        }
        *(s32 *)(temp_18 + 0x1C58) = 1;
        func_0045af60(0, 0, 0, 0);
    }
    temp_3 = temp_18 + 0x1C48;
    *(s16 *)temp_3 = 0;
    var_4_3 = 0;
    if (iGpffffb538 < 0xF) {
        var_4_3 = 1;
        *(s16 *)temp_3 = 1;
    }
    if ((D_008C024E[0] & 8) && (var_4_3 > 0)) {
        temp_3_4 = iGpffffb538 + 1;
        iGpffffb538 = temp_3_4;
        if (temp_3_4 == 8) {
            *(s32 *)(temp_18 + 0x1C34) = 1;
            func_0029ebf0(arg0, 1);
        }
        *(s32 *)(temp_18 + 0x1C60) = 1;
        func_0045af60(0, 0, 0, 0);
    }
    func_0029ecb0(arg0);
}

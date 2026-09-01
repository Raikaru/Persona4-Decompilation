/* Closest non-MATCH candidate archived before reverting; lverify report had MISMATCH. */
u8 *func_0015d310(u16 *arg0)
{
    s32 sp8C;
    s32 sp88;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 temp_4_5;
    s32 var_18;
    s32 var_19_2;
    s64 temp_3_2;
    s64 temp_3_3;
    s64 var_2;
    s64 var_2_2;
    s32 temp_22;
    s32 temp_22_2;
    u16 *var_5;
    u16 temp_4_2;
    s32 var_19;
    s32 var_20;
    u32 var_17;
    u32 var_18_2;
    u32 var_18_3;
    u32 var_21;
    u8 temp_3;
    u8 *temp_20;
    u8 *temp_4;
    u8 *var_16;

    var_5 = arg0;
    if (arg0 == NULL) {
        return NULL;
    }
    var_17 = 0;
loop_3:
    if (*var_5 != 0xFFFF) {
        var_17 += 1;
        var_5 += 0x42;
        goto loop_3;
    }
    var_16 = (u8 *)arg0 + (var_17 * 0x84) - 0x84;
    var_18 = 3;
    var_19 = 0x1F;
    var_20 = 0;
    func_001104d0((s16)func_001060b0(), &sp8C, &sp88);
    var_21 = 0;
    goto loop_test;
loop_body:
        temp_4 = iGpffff9db0;
        if ((*(s32 *)(temp_4 + 0) == *(u16 *)(var_16 + 0x64)) &&
            (*(s32 *)(temp_4 + 4) == *(u16 *)(var_16 + 0x66))) {
            temp_4_2 = *(u16 *)(var_16 + 2);
            if ((temp_4_2 == var_18) &&
                (*(u16 *)(var_16 + 4) == var_19) &&
                (*(u16 *)(var_16 + 6) == var_20)) {
                var_18 = 3;
                var_19 = 0x1F;
                var_20 = 0;
            }
            if (func_0014bdb0(temp_4_2, *(u16 *)(var_16 + 4),
                             var_18, var_19) == 1) {
                if ((*(u16 *)(var_16 + 2) == sp8C) &&
                    (*(u16 *)(var_16 + 4) == sp88) &&
                    ((func_001060c0() & 0xFF) < var_20)) {
                    var_18 = *(u16 *)(var_16 + 2);
                    var_19 = *(u16 *)(var_16 + 4);
                    var_20 = *(u16 *)(var_16 + 6);
                    goto block_50;
                }
                if (((*(u8 *)(var_16 + 8) == 0) ||
                     (*(u8 *)(var_16 + 8) &
                      (1 << func_00110d30((s16)func_001060b0())))) &&
                    ((*(u8 *)(var_16 + 9) == 0) ||
                     (*(u8 *)(var_16 + 9) &
                      (1 << func_00110580((s16)func_001060b0())))) &&
                    ((*(u8 *)(var_16 + 0xA) == 0) ||
                     (*(u8 *)(var_16 + 0xA) &
                      (1 << (func_001060c0() & 0xFF))))) {
                    temp_3 = *(u8 *)(var_16 + 0xB);
                    if (temp_3 == 1) {
                        temp_22 = (s16)func_001060b0();
                        var_2 = (s64)(func_00110960(temp_22,
                                                     func_001060c0() & 0xFF) << 0x38) >> 0x38;
                        temp_3_2 = var_2 & 1;
                        if ((var_2 < 0) && (temp_3_2 != 0)) {
                            temp_3_2 -= 2;
                        }
                        if (temp_3_2 != 0) {
                            goto block_50;
                        }
                        goto block_34;
                    }
                    if (temp_3 == 2) {
                        temp_22_2 = (s16)func_001060b0();
                        var_2_2 = (s64)(func_00110960(temp_22_2,
                                                       func_001060c0() & 0xFF) << 0x38) >> 0x38;
                        temp_3_3 = var_2_2 & 1;
                        if ((var_2_2 < 0) && (temp_3_3 != 0)) {
                            temp_3_3 -= 2;
                        }
                        if (temp_3_3 != 0) {
                            goto block_34;
                        }
                        goto block_50;
                    }
block_34:
                    var_18_2 = 0;
loop_38:
                    if (var_18_2 < 0xC) {
                        temp_4_3 = *(s32 *)(var_16 + (var_18_2 * 4) + 0x34);
                        if ((temp_4_3 == -1) ||
                            (func_00106330(temp_4_3) != 1)) {
                            var_18_2 += 1;
                            goto loop_38;
                        }
                    }
                    if (var_18_2 >= 0xC) {
                        var_19_2 = 0;
                        var_18_3 = 0;
loop_46:
                        if (var_18_3 < 5) {
                            temp_20 = var_16 + (var_18_3 * 8);
                            temp_4_4 = *(s32 *)(temp_20 + 0xC);
                            if (temp_4_4 == -1) {
                                var_18_3 += 1;
                                goto loop_46;
                            }
                            var_19_2 = 1;
                            if (func_00106330(temp_4_4) != 1) {
                                var_18_3 += 1;
                                goto loop_46;
                            }
                            temp_4_5 = *(s32 *)(temp_20 + 0x10);
                            if (temp_4_5 != -1) {
                                if (func_00106330(temp_4_5) != 1) {
                                    var_18_3 += 1;
                                    goto loop_46;
                                }
                            }
                        }
                        if ((var_18_3 >= 5) && (var_19_2 != 0)) {
                            goto block_49;
                        }
                    } else {
                        goto block_49;
                    }
                } else {
                    goto block_50;
                }
            } else {
block_49:
                var_18 = *(u16 *)(var_16 + 2);
                var_19 = *(u16 *)(var_16 + 4);
                var_20 = *(u16 *)(var_16 + 6);
                goto block_50;
            }
        } else {
block_50:
            var_21 += 1;
            var_16 -= 0x84;
loop_test:
            if (var_21 < var_17) {
                goto loop_body;
            }
        }
    if (var_21 >= var_17) {
        var_16 = NULL;
    }
    return var_16;
}

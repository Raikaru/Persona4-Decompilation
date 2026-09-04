/* W45c19 measured candidate for func_00194670.
 * object 844B, window 864B, normalized diff 142 (fndiff differing words 142).
 * Levers tried: generated M2C control-flow shape; explicit callback locals;
 * direct global iGpffffb3ac list addressing; switch fallthrough labels; 16-bit
 * loop counters with masked increments; direct jtbl_008873EC dispatch.
 */
void func_00194670(u8 *arg0)
{
    void (*temp_2)(u8 *);
    void (*temp_2_2)(u8 *);
    s16 temp_3_3;
    s16 temp_3_4;
    s32 temp_17;
    s32 var_16;
    s32 var_16_2;
    s32 var_3;
    s32 var_3_2;
    u8 temp_4;
    u8 temp_4_2;
    u8 temp_5;
    u8 temp_5_2;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_5;
    u8 *temp_3_6;

    if ((*(u8 *)(arg0 + 0x46) == 0) &&
        (temp_4 = *(u8 *)(arg0 + 0x47), (temp_4 & 8) != 0)) {
        if (temp_4 & 4) {
            temp_2 = *(void (**)(u8 *))(arg0 + 0x70);
            if (temp_2 != NULL) {
                temp_2(*(u8 **)(arg0 + 0x78));
            }
            if ((*(u8 *)(arg0 + 0x47) & 8) != 0) {
                temp_5 = *(u8 *)(arg0 + 0x44);
                temp_3 = *(u8 **)(arg0 + 0x80);
                if (temp_3 != NULL) {
                    *(u8 **)(temp_3 + 0x7C) = *(u8 **)(arg0 + 0x7C);
                } else {
                    *(u8 **)(iGpffffb3ac +
                             ((temp_5 & 0xFF) * 8) + 0x19C) =
                        *(u8 **)(arg0 + 0x7C);
                }
                temp_3_2 = *(u8 **)(arg0 + 0x7C);
                if (temp_3_2 != NULL) {
                    *(u8 **)(temp_3_2 + 0x80) = *(u8 **)(arg0 + 0x80);
                } else {
                    *(u8 **)(iGpffffb3ac +
                             ((temp_5 & 0xFF) * 8) + 0x198) =
                        *(u8 **)(arg0 + 0x80);
                }
            }
            jtbl_008873EC[0](arg0);
            return;
        }
        temp_17 = *(s32 *)(arg0 + 0x4C);
        *(s32 *)(arg0 + 0x4C) = temp_17 + 1;
        temp_4_2 = *(u8 *)(arg0 + 0x45);
        switch (temp_4_2) {
        case 0:
            var_16 = 0;
loop_23_00194670:
            if ((var_16 & 0xFFFF) >= 2) {
                var_3 = 1;
            } else if (func_00193d90(
                           arg0 + ((var_16 & 0xFFFF) * 0x10),
                           temp_17) == 0) {
                var_3 = 0;
            } else {
                var_16 = (var_16 + 1) & 0xFFFF;
                goto loop_23_00194670;
            }
            if (var_3 != 0) {
                *(u8 *)(arg0 + 0x45) = 1;
        case 1:
                temp_3_3 = *(s16 *)(arg0 + 0x48);
                if (temp_3_3 <= 0) {
                    *(u8 *)(arg0 + 0x45) = 2;
        case 2:
                    if ((*(s32 (**)(s32))(arg0 + 0x6C))(
                            *(s32 *)(arg0 + 0x78)) != 0) {
                        *(u8 *)(arg0 + 0x45) = 3;
        case 3:
                        var_16_2 = 0;
loop_37_00194670:
                        if ((var_16_2 & 0xFFFF) >= 2) {
                            var_3_2 = 1;
                        } else if (func_00193d90(
                                       ((var_16_2 & 0xFFFF) * 0x10) +
                                           arg0 + 0x20,
                                       temp_17) == 0) {
                            var_3_2 = 0;
                        } else {
                            var_16_2 =
                                (var_16_2 + 1) & 0xFFFF;
                            goto loop_37_00194670;
                        }
                        if (var_3_2 != 0) {
                            *(u8 *)(arg0 + 0x45) = 4;
        case 4:
                            temp_3_4 = *(s16 *)(arg0 + 0x4A);
                            if (temp_3_4 <= 0) {
                                temp_2_2 =
                                    *(void (**)(u8 *))(arg0 + 0x70);
                                if (temp_2_2 != NULL) {
                                    temp_2_2(*(u8 **)(arg0 + 0x78));
                                }
                                if ((*(u8 *)(arg0 + 0x47) & 8) != 0) {
                                    temp_5_2 = *(u8 *)(arg0 + 0x44);
                                    temp_3_5 = *(u8 **)(arg0 + 0x80);
                                    if (temp_3_5 != NULL) {
                                        *(u8 **)(temp_3_5 + 0x7C) =
                                            *(u8 **)(arg0 + 0x7C);
                                    } else {
                                        *(u8 **)(iGpffffb3ac +
                                                 ((temp_5_2 & 0xFF) * 8) +
                                                 0x19C) =
                                            *(u8 **)(arg0 + 0x7C);
                                    }
                                    temp_3_6 = *(u8 **)(arg0 + 0x7C);
                                    if (temp_3_6 != NULL) {
                                        *(u8 **)(temp_3_6 + 0x80) =
                                            *(u8 **)(arg0 + 0x80);
                                    } else {
                                        *(u8 **)(iGpffffb3ac +
                                                 ((temp_5_2 & 0xFF) * 8) +
                                                 0x198) =
                                            *(u8 **)(arg0 + 0x80);
                                    }
                                }
                                jtbl_008873EC[0](arg0);
                                return;
                            }
                            *(s16 *)(arg0 + 0x4A) = temp_3_4 - 1;
                        }
                    } else {
                        *(s32 *)(arg0 + 0x50) =
                            *(s32 *)(arg0 + 0x50) + 1;
                        return;
                    }
                } else {
                    *(s16 *)(arg0 + 0x48) = temp_3_3 - 1;
                    return;
                }
            }
            break;
        }
    }
}

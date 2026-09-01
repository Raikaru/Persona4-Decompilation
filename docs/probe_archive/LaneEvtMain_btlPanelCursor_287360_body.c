/* Closest clean-C candidate; rejected after register/source-order variants, compiler-floor triage. */
// FUN_00287360
void func_00287360(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    s16 sp6E;
    s16 sp6C;
    f32 sp64;
    f32 sp60;
    s8 sp58[8];
    f32 var_f12;
    s32 temp_6;
    s32 var_4;
    s32 var_3;
    s32 var_9;
    s32 temp_8;
    s32 temp_3;

    var_4 = 1;
    temp_6 = *(s32 *)(arg4 + 0);
    if (arg2 != NULL) {
        var_9 = *(u16 *)(arg2 + 0);
    } else {
        var_9 = *(u16 *)(arg4 + 0xC);
    }
    if (arg1 != NULL) {
        var_3 = *(u16 *)(arg1 + 0);
    } else {
        var_3 = *(u16 *)(arg4 + 0x10);
    }
    temp_8 = var_3 - var_9;
    if (temp_8 != 0) {
        var_f12 = (f32)(arg3 - var_9) / (f32)temp_8;
    } else {
        var_f12 = 0.0f;
    }
    temp_3 = *(s32 *)(arg0 + 0);
    switch (temp_3) {
    case 39:
        if ((arg2 != NULL) && (*(u16 *)(arg2 + 0) == arg3)) {
            if (*(s8 *)(arg2 + 0x10) != 0) {
                func_0028b270(1);
                DAT_007645DC = *(s16 *)(arg2 + 0x14);
            } else {
                DAT_007645DC = 0;
                func_0028b270(0);
            }
            func_00440b68((char *)D_0063C400, DAT_007645D8,
                          DAT_007645DC);
        }
        break;
    case 25:
    case 8:
    case 17:
    case 16:
    case 27:
    case 23:
    case 15:
    case 14:
    case 13:
    case 11:
        break;
    case 10: {
        s32 var_3_2;
        s32 var_6_2;
        s32 temp_4_2;
        s64 var_16;
        u8 *var_19;
        if (arg2 != NULL) {
            var_3_2 = *(s32 *)(arg2 + 0x48);
            var_4 = *(s32 *)(arg2 + 4);
        } else {
            var_3_2 = 0;
        }
        if (arg1 != NULL) {
            var_6_2 = *(s32 *)(arg1 + 0x48);
        } else {
            var_6_2 = 0;
        }
        if ((var_3_2 != 0) || (var_6_2 != 0)) {
            func_0028f990(var_4, var_f12, (f32 *)var_3_2,
                          (f32 *)var_6_2, D_008821B0);
            var_19 = NULL;
            var_16 = 0;
            temp_4_2 = *(s8 *)(arg0 + 0x1E);
            switch (temp_4_2) {
            case 2:
                var_16 = 1;
                break;
            case 3:
                if (arg2 != NULL) {
                    var_19 = (u8 *)func_00145270(*(u16 *)(arg0 + 0x20));
                    if (var_19 != NULL) {
                        var_16 = (var_19 != NULL);
                        if (*(u16 *)(arg2 + 2) != 0) {
                        }
                    }
                }
                break;
            case 1:
                var_16 = (arg2 != NULL);
                break;
            default:
                if (*(s8 *)(arg0 + 0x1E) != 0) {
                    func_0046d730(D_0063C3B0, 0x700);
                }
                break;
            }
            if (var_16 != 0) {
                func_0028ced0(*(s32 *)(arg0 + 4),
                              *(s8 *)(arg0 + 0x1E), (s32)var_19,
                              D_008821B0, D_008821C0, D_008821D0);
            }
        }
        break;
    }
    case 6: {
        s32 temp_4;
        s32 temp_3_2;
        s32 temp_19;
        s32 temp_18;
        s32 temp_3_3;
        s32 temp_2;
        s32 var_4_2;
        u8 *temp_2_2;
        s8 *var_6;
        s8 *var_5;
        if (arg2 != NULL) {
            temp_4 = (temp_6 & 0x10) != 0;
            if ((temp_4 != 1) &&
                (*(u16 *)(arg2 + 0) == arg3) &&
                (func_00122720() != 0)) {
                temp_3_2 = *(s16 *)(arg2 + 0x10);
                if (temp_3_2 == 1) {
                    temp_19 = *(s16 *)(arg2 + 0x12);
                    if (temp_19 == 7) {
                        *(s8 *)(arg4 + 0x44) |= 4;
                    } else {
                        temp_18 = *(s8 *)(arg2 + 0x14);
                        *(s32 *)(arg4 + 0x758) = 1;
                        if ((temp_19 != 0) ||
                            (func_001227a0() != 0)) {
                            var_6 = (s8 *)D_00763888;
                            var_5 = sp58;
                            var_4_2 = 4;
                            do {
                                temp_3_3 = var_6[0];
                                temp_2 = var_6[1];
                                var_6 += 2;
                                var_4_2 -= 1;
                                var_5[0] = temp_3_3;
                                var_5[1] = temp_2;
                                var_5 += 2;
                            } while (var_4_2 > 0);
                            func_00122520(temp_19, *(u16 *)(arg2 + 2));
                            if ((temp_18 != 0) &&
                                ((u32)temp_18 < 3U)) {
                                temp_2_2 = (u8 *)((s32)temp_18 * 4 +
                                                  (s32)(u8 *)&sp58 - 4);
                                func_001228a0(temp_2_2[0],
                                              temp_2_2[1],
                                              temp_2_2[2]);
                            }
                        }
                    }
                } else if ((temp_3_2 == 0) &&
                           (func_001227a0() != 0)) {
                    *(s32 *)(arg4 + 0x758) = 1;
                    if (*(s16 *)(arg2 + 0x12) == -1) {
                        *(s16 *)(arg2 + 0x12) = 0;
                    }
                    func_00122640(*(s16 *)(arg2 + 0x12),
                                  *(u16 *)(arg2 + 2));
                }
            }
        } else if ((temp_6 & 0x80000000) != 0 &&
                   *(s32 *)(arg4 + 0x758) == 1) {
            func_00440b68((char *)D_0063C3F0);
            func_00122640(1, 1);
            *(s32 *)(arg4 + 0x758) = 0;
        }
        break;
    }
    case 36: {
        s32 temp_4_4;
        s32 temp_3_4;
        s32 var_4_3;
        s32 var_3_3;
        u8 *var_19;
        if (arg2 != NULL) {
            if (arg3 == *(u16 *)(arg2 + 0)) {
                temp_4_4 = *(s8 *)(arg2 + 0x10);
                if (temp_4_4 == 2) {
                    arg2 = (u8 *)*(s32 *)(arg4 + (*(s32 *)(arg0 + 4) * 4) +
                                           0x6C4);
                    if ((arg2 != NULL) &&
                        (func_00452490((s32)arg2) != 0)) {
                        func_00120f20(arg2);
                    }
                    *(s32 *)(arg4 + (*(s32 *)(arg0 + 4) * 4) +
                             0x6C4) = 0;
                } else if (temp_4_4 == 1) {
                    if (*(s32 *)(arg4 + (*(s32 *)(arg0 + 4) * 4) +
                                 0x6C4) != 0) {
                        if (func_00120ee0((void *)*(s32 *)(
                                arg4 + (*(s32 *)(arg0 + 4) * 4) +
                                0x6C4)) == 0) {
                            temp_3_4 = *(s32 *)(arg0 + 4);
                            if (temp_3_4 == 2) {
                                *(s32 *)arg4 |= 0x800;
                            } else if (temp_3_4 == 1) {
                                *(s32 *)arg4 |= 0x400;
                            } else if (temp_3_4 == 0) {
                                *(s32 *)arg4 |= 0x200;
                            }
                        }
                        func_00120f00((void *)*(s32 *)(
                            arg4 + (*(s32 *)(arg0 + 4) * 4) + 0x6C4));
                    }
                } else if (*(s8 *)(arg2 + 0x10) == 0) {
                    var_4_3 = 0;
                    var_3_3 = 0;
                    if (*(s8 *)(arg2 + 0x20) == 0) {
                        var_4_3 = *(s16 *)(arg2 + 0x14);
                        var_3_3 = *(s16 *)(arg2 + 0x16);
                    }
                    sp6C = var_4_3;
                    sp6E = var_3_3;
                    var_19 = (u8 *)*(s32 *)(
                        arg4 + (*(s32 *)(arg0 + 4) * 4) + 0x6C4);
                    if ((var_19 != NULL) &&
                        (func_00452490((s32)var_19) != 0)) {
                        func_00120f20(var_19);
                    }
                    *(s32 *)(arg4 + (*(s32 *)(arg0 + 4) * 4) + 0x6C4) =
                        func_00120e20((s32)func_00286350(), (s32)sp6C);
                    sp60 = (f32)*(s16 *)(arg2 + 0x1C);
                    sp64 = (f32)*(s16 *)(arg2 + 0x1E);
                    func_00120f40(
                        (u8 *)*(s32 *)(arg4 + (*(s32 *)(arg0 + 4) * 4) +
                                       0x6C4),
                        *(s64 *)&sp60);
                }
            }
        } else if ((temp_6 & 0x80000000) != 0) {
            arg2 = (u8 *)*(s32 *)(arg4 + (*(s32 *)(arg0 + 4) * 4) +
                                  0x6C4);
            if (arg2 != NULL) {
                if (func_00452490((s32)arg2) != 0) {
                    func_00120f20(arg2);
                    if (func_00120ee0(arg2) != 0) {
                        func_00452080((s32)arg2);
                    }
                }
                *(s32 *)(arg4 + (*(s32 *)(arg0 + 4) * 4) +
                         0x6C4) = 0;
            }
        }
        break;
    }
    default:
        break;
    }
}

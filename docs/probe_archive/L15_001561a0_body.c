/* Closest non-MATCH candidate archived before reverting; lverify report had MISMATCH. */
s32 func_001561a0(u8 *arg0)
{
    s16 temp_4_2;
    s16 var_18;
    s32 temp_2;
    s32 temp_4;
    s32 temp_4_3;
    s64 temp_17;
    s64 temp_18;
    s64 var_17;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_2 = *(s32 *)(temp_16 + 0);
    if (temp_2 < 3) {
        goto after_check;
    }
    if (func_00106330(0x1470) != 0) {
        goto after_check;
    }
    func_002aaa80();
after_check:
    temp_2 = *(s32 *)(temp_16 + 0);
    switch (temp_2) {
    case 0:
        if (func_0014ef40() != 0) {
            if (func_0014a230(*(u16 *)(temp_16 + 8),
                              *(u16 *)(temp_16 + 0xA)) == 0) {
                *(s32 *)(temp_16 + 0x18) =
                    (s32)func_001601e0(*(u16 *)(temp_16 + 8));
            }
            *(s32 *)(temp_16 + 0) = 1;
    case 1:
            if (func_001602a0(*(s32 *)(temp_16 + 0x18),
                              *(u16 *)(temp_16 + 8)) != 0) {
                *(s32 *)(temp_16 + 0x18) = 0;
                iGpffffb210 = 0;
                if ((*(s32 *)(temp_16 + 4) == 0) &&
                    (D_007D3D64[0] != NULL) &&
                    (iGpffffb268 == 0)) {
                    *(s32 *)(temp_16 + 0x1C) =
                        func_0029db50(0xF, D_007D3D64[0], D_007D3D68[0],
                                       *(u16 *)(temp_16 + 0xA) - 1);
                }
                *(s32 *)(temp_16 + 0) += 1;
        case 2:
                if ((*(s32 *)(temp_16 + 4) != 0) ||
                    ((temp_4 = *(s32 *)(temp_16 + 0x1C),
                      (temp_4 == 0)) ||
                     (func_00452490(temp_4) != 1))) {
                    *(s32 *)(temp_16 + 0x18) =
                        (s32)func_0015ff20(*(u16 *)(temp_16 + 8),
                                           *(u16 *)(temp_16 + 0xA));
                    func_00144c90(*(u16 *)(temp_16 + 8),
                                  *(u16 *)(temp_16 + 0xA));
                    func_00144e10(*(s16 *)(temp_16 + 0xC));
                    temp_4_2 = *(s16 *)(temp_16 + 0xE);
                    if (temp_4_2 != 0) {
                        func_00144ed0(temp_4_2);
                    } else {
                        var_17 = -1;
                        var_18 = 0;
                        if (*(s32 *)(temp_16 + 4) == 1) {
                            temp_18 = (s64)(func_001060b0() << 0x30) >> 0x30;
                            var_17 =
                                (s64)(s32)func_00248e20(
                                    *(s32 *)(temp_16 + 0x10),
                                    *(s32 *)(temp_16 + 0x14),
                                    (s64)(func_00110960(
                                              temp_18,
                                              func_001060c0() & 0xFF) << 0x38) >>
                                        0x38);
                            if (var_17 != -1) {
                                if (var_17 & 0x8000) {
                                    var_18 = var_17 & 0x7FF;
                                } else {
                                    iGpffffb20c = 1;
                                    func_00123aa0(
                                        (s64)(var_17 << 0x30) >> 0x30);
                                }
                            }
                        }
                        if (var_18 == 0) {
                            if (var_17 == -1) {
                                temp_17 =
                                    (s64)(func_001060b0() << 0x30) >> 0x30;
                                var_17 =
                                    (s64)(func_00110960(
                                              temp_17,
                                              func_001060c0() & 0xFF) << 0x38) >>
                                    0x38;
                            }
                            *(s16 *)(temp_16 + 0xE) =
                                func_00154720(*(u16 *)(temp_16 + 8),
                                              *(u16 *)(temp_16 + 0xA), var_17);
                        } else {
                            *(s16 *)(temp_16 + 0xE) = var_18;
                        }
                        func_00144ed0(*(s16 *)(temp_16 + 0xE));
                    }
                    *(s32 *)(temp_16 + 0) += 1;
            case 3:
                    if (func_00160000(*(u8 **)(temp_16 + 0x18)) != 0) {
                        *(s32 *)(temp_16 + 0x18) = 0;
                        if (func_00144f60() != 0) {
                            iGpffffb210 = 1;
                            if (D_007D3D64[0] != NULL) {
                                *(s32 *)(temp_16 + 0x1C) =
                                    func_0029db50(
                                        0xF, D_007D3D64[0], D_007D3D68[0],
                                        *(u16 *)(temp_16 + 0xA) - 1);
                            }
                            *(s32 *)(temp_16 + 0) += 1;
                    case 4:
                            temp_4 = *(s32 *)(temp_16 + 0x1C);
                            if ((temp_4 == 0) ||
                                (func_00452490(temp_4) != 1)) {
                                if (func_0014a190(
                                        *(u16 *)(temp_16 + 8),
                                        *(u16 *)(temp_16 + 0xA)) == 0) {
                                    D_007D2544[0] =
                                        func_0014e5e0(0, D_005EFF80, -1,
                                                      D_007E3710[0]);
                                    D_007D2548[0] =
                                        func_0014e5e0(0, D_005EFFA0, -1,
                                                      D_007E3714[0]);
                                    D_007D254C[0] =
                                        func_0014e5e0(0, D_005EFFC0, -1,
                                                      D_007E3718[0]);
                                }
                                *(s32 *)(temp_16 + 0) += 1;
                        case 5:
                                if ((func_0014a190(
                                         *(u16 *)(temp_16 + 8),
                                         *(u16 *)(temp_16 + 0xA)) != 0) ||
                                    ((func_0014e710(D_007D2544[0]) != 0) &&
                                     (func_0014e710(D_007D2548[0]) != 0) &&
                                     (func_0014e710(D_007D254C[0]) != 0))) {
                                    D_007D2514[0] =
                                        func_0016e2e0((s32)D_007D2510);
                                    func_00155070();
                                    *(s32 *)(temp_16 + 0) = 8;
                            case 8:
                                    return -1;
                                }
                                goto block_48;
                            }
                            goto block_48;
                        }
                    }
                    goto block_48;
                }
                goto block_48;
            }
            goto block_48;
        }
    default:
block_48:
        return 0;
    }
}

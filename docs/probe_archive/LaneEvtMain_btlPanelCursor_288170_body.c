/* Closest clean-C candidate; rejected after stack/order/branch variants, compiler-floor triage. */
typedef struct {
    u8 sp70[0x20];
    u8 sp90[0x20];
    s32 spB0[4];
    u8 spC0[0x130];
    u8 sp1F0[0x10];
    f32 sp200[4];
    f32 sp210[4];
    f32 sp220[4];
    f32 sp230[4];
    u8 sp240[0x10];
    f32 sp250[4];
} Func00288170Scratch;
#define sp70 (work.sp70)
#define sp90 (work.sp90)
#define spB0 (work.spB0)
#define spC0 (work.spC0)
#define sp1F0 (work.sp1F0)
#define sp200 (work.sp200)
#define sp210 (work.sp210)
#define sp220 (work.sp220)
#define sp230 (work.sp230)
#define sp240 (work.sp240)
#define SP250 (work.sp250)
// FUN_00288170
s32 func_00288170(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3, u8 *arg4) {
    Func00288170Scratch work;
    u8 *var_3;
    s32 var_2;
    s32 var_16;
    s32 temp_3_6;
    s32 temp_3_9;
    s8 temp_2;
    s8 temp_3;
    s8 temp_3_2;
    s8 temp_3_3;
    s8 temp_3_4;
    s8 temp_3_5;
    s8 temp_3_7;
    s8 temp_3_8;
    s8 temp_3_10;
    s32 temp_16;
    s32 temp_17;
    s32 var_7;
    s32 var_17;
    f32 temp_f20;
    f32 var_f20;
    u16 temp_4;
    u16 temp_4_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;

    var_3 = sp240;
    var_2 = 0xC;
    if (var_3 != NULL) {
        do {
            *var_3 = 0;
            var_3++;
            var_2--;
        } while (var_2 != 0);
    }
    var_16 = 0;
    var_f20 = 0.0f;
    switch (arg0) {
    case 0:
        if (D_008821E0[0] != 1) {
            return 0;
        }
        if (func_00145270(*(u16 *)(arg3 + 0xC)) != NULL) {
            goto case0_nonnull;
        }
        return 1;
    case0_nonnull:
        var_2 = ((*(u32 *)(arg2 + 0) & 0x80000000) != 0);
        if (var_2 != 0 &&
            arg1 == *(s32 *)(arg2 + 0xC)) {
            func_00146e60(*(u16 *)(arg3 + 0xC),
                          arg3 + 0x38, arg3 + 0x44);
            SP250[0] = 1.0f;
            SP250[1] = 1.0f;
            SP250[2] = 1.0f;
            func_00146ee0(*(u16 *)(arg3 + 0xC),
                          (u8 *)SP250);
            func_00269740(*(u16 *)(arg3 + 0xC));
            func_00269620(*(u16 *)(arg3 + 0xC),
                          *(u8 *)(arg3 + 0x53), 0, 0);
            *(s32 *)(arg3 + 0x60) = 0;
            func_00293270();
            if ((*(s32 *)(arg3 + 0x54) & 2) != 0) {
                func_00269c20(*(u16 *)(arg3 + 0xC), 1);
            } else {
                func_00269c20(*(u16 *)(arg3 + 0xC), 0);
            }
        }
        return 1;
    case 1:
        return 1;
    case 2:
        if (*(u16 *)(arg4 + 0) == arg1) {
            temp_2 = *(s8 *)(arg4 + 0x10);
            switch (temp_2) {
            case 0:
                if (*(s8 *)(arg4 + 0x14) != 0) {
                    func_00269c20(*(u16 *)(arg3 + 0xC), 0);
                } else {
                    func_00269c20(*(u16 *)(arg3 + 0xC), 1);
                }
                break;
            case 1:
                temp_3 = *(s8 *)(arg4 + 0x14);
                switch (temp_3) {
                case 0:
                    *(f32 *)(sp230 + 0) = *(f32 *)(arg4 + 0x18);
                    *(f32 *)(sp230 + 4) = *(f32 *)(arg4 + 0x1C);
                    *(f32 *)(sp230 + 8) = *(f32 *)(arg4 + 0x20);
                    if ((*(s8 *)(arg4 + 0x15) == 0) &&
                        (func_00268e60(*(u16 *)(arg3 + 0xC),
                                       (u8 *)sp230,
                                       func_0028bf90(*(s16 *)(arg4 + 0x16))) == 1)) {
                        *(s32 *)(arg3 + 0x60) =
                            (*(s8 *)(arg4 + 0x25) != 0);
                        temp_3_2 = *(s8 *)(arg4 + 0x34);
                        if ((temp_3_2 & 1) != 0) {
                            func_0026bda0(
                                *(u16 *)(arg3 + 0xC), 1,
                                (s8)((*(s8 *)(arg4 + 0x35) + 1) & 0xFF),
                                *(s8 *)(arg4 + 0x36),
                                *(s8 *)(arg4 + 0x37),
                                (s8)(temp_3_2 >> 1));
                        }
                        if (*(s8 *)(arg4 + 0x26) == 1) {
                            temp_2_2 =
                                (u8 *)func_00145270(*(u16 *)(arg3 + 0xC));
                            if ((temp_2_2 != NULL) &&
                                (func_00268e30(
                                     (f32 *)(temp_2_2 + 4),
                                     sp230,
                                     &work.sp250[3]) == 1)) {
                                *(f32 *)(sp240 + 4) = work.sp250[3];
                                func_00269340(*(u16 *)(arg3 + 0xC),
                                              (u8 *)sp240, 0xF, 0);
                            }
                        }
                    }
                    break;
                case 1:
                    func_0028d1b0(*(u8 **)(arg4 + 0x40), spC0, 0);
                    if (*(s8 *)(arg4 + 0x15) == 0) {
                        temp_f20 =
                            func_0028bf90(*(s16 *)(arg4 + 0x16));
                        temp_17 = (*(s8 *)(arg4 + 0x24) != 0);
                        var_17 = (*(s8 *)(arg4 + 0x25) != 0);
                        temp_3_3 = *(s8 *)(arg4 + 0x34);
                        if ((temp_3_3 & 1) != 0) {
                            func_0026bda0(
                                *(u16 *)(arg3 + 0xC), 1,
                                (s8)((*(s8 *)(arg4 + 0x35) + 1) & 0xFF),
                                *(s8 *)(arg4 + 0x36),
                                *(s8 *)(arg4 + 0x37),
                                (s8)(temp_3_3 >> 1));
                        }
                        if (*(s8 *)spC0 > 0) {
                            func_002692d0(*(u16 *)(arg3 + 0xC),
                                          (u32)spC0, temp_f20, temp_17);
                            *(s32 *)(arg3 + 0x60) = var_17;
                            func_00440b68((char *)D_0063C510);
                        }
                    }
                    break;
                case 2:
                    temp_2_3 =
                        (u8 *)func_00145270(*(u16 *)(arg3 + 0xC));
                    if (temp_2_3 != NULL) {
                        *(f32 *)(sp220 + 0) = *(f32 *)(arg4 + 0x18);
                        *(f32 *)(sp220 + 4) = *(f32 *)(arg4 + 0x1C);
                        *(f32 *)(sp220 + 8) = *(f32 *)(arg4 + 0x20);
                        *(f32 *)(sp210 + 0) = *(f32 *)(arg4 + 0x28);
                        *(f32 *)(sp210 + 4) = *(f32 *)(arg4 + 0x2C);
                        *(s32 *)(sp210 + 8) = 0;
                        func_00146a10(temp_2_3, (u8 *)sp220,
                                      (u8 *)sp210, 0);
                    }
                    break;
                }
                break;
            case 4:
                *(f32 *)(sp240 + 0) = 0.0f;
                *(f32 *)(sp240 + 4) = *(f32 *)(arg4 + 0x14);
                *(f32 *)(sp240 + 8) = 0.0f;
                func_00269340(*(u16 *)(arg3 + 0xC), (u8 *)sp240,
                              *(s16 *)(arg4 + 0x24), 0);
                temp_3_4 = *(s8 *)(arg4 + 0x34);
                if ((temp_3_4 & 1) != 0) {
                    func_0026bda0(
                        *(u16 *)(arg3 + 0xC), 2,
                        (s8)((*(s8 *)(arg4 + 0x35) + 1) & 0xFF),
                        *(s8 *)(arg4 + 0x36),
                        *(s8 *)(arg4 + 0x37),
                        (s8)(temp_3_4 >> 1));
                    func_00440b68((char *)D_0063C530);
                }
                break;
            case 11:
                var_3 = (u8 *)spB0;
                var_2 = 0x10;
                if (var_3 != NULL) {
                    do {
                        *var_3 = 0;
                        var_3 = (u8 *)var_3 + 1;
                        var_2--;
                    } while (var_2 != 0);
                }
                *(s32 *)(spB0 + 0) = *(s8 *)(arg4 + 0x35);
                *(s32 *)(spB0 + 4) = *(s8 *)(arg4 + 0x36);
                *(s32 *)(spB0 + 8) = *(s8 *)(arg4 + 0x37);
                *(s32 *)(spB0 + 0xC) = *(s8 *)(arg4 + 0x30);
                if (*(s8 *)(arg4 + 0x34) != 0) {
                    func_00293710(
                        *(u16 *)(arg3 + 0xC), 4, 0.0f, 0.0f,
                        *(f32 *)(arg4 + 0x14), 0.0f,
                        *(s8 *)(arg4 + 0x24), (u8 *)spB0);
                } else {
                    func_00293710(
                        *(u16 *)(arg3 + 0xC), 4, 0.0f, 0.0f,
                        *(f32 *)(arg4 + 0x14), 0.0f,
                        *(s8 *)(arg4 + 0x24), NULL);
                }
                break;
            case 5:
                temp_3_5 = *(s8 *)(arg4 + 0x15);
                switch (temp_3_5) {
                case 1:
                    break;
                case 0:
                    func_0026bc10(*(u16 *)(arg3 + 0xC),
                                  *(u8 *)(arg4 + 0x14));
                    break;
                }
                break;
            case 6:
                temp_4 = *(u16 *)(arg3 + 0xC);
                temp_3_6 = (temp_4 & 0xFFC00) >> 10;
                switch (temp_3_6) {
                case 3:
                    temp_2_4 = (u8 *)func_00145270(temp_4);
                    if (temp_2_4 != NULL) {
                        var_16 = *(s32 *)(temp_2_4 + 0x164);
                    }
                    break;
                case 1:
                    temp_2_5 = (u8 *)func_00145270(temp_4);
                    if (temp_2_5 != NULL) {
                        var_16 = *(s32 *)(temp_2_5 + 0x164);
                    }
                    break;
                }
                temp_3_7 = *(s8 *)(arg4 + 0x15);
                switch (temp_3_7) {
                case 0:
                    var_f20 = fGpffff8218;
                    break;
                case 1:
                    var_f20 = fGpffff809c;
                    break;
                case 2:
                    var_f20 = fGpffff8504;
                    break;
                }
                temp_3_8 = *(s8 *)(arg4 + 0x14);
                switch (temp_3_8) {
                case 0:
                    if (var_16 != 0) {
                        func_002932b0(*(u16 *)(arg3 + 0xC));
                        var_3 = sp1F0;
                        var_2 = 0xC;
                        if (var_3 != NULL) {
                            do {
                                *var_3 = 0;
                                var_3++;
                                var_2--;
                            } while (var_2 != 0);
                        }
                        *(f32 *)(sp200 + 0) = *(f32 *)(arg4 + 0x18);
                        *(f32 *)(sp200 + 4) = *(f32 *)(arg4 + 0x1C);
                        *(s32 *)(sp200 + 8) = 0;
                        func_00146f50(sp70, sp1F0, (u8 *)sp200);
                        func_0047a890((void *)var_16, var_f20);
                        func_0047a900((void *)var_16, sp90);
                    }
                    break;
                case 1:
                    if (var_16 != 0) {
                        if (func_0047a9d0((void *)var_16) == 1) {
                            func_0047a890((void *)var_16,
                                          fGpffff8218);
                            func_0047a990((void *)var_16);
                        }
                        func_002932b0(*(u16 *)(arg3 + 0xC));
                    }
                    break;
                case 2:
                    func_002933a0(*(u16 *)(arg3 + 0xC), 1,
                                  var_f20 / fGpffff8218);
                    break;
                case 3:
                    func_002933a0(*(u16 *)(arg3 + 0xC), 2,
                                  var_f20 / fGpffff8218);
                    break;
                case 4:
                    func_00293550(*(u16 *)(arg3 + 0xC),
                                  *(u16 *)(arg4 + 0x18), 3,
                                  var_f20 / fGpffff8218);
                    break;
                }
                break;
            case 7:
                temp_4_2 = *(u16 *)(arg3 + 0xC);
                temp_3_9 = (temp_4_2 & 0xFFC00) >> 10;
                switch (temp_3_9) {
                case 3:
                    temp_2_6 = (u8 *)func_00145270(temp_4_2);
                    if (temp_2_6 != NULL) {
                        var_16 = *(s32 *)(temp_2_6 + 0x164);
                    }
                    break;
                case 1:
                    temp_2_6 = (u8 *)func_00145270(temp_4_2);
                    if (temp_2_6 != NULL) {
                        var_16 = *(s32 *)(temp_2_6 + 0x164);
                    }
                    break;
                }
                temp_3_10 = *(s8 *)(arg4 + 0x14);
                if (temp_3_10 == 0) {
                    if (var_16 != 0) {
                        func_002915f0(arg2, var_16,
                                      *(s8 *)(arg4 + 0x15),
                                      *(s16 *)(arg4 + 0x16),
                                      *(s32 *)(arg4 + 0x18));
                    }
                } else if ((temp_3_10 == 1) && (var_16 != 0)) {
                    func_00291790((u8 *)var_16,
                                  *(s8 *)(arg4 + 0x15));
                }
                break;
            case 8:
                var_7 = 0;
                if (*(s8 *)(arg4 + 0x19) != 0) {
                    var_7 = 1;
                }
                func_00269620(*(u16 *)(arg3 + 0xC),
                              *(u8 *)(arg4 + 0x18),
                              *(s16 *)(arg4 + 0x14), var_7);
                break;
            case 9:
                func_0026bd50(*(u16 *)(arg3 + 0xC),
                              *(s8 *)(arg4 + 0x14) == 0);
                break;
            case 10:
                *(f32 *)(SP250 + 0) = *(f32 *)(arg4 + 0x18);
                *(f32 *)(SP250 + 4) = *(f32 *)(arg4 + 0x18);
                *(f32 *)(SP250 + 8) = *(f32 *)(arg4 + 0x18);
                func_00269440(*(u16 *)(arg3 + 0xC),
                              (u8 *)SP250,
                              *(s16 *)(arg4 + 0x14));
                break;
            }
        }
        return 1;
    default:
        return 1;
    }
}
#undef sp70
#undef sp90
#undef spB0
#undef spC0
#undef sp1F0
#undef sp200
#undef sp210
#undef sp220
#undef sp230

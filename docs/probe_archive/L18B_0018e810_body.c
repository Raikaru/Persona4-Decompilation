/* Closest candidate for func_0018e810; did not match retail (normalized diff nonzero). */

// FUN_0018E810
s32 func_0018e810(u8 *arg0)
{
    f32 spCC;
    s32 temp_16_7;
    s32 temp_17;
    s32 temp_21;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_3;
    s32 var_19;
    s32 var_20;
    u8 temp_16;
    u8 temp_16_2;
    u8 temp_16_3;
    u8 temp_16_4;
    u8 temp_16_5;
    u8 temp_16_6;
    s64 temp_30;
    u8 *temp_18;
    u8 *temp_22;

    temp_18 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)temp_18;
    switch (temp_3) {
    case 0:
        temp_2 = func_00470250(arg0, 0x100, 0x40);
        *(s32 *)(temp_18 + 0x1B438) = temp_2;
        func_00470810(temp_2, &D_005F5730, 4);
        func_00470430(*(s32 *)(temp_18 + 0x1B438), 0x14);
        func_004703c0(*(s32 *)(temp_18 + 0x1B438), 4);
        func_004703d0(*(s32 *)(temp_18 + 0x1B438), 1);
        *(u8 **)(temp_18 + 0x1B434) = (u8 *)&D_007E3720;
        *(s32 *)temp_18 = *(s32 *)temp_18 + 1;
        break;
    case 1:
        if (D_008C024E[0] & 0x40) {
            temp_2_2 = func_00470e20(*(s32 *)(temp_18 + 0x1B438));
            switch (temp_2_2) {
            case 0:
                temp_17 = *func_00470bd0(
                              *(s32 *)(temp_18 + 0x1B438), 3) << 4;
                temp_22 = *(u8 **)(temp_18 + 0x1B434) + temp_17;
                temp_16 = temp_22[8];
                *(func_00155280() + 0x4A) = temp_16;
                temp_17 = *func_00470bd0(
                              *(s32 *)(temp_18 + 0x1B438), 3) << 4;
                temp_22 = *(u8 **)(temp_18 + 0x1B434) + temp_17;
                temp_16_2 = temp_22[9];
                *(func_00155280() + 0x4B) = temp_16_2;
                *(s32 *)(temp_18 + 4) = 2;
                func_001582f0(*(s32 *)(temp_18 + 4),
                              *func_00470bd0(*(s32 *)(temp_18 + 0x1B438), 0),
                              0);
                func_00452080(*(s32 *)(temp_18 + 0x1B438));
                *(s32 *)temp_18 = *(s32 *)temp_18 + 1;
                break;
            case 1:
                temp_17 = *func_00470bd0(
                              *(s32 *)(temp_18 + 0x1B438), 3) << 4;
                temp_22 = *(u8 **)(temp_18 + 0x1B434) + temp_17;
                temp_16_3 = temp_22[8];
                *(func_00155280() + 0x4A) = temp_16_3;
                temp_17 = *func_00470bd0(
                              *(s32 *)(temp_18 + 0x1B438), 3) << 4;
                temp_22 = *(u8 **)(temp_18 + 0x1B434) + temp_17;
                temp_16_4 = temp_22[9];
                *(func_00155280() + 0x4B) = temp_16_4;
                *(s32 *)(temp_18 + 4) = 0;
                func_001582f0(*(s32 *)(temp_18 + 4),
                              *func_00470bd0(*(s32 *)(temp_18 + 0x1B438), 1),
                              0);
                func_00452080(*(s32 *)(temp_18 + 0x1B438));
                *(s32 *)temp_18 = *(s32 *)temp_18 + 1;
                break;
            case 2:
                temp_17 = *func_00470bd0(
                              *(s32 *)(temp_18 + 0x1B438), 3) << 4;
                temp_22 = *(u8 **)(temp_18 + 0x1B434) + temp_17;
                temp_16_5 = temp_22[8];
                *(func_00155280() + 0x4A) = temp_16_5;
                temp_17 = *func_00470bd0(
                              *(s32 *)(temp_18 + 0x1B438), 3) << 4;
                temp_22 = *(u8 **)(temp_18 + 0x1B434) + temp_17;
                temp_16_6 = temp_22[9];
                *(func_00155280() + 0x4B) = temp_16_6;
                *(s32 *)(temp_18 + 4) = 1;
                func_001582f0(*(s32 *)(temp_18 + 4),
                              *func_00470bd0(*(s32 *)(temp_18 + 0x1B438), 2),
                              0);
                func_00452080(*(s32 *)(temp_18 + 0x1B438));
                *(s32 *)temp_18 = *(s32 *)temp_18 + 1;
                break;
            default:
                break;
            }
        }
        break;
    case 2:
        *(s32 *)temp_18 = temp_3 + 1;
        break;
    case 3:
        *(s32 *)temp_18 = temp_3 + 1;
        break;
    case 4:
        if (D_008C024E[0] & 0x8000) {
            *(s32 *)(temp_18 + 0x1B430) = *(s32 *)(temp_18 + 0x1B430) - 1;
        } else if (D_008C024E[0] & 0x2000) {
            *(s32 *)(temp_18 + 0x1B430) = *(s32 *)(temp_18 + 0x1B430) + 1;
        }
        if (*(s32 *)(temp_18 + 0x1B430) < 0) {
            *(s32 *)(temp_18 + 0x1B430) = 3;
        }
        if (*(s32 *)(temp_18 + 0x1B430) >= 4) {
            *(s32 *)(temp_18 + 0x1B430) = 0;
        }
        if (D_008C024E[0] & 0x40) {
            func_001582f0(*(s32 *)(temp_18 + 4), 0, 0);
        }
        func_00450340(iGpffff9fd0, (s32)&iGpffff9fdc, iGpffffb240);
        var_20 = 0;
        while (var_20 < 0x18) {
            var_19 = 0;
            temp_17 = var_20 << 8;
            temp_21 = var_20 * 0x12;
            temp_22 = temp_18 + var_20 * 0x1200;
            while (var_19 < 0x10) {
                temp_16_7 = var_19 * 0x10;
                if ((*(temp_17 + func_00155280() + temp_16_7 + 0x54) != 0) &&
                    ((*(temp_17 + func_00155280() + temp_16_7 + 0x55) & 0xF) == 1)) {
                    temp_30 = *(temp_17 + func_00155280() + temp_16_7 + 0x58);
                    temp_16 = *(temp_17 + func_00155280() + temp_16_7 + 0x59);
                    func_0017d1f0(
                        (s32)&D_007966D0,
                        (s32)(temp_22 + var_19 * 0x120 + 0x10),
                        temp_30, 0, temp_16,
                        (f32)(var_19 * 0x12), (f32)temp_21, 0);
                }
                if (*(temp_17 + func_00155280() + temp_16_7 + 0x54) == 2) {
                    spCC = iGpffff9fd8;
                    func_0014def0(
                        (s32)&D_007966D0,
                        (s32)(temp_22 + var_19 * 0x120 + 0x10),
                        (f32)(var_19 * 0x12), (f32)temp_21,
                        0, 0x41900000, 0x41900000,
                        &spCC, 0, 0, 0, 0, 0, 0, 0);
                }
                var_19 += 1;
            }
            var_20 += 1;
        }
        if (D_008C024E[0] & 0x20) {
            *(s32 *)temp_18 = 0;
        }
        break;
    default:
        break;
    }
    return 0;
}

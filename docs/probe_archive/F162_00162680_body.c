// FUN_00162680
u8 *func_00162680(u16 arg0, u16 arg1, s32 arg2)
{
    extern void func_004787e0(u8 *arg0);
    s32 temp_22;
    s32 *temp_16_2;
    s32 *temp_16_5;
    s32 temp_16;
    s32 temp_16_3;
    s32 temp_16_4;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_5;
    s32 var_16;
    s32 var_17;
    s32 var_18;
    s32 var_19;
    s32 var_4;
    s32 var_4_2;
    u8 **temp_3_2;
    u8 **temp_3_4;
    u8 *temp_17;
    u8 *temp_21;
    u8 *temp_3;
    u8 *temp_3_3;
    u8 *var_20;

    var_19 = 0;
    var_17 = 0;
    var_16 = 0;
    goto loop_test;
loop_body:
    if (arg2 == (s32)(s16)func_00105ee0(var_16)) {
        var_19 = var_16 + 1;
        goto loop_done;
    }
    var_16 += 1;
loop_test:
    if (var_16 < 3) {
        goto loop_body;
    }
loop_done:
    if (arg2 == 1) {
        if (func_00162510(arg0, arg1) == 1) {
            var_18 = 9;
            temp_2 = func_00110d60((s16)func_001060b0());
            switch (temp_2) {
            case 2:
            case 0:
                var_17 = 0x103;
                break;
            case 3:
            case 1:
                var_17 = 0x102;
                break;
            }
        } else {
            temp_16_3 = arg0 & 0xFFFF;
            if ((temp_16_3 == 0x44) && ((arg1 & 0xFFFF) == 1)) {
                var_18 = 9;
                var_17 = 0x100;
            } else if (func_0015a160() != 0) {
                var_18 = 1;
                var_17 = arg2 & 0xFFFF;
            } else if (((temp_16_3 == 7) && ((arg1 & 0xFFFF) == 2)) ||
                       ((temp_16_3 == 7) && ((arg1 & 0xFFFF) == 3))) {
                var_18 = 9;
                temp_2_2 = func_00110d60((s16)func_001060b0());
                switch (temp_2_2) {
                case 0:
                    var_17 = 0x10B;
                    break;
                case 2:
                    var_17 = 0x10D;
                    break;
                case 1:
                    var_17 = 0x10A;
                    break;
                case 3:
                    var_17 = 0x10C;
                    break;
                }
            } else {
                var_18 = 9;
                temp_2_3 = func_00110d60((s16)func_001060b0());
                switch (temp_2_3) {
                case 0:
                    var_17 = 0x101;
                    break;
                case 2:
                    var_17 = 0x105;
                    break;
                case 1:
                    var_17 = 0x100;
                    break;
                case 3:
                    var_17 = 0x104;
                    break;
                }
            }
        }
        temp_16_4 = var_19 * 8;
        temp_21 = D_007F16F0 + temp_16_4;
        temp_22 = var_18 & 0xFFFF;
        if ((temp_22 == *(u16 *)temp_21) &&
            ((var_17 & 0xFFFF) ==
             *(u8 *)(D_007F16F2 + temp_16_4))) {
            var_20 = *(u8 **)(D_007F16F4 + temp_16_4);
        } else {
            var_20 = NULL;
        }
        if (var_20 == NULL) {
            var_20 = func_00478140(var_18, var_17, 0);
            if (temp_22 == 1) {
                func_0047d140();
            } else {
                func_0047aaa0(var_20, 0, (void *)9, (void *)0x163, D_005F13A0, 0);
                func_0047adf0(var_20, 0, 0x1F4);
            }
            if (*(u8 *)(D_007F16F4 + temp_16_4) != 0) {
                var_4_2 = 0;
loop_53:
                if (var_4_2 < 5) {
                    temp_3_3 =
                        (u8 *)(*(s32 *)(temp_21 + 4) + var_4_2 * 0xC);
                    *(u8 *)(temp_3_3 + 0x28C) =
                        *(u8 *)(temp_3_3 + 0x28C) | 1;
                    var_4_2 += 1;
                    goto loop_53;
                }
                temp_16_5 = (s32 *)(D_007F16F4 + var_19 * 8);
                func_004787e0((u8 *)*temp_16_5);
                *temp_16_5 = 0;
            }
            temp_4_2 = var_19 * 8;
            temp_3_4 = (u8 **)(D_007F16F4 + temp_4_2);
            *temp_3_4 = var_20;
            *(u16 *)temp_21 = *(u16 *)(var_20 + 0xD4);
            *(u8 *)(D_007F16F2 + temp_4_2) =
                *(u8 *)(*temp_3_4 + 0xD6);
        } else {
            func_0047a220(var_20, &iGpffff9f10);
            func_0047a990(var_20);
        }
    } else {
        goto generic;
    }
    goto done;
generic:
 
    if (arg2 != 1) {
        temp_5 = arg2 & 0xFFFF;
        temp_16 = var_19 * 8;
        temp_17 = D_007F16F0 + temp_16;
        if ((*(u16 *)temp_17 == 1) &&
            (temp_5 == *(u8 *)(D_007F16F2 + temp_16))) {
            var_20 = *(u8 **)(D_007F16F4 + temp_16);
        } else {
            var_20 = NULL;
        }
        if (var_20 == NULL) {
            var_20 = func_00478140(1, temp_5, 0);
            func_0047d140();
            if (*(u8 *)(D_007F16F4 + temp_16) != 0) {
                var_4 = 0;
loop_65:
                if (var_4 < 5) {
                    temp_3 = (u8 *)(*(s32 *)(temp_17 + 4) + var_4 * 0xC);
                    *(u8 *)(temp_3 + 0x28C) =
                        *(u8 *)(temp_3 + 0x28C) | 1;
                    var_4 += 1;
                    goto loop_65;
                }
                temp_16_2 = (s32 *)(D_007F16F4 + var_19 * 8);
                func_004787e0((u8 *)*temp_16_2);
                *temp_16_2 = 0;
            }
            temp_4 = var_19 * 8;
            temp_3_2 = (u8 **)(D_007F16F4 + temp_4);
            *temp_3_2 = var_20;
            *(u16 *)temp_17 = *(u16 *)(var_20 + 0xD4);
            *(u8 *)(D_007F16F2 + temp_4) =
                *(u8 *)(*temp_3_2 + 0xD6);
        } else {
            func_0047a220(var_20, &iGpffff9f10);
            func_0047a990(var_20);
        }
    }
done:
    return var_20;
}

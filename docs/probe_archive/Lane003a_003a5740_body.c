/* Attempted reconstruction; restored to INCLUDE_ASM because scoped lverify remained MISMATCH (object 516B/window 512B, nd 315). */
void func_003a5740(u8 *arg0, s32 arg3, u8 *arg4)
{
    s32 temp_3;
    s32 temp_6;
    s32 var_4;
    s32 var_9;
    u8 *var_5;
    u8 *var_8;
    u8 *temp_10;
    u8 *temp_11;
    u8 *temp_12;
    u8 *temp_13;
    u8 *temp_14;
    u8 *temp_15;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_18;
    u8 *temp_19;
    u8 *temp_20;
    u8 *temp_21;
    u8 *temp_24;
    u8 *temp_25;

    var_5 = *(u8 **)(arg4 + 4);
    temp_6 = *(s32 *)(arg4 + 8);
    temp_3 = *(s32 *)(arg0 + 4);
    var_8 = *(u8 **)arg0;
    if (temp_6 != temp_3) {
        var_4 = 0;
        if (arg3 > 0) {
            if (arg3 >= 9) {
                var_9 = 0;
                if ((arg3 >= 0) && (arg3 < 0x7FFFFFFF)) {
                    var_9 = 1;
                }
                if (var_9 != 0) {
                    do {
                        temp_20 = var_5 + temp_6;
                        temp_21 = var_8 + temp_3;
                        temp_18 = temp_20 + temp_6;
                        temp_19 = temp_21 + temp_3;
                        temp_16 = temp_18 + temp_6;
                        temp_17 = temp_19 + temp_3;
                        temp_24 = temp_16 + temp_6;
                        temp_25 = temp_17 + temp_3;
                        temp_14 = temp_24 + temp_6;
                        temp_15 = temp_25 + temp_3;
                        temp_12 = temp_14 + temp_6;
                        *(f32 *)(var_8 + 0) = *(f32 *)(var_5 + 0);
                        temp_13 = temp_15 + temp_3;
                        var_4 += 8;
                        temp_10 = temp_12 + temp_6;
                        temp_11 = temp_13 + temp_3;
                        *(f32 *)(var_8 + 4) = *(f32 *)(var_5 + 4);
                        *(f32 *)(var_8 + 8) = *(f32 *)(var_5 + 8);
                        var_5 = temp_10 + temp_6;
                        var_8 = temp_11 + temp_3;
                        *(f32 *)(temp_21 + 0) = *(f32 *)(temp_20 + 0);
                        *(f32 *)(temp_21 + 4) = *(f32 *)(temp_20 + 4);
                        *(f32 *)(temp_21 + 8) = *(f32 *)(temp_20 + 8);
                        *(f32 *)(temp_19 + 0) = *(f32 *)(temp_18 + 0);
                        *(f32 *)(temp_19 + 4) = *(f32 *)(temp_18 + 4);
                        *(f32 *)(temp_19 + 8) = *(f32 *)(temp_18 + 8);
                        *(f32 *)(temp_17 + 0) = *(f32 *)(temp_16 + 0);
                        *(f32 *)(temp_17 + 4) = *(f32 *)(temp_16 + 4);
                        *(f32 *)(temp_17 + 8) = *(f32 *)(temp_16 + 8);
                        *(f32 *)(temp_25 + 0) = *(f32 *)(temp_24 + 0);
                        *(f32 *)(temp_25 + 4) = *(f32 *)(temp_24 + 4);
                        *(f32 *)(temp_25 + 8) = *(f32 *)(temp_24 + 8);
                        *(f32 *)(temp_15 + 0) = *(f32 *)(temp_14 + 0);
                        *(f32 *)(temp_15 + 4) = *(f32 *)(temp_14 + 4);
                        *(f32 *)(temp_15 + 8) = *(f32 *)(temp_14 + 8);
                        *(f32 *)(temp_13 + 0) = *(f32 *)(temp_12 + 0);
                        *(f32 *)(temp_13 + 4) = *(f32 *)(temp_12 + 4);
                        *(f32 *)(temp_13 + 8) = *(f32 *)(temp_12 + 8);
                        *(f32 *)(temp_11 + 0) = *(f32 *)(temp_10 + 0);
                        *(f32 *)(temp_11 + 4) = *(f32 *)(temp_10 + 4);
                        *(f32 *)(temp_11 + 8) = *(f32 *)(temp_10 + 8);
                    } while (var_4 < (arg3 - 8));
                }
            }
            if (var_4 < arg3) {
                do {
                    var_4 += 1;
                    *(f32 *)(var_8 + 0) = *(f32 *)(var_5 + 0);
                    *(f32 *)(var_8 + 4) = *(f32 *)(var_5 + 4);
                    *(f32 *)(var_8 + 8) = *(f32 *)(var_5 + 8);
                    var_5 += temp_6;
                    var_8 += temp_3;
                } while (var_4 < arg3);
            }
        }
    } else {
        func_003a4d50(var_8, var_5, arg3 * temp_3);
    }
}

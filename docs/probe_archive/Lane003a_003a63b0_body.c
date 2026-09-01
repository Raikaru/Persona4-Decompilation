/* Attempted reconstruction; restored to INCLUDE_ASM because scoped lverify remained MISMATCH (object 448B/window 448B, nd 289 after register-order probes). */
void func_003a63b0(u8 *arg0, s32 arg1, u8 *arg2)
{
    s32 temp_3;
    s32 temp_4;
    s32 var_9;
    s32 var_6;
    f32 *var_7;
    f32 *var_8;
    f32 *temp_10;
    f32 *temp_11;
    f32 *temp_12;
    f32 *temp_13;
    f32 *temp_14;
    f32 *temp_15;
    f32 *temp_16;
    f32 *temp_17;
    f32 *temp_18;
    f32 *temp_19;
    f32 *temp_20;
    f32 *temp_24;
    f32 *temp_25;
    f32 *temp_7;
    f32 temp_f0;

    var_8 = *(f32 **)arg0;
    temp_3 = *(s32 *)(arg2 + 0x20);
    temp_4 = *(s32 *)(arg0 + 4);
    var_7 = *(f32 **)(arg2 + 0x1C);
    if (temp_3 != temp_4) {
        var_6 = 0;
        if (arg1 > 0) {
            if (arg1 >= 9) {
                var_9 = 0;
                if ((arg1 >= 0) && (arg1 < 0x7FFFFFFF)) {
                    var_9 = 1;
                }
                if (var_9 != 0) {
                    do {
                        temp_20 = (f32 *)((s32)var_8 + temp_4);
                        temp_19 = (f32 *)((s32)temp_20 + temp_4);
                        temp_17 = (f32 *)((s32)temp_19 + temp_4);
                        var_6 += 8;
                        temp_25 = (f32 *)((s32)temp_17 + temp_4);
                        temp_15 = (f32 *)((s32)temp_25 + temp_4);
                        temp_13 = (f32 *)((s32)temp_15 + temp_4);
                        temp_11 = (f32 *)((s32)temp_13 + temp_4);
                        *(f32 *)((s32)var_8 + 0) =
                            *(f32 *)((s32)var_7 + 0);
                        temp_7 = (f32 *)((s32)var_7 + temp_3);
                        *(f32 *)((s32)var_8 + 4) =
                            *(f32 *)((s32)var_7 + 4);
                        temp_18 = (f32 *)((s32)temp_7 + temp_3);
                        temp_16 = (f32 *)((s32)temp_18 + temp_3);
                        temp_24 = (f32 *)((s32)temp_16 + temp_3);
                        temp_14 = (f32 *)((s32)temp_24 + temp_3);
                        var_8 = (f32 *)((s32)temp_11 + temp_4);
                        temp_12 = (f32 *)((s32)temp_14 + temp_3);
                        temp_10 = (f32 *)((s32)temp_12 + temp_3);
                        *(f32 *)((s32)temp_20 + 0) =
                            *(f32 *)((s32)temp_7 + 0);
                        var_7 = (f32 *)((s32)temp_10 + temp_3);
                        *(f32 *)((s32)temp_20 + 4) =
                            *(f32 *)((s32)temp_7 + 4);
                        *(f32 *)((s32)temp_19 + 0) =
                            *(f32 *)((s32)temp_18 + 0);
                        *(f32 *)((s32)temp_19 + 4) =
                            *(f32 *)((s32)temp_18 + 4);
                        *(f32 *)((s32)temp_17 + 0) =
                            *(f32 *)((s32)temp_16 + 0);
                        *(f32 *)((s32)temp_17 + 4) =
                            *(f32 *)((s32)temp_16 + 4);
                        *(f32 *)((s32)temp_25 + 0) =
                            *(f32 *)((s32)temp_24 + 0);
                        *(f32 *)((s32)temp_25 + 4) =
                            *(f32 *)((s32)temp_24 + 4);
                        *(f32 *)((s32)temp_15 + 0) =
                            *(f32 *)((s32)temp_14 + 0);
                        *(f32 *)((s32)temp_15 + 4) =
                            *(f32 *)((s32)temp_14 + 4);
                        *(f32 *)((s32)temp_13 + 0) =
                            *(f32 *)((s32)temp_12 + 0);
                        *(f32 *)((s32)temp_13 + 4) =
                            *(f32 *)((s32)temp_12 + 4);
                        *(f32 *)((s32)temp_11 + 0) =
                            *(f32 *)((s32)temp_10 + 0);
                        *(f32 *)((s32)temp_11 + 4) =
                            *(f32 *)((s32)temp_10 + 4);
                    } while (var_6 < (arg1 - 8));
                }
            }
            if (var_6 < arg1) {
                do {
                    var_6 += 1;
                    temp_f0 = *(f32 *)((s32)var_7 + 4);
                    *(f32 *)((s32)var_8 + 0) =
                        *(f32 *)((s32)var_7 + 0);
                    var_7 = (f32 *)((s32)var_7 + temp_3);
                    *(f32 *)((s32)var_8 + 4) = temp_f0;
                    var_8 = (f32 *)((s32)var_8 + temp_4);
                } while (var_6 < arg1);
            }
        }
    } else {
        func_003a4d50((u8 *)var_8, (u8 *)var_7, arg1 * temp_4);
    }
}

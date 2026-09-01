// object 364/window 320/normalized_diff 226
s32 func_003a8500(u8 *arg0)
{
    s32 *temp_2_2;
    s32 temp_19;
    s32 temp_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 var_16;
    s32 var_17;

    var_17 = 0;
    *(s32 *)(arg0 + 0xC) = func_003a7f80();
    temp_19 = *(s32 *)(arg0 + 0xC);
    if (temp_19 != 0) {
        var_16 = func_004115d0();
        if (var_16 != 0) {
            temp_2 = func_00412ca0(var_16);
            if (temp_2 != 0) {
                temp_2_2 = func_003cfa70();
                temp_2_3 = func_00412fb0(temp_2, 0, temp_2_2, 0);
                func_00412e90(temp_2_3, *temp_2_2, 0, 0);
                temp_2_4 = func_004125e0(temp_2_3);
                if (temp_2_4 != 0) {
                    temp_2_5 = func_00412e90(temp_2_4, *temp_2_2, 0, 0);
                    func_003cf9b0(
                        (u8 *)temp_2_5, 1, (void *)func_003a8180);
                    func_003cfa30(temp_2_5, temp_19);
                } else {
                    func_00411670(var_16);
                    goto block_9;
                }
            } else {
                func_00411670(var_16);
                goto block_9;
            }
        } else {
block_9:
            var_16 = 0;
        }
        *(s32 *)(arg0 + 0x10) = var_16;
        if (*(s32 *)(arg0 + 0x10) != 0) {
            var_17 = 1;
        }
    }
    return var_17;
}

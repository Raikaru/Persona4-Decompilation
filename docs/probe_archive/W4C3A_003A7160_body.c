// object 300/window 320/normalized_diff 64
s32 func_003a7160(u8 *arg0)
{
    u8 *temp_2;
    s32 var_17 = 0;
    u8 *var_16;
    u8 *temp_19;
    s32 *temp_2_2;

    temp_19 = (u8 *)func_003a6ba0();
    *(u8 **)(arg0 + 4) = temp_19;
    temp_19 = (u8 *)*(s32 *)(arg0 + 4);
    if (temp_19 == 0) {
        goto block_store;
    }
    var_16 = (u8 *)func_004115d0();
    if (var_16 == 0) {
        goto block_setzero;
    }
    temp_2 = (u8 *)func_00412ca0((s32)var_16);
    if (temp_2 == 0) {
        goto block_cleanup;
    }
    temp_2_2 = func_003cfa70();
    temp_2 = (u8 *)func_00412fb0((s32)temp_2, 0, temp_2_2, 0);
    func_00412e90((s32)temp_2, *temp_2_2, 0, 0);
    temp_2 = (u8 *)func_004125e0((s32)temp_2);
    if (temp_2 == 0) {
        goto block_cleanup;
    }
    temp_2 = (u8 *)func_00412e90((s32)temp_2, *temp_2_2, 0, 0);
    func_003cf9b0((u8 *)temp_2, 1, (void *)func_003a6df0);
    func_003cfa30(temp_2, temp_19);
    goto block_store;
block_cleanup:
    func_00411670((s32)var_16);
block_setzero:
    var_16 = 0;
block_store:
    *(s32 *)(arg0 + 8) = (s32)var_16;
    if (*(s32 *)(arg0 + 8) != 0) {
        var_17 = 1;
    }
    return var_17;
}

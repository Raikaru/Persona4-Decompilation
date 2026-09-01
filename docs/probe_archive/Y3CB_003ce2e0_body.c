/* object 196B, window 192B, normalized_diff 36; differing offsets 0x1C-0x34, 0x3C-0x40, 0x48-0x58, 0x60-0x80, 0x88-0xC0; casts written: none; levers ruled out: explicit false-branch/null-check shape (oversized-object archive condition). */
s32 func_003ce2e0(u8 *arg0) {
    extern u32 **func_003ce050(u32 **arg0, u32 arg1, u8 *arg2);
    extern void func_003e1ea0(u8 *arg0);
    extern s32 iGpffffb730;
    u32 **var_2;
    u32 *temp_3;
    u32 *var_17;
    u32 temp_16;
    u32 var_18;
    u8 *temp_4;
    u8 *var_6;

    var_2 = (u32 **)(arg0 + iGpffffb730);
    temp_3 = *var_2;
    if ((temp_3 == NULL) ||
        (*(u16 *)(*(u8 **)(arg0 + 0x54) + 4) != *temp_3)) {
        var_6 = NULL;
    } else {
        var_6 = (u8 *)1;
    }
    if (var_6 != NULL) {
    } else {
        var_2 = func_003ce050(var_2, *(u16 *)(*(u8 **)(arg0 + 0x54) + 4), var_6);
    }
    var_17 = *var_2;
    temp_16 = *var_17;
    var_18 = 0;
    if (temp_16 != 0) {
        do {
            temp_4 = *(u8 **)(var_17 + 1);
            if (temp_4 != NULL)
                func_003e1ea0(temp_4);
            var_18 += 1;
            var_17 += 1;
        } while (var_18 < temp_16);
    }
    return 1;
}

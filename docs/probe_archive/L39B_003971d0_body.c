/* Rejected reconstruction archive: object 428B / window 448B / normalized_diff 257. */
u32 *func_003971d0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 sp70[32];
    s32 *var_6;
    s32 temp_16;
    s32 temp_3;
    s32 var_17;
    s32 var_5_2;
    s32 var_7;
    s32 var_4_2;
    s32 allocator_arg;
    s32 var_5;
    u32 *temp_2;
    u8 *var_4;

    var_17 = 1;
    temp_16 = arg1 * 0x10;
    var_4 = (u8 *)(*(s32 *)(arg0 + 0x10) + temp_16);
    var_5 = 0;
    if ((*(u32 *)(var_4 + 8) & 1) == 0) {
        var_5 = 1;
        var_4 += 0x10;
    }
    if (var_5 != 0) {
        do {
            temp_3 = *(s32 *)(var_4 + 8);
            if ((temp_3 & 2) != 0) {
                var_5 += 1;
            }
            if ((temp_3 & 1) != 0) {
                var_5 -= 1;
            }
            var_17 += 1;
            var_4 += 0x10;
        } while (var_5 != 0);
    }
    allocator_arg = iGpffffb5dc;
    temp_2 = (u32 *)D_008873F8[0](allocator_arg, 0x3011E);
    temp_2[0] = arg2 | 1;
    temp_2[1] = var_17;
    temp_2[8] = (u32)func_003d5f50(*(u8 **)(arg0 + 0x20), arg1, var_17, arg3);
    if (arg1 != 0) {
        var_6 = &sp70[0];
        var_5_2 = -1;
        var_7 = 0;
        if (arg1 > 0) {
            var_4_2 = 0;
            do {
                if ((*(u32 *)(*(s32 *)(arg0 + 0x10) + var_4_2 + 8) & 2) != 0) {
                    *var_6 = var_5_2;
                    var_6 += 1;
                }
                if ((*(u32 *)(*(s32 *)(arg0 + 0x10) + var_4_2 + 8) & 1) != 0) {
                    var_6 -= 1;
                    var_5_2 = *var_6;
                } else {
                    var_5_2 = var_7;
                }
                var_7 += 1;
                var_4_2 += 0x10;
            } while (var_7 < arg1);
        }
        temp_2[7] = var_5_2;
    } else {
        temp_2[7] = -1;
    }
    temp_2[5] = *(u32 *)(*(s32 *)(arg0 + 0x10) + temp_16 + 0xC);
    temp_2[2] = *(u32 *)(arg0 + 8) + arg1 * 0x40;
    temp_2[3] = 0;
    temp_2[4] = *(u32 *)(arg0 + 0x10) + temp_16;
    temp_2[6] = (u32)arg0;
    return temp_2;
}

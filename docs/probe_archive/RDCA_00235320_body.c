// FUN_00235320 NONMATCHING
s64 func_00235320(u8 *arg0)
{
    s32 temp_18;
    s32 temp_3;
    s32 temp_4;
    s64 var_17;
    s64 var_2;
    s64 var_2_2;
    u64 var_20;
    var_17 = 3;
    if (*(u16 *)arg0 & 4) {
        if (*(u16 *)(arg0 + 2) >= 0x150)
            func_0046d730(D_00635938, 0x6D8);
        if (*(u16 *)(iGpffffb3c4 + *(u16 *)(arg0 + 2) * 0x3C) & 0x1000)
            var_17 = (s64)(s32)(3 * 2);
    }
    var_20 = 0;
loop_20:
    if (var_20 >= 0x10U)
        return -1;
    temp_18 = (s32)(var_20 & 0xFF);
    if (temp_18 >= 0x18)
        func_0046d730(D_00635938, 0x4C1);
    if (temp_18 < 0x10)
        var_2 = (s64)(s32)func_002332a0(arg0, (s32)(var_20 & 0xFF));
    else
        var_2 = (s64)(s32)(((*(s32 *)(arg0 + 0x14) & (1 << temp_18)) != 0));
    if (temp_18 >= 0x18)
        func_0046d730(D_00635938, 0x42A);
    temp_4 = (s32)(var_20 & 0xFF);
    temp_3 = (temp_4 >> 1) & 0xFFFF;
    if (temp_4 & 1)
        var_2_2 = (s64)(s32)((s32)*(u8 *)(arg0 + temp_3 + 0x24) >> 4);
    else
        var_2_2 = (s64)(s32)(*(u8 *)(arg0 + temp_3 + 0x24) & 0xF);
    if ((var_2 != 0) && (var_2_2 >= var_17))
        return (s64)(s32)var_20;
    var_20 += 1;
    goto loop_20;
}

/* Best probe for func_00235320; not byte-exact (20 differing words, 512-byte retail window). */
/* Retail saved registers: s0=arg0, s1=current flag/value, s2=loop index, s3=threshold, s4=loop counter. */
/* Tried: plain C reconstruction; opt_propagation off; opt_common_subs off; strict u16/u8 parity temporaries (u8 temp_4, u16 temp_3); s64 temporary for the branch-only boolean extension. Also tried value reuse, alternate local scopes/declaration orders, common-subexpression mode, explicit gotos, and prototype/address-expression variants. */
s64 func_00235320(u8 *arg0)
{
    u8 temp_4;
    u16 temp_3;
    s8 value;
    s32 var_17;
    s32 temp_18;
    s32 var_19;
    s32 var_20;

    var_17 = 3;
    if (*(u16 *)arg0 & 4) {
        if (*(u16 *)(arg0 + 2) >= 0x150) {
            func_0046d730(D_00635938, 0x6D8);
        }
        if (*(u16 *)((u8 *)iGpffffb3c4 + *(u16 *)(arg0 + 2) * 0x3C) & 0x1000) {
            var_17 = (s8)var_17;
            var_17 *= 2;
            var_17 = (s8)var_17;
        }
    }
    var_20 = 0;
    temp_18 = (s8)var_17;
    goto loop_check;
loop_body:
    var_19 = var_20 & 0xFF;
    if (var_19 >= 0x18) {
        func_0046d730(D_00635938, 0x4C1);
    }
    if (var_19 < 0x10) {
        value = func_002332a0(arg0, var_20 & 0xFF);
    }
    else {
        {
            s64 temp_bool;
            temp_bool = (*(s32 *)(arg0 + 0x14) & (1 << var_19)) != 0;
            value = (s8)temp_bool;
        }
    }
    var_17 = (s8)value;
    if (var_19 >= 0x18) {
        func_0046d730(D_00635938, 0x42A);
    }
    temp_4 = var_20 & 0xFF;
    temp_3 = temp_4 >> 1;
    if (temp_4 & 1) {
        value = (s8)(*(u8 *)(arg0 + temp_3 + 0x24) >> 4);
    }
    else {
        value = (s8)(*(u8 *)(arg0 + temp_3 + 0x24) & 0xF);
    }
    if (var_17 == 0) {
        goto loop_advance;
    }
    if ((s8)value < (s8)temp_18) {
        goto loop_advance;
    }
    return (s64)(s8)var_20;
loop_advance:
    var_20 += 1;
loop_check:
    if ((u32)var_20 < 0x10U) {
        goto loop_body;
    }
    return -1;
}

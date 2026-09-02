/* CLOSED body for func_0019fc70.
   Retail frame 0x50: $s3=arg0, $s2=temp_18 (arg0+0x6e),
   $s1=temp_17 (unit record +2), $s0=temp_16 (temp_18 & 0xffff).
   Exact match: write case 0/default before case 1; MWCC tests the last-written
   case first, so the dispatch emits case 1 before case 0/default. */
/* measured: opt_propagation off with named table pointers preserves retail load order. */
#pragma push
#pragma opt_propagation off
s32 func_0019fc70(u8 *arg0)
{
    u16 temp_18;
    u16 temp_17;
    s32 temp_16;
    u16 result;
    u8 *temp_4;

    temp_18 = *(u16 *)(arg0 + 0x6E);
    result = (u16)func_001d7f10(arg0, NULL, temp_18, 0);
    temp_4 = *(u8 **)(arg0 + 0x30);
    temp_17 = *(u16 *)(*(u8 **)(temp_4 + 0xA64) + 2);
    if (result != 0)
        goto result_zero_0019fc70;

    temp_16 = temp_18 & 0xFFFF;
    if ((iGpffffb3b8[temp_16 * 0x28] & 2) != 0) {
        switch (*(u8 *)(temp_4 + 0xA2)) {
        case 1:
            goto type_one_0019fc70;
        default:
            goto result_one_0019fc70;
        }
 type_one_0019fc70:
        if (func_001f0a50(arg0) != 0) {
            {
                u8 *table18;
                table18 = iGpffffb3cc;
                if ((*(s16 *)(p4_unit_00195530(
                    (u16)temp_17 * 0xE8, table18) + 0x18) &
                     0x100) != 0) {
                    return 1;
                }
            }
        }
        {
            u8 *table22;
            table22 = iGpffffb3cc;
            if (*(s16 *)(p4_unit_00195530(
                (u16)temp_17 * 0xE8, table22) + 0x22) == 1)
                return 0;
        }
 result_one_0019fc70:
        return 1;
    }
    if (func_001f11e0((s64)(s16)temp_18) != 0) {
        {
            u8 *flags_table;
            flags_table = iGpffffb3bc;
            if ((*(u16 *)(p4_unit_00195530(
                temp_16 * 4, flags_table) + 2) & 1) == 0)
                return 0;
        }
        /* Deliberately write case 0 before case 1: MWCC tests the last-written case first. */
        switch (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2)) {
        case 0:
        default:
            goto second_default_0019fc70;
        case 1:
            goto second_type_one_0019fc70;
        }
second_type_one_0019fc70:
        {
            u8 *table26;
            table26 = iGpffffb3cc;
            if (*(s16 *)(p4_unit_00195530(
                (u16)temp_17 * 0xE8, table26) + 0x26) == 1)
                return 0;
        }
second_default_0019fc70:
        return 1;
    }
 result_zero_0019fc70:
    return 0;
}
#pragma pop

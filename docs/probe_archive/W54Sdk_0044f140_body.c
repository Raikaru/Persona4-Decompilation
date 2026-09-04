/* object 604B, retail window 608B, normalized_diff 60 after recovering the
 * same-TU static func_0044e9e0 call shape. The prior cross-TU fake-return
 * version measured nd87. Residual is a saved-register rotation across both
 * allocate/relocate branches. Probed declaration orders, cached versus inline
 * arg0-4, and propagation control; static helper visibility improves but does
 * not close the allocation floor. */
#pragma push
#pragma opt_propagation off
s32 func_0044f140(void *arg0, u32 arg1)
{
    u32 var_18;
    s32 temp_2;
    s32 temp_16;
    s32 temp_17;
    s32 temp_2_2;
    s32 temp_16_2;
    s32 temp_17_2;
    s32 temp_21;
    s32 temp_23;
    s32 **temp_3;
    s32 work;
    s32 result;
    s32 *temp_18;

    temp_21 = func_0042ba20();
    if (arg0 == NULL) {
        temp_17 = func_0042ba20();
        if (arg1 == 0) {
            func_0046d730(D_007104E0, 0x653);
        }
        temp_16 = (arg1 + 0x37) & ~0xF;
        temp_2 = func_0043ece8(temp_16);
        if (temp_2 == 0) {
            func_0046d700(D_007104E0, 0x65F, D_007104F0,
                          D_00763D1C->bytes, arg1);
        }
        work = func_0044eaa0(temp_2, temp_16, 0x10, 0);
        if (temp_17 != 0) {
            func_0042ba70();
        }
        result = work;
    } else {
        temp_3 = (s32 **)((u8 *)arg0 - 4);
        var_18 = **temp_3;
        if (arg1 < var_18) {
            var_18 = arg1;
        }
        temp_23 = func_0042ba20();
        if (arg1 == 0) {
            func_0046d730(D_007104E0, 0x653);
        }
        temp_16_2 = (arg1 + 0x37) & ~0xF;
        temp_2_2 = func_0043ece8(temp_16_2);
        if (temp_2_2 == 0) {
            func_0046d700(D_007104E0, 0x65F, D_007104F0,
                          D_00763D1C->bytes, arg1);
        }
        work = func_0044eaa0(temp_2_2, temp_16_2, 0x10, 0);
        if (temp_23 != 0) {
            func_0042ba70();
        }
        func_0043f810((void *)work, arg0, var_18);
        temp_17_2 = func_0042ba20();
        if (arg0 == NULL) {
            func_0046d730(D_007104E0, 0x670);
        }
        temp_18 = *temp_3;
        func_0044e9e0((u8 *)(u64)temp_18);
        func_0043ed08((void *)(u64)temp_18);
        if (temp_17_2 != 0) {
            func_0042ba70();
        }
        result = work;
    }
    if (temp_21 != 0) {
        func_0042ba70();
    }
    return result;
}
#pragma pop

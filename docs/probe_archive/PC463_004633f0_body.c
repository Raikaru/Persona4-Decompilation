/* FAMILY OR-destination colouring floor with func_0014bbe0 (see build/FKMS_0014bbe0_body.c): object_size=296; window=304; normalized_diff=4; differing offsets=112,116,172,176. Exact residual: candidate +112/+172 `or $v0,$v1,$v0`, +116/+176 `mtc1 $v0,$f0`; retail uses `or $v1,$v1,$v0` and `mtc1 $v1,$f0`. Both functions have the same repeated two-pair REGISTER CLASS/LIFETIME residual. Four hypothesis lanes failed in both: hidden return (both already return s32; nd 4), early live return local (nd 4), first-operand destination (`temp_6 |= temp_5`; nd 4), and extending an existing local lifetime/post-mtc1 read (nd 4). Earlier exhausted probes include func_003e82e0 declarations, local declaration/type/order changes, compound/transposed/raw ORs, block/condition/goto forms, optimization_level 1, opt_propagation, inline/typed/direct helpers, result/conversion locals, and doubled-arithmetic spellings; all retained nd 4 or grew the object. Retail 0014bbe0 has distinct negative-arm blocks, not a shared OR/mtc1 block. No further source change justified. */
s32 func_004633f0(void) {
    f32 var_f0_2;
    f32 var_f0;
    s32 temp_2;
    s32 temp_4;
    s32 temp_6;
    s32 temp_5;

    func_0044f720();
    iGpffffba8c = func_003e23e0();
    func_003e82e0(func_00457120(), 0, 0);
    temp_4 = *(s32 *)0x10000000;
    iGpffffb198 = temp_4;
    temp_2 = temp_4 - iGpffffb194;
    if (temp_2 >= 0) {
        var_f0 = (f32)temp_2;
    } else {
        temp_6 = (s32)((u32)temp_2 >> 1);
        temp_5 = temp_2 & 1;
        temp_6 = temp_6 | temp_5;
        var_f0 = (f32)temp_6 + (f32)temp_6;
    }
    iGpffffbb20 = var_f0;
    if (temp_4 >= 0) {
        var_f0_2 = (f32)temp_4;
    } else {
        temp_6 = (s32)((u32)temp_4 >> 1);
        temp_5 = temp_4 & 1;
        temp_6 = temp_6 | temp_5;
        var_f0_2 = (f32)temp_6 + (f32)temp_6;
    }
    iGpffffbb1c = var_f0_2;
    iGpffffbb24 = 100.0f * ((*(f32 *)&iGpffffbb20) / 520.0f);
    *(s32 *)0x10000000 = 0;
    func_003e5510(0);
    func_00466600();
    func_00466c60();
    func_0050cd80();
    return 0;
}

/*
 * Probe archive for func_002494c0 (432B window).
 * Measured with LaneCmmMisc_scope.json before restoration: object 424B,
 * window 432B, normalized_diff 267. First differing offsets recorded by
 * the scoped report: 25, 26, 29, 30, 44-48, 50, 52-55, 60-61 (additional
 * differences follow in the report). This body is archived as reference only
 * and is not left live because it is not a MATCH.
 *
 * Both Hex-Rays and Ghidra agree on the data/control-flow layout: seed/date
 * call, A61-gated table lookup with a shared NULL path, argument assertion,
 * and two capped halfword updates. The candidate below preserves that layout.
 *
 * Ruled out by scoped probes: u64/wide arg0, u64 arg1, integer versus pointer
 * base declaration, declaration-order permutations, argument-copy locals,
 * explicit second-index temporaries, opt_propagation off, opt_common_subs off
 * with this body, nested versus merged A61/limit conditions, and the tested
 * operand/comparison spellings. The remaining residual was saved-register
 * coloring plus branch/shared-NULL scheduling and field-load placement.
 */
s32 func_002494c0(u32 arg0, s32 arg1)
{
    s32 sp5C;
    s32 sp58;
    s32 temp_arg0;
    s32 temp_arg1;
    u8 *temp_17;
    u8 *var_18;
    s32 temp_17_2;
    s32 temp_17_3;
    u16 temp_2_2;
    u16 temp_2_4;
    u16 *temp_2;
    u16 *temp_2_3;
    s32 var_2;
    s32 var_2_2;
    temp_arg0 = arg0;
    temp_arg1 = arg1;

    temp_17 = D_008814D0[0] + 8;
    func_001104d0(temp_arg0, &sp5C, &sp58);
    if ((func_00106330(0xA61) == 0) ||
        (var_18 = (u8 *)(temp_17 + (func_001064f0(0x6D) * 0x24)),
         (func_00110600(*(u8 *)(var_18 + 2),
                       *(u8 *)(var_18 + 3)) > temp_arg0))) {
        var_18 = NULL;
    }
    if ((temp_arg1 != 0) && (temp_arg1 != 1)) {
        func_0046d730(D_006359D0, 0x4AB);
    }
    if (var_18 == NULL) {
        func_0046d730(D_006359D0, 0x4AC);
    }
    temp_17_2 = temp_arg1 * 0x10;
    temp_2 = (u16 *)(temp_17_2 + (u32)var_18 + 4);
    temp_2_2 = *temp_2;
    if (temp_2_2 != 0) {
        var_2 = (func_00106600((s16)temp_2_2) & 0xFF) +
                *(s16 *)(temp_17_2 + (u32)var_18 + 6);
        if (var_2 >= 0x64) {
            var_2 = 0x63;
        }
        func_00106620((s16)*temp_2, var_2 & 0xFF);
    }
    temp_2_3 = (u16 *)(temp_17_2 + (u32)var_18 + 8);
    temp_2_4 = *temp_2_3;
    if (temp_2_4 != 0) {
        temp_17_3 = temp_arg1 * 0x10;
        var_2_2 = (func_00106600((s16)temp_2_4) & 0xFF) +
                  *(s16 *)(temp_17_3 + (u32)var_18 + 0xA);
        if (var_2_2 >= 0x64) {
            var_2_2 = 0x63;
        }
        func_00106620((s16)*temp_2_3, var_2_2 & 0xFF);
    }
    return 1;
}

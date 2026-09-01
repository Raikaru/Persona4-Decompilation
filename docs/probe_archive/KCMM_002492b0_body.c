/* object_size=156 window=192 normalized_diff=25 differing_word_offsets=60,116,124,128,132,136,140,144,148; ruled out merged-NULL condition, explicit boolean/result locals, switch wrapping, direct returns, shared-tail gotos, and opt_rebuildconditionals off. Residual is retail's out-of-line NULL block plus longer 0/1 return tail and branch polarity; no compliant exact C body found. */
// FUN_002492B0 NONMATCHING
s32 func_002492b0(u32 arg0) {
    s32 sp3C;
    s32 sp38;
    s32 cond;
    s32 hit;
    s32 result;
    u8 *temp_17;
    u8 *var_17;

    temp_17 = D_008814D0[0] + 8;
    func_001104d0(arg0, &sp3C, &sp38);
    if (func_00106330(0xA61) == 0) {
        goto null_p;
    }
    var_17 = temp_17 + func_001064f0(0x6D) * 0x24;
    cond = arg0 < func_00110600(var_17[2], var_17[3]);
    if (cond != 0) {
        goto null_p;
    }
    goto done_p;
null_p:
    var_17 = NULL;
done_p:
    hit = (var_17 != NULL);
    if (hit != 0) {
        result = 1;
        goto done_result;
    }
    result = 0;
done_result:
    return result;
}

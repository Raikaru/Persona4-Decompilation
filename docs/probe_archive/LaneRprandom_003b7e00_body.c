/* Best plain-C candidate for func_003b7e00; object 584/592, fndiff residual 2 tail-padding words, lverify MATCH. */
/* Retail saved GPRs: s21=arg0, s20=arg2, s19=temp_19, s18=temp_16, s17=var_17, s16=temp_18, s22=temp_20. */
u8 *func_003b7e00(u8 *arg0, s32 arg1, u8 *arg2)
{
    u8 sp18c[4];
    u32 sp188;
    u8 temp_80[264];
    u32 value;
    u32 temp_19;
    s32 temp_16;
    u32 temp_18;
    u32 temp_20;
    u8 *var_17;

    if ((*(u32 *)(arg2 + 8) & 0x01000000) == 0) {
        goto parse_body;
    }
    if (func_003b8ad0(arg0, arg2) == 0) {
        goto fast_fail;
    }
    goto fast_success;
fast_fail:
    return NULL;
fast_success:
    return arg0;
parse_body:
    if (func_003df360(arg0, sp18c, 4) == 0) {
        goto fail_read;
    }
    temp_16 = *(s32 *)(arg2 + 0x14);
    value = *(u32 *)sp18c;
    temp_19 = (value >> 8) & 0xFF;
    temp_20 = value & 0xFF;
    temp_18 = (value >> 16) & 0xFF;
    sp188 = temp_19;
    var_17 = D_008873F8[0](D_008864A8[0], 0x30116);
    func_0043f9c8(var_17, 0, 0x48);
    if (temp_18 == 0) {
        goto fill_count;
    }
check_count:
    if (sp188 == 0) {
        func_003b7590(var_17, NULL, NULL, temp_80, &sp188, temp_16);
    }
    if (func_003b7680(var_17, temp_20, sp188, temp_16,
                      temp_80, NULL, NULL, 0) == 0) {
        goto release_buffer;
    }
compare_start:
    if (var_17 == NULL) {
        goto fail_null;
    }
    if (temp_19 == func_003e2910(arg0, *(void **)(var_17 + 8), temp_19)) {
        goto read_blocks;
    }
    goto fail_compare;
fail_compare:
    return NULL;
fail_read:
    return NULL;
fill_count:
    func_003b7510(var_17, 0, temp_16);
    goto check_count;
release_buffer:
    jtbl_008873FC[0](D_008864A8[0], var_17);
    var_17 = NULL;
    goto compare_start;
fail_null:
    return NULL;
read_blocks:
    if (func_003df360(arg0, *(void **)(var_17 + 0x14), temp_16 * 4) == 0) {
        goto fail_blocks1;
    }
    if (func_003df300(arg0, *(void **)(var_17 + 0x18), temp_16 * 0x10) == 0) {
        goto fail_blocks2;
    }
    *(u32 *)(var_17 + 0x10) = temp_18;
    if (func_003df300(arg0, *(void **)(var_17 + 0x0C),
                      *(u32 *)var_17 << 6) == 0) {
        goto fail_blocks3;
    }
    if (func_003b7290(arg0, var_17) == NULL) {
        goto fail_b7290;
    }
    func_003b8410(arg2, var_17);
    goto fast_success;
fail_blocks1:
    return NULL;
fail_blocks2:
    return NULL;
fail_blocks3:
    return NULL;
fail_b7290:
    return NULL;
}

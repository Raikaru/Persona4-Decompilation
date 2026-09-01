/* Closest plain-C candidate for func_003b7e00; retained after scoped lverify mismatch (object 564/592, nd 316). */
u8 *func_003b7e00(u8 *arg0, s32 arg1, u8 *arg2)
{
    u8 sp18c[4];
    u32 sp188;
    u8 temp_80[264];
    u32 temp_19;
    s32 temp_16;
    u32 temp_18;
    u32 temp_20;
    u8 *var_17;
    u8 *result;

    if ((*(u32 *)(arg2 + 8) & 0x01000000) != 0) {
        if (func_003b8ad0(arg0, arg2) == 0) {
            result = NULL;
            goto block_26;
        }
    } else {
        if (func_003df360(arg0, sp18c, 4) == 0) {
            result = NULL;
            goto block_26;
        }
        temp_16 = *(s32 *)(arg2 + 0x14);
        temp_19 = (*(u32 *)sp18c >> 8) & 0xFF;
        temp_18 = (*(u32 *)sp18c >> 16) & 0xFF;
        temp_20 = *(u32 *)sp18c & 0xFF;
        sp188 = temp_19;
        var_17 = D_008873F8[0](D_008864A8[0], 0x30116);
        func_0043f9c8(var_17, 0, 0x48);
        if (temp_18 == 0) {
            func_003b7510(var_17, 0, temp_16);
        }
        if (sp188 == 0) {
            func_003b7590(var_17, NULL, NULL, temp_80, &sp188, temp_16);
        }
        if (func_003b7680(var_17, temp_20, sp188, temp_16,
                          temp_80, NULL, NULL, 0) == 0) {
            jtbl_008873FC[0](D_008864A8[0], var_17);
            var_17 = NULL;
        }
        if (var_17 == NULL) {
            result = NULL;
            goto block_26;
        }
        if (temp_19 != func_003e2910(arg0, *(void **)(var_17 + 8), temp_19)) {
            result = NULL;
            goto block_26;
        }
        if (func_003df360(arg0, *(void **)(var_17 + 0x14), temp_16 * 4) == 0) {
            result = NULL;
            goto block_26;
        }
        if (func_003df300(arg0, *(void **)(var_17 + 0x18), temp_16 * 0x10) == 0) {
            result = NULL;
            goto block_26;
        }
        *(u32 *)(var_17 + 0x10) = temp_18;
        if (func_003df300(arg0, *(void **)(var_17 + 0x0C),
                          *(u32 *)var_17 << 6) == 0) {
            result = NULL;
            goto block_26;
        }
        if (func_003b7290(arg0, var_17) == NULL) {
            result = NULL;
            goto block_26;
        }
        func_003b8410(arg2, var_17);
    }
    result = arg0;
block_26:
    return result;
}

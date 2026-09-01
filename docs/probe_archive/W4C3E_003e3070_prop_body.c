#pragma opt_propagation off
s32 func_003e3070(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *var_3;

    var_3 = *(u8 **)(arg0 + 0x10);
    if (var_3 != NULL) {
loop_1:
        if (*(s32 *)(var_3 + 8) != arg1) {
            var_3 = *(u8 **)(var_3 + 0x30);
            if (var_3 == NULL) {
            } else {
                goto loop_1;
            }
        }
    }
    if (var_3 != NULL) {
        *(s32 *)(var_3 + 0x18) = arg2;
        return *(s32 *)(var_3 + 0);
    }
    return -1;
}
#pragma opt_propagation on

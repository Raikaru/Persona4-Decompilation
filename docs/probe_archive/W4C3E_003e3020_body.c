s32 func_003e3020(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
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
        *(s32 *)(var_3 + 0x0C) = arg2;
        *(s32 *)(var_3 + 0x10) = arg3;
        *(s32 *)(var_3 + 0x14) = arg4;
        return *(s32 *)(var_3 + 0);
    }
    return -1;
}

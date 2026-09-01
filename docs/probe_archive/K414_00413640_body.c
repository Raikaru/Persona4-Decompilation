/* object_size=196B window=192B normalized_diff=73; MWCC frameless candidate, object exceeded window. */
void func_00413640(u8 **arg0, u8 **arg1, u8 **arg2) {
    u8 *var_4;
    u8 *var_5;
    u8 *var_6;
    u8 *var_7;
    u8 *var_3;

    var_4 = (u8 *)(arg0);
    var_5 = (u8 *)(arg1);
    var_6 = (u8 *)(arg2);
    if (*(s32 *)(var_5 + 0xC) != 0) {
        do {
            var_5 = *(u8 **)(var_5 + 0xC);
        } while (*(s32 *)(var_5 + 0xC) != 0);
    }
    if (*(s32 *)(var_6 + 0xC) != 0) {
        do {
            var_6 = *(u8 **)(var_6 + 0xC);
        } while (*(s32 *)(var_6 + 0xC) != 0);
    }
    if ((s32)(var_5) != (s32)(var_6)) {
        var_7 = var_5;
        if (*(s32 *)(var_5 + 4) != 0) {
            do {
                var_7 = *(u8 **)(var_7 + 4);
            } while (*(s32 *)(var_7 + 4) != 0);
        }
        *(u8 **)(var_7 + 4) = (u8 *)(var_6);
        *(u8 **)(var_6 + 0xC) = (u8 *)(var_5);
        var_3 = *(u8 **)(var_4);
        if ((s32)(var_3) != (s32)(var_6)) {
            do {
                var_4 = (u8 *)(var_3 + 8);
                var_3 = *(u8 **)(var_3 + 8);
            } while ((s32)(var_3) != (s32)(var_6));
        }
        *(u8 **)(var_4) = *(u8 **)(var_3 + 8);
    }
}

/* measured: object=80 window=80 normalized_diff=42; reverted to INCLUDE_ASM. */
s32 func_004e1528(u8 *arg0, s32 *arg1) {
    s32 *entry;
    s32 result = -1;

    if (D_009231F4 != 0) {
        entry = (s32 *)func_004e1418(arg0);
        result = -3;
        if (entry != 0) {
            *arg1 = *(s32 *)((u8 *)entry + 0xC);
            result = 0;
        }
    }
    return result;
}

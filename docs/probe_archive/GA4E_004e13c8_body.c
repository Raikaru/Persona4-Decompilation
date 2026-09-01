/* measured: object=80 window=80 normalized_diff=11; reverted to INCLUDE_ASM. */
s8 *func_004e13c8(void) {
    s32 count = D_009231F8;
    s32 index = 0;
    s8 *entry = (s8 *)D_009231F4;

    if (count > 0) {
        do {
            if (*entry == 0) {
                return entry;
            }
            entry += 0x10;
            index += 1;
        } while (index < count);
    }
    return 0;
}

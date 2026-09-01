/* measured: object=76 window=80 normalized_diff=6; reverted to INCLUDE_ASM. */
s32 func_004e8008(u8 *arg0) {
    u8 *entry;

    if (arg0 == 0) {
        func_004e7458(&D_0075B6D0);
        return 0;
    }
    entry = arg0;
    if (*(s8 *)(entry + 2) != 1) {
        return 0;
    }
    return *(s32 *)(entry + 0x28) << 11;
}

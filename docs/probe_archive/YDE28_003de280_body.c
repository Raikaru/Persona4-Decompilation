u32 func_003de280(u8 *arg0, u32 arg1) {
    u32 count = *(u32 *)(arg0 + 4);
    if (arg1 >= count) {
        return 0;
    }
    u32 base = *(u32 *)(arg0 + 0x58);
    return base + ((arg1 * 7U) << 4);
}

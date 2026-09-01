/* func_003bcfb0 best plain-C attempt: object 76B/window 80B, normalized_diff 10. */
s32 func_003bcfb0(s32 arg0) {
    s32 count = 0;
    s32 index;
    s32 limit;
    u8 *entry;
    s32 *base;

    base = (s32 *)(arg0 + iGpffffb680);
    limit = base[0];
    if (limit > 0) {
        index = 0;
        entry = (u8 *)(uintptr_t)base[1];
        do {
            if (*(s32 *)(entry + 0xC) != 0) {
                count += 1;
            }
            index += 1;
            entry += 0x10;
        } while (index < limit);
    }
    return count;
}

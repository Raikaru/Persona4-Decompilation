/* Best plain-C attempt: object 72B/window 80B, normalized_diff 2 (build/W3C3B_cf10_nd2_restored.json). */
s32 func_003bcf10(s32 arg0) {
    s32 count;
    s32 index;
    s32 length;
    u8 *base;
    u8 *entry;

    count = 0;
    base = (u8 *)(arg0 + iGpffffb668);
    length = *(s32 *)(base + 0);
    index = count;
    if (index < length) {
        entry = *(u8 **)(base + 4);
        do {
            if (*(s32 *)(entry + 0xC) == 0) goto no_count;
            count += 1;
no_count:
            index += 1;
            entry += 0x10;
        } while (index < length);
    }
    return count;
}

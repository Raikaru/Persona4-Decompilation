/* Best plain-C attempt: object 152B/window 160B, normalized_diff 7 (build/W3C3B_bcbe0_positive_bool_local.json). */
s32 func_003bcbe0(s32 arg0, s32 arg1) {
    u8 *base;
    s32 count;
    s32 index;
    s32 offset;
    s32 positive;

    base = (u8 *)(arg0 + arg1);
    if (*(s32 *)(base + 4) != 0) {
        count = *(s32 *)(base + 0);
        positive = 0 < count;
        if (positive == 0) goto callback;
        index = 0;
        offset = 0;
        do {
            func_003bbea0(*(s32 *)(base + 4) + offset);
            index += 1;
            count = *(s32 *)(base + 0);
            offset += 0x10;
        } while (index < count);
callback:
        jtbl_008873EC[0](*(u8 **)(base + 4));
    }
    *(s32 *)(base + 4) = 0;
    *(s32 *)(base + 0) = 0;
    return arg0;
}

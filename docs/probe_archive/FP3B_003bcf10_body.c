/* func_003bcf10 best current plain-C attempt: object 76B, window 80B, normalized_diff 50. */
s32 func_003bcf10(s32 arg0) {
    s32 count;
    s32 index;
    s32 length;
    u8 *base;
    u8 *entry;

    count = 0;
    base = (u8 *)(arg0 + iGpffffb668);
    length = *(s32 *)(base + 0);
    if (length <= 0) goto done;
    index = 0;
    entry = *(u8 **)(base + 4);
loop:
    if (*(s32 *)(entry + 0xC) != 0) count += 1;
    index += 1;
    if (index < length) {
        entry += 0x10;
        goto loop;
    }
done:
    return count;
}

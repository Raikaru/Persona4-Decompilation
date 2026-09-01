/* func_003c4bc0 near-match archive: object 60 bytes, window 64 bytes, normalized_diff 8. */
/* residual words: +0x04/+0x1C/+0x34/+0x38; branch targets and epilogue jr placement. */
s32 func_003c4bc0(u8 *arg0, s32 arg1) {
    s32 count;
    s32 index;
    s32 *p;

    count = *(s32 *)(arg0 + 4);
    index = count - 1;
    if (count > 0) {
        p = *(s32 **)(arg0 + 0) + index;
        do {
            if (*p == arg1) {
                goto done;
            }
            p -= 1;
        } while (index-- > 0);
    }
done:
    ;
    return index;
}

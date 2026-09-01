/* func_003c47c0 near-match archive: object 92 bytes, window 96 bytes, normalized_diff 8. */
/* residual words: +0x0C/+0x10; retail interleaves move $s1,$a0 between sq stores. */
s32 func_003c47c0(u8 *arg0) {
    s32 total;

    total = 0x28;
    if (*(u8 **)arg0 != NULL) {
        total += func_003e6240(*(u8 **)arg0) + 0xC;
    }
    return total + (func_003e3370(D_0070AFF0, arg0) + 0xC);
}

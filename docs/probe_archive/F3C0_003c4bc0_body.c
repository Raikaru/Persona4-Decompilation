/* func_003c4bc0 archive: object 60B, window 64B, normalized_diff 8; differing offsets 4,28,52,54,55,56,58,59; current body remains a branch-target/epilogue layout residual. Schedule + no_branch_likely together are required for 60B; schedule off measured 68B/64B, nd 46. Explicit out-of-line guard/goto labels and a separated epilogue label were additionally ruled out. */
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

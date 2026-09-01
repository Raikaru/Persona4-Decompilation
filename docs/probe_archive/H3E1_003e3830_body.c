/* object_size=60B window=64B normalized_diff=18 differing_offsets=16,24,26,27,28,30,31,32,34,35,36,37,38,39,40,41; ruled out branch-join/goto, schedule, no_branch_likely, and optimization_level 1 probes. */
s32 func_003e3830(u8 *arg0, s32 arg1) {
    u8 *node;
    node = *(u8 **)(arg0 + 0x10);
    if (node != NULL) {
    loop:
        if (*(s32 *)(node + 8) == arg1) {
            return *(s32 *)(node + 0);
        }
        node = *(u8 **)(node + 0x30);
        if (node == NULL) {
            goto done;
        }
        goto loop;
    }
done:
    return -1;
}

/* object_size=60B window=64B normalized_diff=20 differing_offsets=4,6,16,24,26,27,28,30,31,32,34,35,36,37,38,39; ruled out plain-C while/goto branch-join layouts and schedule/no_branch_likely as the remaining delay-slot discrepancy. */
s32 func_003e3830(u8 *arg0, s32 arg1) {
    u8 *node;

    node = *(u8 **)(arg0 + 0x10);
    while (node != NULL) {
        if (*(s32 *)(node + 8) == arg1) {
            return *(s32 *)node;
        }
        node = *(u8 **)(node + 0x30);
    }
    return -1;
}

/* object_size=72B window=80B normalized_diff=9 differing_offsets=4,16,36,40,44,48,56; ruled out no_branch_likely, optimization_level 1, do/while, empty-else, and direct store-guard probes. */
s32 func_003e30c0(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *node;

    node = *(u8 **)(arg0 + 0x10);
    if (node != NULL) {
    loop:
        if (*(s32 *)(node + 8) == arg1) {
            goto found;
        }
        node = *(u8 **)(node + 0x30);
        if (node != NULL) {
            goto loop;
        } else {
            ;
        }
    }
found:
    if (node != NULL) {
        *(s32 *)(node + 0x1c) = arg2;
        return *(s32 *)(node + 0);
    }
    return -1;
}

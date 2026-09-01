/* object_size=72B window=80B normalized_diff=16 differing_offsets=4,16,36,38,39,40,42,43,44,46,47,48,50,51,58,59; ruled out explicit-found and switch/if/while/do-while loop shapes, empty-else variants, schedule and paired schedule+no_branch_likely probes, and direct field-load spellings. Retail keeps a loop-exit nop and puts node->0 in the unconditional branch delay slot; candidate's guard/body and return-load placement remain displaced. */
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

/* object_size=80B window=80B normalized_diff=20 differing_offsets=4,16,36,38,39,40,42,43,44,46,47,48,50,52,54,56; ruled out labeled-return/goto layout, paired schedule+no_branch_likely bracket, direct field-load spellings, and loop branch-shape probes. Retail retains an extra loop-exit nop and places node->0 in the unconditional branch delay slot; candidate stores/returns are displaced by four bytes. */
s32 func_003e3020(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *node;

    node = *(u8 **)(arg0 + 0x10);
    if (node != NULL) {
    loop:
        if (*(s32 *)(node + 8) != arg1) {
            node = *(u8 **)(node + 0x30);
            if (node == NULL) {
            } else {
                goto loop;
            }
        }
    }
    if (node != NULL) {
        *(s32 *)(node + 0x0c) = arg2;
        *(s32 *)(node + 0x10) = arg3;
        *(s32 *)(node + 0x14) = arg4;
        return *(s32 *)(node + 0);
    }
    return -1;
}

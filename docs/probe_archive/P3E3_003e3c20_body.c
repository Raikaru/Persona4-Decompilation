/* object_size=96B window=112B normalized_diff=22 differing_offsets=[28,68,69,70,71,72,73,74,75,76,78,79,80,82,84,86] classification=compiler branch-join/padding floor; schedule on + no_branch_likely on and plain-C declaration/type/loop/goto variants ruled out; retail has an extra nop after the loop bnez and therefore a 16-byte longer epilogue, while b210 emits the return move immediately. */
u8 *func_003e3c20(u8 *arg0, s32 arg1) {
    u8 *node = *(u8 **)(arg0 + 0x14);
    if (node) {
        do {
            ((void (*)(s32, s32, s32))(*(s32 *)(node + 0x24)))(
                arg1, *(s32 *)(node + 0), *(s32 *)(node + 4));
            node = *(u8 **)(node + 0x34);
        } while (node);
    }
    return arg0;
}

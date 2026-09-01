/* N3B best: object 76B/window 80B, normalized_diff 29. Same shape as the cf10 twin (retail bodies are identical except the gp symbol). Residual: retail slt $at,$zero,$a0;beqz $at guard with move a2,zero in the delay slot; b210 folds or recolours every literal spelling. */
s32 func_003bcfb0(s32 arg0) {
    u32 count;
    s32 index;
    s32 length;
    u8 *base;
    u8 *entry;

    count = 0;
    base = (u8 *)(arg0 + iGpffffb680);
    length = *(s32 *)(base + 0);
    index = 0;
    if (length > 0) {
        entry = *(u8 **)(base + 4);
        while (index < length) {
            if (*(s32 *)(entry + 0xC) != 0) {
                count += 1;
            }
            index += 1;
            entry += 0x10;
        }
    }
    return count;
}

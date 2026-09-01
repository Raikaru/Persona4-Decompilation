/* N3B best: object 76B/window 80B, normalized_diff 29. While-form with constant-right guard; plain do-while scores nd32; schedule-on folds the guard to bgezal $zero (68-84B). Residual: retail lowers the entry guard generically as slt $at,$zero,$a0;beqz $at with move a2,zero in the delay slot; b210 either folds to blez/bltz or colours a named register. */
s32 func_003bcf10(s32 arg0) {
    u32 count;
    s32 index;
    s32 length;
    u8 *base;
    u8 *entry;

    count = 0;
    base = (u8 *)(arg0 + iGpffffb668);
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

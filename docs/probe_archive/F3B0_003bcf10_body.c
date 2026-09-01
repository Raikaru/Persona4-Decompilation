/* object 76B/window 80B, normalized_diff 32; differing word offsets 0,4,16,20,24,52,56,60,64,68 (fndiff reloc-masked). Ruled out direct do/while, positive and zero-left guards, for/while forms, global-temp and base-first order, signed/u32 count, local declaration order, schedule, optimization-level 1, opt_propagation, and no_branch_likely probes; current TU recheck remained 76B/nd32. */
s32 func_003bcf10(s32 arg0) {
    s32 count;
    s32 index;
    s32 length;
    u8 *base;
    u8 *entry;

    count = 0;
    base = (u8 *)(arg0 + iGpffffb668);
    length = *(s32 *)(base + 0);
    index = count;
    if (index < length) {
        entry = *(u8 **)(base + 4);
        do {
            if (*(s32 *)(entry + 0xC) == 0) goto no_count;
            count += 1;
no_count:
            index += 1;
            entry += 0x10;
        } while (index < length);
    }
    return count;
}

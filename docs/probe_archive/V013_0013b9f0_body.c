/* measured: object 896B, retail window 768B, normalized_diff 207, differing offsets 0,8-32,40-96,104-176,184-224,232-288,296-392,400-432,440-888; archived immediately because object exceeded retail window; ruled out direct generated-loop reconstruction and corrected helper declarations */
s32 func_0013b9f0(u8 *arg0)
{
    extern u16 D_008C024E[];
    extern u16 D_008C0252[];
    extern u32 func_00106880(s16 arg0);
    extern s32 func_0012ff40(s32 arg0, s32 arg1, s16 arg2);
    s16 count;
    s16 total;
    s16 start;
    s16 index;
    s16 threshold;
    s16 low;
    s16 high;
    s32 selected;

    count = *(s16 *)(arg0 + 0xC3E);
    if (count < 2) return 0;
    total = *(s16 *)(arg0 + 0x22) + *(s16 *)(arg0 + 0x24);
    if (D_008C024E[0] & 4) {
        start = total;
        if (total == 0) start = count;
        selected = func_00106880(*(s16 *)(arg0 + (start - 1) * 4 + 0x3E));
        index = start - 1;
        while (index > 0 && selected == func_00106880(*(s16 *)(arg0 + index * 4 + 0x3A))) index--;
        goto process;
    }
    if (D_008C024E[0] & 8) {
        selected = func_00106880(*(s16 *)(arg0 + total * 4 + 0x3E));
        index = total + 1;
        while (index < count && selected == func_00106880(*(s16 *)(arg0 + index * 4 + 0x3E))) index++;
        if (index >= count) index = 0;
        goto process;
    }
    if (D_008C0252[0] & 4) {
        if (total == 0) index = total;
        else {
            selected = func_00106880(*(s16 *)(arg0 + (total - 1) * 4 + 0x3E));
            index = total - 1;
            while (index > 0 && selected == func_00106880(*(s16 *)(arg0 + index * 4 + 0x3A))) index--;
        }
        goto process;
    }
    if (D_008C0252[0] & 8) {
        selected = func_00106880(*(s16 *)(arg0 + total * 4 + 0x3E));
        index = total + 1;
        while (index < count && selected == func_00106880(*(s16 *)(arg0 + index * 4 + 0x3E))) index++;
        if (index >= count) index = total;
process:
        if (total == index) return 0;
        if (count < 7) { low = 0; high = index; }
        else {
            threshold = count - 6;
            if (index >= threshold) { low = threshold; high = index - low; }
            else { low = index; high = 0; }
        }
        func_0012ff40((s32)arg0, 0, high);
        func_0012ff40((s32)arg0, 1, low);
        return 1;
    }
    return 0;
}

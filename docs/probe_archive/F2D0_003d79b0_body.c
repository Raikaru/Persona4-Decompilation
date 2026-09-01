/* object_size=108 window=112 normalized_diff=8 differing_offsets=0x24-0x2b; classification: independent constant/index materialization order residual; retail uses sq, not sd. */
s32 func_003d79b0(s32 arg0)
{
    extern s32 iGpffffb74c;
    s32 value;
    u32 index;
    u8 *entry;

    if (func_003d8150() != 0) {
        value = 0xC;
        value += 4;
        index = 0;
        entry = (u8 *)(arg0 + iGpffffb74c);
        do {
            if (*(s32 *)(entry + 8) != 0) {
                value += 0x20;
            }
            index++;
            entry += 4;
        } while (index < 8);
        return value;
    }
    return 0;
}

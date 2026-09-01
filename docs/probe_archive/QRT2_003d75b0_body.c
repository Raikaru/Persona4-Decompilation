/* object 296B vs window 288B, normalized_diff 191, differing offsets first reported 0x04-0x08,0x0a-0x10,0x12,0x14-0x16; classification oversized candidate/different function; ruled out further reordering after automatic archive threshold. */
/* Candidate attempted typed byte-pointer translation with iGpffffb748, a signed 64-bit mask cast to reproduce dsll32/dsra32, and old-style helper declarations. */

s32 func_003d75b0(s32 arg0, s32 arg2)
{
    extern s32 func_003deff0();
    extern s32 func_003df240();
    extern s32 func_003d8060();
    extern s32 func_003e2ab0();
    s32 mask_slot;
    s32 stride;
    s64 mask;
    u32 count;
    u32 index;
    u8 **entry;
    u8 *base;
    u8 *cursor;

    mask = 0;
    index = 0;
    mask_slot = 0;
    base = (u8 *)(arg2 + iGpffffb748);
    stride = 4;
    cursor = base;
    do {
        if (*(s32 *)(cursor + 8) != 0) {
            stride += 0x20;
            mask = ((s64)(mask << 0x20) >> 0x20) | (1 << index);
            mask_slot = (s32)mask;
        }
        index += 1;
        cursor += 4;
    } while (index < 8U);
    if (func_003deff0(arg0, 1, stride, 0x37002, 0x37) != 0) {
        goto block_first_ok;
    }
    goto block_13;
block_first_ok:
    if (func_003df240(arg0, &mask_slot, 4) == 0) {
        goto block_13;
    }
    count = 0;
    do {
        entry = *(u8 ***)(base + 8);
        if (entry != NULL) {
            func_003e2ab0(arg0, func_003d8060(*entry), 0x20);
        }
        count += 1;
        base += 4;
    } while (count < 8U);
    return arg0;
block_13:
    return 0;
}

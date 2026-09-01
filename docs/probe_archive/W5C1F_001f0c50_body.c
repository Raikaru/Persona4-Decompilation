/* Best candidate for func_001f0c50: object 212B, window 224B, normalized_diff 161. */
s32 func_001f0c50(u8 *arg0)
{
    s32 result;
    s32 i;
    s32 n;
    s32 one;
    s32 j;
    s32 innerCount;
    u8 **slot;
    u8 *target;
    u8 *entry;
    u8 *base0;
    u8 *base1;

    result = 0;
    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    one = 1;
    goto outer_test;
outer:
    slot = (u8 **)(arg0 + ((i & 0xFFFF) * 4) + 0x38);
    target = *slot;
    if (target == arg0) {
        goto outer_next;
    }
    base0 = *(u8 **)(arg0 + 0x30);
    base1 = *(u8 **)(target + 0x30);
    if (*(u8 *)(base0 + 0xA2) == *(u8 *)(base1 + 0xA2)) {
        goto same_type;
    }
    result = 0;
    goto done;
same_type:
    if (result != 0) {
        goto outer_next;
    }
    j = 0;
    innerCount = *(u8 *)(target + 0xD9);
    goto inner_test;
inner:
    entry = target + ((j & 0xFFFF) << 5);
    if (*(s32 *)(entry + 0xF0) > 0) {
        result = one;
    }
    if (*(s32 *)(entry + 0xF4) > 0) {
        result = one;
    }
    if (*(s32 *)(entry + 0xFC) != 0) {
        result = one;
    }
    j = (j + 1) & 0xFFFF;
inner_test:
    if ((j & 0xFFFF) < innerCount) {
        goto inner;
    }
outer_next:
    i = (i + 1) & 0xFFFF;
    goto outer_test;
outer_test:
    if ((i & 0xFFFF) < n) {
        goto outer;
    }
done:
    return result;
}

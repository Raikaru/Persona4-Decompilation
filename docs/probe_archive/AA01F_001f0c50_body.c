// FUN_001F0C50
s32 func_001f0c50(u8 *arg0)
{
    s32 result;
    s32 i;
    s32 j;
    s32 n;
    s32 innerCount;
    u8 *target;
    u8 *base;

    result = 0;
    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    goto outer_test;
outer:
    target = *(u8 **)(arg0 + ((u16)i << 2) + 0x38);
    if (target == arg0) {
        goto outer_next;
    }
    base = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(base + 0xA2) != *(u8 *)(*(u8 **)(target + 0x30) + 0xA2)) {
        result = 0;
        goto done;
    }
    if (result != 0) {
        goto outer_next;
    }
    j = 0;
    innerCount = *(u8 *)(target + 0xD9);
    goto inner_test;
inner:
    if (*(s32 *)(target + ((u16)j << 5) + 0xF0) > 0) {
        result = 1;
    }
    if (*(s32 *)(target + ((u16)j << 5) + 0xF4) > 0) {
        result = 1;
    }
    if (*(s32 *)(target + ((u16)j << 5) + 0xFC) != 0) {
        result = 1;
    }
    j = (j + 1) & 0xFFFF;
inner_test:
    if ((j & 0xFFFF) < innerCount) {
        goto inner;
    }
outer_next:
    i = (i + 1) & 0xFFFF;
outer_test:
    if ((i & 0xFFFF) < n) {
        goto outer;
    }
done:
    return result;
}

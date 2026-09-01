/* object_size=72B window=80B normalized_diff=24 differing_offsets=6,10,14,28,30,31,34,36,38,40,41,42,43,44,45,46; ruled out declaration-order, base-local, O1/O3, CSE, loop-invariant, schedule, and explicit-goto probes. */
s32 func_003e23e0(void) {
    s32 base;
    u8 *head;
    u8 *node;
    register s32 result;
    base = (s32)D_008872E0 + (u32)iGpffffb780;
    head = *(u8 **)(base + 0x24);
    node = *(u8 **)head;
    if (node == head) {
        goto done;
    }
    result = *(s32 *)(base + 8);
loop:
    result += *(s32 *)(node + 8);
    node = *(u8 **)node;
    if (node != head) {
        goto loop;
    }
done:
    return result;
}

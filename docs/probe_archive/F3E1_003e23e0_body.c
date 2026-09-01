/* object_size=72B window=80B normalized_diff=20 differing_offsets=2,6,10,14,28,30,31,34,36,38,46,47,52,53,54,55; ruled out direct-global and base-local address spellings, integer-domain address arithmetic, register qualifiers, result declaration order, goto/if/do-while loop shapes, and O1/O3/schedule probes; no callees. Retail's first three address instructions and loop delay-slot/nop placement remain compiler register/scheduling residuals. */
s32 func_003e23e0(void) {
    u8 *base;
    u8 *head;
    u8 *node;
    register s32 result;

    base = (u8 *)D_008872E0 + (s32)iGpffffb780;
    head = *(u8 **)(base + 0x24);
    node = *(u8 **)head;
    if (node != head) {
        result = *(s32 *)(base + 8);
    loop:
        result += *(s32 *)(node + 8);
        node = *(u8 **)node;
        if (node != head) {
            goto loop;
        }
    }
    return result;
}

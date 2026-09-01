/* object 296B/window 304B, normalized_diff 124, differing offsets 4-31,52,56,88,104,108,116-124,...; classification UNDERSIZED/NEAR_MISS (8B short). Retail frame exact 64B saves s2/s1/s0 (three long-lived locals), one pointer argument; candidate has same frame/saves but switch/list layout and prologue constant scheduling differ. No movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, or sd/sq mixed-unit floor. Ruled out generated switch, direct explicit if-chain, case declaration reorder (-2 first), schedule/no_branch probe; helper prototypes are block-scoped and exact call targets. */
void func_003c91d0(u8 *arg0) {
    extern void func_003ca960(u8 *arg0);
    extern void func_003ca9d0(u8 *arg0);
    extern void func_003e1ea0(u8 *arg0);
    u8 *self;
    u8 *cursor;
    u8 *sentinel;
    s32 state;

    self = arg0;
    state = *(s32 *)self;
    switch (state) {
    case -1:
        if (*(u8 **)(self + 0x34) != NULL)
            func_003e1ea0(*(u8 **)(self + 0x34));
        cursor = *(u8 **)(self + 0x38);
        sentinel = self + 0x38;
        if (cursor != sentinel) {
list_a:
            func_003ca9d0(cursor);
            cursor = *(u8 **)cursor;
            if (cursor != sentinel)
                goto list_a;
        }
        cursor = *(u8 **)(self + 0x40);
        sentinel = self + 0x40;
        if (cursor != sentinel) {
list_b:
            func_003ca960(cursor);
            cursor = *(u8 **)cursor;
            if (cursor != sentinel)
                goto list_b;
        }
        func_003e3c20(D_0070B040, self);
        if (*(s32 *)(self + 0x78) != 0) {
            func_003c5760(*(u8 **)(self + 0x78));
            *(s32 *)(self + 0x78) = 0;
        }
        break;
    case -2:
        break;
    default:
        cursor = *(u8 **)(self + 8);
        if (cursor != NULL)
            func_003c91d0(cursor);
        cursor = *(u8 **)(self + 0xC);
        if (cursor != NULL)
            func_003c91d0(cursor);
        break;
    }
}

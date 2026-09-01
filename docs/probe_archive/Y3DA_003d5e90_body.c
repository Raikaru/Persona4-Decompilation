/* object 176B, window 192B, normalized_diff 34; differing offsets 52,60,64,68,72,76,80,84,88,92,96,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160,164,168,172,176,180,184; casts written: none; levers ruled out: schedule on, no_branch_likely on, opt_propagation off, named signed guard boolean, both loop-exit comparison directions, guarded do/while, explicit goto loop/done layout, direct indexed field expressions, and callback argument staging. */
s32 func_003d5e90(u8 *arg0, u8 *arg1, u8 *arg2, f32 fparg0) {
    s32 index;
    s32 has_items;
    s32 count;

    index = 0;
    count = *(s32 *)(arg0 + 0x2C);
    has_items = (0 < count);
    if (has_items == 0) {
        goto done;
    }
    do {
        ((void (*)(u8 *, u8 *, u8 *, f32))(*(u32 *)(arg0 + 0x40)))(
            arg0 + index * *(s32 *)(arg0 + 0x24) + 0x4C,
            arg1 + index * *(s32 *)(arg1 + 0x24) + 0x4C,
            arg2 + index * *(s32 *)(arg2 + 0x24) + 0x4C,
            fparg0);
        index += 1;
    } while (*(s32 *)(arg0 + 0x2C) > index);
done:
    return 1;
}

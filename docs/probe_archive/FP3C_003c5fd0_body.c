/* func_003c5fd0 near-match archive: current object 136B/window 144B, normalized_diff 93; differing offsets 2,8,10,20,22-124 (31 differing words). The stale nd 88 switch reconstruction has a large control-flow order residual. */
s32 func_003c5fd0(u8 *arg0, u8 *arg1) {
    u8 type;
    s32 flags;

    type = *(u8 *)(arg1 + 0);
    switch (type) {
    case 7:
    test7:
        flags = *(s32 *)(arg1 + 8);
        if ((flags & 0x01000000) == 0)
            goto general;
        goto fixed;
    case 8:
        flags = *(s32 *)(arg1 + 8);
        if ((flags & 0x01000000) != 0)
            goto fixed;
        goto test7;
    default:
        goto general;
    }
fixed:
    return (*(u16 *)(arg0 + 4) << 3) + 0xC;
general:
    return (*(u16 *)(arg0 + 4) << 3) + 0xC + (*(s32 *)(arg0 + 8) << 2);
}

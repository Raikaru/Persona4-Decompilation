/* func_003c0050 archive: object 136B, window 144B, current normalized_diff 35; differing offsets 38-46,54,84,94,98,100-105. Same-size stale body; declaration order and dependent initialization did not move end/node/next register or load order. Schedule off is oversized at 156B/144B, nd 106. */
u8 *func_003c0050(u8 *arg0, s32 (*arg1)(s32, s32), s32 arg2) {
    extern s32 iGpffffb6b4;
    u8 *end;
    s32 *node;
    s32 next;

    end = arg0 + 0x10;
    node = *(s32 **)(arg0 + 0x10);
    if (node == (s32 *)end)
        goto empty;
loop:
    next = *node;
    if (arg1((s32)((u8 *)node - 4) - iGpffffb6b4, arg2) == 0)
        return arg0;
    node = (s32 *)next;
    if (next != (s32)end)
        goto loop;
empty:
    return arg0;
}

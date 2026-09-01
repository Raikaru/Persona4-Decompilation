/* CURRENT RECHECK: object 168B/window 160B, normalized_diff 114; differing offsets 20,22,23,24,26,27,32,33,34,35,36,37,38,39,40,41. Object exceeds the retail window, so this body is archived immediately. Prior probes ruled out block-scope func_003e9700(s32 *), dependent sentinel load, schedule/no_branch_likely, declaration order, explicit labels, an empty trampoline, and self-assignment; the prior object-140/nd24 archive was stale under the current TU. */
u8 *func_003bfe90(u8 *arg0) {
    extern u8 *func_003e9700(s32 arg0);
    s32 (*callback)(u8 *);
    u8 *result;
    u8 *current;
    u8 *entry;
    u8 *sentinel;

    sentinel = arg0 + 8;
    current = *(u8 **)sentinel;
    result = arg0;
    if (current == sentinel)
        goto empty;
loop:
    entry = current - 0x40;
    if ((*(u8 *)(current - 0x3E) & 4) != 0)
        goto callback_block;
advance:
    current = *(u8 **)current;
    if (current != sentinel)
        goto loop;
    if (current == sentinel)
        goto empty;
    result = result;
empty:
    goto done;
done:
    return result;
callback_block:
    func_003e9700(*(s32 *)(entry + 4));
    callback = *(s32 (**)(u8 *))(entry + 0x48);
    if (callback(entry) != 0)
        goto advance;
    result = NULL;
    goto advance;
}

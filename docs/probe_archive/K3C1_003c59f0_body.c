/* func_003c59f0 archive: current object 168B/window 160B, normalized_diff 98; first reported differing offsets 16-20,22,24-31,34,36 (verify reports first 16 offsets only). The archived body is oversized, so no further probes were attempted. */
u8 *func_003c59f0(u8 *arg0, s32 (*arg1)(u8 *, u8 *, s32), s32 arg2) {
    u8 *cursor;
    s32 remaining;
    s32 user;
    s32 (*callback)(u8 *, u8 *, s32);
    u8 *self;
    u16 count;

    self = arg0;
    callback = arg1;
    user = arg2;
    count = *(u16 *)(self + 4);
    remaining = (s32)count - 1;
    cursor = (u8 *)(*(s32 *)(self + 0xC) + (s32)self + 0x10);
    if (count != 0) {
        do {
            if (callback(cursor, self, user) == 0)
                return self;
            cursor += 0xC;
        } while (remaining-- != 0);
    }
    return self;
}
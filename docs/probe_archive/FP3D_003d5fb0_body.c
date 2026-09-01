/* Archived best attempt for func_003d5fb0: object 76 bytes, window 96 bytes, normalized_diff 15. schedule on. */
s32 func_003d5fb0(u8 *arg0) {
    u8 *self;
    s32 value;
    self = arg0;
    value = func_003df5d0(4, *(s32 *)(self + 4) | 0x40000);
    *(s32 *)(self + 0x10) = value;
    if (value == 0) {
        return 0;
    }
    *(s32 *)(self + 0x14) = 0;
    return (s32)self;
}

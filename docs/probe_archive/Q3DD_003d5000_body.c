/* object 316B/window 304B/normalized_diff 181; differing offsets 16,24-43; classification OVERSIZED; no movz/movn, COP1 accumulator, standalone MMI, framed tail jump, or custom COP1 opcode observed; direct float-copy reconstruction with pinned log aggregate was oversized and discarded immediately. */
s32 func_003d5000(u8 *arg0) {
    s32 count;
    s32 i;
    u8 *entry;
    u8 *dst;
    struct {
        s32 limit_code;
        s32 limit_value;
        s32 duplicate_code;
        s32 duplicate_value;
    } frame;

    count = iGpffffb728;
    if (count < 0x10) {
        if (count > 0) {
            entry = (u8 *)D_00886E50;
            i = 0;
            do {
                if (*(s32 *)arg0 == *(s32 *)entry) {
                    frame.duplicate_code = 0x1B7;
                    frame.duplicate_value = func_003df590(0);
                    func_003df4d0(&frame.duplicate_code);
                    return 0;
                }
                i += 1;
                entry += 0x30;
            } while (i < count);
        }
        dst = (u8 *)D_00886E50 + count * 0x30;
        *(f32 *)(dst + 0) = *(f32 *)(arg0 + 0);
        *(f32 *)(dst + 4) = *(f32 *)(arg0 + 4);
        *(f32 *)(dst + 8) = *(f32 *)(arg0 + 8);
        *(f32 *)(dst + 0xC) = *(f32 *)(arg0 + 0xC);
        *(f32 *)(dst + 0x10) = *(f32 *)(arg0 + 0x10);
        *(f32 *)(dst + 0x14) = *(f32 *)(arg0 + 0x14);
        *(f32 *)(dst + 0x18) = *(f32 *)(arg0 + 0x18);
        iGpffffb728 = count + 1;
        *(f32 *)(dst + 0x1C) = *(f32 *)(arg0 + 0x1C);
        *(f32 *)(dst + 0x20) = *(f32 *)(arg0 + 0x20);
        *(f32 *)(dst + 0x24) = *(f32 *)(arg0 + 0x24);
        *(f32 *)(dst + 0x28) = *(f32 *)(arg0 + 0x28);
        return 1;
    }
    frame.limit_code = 0x1B7;
    frame.limit_value = func_003df590(1);
    func_003df4d0(&frame.limit_code);
    return 0;
}

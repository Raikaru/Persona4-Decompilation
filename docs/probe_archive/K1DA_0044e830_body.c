/* object 204B, retail window 160B, normalized_diff 167; differing offsets 0x0,0x4,0x6,0x8-0xC,0xE,0x10-0x14,0x16,0x1C; object exceeds window, so reconstruction rather than polish. Corrected declaration: func_0044ddf0(u32 *,u32 *). Tried scalar and aggregate stack layouts; MWCC keeps the parser output at +0x10 rather than retail +0, ruled out within stopping budget. */
s64 func_0044e830(s64 arg0) {
    struct {
        u32 sp0;
        u32 sp4;
        u32 sp8;
        u32 padC;
        u64 sp10;
        u8 pad18[8];
        s64 sp20;
    } frame;
    s64 var_2;
    u64 var_15;

    frame.sp20 = arg0;
    func_0044ddf0((u32 *)&frame.sp20, (u32 *)&frame.sp0);
    var_2 = 0;
    if ((frame.sp0 ^ 2) != 0) {
        if ((frame.sp0 >= 2U) && (frame.sp4 == 0)) {
            var_2 = -1;
            if ((frame.sp0 ^ 4) != 0) {
                var_2 = 0;
                if ((s32)frame.sp8 >= 0) {
                    var_2 = -1;
                    if (frame.sp8 < 0x20) {
                        if (frame.sp8 >= 0x3D) {
                            var_15 = frame.sp10 << (frame.sp8 - 0x3C);
                        } else {
                            var_15 = frame.sp10 >> (0x3C - frame.sp8);
                        }
                        var_2 = (s64)(var_15 << 0x20) >> 0x20;
                    }
                }
            }
        }
    }
    return var_2;
}

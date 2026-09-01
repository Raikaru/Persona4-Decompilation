/* object 316B/window 288B/normalized_diff 212; differing offsets 4-24; classification OVERSIZED; no movz/movn, COP1 accumulator, standalone MMI, framed tail jump, or custom COP1 opcode observed; aggregate stack and explicit helper declarations still produced a different oversized body, discarded immediately. */
s32 func_003dc370(s8 *arg0) {
    extern s32 func_003e2910(u8 *arg0, void *dst, s32 size);
    extern s32 func_003ef0d0(void);
    extern s32 func_003ef6b0(s32 arg0);
    extern s32 func_003ef6d0(void);
    extern s32 func_003db630(s8 *arg0, s32 *arg1);
    extern s32 func_003dbe40(s8 *arg0);
    s32 index;
    s32 temp_2;
    struct {
        u8 pad[8];
        u8 count;
        u8 pad2;
        u16 half;
        s32 value;
    } frame;

    if (func_003e2910((u8 *)arg0, &frame.count, 4) < 4U) {
        return 0;
    }
    temp_2 = func_003ef0d0();
    frame.value = temp_2;
    if (temp_2 != 0) {
        if (frame.half > 0) {
            temp_2 = func_003ef6d0();
            func_003ef6b0(frame.value);
            index = 0;
            if (frame.count != 0) {
                do {
                    if (func_003dbe40(arg0) == 0) {
                        func_003ef6b0(temp_2);
                        return 0;
                    }
                    index += 1;
                } while (index < frame.count);
            }
            func_003ef6b0(temp_2);
        } else {
            index = 0;
            if (frame.count != 0) {
                do {
                    func_003db630(arg0, &frame.value);
                    index += 1;
                } while (index < frame.count);
            }
        }
        return frame.value;
    }
    return 0;
}

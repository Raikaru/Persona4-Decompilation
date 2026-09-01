/* object 344B/window 304B/normalized_diff 251; differing offsets 0,4,6-33; classification OVERSIZED; no movz/movn, COP1 accumulator, standalone MMI, framed tail jump, or custom COP1 opcode observed; direct stack-aggregate reconstruction was oversized and discarded immediately. */
s32 func_003d81d0(s8 *arg0, u16 arg1, u8 *arg2) {
    extern s32 func_003df240();
    extern s32 func_003df270();
    s32 size;
    struct {
        s32 final_size;
        s32 first_size;
        u8 pad[2];
        u16 half0;
        u16 half1;
        u8 byte_m;
        u8 byte_b;
    } frame;

    frame.byte_b = 0x42;
    func_003e2ab0(arg0, &frame.byte_b, 1);
    frame.byte_m = 0x4D;
    func_003e2ab0(arg0, &frame.byte_m, 1);
    if (arg1 < 9U) {
        size = (1 << arg1) * 4;
    } else {
        size = 0;
    }
    frame.first_size = size + 0x36 +
        (*(s32 *)(arg2 + 8) *
            (((*(s32 *)(arg2 + 4) * arg1 + 0x1F) & ~0x1F) >> 3));
    func_003df240(arg0, &frame.first_size, 4);
    frame.half1 = 0;
    func_003df270(arg0, &frame.half1, 2);
    frame.half0 = 0;
    func_003df270(arg0, &frame.half0, 2);
    if (arg1 < 9U) {
        size = (1 << arg1) * 4;
    } else {
        size = 0;
    }
    frame.final_size = size + 0x36;
    func_003df240(arg0, &frame.final_size, 4);
    return 0xE;
}

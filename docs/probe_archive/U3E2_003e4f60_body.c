/* object 344B/window 320B, normalized_diff 264; differing offsets 0x04 onward; frame 80B matched but 24-byte surplus; prologue saved s1/s0 and args arg0,arg1; block-scope declarations for callees; classification call materialisation, range-guard, switch order and return-tail residuals; ruled out explicit-gap aggregate and schedule-on probes. */
u8 *func_003e4f60(u8 *arg0, s32 arg1) {
    u8 *source;
    s32 key;
    s32 temp;
    struct {
        u8 gap0[8];
        s32 sp38;
        s32 sp3C;
        u8 gap1[4];
        u32 sp44;
        u32 sp48;
        s32 sp4C;
    } frame;
    s32 in_range;
    extern s32 func_003deea0();
    extern void func_003df4d0();
    extern s32 func_003df590();
    extern s32 func_003e2ce0();
    extern u8 *func_003e4be0();
    extern u8 *func_003e4d80();

    source = arg0;
    key = arg1;
    temp = 0;
    if (func_003deea0(key, &frame.sp4C, &frame.sp48, &frame.sp44, temp) != 0) {
loop:
        if (frame.sp44 < 0x35000U) {
            in_range = 0;
        } else {
            in_range = (frame.sp44 < 0x37003U);
        }
        if (in_range == 0) {
            goto error;
        }
        switch (frame.sp4C) {
        case 2:
            return func_003e4be0(source, key, frame.sp48);
        case 19:
            return func_003e4d80(source, key, frame.sp48);
        default:
            break;
        }
        if (func_003e2ce0(key, frame.sp48) == 0) {
            goto done;
        }
        if (func_003deea0(key, &frame.sp4C, &frame.sp48, &frame.sp44, temp) == 0) {
            goto done;
        }
        goto loop;
    }
error:
    frame.sp38 = 1;
    frame.sp3C = func_003df590(0x80000004);
    func_003df4d0(&frame.sp38);
done:
    return NULL;
}

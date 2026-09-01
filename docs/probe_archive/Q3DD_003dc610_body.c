/* object 312B/window 304B/normalized_diff 203; differing offsets 28,38,42,46,49-61,63; classification OVERSIZED; no movz/movn, COP1 accumulator, standalone MMI, framed tail jump, or custom COP1 opcode observed; direct sqrtf and callback reconstruction still exceeded the window and was discarded immediately. */
s32 func_003dc610(u8 *arg0, u8 *arg1) {
    extern u8 *func_003dc490(u8 *arg0, u8 *arg1);
    extern u8 *func_003dc510(u8 *arg0, u8 *arg1);
    extern u8 *func_003dc590(u8 *arg0, u8 *arg1);
    extern f32 sqrtf(f32 arg0);
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f6;
    s32 result;
    u8 *(*callback)(u8 *arg0, u8 *arg1);
    result = arg0 != NULL;
    if (result != 0) {
        result = arg1 != NULL;
    }
    if (result != 0) {
        temp_f5 = *(f32 *)(arg1 + 0x14);
        temp_f4 = *(f32 *)(arg1 + 0);
        temp_f3 = *(f32 *)(arg1 + 0x28);
        temp_f2 = temp_f3 + (temp_f4 + temp_f5);
        if (temp_f2 <= 0.0f) {
            if (!(temp_f4 <= temp_f5)) {
                if (!(temp_f4 <= temp_f3)) {
                    callback = func_003dc490;
                } else {
                    callback = func_003dc590;
                }
            } else if (!(temp_f5 <= temp_f3)) {
                callback = func_003dc510;
            } else {
                callback = func_003dc590;
            }
            callback(arg0, arg1);
        } else {
            temp_f6 = sqrtf(1.0f + temp_f2);
            *(f32 *)(arg0 + 0xC) = 0.5f * temp_f6;
            temp_f6 = 0.5f / temp_f6;
            temp_f5 = *(f32 *)(arg1 + 0x18);
            temp_f4 = *(f32 *)(arg1 + 0x24);
            temp_f3 = *(f32 *)(arg1 + 4);
            temp_f2 = *(f32 *)(arg1 + 0x10);
            *(f32 *)(arg0 + 0) = temp_f6 * (temp_f5 - temp_f4);
            temp_f5 = *(f32 *)(arg1 + 0x20);
            temp_f4 = *(f32 *)(arg1 + 8);
            *(f32 *)(arg0 + 4) = temp_f6 * (temp_f5 - temp_f4);
            *(f32 *)(arg0 + 8) = temp_f6 * (temp_f3 - temp_f2);
        }
    }
    return result;
}

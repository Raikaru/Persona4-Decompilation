/* object 352B/window 304B/normalized_diff 248; differing offsets 16-36; classification OVERSIZED; no movz/movn, COP1 accumulator, standalone MMI, framed tail jump, or custom COP1 opcode observed; direct flag-accumulation reconstruction emitted absolute HI16/LO16 string addresses instead of retail GPREL calls and exceeded the window, discarded immediately. */
u8 *func_003dddf0(u8 *arg0, s8 *arg1) {
    extern s8 *func_00443010(s8 *arg0, s8 *arg1);
    extern u8 *func_003ddca0(u8 *arg0);
    extern s8 iGpffffab3c[];
    extern s8 iGpffffab40[];
    extern s8 iGpffffab44[];
    extern s8 iGpffffab48[];
    extern s8 iGpffffab4c[];
    s32 flag;
    s32 has_first;
    s32 has_second;
    u8 *temp;
    flag = 0;
    has_first = 0;
    has_second = 0;
    if (func_00443010(arg1, iGpffffab3c) != NULL) has_first = 1;
    if (func_00443010(arg1, iGpffffab40) != NULL) has_second = 1;
    if (func_00443010(arg1, iGpffffab44) != NULL) {
        flag |= 1;
        if (has_first != 0) { flag |= 2; flag |= 8; }
    }
    if (func_00443010(arg1, iGpffffab48) != NULL) {
        flag |= 2; flag |= 4;
        if (has_first != 0) flag |= 1;
    }
    if (func_00443010(arg1, iGpffffab4c) != NULL) {
        flag |= 2; flag |= 8;
        if (has_first != 0) flag |= 1;
        if (has_second != 0) flag |= 4;
    }
    temp = func_003ddca0(arg0);
    if (temp != NULL) return func_003dda50(temp, (s32)arg0, flag, 0, 0);
    return NULL;
}

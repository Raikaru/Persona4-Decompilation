/* object 276B/window 256B/normalized_diff 204; differing offsets 16-35; classification OVERSIZED; ruled out confirmed compiler floors (no movz/movn, COP1 accumulator, standalone MMI, framed tail jump, or custom COP1 opcode); raw M2C body measured and discarded immediately. */
s32 func_003dd430(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4) {
    extern s32 func_00442948();
    extern void (*D_008873AC[])(s32 arg0, s32 arg1);
    s32 temp_17;
    s32 temp_2;
    s32 var_6;
    s8 *var_5;
    s8 temp_4;

    temp_17 = func_00442948(arg2);
    temp_2 = func_00442948(arg3);
    if ((arg1 - 1) < (temp_17 + temp_2)) {
        return 0;
    }
    D_008873AC[0](arg0, arg2);
    var_6 = 0;
    if (temp_2 >= 0) {
        var_5 = (s8 *)(arg0 + temp_17);
        do {
            temp_4 = *(s8 *)(arg3 + var_6);
            if ((temp_4 != 0x2F) && (temp_4 != 0x5C)) {
                *var_5 = temp_4;
            } else {
                *var_5 = arg4;
            }
            var_6 += 1;
            var_5 += 1;
        } while (temp_2 >= var_6);
    }
    return arg0;
}

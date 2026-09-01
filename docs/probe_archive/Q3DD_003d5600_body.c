/* object 324B/window 272B/normalized_diff 219; differing offsets 4-24; classification OVERSIZED; ruled out confirmed compiler floors (no movz/movn, COP1 accumulator, standalone MMI, framed tail jump, or custom COP1 opcode); direct M2C-shaped chain is a different function and was discarded immediately. */
s32 func_003d5600(s32 **arg0, s32 arg1) {
    extern s32 func_003d5710();
    extern s32 func_003df1a0();
    extern s32 func_003df240();
    s32 sp3c;

    sp3c = 0x100;
    func_003deff0(arg1, 0x1B, func_003d5710(), 0x37002, 0x37);
    if (func_003df240(arg1, &sp3c, 4) == 0) {
        return 0;
    }
    if (func_003df240(arg1, *arg0, 4) == 0) {
        return 0;
    }
    if (func_003df240(arg1, arg0 + 1, 4) == 0) {
        return 0;
    }
    if (func_003df240(arg1, arg0 + 2, 4) == 0) {
        return 0;
    }
    if (func_003df1a0(arg1, arg0 + 3, 4) == 0) {
        return 0;
    }
    ((void (*)(s32 **, s32))(*(void **)(*(s32 **)arg0 + 0x24)))(arg0, arg1);
    return 1;
}

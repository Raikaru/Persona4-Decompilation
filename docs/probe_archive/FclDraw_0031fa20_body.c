/* func_0031fa20 draft: 555 differing words reloc-masked (3024-byte window).
   Shape: FclVec2 arg1 (homed at sp+0x58), s32 arg2 passed raw to 6a70/6af0/69f0
   (69f0 needs a local s32-last-parameter extern), s8 arg3, struct-return
   func_002b2970 nested in the consuming calls, FclByte4 colours.
   Open problems: a named y0 = arg1.y is hoisted to function entry (retail loads it
   after func_0046d200); in the all-expression form the arg1.y temp is CSE'd into
   block 2 (retail reloads 0x5C there) and costs an extra saved FPR ($f22), which
   also shifts the frame and GPR colouring (retail arg2 $s0, arg3 $s1, handle $s2).
   See FclDraw_0031c2b0_0031cce0_20260925.md. */
// FUN_0031FA20
void func_0031fa20(u8 *arg0, FclVec2 arg1, s32 arg2, s8 arg3) {
    extern void func_002b69f0(s16, FclVec2, FclVec2, u32, u32, s32);
    extern FclVec2 func_002b2970(f32, f32);
    FclByte4 c13C;
    FclByte4 c138;
    FclByte4 c134;
    FclByte4 c130;
    FclByte4 c12C;
    u8 *h;
    f32 y;
    f32 x;

    h = func_0046d200(func_00331560(), 0x193);
    x = arg1.y;
    func_002b6c30(0x27C, func_002b2970(arg1.x, x), 191.0f, 0x57);
    c13C = func_002b2a60(0, 0, 0x99, 0xFF);
    *(FclByte4 *)(func_002b6150(0x27C) + 0x85) = c13C;
    func_002b6a70(0x27C, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(0x27C, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b69f0(0x27C, func_002b2970(arg1.x, x + func_0046b2f0(h) / 2.0f), func_002b2970(arg1.x, x), 0, 3, arg2);
    if (arg3 == 1) {
        func_002b6a70(0x27C, 0xFF, 0, 0, 0, (s16)((s16)arg2 + 3));
        func_002b6af0(0x27C, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b69f0(0x27C, func_002b2970(arg1.x, x), func_002b2970(arg1.x, x + func_0046b2f0(h) / 2.0f), 0, 3, arg2);
    }
    func_0046d280(h);
    h = func_0046d200(func_00331560(), 0x19B);
    y = arg1.y;
    x = (f32)0x11D + arg1.x;
    func_002b6c30(0x289, func_002b2970(x, y), 191.0f, 0x57);
    c138 = func_002b2a60(0, 0, 0x99, 0xFF);
    *(FclByte4 *)(func_002b6150(0x289) + 0x85) = c138;
    func_002b6a70(0x289, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(0x289, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b69f0(0x289, func_002b2970(x, y + func_0046b2f0(h) / 2.0f), func_002b2970(x, y), 0, 3, arg2);
    if (arg3 == 1) {
        func_002b6a70(0x289, 0xFF, 0, 0, 0, (s16)((s16)arg2 + 3));
        func_002b6af0(0x289, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        x = (f32)0x11D + arg1.x;
        func_002b69f0(0x289, func_002b2970(x, y), func_002b2970(x, y + func_0046b2f0(h) / 2.0f), 0, 3, arg2);
    }
    func_0046d280(h);
    h = func_0046d200(func_00331560(), 0x72);
    y = 4.0f + arg1.y;
    x = 102.0f + arg1.x;
    func_002b6c30(0x72, func_002b2970(x, y), 177.0f, 0x59);
    c134 = func_002b2a60(0x33, 0xCD, 0xFF, 0xFF);
    *(FclByte4 *)(func_002b6150(0x72) + 0x85) = c134;
    func_002b6a70(0x72, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(0x72, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b69f0(0x72, func_002b2970(x, y + func_0046b2f0(h) / 2.0f), func_002b2970(x, y), 0, 3, arg2);
    if (arg3 == 1) {
        func_002b6a70(0x72, 0xFF, 0, 0, 0, (s16)((s16)arg2 + 3));
        func_002b6af0(0x72, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        y = 4.0f + arg1.y;
        x = 102.0f + arg1.x;
        func_002b69f0(0x72, func_002b2970(x, y), func_002b2970(x, y + func_0046b2f0(h) / 2.0f), 0, 3, arg2);
    }
    func_0046d280(h);
    h = func_0046d200(func_00331560(), 0x73);
    y = 9.0f + arg1.y;
    x = 55.0f + arg1.x;
    func_002b6c30(0x2AF, func_002b2970(x, y), 175.0f, 0x59);
    c130 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
    *(FclByte4 *)(func_002b6150(0x2AF) + 0x85) = c130;
    func_002b6a70(0x2AF, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(0x2AF, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b69f0(0x2AF, func_002b2970(x, y + func_0046b2f0(h) / 2.0f), func_002b2970(x, y), 0, 3, arg2);
    if (arg3 == 1) {
        func_002b6a70(0x2AF, 0xFF, 0, 0, 0, (s16)((s16)arg2 + 3));
        func_002b6af0(0x2AF, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        y = 9.0f + arg1.y;
        x = 55.0f + arg1.x;
        func_002b69f0(0x2AF, func_002b2970(x, y), func_002b2970(x, y + func_0046b2f0(h) / 2.0f), 0, 3, arg2);
    }
    y = 9.0f + arg1.y;
    x = 208.0f + arg1.x;
    func_002b6c30(0x2B0, func_002b2970(x, y), 175.0f, 0x59);
    c12C = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
    *(FclByte4 *)(func_002b6150(0x2B0) + 0x85) = c12C;
    func_002b6a70(0x2B0, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(0x2B0, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b69f0(0x2B0, func_002b2970(x, y + func_0046b2f0(h) / 2.0f), func_002b2970(x, y), 0, 3, arg2);
    if (arg3 == 1) {
        func_002b6a70(0x2B0, 0xFF, 0, 0, 0, (s16)((s16)arg2 + 3));
        func_002b6af0(0x2B0, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        y = 9.0f + arg1.y;
        x = 208.0f + arg1.x;
        func_002b69f0(0x2B0, func_002b2970(x, y), func_002b2970(x, y + func_0046b2f0(h) / 2.0f), 0, 3, arg2);
    }
    func_0046d280(h);
}

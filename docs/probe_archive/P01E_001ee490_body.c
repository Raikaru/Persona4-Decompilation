/* object 384B, window 384B, normalized_diff 4, differing offsets 0xA4/0xA8/0xCA/0xCE: retail slti $at,$v0,13; bnez $at versus candidate slti $v0,$v0,13; bnez $v0 in both quotient-rounding guards; classification: MWCCPS2 conditional-result register-colouring floor; ruled out: typed mixed ABI declarations (func_00195850(u8 *, f32 *) and func_001ec790(u8 *, s16, s16, f32)), old-style callee views, s64 quotient locals (nd6 with daddiu increment residual), s32 quotient locals (nd4), direct >= guards, inverted/empty-body guards, explicit goto guards (nd4), operand-order guards (nd4), named remainder locals (nd4), 64-bit increment casts (400B/nd170), narrow remainder casts (400B/nd181), optimization_level 1 (400B/nd276), single-case switch guards (400B/nd172), quotient declaration swap (nd20), and no movz/movn, COP1 accumulator, standalone MMI, or framed tail-jump floor present. */
s32 func_001ee490(u8 *arg0) {
    extern void func_00195850(u8 *arg0, f32 *arg1);
    extern void func_001ec790(u8 *arg0, s16 arg1, s16 arg2, f32 arg3);
    f32 coords[3];
    s16 out_x;
    s16 out_y;
    f32 scale;
    f32 base;
    s32 x;
    s32 y;
    s32 rounded_x;
    s32 rounded_y;

    if ((*(s32 *)(arg0 + 0x9C) & 4) == 0) {
        return 0;
    }
    func_00195850(arg0, coords);
    scale = *(f32 *)(arg0 + 0x90) * *(f32 *)(arg0 + 0x2C);
    base = (f32)1750;
    x = (s32)(base + coords[0]);
    y = (s32)(base + coords[2]);
    rounded_x = (s64)(s16)(x / 25);
    rounded_y = (s64)(s16)(y / 25);
    if ((x % 25) >= 13) {
        rounded_x = (s64)(s16)(rounded_x + 1);
    }
    if ((y % 25) >= 13) {
        rounded_y = (s64)(s16)(rounded_y + 1);
    }
    if (&out_x != NULL) {
        out_x = (s16)rounded_x;
    }
    if (&out_y != NULL) {
        out_y = (s16)rounded_y;
    }
    if (*(s16 *)(arg0 + 0x508) != out_x ||
        *(s16 *)(arg0 + 0x50A) != out_y ||
        *(f32 *)(arg0 + 0x50C) != scale) {
        func_001ec790(arg0, out_x, out_y, scale);
        *(s16 *)(arg0 + 0x508) = out_x;
        *(s16 *)(arg0 + 0x50A) = out_y;
        *(f32 *)(arg0 + 0x50C) = scale;
        return 1;
    }
    return 0;
}

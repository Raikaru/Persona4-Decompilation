/* object 308B / window 320B / normalized_diff 16 / differing offsets 162,184,216,220,221,222,225,233,234,250,252,253,254,256,257,258 / instruction deficit 0 (tail-aligned; 3 words shorter due compiler shape) / classification COP1 accumulator-chain + FP register-colouring floor / ruled out: unsigned-int-to-float spelling, reload increment, zero-seeded ratio, source order, helper declaration */
s32 func_003720c0(u8 *arg0) {
    f32 ratio;
    f32 start;
    f32 diff;
    f32 zero;
    f32 t;

    ratio = (f32)(u32)*(u16 *)(arg0 + 0);
    if (!(ratio < *(f32 *)(arg0 + 4))) {
        return 1;
    }
    *(u16 *)arg0 += 1;
    if (*(f32 *)(arg0 + 4) <= 0.0f) {
        func_0046d730(&D_0064E9C0, 0x1EF);
    }
    start = *(f32 *)(arg0 + 0x18);
    t = (f32)(u32)*(u16 *)(arg0 + 0);
    zero = 0.0f;
    ratio = t + zero;
    ratio = ratio / *(f32 *)(arg0 + 4);
    diff = *(f32 *)(arg0 + 0x1C) - start;
    diff = diff * ratio;
    ratio = diff + start;
    func_00371160(arg0 + 0x2C, arg0 + 0x20, arg0 + 0x38, arg0 + 0xC, ratio);
    return 0;
}

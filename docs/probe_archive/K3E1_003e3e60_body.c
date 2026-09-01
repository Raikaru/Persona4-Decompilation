/* object_size=160B window=160B normalized_diff=n/a (COP1 MAC unavailable) differing_offsets=n/a; ruled out compliant plain-C loop/type/order/scheduler probes because retail uses mula.s/madd.s/adda.s accumulator instructions. */
u8 *func_003e3e60(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    f32 *out = (f32 *)arg0;
    f32 *in = (f32 *)arg1;
    f32 *m = (f32 *)arg3;
    s32 count = arg2 - 1;
    if (count >= 0) {
        do {
            out[0] = in[0] * m[0] + in[1] * m[4] + in[2] * m[8] + m[12];
            out[1] = in[0] * m[1] + in[1] * m[5] + in[2] * m[9] + m[13];
            out[2] = in[0] * m[2] + in[1] * m[6] + in[2] * m[10] + m[14];
            in += 3;
            out += 3;
            count -= 1;
        } while (count >= 0);
    }
    return arg0;
}

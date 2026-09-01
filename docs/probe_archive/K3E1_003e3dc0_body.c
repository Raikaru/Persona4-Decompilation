/* object_size=160B window=160B normalized_diff=n/a (COP1 MAC unavailable) differing_offsets=n/a; ruled out compliant plain-C type/order/scheduler probes because retail uses ordinary COP1 mula.s/madd.s/adda.s accumulator chain. */
u8 *func_003e3dc0(u8 *arg0, u8 *arg1, u8 *arg2) {
    f32 x = *(f32 *)(arg1 + 0);
    f32 y = *(f32 *)(arg1 + 4);
    f32 z = *(f32 *)(arg1 + 8);
    f32 *m = (f32 *)arg2;
    f32 *out = (f32 *)arg0;
    /* Retail computes three affine rows through a COP1 accumulator. */
    out[0] = x * m[0] + y * m[4] + z * m[8] + m[12];
    out[1] = x * m[1] + y * m[5] + z * m[9] + m[13];
    out[2] = x * m[2] + y * m[6] + z * m[10] + m[14];
    return arg0;
}

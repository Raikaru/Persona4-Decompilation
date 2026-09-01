/* object_size=160B window=160B normalized_diff=n/a (COP1 MAC unavailable) differing_offsets=n/a; ruled out compliant plain-C comparison/order/scheduler probes because retail uses mula.s/madda.s/madd.s accumulator instructions. */
s32 func_003e8200(s32 arg0, f32 *arg1) {
    f32 threshold = arg1[3];
    s32 result = 2;
    f32 *row = (f32 *)((u8 *)arg0 + 0x94);
    s32 remaining = 5;
    do {
        f32 value = arg1[0] * row[1] + arg1[1] * row[0] + arg1[2] * row[2] - row[3];
        if (value <= threshold) {
            return 0;
        }
        if (value > -threshold) {
            result = 1;
        }
        row = (f32 *)((u8 *)row + 0x14);
        remaining -= 1;
    } while (remaining != 0);
    return result;
}

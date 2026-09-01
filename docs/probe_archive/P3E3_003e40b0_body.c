/* object_size=208B window=208B normalized_diff=n/a (COP1 MAC floor) differing_offsets=n/a; retail uses mula.s/madda.s/madd.s accumulator instructions plus sqrt/coprocessor condition code, which compliant C cannot spell; ruled out plain-C arithmetic, scheduler pragmas, and type/operand probes. */
f32 func_003e40b0(u8 *arg0, u8 *arg1) {
    f32 length_sq;
    f32 scale;
    length_sq = *(f32 *)(arg1 + 4) * *(f32 *)(arg1 + 4)
        + *(f32 *)arg1 * *(f32 *)arg1
        + *(f32 *)(arg1 + 8) * *(f32 *)(arg1 + 8);
    scale = (length_sq > 0.0f) ? (1.0f / sqrtf(length_sq)) : length_sq;
    *(f32 *)arg0 = *(f32 *)arg1 * scale;
    *(f32 *)(arg0 + 4) = *(f32 *)(arg1 + 4) * scale;
    *(f32 *)(arg0 + 8) = *(f32 *)(arg1 + 8) * scale;
    return length_sq;
}

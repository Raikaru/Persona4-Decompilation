/* object_size=192B window=192B normalized_diff=n/a (COP1 MAC and COP1 condition-code floor) differing_offsets=n/a; retail uses mula.s/madd.s accumulator instructions and a COP1 condition-code extension, which compliant C cannot spell; ruled out plain-C arithmetic, scheduler pragmas, and type/operand probes. */
void func_003e41e0(f32 *arg0, f32 *arg1) {
    f32 length_sq;
    f32 scale;
    length_sq = arg1[0] * arg1[0] + arg1[1] * arg1[1];
    scale = (length_sq > 0.0f) ? (1.0f / length_sq) : length_sq;
    arg0[0] = arg1[0] * scale;
    arg0[1] = arg1[1] * scale;
}

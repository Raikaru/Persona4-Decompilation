/* object_size=80B window=80B normalized_diff=n/a (COP1 MAC floor) differing_offsets=n/a; retail uses ordinary COP1 mula.s/msub.s/madda.s/madd.s instructions, which compliant C cannot spell; ruled out plain-C scheduler/type/operand probes. */
f32 func_003e0130(f32 *arg0) {
    return arg0[0] * (arg0[5] * arg0[10] - arg0[6] * arg0[9])
        - arg0[1] * (arg0[4] * arg0[10] - arg0[6] * arg0[8])
        + arg0[2] * (arg0[4] * arg0[9] - arg0[5] * arg0[8]);
}

/* object 112B, window 112B, normalized_diff=n/a (COP1 MAC unavailable), differing_offsets=n/a; ruled out compliant plain-C scheduler/type/operand probes because retail uses ordinary COP1 mula.s/madda.s/madd.s chains that plain MWCCPS2 C does not emit. */
f32 func_003e01e0(u8 *arg0) {
    f32 *m = (f32 *)arg0;
    f32 row0 = m[1] * m[1] + m[0] * m[0] + m[2] * m[2] - 1.0f;
    f32 row1 = m[5] * m[5] + m[4] * m[4] + m[6] * m[6] - 1.0f;
    f32 row2 = m[9] * m[9] + m[8] * m[8] + m[10] * m[10] - 1.0f;
    return row0 * row0 + row1 * row1 + row2 * row2;
}

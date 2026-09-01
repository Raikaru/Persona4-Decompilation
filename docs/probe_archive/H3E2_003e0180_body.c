/* object 96B, window 96B, normalized_diff=n/a (COP1 MAC unavailable), differing_offsets=n/a; ruled out compliant plain-C scheduler/type/operand probes because retail uses ordinary COP1 mula.s/madda.s/madd.s chains that plain MWCCPS2 C does not emit. */
f32 func_003e0180(u8 *arg0) {
    f32 *m = (f32 *)arg0;
    f32 row0 = m[0] * m[4] + m[1] * m[5] + m[2] * m[6];
    f32 row1 = m[0] * m[8] + m[1] * m[9] + m[2] * m[10];
    f32 row2 = m[4] * m[8] + m[5] * m[9] + m[6] * m[10];
    return row0 * row0 + row1 * row1 + row2 * row2;
}

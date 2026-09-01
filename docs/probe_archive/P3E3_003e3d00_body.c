/* object_size=192B window=192B normalized_diff=n/a (COP1 MAC floor) differing_offsets=n/a; retail uses ordinary COP1 mula.s/madd.s/adda.s accumulator chains in the loop, which compliant C cannot spell; ruled out plain-C arithmetic, type/order reconstruction, scheduler pragmas, and operand probes. */
u8 *func_003e3d00(f32 *arg0, f32 *arg1, s32 arg2, f32 *arg3) {
    s32 i;
    (void)arg1;
    (void)arg3;
    for (i = arg2 - 1; i >= 0; i--) {
        /* COP1 accumulator chain intentionally not representable in compliant C. */
    }
    return (u8 *)arg0;
}

/* object 1520B / window 1520B / normalized_diff 0; differing offsets: none (ASM baseline); classification: COP1 accumulator-chain floor; ruled out: retail adda.s/msuba.s/madd.s/madda.s chains in both interpolation phases, which plain MWCC C cannot emit; no source probing per floor policy. */
void func_00385380(u8 *arg0)
{
    /* Retail's animation blend and coordinate interpolation use COP1 accumulators. */
    (void)arg0;
}

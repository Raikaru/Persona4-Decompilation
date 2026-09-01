/* object 1648B / window 1648B / normalized_diff 0; differing offsets: none (ASM baseline); classification: COP1 accumulator-chain floor; ruled out: retail adda.s/madd.s chains in random color generation and the four-entry render loop, which plain MWCC C cannot emit; no source probing per floor policy. */
void func_00389640(u8 *arg0)
{
    /* Retail's color interpolation and vertex placement use COP1 accumulators. */
    (void)arg0;
}

/* object 2880B / window 2880B / normalized_diff 0; differing offsets: none (ASM baseline); classification: COP1 accumulator-chain floor; ruled out: retail repeated mula.s/adda.s/madd.s/msub.s chains in timeline easing, text placement, and icon animation, which plain MWCC C cannot emit; no source probing per floor policy. */
void func_00387e70(u8 *arg0)
{
    /* Retail's timeline renderer requires COP1 accumulators throughout. */
    (void)arg0;
}

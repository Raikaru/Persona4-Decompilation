/* object 4752B / window 4752B / normalized_diff 0; differing offsets: none (ASM baseline); classification: COP1 accumulator-chain floor; ruled out: numerous retail mula.s/adda.s/madd.s chains for animation easing and repeated color interpolation, including accumulator-dependent byte conversion paths, which plain MWCC C cannot emit; no source probing per floor policy. */
void func_00385970(u8 *arg0)
{
    /* Retail's effect animation uses COP1 accumulator arithmetic. */
    (void)arg0;
}

/* Fresh scoped measurement: object_size=44 window=48 normalized_diff=7 differing_offsets=0,36,38,39,40,42,43; classification=loop-exit layout residual. Retail's bnez delay nop is followed by an additional nop before jr $ra; schedule off was measured and worsened to 48B/nd26, while/do-while and explicit goto/precheck variants did not add the nop. */
s32 func_003f5040(u32 arg0)
{
    s32 result;

    result = -1;
    if (arg0 == 0)
        goto done;
    do {
        arg0 >>= 1;
        result += 1;
    } while (arg0 != 0);
done:
    return result;
}

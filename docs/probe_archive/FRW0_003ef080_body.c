/* object_size=100 window=80 normalized_diff=69 differing_offsets=12,13,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76; classification=oversized after scalar conditional-move spelling; restored INCLUDE_ASM immediately. Earlier pointer-ternary/goto shape was 80/80 nd30 but did not match retail branch polarity/movz layout. */
s32 *func_003ef080(s32 *arg0, s32 arg1)
{
    extern s32 (*D_00887348[])(s32 *arg0, s32 arg1, s32 arg2);
    s32 *var_16;

    var_16 = arg0;
    if (arg1 == 0)
        goto clear;
    var_16 = (s32 *)((D_00887348[0](arg0, arg1, 0) != 0) ? (u32)var_16 : 0);
    goto done;
clear:
    *var_16 = 0;
done:
    return var_16;
}

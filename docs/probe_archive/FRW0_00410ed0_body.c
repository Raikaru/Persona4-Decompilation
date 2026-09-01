/* object_size=56 window=48 normalized_diff=29 differing_offsets=24,25,26,27,28,29,31,32,33,34,35,36,37,38,39,40; classification=oversized candidate (callee declaration/conditional return shape did not reproduce retail movz $s0,$zero,$v0). */
s32 func_00410ed0(s32 arg0, s32 arg1)
{
    extern s32 func_00411060(void);

    iGpffffb9b8 = arg1;
    return (func_00411060() == 0) ? 0 : arg0;
}

/* object 148B / window 160B / normalized_diff 6; residual at 0x40-0x44: func_003e1220 argument setup order: retail loads iGpffffaa0c into $a3 before materializing 0x40120 into $t1; candidate reverses. First diffs: [64, 65, 66, 67, 70, 71]. */
/* LANE_98350_G: opt_propagation off to keep the GP-load and constant-materialization as named locals, possibly letting the scheduler order them as in retail. */
#pragma push
#pragma opt_propagation off
// FUN_00398350
s32 func_00398350(s32 arg0)
{
    s32 temp_2;

    if (D_00884A7C[0] == 0)
        goto alloc;
block_1:
    D_00884A7C[0] += 1;
    return arg0;
alloc:
    temp_2 = func_003e1220(0x90, iGpffffaa08, 0x10, iGpffffaa0c,
                           D_00884A90, 0x40120U);
    D_00884A80[0] = temp_2;
    if (temp_2 == 0)
        goto block_5;
    if (func_0039aa30() != 0)
        goto block_1;
    goto done_zero;
done_zero:
    return 0;
block_5:
    return 0;
}
#pragma pop

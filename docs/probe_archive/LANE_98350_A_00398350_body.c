/* LANE_98350_A / 2026-09-02 / -O2,p baseline. F390_00398350_body.c starting point.
   Residual: object 148B / window 160B / nd 6 (2 words). Offsets 0x40/0x44:
   retail emits `lw $a3,-0x55F4($gp)` then `lui $v0,0x4`; candidate reverses.
   Tried: archive body as-is under existing schedule on + no_branch_likely on.
   Fndiff: 5 differing words (reloc-masked); non-reloc residual confirmed. */

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

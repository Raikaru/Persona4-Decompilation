/* object 148 / window 160 / normalized_diff 6; differing offsets 0x40 and 0x44 (retail lw $a3,-0x55F4($gp) then lui $v0,4; candidate reverses those words). PREHEADER ORDER residual. Newly ruled out in this wave: unsigned and pointer-typed arg3/callee prototypes, unsigned GP declaration, direct constant assignment, comma-sequenced GP/constant assignments, adjacent GP-before-constant assignments, declaration-order swap, and a six-field aggregate argument initializer. Existing archive exclusions remain in FP39_00398350_body.c. */
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

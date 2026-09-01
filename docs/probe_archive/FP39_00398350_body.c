/* object 148 / window 160 / nd 6; only differing words are offsets 0x40 and 0x44: retail emits lw $a3,-0x55F4($gp) before lui $v0,0x4, while the candidate emits the reverse in func_003e1220(0x90, iGpffffaa08, 0x10, iGpffffaa0c, D_00884A90, 0x40120). */
/* Ruled out: canonical and unnamed prototypes, unsuffixed constant, direct scalar globals, declaration-order swap, plain and static-inline reordered helper, constant and GP temp lifetimes, result register, scoped opt_loop, optimization_level, named locals for both arguments in argument order and retail hardware order with all six adjacent assignments, asymmetric naming of the GP global in a named s32 with inline 0x40120U and the opposite pairing, extern s32 iGpffffaa0c[] read via [0] (obj 152 / nd 21), #pragma schedule off (nd 39), unsigned and pointer-typed arg3/callee prototypes, unsigned GP declaration, direct constant assignment, comma-sequenced GP/constant assignments, adjacent GP-before-constant assignments, declaration-order swap, and a six-field aggregate argument initializer. */
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

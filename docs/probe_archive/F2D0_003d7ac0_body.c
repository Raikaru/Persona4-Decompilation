/* object_size=108 window=112 normalized_diff=32 differing_offsets=0x30,0x48-0x6c; classification: exact prologue, argument materialization, both helper call sequences, and first plain branch under schedule+no_branch_likely; remaining residual is retail's unconditional branch target/layout and `movz $s1,$zero,$v0` conditional move, which compliant plain C emits as a branch plus moves (MWCC movz floor). Block-scope externs: func_003e2ab0(s32,s32,s32), func_003df240(s32,s32,s32). */
s32 func_003d7ac0(s32 arg0, s32 arg1)
{
    extern s32 func_003e2ab0(s32, s32, s32);
    extern s32 func_003df240(s32, s32, s32);
    if (func_003e2ab0(arg1, arg0, 0x20) == 0) {
        return 0;
    }
    return (func_003df240(arg1, arg0 + 0x20, 0x20) == 0) ? 0 : arg0;
}

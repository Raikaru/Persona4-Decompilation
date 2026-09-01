/* object_size 60B, window 64B, normalized_diff 17, differing words at offsets 4, 8, 12, 48, 52 (reloc-masked; current first_diffs 4-15 and 48-55). Best current C candidate is schedule off + opt_propagation off. Classification: prologue/epilogue ORDER/scheduler residual; retail moves zero before saves and puts addiu-sp in the jr delay slot, while the candidate emits both in the opposite order. Re-measured after declaration changes. Freshly ruled out: split initialization (unchanged nd17), schedule-on alone (40B/nd31), and schedule-on + opt_propagation-off (52B/nd31); prior ruled-out probes remain: optimization_level 1, reversed local declaration order, separate call-result local, reversed addend/call operand order, result-dependent call address, and intra-function schedule toggles. */
s32 func_003d5710(u8 **arg0) {
    s32 temp = 0;
    s32 result = temp + 0x14;
    return result + (*(s32 (**)(void))(*arg0 + 0x28))();
}

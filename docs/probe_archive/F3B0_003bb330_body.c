/* object 104B/window 112B, normalized_diff 20; differing word offsets 4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,84 (fndiff reloc-masked). Best current-TU switch probe retained optimization_level 1, no_branch_likely on, and schedule on; if/goto/switch-order, stack-local order, schedule-off, and propagation probes were ruled out. */
#pragma optimization_level 1
#pragma no_branch_likely on
#pragma schedule on
s32 func_003bb330(u8 *arg0) {
    s32 sp1C;
    s32 sp18;
    s32 temp_3;

    temp_3 = *(s32 *)(arg0 + 0xC);
    switch (temp_3) {
    case 1:
        return *(s32 *)(arg0 + 8) - 2;
    case 2:
        return *(s32 *)(arg0 + 8) - 3;
    default:
        sp18 = 0x102;
        sp1C = func_003df590(1);
        func_003df4d0(&sp18);
        return 0;
    }
}
#pragma schedule off
#pragma no_branch_likely off
#pragma optimization_level 2

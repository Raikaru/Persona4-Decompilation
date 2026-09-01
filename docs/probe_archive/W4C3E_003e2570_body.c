/* object 120B, window 128B, normalized_diff 14; volatile-dependent; without it the object is 2 words undersized because the store/reload accesses fold; nonvolatile best after H001 cleanup; volatile-only exact attempt rejected. */
/* measured: schedule on probe for the nonvolatile body. */
#pragma schedule on
/* measured: no_branch_likely on probe for the nonvolatile body. */
#pragma no_branch_likely on
s32 func_003e2570(s32 arg0, s32 arg1) {
    s32 *slot;
    s32 result;

    D_00764878 = arg1;
    result = func_003e1220(0x24, D_00763C54, 4, D_00763C58, D_00887220, 0x40404);
    slot = (s32 *)(D_008872E0 + D_00764878);
    *slot = result;
    result = *slot;
    if (result == 0) {
        return 0;
    }
    D_0076487C += 1;
    return arg0;
}
/* measured: close no_branch_likely after the nonvolatile body. */
#pragma no_branch_likely off
/* measured: close schedule after the nonvolatile body. */
#pragma schedule off

/* object 124B, window 144B, normalized_diff 17; volatile-dependent; without it the object is 2 words undersized because the store/reload accesses fold; nonvolatile best after H001 cleanup; volatile-only exact attempt rejected. */
extern s32 D_00763C7C;
extern s32 D_00763C80;
extern u8 D_008872B0[];
/* measured: schedule on probe for the nonvolatile body. */
#pragma schedule on
/* measured: no_branch_likely on probe for the nonvolatile body. */
#pragma no_branch_likely on
s32 func_003e8080(s32 arg0, s32 arg1) {
    s32 *slot;
    s32 result;

    D_007648A0 = arg1;
    result = func_003e1220(*(s32 *)D_0070B710, D_00763C7C, 0x10, D_00763C80, D_008872B0, 0x40005);
    slot = (s32 *)(D_008872E0 + D_007648A0);
    *slot = result;
    result = *slot;
    if (result == 0) {
        return 0;
    }
    D_007648A4 += 1;
    return arg0;
}
/* measured: close no_branch_likely after the nonvolatile body. */
#pragma no_branch_likely off
/* measured: close schedule after the nonvolatile body. */
#pragma schedule off

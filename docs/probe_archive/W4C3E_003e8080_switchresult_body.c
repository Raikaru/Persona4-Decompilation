#pragma schedule on
#pragma no_branch_likely on
#pragma opt_common_subs off
s32 func_003e8080(s32 arg0, s32 arg1) {
    extern s32 D_00763C7C;
    extern s32 D_00763C80;
    extern u8 D_008872B0[];
    s32 *slot;
    s32 result;

    D_007648A0 = arg1;
    result = func_003e1220(*(s32 *)D_0070B710, D_00763C7C, 0x10, D_00763C80, D_008872B0, 0x40005);
    slot = (s32 *)(D_008872E0 + D_007648A0);
    *slot = result;
    result = *slot;
    switch ((u32)result) {
    default:
        goto increment;
    case 0:
        goto setzero;
    }
setzero:
    return 0;
increment:
    D_007648A4 += 1;
    return arg0;
}
#pragma opt_common_subs on
#pragma no_branch_likely off
#pragma schedule off

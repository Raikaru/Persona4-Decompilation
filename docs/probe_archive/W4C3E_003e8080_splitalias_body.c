#pragma schedule on
#pragma no_branch_likely on
#pragma opt_common_subs off
s32 func_003e8080(s32 arg0, s32 arg1) {
    extern s32 D_00763C7C;
    extern s32 D_00763C80;
    extern u8 D_008872B0[];
    struct Store { u32 value; } *store;
    s32 *load;
    s32 result;

    D_007648A0 = arg1;
    result = func_003e1220(*(s32 *)D_0070B710, D_00763C7C, 0x10, D_00763C80, D_008872B0, 0x40005);
    store = (struct Store *)(D_008872E0 + D_007648A0);
    load = (s32 *)(D_008872E0 + D_007648A0);
    store->value = (u32)result;
    result = *load;
    if (result == 0) {
        return 0;
    }
    D_007648A4 += 1;
    return arg0;
}
#pragma opt_common_subs on
#pragma no_branch_likely off
#pragma schedule off

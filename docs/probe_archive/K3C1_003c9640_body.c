/* object 132B, window 144B, normalized_diff 46; differing offsets 0x10,0x30,0x31,0x32,0x34,0x37,0x39,0x3b,0x3c,0x50,0x51,0x53,0x5a,0x5b,0x5e. Tried direct and positive/negative guards, explicit gotos, cached base/self locals, ternary versus branch-fed assignment, schedule/no_branch_likely, and opt_rebuildconditionals off; retail's movz/branch and out-of-line block layout remain. */
#pragma push
#pragma opt_rebuildconditionals off
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003c9640(u8 *arg0) {
    extern s32 func_004114d0(s32 arg0, u8 *arg1, s32 arg2);
    u8 *base;
    s32 value;
    if (*(u16 *)(arg0 + 0x84) <= 0)
        goto done;
    value = *(s32 *)(arg0 + 0x7C);
    if (value == 0)
        goto fallback;
call:
    if (func_004114d0(value, arg0, 1) == 0)
        arg0 = NULL;
    return arg0;
fallback:
    base = *(u8 **)D_008872E4;
    value = *(s32 *)(base + 0x6C);
    if (value != 0)
        goto call;
    value = *(s32 *)(D_008872E0 + iGpffffb9b8 + 0x40);
    goto call;
done:
    return arg0;
}
#pragma pop
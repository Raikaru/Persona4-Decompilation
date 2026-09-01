// Candidate archive for func_003c57d0.
// Best probe: schedule/no_branch_likely on, stack pair and forward error label; object 532B/window 544B, normalized_diff 63. Remaining differences are register allocation in repeated record-address arithmetic.
u8 *func_003c57d0(u8 *arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4,
                  s16 arg5, s16 arg6, s16 arg7, u16 arg8) {
    extern void *(*D_008873F0[])(s32 arg0, s32 arg1, s32 arg2);
    extern s32 func_003df590(s32 arg0, ...);
    extern void func_003df4d0(s32 *arg0);
    s32 sp[2];
    s8 *var_2;
    u32 temp_16;
    u32 temp_5;

    temp_5 = *(u32 *)(arg0 + 4);
    if (temp_5 >= *(u32 *)(arg0 + 0)) {
        temp_16 = (temp_5 + 1) * 0x14;
        if (temp_5 != 0)
            var_2 = (s8 *)D_008873F0[0](*(s32 *)(arg0 + 8),
                                        temp_16, 0x01030502);
        else
            var_2 = (s8 *)((void *(*)(s32, s32))jtbl_008873E8[0])
                          (temp_16, 0x01030502);
        if (var_2 == NULL)
            goto error;
        *(s8 **)(arg0 + 8) = var_2;
        *(u32 *)(arg0 + 0) = *(u32 *)(arg0 + 4) + 1;
    }
    *(s32 *)(*(u32 *)(arg0 + 4) * 0x14 + *(u8 **)(arg0 + 8) + 8) = arg1;
    *(s16 *)(*(u32 *)(arg0 + 4) * 0x14 + *(u8 **)(arg0 + 8) + 0) = arg2;
    *(s16 *)(*(u32 *)(arg0 + 4) * 0x14 + *(u8 **)(arg0 + 8) + 2) = arg3;
    *(s16 *)(*(u32 *)(arg0 + 4) * 0x14 + *(u8 **)(arg0 + 8) + 4) = arg4;
    *(s16 *)(*(u32 *)(arg0 + 4) * 0x14 + *(u8 **)(arg0 + 8) + 0xC) = arg5;
    *(s16 *)(*(u32 *)(arg0 + 4) * 0x14 + *(u8 **)(arg0 + 8) + 0xE) = arg6;
    *(s16 *)(*(u32 *)(arg0 + 4) * 0x14 + *(u8 **)(arg0 + 8) + 0x10) = arg7;
    *(s16 *)(*(u32 *)(arg0 + 4) * 0x14 + *(u8 **)(arg0 + 8) + 0x12) = arg8;
    *(u32 *)(arg0 + 4) = *(u32 *)(arg0 + 4) + 1;
    return arg0;
error:
    sp[0] = 2;
    sp[1] = func_003df590(0x80000013, temp_16);
    func_003df4d0(sp);
    return NULL;
}

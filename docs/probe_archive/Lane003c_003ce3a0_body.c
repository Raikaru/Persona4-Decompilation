// Candidate archive for func_003ce3a0.
// Schedule/no_branch_likely C reconstruction; object 412B/window 448B, normalized_diff 296. Frame/register/control-flow shape remained too small versus retail.
s32 func_003ce3a0(s32 arg0, u8 *arg1) {
    extern void func_003cc6e0(u8 *arg0);
    extern s32 func_003deff0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern s32 func_003e2ab0(s32 arg0, void *arg1, s32 arg2);
    extern void func_004220d8(u8 *arg0, u8 *arg1);
    extern s32 func_003ce170(u8 *arg0);
    extern void func_003ce230(u8 *arg0);
    s32 sp[2];
    u32 *temp_16;
    u32 *temp_18;
    u32 *temp_21_2;
    u32 *var_16;
    u32 *var_19;
    u32 temp_21;
    u32 var_17;
    u32 var_17_2;

    if ((*(s32 *)(arg1 + 8) & 0x01000000) != 0) {
        temp_18 = (u32 *)(arg1 + iGpffffb730);
        temp_21 = *temp_18;
        var_17 = 0;
        if (temp_21 != 0) {
            var_16 = temp_18;
            do {
                func_003cc6e0((u8 *)*(u32 **)((u8 *)var_16 + 4));
                var_17 += 1;
                var_16 += 1;
            } while (var_17 < temp_21);
        }
        if (func_003deff0(arg0, 1, func_003ce840(arg1) - 0xC, 0x37002, 0x37) == 0)
            goto block_18;
        if (func_003e2ab0(arg0, &iGpffffaab8, 4) == 0)
            goto block_18;
        var_17_2 = 0;
        if (*temp_18 != 0) {
            var_19 = temp_18;
            do {
                temp_16 = (u32 *)*(u32 **)((u8 *)var_19 + 4);
                temp_21_2 = (u32 *)((u8 *)temp_16 + 0x18);
                sp[1] = *(s32 *)((u8 *)temp_16 + 8) -
                        (*(s32 *)((u8 *)temp_16 + 0x20) - (s32)temp_16);
                if (func_003e2ab0(arg0, &sp[1], 4) == 0)
                    goto block_18;
                sp[0] = func_003ce170((u8 *)temp_21_2);
                if (func_003e2ab0(arg0, &sp[0], 4) == 0)
                    goto block_18;
                if (func_003e2ab0(arg0, *(void **)((u8 *)temp_21_2 + 8), sp[1]) == 0)
                    goto block_18;
                func_003ce230((u8 *)temp_21_2);
                func_004220d8((u8 *)temp_16,
                               (u8 *)temp_16 + *(s32 *)((u8 *)temp_16 + 8) + 0x18);
                var_17_2 += 1;
                var_19 += 1;
            } while (var_17_2 < *temp_18);
        }
    }
    return arg0;
block_18:
    return 0;
}

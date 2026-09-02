// object 308B/window 320B/normalized_diff 61
// differing offsets: prologue (saved-register selection and frame size),
//   s0 vs s2 for the arg0/state pointer, s3 vs s1 for the return flag,
//   call-argument materialisation order around func_003cf9b0/003cfa30.
// levers ruled out: #pragma schedule on, #pragma no_branch_likely on,
//   declaration-order permutations, parameter vs local-copy of arg0,
//   single temp reuse for temp_2_3/4/5.
// remaining: saved-register graph-colouring floor; parameter arg0 and the
//   early-initialised return flag do not land in the retail s2/s1 slots.
s32 func_003a8500(u8 *arg0)
{
    s32 *temp_2_2;
    s32 temp_2;
    s32 temp_19;
    u8 *state;
    s32 temp;
    s32 var_17;
    s32 var_16;

    state = arg0;
    *(s32 *)(state + 0xC) = func_003a7f80();
    temp_19 = *(s32 *)(state + 0xC);
    if (temp_19 != 0) {
        var_16 = func_004115d0();
        if (var_16 != 0) {
            temp_2 = func_00412ca0(var_16);
            if (temp_2 != 0) {
                temp_2_2 = func_003cfa70();
                temp = func_00412fb0(temp_2, 0, temp_2_2, 0);
                func_00412e90(temp, *temp_2_2, 0, 0);
                temp = func_004125e0(temp);
                if (temp != 0) {
                    temp = func_00412e90(temp, *temp_2_2, 0, 0);
                    func_003cf9b0((u8 *)temp, 1, (void *)func_003a8180);
                    func_003cfa30(temp, temp_19);
                } else {
                    func_00411670(var_16);
                    goto block_9;
                }
            } else {
                func_00411670(var_16);
                goto block_9;
            }
        } else {
block_9:
            var_16 = 0;
        }
        *(s32 *)(state + 0x10) = var_16;
        var_17 = 0;
        if (*(s32 *)(state + 0x10) != 0) {
            var_17 = 1;
        }
    } else {
        var_17 = 0;
    }
    return var_17;
}

/* TRSL 2026-08-14: object 472B / window 480B / normalized_diff 57; differing offsets 40,44,52,60,64,68,72,76,84,88,92,100,104,108,112,116,120,124,156,160,164,168,324; deficit 2 instructions; classification saved-register coloring + pre-call destination-address hoist; ruled out typed aggregate fields, direct field accesses, slot pointer, reload, add-base, declaration-order, and pointer aliases. */
s32 func_0021f340(BtlResultWork *work)
{
    s32 temp_2;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 var_16;
    s32 var_18;
    s32 var_18_2;
    u16 temp_3;
    u8 *arg0;

    arg0 = (u8 *)work;
    if (!(*(u16 *)(arg0 + 0) & 0x100)) {
        temp_4 = *(s32 *)(arg0 + 0x4BC);
        if (temp_4 != 0 && func_004553c0((u8 *)temp_4) != 0) {
            var_18 = 0;
            while (var_18 < 3) {
                temp_2 = (s32)func_0046af60(
                    (u8 *)func_00455ea0(temp_4, var_18, 0));
                *(s32 *)(arg0 + var_18 * 4 + 0x400) = temp_2;
                if (temp_2 == 0) {
                    func_0046d730(&D_00629610, 0x181);
                }
                var_18 += 1;
            }
            *(u16 *)(arg0 + 0) |= 0x100;
        } else {
            return 0;
        }
    }
    if (!(*(u16 *)(arg0 + 0) & 0x20)) {
        var_18_2 = 0;
        var_16 = 0;
        while (var_18_2 < 3) {
            temp_4_2 = *(s32 *)(arg0 + var_18_2 * 4 + 0x400);
            if (temp_4_2 != 0 && func_0046a750(temp_4_2) != 0) {
                var_16 += 1;
            }
            var_18_2 += 1;
        }
        if (var_16 == 3) {
            *(u16 *)(arg0 + 0) |= 0x20;
            temp_4_3 = *(s32 *)(arg0 + 0x4BC);
            if (temp_4_3 != 0) {
                func_00454bd0((u8 *)temp_4_3);
                *(s32 *)(arg0 + 0x4BC) = 0;
            }
        }
    }
    if (!(*(u16 *)(arg0 + 0) & 0x40)) {
        temp_4_4 = *(s32 *)(*(u8 **)(arg0 + 0x570) + 0x934);
        if (temp_4_4 != 0 && func_004553c0((u8 *)temp_4_4) != 0) {
            *(u16 *)(arg0 + 0) |= 0x40;
        }
    }
    temp_3 = *(u16 *)(arg0 + 0);
    if ((temp_3 & 0x20) && (temp_3 & 0x40)) {
        return 1;
    }
    return 0;
}

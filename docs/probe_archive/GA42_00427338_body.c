/* measured: object=652 window=624 normalized_diff=446; reverted to assembly fallback. */
// FUN_00427338
s32 func_00427338(s32 unused, s32 *arg1, s32 arg2)
{
    s32 sp30;
    u8 *sp24;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    u8 *var_16;
    s32 *temp_5;
    s32 temp_16_2;
    s32 temp_16_3;
    s32 temp_19;
    s32 temp_20;
    s32 var_18;
    s32 var_6;
    u8 *temp_16;

    temp_16 = (u8 *)func_00426248();
    func_004266c8(2);
    if ((D_0070C67C == 0) || (temp_16 == NULL) ||
        (temp_20 = *(s32 *)(temp_16 + 4), temp_20 == 0)) {
        func_004266f8();
        return -9;
    }
    *(s32 *)(D_0088F780 + 0xC) = *(s32 *)(temp_16 + 0);
    *(s32 *)(D_0088F780 + 0x1C) =
        (s32)((temp_16 - D_00890C80) >> 4);
    sp14 = 1;
    sp24 = D_007541E8;
    temp_16_2 = temp_20 & 0x8000;
    *(s32 **)(D_0088F780 + 0x10) = arg1;
    *(s32 *)(D_0088F780 + 0x14) = arg2;
    sp18 = 0;
    temp_19 = func_004217e0(&sp10, (u8 *)1);
    *(s32 *)(D_0088F780 + 8) = 4;
    *(s32 **)(D_0088F780 + 4) = &sp30;
    *(s32 *)(D_0088F780 + 0) = temp_19;
    if (temp_16_2 != 0) {
        func_00421820(D_0070C68C);
        var_18 = temp_16_2;
        if (D_0070C5F8[0] == -1) {
            var_16 = (u8 *)0x890000;
            D_0070C5F8[0] = *(s32 *)(D_0088F780 + 0);
            *(s32 *)(D_0088F780 + 0) = -*(s32 *)(D_0088F780 + 0);
        } else {
            var_16 = D_008903C0;
            var_6 = 1;
            while (var_6 < 0x20) {
                temp_5 = &D_0070C5F8[var_6];
                var_6 += 1;
                if (*temp_5 == -1) {
                    *temp_5 = *(s32 *)(D_0088F780 + 0);
                    *(s32 *)(D_0088F780 + 0) =
                        -*(s32 *)(D_0088F780 + 0);
                    break;
                }
            }
        }
        func_00421800(D_0070C68C);
    } else {
        var_16 = D_008903C0;
        var_18 = 0;
    }
    if (!(temp_20 & 0x20000000)) {
        func_00424e78(arg1, arg2);
    }
    func_00424e78(D_0088F780, 0x20);
    if (func_00426158(D_00890E80, 2, 0, D_0088F780, 0x20,
                      (s32)var_16, 4, 0, 0, var_18) < 0) {
        func_004217f0(temp_19);
        func_004266f8();
        return -0xB;
    }
    temp_16_3 =
        (s32)*((u8 *)((u32)var_16 | 0x20000000U));
    func_004266f8();
    if (temp_16_3 == 0) {
        func_004217f0(temp_19);
        return -0xB;
    }
    if (var_18 != 0) {
        func_004217f0(temp_19);
        return 0;
    }
    func_00421820(temp_19);
    func_004217f0(temp_19);
    return sp30;
}

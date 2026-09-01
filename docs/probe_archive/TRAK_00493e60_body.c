/* object 628B / window 624B / normalized_diff 233; oversized and archived immediately. */
/* Palette reconstruction candidate; callee declarations were checked against matched definitions, but object remained oversized. */
u8 *func_00493e60(u16 arg0, u16 arg1) {
    u8 *temp_2;
    s32 temp_18;
    s32 var_4;
    u16 *temp_2_2;
    u16 *temp_2_3;
    u16 *temp_6;
    u16 *temp_7;
    u32 temp_17;
    u32 var_5;
    u8 *temp_10;
    u8 *temp_10_2;
    u8 *temp_9;
    u8 *temp_9_2;

    if ((arg1 & 0xFFFF) < 2) {
        func_0046d730(&D_00713E30, 0x205);
    }
    temp_17 = arg0 & 0xFFFF;
    temp_18 = (temp_17 * 2) + 0x1C;
    func_0044ea90(&D_00713E30, 0x20A);
    temp_2 = (u8 *)(*jtbl_008873E8)(temp_18, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(&D_00713E30, 0x20B);
    }
    func_0043f9c8(temp_2, 0, temp_18);
    *(u8 **)(temp_2 + 0x18) = temp_2 + 0x1C;
    temp_2_2 = (u16 *)func_00483e10(arg0, arg1, (void *)D_00713310, 3, 0x48);
    *(u16 **)(temp_2 + 0x10) = temp_2_2;
    *temp_2_2 &= 0xFFFB;
    temp_2_3 = (u16 *)func_00483c40(arg0, 1, 6, 8, (void *)D_00713420, 0x48);
    *(u16 **)(temp_2 + 0x14) = temp_2_3;
    *temp_2_3 &= 0xFFFB;
    var_5 = 0;
    while (var_5 < temp_17) {
        temp_6 = *(u16 **)(temp_2 + 0x10);
        if (D_00764C54[3] != 0xFF) {
            var_4 = (var_5 & 0xFFFF) * 4;
            temp_10 = *(u8 **)((u8 *)temp_6 + 0x54) + var_4;
            temp_10 = *(u8 **)temp_10;
            temp_10[4] = D_00764C54[0];
            temp_10[5] = D_00764C54[1];
            temp_10[6] = D_00764C54[2];
            temp_10[7] = D_00764C54[3];
        } else {
            D_00764C54[3] = 0xFE;
            var_4 = (var_5 & 0xFFFF) * 4;
            temp_10_2 = *(u8 **)((u8 *)temp_6 + 0x54) + var_4;
            temp_10_2 = *(u8 **)temp_10_2;
            temp_10_2[4] = D_00764C54[0];
            temp_10_2[5] = D_00764C54[1];
            temp_10_2[6] = D_00764C54[2];
            temp_10_2[7] = D_00764C54[3];
            D_00764C54[3] = 0xFF;
        }
        temp_7 = *(u16 **)(temp_2 + 0x14);
        if (D_00764C54[3] != 0xFF) {
            temp_9 = *(u8 **)((u8 *)temp_7 + 0x54) + var_4;
            temp_9 = *(u8 **)temp_9;
            temp_9[4] = D_00764C54[0];
            temp_9[5] = D_00764C54[1];
            temp_9[6] = D_00764C54[2];
            temp_9[7] = D_00764C54[3];
        } else {
            D_00764C54[3] = 0xFE;
            temp_9_2 = *(u8 **)((u8 *)temp_7 + 0x54) + var_4;
            temp_9_2 = *(u8 **)temp_9_2;
            temp_9_2[4] = D_00764C54[0];
            temp_9_2[5] = D_00764C54[1];
            temp_9_2[6] = D_00764C54[2];
            temp_9_2[7] = D_00764C54[3];
            D_00764C54[3] = 0xFF;
        }
        var_5 += 1;
    }
    return temp_2;
}

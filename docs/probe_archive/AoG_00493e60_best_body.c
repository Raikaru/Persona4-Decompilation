/* Best measured reconstruction for FUN_00493E60; retained before reverting. */
/* Residual: 51 reloc-masked words (obj 620B / retail window 624B). */
/* Retail register list: s4=arg0, s3=arg1, s1=(u16)arg0, s2=size, s0=allocation;
 * loop counter=a1, index=a0, first table base=a2, first element=t2,
 * first bytes=t1,t0,a3,a2; second table base=a3, second element=t1,
 * second bytes=t0,a3,a2,a0; alpha constants v1=0xff and v0=0xfe. */
#pragma push
#pragma opt_propagation off
// FUN_00493E60
u8 *func_00493e60(u16 arg0, u16 arg1) {
    s32 temp_18;
    u8 *temp_2;
    u16 temp_17;
    s32 var_4;
    u16 *temp_2_2;
    u16 *temp_6;
    u16 *temp_7;
    u8 *temp_10;
    s32 temp_ff;
    s32 temp_fe;
    u8 *temp_9;

    if ((u16)arg1 < 2) {
        func_0046d730(&D_00713E30, 0x205);
    }
    temp_17 = (arg0 + 0) & 0xFFFF;
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
    temp_2_2 = (u16 *)func_00483c40(arg0, 1, 6, 8, (void *)D_00713420, 0x48);
    *(u16 **)(temp_2 + 0x14) = temp_2_2;
    *temp_2_2 = *temp_2_2 & (u16)0xFFFB;
    {
        u32 var_5;
        var_5 = 0;
    temp_ff = 0xFF;
    temp_fe = 0xFE;
    for (; var_5 < temp_17; var_5 += 1) {
        temp_6 = *(u16 **)(temp_2 + 0x10);
        if (D_00764C54[3] != temp_ff) {
            var_4 = (u16)var_5 * 4;
            temp_10 = *(u8 **)((u8 *)temp_6 + 0x54) + var_4;
            temp_10 = *(u8 **)temp_10;
            temp_10[4] = D_00764C54[0];
            temp_10[5] = D_00764C54[1];
            temp_10[6] = D_00764C54[2];
            temp_10[7] = D_00764C54[3];
        } else {
            D_00764C54[3] = temp_fe;
            var_4 = (u16)var_5 * 4;
            temp_10 = *(u8 **)((u8 *)temp_6 + 0x54) + var_4;
            temp_10 = *(u8 **)temp_10;
            temp_10[4] = D_00764C54[0];
            temp_10[5] = D_00764C54[1];
            temp_10[6] = D_00764C54[2];
            temp_10[7] = D_00764C54[3];
            D_00764C54[3] = temp_ff;
        }
        temp_7 = *(u16 **)(temp_2 + 0x14);
        if (D_00764C54[3] != temp_ff) {
            temp_9 = *(u8 **)((u8 *)temp_7 + 0x54) + var_4;
            temp_9 = *(u8 **)temp_9;
            temp_9[4] = D_00764C54[0];
            temp_9[5] = D_00764C54[1];
            temp_9[6] = D_00764C54[2];
            temp_9[7] = D_00764C54[3];
        } else {
            D_00764C54[3] = temp_fe;
            temp_9 = *(u8 **)((u8 *)temp_7 + 0x54) + var_4;
            temp_9 = *(u8 **)temp_9;
            temp_9[4] = D_00764C54[0];
            temp_9[5] = D_00764C54[1];
            temp_9[6] = D_00764C54[2];
            temp_9[7] = D_00764C54[3];
            D_00764C54[3] = temp_ff;
        }
    }
    }
    return temp_2;
}
#pragma pop

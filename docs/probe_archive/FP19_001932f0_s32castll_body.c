s32 func_001932f0(void)
{
    u8 sp50[0x3C];
    s32 var_19;
    s32 var_18;
    u16 temp_17;
    s32 temp_4;
    u16 temp_4_2;
    u16 temp_3;
    u8 *temp_16;

    func_001fc1b0(1);
    temp_17 = func_0029cc00(0) & 0xFFFF;
    temp_16 = (u8 *)(iGpffffb414 + (temp_17 * 0x18));
    func_0043f9c8(sp50, 0, 0x3C);
    *(s32 *)(sp50 + 4) = func_00231580(1);
    var_18 = (s32)1LL;
    var_19 = 0;
    goto loop_5_check;
loop_5_body:
    temp_4_2 = func_00105ee0(temp_4) & 0xFFFF;
    if ((temp_4_2 != 0) && ((u16)var_18 < 4)) {
        *(s32 *)((u8 *)sp50 - 0x50 +
                 ((var_18 & 0xFFFF) * 4) + 0x54) =
            func_00231580(temp_4_2);
        var_18 = (var_18 + 1) & 0xFFFF;
    }
    var_19 = (var_19 + 1) & 0xFFFF;
loop_5_check:
    temp_4 = var_19 & 0xFFFF;
    if (temp_4 < 4) {
        goto loop_5_body;
    }
    *(s32 *)(sp50 + 0x14) = func_00231630(temp_17);
    temp_3 = *(u16 *)(temp_16 + 0x12);
    if ((temp_3 == 0) && (*(u16 *)(temp_16 + 0x14) == 0)) {
        *(u16 *)(sp50 + 0x20) = 0xF0;
        *(u16 *)(sp50 + 0x22) = 1;
    } else {
        *(u16 *)(sp50 + 0x20) = temp_3;
        *(u16 *)(sp50 + 0x22) = *(u16 *)(temp_16 + 0x14);
    }
    func_001029a0(6, sp50, 0x3C, 4);
    return 1;
}
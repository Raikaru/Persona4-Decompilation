void func_00205c20(u8 *arg0, s16 arg1, f32 fparg0, f32 fparg1,
                   u8 arg2, s32 arg3)
{
    extern s16 func_00105f00(s16 arg0);
    extern s32 func_0010d6d0(s16 arg0);
    extern void func_00274ed0(f32 arg0, f32 arg1, f32 arg2, s32 arg3,
                              s32 arg4, s32 arg5, s32 arg6, s32 arg7,
                              s32 arg8);
    u8 *temp_2;
    u8 *temp_18;
    u8 *temp_16;
    u8 var_17;

    temp_2 = (u8 *)func_00452560(*(s32 *)(arg0 + 0x5B0));
    temp_18 = temp_2;
    if (arg3 != 0) {
        var_17 = 0x1B;
    } else {
        var_17 = 0xFF;
    }
    temp_16 = *(u8 **)(p4_002091f0_add((u32)(arg1 * 4), arg0) + 0x17C);
    func_00272c60(0x40);
    func_00274ed0(
        1.0f + fparg0, (19.0f + fparg1) - 3.0f, 50.0f,
        (arg2 & 0xFF) | ((var_17 & 0xFF) << 8) |
            ((var_17 & 0xFF) << 0x18) | ((var_17 & 0xFF) << 0x10),
        0, 1, func_0010d6d0(*(s16 *)(temp_16 + 0xA4)), 0, 0);
    func_00272c80(0x40);
    func_00201650(temp_18, 9, 0x3C, 155.0f + fparg0,
                  24.0f + fparg1, var_17, var_17, var_17, arg2);
    func_00201650(
        temp_18, 9, func_00105f00(*(s16 *)(temp_16 + 0xA4)) + 0x3F,
        178.0f + fparg0, 16.0f + fparg1, var_17, var_17, var_17,
        arg2);
}

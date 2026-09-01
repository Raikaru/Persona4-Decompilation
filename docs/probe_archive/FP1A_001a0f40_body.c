/* Best candidate for func_001a0f40; object 440B, window 448B, normalized_diff 32. */
void func_001a0f40(s64 *arg0)
{
    f32 sp30[3];
    s32 temp_7;
    u16 var_5;
    u16 temp_6;
    u8 temp_3;
    u8 *temp_16;
    u8 *temp_2;
    u32 temp_table;

    temp_16 = *(u8 **)((u8 *)arg0 + 0x30);
    if (((*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) != 0) &&
        ((*(u16 *)((u8 *)arg0 + 0x1A) & 1) != 0) &&
        (temp_16[0xA2] == 0)) {
        *(u16 *)((u8 *)arg0 + 0x14) = 9;
    }
    if (func_001b0e90(arg0) != 0) {
        temp_6 = *(u16 *)((u8 *)arg0 + 0x14);
        func_001b0800(func_001a_identity((u8 *)arg0), temp_6);
        return;
    }
    func_00194ff0(temp_16, &sp30[0], 0, NULL);
    if (!(func_001ec250(temp_16 + 4, &sp30[0]) <= 75.0f)) {
        var_5 = 2;
        temp_7 = (!(iGpffffb3b8[
            (*(u16 *)((u8 *)arg0 + 0x6E) * 0x28)] & 2)) & 0xFFFF;
        temp_6 = *(u16 *)(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA64) + 2);
        temp_3 = *(u8 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA2);
        switch (temp_3) {
        case 0:
            break;
        case 1:
            temp_table = (u32)iGpffffb3cc;
            var_5 = *(u16 *)((u8 *)temp_table +
                (((temp_6 * 0xE8) + ((temp_7 & 0xFFFF) * 4)) + 0x24));
            break;
        }
        temp_2 = func_001973f0(
            *(u8 **)((u8 *)arg0 + 0x30), &sp30[0], 0, temp_7,
            D_005F6D20[var_5 & 0xFFFF]);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2, 1);
        return;
    }
    func_001b0800(arg0, *(u16 *)((u8 *)arg0 + 0x14));
}

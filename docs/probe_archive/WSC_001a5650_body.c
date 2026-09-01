/* Best measured body for func_001a5650; object 660B, window 656B, residual 76 words. */
// FUN_001A5650
void func_001a5650(s64 *arg0)
{
    struct Action {
        u8 pad[0x30];
        u8 *unit;
    };
    f32 sp30[3];
    void func_001b0800(u8 *arg0, u16 arg1);
    u16 temp_7;
    u16 temp_3_3;
    u16 var_5;
    u16 var_5_2;
    u16 var_5_3;
    u16 temp_3;
    u8 temp_3_2;
    u8 *temp_16;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_4;
    u8 *temp_4_2;

    temp_16 = *(u8 **)((u8 *)arg0 + 0x30);
    temp_4 = D_0076449C;
    if ((*(s32 *)(temp_4 + 0xC) & 0x400000) &&
        (*(u16 *)(temp_4 + 0x18) & 2)) {
        temp_3 = *(u16 *)((u8 *)arg0 + 0x6C);
        switch (temp_3) {
        case 1:
            var_5 = 0x12;
            break;
        case 2:
        case 3:
            var_5 = 0x13;
            break;
        case 9:
            var_5 = 0x14;
            break;
        default:
            var_5 = 0;
            break;
        }
        func_001b0800((u8 *)arg0, var_5);
        return;
    }
    func_00194ff0(temp_16, sp30, 0, NULL);
    if (!(func_001ec250(temp_16 + 4, sp30) <= 75.0f)) {
        func_001a03b0(arg0);
        var_5_2 = 2;
        temp_7 = (!(iGpffffb3b8[
            (*(u16 *)((u8 *)arg0 + 0x6E) * 0x28)] & 2)) & 0xFFFF;
        temp_4_2 = ((struct Action *)arg0)->unit;
        temp_3 = *(u16 *)(*(u8 **)(temp_4_2 + 0xA64) + 2);
        temp_3_2 = *(u8 *)(temp_4_2 + 0xA2);
        switch (temp_3_2) {
        case 0:
            break;
        case 1:
            temp_4 = iGpffffb3cc;
            var_5_2 = *(u16 *)(temp_4 +
                ((temp_3 * 0xE8) + (temp_7 * 4)) + 0x24);
            break;
        }
        temp_2 = func_001973f0(
            temp_4_2,
            sp30,
            0,
            temp_7,
            D_005F6D20[var_5_2] * D_0076144C);
        *(s64 *)(temp_2 + 0x60) = *arg0;
        func_00194590(temp_2, 1);
        temp_2_2 = func_001bc920((u8 *)arg0, 0x18);
        *(s64 *)(temp_2_2 + 0x60) = *arg0;
        func_00194590(temp_2_2, 0);
        return;
    }
    temp_3_3 = *(u16 *)((u8 *)arg0 + 0x6C);
    switch (temp_3_3) {
    case 1:
        var_5_3 = 0x12;
        break;
    case 2:
    case 3:
        var_5_3 = 0x13;
        break;
    case 9:
        var_5_3 = 0x14;
        break;
    default:
        var_5_3 = 0;
        break;
    }
    func_001b0800((u8 *)arg0, var_5_3);
}

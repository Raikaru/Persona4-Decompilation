/* Best candidate for func_001a1c80; object 540B, window 544B, normalized_diff 2. */
void func_001a1c80(u8 *arg0)
{
    u8 *var_17;
    s32 var_16;
    u8 temp_3;
    u8 *temp_2;

    switch (*(u16 *)(arg0 + 0x6C)) {
    case 4:
        func_001d7c60(arg0, arg0 + 0x98, 2, 0, 0);
        var_16 = *(u16 *)(arg0 + 0x6E);
        if (var_16 == 0) {
            var_16 = -1;
        }
        break;
    default:
        var_16 = *(u16 *)(arg0 + 0x6E);
        temp_3 = *(u8 *)(func_001a_add_offset(var_16 * 0x28,
                                               (u32)iGpffffb3b8) + 8);
        switch (temp_3) {
        case 1:
        case 2:
            func_001d7c60(
                arg0,
                arg0 + 0x98,
                *(u8 *)(func_001a_add_offset(var_16 * 0x28,
                                              (u32)iGpffffb3b8) + 9),
                *(u8 *)(func_001a_add_offset(var_16 * 0x28,
                                              (u32)iGpffffb3b8) + 0xA),
                0);
            break;
        default:
            func_001d7f10(arg0, arg0 + 0x98, var_16 & 0xFFFF, 0);
            break;
        }
        break;
    }
init_1c80:
    func_001d8cb0(arg0, arg0 + 0x98);
    temp_3 = *(u8 *)(func_001a_add_offset(
        *(u16 *)(arg0 + 0x6E) * 0x28, (u32)iGpffffb3b8) + 8);
    switch (temp_3) {
    case 1:
    case 2:
        goto type12_2_1c80;
    default:
        goto typeother_2_1c80;
    }
type12_2_1c80:
    var_17 = NULL;
    goto after_type_1c80;
typeother_2_1c80:
    func_001d8e50(arg0, arg0 + 0x98);
after_type_1c80:
    func_0020b6d0(
        *(s32 *)(D_0076449C + 0xDD4),
        arg0,
        arg0 + 0x98,
        (s64)(s16)var_16);
    temp_2 = func_001bc920(arg0, 0x22);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 0);
    func_00212010(*(s32 *)(D_0076449C + 0xDD4));
    func_0019faf0(arg0);
    if (var_17 != NULL) {
        temp_2 = func_0019e550(NULL, *(u8 **)(var_17 + 0x30), 1);
        func_00194590(temp_2, 1);
        temp_2 = func_0019e7c0(*(s32 *)(var_17 + 0x30), 0);
        func_00194590(temp_2, 1);
    }
}
